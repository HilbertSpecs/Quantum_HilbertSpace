#include <iostream>
#include <fstream>
#include <iomanip>
#include <random>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "include/hilbertspace/QuantumChannel.hpp"
using namespace std;

void QuantumChannel::setmessageDescriptor(int bl_ind, string mes_hd){
    block_index = bl_ind;
    message_header = mes_hd;
}

int QuantumChannel::getBlockIndex() const {
    return block_index;
}

string QuantumChannel::getMessageHeader() const {
    return message_header;
}

double QuantumChannel::initialize(int min, int max, int num){
    
    a = min;
    b = max;
    N = num;
    
    step = (b - a)/N;
    
    d000 = new double[N];
    d001 = new double[N];
    d010 = new double[N];
    d100 = new double[N];
    d011 = new double[N];
    d101 = new double[N];
    d110 = new double[N];
    d111 = new double[N];
    
    r000 = new double[N];
    r001 = new double[N];
    r010 = new double[N];
    r100 = new double[N];
    r011 = new double[N];
    r101 = new double[N];
    r110 = new double[N];
    r111 = new double[N];
    
    for(i = 0; i < N;i++)
    {
        d000[i] = 0;
        d001[i] = 0;
        d010[i] = 0;
        d100[i] = 0;
        d011[i] = 0;
        d101[i] = 0;
        d110[i] = 0;
        d111[i] = 0;
    }
    
    for(i = 0; i < N;i++)
    {
        r000[i] = 0;
        r001[i] = 0;
        r010[i] = 0;
        r100[i] = 0;
        r011[i] = 0;
        r101[i] = 0;
        r110[i] = 0;
        r111[i] = 0;
    }
    
    cout << "step: " << step << endl;
    
    return step;
}

void QuantumChannel::generateRandomDistribution(double st, int num){
    
    step = st;
    N = num;
    
    unsigned seed = time(0);
    srand(seed);
    
    for(i = 0; i < N;i++){
        
        d000[i] = step + d000[i-1];
        d001[i] = step + d001[i-1];
        d010[i] = step + d010[i-1];
        d100[i] = step + d100[i-1];
        d011[i] = step + d011[i-1];
        d101[i] = step + d101[i-1];
        d110[i] = step + d110[i-1];
        d111[i] = step + d111[i-1];
        
        cout << d000[i] << setw(5) << d001[i] << setw(5) << d010[i] << setw(5) <<
        d100[i] << setw(5) << d011[i] << setw(5) << d101[i] << setw(5) <<
        d110[i] << setw(5) << d111[i] << endl;
        
    }
    
    cout << "RandomState: (Non-Normalized)" << endl;
    for(i = 0; i < N;i++){
        /*
         r000[i] = rand()/((double) RAND_MAX);
         r001[i] = rand()/((double) RAND_MAX);
         r010[i] = rand()/((double) RAND_MAX);
         r100[i] = rand()/((double) RAND_MAX);
         r011[i] = rand()/((double) RAND_MAX);
         r101[i] = rand()/((double) RAND_MAX);
         r110[i] = rand()/((double) RAND_MAX);
         r111[i] = rand()/((double) RAND_MAX);
         */
        r000[i] = rand()/((double) RAND_MAX);
        r001[i] = rand()/((double) RAND_MAX);
        r010[i] = rand()/((double) RAND_MAX);
        r100[i] = rand()/((double) RAND_MAX);
        r011[i] = rand()/((double) RAND_MAX);
        r101[i] = rand()/((double) RAND_MAX);
        r110[i] = rand()/((double) RAND_MAX);
        r111[i] = rand()/((double) RAND_MAX);
        
        cout << setprecision(7) << r000[i] << setw(5) << r001[i] << setw(5) << r010[i] << setw(5) <<
        r100[i] << setw(5) << r011[i] << setw(5) << r101[i] << setw(5) <<
        r110[i] << setw(5) << r111[i] << endl;
        
    }
    
}

