#include "G4VProcess.hh"

#include "BFieldSteAct.hh"

BFieldSteAct::BFieldSteAct(BFieldEveAct* eveAct) : G4UserSteppingAction(), fEveAct(eveAct)
{
}

BFieldSteAct::~BFieldSteAct()
{
}

void BFieldSteAct::UserSteppingAction(const G4Step* step)
{
	// Who am I? Where am I?
	// // Track ID
	G4int trackID = step -> GetTrack() -> GetTrackID();
	// // Particle name
	G4String parName = step -> GetTrack() -> GetDefinition() -> GetParticleName();
	// // Particle ID
	G4int parID = step -> GetTrack() -> GetDefinition() -> GetPDGEncoding();
	// // Physical volume
	G4String namePrePV = step -> GetPreStepPoint() -> GetPhysicalVolume() -> GetName();
	G4String namePostPV;
	G4VPhysicalVolume* postPV = step -> GetPostStepPoint() -> GetPhysicalVolume();
	if ( postPV != 0 ) namePostPV = postPV -> GetName();
	else namePostPV = "outside";
	// // Position
	G4ThreeVector prePos = step -> GetPreStepPoint() -> GetPosition();
	G4ThreeVector postPos = step -> GetPostStepPoint() -> GetPosition();

	// It's time to fill root file. First, information must be passed to event action.
	// We care of only the particles hit any sensor.
	if ( namePostPV == "sensor" )
	{
    // Set Event ID
    //fEveAct -> SetEventID (G4EventManager::GetEventManager()->GetConstCurrentEvent()->GetEventID());
		// Set track ID
		fEveAct -> SetTrackID(trackID);
		// Set particle name
		fEveAct -> SetParName(trackID, parName);
		// Set particle ID
		fEveAct -> SetParID(trackID, parID);
		// Set position
		fEveAct -> SetPos(trackID, postPos);
	}

	// Vervose
//	G4cout << "PID: " << parName << ", LV: " << step -> GetPreStepPoint() -> GetPhysicalVolume() -> GetLogicalVolume() -> GetName() << G4endl;
//	G4cout << "PID: " << parName << ", Position: From ("
//	       << prePos.x()  << ", " << prePos.y()  << ", " << prePos.z()  << ") to ("
//	       << postPos.x() << ", " << postPos.y() << ", " << postPos.z() << ")" << G4endl;
}
