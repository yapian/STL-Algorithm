#include "algostuff.h"

/*
 *检验区间内元素是否已经排序，is_sorted_until()返回第一个破坏排序的元素迭代器，可以使用新增加的操作符判断
 * 
 */
int main()
{
	vector<int> coll1 = { 1, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	print_elements(coll1, "coll1: ");

	// check whether coll1 is sorted
	if (is_sorted(coll1.begin(), coll1.end())) {
		cout << "coll1 is sorted" << endl;
	}
	else {
		cout << "coll1 is not sorted" << endl;
	}

	map<int, string> coll2{ { 1, "Bill" }, { 2, "Jim" }, { 3, "Nico" }, { 4, "Liu" }, { 5, "Ai" } };
	print_mapped_elements(coll2, "coll2: ");

	// define predicate to compare names
	auto compareName = [](const pair<int, string>& e1,
		const pair<int, string>& e2){
		return e1.second<e2.second;
	};

	// check whether the names in coll2 are sorted
	if (is_sorted(coll2.cbegin(), coll2.cend(),
		compareName)) {
		cout << "names in coll2 are sorted" << endl;
	}
	else {
		cout << "names in coll2 are not sorted" << endl;
	}

	// print first unsorted name
	auto pos = is_sorted_until(coll2.cbegin(), coll2.cend(),
		compareName);
	if (pos != coll2.end()) {
		cout << "first unsorted name: " << pos->second << endl;
	}
}
