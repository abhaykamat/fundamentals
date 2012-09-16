//
//  misc.hpp
//  fundamentals
//
//  Created by Andreas Fragner on 6/3/12.
//

#ifndef fundamentals_misc_h
#define fundamentals_misc_h

#include "initialize.hpp"
#include "bit.hpp"


template <typename T> void Swap(T&,T&);
template <typename T> void XOR_swap(T*, T*);
template <typename T> bool isPowerOfTwo(const T&);
template <typename T> T HornerPolynomial(const T&, int, const T);
void StringReversal1(char*);
void StringReversal2(char*);
void StackDirection(int *);


//--------------------------------------------------------------------
//
// NUMBER SWAP
// swap the values of two variables (subtraction swap)
//
//--------------------------------------------------------------------

template <typename T> void Swap(T& a,T& b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

//--------------------------------------------------------------------
//
// XOR SWAP
// note: can also do this with a one line macro #define SWP(x,y) (x^=y, y^=x, x^=y)
//
//--------------------------------------------------------------------

template <typename T> void XOR_swap(T* a, T* b)
{
    if( a != b )
    {   *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}

//--------------------------------------------------------------------
//
// CHECK IF X is A POWER OF 2
// returns true if X is a power of two
//
//--------------------------------------------------------------------


template <typename T> bool isPowerOfTwo(const T& x)
{
    return !(x&(x-1));
}

//--------------------------------------------------------------------
//
// HORNER's ALGORITHM
// efficient evaluation of a polynomial of order k whose
// coefficients are given by the array coefficients
//
//--------------------------------------------------------------------


template <typename T> T HornerPolynomial(const T& coefficients, int order, const T x)
{
    int k = order;
    T b = coefficients[k];
    
    while( k > 0 )
    {
        b = b*x + coefficients[k-1];
        k--;
    }
    
    return b;
}

//--------------------------------------------------------------------
//
// STRING REVERSAL version 1
// using a XOR swap technique with two pointers
// Warning: not fully portable (UTF-8 characters)
//
//--------------------------------------------------------------------

void StringReversal1(char* in){
    
    char* hp = in;
    
    if( in == NULL || !(*in) )
        return;
    
    while( hp && *hp ){ ++hp; } //find end of string
    --hp;
    
    while( in < hp ){
        XOR_swap(hp,in);
        --hp; ++in;
    }
}

//--------------------------------------------------------------------
//
// STRING REVERSAL version 2
// using a temp variable instead of XOR
// assumes a NULL terminated char sequence
//
//--------------------------------------------------------------------

void StringReversal2( char *in ) {
    
    if( in == NULL || !(*in) )
        return;
    
    char temp, *end;
    end = in + strlen(in) - 1; //set to last position
    
    while( end > in ) {
        temp = *in;
        *in = *end;//swap opposite ends of string
        *end = temp;//swap
        ++in;
        --end;
    }
}


//--------------------------------------------------------------------
//
// FINDING THE DIRECTION OF PROGRESSION OF A STACK
// once main is called argc is pushed to the stack
// when stack_direction is called, a pointer to the address of argc is pushed to the stack (the address of argc
// itself). the pointer is accessed by p and the original via &p and thus we can compare two addresses that were
// allocated immediately after each other
//
//--------------------------------------------------------------------


void StackDirection(int * p) {
    printf("Stack Direction: %s\n", p < (int*)(&p) ? "up" : "down");
}


//--------------------------------------------------------------------
//
// TEST FUNCTION
//
//--------------------------------------------------------------------

void test_misc(){
    
     cout << "\n\n----TESTING MISCELLANEOUS LIB IMPLEMENTATION----\n" << endl;
    
    char alpha[] = "abcde";
    StringReversal1(alpha);
    cout << "\n" << alpha << endl;
}

#endif
