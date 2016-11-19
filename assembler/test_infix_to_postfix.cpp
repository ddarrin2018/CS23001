#include "utilities.hpp"
//TESTING
//create data set to properly test the conversion algorithm
//create unit tests for these
//should work on data3-1.txt 
//make tests should build an run all tests
void main() {
	String top = inToPost("( AX + ( B * C ) ) ;");
	std::cout << top << std::endl;
}