#include "algostuff.h"

bool bothEvenOrOdd(int elem1, int elem2)
{
	return elem1 % 2 == elem2 % 2;
}

void equal_test()
{
	vector<int> coll1;
	list<int> coll2;

	insert_elements(coll1, 1, 7);
	insert_elements(coll2, 3, 9);

	print_elements(coll1, "coll1: ");
	print_elements(coll2, "coll2: ");

	// check whether both collections are equal
	if (equal(coll1.begin(), coll1.end(),  // first range
		coll2.begin())) {            // second range
		cout << "coll1 == coll2" << endl;
	}
	else {
		cout << "coll1 != coll2" << endl;
	}

	// check for corresponding even and odd elements
	if (equal(coll1.begin(), coll1.end(),  // first range
		coll2.begin(),               // second range
		bothEvenOrOdd)) {            // comparison criterion
		cout << "even and odd elements correspond" << endl;
	}
	else {
		cout << "even and odd elements do not correspond" << endl;
	}
}

void permutation_test()
{
	vector<int> coll1;
	list<int> coll2;
	deque<int> coll3;

	coll1 = { 1, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	coll2 = { 1, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	coll3 = { 11, 12, 13, 19, 18, 17, 16, 15, 14, 11 };

	print_elements(coll1, "coll1: ");
	print_elements(coll2, "coll2: ");
	print_elements(coll3, "coll3: ");

	// check whether both collections have equal elements in any order
	if (is_permutation(coll1.cbegin(), coll1.cend(), // first range
		coll2.cbegin())) {            // second range
		cout << "coll1 and coll2 have equal elements" << endl;
	}
	else {
		cout << "coll1 and coll2 don't have equal elements" << endl;
	}

	// check for corresponding number of even and odd elements
	if (is_permutation(coll1.cbegin(), coll1.cend(), // first range
		coll3.cbegin(),               // second range
		bothEvenOrOdd)) {             // comparison criterion
		cout << "numbers of even and odd elements match" << endl;
	}
	else {
		cout << "numbers of even and odd elements don't match" << endl;
	}
}

void mismatch_test()
{
	vector<int> coll1 = { 1, 2, 3, 4, 5, 6 };
	list<int>   coll2 = { 1, 2, 4, 8, 16, 3 };

	print_elements(coll1, "coll1: ");
	print_elements(coll2, "coll2: ");

	// find first mismatch
	auto values = mismatch(coll1.cbegin(), coll1.cend(),  // first range
		coll2.cbegin());               // second range
	if (values.first == coll1.end()) {
		cout << "no mismatch" << endl;
	}
	else {
		cout << "first mismatch: "
			<< *values.first << " and "
			<< *values.second << endl;
	}

	// find first position where the element of coll1 is not
	// less than the corresponding element of coll2
	values = mismatch(coll1.cbegin(), coll1.cend(),       // first range
		coll2.cbegin(),                     // second range
		less_equal<int>());                 // criterion
	if (values.first == coll1.end()) {
		cout << "always less-or-equal" << endl;
	}
	else {
		cout << "not less-or-equal: "
			<< *values.first << " and "
			<< *values.second << endl;
	}
}
int main()
{
	equal_test(); // 检验相等性

	permutation_test(); // 两个区间是否为一个排列组合，也就是”顺序无所谓“的情况下两区间的相等性

	mismatch_test(); // 返回值是pair， 指向第一组不匹配的位置

	//lexicographical_compare 使用字典序比较两个序列的大小
}

