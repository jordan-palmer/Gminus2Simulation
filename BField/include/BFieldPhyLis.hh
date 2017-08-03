#ifndef BFIELDPHYLIS_h
#define BFIELDPHYLIS_h 1

#include "G4VModularPhysicsList.hh"

class BFieldPhyLis: public G4VModularPhysicsList
{
public:
  BFieldPhyLis();
  virtual ~BFieldPhyLis();
  
  virtual void SetCuts();
};
#endif
