#include "algostuff.h"

// 原地合并
int main()
{
	list<int> coll;

	// insert two sorted sequences
	insert_elements(coll, 1, 7);
	insert_elements(coll, 1, 8);
	print_elements(coll);

	// find beginning of second part (element after 7)
	list<int>::iterator pos;
	pos = find(coll.begin(), coll.end(), 7);    
	++pos;

	// merge into one sorted range
	inplace_merge(coll.begin(), pos, coll.end());

	print_elements(coll);

}
