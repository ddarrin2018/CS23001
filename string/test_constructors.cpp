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
	
    {
		//Char constructor
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str('a');

        // VERIFY
        assert(str[0] == 'a' );
		assert(str[1] == '\0');
    }

	std::cout << "Done testing char constructor." << std::endl;


    {	
		//char array constructor 
		//one character long string
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str("a");

        // VERIFY
        assert(str[0] == 'a');
		assert(str[1] == '\0');

    }

    {
		//char array constructor multiple character array
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str("abc");

        // VERIFY
        assert(str[0] == 'a');
		assert(str[1] == 'b');
		assert(str[2] == 'c');
		assert(str[3] == '\0');
    }

	std::cout << "Done testing char array constructor." << std::endl;
      
    std::cout << "Done testing constructors." << std::endl;
	
	
}

