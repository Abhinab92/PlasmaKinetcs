#include "read.h"

Read::Read(){
  myfile.open("../../input.txt");
}

Read::read_file(){
  std::string temp_file;
  if (myfile.is_open()){
    myfile.ignore(1000,'\n');
    myfile.ignore(1000,'\n');
    myfile.ignore(1000,'=');
    myfile.ignore(1000,' ');
    getline(myfile,temp);
    rxn_file = "../../Reaction_Mechanisms/" + temp;
    myfile.ignore(1000,'=');
    myfile.ignore(1000,' ');
    getline(myfile,temp);
    thermo_file = "../../Thermodynamics/" + temp;
    myfile.ignore(1000,'=');
    myfile.ignore(1000,' ');
    getline(myfile,temp);
    Te = std::stod(temp);
    myfile.ignore(1000,'=');
    myfile.ignore(1000,' ');
    getline(myfile,temp);
    Tg = std::stod(temp);
    myfile.ignore(1000,'=');
    myfile.ignore(1000,' ');
    getline(myfile,temp);
    end_time = std::stod(temp);
    myfile.ignore(1000,'=');
    myfile.ignore(1000,' ');
    getline(myfile,temp);
    dt = std::stod(temp);
  }
}

Read::~Read(){
  myfile.close();
}
