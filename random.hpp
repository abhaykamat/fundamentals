//
//  random.h
//  fundamentals
//
//  Created by Andreas Fragner on 6/6/12.
//
//  RAND_MAX =  2147483647 on this machine 

#ifndef fundamentals_random_h
#define fundamentals_random_h

#include "initialize.hpp"
#include "errors.hpp"
#include "misc.hpp"

double uniformDouble(const double&, const double&);
int uniformInt(const int&, const int&);
unsigned long int binomialRand(const int&, const double&);
unsigned long int geometricRand( const double&);
double exponentialRand(const double&, const double&);
double poissonRand(const double&, const double&);
//double customRand(double,double,function_object??);
template <typename T> void KnuthShuffle(typename vector<T>::iterator,typename vector<T>::iterator);
template <typename T> T RandomLine(ifstream);
void testRandom();


//--------------------------------------------------------------------
//
// UNIFORM RAND DOUBLE AND INT
// uniform random variable on the interval [min,max]
//
//--------------------------------------------------------------------


double uniformDouble(const double& min, const double& max)
{
    RangeError e;
    
    try{
        if(min > max){ throw e; }
        return ((double) rand() / RAND_MAX) * (max-min) + min;
    }
    catch(RangeError &e){
        cout << "\n" << e.what() <<endl;
        return 0;
    }
}


int uniformInt(const int&min, const int& max)
{
    RangeError e;
    
    try{
        if(min > max){ throw e; }
        return ((int) rand()%(max-min) + min );
    }
    catch(RangeError &e){
        cout << "\n" << e.what() <<endl;
        return 0;
    }
}


//--------------------------------------------------------------------
//
// BINOMIAL RAND
// generates a binomial random variable with success probability p
// in n trials; via inverse transform method
//
//--------------------------------------------------------------------

unsigned long int binomialRand(const int& n, const double& p)
{
    double U = uniformDouble(0.0,1.0), x = pow((1-p),n), F = x;
    long unsigned int i = 0;
    
    while( i < RAND_MAX ) //just to avoid overflow
    {
        if( U < F ){ return i; }
        
        x *= ((n-i)/(i+1))*(p/(1-p)); //inverse CDF
        F += x;
        ++i;
    }
    return 0;
}


//--------------------------------------------------------------------
//
// GEOMETRIC RAND
// generates a geometric random variate on interval
// with success probability p, based on discrete inverse transform method
//
//--------------------------------------------------------------------


unsigned long int geometricRand( const double& p = 0.5 )
{
    ProbabilityError e;
    
    try {
        if( p > 1 || p < 0)
            throw e;
        
        return ((unsigned long int) log(1-uniformDouble(0.0,1.0)) / log(1-p) +1);
    }
    catch( ProbabilityError& e)
    {
        cout << e.what() << endl;
        return 0;
    }
}


//--------------------------------------------------------------------
// EXPONENTIAL RAND
// generates an exponential random variable with arrival rate lambda
// returns the arrival time between two events (in no units)
//--------------------------------------------------------------------

/*
 double exponentialRand(double lambda)
 {
 return -(1/lambda)*log( uniformRand(0,1) );
 }
 */

//--------------------------------------------------------------------
// POISSONIAN RAND
// generates a binomial random variable on interval [a
//--------------------------------------------------------------------

/*
 double poissonRand(double lambda, double t)
 {
 
 }
 */


//--------------------------------------------------------------------
// NORMAL RAND
// generates a normal random variable using Box-Mueller algorithm
//--------------------------------------------------------------------

/*
 double normalRand(double lambda, double t)
 {
 
 }
 */


//--------------------------------------------------------------------
// CUSTOM RAND
// generates a discrete random variate on interval [a,b] based on a discrete
// probability mass function given as input vector/deque/list ? what's best in this
// application? build this generic just like STL algorithms such that we can pass
// an arbitrary pair of iterators
//--------------------------------------------------------------------

/*
 double customRand(double,double,function_object_pointer)
 {
 
 }
 */


//--------------------------------------------------------------------
// CUSTOM RAND
// generates a random variate on interval [a,b] based on a custom CDF
// the CDF is passed as a function pointer or better yet, a function
// object
//--------------------------------------------------------------



//--------------------------------------------------------------------
// KNUTH SHUFFLE
// shuffle elements in a range by random permutation
// complexity O(n)
//--------------------------------------------------------------------


template <typename T> void KnuthShuffle( typename vector<T>::iterator start, typename vector<T>::iterator end )
{
    int range = (int) (end - start), i = 0;
    typename vector<T>::iterator it = start;
    
    while( start != end && i < (range-2) )
    {
        XOR_swap( &(*it), &(*(start + uniformInt(i, range-1)) ) );
        ++it; ++i;
    }
}


//--------------------------------------------------------------------
//
// RANDOMIZED LINE SELECTION ALGORITHM
// picks a uniform random line from a file with only ONE pass and returns it as a string
// uses the same trick as Knuth shuffle (see random.hpp)
//
//--------------------------------------------------------------------

template <typename T> T RandomLine(ifstream file)
{
    T line, rand_line;
    int k=0;
    
    while( getline(file, line) )
    {
        if( rand()%(++k) == 0 ) //note: rand%K is true with probability 1/K
            rand_line = line;
    }
    
    return rand_line;
}


//--------------------------------------------------------------------
//
// TEST FUNCTION
//
//--------------------------------------------------------------------


void testRandom(){
    
     cout << "\n\n----TESTING RANDOM LIB IMPLEMENTATION----\n" << endl;
    
    int a=7, b=20000;
    
    cout<<"\n"<< uniformInt(a,b)<<endl;
    cout<<"\n"<< uniformInt(a,b)<<endl;
    cout<<"\n"<< uniformInt(a,b)<<endl;
    cout<<"\n";
    
    vector<int> vec;
    for(int k=1;k<10;++k)
        vec.push_back(k);
    
    KnuthShuffle<int>(vec.begin(),vec.end());
    
    cout << "\n\nKnuth shuffle\n"<<endl;
    ostream_iterator<int> ost(cout,"\t");
    copy(vec.begin(),vec.end(),ost);
    
    
}


#endif
