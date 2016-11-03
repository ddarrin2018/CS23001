//  String class test program
//
//  Tests: std::vector<String> String::split(char) const;
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main()
{
	{
		
		//------------------------------------------------------
		// SETUP FIXTURE
		String str1("alligators are my life");

		// TEST
		std::vector<String> result = str1.split(' ');
		std::vector<String> answer = { "alligators", "are", "my", "life" };
		// VERIFY
		assert(str1 == "alligators are my life");
		assert(result == answer);

	}
	{
		//start == 0 && end < length
		//------------------------------------------------------
		// SETUP FIXTURE
		String str1("alligators; are; my life");

		// TEST
		std::vector<String> result = str1.split(';');
		std::vector<String> answer = { "alligators", " are", " my life" };
		// VERIFY
		assert(str1 == "alligators; are; my life");
		assert(result == answer);

	}

	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String str1;

		// TEST
		std::vector<String> result = str1.split(';');
		std::vector<String> answer = { ""};
		// VERIFY
		assert(str1 == "");
		assert(result == answer);

	}

	{
		
		//------------------------------------------------------
		// SETUP FIXTURE
		String str1("alligators are my life");

		// TEST
		std::vector<String> result = str1.split(';');
		std::vector<String> answer = { "alligators are my life" };
		// VERIFY
		assert(str1 == "alligators are my life");
		assert(result == answer);

	}
	{

		//------------------------------------------------------
		// SETUP FIXTURE
		String str1("alligators are my life ");

		// TEST
		std::vector<String> result = str1.split(' ');
		std::vector<String> answer = { "alligators", "are", "my", "life" };
		// VERIFY
		assert(str1 == "alligators are my life ");
		assert(result == answer);

	}

	{

		//------------------------------------------------------
		// SETUP FIXTURE
		String str1(" alligators are my life");

		// TEST
		std::vector<String> result = str1.split(' ');
		std::vector<String> answer = { "alligators", "are", "my", "life" };
		// VERIFY
		assert(str1 == " alligators are my life");
		assert(result == answer);

	}
	{

		//------------------------------------------------------
		// SETUP FIXTURE
		String str1("   alligators are my life");

		// TEST
		std::vector<String> result = str1.split(' ');
		std::vector<String> answer = { "alligators", "are", "my", "life" };
		// VERIFY
		assert(str1 == "   alligators are my life");
		assert(result == answer);

	}

	{

		//------------------------------------------------------
		// SETUP FIXTURE
		String str1("alligators are my life    ");

		// TEST
		std::vector<String> result = str1.split(' ');
		std::vector<String> answer = { "alligators", "are", "my", "life" };
		// VERIFY
		assert(str1 == "   alligators are my life    ");
		assert(result == answer);

	}


	std::cout << "done testing split" << std::endl;
}