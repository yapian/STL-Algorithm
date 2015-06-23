#include "algostuff.h"


int main()
{
	vector<int> coll1;
	deque<int> coll2;

	insert_elements(coll1, 1, 9);
	insert_elements(coll2, 11, 23);

	print_elements(coll1, "coll1: ");
	print_elements(coll2, "coll2: ");

	// swap elements of coll1 with corresponding elements of coll2
	deque<int>::iterator pos;
	pos = swap_ranges(coll1.begin(), coll1.end(),  // first range
		coll2.begin());              // second range

	print_elements(coll1, "\ncoll1: ");
	print_elements(coll2, "coll2: ");
	if (pos != coll2.end()) {
		cout << "first element not modified: "
			<< *pos << endl;
	}

	// mirror first three with last three elements in coll2
	swap_ranges(coll2.begin(), coll2.begin() + 3,    // first range
		coll2.rbegin());                   // second range

	print_elements(coll2, "\ncoll2: ");

}

