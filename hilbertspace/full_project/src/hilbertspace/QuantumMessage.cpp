#include <iostream>
#include <fstream>
#include <iomanip>
#include <random>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "include/hilbertspace/QuantumChannel.hpp"
#include "include/hilbertspace/LinkedList.hpp"
using namespace std;

//declare variables


//function prototypes


//main function 
int main(){

        LinkedList<QuantumChannel> quantumInformationChannel_1;
        QuantumChannel ChannelName;
    
        QuantumChannel Message_1;
        
    
        //Channel Descriptor
        ChannelName.messageDescriptor(0, "QuantumInformationChannel_1");
    
        //Message_1
        Message_1.messageDescriptor(1, "Message_1");
        Message_1.initialize(0, 1, 100);
        Message_1.generateRandomDistribution(.01,100);
    	  Message_1.generateEnergyField(1000, 1, 100);
        Message_1.generateHamiltonian(8);
    	  Message_1.generateQuantumChannel(2,4,16);
    	  Message_1.encodeQuantumInformation();
    	  Message_1.displayQuantumInformation();
        Message_1.MonteCarloRandomWalker(10000,1000, .5);
        Message_1.deallocateMemory();
    
        
    
        //Channel
        quantumInformationChannel_1.appendNode(ChannelName);
        quantumInformationChannel_1.appendNode(Message_1);
        
    
        cout << "QuantumInformationChannel: " << endl;
        quantumInformationChannel_1.displayList();
    
	return 0;
}
