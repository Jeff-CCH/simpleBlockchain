#include "blockchain.h"

BlockChain::BlockChain(uint32_t difficulty) : difficulty(difficulty) {
    genFirstBlock();
    cout << "init BlockChain complete\n";
}

void BlockChain::genFirstBlock() {
    Block firstBlock(0, "This is Genisis Block\n");
    firstBlock.sHashPrev = "0";
    firstBlock.mine(this->difficulty);
    blockchain.push_back(firstBlock);
}

bool BlockChain::addBlock(Block &newBlock) {
    newBlock.sHashPrev = getLastBlock().getHash();
    newBlock.mine(difficulty); //mine block
    //send to others to verify the integrity
    //after confirmed, add to blockchain
    blockchain.push_back(newBlock);
    return true;
}

Block BlockChain::getLastBlock() const {
    return blockchain.back();
}

void BlockChain::displayChain() const {
    for (auto &b : blockchain) {
        printf("Block#%d Data: %s Hash:%s Prev Hash: %s\n", b.index, 
                                                            b.sData.c_str(),
                                                            b.sHash.c_str(),
                                                            b.sHashPrev.c_str());
    }
}
