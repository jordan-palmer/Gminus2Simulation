////////////////////////////////////////////////////////////////////////
//   A simple example of finding 2D track from the detected positron  //
// hit position. I hope it helpful.                                   //
//                                                                    //
//               - 2017. 8. 2. Hoyong Jeong (hyjeong@hep.korea.ac.kr) //
////////////////////////////////////////////////////////////////////////

void track()
{
	gROOT -> Reset();

	// Read file
	TChain* chain = new TChain("tree");
	chain -> Add("output.root");

	// Get branches
	int eventID, trackID, parID;
	double x, y, z;
	chain -> SetBranchAddress("eventID", &eventID);
	chain -> SetBranchAddress("trackID", &trackID);
	chain -> SetBranchAddress(  "parID",   &parID);
	chain -> SetBranchAddress(   "posX",       &x);
	chain -> SetBranchAddress(   "posY",       &y);
	chain -> SetBranchAddress(   "posZ",       &z);

	// Define TGraph
	TGraph *gr = new TGraph();

	// Fill points into the TGraph object
	for ( int i = 0; i < chain -> GetEntries(); i++ )
	{
		chain -> GetEntry(i);
		gr -> SetPoint(i, x, y);
	}

	// Function to be minimized
	auto chi2Function = [&](const double *par)
	{
		// Minimization function computing the sum of squares of residuals
		// looping at the graph points
		int np = gr -> GetN();
		double f = 0;
		double *x = gr -> GetX();
		double *y = gr -> GetY();

		for ( int i = 0; i < np; i++ )
		{
			double u  = x[i] - par[0];
			double v  = y[i] - par[1];
			double dr = par[2] - TMath::Sqrt(u*u + v*v);
			f += dr*dr;
		}

		return f;
	};

	// Wrap chi-square funciton in a function object for the fit
	// 3 is the number of fit parameters (size of array par)
	ROOT::Math::Functor fcn(chi2Function, 3);
	ROOT::Fit::Fitter fitter;

	double pStart[3] = {-150, -150, 150}; // I decided it by my eyes.
	fitter.SetFCN(fcn, pStart);
	fitter.Config().ParSettings(0).SetName("x0");
	fitter.Config().ParSettings(1).SetName("y0");
	fitter.Config().ParSettings(2).SetName("R");

	// Do the fit 
	bool ok = fitter.FitFCN();
	if (!ok) Error("line3Dfit", "Line3D Fit failed");

	const ROOT::Fit::FitResult &result = fitter.Result();
	result.Print(std::cout);

	// I'd like to draw sensor structure also...
	TGraph *sensor[96];
	for ( int i = 0; i < 96; i++ )
	{
		sensor[i] = new TGraph();
	}

	// Two end points for four each sensor in one vane
	// You can check these dimensions in GDML file.
	TVector3 v1( 65.0,   2.0, 0.0), v2(163.8,   2.0, 0.0),
	         v3(165.25,  2.0, 0.0), v4(264.25,  2.0, 0.0),
	         v5( 65.0,  -2.0, 0.0), v6(163.8,  -2.0, 0.0),
	         v7(165.25, -2.0, 0.0), v8(264.25, -2.0, 0.0);

	// Each vane is placed with rotating on the axis by 15 degree.
	TRotation r;
	r.RotateZ(TMath::Pi()/12.0);
	for ( int i = 0; i < 24; i++ )
	{
		int n = 4*i;
		sensor[n]   -> SetPoint(0, v1.x(), v1.y());
		sensor[n]   -> SetPoint(1, v2.x(), v2.y());
		sensor[n+1] -> SetPoint(0, v3.x(), v3.y());
		sensor[n+1] -> SetPoint(1, v4.x(), v4.y());
		sensor[n+2] -> SetPoint(0, v5.x(), v5.y());
		sensor[n+2] -> SetPoint(1, v6.x(), v6.y());
		sensor[n+3] -> SetPoint(0, v7.x(), v7.y());
		sensor[n+3] -> SetPoint(1, v8.x(), v8.y());

		// Rotate!
		v1 = r*v1; v2 = r*v2; v3 = r*v3; v4 = r*v4;
		v5 = r*v5; v6 = r*v6; v7 = r*v7; v8 = r*v8;
	}
	
	// Draw
	TCanvas *c = new TCanvas("c", "Track", 0, 0, 900, 900);
	c -> SetGrid();
	sensor[0] -> Draw("AL");
	for ( int i = 1; i < 96; i++ ) sensor[i] -> Draw("same");
	gr -> Draw("sameP");

 	TArc *arc = new TArc(result.Parameter(0), result.Parameter(1), result.Parameter(2));
	arc -> SetLineColor(kBlue);
	arc -> SetLineWidth(2);
	arc -> SetFillStyle(4000); // Don't fill. Make it transparent.
	arc -> Draw("same");

	// Style
	sensor[0] -> GetXaxis() -> SetLimits(-300, 300);
	sensor[0] -> GetYaxis() -> SetRangeUser(-300, 300);
	sensor[0] -> GetHistogram() -> GetXaxis() -> SetTitle("x position (mm)");
	sensor[0] -> GetHistogram() -> GetYaxis() -> SetTitle("y position (mm)");
	gr -> SetMarkerStyle(20);
	gr -> SetMarkerColor(kRed);
}
