//
//  errors.hpp
//  fundamentals
//  
//  Some custom exception handlers for fundamentals
//  Created by Andreas Fragner on 7/13/12.
//

#include <exception>
#include <stdexcept>
#include <string>

using namespace std;

#ifndef fundamentals_errors_h
#define fundamentals_errors_h

class RangeError: public runtime_error
{    
    public:
    RangeError():runtime_error("Error: Invalid parameter range or interval."){};
    ~RangeError() throw(){};
    
    /*
    virtual const char* what() {
        return "Error: Invalid parameter range or interval - ";
    }
    */
};

class ConvergenceError: public runtime_error
{
public:
    ConvergenceError():runtime_error("Error: Numerical scheme did not converge."){};
    ~ConvergenceError() throw(){};
};


class ProbabilityError: public runtime_error
{
    public:
    ProbabilityError():runtime_error("Error: Probability value out of range [0,1]."){};
    ~ProbabilityError() throw(){};
};

class DivisionByZeroError : public runtime_error
{
    public:
    DivisionByZeroError():runtime_error("Error: Division by zero."){};
};

#endif
