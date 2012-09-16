//
//  search.h
//  fundamentals
//
//  Created by Andreas Fragner on 5/26/12.
//

#ifndef fundamentals_search_h
#define fundamentals_search_h

#include "initialize.hpp"

template <typename T1, typename T2> vector< pair<T1,T1> > PairSum(typename vector<T1>::iterator, typename vector<T1>::iterator, T2);
template <typename T1, typename T2> back_insert_iterator<vector<pair<T1,T1> > > PairSum2(typename vector<T1>::iterator, typename vector<T1>::iterator, back_insert_iterator<vector<pair<T1,T1> > >, T2);
long FindMissingInteger1(int*, size_t);
long FindMissingInteger2(int*, size_t);

// BINARY SEARCH 
//template <typename T> T BinarySearch(const T &array);
// FINDING UNIQUE ELEMENTS
// FINDING UNIQUE TRIPLES


//--------------------------------------------------------------------
//
// PAIR SUM O(n)
// find all pairs in a sorted array that sum to a given number M
// returns a vector of pairs of the given input type
//
//--------------------------------------------------------------------


template <typename T1, typename T2> vector< pair<T1,T1> > PairSum(typename vector<T1>::iterator first, typename vector<T1>::iterator last, T2 M)
{
    vector< pair<T1,T1> > results;
    T2 sum = 0;
    
    while( first != last )
    {
        sum = (T2) ((*first) + (*last));
        if( sum == M )
        {
            results.push_back( pair<T1,T1>(*first,*last) );
            ++first; --last;
        }
        else if( sum < M )
            ++first;
        else if( sum > M )
            --last;
    }
    
    return results;
}


//same algorithm as above but takes a back_insert_iterator
template <typename T1, typename T2> back_insert_iterator<vector<pair<T1,T1> > > PairSum2(typename vector<T1>::iterator first, typename vector<T1>::iterator last, back_insert_iterator<vector<pair<T1,T1> > > results, T2 M)
{
    T2 sum = 0;
    
    while( first != last )
    {
        sum = (T2) ((*first) + (*last));
        if( sum == M )
        {
            *results = ( pair<T1,T1>(*first,*last) );
            ++results;
            ++first; --last;
        }
        else if( sum < M )
            ++first;
        else if( sum > M )
            --last;
    }
    
    return results;
}




//--------------------------------------------------------------------
//
// UNIQUE TRIPLES
//
//--------------------------------------------------------------------

/*
 find all unique triples in an array that sum to zero
 */



//--------------------------------------------------------------------
//
// FINDING THE MISSING INTEGER - version 1
// using the sum technique, complexity O(n)
//
//--------------------------------------------------------------------

long FindMissingInteger1(int* arr, size_t n ){
    
    long total = (n+1)*(n+2)/2;
    for(int i=0; i<n; ++i)
        total -=arr[i];
    
    return total;
}

//--------------------------------------------------------------------
//
// FINDING THE MISSING INTEGER - version 2
// XOR technique, using a bit mask, complexity O(n)
// Note: a binary search with sort would be worse complexity in general
//
//--------------------------------------------------------------------

long FindMissingInteger2(int* arr, size_t n ){
    
    int i;
    int x1 = arr[0];
    int x2 = 1;
    
    for ( i = 1; i< n; i++)
        x1 ^= arr[i]; // xor the first array element with all others
    
    for ( i = 2; i <= n+1; i++)
        x2 ^= i; // xor 1 with all numbers from 2  to n+1
    
    return (x1^x2);
}


//--------------------------------------------------------------------
//
// TEST
//
//--------------------------------------------------------------------


void testSearch(){
    
    cout << "\n----TESTING SEARCH FUNCTION LIBRARY----\n" << endl;
    
    cout << "\nPair Sums:\n";
    
    vector<int> v;
    for(int i=1; i<= 30; ++i)
        v.push_back(i);
    
    vector< pair<int,int> > results = PairSum<int>(v.begin(),--v.end(),10);
    
    for( vector< pair<int,int> >::iterator i = results.begin(); i != results.end(); ++i )
        cout << i->first << "\t" << i->second << "\n";
    
}



#endif
