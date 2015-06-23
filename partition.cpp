#include "algostuff.h"

// 它们的返回值指向划分它们的第一个元素
int main()
{
	vector<int> coll1;
	vector<int> coll2;

	insert_elements(coll1, 1, 9);
	insert_elements(coll2, 1, 9);
	print_elements(coll1, "coll1: ");
	print_elements(coll2, "coll2: ");
	cout << endl;

	// move all even elements to the front
	vector<int>::iterator pos1, pos2;
	pos1 = partition(coll1.begin(), coll1.end(), [](int elem){ return elem % 2 == 0;});
	pos2 = stable_partition(coll2.begin(), coll2.end(), [](int elem){ return elem % 2 == 0;	});

	// print collections and first odd element
	print_elements(coll1, "coll1: ");
	cout << "first odd element: " << *pos1 << endl;
	print_elements(coll2, "coll2: ");
	cout << "first odd element: " << *pos2 << endl;

	/*
	* partiton_copy
	*/
	vector<int> coll = { 1, 6, 33, 7, 22, 4, 11, 33, 2, 7, 0, 42, 5 };
	print_elements(coll, "coll: ");

	// destination collections:
	vector<int> evenColl;
	vector<int> oddColl;

	// copy all elements partitioned accordingly into even and odd elements
	partition_copy(coll.cbegin(), coll.cend(), back_inserter(evenColl), back_inserter(oddColl), 
		[](int elem){   
		return elem % 2 == 0;
	});

	print_elements(evenColl, "evenColl: ");
	print_elements(oddColl, "oddColl:  ");
}
/*
coll1: 1 2 3 4 5 6 7 8 9
coll2: 1 2 3 4 5 6 7 8 9

coll1: 8 2 6 4 5 3 7 1 9
first odd element: 5
coll2: 2 4 6 8 1 3 5 7 9
first odd element: 1
coll: 1 6 33 7 22 4 11 33 2 7 0 42 5
evenColl: 6 22 4 2 0 42
oddColl:  1 33 7 11 33 7 5
请按任意键继续. . .
*/
