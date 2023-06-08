#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include <random>
using namespace std;


#ifndef QUANTUMCHANNEL_HPP
#define QUANTUMCHANNEL_HPP

class QuantumChannel
{

    private:
    
    
        string message_header;
        int block_index;
        int i, j, N, dim, mini, maxi;
        int dim_qubit, dim_bell, dim_monte;
        double step, a, b;
        double *d000, *d001, *d010, *d100, *d011, *d101, *d110, *d111;
        double *r000, *r001, *r010, *r100, *r011, *r101, *r110, *r111;
    
        double **Hm;
        double **HmQubit, **HmBell, **HmMonte;
    
        double *a0, *b1;
        double *a00, *b01, *c10, *d11;
        double *a0000, *b0001, *c0010, *d0011, *e0100, *f0101, *g0110, *h0111, *i1000, *j1001, *k1010, *l1011, *m1100, *n1101, *o1110, *p1111;
    
        double *E000, *E001, *E010, *E100, *E011, *E101, *E110, *E111;
    
    //MonteCarlo Walker
        int max_trials, number_walks;
        double move_probability;
    
        int *walk_cumulative0000;
        int *walk_cumulative0001;
        int *walk_cumulative0010;
        int *walk_cumulative0011;
        int *walk_cumulative0100;
        int *walk_cumulative0101;
        int *walk_cumulative0110;
        int *walk_cumulative0111;
        int *walk_cumulative1000;
        int *walk_cumulative1001;
        int *walk_cumulative1010;
        int *walk_cumulative1011;
        int *walk_cumulative1100;
        int *walk_cumulative1101;
        int *walk_cumulative1110;
        int *walk_cumulative1111;
    
        int *walk2_cumulative0000;
        int *walk2_cumulative0001;
        int *walk2_cumulative0010;
        int *walk2_cumulative0011;
        int *walk2_cumulative0100;
        int *walk2_cumulative0101;
        int *walk2_cumulative0110;
        int *walk2_cumulative0111;
        int *walk2_cumulative1000;
        int *walk2_cumulative1001;
        int *walk2_cumulative1010;
        int *walk2_cumulative1011;
        int *walk2_cumulative1100;
        int *walk2_cumulative1101;
        int *walk2_cumulative1110;
        int *walk2_cumulative1111;
    
        int position_0000, position_0001, position_0010, position_0011, position_0100, position_0101, position_0110, position_0111, position_1000, position_1001, position_1010, position_1011, position_1100, position_1101,
            position_1110, position_1111;
        double average_0000, average_0001, average_0010, average_0011, average_0100, average_0101, average_0110, average_0111, average_1000, average_1001, average_1010, average_1011, average_1100, average_1101,
            average_1110, average_1111;
        double average2_0000, average2_0001, average2_0010, average2_0011, average2_0100, average2_0101, average2_0110, average2_0111, average2_1000, average2_1001, average2_1010, average2_1011, average2_1100, average2_1101,
            average2_1110, average2_1111;
        double variance_0000, variance_0001, variance_0010, variance_0011, variance_0100, variance_0101, variance_0110, variance_0111, variance_1000, variance_1001, variance_1010, variance_1011, variance_1100, variance_1101,
            variance_1110, variance_1111;
        double ranNum_0000, ranNum_0001, ranNum_0010, ranNum_0011, ranNum_0100, ranNum_0101, ranNum_0110, ranNum_0111, ranNum_1000, ranNum_1001, ranNum_1010, ranNum_1011, ranNum_1100, ranNum_1101,
            ranNum_1110, ranNum_1111;
    
   /* struct qubit{
        
        double *a0;
        double *b1;
        
     };
    
    struct bellState{
        
        double *a00;
        double *b01;
        double *c10;
        double *d11;
        
     };
    
   struct monteCarlo{
        
        double *a0000;
        double *b0001;
        double *c0010;
        double *d0011;
        double *e0100;
        double *f0101;
        double *g0110;
        double *h0111;
        double *i1000;
        double *j1001;
        double *k1010;
        double *l1011;
        double *m1100;
        double *n1101;
        double *o1110;
        double *p1111;
        
    };
    */
	public:
    
        virtual void setmessageDescriptor(int, string);
        virtual int getBlockIndex() const;
        virtual string getMessageHeader() const;
        double initialize(int, int, int);
        void generateRandomDistribution(double, int);
        void generateEnergyField(int, int, int);
        void generateHamiltonian(int);
        void generateQuantumChannel(int, int, int);
        void encodeQuantumInformation();
        void displayQuantumInformation();
        void MonteCarloRandomWalker(int, int, double);
        //void displayRadial();
        void deallocateMemory();
    
    friend ostream &operator << (ostream &, const QuantumChannel &);

};


#endif

