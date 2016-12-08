#include <cmath>
#include <sstream>
#include <fstream>
#include "utility.h"

std::string species_info = "methane_air.txt";
double Te = 100.0*11604.0 //in K
double Tg = 300.0 // in K
double end_time = 1.0e-3 // in s
double dt = 1.0e-9; // in s
int iter = int(end_time/dt);
double R = 8.314; // Gas constat in J/mol.K

double3D K;
int size;
string1D species;
double1D sp;
double1D E;
double1D Cp;

void read_file();
void solve_rxn();
void calc_change(double1D, double1D);
void write_file();
void calc_temp();

int main(){
  read_file();
  solve_rxn();
  return 0;
}

void read_file(){
  ifstream myfile;
  myfile.open(species_info);
  myfile.close();
}

void solve_rxn(){
  double1D sp1, sp_temp;
  double1D k, k1, k2, k3, k4;
  sp1.resize(size);
  sp_temp.resize(size);
  k1.resize(size);
  k2.resize(size);
  k3.resize(size);
  k4.resize(size);
  write_file();
  for (int i = 0; i < iter; i++){
    //sp1 = sp;
    calc_change(k1,sp);
    sp_temp = sp + k1*(dt/2.0);
    calc_change(k2,sp_temp);
		sp_temp = sp + k2*(dt/2.0);
    calc_change(k3,sp_temp);
		sp_temp = sp + k3*dt;
    calc_change(k4,sp_temp);
    k = k1/6.0 + k2/3.0 + k3/3.0 + k4/6.0;
    sp += k*dt;
		calc_temp(k);
    if (i%100 == 99){
      write_file(i);
    }
  }
}

void calc_change(double1D t_k, double1D t_s){
	double temp;
  for (int x = 0; x < K.size(); x++){
    t_k[x] = 0.0;
    for (int y = 0; y < K[i].size(); y++){
      temp = K[x][y][0]*pow(300.0/Tg,K[x][y][1])*exp(K[x][y][2]/(R*Tg))*pow(300.0/Te,K[x][y][3]);
      for (int z = 4; z < K[x][y].size(); z++){
        temp *= t_s[K[x][y][z]];
      }
      t_k[x] += temp;
    }
  }
}

void calc_temp(double1D k){
	double dnE = 0.0;
	double n = 0.0;
	double nCp = 0.0;
	for (int i = 0; i < size; i++){
		dnE += (k[i]*E[i]);
		n += sp[i];
		nCp += (sp[i]*Cp[i]);
	}
	Tg += (dnE*n/nCp*dt*dt);
}

void write_file(int it = -1){
  std::ofstream myfile;
  std::stringstream stream;
  myfile.open("Output.txt", std::ofstream::app);
  stream << std::scientific << std::setprecision(1) << double((it+1)*dt);
  myfile << stream.str();
  for (int i = 0; i < size; i++){
    myfile << "\t" << std::to_string();
  }
  myfile << "\n";
  myfile.close();
}
