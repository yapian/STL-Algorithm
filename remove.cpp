#include "algostuff.h"
using namespace placeholders;

int main()
{
	vector<int> coll;

	insert_elements(coll, 2, 6);
	insert_elements(coll, 4, 9);
	insert_elements(coll, 1, 7);
	print_elements(coll, "coll:               ");
	
	// 将原本置于后面的未删除元素向前移动，覆盖被移除元素； 返回值指向新的逻辑终点，应该将此终点至原终点的迭代器范围erase
	vector<int>::iterator pos;
	pos = remove(coll.begin(), coll.end(), 5); 

	print_elements(coll, "size not changed:   ");

	coll.erase(pos, coll.end());
	print_elements(coll, "size changed:       ");

	coll.erase(remove_if(coll.begin(), coll.end(), [](int elem){ return elem<4;	}), coll.end());
	print_elements(coll, "<4 removed:         ");


	/*
	* 复制时一并移除元素
	*/
	list<int> coll1;

	insert_elements(coll1, 1, 6);
	insert_elements(coll1, 1, 9);
	print_elements(coll1);

	
	remove_copy(coll1.cbegin(), coll1.cend(),  ostream_iterator<int>(cout, " "),  3);                       
	cout << endl;

	remove_copy_if(coll1.cbegin(), coll1.cend(), ostream_iterator<int>(cout, " "), [](int elem){ return elem>4; });
	cout << endl;

	
	multiset<int> coll2;
	remove_copy_if(coll1.cbegin(), coll1.cend(), inserter(coll2, coll2.end()), bind(less<int>(), _1, 4)); 
	print_elements(coll2);

}

/*
coll:               2 3 4 5 6 4 5 6 7 8 9 1 2 3 4 5 6 7
size not changed:   2 3 4 6 4 6 7 8 9 1 2 3 4 6 7 5 6 7
size changed:       2 3 4 6 4 6 7 8 9 1 2 3 4 6 7
<4 removed:         4 6 4 6 7 8 9 4 6 7
1 2 3 4 5 6 1 2 3 4 5 6 7 8 9
1 2 4 5 6 1 2 4 5 6 7 8 9
1 2 3 4 1 2 3 4
4 4 5 5 6 6 7 8 9
请按任意键继续. . .
*/
