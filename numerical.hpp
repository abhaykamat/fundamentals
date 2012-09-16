//
//  numerical.h
//  fundamentals
//
//  Created by Andreas Fragner on 7/4/12.
//

#ifndef fundamentals_numerical_h
#define fundamentals_numerical_h

#include "initialize.hpp"
#include "errors.hpp"


double SqrtBisection(const double&, const double&, const double&, const double&, unsigned long);
bool test_Numerical();

//--------------------------------------------------------------------
//
// SQRT VIA BISECTION METHOD - does not throw; slow
//
//--------------------------------------------------------------------


double SqrtBisection(const double& x, const double& a, const double& b, const double& precision = 0.1, unsigned long max_iteration = 100000000)
{
    
    RangeError ex1;
    ConvergenceError ex2;
    unsigned long k = 0;
    
    if( a*a==x ) return a;
    else if( b*b == x) return b;
    
    try{
        if( a >= b || a*a > x || b*b < x  ){ throw ex1; }
        else{
            double pivot = (a+b)/2.;
            while ( abs(pivot*pivot - x) > precision )
            {
                if( pivot*pivot > x ) pivot = (a+pivot)/2.;
                else if (pivot*pivot < x ) pivot = (pivot + b)/2.;
                ++k;
                if ( k > max_iteration ){ throw ex2; }
            }
            return pivot;
        }
    }
    catch( RangeError& ex1)
    {
        cout << "\n" << ex1.what() << endl;
        return 0;
    }
    catch( ConvergenceError& ex2)
    {
        cout << "\n" << ex2.what() << endl;
        return 0;
    }
    catch( ... )
    {
        cout << "\nAn unknown error occurred during bisection method." << endl;
        return 0;
    }
}


//--------------------------------------------------------------------
//
// TEST
//
//--------------------------------------------------------------------

bool test_Numerical(){
    
    cout << "\n\n----TESTING NUMERICAL LIB IMPLEMENTATION----\n" << endl;
    
    int x = 64, a = 6, b = 9;
    int x1 = 147, a1 = 12, b1 = 13;
    
    cout << "\nSquare root of "<< x <<" :" << SqrtBisection(x,a,b);
    cout << "\nSquare root of "<< x1 <<" :" << SqrtBisection(x1,a1,b1);
    
    
    return true;
}


#endif


