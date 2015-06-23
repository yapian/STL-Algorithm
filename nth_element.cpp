#include "algostuff.h"


int main()
{
	deque<int> coll;

	insert_elements(coll, 3, 7);
	insert_elements(coll, 2, 6);
	insert_elements(coll, 1, 5);
	print_elements(coll);

	// extract the four lowest elements
	nth_element(coll.begin(), coll.begin() + 3, coll.end()); 

	// print them
	cout << "the four lowest elements are:  ";
	copy(coll.cbegin(), coll.cbegin() + 4, ostream_iterator<int>(cout, " "));
	cout << endl;

	// extract the four highest elements
	nth_element(coll.begin(), coll.end() - 4, coll.end());

	// print them
	cout << "the four highest elements are: ";
	copy(coll.cend() - 4, coll.cend(), ostream_iterator<int>(cout, " "));
	cout << endl;

	// extract the four highest elements (second version)
	nth_element(coll.begin(), coll.begin() + 3, coll.end(), greater<int>());  

	// print them
	cout << "the four highest elements are: ";
	copy(coll.cbegin(), coll.cbegin() + 4, ostream_iterator<int>(cout, " "));
	cout << endl;
}
/*
3 4 5 6 7 2 3 4 5 6 1 2 3 4 5
the four lowest elements are:  1 2 2 3
the four highest elements are: 5 6 6 7
the four highest elements are: 7 6 6 5
请按任意键继续. . .
*/
