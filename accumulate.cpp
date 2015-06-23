#include "algostuff.h"


int main()
{

	/*
	* accumulate
	*/
	vector<int> coll;

	insert_elements(coll, 1, 9);
	print_elements(coll);

	// process sum of elements
	cout << "sum: " << accumulate(coll.cbegin(), coll.cend(), 0) << endl;

	// process sum of elements less 100
	cout << "sum: " << accumulate(coll.cbegin(), coll.cend(), -100) << endl;

	// process product of elements
	cout << "product: " << accumulate(coll.cbegin(), coll.cend(), 1, multiplies<int>()) << endl;

	// process product of elements (use 0 as initial value)
	cout << "product: " << accumulate(coll.cbegin(), coll.cend(), 0, multiplies<int>()) << endl;


	/*
	* 两个数列的内积
	*/

	coll.clear();

	insert_elements(coll, 1, 6);
	print_elements(coll);

	// process sum of all products
	// (0 + 1*1 + 2*2 + 3*3 + 4*4 + 5*5 + 6*6)
	cout << "inner product: " << inner_product(coll.cbegin(), coll.cend(), coll.cbegin(), 0) << endl;

	// process sum of 1*6 ... 6*1
	// (0 + 1*6 + 2*5 + 3*4 + 4*3 + 5*2 + 6*1)
	cout << "inner reverse product: " << inner_product(coll.cbegin(), coll.cend(), coll.crbegin(), 	0) << endl;

	// process product of all sums
	// (1 * 1+1 * 2+2 * 3+3 * 4+4 * 5+5 * 6+6)
	cout << "product of sums: "	<<
		inner_product(coll.cbegin(), coll.cend(), coll.cbegin(), 1, multiplies<int>(), 	plus<int>()) << endl;
}
/*
1 2 3 4 5 6 7 8 9
sum: 45
sum: -55
product: 362880
product: 0
1 2 3 4 5 6
inner product: 91
inner reverse product: 56
product of sums: 46080
请按任意键继续. . .
*/
