#include "BFieldActIni.hh"
#include "BFieldPriGenAct.hh"
#include "BFieldSteAct.hh"
#include "BFieldEveAct.hh"
//#include "BFieldSteAct.hh"
#include "BFieldRunAct.hh"


BFieldActIni::BFieldActIni() : G4VUserActionInitialization()
{}

BFieldActIni::~BFieldActIni()
{}

void BFieldActIni::BuildForMaster() const 
{
  SetUserAction(new BFieldRunAct);
}

void BFieldActIni::Build() const
{
  SetUserAction(new BFieldPriGenAct);
  SetUserAction(new BFieldRunAct);
  
  BFieldEveAct* BFieldA = new BFieldEveAct;
  SetUserAction(BFieldA);
  SetUserAction(new BFieldSteAct(BFieldA));
}  
