#include "algostuff.h"

// 以此赋值 value, value+1, value+2, ...
int main()
{
	array<int, 10> coll;

	iota(coll.begin(), coll.end(),  // destination range
		42);                       // start value

	print_elements(coll, "coll: ");
}

