//reads a sest of infix expressions from a file and writes the infix and postfix expressions
//to another file

///inglude utilities.hpp
/*
input file format: 
*fully parenthesized valid infix expression
*operands are 1-6 char in length
*opeartors are +-* divide
*only one expression per line,each expression is seperated by a semicolon
*read till end of file is reached
*/
//cmd line interface: prostfix input [output] 
	//input filename is required 
	//output filename is optional
	//if no output it will output to screen 
//make postfix builds the application



#include "utilities.hpp"
#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {

	//makes sure there is at least one cmd line argument
	if (argc == 1) {
		std::cout << "input filename is required" << std::endl;
		exit(1);//?
		}
	
	//opens input file
	std::ifstream in(argv[1]);
	if (!in) { std::cout << "Couldn't open " << argv[1] << "\n"; exit(2); }
	
	//openst output file
	if (argc == 3) {
	  std::ofstream out(argv[2]);
	  if (!out) {std::cout << "Couldn'topen " << argv[2] << "\n"; exit(3);}
	}

	std::cout << "before close" << std::endl;
	
	//close streams
	in.close();
	if (argc == 3) {out.close();}
	
	return 0;
}
