//
//  primes.hpp
//  fundamentals
//
//  Created by Andreas Fragner on 6/6/12.
//

#ifndef fundamentals_primes_h
#define fundamentals_primes_h

#include "helpers.hpp"
#include "initialize.hpp"


back_insert_iterator<vector<long> > generatePrimes( unsigned long, back_insert_iterator<vector<long> >);
back_insert_iterator<vector<long> > getPrimes(const int, back_insert_iterator<vector<long> >);
bool isPrime(long int);
void test_primes();

//--------------------------------------------------------------------
//
// GENERATE PRIMES O(n log log n)
// Generates all primes up to incl. N and places them in the container
// beginning at the location pointed to by oitr. Standard sieve of
// Erathosthenes. Note the use of back_insert_iterator such that the
// output vector doesn't need to be sized in advance
//
//--------------------------------------------------------------------


back_insert_iterator<vector<long> > generatePrimes( unsigned long N, back_insert_iterator<vector<long> > oitr )
{
    int j, i = 2;
    deque<bool> deq(N);
    fill_n(deq.begin(), N, true);
    
    deque<bool>::iterator itr = deq.begin();
    
    while( i*i <= N )
    {
        ++itr;
        if( *itr )
        {
            for( j= (int) pow(i*1.0,2)-1; j <= N; j = j + i )
                 *(deq.begin()+j) = false;
        }
        ++i;
    }
    
    itr = deq.begin()+1;
    while(itr != deq.end())
    {
      if( *itr )
        {
            *oitr = (int) ( itr-deq.begin()+1 );
            ++oitr;
        }
        ++itr;
    }
    
    return oitr;
}

//--------------------------------------------------------------------
//
// GET PRIMES
// identify all prime numbers in an input int array
// and load them into the container pointed to by output
//
//--------------------------------------------------------------------

back_insert_iterator<vector<long> > getPrimes(const int arr[], back_insert_iterator<vector<long> > output)
{
    while ( arr != NULL )
    {    if( isPrime( *(arr) ) ) *output = *arr;
        ++arr; ++output;
    }
    
    return output;
}


//--------------------------------------------------------------------
//
// CHECK FOR PRIMALITY O(sqrt(N))
//
//--------------------------------------------------------------------

bool isPrime(long int n)
{
    if ( n == 2 or n == 3 ) return true;
    if( n%2 == 0 or n%3 == 0 ) return false;
    
    long int k = 5;
    int j = 2;
    
    while( k*k <= n )
    {
        if( n%k == 0 ) return false;
        k += j;
        j = 6 - j;
    }
    
    return true;
}


//--------------------------------------------------------------------
//
// GCD
// find the greatest common denominator of two integers
// using Euclid's algorithm
//
//--------------------------------------------------------------------

template <typename T> T gcd(T a, T b)
{
    while( b!= 0 )
    {
        T temp = a%b;
        a = b;
        b = temp;
    }
    return a < 0 ? -a : a;
}


//--------------------------------------------------------------------
//
// GET NEXT PRIME greater equal N
// This is based on Bertrand's theorem, which states that for all N>2
// there exists a prime such that N < p < 2N
//
//--------------------------------------------------------------------



//--------------------------------------------------------------------
//
// TEST FUNCTION
//
//--------------------------------------------------------------------

void test_primes(){
    
    cout << "\n----TESTING PRIME LIBRARY----\n" << endl;
    
    long Np = 64;
    vector<long> vec;
    
    generatePrimes( Np, back_insert_iterator<vector<long> >(vec) );
  
    copy( vec.begin(), vec.end(), ostream_iterator<int>(cout,"\n"));
    
    cout << "\n" << *vec.begin() << " is prime? "<< isPrime( *vec.begin() );
    cout << "\n" << *(vec.begin()+2) << " is prime? "<< isPrime( *(vec.begin()+2) );
    cout << "\n" << 128 << " is prime? "<< isPrime( 128 );
    
    cout << endl;
}


#endif
