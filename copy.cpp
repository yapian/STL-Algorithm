#include "algostuff.h"


int main()
{
	vector<string> coll1 = { "Hello", "this", "is", "an", "example" };
	list<string> coll2;

	// 使用插入式代替赋值式
	copy(coll1.cbegin(), coll1.cend(),       
		back_inserter(coll2));           


	copy(coll2.cbegin(), coll2.cend(),        
		ostream_iterator<string>(cout, " "));  
	cout << endl;


	copy(coll1.crbegin(), coll1.crend(),      
		coll2.begin());                       


	copy(coll2.cbegin(), coll2.cend(),         
		ostream_iterator<string>(cout, " "));  
	cout << endl;

	// initialize source collection with "..........abcdef.........."
	vector<char> source(10, '.');
	for (int c = 'a'; c <= 'f'; c++) {
		source.push_back(c);
	}
	source.insert(source.end(), 10, '.');
	print_elements(source, "source: ");

	// copy all letters three elements in front of the 'a'
	vector<char> c1(source.cbegin(), source.cend());
	copy(c1.cbegin() + 10, c1.cbegin() + 16,           // source range
		c1.begin() + 7);                            // destination range
	print_elements(c1, "c1:     ");

	// 从后向前挨个复制，与上述copy复制的方向相反
	vector<char> c2(source.cbegin(), source.cend());
	copy_backward(c2.cbegin() + 10, c2.cbegin() + 16,  // source range
		c2.begin() + 19);                  // destination range
	print_elements(c2, "c2:     ");

}
