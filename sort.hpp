//
//  sort.h
//  preparaton
//
//  Created by Andreas Fragner on 5/26/12.
//

#ifndef preparaton_sort_hpp
#define preparaton_sort_hpp

#include "initialize.hpp"
#include "random.hpp"

//for testing purposes
namespace br = boost::random;
br::mt19937 rng( (const unsigned int) time(NULL) ); //seed the mersenne twister; this is uniform
br::normal_distribution<> nd(0.0, 1.0);
br::variate_generator<br::mt19937&, br::normal_distribution<> > normal_rand(rng, nd);


//PROTOTYPES

template <typename T> void InsertionSort( typename std::vector<T>::iterator, typename std::vector<T>::iterator);
template <typename T> void QuickSort( typename vector<T>::iterator, typename vector<T>::iterator );
template <typename T> void MergeSort( typename vector<T>::iterator, typename vector<T>::iterator );


//--------------------------------------------------------------------
//
// QUICKSORT
//
//--------------------------------------------------------------------


template <typename T> void QuickSort( typename vector<T>::iterator start, typename vector<T>::iterator end )
{

    
}


//--------------------------------------------------------------------
//
// MERGESORT
//
//--------------------------------------------------------------------

template <typename T> void MergeSort( typename vector<T>::iterator start, typename vector<T>::iterator end )
{
    
    
}

//--------------------------------------------------------------------
//
// INSERTION SORT
//
//--------------------------------------------------------------------



template <typename T> void InsertionSort( typename vector<T>::iterator start, typename vector<T>::iterator end )
{
    //start always points to the last element up to which the vector is sorted
    T key = *start;
    typename vector<T>::iterator current = start, begin = start;
    
    while( start != end)
    {
        key = *(start+1);
        current = start;
        
        // swap elements until we hit a smaller one
        while( *current>key && ((current+1) != begin ) )
        {
            *(current+1) = *current;
            --current;
        }
        
        *(current+1) = key;
        ++start;
    }
}


//--------------------------------------------------------------------
//
// TEST FUNCTION
//
//--------------------------------------------------------------------

void test_sort(){

    
    cout << "\n----TESTING SORT LIBRARY----\n" << endl;
    
    //class template instance, must be called in conjunction with a variate or rand generator
    br::uniform_int_distribution<> uniform_rand(1,20000);

    vector<int> vec;
    
    while( (int)(vec.end() - vec.begin()) < 25 )
        vec.push_back( uniform_rand(rng) );
    
    cout << "\nInsertion Sort\n" << endl;
    InsertionSort<int>( vec.begin(), vec.end());
    copy(vec.begin(), vec.end(), ostream_iterator<int> (cout, "\n"));
    
    KnuthShuffle<int>(vec.begin(),vec.end()); //reset

    cout << "\n\nQuick Sort\n" << endl;

    
    KnuthShuffle<int>(vec.begin(),vec.end()); //reset
    
    cout << "\n\nMerge Sort\n" << endl;
    
    
    cout << "\n" << endl;
    

}



#endif


