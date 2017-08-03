
{
  /*  gSystem->Load ("RooJordan2_cxx.so");
  RooRealVar t ("t", "t",0.1, 0.0, 20.e-6);
  RooRealVar wa ("wa", "wa", 1.e6);
  RooRealVar A("A", "A",10.);
  RooRealVar phi("phi", "phi", 6.5);
  RooRealVar N("N", "N", 10.e6);
  RooRealVar tau("tau", "tau", 2.2e-6);

  RooJordan2 *jordan = new RooJordan2 ("jordan", "jordan", t, wa, A, tau, phi, N);*/
  double ta = 2.2E-6;
  double As = 1;
  double w = 10E5;
  double pi = 0;

  const Int_t n = 1000;
  Double_t x[n], y[n];
  for (Int_t i=0;i<n;i++) {
    double t = i/100000000.;
    x[i] = t;
    y[i] = pow(10,9)*exp(-t/ta)*(1 + As*cos(w*t + pi));
  }
  TGraph *gr = new TGraph(n,x,y);
  gr->SetTitle("a simple graph");
  
  gr->GetXaxis()->SetTitle("X title");
  gr->GetYaxis()->SetTitle("Y title");
  gr->Draw();

  
}


