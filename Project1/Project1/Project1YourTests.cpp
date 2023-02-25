
#include <cassert>
#include "Project1.h"

using std::cin;
using std::cout;
using std::endl;
using std::istringstream;

// Eric monestime, Amornrat Ajmo

void yourTests() 
{	
	string output;
    int uniqueWord;
	//you must write 4 additional tests cases
	//and document specifically what you are testing in each test
	//you must add test cases, which were not coverred in the 10 test cases
	//included in the project
	//cases

	// testing a period with more than one 1 spaces
	assert( funWithCallLetter( " .   ", output, uniqueWord ) == 0);
    assert( output.length() == string(" .   ").length() );
	cout << "additional test #1 completed" << endl;

	// Testing two space and a ! in the middle
	assert( funWithCallLetter( " ! ", output, uniqueWord ) == 0);
    assert( output.length() == string(" ! ").length() );
	cout << "additional test #2 completed" << endl;

	// Testing word separators in the string  
	assert( funWithCallLetter( "alphaBravo\nalphaBravo!alphaBravo?alphaBravo", output, uniqueWord ) == 4);
    assert( output.compare("ab\nab!ab?ab") == 0 );
    assert( uniqueWord == 1 );
	cout << "additional test #3 completed" << endl;

	// Testing if the word isn't in the array. We input alabama instead of alpha
	assert( funWithCallLetter( "alabamaBravo\nalphaBravo!alphaBravo", output, uniqueWord ) == 0);
	cout << "additional test #4 completed" << endl;
}

