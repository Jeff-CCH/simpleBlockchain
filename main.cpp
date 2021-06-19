/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include "sha256.h"
#include <sstream>
#include "blockchain.h"

using namespace std;

int main()
{
 //   cout<<"Hello World";
    
    BlockChain JBC(1);
    string data = "This is the first user block";
    Block J1(1, data);
    JBC.addBlock(J1);
    JBC.displayChain();
    cout << "BlockChain Test Succeeed!" << endl;
    
    return 0;
}
