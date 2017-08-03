#ifndef BFIELDDETCON_h
#define BFIELDDETCON_h 1

#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4Element.hh"
#include "G4Material.hh"

class G4VPhysicalVolume;
class G4UniformMagField;

class BFieldDetCon: public G4VUserDetectorConstruction
{
public:
	BFieldDetCon(G4VPhysicalVolume*);
	virtual  ~BFieldDetCon();
	virtual G4VPhysicalVolume* Construct();

private:
	void DefineDimensions();
	void ConstructMaterials();
	void DestructMaterials();

private:
	G4VPhysicalVolume* world;

	G4Element* elN;
	G4Element* elO;
	G4Element* elAr;

	G4Material* Air;

  //G4double labX, labY, labZ;
	G4double   iR,   oR,   hZ;

	G4UniformMagField* magField;
};

#endif
