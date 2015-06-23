#include "algostuff.h"


int main()
{
	vector<int> coll;

	insert_elements(coll, 1, 9);
	print_elements(coll, "coll:      ");

	// 以第二个参数指向的元素作为新的头元素，以完成旋转
	// rotate one element to the left
	rotate(coll.begin(), coll.begin() + 1, coll.end()); 
	print_elements(coll, "one left:  ");

	// rotate two elements to the right
	rotate(coll.begin(), coll.end() - 2, coll.end());
	print_elements(coll, "two right: ");

	// rotate so that element with value 4 is the beginning
	rotate(coll.begin(), find(coll.begin(), coll.end(), 4), coll.end());
	print_elements(coll, "4 first:   ");


	/*
	* 复制并同时旋转元素
	*/
	set<int> coll2;

	insert_elements(coll2, 1, 9);
	print_elements(coll2);

	// print elements rotated one element to the left
	set<int>::const_iterator pos = next(coll2.cbegin());
	rotate_copy(coll2.cbegin(), pos, coll2.cend(), ostream_iterator<int>(cout, " ")); 
	cout << endl;

	// print elements rotated two elements to the right
	pos = coll2.cend();
	advance(pos, -2);
	rotate_copy(coll2.cbegin(), pos, coll2.cend(), ostream_iterator<int>(cout, " ")); 
	cout << endl;

	// print elements rotated so that element with value 4 is the beginning
	rotate_copy(coll2.cbegin(),  coll2.find(4), coll2.cend(), ostream_iterator<int>(cout, " ")); 
	cout << endl;
	
}

/*
coll:      1 2 3 4 5 6 7 8 9
one left:  2 3 4 5 6 7 8 9 1
two right: 9 1 2 3 4 5 6 7 8
4 first:   4 5 6 7 8 9 1 2 3
1 2 3 4 5 6 7 8 9
2 3 4 5 6 7 8 9 1
8 9 1 2 3 4 5 6 7
4 5 6 7 8 9 1 2 3
请按任意键继续. . 
*/
