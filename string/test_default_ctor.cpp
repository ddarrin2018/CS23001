//  String class test program
//
//  Tests: tests constructors
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {
		//Default constructor
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str;

        // VERIFY
        assert(str[0] == 0);
    }

std::cout << "Done testing default constructor." << std::endl;
	
	
}

