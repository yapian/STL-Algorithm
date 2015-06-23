#include "algostuff.h"


int main()
{
	/*
	* a1, a2, a3, ...
	* a1, a1+a2, a1+a2+a3, ...
	* a1, a1 op a2, a1 op a2 op a3, ...
	*/
	vector<int> coll;

	insert_elements(coll, 1, 6);
	print_elements(coll);

	// print all partial sums
	partial_sum(coll.cbegin(), coll.cend(),        // source range
		ostream_iterator<int>(cout, " "));  // destination
	cout << endl;

	// print all partial products
	partial_sum(coll.cbegin(), coll.cend(),        // source range
		ostream_iterator<int>(cout, " "),   // destination
		multiplies<int>());                // operation
	cout << endl;

	/*
	* a1, a2, a3, ...
	* a1, a2-a1, a3-a2, ...
	* a1, a2 op a1, a3 op a2, ...
	*/

	coll.clear();

	insert_elements(coll, 1, 6);
	print_elements(coll);

	// print all differences between elements
	adjacent_difference(coll.cbegin(), coll.cend(),       // source
		ostream_iterator<int>(cout, " ")); // destination
	cout << endl;

	// print all sums with the predecessors
	adjacent_difference(coll.cbegin(), coll.cend(),       // source
		ostream_iterator<int>(cout, " "),  // destination
		plus<int>());                     // operation
	cout << endl;

	// print all products between elements
	adjacent_difference(coll.cbegin(), coll.cend(),       // source
		ostream_iterator<int>(cout, " "),  // destination
		multiplies<int>());               // operation
	cout << endl;
}
