#ifndef RK4_H_
#define RK4_H_

class reaction{
  private:
    std::vector<double> sp1, sp2, sp3, sp4;
    std::vector<double> k, k1, k2, k3, k4;
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

    void calc_change(std::vector<double> t_k, std::vector<double> t_s, double t){
      
    }

    void calc_val(){

    }
}

#endif
