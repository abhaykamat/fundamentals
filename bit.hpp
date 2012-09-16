//
//  bit.hpp
//  fundamentals
//
//  Created by Andreas Fragner on 5/26/12.
//


#ifndef preparaton_bit_h
#define preparaton_bit_h

#include "initialize.hpp"
#include "errors.hpp"

// PROTOTYPES

template <class T> bool GetBit(const T&, unsigned int i=0); 
template <class T> void FlipBit(T&, unsigned int);
template <class T> void SetBit(T&, unsigned int);
template <class T> void SetBitTo(T&, unsigned int, bool);
template <class T> void ClearBit(T&, unsigned int);
template <class T> void ClearBits(T&, unsigned int, unsigned int);
template <class T> int MostSignificantBit(const T&);
template <class T> int LeastSignificantBit(const T& obj);


//--------------------------------------------------------------------
//
// GET BIT
// returns the bit value at position i in the binary
// representation of an object of type T
//
//--------------------------------------------------------------------

template <class T> bool GetBit(const T& obj, unsigned int i)
{
    return ( ( obj & (1 << i)) != 0 );
}


//--------------------------------------------------------------------
//
// BIT FLIP
// flip the bit value at position i in the binary
// representation of an object of type T
//
//--------------------------------------------------------------------

template <class T> void FlipBit(T& obj, unsigned int i)
{
    obj = obj ^ (1 << i);
}


//--------------------------------------------------------------------
//
// SET BIT
// set the bit value at position i in the binary
// representation of an object of type T to 1
//
//--------------------------------------------------------------------


template <class T> void SetBit(T& obj, unsigned int i)
{
    obj = ( obj | (1 << i ) );
}

//--------------------------------------------------------------------
//
// SET BIT TO
// set the bit value at position i in the binary
// representation of an object of type T to k
//
//--------------------------------------------------------------------

template <class T> void SetBitTo(T& obj, unsigned int i, bool k)
{
    if(k)
    { SetBit(obj, i); }
    else
    {
        if( GetBit(obj,i) )
            FlipBit(obj,i);
    }
}

//--------------------------------------------------------------------
//
// CLEAR BIT
// clear the value of bit at position i in the binary
// representation of an object of type T
//
//--------------------------------------------------------------------

template <class T> void ClearBit(T& obj, unsigned int i)
{
    obj = obj & (~(1<<i));
}


//--------------------------------------------------------------------
//
// CLEAR BITS all bits from i through j
// clear all bits at positions i through j in the binary
// representation of an object of type T (starting from the left, i.e. i <= j )
//
//--------------------------------------------------------------------

template <class T> void ClearBits(T& obj, unsigned int i, unsigned  int j)
{
    RangeError e;
    
    try{
        if( i > j) { throw e; }
        int x = int( pow(2.0,double(j-i+1))-1 );
        obj = obj & (~(x<<i));
    }
    catch(RangeError &e)
    {
        cout << e.what() << endl;
    }
}

//--------------------------------------------------------------------
//
// MOST SIGNIFICANT BIT
// return the position of the most significant bit from the
// left in the binary representation of obj
//
//--------------------------------------------------------------------

template <class T> int MostSignificantBit(const T& obj, unsigned int i)
{
    return 0;
}

//--------------------------------------------------------------------
//
// LEAST SIGNIFICANT BIT
// return the position of the least significant bit set from the
// right in the binary representation of obj
//
//--------------------------------------------------------------------

template <class T> int LeastSignificantBit(const T& obj, unsigned int i)
{
    return 0;
}



#endif


