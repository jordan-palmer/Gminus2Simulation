#ifndef BFIELDEVEACT_h
#define BFIELDEVEACT_h 1

#include "G4UserEventAction.hh" 
#include <map>

class G4Event;

class BFieldEveAct: public G4UserEventAction
{
  public:
	BFieldEveAct();
	virtual ~BFieldEveAct();

	virtual void BeginOfEventAction(const G4Event*);
	virtual void EndOfEventAction(const G4Event*);

  void SetEventID (G4int);
	void SetTrackID(G4int);
	void SetParName(G4int, G4String);
	void SetParID(G4int, G4int);
	void SetPos(G4int, G4ThreeVector);

private:
  G4int eventID;
	std::map<G4int, G4int> trackID;
	std::map<G4int, G4String> parName;
	std::map<G4int, G4int> parID;
	std::map<G4int, G4ThreeVector> pos;
};

#endif
