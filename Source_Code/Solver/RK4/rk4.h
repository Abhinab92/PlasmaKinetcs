#ifndef RK4_H_
#define RK4_H_

class reaction{
  private:
    double1D sp1, sp2, sp3, sp4;
    double1D k, k1, k2, k3, k4;
    int iter;

  public:
    reaction(int size){
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

    void calc_change(double1D t_k, double1D t_s, double3D K, double t, double T){
      for (int x = 0; x < K.size(); x++){
        t_k[x] = 0.0;
        for (int y = 0; y < K[x].size(); y++){
          double temp = K[x][y][0]; // needs to be changed
          for (int z = 1; z < K[x][y].size(); z++){
            temp *= t_s[K[x][y][z]];
          }
          t_k[x] += temp;
        }
        t_k[x] = t_s[x] + t*t_k[x];
      }
    }

    void calc_val(double1D s1, double1D s2; double1D K, double1D t){
      s1 = s2 + t*K;
    }
}

#endif
