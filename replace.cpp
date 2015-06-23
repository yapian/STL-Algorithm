#include "algostuff.h"
using namespace placeholders;

int main()
{
	list<int> coll;

	insert_elements(coll, 2, 7);
	insert_elements(coll, 4, 9);
	print_elements(coll, "coll: ");

	// 使用42替换6
	replace(coll.begin(), coll.end(), 6, 42);                          
	print_elements(coll, "coll: ");

	// 将满足第三个参数判别式的元素替换为0
	replace_if(coll.begin(), coll.end(), [](int elem){ return elem<5;},	0);  
	print_elements(coll, "coll: ");

	/*
	* 复制并替换元素
	*/
	coll.clear();


	insert_elements(coll, 2, 6);
	insert_elements(coll, 4, 9);
	print_elements(coll);

	
	replace_copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout, " "), 5, 55);                                
	cout << endl;

	replace_copy_if(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout, " "), bind(less<int>(), _1, 5), 42);  
	cout << endl;

	
	replace_copy_if(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout, " "), [](int elem){ return elem % 2 == 1;}, 0); 
	cout << endl;

}

/*
coll: 2 3 4 5 6 7 4 5 6 7 8 9
coll: 2 3 4 5 42 7 4 5 42 7 8 9
coll: 0 0 0 5 42 7 0 5 42 7 8 9
2 3 4 5 6 4 5 6 7 8 9
2 3 4 55 6 4 55 6 7 8 9
42 42 42 5 6 42 5 6 7 8 9
2 0 4 0 6 4 0 6 0 8 0
请按任意键继续. . .
*/
