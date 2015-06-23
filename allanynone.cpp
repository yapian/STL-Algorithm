#include "algostuff.h"



int main()
{
	vector<int> coll;
	vector<int>::iterator pos;

	insert_elements(coll, 1, 9);
	print_elements(coll, "coll: ");

	// define an object for the predicate (using a lambda)
	auto isEven = [](int elem) {
		return elem % 2 == 0;
	};

	// print whether all, any, or none of the elements are/is even
	cout << boolalpha << "all even?:  "
		<< all_of(coll.cbegin(), coll.cend(), isEven) << endl;
	cout << "any even?:  "
		<< any_of(coll.cbegin(), coll.cend(), isEven) << endl;
	cout << "none even?: "
		<< none_of(coll.cbegin(), coll.cend(), isEven) << endl;


}
