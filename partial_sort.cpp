#include "algostuff.h"


int main()
{
	deque<int> coll;

	insert_elements(coll, 3, 7);
	insert_elements(coll, 2, 6);
	insert_elements(coll, 1, 5);
	print_elements(coll);

	// 在 coll.begin() 至 coll.end() 范围内， 只求前5个最小元素， 不保证后面的元素有序
	partial_sort(coll.begin(), coll.begin() + 5, coll.end());
	print_elements(coll);

	partial_sort(coll.begin(), coll.begin() + 5, coll.end(), greater<int>());
	print_elements(coll);


	partial_sort(coll.begin(), coll.end(), coll.end());
	print_elements(coll);

	/*
	* partial_sort_copy
	*/
	deque<int> coll1;
	vector<int> coll6(6);      // initialize with 6 elements
	vector<int> coll30(30);    // initialize with 30 elements

	insert_elements(coll1, 3, 7);
	insert_elements(coll1, 2, 6);
	insert_elements(coll1, 1, 5);
	print_elements(coll1);

	// 排序区间是源区间或者目标区间的最小范围
	// copy elements of coll1 sorted into coll6
	vector<int>::const_iterator pos6;
	pos6 = partial_sort_copy(coll1.cbegin(), coll1.cend(),
		coll6.begin(), coll6.end());

	// 返回的迭代器指向目标区域”最后被复制元素“的下一个位置
	// print all copied elements
	copy(coll6.cbegin(), pos6,
		ostream_iterator<int>(cout, " "));
	cout << endl;

	// copy elements of coll1 sorted into coll30
	vector<int>::const_iterator pos30;
	pos30 = partial_sort_copy(coll1.cbegin(), coll1.cend(),
		coll30.begin(), coll30.end(),
		greater<int>());

	// print all copied elements
	copy(coll30.cbegin(), pos30,
		ostream_iterator<int>(cout, " "));
	cout << endl;
}
/*
3 4 5 6 7 2 3 4 5 6 1 2 3 4 5
1 2 2 3 3 7 6 5 5 6 4 4 3 4 5
7 6 6 5 5 1 2 2 3 3 4 4 3 4 5
1 2 2 3 3 3 4 4 4 5 5 5 6 6 7
3 4 5 6 7 2 3 4 5 6 1 2 3 4 5
1 2 2 3 3 3
7 6 6 5 5 5 4 4 4 3 3 3 2 2 1
请按任意键继续. . .
*/
