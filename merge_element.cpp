#include "algostuff.h"


int main()
{
	vector<int> c1 = { 1, 2, 2, 4, 6, 7, 7, 9 };

	deque<int>  c2 = { 2, 2, 2, 3, 6, 6, 8, 9 };

	// print source ranges
	cout << "c1:                         ";
	copy(c1.cbegin(), c1.cend(),
		ostream_iterator<int>(cout, " "));
	cout << endl;
	cout << "c2:                         ";
	copy(c2.cbegin(), c2.cend(),
		ostream_iterator<int>(cout, " "));
	cout << '\n' << endl;

	// sum the ranges by using merge()
	cout << "merge():                    ";
	merge(c1.cbegin(), c1.cend(),
		c2.cbegin(), c2.cend(),
		ostream_iterator<int>(cout, " "));
	cout << endl;

	// 并集， 同时出现在集合中的元素，在并集中只出现一次， 如果本来就有重复元素--并集中的重复次数是源区间中重复次数的较大值
	// unite the ranges by using set_union()
	cout << "set_union():                ";
	set_union(c1.cbegin(), c1.cend(),
		c2.cbegin(), c2.cend(),
		ostream_iterator<int>(cout, " "));
	cout << endl;

	// 交集， 如果本来就有重复元素--交集中的重复次数是源区间中重复次数的较小值
	// intersect the ranges by using set_intersection()
	cout << "set_intersection():         ";
	set_intersection(c1.cbegin(), c1.cend(),
		c2.cbegin(), c2.cend(),
		ostream_iterator<int>(cout, " "));
	cout << endl;

	// 差集， 如果本来就有重复元素--差集中的重复次数是第一源区间中重复次数减去第二源区间重复次数
	// determine elements of first range without elements of second range
	// by using set_difference()
	cout << "set_difference():           ";
	set_difference(c1.cbegin(), c1.cend(),
		c2.cbegin(), c2.cend(),
		ostream_iterator<int>(cout, " "));
	cout << endl;

	// 或存在第一个区间，或存在于第二个区间中，重复次数为相减的值
	// determine difference the ranges with set_symmetric_difference()
	cout << "set_symmetric_difference(): ";
	set_symmetric_difference(c1.cbegin(), c1.cend(),
		c2.cbegin(), c2.cend(),
		ostream_iterator<int>(cout, " "));
	cout << endl;

}

/*
c1:                         1 2 2 4 6 7 7 9
c2:                         2 2 2 3 6 6 8 9

merge():                    1 2 2 2 2 2 3 4 6 6 6 7 7 8 9 9
set_union():                1 2 2 2 3 4 6 6 7 7 8 9
set_intersection():         2 2 6 9
set_difference():           1 4 7 7
set_symmetric_difference(): 1 2 3 4 6 7 7 8
请按任意键继续. . .
*/