void QuantumChannel::generateEnergyField(int minim, int maxim, int num){
    
    mini = minim;
    maxi = maxim;
    
    N = num;
    
    unsigned seed = time(0);
    srand(seed);
    
    E000 = new double[N];
    E001 = new double[N];
    E010 = new double[N];
    E100 = new double[N];
    E011 = new double[N];
    E101 = new double[N];
    E110 = new double[N];
    E111 = new double[N];
    
    for(i = 0; i < N;i++){
        E000[i] = 0;
        E001[i] = 0;
        E010[i] = 0;
        E100[i] = 0;
        E011[i] = 0;
        E101[i] = 0;
        E110[i] = 0;
        E111[i] = 0;
    }
    cout << "Energy Field: (mJ)" << endl;
    for(i = 0; i < N;i++){
        
        E000[i] = - (rand()% mini + maxi);
        E001[i] = - (rand()% mini + maxi);
        E010[i] = - (rand()% mini + maxi);
        E100[i] = - (rand()% mini + maxi);
        E011[i] = - (rand()% mini + maxi);
        E101[i] = - (rand()% mini + maxi);
        E110[i] = - (rand()% mini + maxi);
        E111[i] = - (rand()% mini + maxi);
        
        cout << setprecision(7) << E000[i] << setw(5) << E001[i] << setw(5) << E010[i] << setw(5) <<
        E100[i] << setw(5) << E011[i] << setw(5) << E101[i] << setw(5) <<
        E110[i] << setw(5) << E111[i] << endl;
        
    }
    
}

void QuantumChannel::generateHamiltonian(int d){
    
    dim = d;
    Hm = new double*[dim];
    
    for(i = 0; i < dim;i++)
        Hm[i] = new double[dim];
    
    for(i = 0; i < dim;i++){
        for(j = 0; j < dim;j++){
            Hm[i][j] = 0;
        }
    }
    cout << "Hamiltonian: " << endl;
    for(i = 0; i < dim;i++){
        for(j = 0; j < dim;j++){
            Hm[i][j] = rand()/((double) RAND_MAX);
            cout << Hm[i][j];
        }
        cout << endl;
    }
    
}

void QuantumChannel::generateQuantumChannel(int di_qu, int di_be, int di_mon){
    
    dim_qubit = di_qu;
    dim_bell = di_be;
    dim_monte = di_mon;
    
    HmQubit = new double*[dim_qubit];
    HmBell = new double*[dim_bell];
    HmMonte = new double*[dim_monte];
    
    a0 = new double[N];
    b1 = new double[N];
    
    a00 = new double[N];
    b01 = new double[N];
    c10 = new double[N];
    d11 = new double[N];
    
    a0000 = new double[N];
    b0001 = new double[N];
    c0010 = new double[N];
    d0011 = new double[N];
    e0100 = new double[N];
    f0101 = new double[N];
    g0110 = new double[N];
    h0111 = new double[N];
    i1000 = new double[N];
    j1001 = new double[N];
    k1010 = new double[N];
    l1011 = new double[N];
    m1100 = new double[N];
    n1101 = new double[N];
    o1110 = new double[N];
    p1111 = new double[N];
    
    for(i = 0; i < dim_qubit;i++)
        HmQubit[i] = new double[dim_qubit];
    for(i = 0; i < dim_bell;i++)
        HmBell[i] = new double[dim_bell];
    for(i = 0; i < dim_monte;i++)
        HmMonte[i] = new double[dim_monte];
    
    for(i = 0; i < N;i++){
        
        a0[i] = 0;
        b1[i] = 0;
        
        a00[i] = 0;
        b01[i] = 0;
        c10[i] = 0;
        d11[i] = 0;
        
        a0000[i] = 0;
        b0001[i] = 0;
        c0010[i] = 0;
        d0011[i] = 0;
        e0100[i] = 0;
        f0101[i] = 0;
        g0110[i] = 0;
        h0111[i] = 0;
        i1000[i] = 0;
        j1001[i] = 0;
        k1010[i] = 0;
        l1011[i] = 0;
        m1100[i] = 0;
        n1101[i] = 0;
        o1110[i] = 0;
        p1111[i] = 0;
    }
    for(i=0;i < dim_qubit;i++){
        for(j = 0; j < dim_qubit;j++){
            HmQubit[i][j] = 0;
        }
    }
    for(i = 0; i < dim_bell;i++){
        for(j = 0; j < dim_bell;j++){
            HmBell[i][j] = 0;
        }
    }
    for(i = 0; i < dim_monte;i++){
        for(j = 0; j < dim_monte;j++){
            HmMonte[i][j] = 0;
        }
    }
    
}

