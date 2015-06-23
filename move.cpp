#include "algostuff.h"


int main()
{
	vector<string> coll1 = { "Hello", "this", "is", "an", "example" };
	list<string> coll2;


	copy(coll1.cbegin(), coll1.cend(),        
		back_inserter(coll2));                


	move(coll2.cbegin(), coll2.cend(),         // source range
		ostream_iterator<string>(cout, " "));  // destination range
	cout << endl;


	move(coll1.crbegin(), coll1.crend(),       // source range
		coll2.begin());                       // destination range


	move(coll2.cbegin(), coll2.cend(),         // source range
		ostream_iterator<string>(cout, " "));  // destination range
	cout << endl;


}

/*
Hello this is an example
example an is this Hello
请按任意键继续. . .
 */
