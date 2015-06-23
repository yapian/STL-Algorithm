#include "algostuff.h"

bool absLess(int elem1, int elem2)
{
	return abs(elem1) < abs(elem2);
}
int main()
{
	deque<int> coll;
	insert_elements(coll, 2, 6);
	insert_elements(coll, -3, 6);
	print_elements(coll);
	// 返回找到的第一个最大或最小元素
	cout << "min: " << *min_element(coll.cbegin(), coll.cend()) << endl;
	cout << "max: " << *max_element(coll.cbegin(), coll.cend()) << endl;

	// minmax_element 返回的是最小值的第一个元素和最大值的最后一个元素
	auto mm = minmax_element(coll.cbegin(), coll.cend());
	cout << "min: " << *(mm.first) << endl;
	cout << "max: " << *(mm.second) << endl;
	cout << "distance: " << distance(mm.first, mm.second) << endl;

	cout << "min of absolute values: " << *min_element(coll.cbegin(), coll.cend(), absLess) << endl;
	cout << "max of absolute values: " << *max_element(coll.cbegin(), coll.cend(), absLess) << endl;
}