void QuantumChannel::encodeQuantumInformation(){
    
    for(i = 0; i < dim_qubit;i++){
        for(j = 0; j < dim_qubit;j++){
            HmQubit[i][j] = rand()/((double) RAND_MAX);
        }
    }
    for(i = 0; i < dim_bell;i++){
        for(j = 0; j < dim_bell;j++)
        {
            HmBell[i][j] = rand()/((double) RAND_MAX);
        }
    }
    for(i = 0; i < dim_monte;i++){
        for(j = 0; j < dim_monte;j++){
            HmMonte[i][j] = rand()/((double) RAND_MAX);
        }
    }
    
}

void QuantumChannel::displayQuantumInformation(){
    
    cout << "HmQubit[][]: " << endl;
    for(i=0;i < dim_qubit;i++){
        for(j = 0; j < dim_qubit;j++){
            cout << setprecision(4) << HmQubit[i][j] << setw(5);
        }
        cout << endl;
    }
    cout << "HmBell[][]: " << endl;
    for(i = 0; i < dim_bell;i++){
        for(j = 0; j < dim_bell;j++){
            cout << setprecision(4) << HmBell[i][j] << setw(5);
        }
        cout << endl;
    }
    cout << "HmMonte[][]: " << endl;
    for(i = 0; i < dim_monte;i++){
        for(j = 0; j < dim_monte;j++){
            cout << setprecision(4) << HmMonte[i][j] << setw(5);
        }
        cout << endl;
    }
    
}

