//  String class test program
//
//  Tests: tests char constructor
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {
	//Tests character
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str('a');

        // VERIFY
        assert(str[0] == 'a' );
		assert(str[1] == '\0');
    }

std::cout << "Done testing char constructor." << std::endl;


}

