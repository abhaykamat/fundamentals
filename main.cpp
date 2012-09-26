//
//  main.cpp
//  fundamentals
//
//  Created by Andreas Fragner on 5/26/12.
//
//

#include "initialize.hpp"
#include "misc.hpp"
#include "bit_test.hpp"
#include "numerical.hpp"
#include "random.hpp"
#include "primes.hpp"
#include "sort.hpp"
#include "data_structures.hpp"
#include "search.hpp"


// MAIN

int main(int argc, char ** argv)
{
    string path = "/Users/andreasfragner/Desktop/";
    
    // TEST STACK DIRECTION (misc.hpp)
    StackDirection(&argc);
    
    // SEARCH
    testSearch();
    
    // SEEDS
    srand( int(time(NULL)) );
    
    // TESTS/SPECS
    BitTest mytest;
    mytest.run();
   
      
    // RANDOM    
    testRandom();

    // DATA STRUCTURES
    
    test_SL();
    test_Stack();
    test_Queue();
    TowersOfHanoi(10);
    
    // NUMERICAL
    test_Numerical();
    
    // PRIMES
    test_primes();
    
    // SORT
    test_sort();
    
    // MISC
    test_misc();
   
    cout << "\n\n\n\n-----------------------------"<<endl;
    cout << "-----------------------------"<<endl;

    
    
    
    
    
    
    return 0;

    
}









