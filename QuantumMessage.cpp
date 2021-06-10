#include <iostream>
#include <fstream>
#include <iomanip>
#include <random>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "QuantumChannel.hpp"
#include "LinkedList.hpp"
using namespace std;

//declare variables


//function prototypes


//main function 
int main(){

        LinkedList<QuantumChannel> quantumInformationChain_1;
        QuantumChannel ChainName;
    
        QuantumChannel Message_1;
        QuantumChannel Message_2;
        QuantumChannel Message_3;
        QuantumChannel Message_4;
        QuantumChannel Message_5;
        QuantumChannel Message_6;
        QuantumChannel Message_7;
    
        //BlockChain Descriptor
        ChainName.messageDescriptor(0, "QuantumInformationChain_1");
    
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
    
        //Message_2
        Message_2.messageDescriptor(2, "Message_2");
        Message_2.initialize(0, 1, 100);
        Message_2.generateRandomDistribution(.01,100);
        Message_2.generateEnergyField(1000, 1, 100);
        Message_2.generateHamiltonian(8);
        Message_2.generateQuantumChannel(2,4,16);
        Message_2.encodeQuantumInformation();
        Message_2.displayQuantumInformation();
        Message_2.MonteCarloRandomWalker(10000,1000, .5);
        Message_2.deallocateMemory();
    
        //Message_3
        Message_3.messageDescriptor(3, "Message_3");
        Message_3.initialize(0, 1, 100);
        Message_3.generateRandomDistribution(.01,100);
        Message_3.generateEnergyField(1000, 1, 100);
        Message_3.generateHamiltonian(8);
        Message_3.generateQuantumChannel(2,4,16);
        Message_3.encodeQuantumInformation();
        Message_3.displayQuantumInformation();
        Message_3.MonteCarloRandomWalker(10000,1000, .5);
        Message_3.deallocateMemory();
    
        //Message_4
        Message_4.messageDescriptor(4, "Message_4");
        Message_4.initialize(0, 1, 100);
        Message_4.generateRandomDistribution(.01,100);
        Message_4.generateEnergyField(1000, 1, 100);
        Message_4.generateHamiltonian(8);
        Message_4.generateQuantumChannel(2,4,16);
        Message_4.encodeQuantumInformation();
        Message_4.displayQuantumInformation();
        Message_4.MonteCarloRandomWalker(10000,1000, .5);
        Message_4.deallocateMemory();
    
        //Messasge_5
        Message_5.messageDescriptor(5, "Message_5");
        Message_5.initialize(0, 1, 100);
        Message_5.generateRandomDistribution(.01,100);
        Message_5.generateEnergyField(1000, 1, 100);
        Message_5.generateHamiltonian(8);
        Message_5.generateQuantumChannel(2,4,16);
        Message_5.encodeQuantumInformation();
        Message_5.displayQuantumInformation();
        Message_5.MonteCarloRandomWalker(10000,1000, .5);
        Message_5.deallocateMemory();

        //Message_6
        Message_6.messageDescriptor(6, "Message_6");
        Message_6.initialize(0, 1, 100);
        Message_6.generateRandomDistribution(.01,100);
        Message_6.generateEnergyField(1000, 1, 100);
        Message_6.generateHamiltonian(8);
        Message_6.generateQuantumChannel(2,4,16);
        Message_6.encodeQuantumInformation();
        Message_6.displayQuantumInformation();
        Message_6.MonteCarloRandomWalker(10000,1000, .5);
        Message_6.deallocateMemory();
    
        //Message_7
        Message_7.messageDescriptor(7, "Message_7");
        Message_7.initialize(0, 1, 100);
        Message_7.generateRandomDistribution(.01,100);
        Message_7.generateEnergyField(1000, 1, 100);
        Message_7.generateHamiltonian(8);
        Message_7.generateQuantumChannel(2,4,16);
        Message_7.encodeQuantumInformation();
        Message_7.displayQuantumInformation();
        Message_7.MonteCarloRandomWalker(10000,1000, .5);
        Message_7.deallocateMemory();
    
        //BlockChain
        quantumInformationChain_1.appendNode(ChainName);
        quantumInformationChain_1.appendNode(Message_1);
        quantumInformationChain_1.appendNode(Message_2);
        quantumInformationChain_1.appendNode(Message_3);
        quantumInformationChain_1.appendNode(Message_4);
        quantumInformationChain_1.appendNode(Message_5);
        quantumInformationChain_1.appendNode(Message_6);
        quantumInformationChain_1.appendNode(Message_7);
    
        cout << "QuantumInformationBlockChain: " << endl;
        quantumInformationChain_1.displayList();
    
	return 0;
}
