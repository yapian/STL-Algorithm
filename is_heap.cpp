#include "algostuff.h"


int main()
{
	vector<int> coll1 = { 9, 8, 7, 7, 7, 5, 4, 2, 1 };
	vector<int> coll2 = { 5, 3, 2, 1, 4, 7, 9, 8, 6 };
	print_elements(coll1, "coll1: ");
	print_elements(coll2, "coll2: ");

	// check whether the collections are heaps
	cout << boolalpha << "coll1 is heap: "
		<< is_heap(coll1.cbegin(), coll1.cend()) << endl;
	cout << "coll2 is heap: "
		<< is_heap(coll2.cbegin(), coll2.cend()) << endl;

	// print the first element that is not a heap in coll2
	auto pos = is_heap_until(coll2.cbegin(), coll2.cend());
	if (pos != coll2.end()) {
		cout << "first non-heap element: " << *pos << endl;
	}

}
