#ifndef READ_H_
#define READ_H_

#include <fstream>
#include <string>

class Read : public Run{
  private:
    std::string rxn_file, thermo_file;
    ifstream myfile;

  public:
    Read();
    void read_file();
    ~Read();
}

#endif