void QuantumChannel::MonteCarloRandomWalker(int mx_tr, int num_wal, double mv_pr){
    
    unsigned seed = time(0);
    srand(seed);
    
    max_trials = mx_tr;
    number_walks = num_wal;
    move_probability = mv_pr;
    
    walk_cumulative0000 = new int[number_walks];
    walk_cumulative0001 = new int[number_walks];
    walk_cumulative0010 = new int[number_walks];
    walk_cumulative0011 = new int[number_walks];
    walk_cumulative0100 = new int[number_walks];
    walk_cumulative0101 = new int[number_walks];
    walk_cumulative0110 = new int[number_walks];
    walk_cumulative0111 = new int[number_walks];
    walk_cumulative1000 = new int[number_walks];
    walk_cumulative1001 = new int[number_walks];
    walk_cumulative1010 = new int[number_walks];
    walk_cumulative1011 = new int[number_walks];
    walk_cumulative1100 = new int[number_walks];
    walk_cumulative1101 = new int[number_walks];
    walk_cumulative1110 = new int[number_walks];
    walk_cumulative1111 = new int[number_walks];
    
    walk2_cumulative0000 = new int[number_walks];
    walk2_cumulative0001 = new int[number_walks];
    walk2_cumulative0010 = new int[number_walks];
    walk2_cumulative0011 = new int[number_walks];
    walk2_cumulative0100 = new int[number_walks];
    walk2_cumulative0101 = new int[number_walks];
    walk2_cumulative0110 = new int[number_walks];
    walk2_cumulative0111 = new int[number_walks];
    walk2_cumulative1000 = new int[number_walks];
    walk2_cumulative1001 = new int[number_walks];
    walk2_cumulative1010 = new int[number_walks];
    walk2_cumulative1011 = new int[number_walks];
    walk2_cumulative1100 = new int[number_walks];
    walk2_cumulative1101 = new int[number_walks];
    walk2_cumulative1110 = new int[number_walks];
    walk2_cumulative1111 = new int[number_walks];
    
    for(i = 0; i < number_walks;i++){
        
        walk_cumulative0000[i] = 0;
        walk_cumulative0001[i] = 0;
        walk_cumulative0010[i] = 0;
        walk_cumulative0011[i] = 0;
        walk_cumulative0100[i] = 0;
        walk_cumulative0101[i] = 0;
        walk_cumulative0110[i] = 0;
        walk_cumulative0111[i] = 0;
        walk_cumulative1000[i] = 0;
        walk_cumulative1001[i] = 0;
        walk_cumulative1010[i] = 0;
        walk_cumulative1011[i] = 0;
        walk_cumulative1100[i] = 0;
        walk_cumulative1101[i] = 0;
        walk_cumulative1110[i] = 0;
        walk_cumulative1111[i] = 0;
        
        walk2_cumulative0000[i] = 0;
        walk2_cumulative0001[i] = 0;
        walk2_cumulative0010[i] = 0;
        walk2_cumulative0011[i] = 0;
        walk2_cumulative0100[i] = 0;
        walk2_cumulative0101[i] = 0;
        walk2_cumulative0110[i] = 0;
        walk2_cumulative0111[i] = 0;
        walk2_cumulative1000[i] = 0;
        walk2_cumulative1001[i] = 0;
        walk2_cumulative1010[i] = 0;
        walk2_cumulative1011[i] = 0;
        walk2_cumulative1100[i] = 0;
        walk2_cumulative1101[i] = 0;
        walk2_cumulative1110[i] = 0;
        walk2_cumulative1111[i] = 0;
    }
    
    for(i = 0; i < max_trials;i++){
        
        position_0000 = 0;
        position_0001 = 0;
        position_0010 = 0;
        position_0011 = 0;
        position_0100 = 0;
        position_0101 = 0;
        position_0110 = 0;
        position_0111 = 0;
        position_1000 = 0;
        position_1001 = 0;
        position_1010 = 0;
        position_1011 = 0;
        position_1100 = 0;
        position_1101 = 0;
        position_1110 = 0;
        position_1111 = 0;
        
        for(j = 0; j < number_walks;j++){
            
            ranNum_0000 = rand()/((double) RAND_MAX);
            ranNum_0001 = rand()/((double) RAND_MAX);
            ranNum_0010 = rand()/((double) RAND_MAX);
            ranNum_0011 = rand()/((double) RAND_MAX);
            ranNum_0100 = rand()/((double) RAND_MAX);
            ranNum_0101 = rand()/((double) RAND_MAX);
            ranNum_0110 = rand()/((double) RAND_MAX);
            ranNum_0111 = rand()/((double) RAND_MAX);
            ranNum_1000 = rand()/((double) RAND_MAX);
            ranNum_1001 = rand()/((double) RAND_MAX);
            ranNum_1010 = rand()/((double) RAND_MAX);
            ranNum_1011 = rand()/((double) RAND_MAX);
            ranNum_1100 = rand()/((double) RAND_MAX);
            ranNum_1101 = rand()/((double) RAND_MAX);
            ranNum_1110 = rand()/((double) RAND_MAX);
            ranNum_1111 = rand()/((double) RAND_MAX);
            
            if(ranNum_0000 >= move_probability)
                position_0000 += 1;
            if(ranNum_0000 < move_probability)
                position_0000 -= 1;
            if(ranNum_0001 >= move_probability)
                position_0001 += 1;
            if(ranNum_0001 < move_probability)
                position_0001 -= 1;
            if(ranNum_0010 >= move_probability)
                position_0010 += 1;
            if(ranNum_0010 < move_probability)
                position_0010 -= 1;
            if(ranNum_0011 >= move_probability)
                position_0011 += 1;
            if(ranNum_0011 < move_probability)
                position_0011 -= 1;
            if(ranNum_0100 >= move_probability)
                position_0100 += 1;
            if(ranNum_0100 < move_probability)
                position_0100 -= 1;
            if(ranNum_0101 >= move_probability)
                position_0101 += 1;
            if(ranNum_0101 < move_probability)
                position_0101 -= 1;
            if(ranNum_0110 >= move_probability)
                position_0110 += 1;
            if(ranNum_0110 < move_probability)
                position_0110 -= 1;
            if(ranNum_0111 >= move_probability)
                position_0111 += 1;
            if(ranNum_0111 < move_probability)
                position_0111 -= 1;
            if(ranNum_1000 >= move_probability)
                position_1000 += 1;
            if(ranNum_1000 < move_probability)
                position_1000 -= 1;
            if(ranNum_1001 >= move_probability)
                position_1001 += 1;
            if(ranNum_1001 < move_probability)
                position_1001 -= 1;
            if(ranNum_1010 >= move_probability)
                position_1010 += 1;
            if(ranNum_1010 < move_probability)
                position_1010 -= 1;
            if(ranNum_1011 >= move_probability)
                position_1011 += 1;
            if(ranNum_1011 < move_probability)
                position_1011 -= 1;
            if(ranNum_1100 >= move_probability)
                position_1100 += 1;
            if(ranNum_1100 < move_probability)
                position_1100 -= 1;
            if(ranNum_1101 >= move_probability)
                position_1101 += 1;
            if(ranNum_1101 < move_probability)
                position_1101 -= 1;
            if(ranNum_1110 >= move_probability)
                position_1110 += 1;
            if(ranNum_1110 < move_probability)
                position_1110 -= 1;
            if(ranNum_1111 >= move_probability)
                position_1111 += 1;
            if(ranNum_1111 < move_probability)
                position_1111 -= 1;
            else
                NULL;
            
            walk_cumulative0000[i] += position_0000;
            walk2_cumulative0000[i] += pow(position_0000, 2);
            walk_cumulative0001[i] += position_0001;
            walk2_cumulative0001[i] += pow(position_0001,2);
            walk_cumulative0010[i] += position_0010;
            walk2_cumulative0010[i] += pow(position_0010,2);
            walk_cumulative0011[i] += position_0011;
            walk2_cumulative0011[i] += pow(position_0011,2);
            walk_cumulative0100[i] += position_0100;
            walk2_cumulative0100[i] += pow(position_0100, 2);
            walk_cumulative0101[i] += position_0101;
            walk2_cumulative0101[i] += pow(position_0101,2);
            walk_cumulative0110[i] += position_0110;
            walk2_cumulative0110[i] += pow(position_0110,2);
            walk_cumulative0111[i] += position_0111;
            walk2_cumulative0111[i] += pow(position_0111,2);
            walk_cumulative1000[i] += position_1000;
            walk2_cumulative1000[i] += pow(position_1000, 2);
            walk_cumulative1001[i] += position_1001;
            walk2_cumulative1001[i] += pow(position_1001,2);
            walk_cumulative1010[i] += position_1010;
            walk2_cumulative1010[i] += pow(position_1010,2);
            walk_cumulative1011[i] += position_1011;
            walk2_cumulative1011[i] += pow(position_1011, 2);
            walk_cumulative1100[i] += position_1100;
            walk2_cumulative1100[i] += pow(position_1100,2);
            walk_cumulative1101[i] += position_1101;
            walk2_cumulative1101[i] += pow(position_1101,2);
            walk_cumulative1110[i] += position_1110;
            walk2_cumulative1110[i] += pow(position_1110,2);
            walk_cumulative1111[i] += position_1111;
            walk2_cumulative1111[i] += pow(position_1111,2);
            
        }
        
    }
    
    for(i = 0; i < number_walks;i++)
    {
        average_0000 = walk_cumulative0000[i]/ ((double) max_trials);
        average2_0000 = walk2_cumulative0000[i]/((double) max_trials);
        variance_0000 = (average2_0000 - pow(average_0000,2));
        
        average_0001 = walk_cumulative0001[i]/((double) max_trials);
        average2_0001 = walk2_cumulative0001[i]/((double) max_trials);
        variance_0001 = (average2_0001 - pow(average_0001,2));
        
        average_0010 = walk_cumulative0010[i]/((double) max_trials);
        average2_0010 = walk2_cumulative0010[i]/((double) max_trials);
        variance_0010 = average2_0010 - pow(average_0010,2);
        
        average_0011 = walk_cumulative0011[i]/ ((double) max_trials);
        average2_0011 = walk2_cumulative0011[i]/((double) max_trials);
        variance_0011 = (average2_0011 - pow(average_0011,2));
        
        average_0100 = walk_cumulative0100[i]/((double) max_trials);
        average2_0100 = walk2_cumulative0100[i]/((double) max_trials);
        variance_0100 = (average2_0100 - pow(average_0100,2));
        
        average_0101 = walk_cumulative0101[i]/ ((double) max_trials);
        average2_0101 = walk2_cumulative0101[i]/((double) max_trials);
        variance_0101 = (average2_0101 - pow(average_0101,2));
        
        average_0110 = walk_cumulative0110[i]/((double) max_trials);
        average2_0110 = walk2_cumulative0110[i]/((double) max_trials);
        variance_0110 = (average2_0110 - pow(average_0110,2));
        
        average_0111 = walk_cumulative0111[i]/((double) max_trials);
        average2_0111 = walk2_cumulative0111[i]/((double) max_trials);
        variance_0111 = average2_0111 - pow(average_0111,2);
        
        average_1000 = walk_cumulative1000[i]/ ((double) max_trials);
        average2_1000 = walk2_cumulative1000[i]/((double) max_trials);
        variance_1000 = (average2_1000 - pow(average_1000,2));
        
        average_1001 = walk_cumulative1001[i]/((double) max_trials);
        average2_1001 = walk2_cumulative1001[i]/((double) max_trials);
        variance_1001 = (average2_1001 - pow(average_1001,2));
        
        average_1010 = walk_cumulative1010[i]/((double) max_trials);
        average2_1010 = walk2_cumulative1010[i]/((double) max_trials);
        variance_1010 = average2_1010 - pow(average_1010,2);
        
        average_1011 = walk_cumulative1011[i]/ ((double) max_trials);
        average2_1011 = walk2_cumulative1011[i]/((double) max_trials);
        variance_1011 = (average2_1011 - pow(average_1011,2));
        
        average_1100 = walk_cumulative1100[i]/((double) max_trials);
        average2_1100 = walk2_cumulative1100[i]/((double) max_trials);
        variance_1100 = (average2_1100 - pow(average_1100,2));
        
        average_1101 = walk_cumulative1101[i]/ ((double) max_trials);
        average2_1101 = walk2_cumulative1101[i]/((double) max_trials);
        variance_1101 = (average2_1101 - pow(average_1101,2));
        
        average_1110 = walk_cumulative1110[i]/((double) max_trials);
        average2_1110 = walk2_cumulative1110[i]/((double) max_trials);
        variance_1110 = (average2_1110 - pow(average_1110,2));
        
        average_1111 = walk_cumulative1111[i]/((double) max_trials);
        average2_1111 = walk2_cumulative1111[i]/((double) max_trials);
        variance_1111 = average2_1111 - pow(average_1111,2);
        
    }
    
    cout << "RandomWalker average: " << setprecision(2) << setw(5) << average_0000 << setw(5) << average_0001 << setw(5) << average_0010 << setw(5) << average_0011 << setw(5) << average_0100 << setw(5) << average_0101 << setw(5) << average_0110 << setw(5) << average_0111 << average_1000 << setw(5) << average_1001 << setw(5) << average_1010 << setw(5) << average_1011 << setw(5) << average_1100 << setw(5) << average_1101 << setw(5) << average_1110 << setw(5) << average_1111 << endl;
    
    cout << "RandomWalker variance: " << setprecision(5) <<  setw(10) << variance_0000 << setw(10) << variance_0001 << setw(10) << variance_0010 << setw(10) << variance_0011 << setw(10) << variance_0100 << setw(10) << variance_0101 << setw(10) << variance_0110 << setw(10) << variance_0111 << setw(10) << variance_1000 << setw(10) << variance_1001 << setw(10) << variance_1010 << setw(10) << variance_1011 << setw(10) << variance_1100 << setw(10) << variance_1101 << setw(10) << variance_1110 << setw(10) << variance_1111 << endl;
}

