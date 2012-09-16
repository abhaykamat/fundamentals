//
//  bit_test.cpp
//  fundamentals
//
//  Created by Andreas Fragner on 7/14/12.
//

#include "test.h"
#include "bit.hpp"


#ifndef fundamentals_bit_test_hpp
#define fundamentals_bit_test_hpp


//bit test class inherited from test class

class BitTest : public Test {
    
public:
    BitTest();
    ~BitTest(){ specs.clear(); results.clear(); };
    
protected:
    
    //test functions
    static bool test_GetBit();
    static bool test_SetBit();
    static bool test_SetBitTo();
    static bool test_FlipBit();
    static bool test_ClearBit();
    static bool test_ClearBits();
    static bool test_MostSignficantBit();
    static bool test_LeastSignficantBit();
};  

//constructor

BitTest::BitTest():Test("Bit Algorithms")
{
    specs.push_back( test_GetBit );
    specs.push_back( test_SetBit );
    specs.push_back( test_SetBitTo );
    specs.push_back( test_FlipBit );
    specs.push_back( test_ClearBit );
    specs.push_back( test_ClearBits );
    specs.push_back( test_MostSignficantBit );
    specs.push_back( test_LeastSignficantBit );
}


bool BitTest::test_GetBit()
{ 
    return (GetBit(1,0) && !GetBit(2,0));
}


bool BitTest::test_SetBit()
{
    int x = 0, y = 2;
    SetBit(x,0);
    SetBit(y,0);
    
    return ( (x == 1) && (y == 3) );
}


bool BitTest::test_SetBitTo()
{ 
    int x = 0, y = 3;
    SetBitTo(x,0,true);
    SetBitTo(y,0,false);
    
    return ( (x == 1) && (y == 2) );
}


bool BitTest::test_FlipBit()
{
    int x = 1, y = 0;
    FlipBit(x,0);
    FlipBit(y,0);
    
    return ( (x == 0) && (y == 1) );
}


bool BitTest::test_ClearBit()
{
    int x = 2, y = 4;
    ClearBit(x,1);
    ClearBit(y,1);
    
    return ( (x==0) && (y==4) );
}

bool BitTest::test_ClearBits()
{
    int x = 3, y = 5;
    ClearBits(x,0,1);
    ClearBits(y,1,2);

    return (x == 0 & y == 1);
}

// TO BE COMPLETED

bool BitTest::test_MostSignficantBit()
{
    
}

bool BitTest::test_LeastSignficantBit()
{
    
}

#endif
