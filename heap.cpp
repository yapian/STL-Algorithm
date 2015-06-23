#include "algostuff.h"


int main()
{
	vector<int> coll;

	insert_elements(coll, 3, 7);
	insert_elements(coll, 5, 9);
	insert_elements(coll, 1, 4);

	print_elements(coll, "on entry:           ");

	// convert collection into a heap
	make_heap(coll.begin(), coll.end());

	print_elements(coll, "after make_heap():  ");

	// pop next element out of the heap
	pop_heap(coll.begin(), coll.end());
	coll.pop_back();

	print_elements(coll, "after pop_heap():   ");

	// push new element into the heap
	coll.push_back(17);
	push_heap(coll.begin(), coll.end());

	print_elements(coll, "after push_heap():  ");

	// convert heap into a sorted collection
	// - NOTE: after the call it is no longer a heap
	sort_heap(coll.begin(), coll.end());

	print_elements(coll, "after sort_heap():  ");
}
/*
on entry:           3 4 5 6 7 5 6 7 8 9 1 2 3 4
after make_heap():  9 8 6 7 7 5 5 3 6 4 1 2 3 4
after pop_heap():   8 7 6 7 4 5 5 3 6 4 1 2 3
after push_heap():  17 7 8 7 4 5 6 3 6 4 1 2 3 5
after sort_heap():  1 2 3 3 4 4 5 5 6 6 7 7 8 17
请按任意键继续. . .
*/
