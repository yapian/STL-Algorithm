#include "algostuff.h"


int main()
{

	list<int> coll;
	// 调用 rand 产生新值
	// insert five random numbers
	generate_n(back_inserter(coll), 5, rand);   
	print_elements(coll);

	// overwrite with five new random numbers
	generate(coll.begin(), coll.end(), 	rand); 
	print_elements(coll);
}

