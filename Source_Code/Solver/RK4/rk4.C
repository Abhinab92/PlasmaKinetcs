#include "rk4.h"

reaction::reaction(int size){
  sp1.resize(size);
  sp2.resize(size);
  sp3.resize(size);
  sp4.resize(size);
  k.resize(size);
  k1.resize(size);
  k2.resize(size);
  k3.resize(size);
  k4.resize(size);
  iter = 0;
}

void reaction::solve_rxn(){
  reaction(sp.size());
  iter = int(end_time/dt);
  for (int i = 0; i < iter; i++){
    sp1 = sp;
    calc_change(k1,sp1);
    calc_val(sp2,sp1,k1);
    calc_change(k2,sp2);
    calc_val(sp3,sp2,k2);
    calc_change(k3,sp3);
    calc_val(sp4,sp3,k3);
    calc_change(k4,sp4);
    k = k1/6.0 + k2/3.0 + k3/3.0 + k4/6.0;
    calc_val(sp,sp1,k);
  }
}

void reaction::calc_change(double1D t_k, double1D t_s){
  for (int x = 0; x < K.size(); x++){
    t_k[x] = 0.0;
    for (int y = 0; y < K[x].size(); y++){
      double temp = K[x][y][0];
      if (K[x][y][1] == double(1)){
        temp *= pow(300.0/Te,K[x][y][2]);
      }
      else if (K[x][y][1] == double(2)){
        temp *= pow(300.0/Tg,K[x][y][2]);
      }
      else if (K[x][y][1] == double(3)){
        temp *= exp(K[x][y][2]/Te);
      }
      for (int z = 3; z < K[x][y].size(); z++){
        temp *= t_s[K[x][y][z]];
      }
      t_k[x] += temp;
    }
    t_k[x] = t_s[x] + dt*t_k[x];
  }
}

void reaction::calc_val(double1D s1, double1D s2; double1D K1){
  s1 = s2 + dt*K1;
}
