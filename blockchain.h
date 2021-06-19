#include <iostream>
#include <list>
#include "block.h"

using namespace std;

class BlockChain {
  public:
    uint32_t difficulty;
    BlockChain(uint32_t difficulty);
    bool addBlock(Block &newBlock);
    Block getLastBlock() const;
    void displayChain() const;
  private:
    list<Block> blockchain;
    void genFirstBlock();
};