void QuantumChannel::deallocateMemory(){
    
    for(i = 0;i < dim;i++)
    {
        delete [] Hm[i];
    }
    
    for(i = 0; i < dim_qubit;i++)
    {
        delete [] HmQubit[i];
    }
    
    for(i = 0; i < dim_bell;i++)
    {
        delete [] HmBell[i];
    }
    
    for(i = 0; i < dim_monte;i++)
    {
        delete [] HmMonte[i];
    }
    
    delete [] Hm;
    delete [] HmQubit;
    delete [] HmBell;
    delete [] HmMonte;
    
    delete [] a0;
    delete [] b1;
    
    delete [] a00;
    delete [] b01;
    delete [] c10;
    delete [] d11;
    
    delete [] a0000;
    delete [] b0001;
    delete [] c0010;
    delete [] d0011;
    delete [] e0100;
    delete [] f0101;
    delete [] g0110;
    delete [] h0111;
    delete [] i1000;
    delete [] j1001;
    delete [] k1010;
    delete [] l1011;
    delete [] m1100;
    delete [] n1101;
    delete [] o1110;
    delete [] p1111;
    
    delete [] d000;
    delete [] d001;
    delete [] d010;
    delete [] d100;
    delete [] d011;
    delete [] d101;
    delete [] d110;
    delete [] d111;
    
    delete [] r000;
    delete [] r001;
    delete [] r010;
    delete [] r100;
    delete [] r011;
    delete [] r101;
    delete [] r110;
    delete [] r111;
    
    delete [] E000;
    delete [] E001;
    delete [] E010;
    delete [] E100;
    delete [] E011;
    delete [] E101;
    delete [] E110;
    delete [] E111;
    
    delete [] walk_cumulative0000;
    delete [] walk_cumulative0001;
    delete [] walk_cumulative0010;
    delete [] walk_cumulative0011;
    delete [] walk_cumulative0100;
    delete [] walk_cumulative0101;
    delete [] walk_cumulative0110;
    delete [] walk_cumulative0111;
    delete [] walk_cumulative1000;
    delete [] walk_cumulative1001;
    delete [] walk_cumulative1010;
    delete [] walk_cumulative1011;
    delete [] walk_cumulative1100;
    delete [] walk_cumulative1101;
    delete [] walk_cumulative1110;
    delete [] walk_cumulative1111;
    
    delete [] walk2_cumulative0000;
    delete [] walk2_cumulative0001;
    delete [] walk2_cumulative0010;
    delete [] walk2_cumulative0011;
    delete [] walk2_cumulative0100;
    delete [] walk2_cumulative0101;
    delete [] walk2_cumulative0110;
    delete [] walk2_cumulative0111;
    delete [] walk2_cumulative1000;
    delete [] walk2_cumulative1001;
    delete [] walk2_cumulative1010;
    delete [] walk2_cumulative1011;
    delete [] walk2_cumulative1100;
    delete [] walk2_cumulative1101;
    delete [] walk2_cumulative1110;
    delete [] walk2_cumulative1111;
    
    i = 0;
    j = 0;
    a = 0;
    b = 0;
    step = 0;
    dim = 0;
    N = 0;
    
    average_0000 = 0;
    average2_0000 = 0;
    variance_0000 = 0;
    
    average_0001 = 0;
    average2_0001 = 0;
    variance_0001 = 0;
    
    average_0010 = 0;
    average2_0010 = 0;
    variance_0010 = 0;
    
    average_0011 = 0;
    average2_0011 = 0;
    variance_0011 = 0;
    
    average_0100 = 0;
    average2_0100 = 0;
    variance_0100 = 0;
    
    average_0101 = 0;
    average2_0101 = 0;
    variance_0101 = 0;
    
    average_0110 = 0;
    average2_0110 = 0;
    variance_0110 = 0;
    
    average_0111 = 0;
    average2_0111 = 0;
    variance_0111 = 0;
    
    average_1000 = 0;
    average2_1000 = 0;
    variance_1000 = 0;
    
    average_1001 = 0;
    average2_1001 = 0;
    variance_1001 = 0;
    
    average_1010 = 0;
    average2_1010 = 0;
    variance_1010 = 0;
    
    average_1011 = 0;
    average2_1011 = 0;
    variance_1011 = 0;
    
    average_1100 = 0;
    average2_1100 = 0;
    variance_1100 = 0;
    
    average_1101 = 0;
    average2_1101 = 0;
    variance_1101 = 0;
    
    average_1110 = 0;
    average2_1110 = 0;
    variance_1110 = 0;
    
    average_1111 = 0;
    average2_1111 = 0;
    variance_1111 = 0;
    
}

ostream &operator << (ostream &strm, const QuantumChannel &obj)
{
    strm << obj.block_index << setw(10) << obj.message_header;
    return strm;
}
