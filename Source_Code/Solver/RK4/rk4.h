#ifndef RK4_H_
#define RK4_H_

class reaction{
  private:
    double1D sp1, sp2, sp3, sp4;
    double1D k, k1, k2, k3, k4;
    int iter;

  public:
    reaction();
    void solve_rxn(double1D sp, double3D K, double T_e, double T_g, double end_time, double dt);
    void calc_change(double1D t_k, double1D t_s, double3D K);
    void calc_val(double1D s1, double1D s2; double1D K);
}

#endif
