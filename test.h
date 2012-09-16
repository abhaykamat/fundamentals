//
//  test.h
//  preparaton
//
//  base classes for testing applications
//
//  Created by Andreas Fragner on 7/14/12.
//  email: andreas.fragner@yale.edu
//
//  ideas: change vector to map and have keys give function description

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <assert.h>

using namespace std;

#ifndef preparaton_test_h
#define preparaton_test_h

typedef bool (*bool_fptr)();

class Test {
    
    public:
    Test(){};
    Test(const string&);
    virtual ~Test(){ specs.clear(); results.clear(); };
        
    bool run(); //run all test methods
    string description; //short description of test
    vector <bool> results; //results of individual test methods
    
    protected:
    vector< bool_fptr >  specs;
    
};


Test::Test(const string& desc):
description(desc)
{};


bool Test::run()
{
    vector< bool_fptr >::iterator i = specs.begin(); 
    int k=1;
    
    cout << "\n\nRUNNING TEST SUITE: " << description <<endl ;
    
    while(i != specs.end() )
    {
        cout << "\n" << k << ": "<< boolalpha << (*i)();
        results.push_back( (*i)() );
        ++i; ++k;
    }
    
    if( find( results.begin(), results.end(), false )!= results.end() )
        return false;
    else
        return true;
}


#endif
