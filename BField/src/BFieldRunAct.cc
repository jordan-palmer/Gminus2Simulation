#include "G4Run.hh"
#include "G4SystemOfUnits.hh"

#include "BFieldRunAct.hh"
#include "BFieldAna.hh"

BFieldRunAct::BFieldRunAct() : G4UserRunAction()
{
	// Create analysis manager
	// The choice of analysis technology is done via selectin of a namespace
	// in BFieldAna.hh
	G4AnalysisManager* AM = G4AnalysisManager::Instance();
	G4cout << "Using " << AM -> GetType() << G4endl;

	// Default settings
	AM -> SetVerboseLevel(2);

	// Creating ntuple
	AM -> CreateNtuple("BFieldWithGDML", "data");
	AM -> CreateNtupleIColumn("trackID"); // Column ID = 0
	AM -> CreateNtupleSColumn("parName"); // Column ID = 1
	AM -> CreateNtupleIColumn("parID");   // Column ID = 2
	AM -> CreateNtupleDColumn("posX");    // Column ID = 3
	AM -> CreateNtupleDColumn("posY");    // Column ID = 4
	AM -> CreateNtupleDColumn("posZ");    // Column ID = 5
	AM -> CreateNtupleDColumn("eventID");    // Column ID = 5
	AM -> FinishNtuple();
}

BFieldRunAct::~BFieldRunAct()
{
	delete G4AnalysisManager::Instance();
}

void BFieldRunAct::BeginOfRunAction(const G4Run* /*run*/)
{
	//inform the runManager to save random number seed
	//G4RunManager::GetRunManager()->SetRandomNumberStore(true);

	// Get analysis manager
	G4AnalysisManager* AM = G4AnalysisManager::Instance();

	// Open an output file
	// The default file name is set in pEDMRunAct::pEDMRunAct(),
	// it can be overwritten in a macro
	G4String fileName = "BFieldWithGDML";
	AM -> OpenFile(fileName);
}

void BFieldRunAct::EndOfRunAction(const G4Run* /*run*/)
{
	// save histograms & ntuple
	G4AnalysisManager* AM = G4AnalysisManager::Instance();
	AM -> Write();
	AM -> CloseFile();
}
