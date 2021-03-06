#include "algostuff.h"


int main()
{

	int source[] = { 1, 4, 4, 6, 1, 2, 2, 3, 1, 6, 6, 6, 5, 7, 5, 4, 4 };
	list<int> coll;

	copy(begin(source), end(source), back_inserter(coll));  
	print_elements(coll);

	auto pos = unique(coll.begin(), coll.end());

	copy(coll.begin(), pos, ostream_iterator<int>(cout, " "));
	cout << "\n\n";

	
	copy(begin(source), end(source), coll.begin());  
	print_elements(coll);

	coll.erase(unique(coll.begin(), coll.end(),	greater<int>()), coll.end());
	print_elements(coll);

	unique_copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout, " ")); 
	cout << endl;
}

/*
1 4 4 6 1 2 2 3 1 6 6 6 5 7 5 4 4
1 4 6 1 2 3 1 6 5 7 5 4

1 4 4 6 1 2 2 3 1 6 6 6 5 7 5 4 4
1 4 4 6 6 6 6 7
1 4 6 7
请按任意键继续. . .
*/
