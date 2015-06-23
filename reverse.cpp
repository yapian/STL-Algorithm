#include "algostuff.h"


int main()
{
	vector<int> coll;

	insert_elements(coll, 1, 9);
	print_elements(coll, "coll: ");

	// reverse order of elements
	reverse(coll.begin(), coll.end());
	print_elements(coll, "coll: ");

	// reverse order from second to last element but one
	reverse(coll.begin() + 1, coll.end() - 1);
	print_elements(coll, "coll: ");

	// print all of them in reverse order
	reverse_copy(coll.cbegin(), coll.cend(),         // source
		ostream_iterator<int>(cout, " "));   // destination
	cout << endl;

	
}

