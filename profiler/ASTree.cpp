/*
 *  ASTree.cpp
 *  Abstract Syntax Tree
 *
 *  Created by Jonathan Maletic
 *  Copyright 2016 Kent State University. All rights reserved.
 *
 *  Modified by:
 *
 */
#include "ASTree.hpp"


 /////////////////////////////////////////////////////////////////////
 // Copy constructor for srcML
 //
srcML::srcML(const srcML& actual) {
	tree = new AST(*(actual.tree));
}

/////////////////////////////////////////////////////////////////////
// Constant time swap for srcML
//
void srcML::swap(srcML& b) {
	std::string t_header = header;
	header = b.header;
	b.header = t_header;

	AST *temp = tree;
	tree = b.tree;
	b.tree = temp;
}

/////////////////////////////////////////////////////////////////////
// Assignment for srcML
//
srcML& srcML::operator=(srcML rhs) {
	swap(rhs);
	return *this;
}

/////////////////////////////////////////////////////////////////////
// Reads in and constructs a srcML object.
//
std::istream& operator >> (std::istream& in, srcML& src) {
	char ch;
	if (!in.eof()) in >> ch;
	src.header = readUntil(in, '>');
	if (!in.eof()) in >> ch;
	if (src.tree) delete src.tree;
	src.tree = new AST(category, readUntil(in, '>'));
	src.tree->read(in);
	return in;
}


/////////////////////////////////////////////////////////////////////
// Prints out a srcML object
//
std::ostream& operator<<(std::ostream& out, const srcML& src) {
	src.tree->print(out);
	return out;
}

/////////////////////////////////////////////////////////////////////
//  Adds in the includes and profile variables
//
void srcML::mainHeader(std::vector<std::string>& profileNames) {
	tree->mainHeader(profileNames);
}

/////////////////////////////////////////////////////////////////////
//  Adds in the includes and profile variables
//
void srcML::fileHeader(const std::string& profileName) {
	tree->fileHeader(profileName);
}


/////////////////////////////////////////////////////////////////////
// Adds in the report to the main.
//
void srcML::mainReport(std::vector<std::string>& profileNames) {
	tree->mainReport(profileNames);
}

/////////////////////////////////////////////////////////////////////
//  Inserts a filename.count() into each function body.
//
void srcML::funcCount(const std::string& profilename) {
	tree->funcCount(profilename);
}

/////////////////////////////////////////////////////////////////////
// Inserts a filename.count() for each statement.
//
void srcML::lineCount(const std::string& profilename) {
	tree->lineCount(profilename);
}



/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
// Constructs a category, token, or whitespace node for the tree.
//
AST::AST(nodes t, const std::string& s) {
	nodeType = t;
	switch (nodeType) {
	case category:
		tag = s;
		break;
	case token:
		text = unEscape(s); //removes <> ??
		break;
	case whitespace:
		text = s;
		break;
	}
}


/////////////////////////////////////////////////////////////////////
// Destructor for AST
//
AST::~AST() {
	//NEED TO IMPLEMENT
	for (std::list<AST*>::iterator i = child.begin(); i != child.end(); ++i) {
		delete *i;
	}
}


/////////////////////////////////////////////////////////////////////
// Copy Constructor for AST
//
AST::AST(const AST& actual) {
	nodeType = actual.nodeType;
	tag = actual.tag;
	closeTag = actual.closeTag;
	text = actual.text;

	for (std::list<AST*>::const_iterator i = actual.child.begin(); i != actual.child.end(); ++i) {
		child.push_back(new AST(*(*i)));
	}
}


/////////////////////////////////////////////////////////////////////
// Constant time swap for AST
//
void AST::swap(AST& b) {
	std::swap(nodeType, b.nodeType);
	tag.swap(b.tag);
	closeTag.swap(b.closeTag);
	text.swap(b.text);
	child.swap(b.child);
}

/////////////////////////////////////////////////////////////////////
// Assignment for AST
//
AST& AST::operator=(AST rhs) {
	swap(rhs);
	return *this;
}


/////////////////////////////////////////////////////////////////////
// Returns a pointer to child[i] where (child[i]->tag == tagName)
//
// IMPORTANT for part 3
AST* AST::getChild(std::string tagName) {
	std::list<AST*>::iterator ptr = child.begin();
	while (((*ptr)->tag != tagName) && (ptr != child.end())) {
		++ptr;
	}
	return *ptr;
}


/////////////////////////////////////////////////////////////////////
// Returns the full name of a <name> node.
//
// IMPORTANT for part 3
//
std::string AST::getName() const {
	std::string result;
	if (child.front()->tag != "name") {
		result = child.front()->text;   //A simple name (e.g., main)
	}
	else {                            //A complex name (e.g., stack::push).
		result = child.front()->child.front()->text;
		result += "::";
		result += child.back()->child.front()->text;
	}
	return result;
}


