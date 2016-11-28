#include <cmath>
#include <vector>
#include <cstdlib>
#include <fstream>
#include "Utilities\vecdef.h"
#include "Utilities\vardef.h"
#include "Solver\RK4\rk4.h"

class Run{
  protected:
    double1D sp;
    double3D K;
    double Te, Tg, dt;

  public:
    virtual void read(){}
    virtual void solve_rxn(){}
    virtual void write(){}

}

int main(){
  Run a;
  a.read();
  a.solve_rxn();
  a.write();

  return 0;
}
