#include <sstream>
#include "block.h"
#include "sha256.h"

string Block::calculateHash() const {
    stringstream ss;
    ss << index << timestamp << nOnce << sData << sHashPrev;
    return sha256(ss.str());
}

void Block::mine(uint32_t difficulty) {
    char result[difficulty + 1];
    //get hash value
    for (int i = 0; i < difficulty; i++) {
        result[i] = '0';
    }
    result[difficulty] = '\0';
    string prefix = string(result);
    //printf("Mining the %d block...\n", this->index);
    do {
        this->nOnce++;
        this->timestamp = time(nullptr);
        this->sHash = calculateHash();
        printf("Mining the %d block: try hash %s\n", this->index, 
                                                   this->sHash.c_str());
    } while (this->sHash.substr(0, difficulty) != prefix);
    
    cout << "Block mined: " << (this->sHash) << endl;
}

string Block::getHash() const {
    return sHash;
}