/////////////////////////////////////////////////////////////////////
//  Adds in the includes and profile variables in a main file.
//
void AST::mainHeader(std::vector<std::string>& profileNames) {

	//NEED TO IMPLEMENT
	//Skip down a couple lines.
	//For each file profile name, add a new node with a profile 
	// declaration.
	//Also, add in the profile declaration for functions and the
	//include for profile.hpp

	std::list<AST*>::iterator subtreeItr = child.begin();

	//inserting include statements
	AST * includeChildPtr = new AST(token, "#include \"profile.hpp\"\n");

	child.insert(subtreeItr, includeChildPtr);

	//---------------
	for (std::vector<std::string>::iterator nameItr = profileNames.begin();
		nameItr != profileNames.end(); ++nameItr) {

		//changing profile name to filename _ => .

		std::string profile_name = *nameItr;
		size_t underscore_pos = profile_name.find_last_of('_');

		std::string filename = profile_name.replace(underscore_pos, 1, ".");

		std::string textToAdd = "profile " + *nameItr + "(\"" + filename + "\");\n";

		//adding an extra line after end because I want
		if (nameItr == --profileNames.end()) {
			textToAdd = textToAdd + "\n";
		}

		//creating new pointer to a subtree
		AST * declareChildPtr = new AST(token, textToAdd);

		//inserting new child
		child.insert(subtreeItr, declareChildPtr);






	}
}


/////////////////////////////////////////////////////////////////////
//  Adds in the includes and profile variables for non-main files
//
void AST::fileHeader(const std::string& profileName) {

	//NEED TO IMPLEMENT
	//Skip down a couple lines.
	//For each file profile name, add a new node with a profile 
	// extern declaration.
	//Also, add in the extern declaration for functions and the
	//include for profile.hpp

	//adding include statement
	std::list<AST*>::iterator subtreeItr = child.begin();

	//inserting include statements
	AST * includeChildPtr = new AST(token, "#include \"profile.hpp\"\n");

	child.insert(subtreeItr, includeChildPtr);

	//adding extern declarations

	//changing profile name to filename _ => .
	std::string profile_name = profileName;
	size_t underscore_pos = profile_name.find_last_of('_');

	std::string filename = profile_name.replace(underscore_pos, 1, ".");

	std::string textToAdd = "extern profile " + profileName + ";\n";

	//creating new pointer to a subtree
	AST * declarationChildPtr = new AST(token, textToAdd);

	//inserting new child
	child.insert(subtreeItr, declarationChildPtr);



}


/////////////////////////////////////////////////////////////////////
// Adds in the report to the main.
// Assumes only one return at end of main body.
//
void AST::mainReport(std::vector<std::string>& profileNames) {

	//NEED TO IMPLEMENT

	//Find the function with name main and then start from the end.
	//Find the main - function with name of "main"
	//Then start from the end() of this function and iterate
	// backwards until you find a return stmt.   You'll want
	// to insert the report statements before this return.


	/*
	find main function and print a cout statement for every prfile name
	ex:  std::cout << foo_cpp << std::endl;
			  std::cout << main1_cpp << std::endl;
	*/


	
	for (std::list<AST *>::iterator unitItr = child.begin(); unitItr != child.end(); ++unitItr) {
		//point unitItr at main
		if ((*unitItr)->tag == "function" && (*unitItr)->getChild("name")->getName() == "main") {
			
			//find block child
			AST * blockAST = (*unitItr)->getChild("block");
			
			//find return child inside block
			AST * returnAST = blockAST->getChild("return");

			//point at the first child of return
			std::list<AST*>::iterator returnItr = returnAST->child.begin();

			
			//iterate through Profilenames
			for (std::vector<std::string>::iterator namesItr = profileNames.begin(); namesItr != profileNames.end(); ++namesItr) {
				std::string textToInsert = "std::cout << " + *namesItr + " << std::endl;\n    ";
				AST * newNode = new AST(token, textToInsert);

				//insert new node
				returnAST->child.insert(returnItr, newNode);
			}

		}

	}
}

/////////////////////////////////////////////////////////////////////
// Adds in a line to count the number of times each function is executed.
//  Assumes no nested functions.
//
void AST::funcCount(const std::string& profileName) {

	//NEED TO IMPLEMENT

	// for all children
	//     if child is a function, constructor, destructor
	//        Find the function name
	//        Find block and insert line as first line in block
	//

	/*
	look for function tag after its first child insert statement that passes line number and function name to that function frofile object
	*/

	AST * newNode = new AST(token, "//<<<I'm here");

	for (std::list<AST*>::iterator unitItr = child.begin(); unitItr != child.end(); ++unitItr) {
		//point iterator at function
		if ((*unitItr)->tag == "function") {

			//find block child
			AST * blockAST = (*unitItr)->getChild("block");

			//point to  first child of block
			std::list<AST*>::iterator blockItr = blockAST->child.begin();

			//insert node before first child
			blockAST->child.insert(++blockItr, newNode);

		}
	}

}

