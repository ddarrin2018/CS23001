/**
 *Marianna Matousek
 *bigint.hpp
 *CS23001
 *This is a header file for an ADT which will represent an arbitrarily large
 *integer.
 */

#ifndef CS2_POINT_HPP
#define CS2_POINT_HPP

#include <iostream>

const int SIZE = 300; //max size of bigint




class bigint {
public:
  bigint(); //initialises bigint to zero
  bigint(int); //makes some int into bigintArray
  bigint(const char[]);//translates a char[] into bigintArray
  bigint operator+(const bigint &) const; //adds two bigints together 
  bool operator==(const bigint&) const; //uses bigint(int)
  int operator[](int) const;//returnes 10^int parameter
  bigint operator*(const bigint &) const; //multiplies two bigints together
  bigint times10(int) const; //returns an bigint multiplies by 10^n with n>0
  bigint times_single_digit(int)const; //multiplies a bigint and a single digit integer between 0 and 9
  friend std::ostream& operator<<(std::ostream&, const bigint &);
  friend std::istream& operator >> (std::istream&, bigint &);

  /*---//extra credit//------------------------------------------------*/
  
  //finds the difference of two bigints if difference is >= 0
  bigint operator-(const bigint &)const;


  //since the internet says it's bad to mess with the ! operator
  //and because I tried and it didn't work correctly :P 
  // returns a factorial of a bigint
  bigint factorial()const; 

  //returns number of trailing zeroes
  int trailing_zeroes()const; 

private:
  int bigintArray[SIZE];
};



#endif
