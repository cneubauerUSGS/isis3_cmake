#include <iostream>
#include "iException.h"
#include "CameraFactory.h"
#include "Pvl.h"
#include "Preference.h"

using namespace std;

int main(int argc, char *argv[]) {
  Isis::Preference::Preferences(true);
  void doit(Isis::Pvl & lab);

  cerr << "Unit test for CameraFactory" << endl;
  cerr << "Testing missing Instrument Group ..." << endl;
  Isis::Pvl lab;
  doit(lab);

  lab.AddGroup(Isis::PvlGroup("Kernels"));

  cerr << "Testing missing spacecraft name ..." << endl;
  lab.AddGroup(Isis::PvlGroup("Instrument"));
  doit(lab);

  cerr << "Testing missing instrument id ..." << endl;
  Isis::PvlGroup &inst = lab.FindGroup("Instrument");
  inst += Isis::PvlKeyword("SpacecraftName", "Bogus Spacecraft");
  doit(lab);

  cerr << "Testing unsupported camera mode ..." << endl;
  inst += Isis::PvlKeyword("InstrumentId", "Bogus Instrument");
  doit(lab);
}

void doit(Isis::Pvl &lab) {
  try {
    cerr << "Version: ";
    cerr << Isis::CameraFactory::CameraVersion(lab) << endl;
  }
  catch(Isis::iException &error) {
    error.Report(false);
  }

  cerr << endl;

  try {
    Isis::CameraFactory::Create(lab);
  }
  catch(Isis::iException &error) {
    error.Report(false);
  }

  cerr << endl;
}



