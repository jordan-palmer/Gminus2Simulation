#include "G4Event.hh"
#include "G4SystemOfUnits.hh"
#include "G4EventManager.hh"

#include "BFieldEveAct.hh"
#include "BFieldAna.hh"

BFieldEveAct::BFieldEveAct()
{
}

BFieldEveAct::~BFieldEveAct()
{
}

void BFieldEveAct::BeginOfEventAction(const G4Event* /*anEvent*/)
{
	trackID.clear();
	parName.clear();
	parID.clear();
	pos.clear();
}

void BFieldEveAct::EndOfEventAction(const G4Event* /*anEvent*/)
{
	// Get analysis manager
	G4AnalysisManager* AM = G4AnalysisManager::Instance();

	G4int iTrack = 1;
	//while ( trackID[iTrack] != 0 )
  //for (int i = 1; i <= trackID.size (); i++) 
  for (std::map<G4int, G4int>::iterator i = trackID.begin (); i != trackID.end (); i++)
	{
		//G4int ID = trackID[iTrack];
		G4int ID = i->first;

		AM -> FillNtupleIColumn(0, ID);
		AM -> FillNtupleSColumn(1, parName[ID]);
		AM -> FillNtupleIColumn(2, parID[ID]);
		AM -> FillNtupleDColumn(3, pos[ID].x());
		AM -> FillNtupleDColumn(4, pos[ID].y());
		AM -> FillNtupleDColumn(5, pos[ID].z());
		AM -> FillNtupleDColumn(6, G4EventManager::GetEventManager()->GetConstCurrentEvent()->GetEventID());

    G4cout << "\x1b[31m (" << G4EventManager::GetEventManager()->GetConstCurrentEvent()->GetEventID() << ", " << ID << ") PARTICLE = " << parName[ID] << "\x1b[0m" << G4endl;

		AM -> AddNtupleRow();
		//iTrack++;
	}
}

void BFieldEveAct::SetEventID (G4int eID) {
  eventID = eID;
}

void BFieldEveAct::SetTrackID(G4int tID)
{ trackID[tID] = tID; }

void BFieldEveAct::SetParName(G4int tID, G4String pN)
{ parName[tID] = pN; }

void BFieldEveAct::SetParID(G4int tID, G4int pID)
{ parID[tID] = pID; }

void BFieldEveAct::SetPos(G4int tID, G4ThreeVector pP)
{ pos[tID] = pP; }
