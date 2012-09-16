//
//  helpers.hpp
//  fundamentals
//
//  various helper functions for fundamentals
//  Created by Andreas Fragner on 8/26/12.
//

#ifndef fundamentals_helpers_hpp
#define fundamentals_helpers_hpp

#include "initialize.hpp"


// Function object that returns successive values
// useful for populating a vector with integers using generate

template <typename T> class successiveValues {
    T k;
    
    public:
    successiveValues(): k(0){};
    T operator()(){ return ++k; }
};





#endif
