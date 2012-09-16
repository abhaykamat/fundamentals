//
//  random_test.h
//  preparaton
//
//  Created by Andreas Fragner on 7/20/12.
//  Copyright (c) 2012 Kimune. All rights reserved.
//

#include "test.h"
#include "random.h"

#ifndef preparaton_random_test_h
#define preparaton_random_test_h


/*
 Generate a certain number of rands of each type of distribution and output them
 to a file into some subfolder, e.g. tests
 Then plot those arrays using Python (import matplotlib.pyplot as plt)
*/


class RandomTest : public Test {
    
    public:
        RandomTest(){};
        ~RandomTest(){ specs.clear(); results.clear() };

    protected:
    
};

//constructor
RandomTest::RandomTest():Test("Random Variate Simulation Tests")
{
//    specs.push_back();

}


#endif
