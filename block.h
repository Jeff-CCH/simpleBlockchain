#include <iostream>
#include <time.h>

using namespace std;

class Block {
  public:
    uint32_t index;
    time_t timestamp;
    string sData;
    string sHash;
    string sHashPrev;
    
    Block(uint32_t index, const string &data) : index(index), sData(data) {
        nOnce = -1;
    }
    void display() const;
    void mine(uint32_t difficulty);
    string getHash() const;
  private:
    int nOnce;
    string calculateHash() const;
};
