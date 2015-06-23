#include "algostuff.h"


int main()
{
	vector<int> coll;
	insert_elements(coll, 1, 3);
	print_elements(coll, "on entry:  ");

	
	while (next_permutation(coll.begin(), coll.end())) {
		print_elements(coll, " ");
	}
	print_elements(coll, "afterward: ");

	
	while (prev_permutation(coll.begin(), coll.end())) {
		print_elements(coll, " ");
	}
	print_elements(coll, "now:       ");

	
	while (prev_permutation(coll.begin(), coll.end())) {
		print_elements(coll, " ");
	}
	print_elements(coll, "afterward: ");

}

