#include "algostuff.h"


int main()
{
	/*
	* binary_search()
	*/
	list<int> coll;
	insert_elements(coll, 1, 9);
	print_elements(coll);

	// check existence of element with value 5
	if (binary_search(coll.cbegin(), coll.cend(), 5)) {
		cout << "5 is present" << endl;
	}
	else {
		cout << "5 is not present" << endl;
	}

	// check existence of element with value 42
	if (binary_search(coll.cbegin(), coll.cend(), 42)) {
		cout << "42 is present" << endl;
	}
	else {
		cout << "42 is not present" << endl;
	}


	/*
	* includes 两个都是排序区间， 全部包含子区间内的元素
	*/

	coll.clear();
	vector<int> search;

	insert_elements(coll, 1, 9);
	print_elements(coll, "coll:   ");

	search.push_back(3);
	search.push_back(4);
	search.push_back(7);
	print_elements(search, "search: ");

	// check whether all elements in search are also in coll
	if (includes(coll.cbegin(), coll.cend(),
		search.cbegin(), search.cend())) {
		cout << "all elements of search are also in coll"
			<< endl;
	}
	else {
		cout << "not all elements of search are also in coll"
			<< endl;
	}

	/*
	* 查找第一个或最后一个位置
	*/
	coll.clear();

	insert_elements(coll, 1, 9);
	insert_elements(coll, 1, 9);
	coll.sort();
	print_elements(coll);

	// print first and last position 5 could get inserted
	auto pos1 = lower_bound(coll.cbegin(), coll.cend(), 5);
	auto pos2 = upper_bound(coll.cbegin(), coll.cend(), 5);

	cout << "5 could get position "
		<< distance(coll.cbegin(), pos1) + 1
		<< " up to "
		<< distance(coll.cbegin(), pos2) + 1
		<< " without breaking the sorting" << endl;

	// insert 3 at the first possible position without breaking the sorting
	coll.insert(lower_bound(coll.begin(), coll.end(), 3), 3);

	// insert 7 at the last possible position without breaking the sorting
	coll.insert(upper_bound(coll.begin(), coll.end(), 7), 7);

	print_elements(coll);


	/*
	* equal_range
	*/

	coll.clear();

	insert_elements(coll, 1, 9);
	insert_elements(coll, 1, 9);
	coll.sort();
	print_elements(coll);

	// print first and last position 6 could get inserted
	pair<list<int>::const_iterator, list<int>::const_iterator> range;
	range = equal_range(coll.cbegin(), coll.cend(), 6);

	cout << "6 could get position "
		<< distance(coll.cbegin(), range.first) + 1
		<< " up to "
		<< distance(coll.cbegin(), range.second) + 1
		<< " without breaking the sorting" << endl;

}

/*
1 2 3 4 5 6 7 8 9
5 is present
42 is not present
coll:   1 2 3 4 5 6 7 8 9
search: 3 4 7
all elements of search are also in coll
1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9
5 could get position 9 up to 11 without breaking the sorting
1 1 2 2 3 3 3 4 4 5 5 6 6 7 7 7 8 8 9 9
1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9
6 could get position 11 up to 13 without breaking the sorting
请按任意键继续. . .
*/
