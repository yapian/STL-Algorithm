#include "algostuff.h"
using namespace placeholders;

int main()
{
	vector<int> coll1;
	list<int> coll2;

	insert_elements(coll1, 1, 9);
	print_elements(coll1, "coll1:   ");

	// negate all elements in coll1
	transform(coll1.cbegin(), coll1.cend(),    // source range
		coll1.begin(),                   // destination range
		negate<int>());                  // operation
	print_elements(coll1, "negated: ");

	// transform elements of coll1 into coll2 with ten times their value
	transform(coll1.cbegin(), coll1.cend(),    // source range
		back_inserter(coll2),            // destination range
		bind(multiplies<int>(), _1, 10));  // operation
	print_elements(coll2, "coll2:   ");

	// print coll2 negatively and in reverse order
	transform(coll2.crbegin(), coll2.crend(),  // source range
		ostream_iterator<int>(cout, " "), // destination range
		[](int elem){                    // operation
		return -elem;
	});
	cout << endl;

	/*
	* 将两序列的元素结合
	*/
	vector<int> coll3;
	list<int> coll4;

	insert_elements(coll3, 1, 9);
	print_elements(coll3, "coll3:   ");

	// square each element
	transform(coll3.cbegin(), coll3.cend(),     // first source range
		coll3.cbegin(),                   // second source range
		coll3.begin(),                    // destination range
		multiplies<int>());               // operation
	print_elements(coll3, "squared: ");

	// add each element traversed forward with each element traversed backward
	// and insert result into coll2
	transform(coll3.cbegin(), coll3.cend(),     // first source range
		coll3.crbegin(),                  // second source range
		back_inserter(coll4),             // destination range
		plus<int>());                     // operation
	print_elements(coll4, "coll4:   ");

	// print differences of two corresponding elements
	cout << "diff:    ";
	transform(coll3.cbegin(), coll3.cend(),     // first source range
		coll4.cbegin(),                   // second source range
		ostream_iterator<int>(cout, " "), // destination range
		minus<int>());                    // operation
	cout << endl;

}
/*
coll1:   1 2 3 4 5 6 7 8 9
negated: -1 -2 -3 -4 -5 -6 -7 -8 -9
coll2:   -10 -20 -30 -40 -50 -60 -70 -80 -90
90 80 70 60 50 40 30 20 10
coll3:   1 2 3 4 5 6 7 8 9
squared: 1 4 9 16 25 36 49 64 81
coll4:   82 68 58 52 50 52 58 68 82
diff:    -81 -64 -49 -36 -25 -16 -9 -4 -1
请按任意键继续. . .
*/
