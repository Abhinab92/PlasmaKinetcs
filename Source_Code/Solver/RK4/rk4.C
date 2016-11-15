#include <vector>
#include "../../Utilities/vecdef.h"
#include "rk4.h"

reaction::solve_rxn(std::vector<double> sp, double end_time, double dt){
  reaction(sp.size());
  for (int i = 0; i < iter; i++){
    sp1 = sp;
    calc_change(k1,sp1,dt);
    calc_val(sp2,sp1,k1,dt);
    calc_change(k2,sp2,dt/double(2));
    calc_val(sp3,sp2,k2,dt/double(2));
    calc_change(k3,sp3,dt/double(2));
    calc_val(sp4,sp3,k3,dt/double(2));
    calc_change(k4,sp4,dt);
    k = k1/double(6) + k2/double(3) + k3/double(3) + k4/double(6);
    calc_val(sp,sp1,k,dt);
  }
}