/////////////////////////////////////////////////////////////////////
// Adds in a line to count the number of times each statement is executed.
//   No breaks, returns, throw etc.
//   Assumes all construts (for, while, if) have { }.
//
void AST::lineCount(const std::string& profileName) {

	//NEED TO IMPLEMENT

	// Recursively check for expr_stmt and call
	// This basis is when isStopTag is true.

	//traverse the tree and and pass the line number to the profile object after ever statement



}


/////////////////////////////////////////////////////////////////////
// Read in and construct AST
// REQUIRES: '>' was previous charater read 
//           && this == new AST(category, "TagName")
//
//
std::istream& AST::read(std::istream& in) {
	AST *subtree;
	std::string temp, Lws, Rws;
	char ch;
	if (!in.eof()) in.get(ch);
	while (!in.eof()) {
		if (ch == '<') {                      //Found a tag
			temp = readUntil(in, '>');
			if (temp[0] == '/') {
				closeTag = temp;
				break;                        //Found close tag, stop recursion
			}
			subtree = new AST(category, temp);               //New subtree
			subtree->read(in);                               //Read it in
			in.get(ch);
			child.push_back(subtree);                        //Add it to child
		}
		else {                                             //Found a token
			temp = std::string(1, ch) + readUntil(in, '<');  //Read it in.
			std::vector<std::string> tokenList = tokenize(temp);
			for (std::vector<std::string>::const_iterator i = tokenList.begin();
				i != tokenList.end(); ++i) {
				if (isspace((*i)[0])) {
					subtree = new AST(whitespace, *i);
				}
				else {
					subtree = new AST(token, *i);
				}
				child.push_back(subtree);
			}
			ch = '<';
		}
	}
	return in;
}


/////////////////////////////////////////////////////////////////////
// Print an AST 
// REQUIRES: indent >= 0
//
std::ostream& AST::print(std::ostream& out) const {
	for (std::list<AST*>::const_iterator i = child.begin();
		i != child.end(); ++i) {
		switch ((*i)->nodeType) {
		case category:
			(*i)->print(out);
			break;
		case token:
			out << (*i)->text;
			break;
		case whitespace:
			out << (*i)->text;
			break;
		}
	}
	return out;
}



/////////////////////////////////////////////////////////////////////
// Utilities
//


/////////////////////////////////////////////////////////////////////
// This returns true if a syntactic category is encountered that
//  will not be profiled.
//
// This is IMPORTANT for milestone 3
bool isStopTag(std::string tag) {
	if (tag == "decl_stmt") return true;
	if (tag == "argument_list") return true;
	if (tag == "init") return true;
	if (tag == "condition") return true;
	if (tag == "cpp:include") return true;
	if (tag == "macro") return true;
	if (tag == "comment type\"block\"") return true;
	if (tag == "comment type\"line\"") return true;
	return false;
}


/////////////////////////////////////////////////////////////////////
// Reads until a key is encountered.  Does not include ch.
// REQUIRES: in.open()
// ENSURES: RetVal[i] != key for all i.
//
std::string readUntil(std::istream& in, char key) {
	std::string result;
	char ch;
	in.get(ch);
	while (!in.eof() && (ch != key)) {
		result += ch;
		in.get(ch);
	}
	return result;
}


/////////////////////////////////////////////////////////////////////
// Converts escaped XML charaters back to charater form
// REQUIRES: s == "&lt;"
// ENSURES:  RetVal == "<"
//
std::string unEscape(std::string s) {
	std::size_t pos = 0;
	while ((pos = s.find("&gt;")) != s.npos) { s.replace(pos, 4, ">"); }
	while ((pos = s.find("&lt;")) != s.npos) { s.replace(pos, 4, "<"); }
	while ((pos = s.find("&amp;")) != s.npos) { s.replace(pos, 5, "&"); }
	return s;
}


/////////////////////////////////////////////////////////////////////
// Given: s == "   a + c  "
// RetVal == {"   ", "a", " ", "+", "c", " "}  
//
std::vector<std::string> tokenize(const std::string& s) {
	std::vector<std::string> result;
	std::string temp = "";
	unsigned i = 0;
	while (i < s.length()) {
		while (isspace(s[i]) && (i < s.length())) {
			temp.push_back(s[i]);
			++i;
		}
		if (temp != "") {
			result.push_back(temp);
			temp = "";
		}
		while (!isspace(s[i]) && (i < s.length())) {
			temp.push_back(s[i]);
			++i;
		}
		if (temp != "") {
			result.push_back(temp);
			temp = "";
		}
	}
	return result;
}


