#include "algostuff.h"


int main()
{

	fill_n(ostream_iterator<float>(cout, " "), 10, 7.7);
	cout << endl;

	list<string> coll;

	// insert "hello" nine times
	fill_n(back_inserter(coll),	9, "hello"); 
	print_elements(coll, "coll: ");

	// overwrite all elements with "again"
	fill(coll.begin(), coll.end(), "again");
	print_elements(coll, "coll: ");

	// replace all but two elements with "hi"
	fill_n(coll.begin(), coll.size() - 2, "hi"); 
	print_elements(coll, "coll: ");

	// replace the second and up to the last element but one with "hmmm"
	list<string>::iterator pos1, pos2;
	pos1 = coll.begin();
	pos2 = coll.end();
	fill(++pos1, --pos2, "hmmm");  
	print_elements(coll, "coll: ");


}
