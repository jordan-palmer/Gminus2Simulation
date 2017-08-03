#include "G4DecayPhysics.hh"
#include "G4EmStandardPhysics.hh"
#include "G4EmExtraPhysics.hh"
#include "G4IonPhysics.hh"
#include "G4StoppingPhysics.hh"
#include "G4HadronElasticPhysics.hh"
#include "G4NeutronTrackingCut.hh"

#include "G4DataQuestionaire.hh"
#include "G4HadronPhysicsQGSP_BERT.hh"

#include "BFieldPhyLis.hh"

BFieldPhyLis::BFieldPhyLis():  G4VModularPhysicsList()
{
  G4DataQuestionaire it(photon);

  defaultCutValue = 0.1*CLHEP::mm;
  SetVerboseLevel(2);

  // EM Physics
  RegisterPhysics( new G4EmStandardPhysics() );

  // Synchroton Radiation & GN Physics
  RegisterPhysics( new G4EmExtraPhysics() );

  // Decays
  RegisterPhysics( new G4DecayPhysics() );

  // Hadron Elastic scattering
  RegisterPhysics( new G4HadronElasticPhysics() );

  // Hadron Physics
  RegisterPhysics( new G4HadronPhysicsQGSP_BERT() );

  // Stopping Physics
  RegisterPhysics( new G4StoppingPhysics() );

  // Ion Physics
  RegisterPhysics( new G4IonPhysics() );

  // Neutron tracking cut
  RegisterPhysics( new G4NeutronTrackingCut() );

}

BFieldPhyLis::~BFieldPhyLis()
{
}

void BFieldPhyLis::SetCuts()
{
  // Use default cut values gamma and e processes
  SetCutsWithDefault();   
}
