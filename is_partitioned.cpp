#include "algostuff.h"

// partition_point()用于在已分割的基础上得到第一个分割元素
int main()
{
	vector<int> coll = { 5, 3, 9, 1, 3, 4, 8, 2, 6 };
	print_elements(coll, "coll: ");

	// define predicate: check whether element is odd:
	auto isOdd = [](int elem) {return elem % 2 == 1; };

	// check whether coll is partitioned in odd and even elements
	if (is_partitioned(coll.cbegin(), coll.cend(), isOdd)) {
		cout << "coll is partitioned" << endl;

		// find first even element:
		auto pos = partition_point(coll.cbegin(), coll.cend(),
			isOdd);
		cout << "first even element: " << *pos << endl;
	}
	else {
		cout << "coll is not partitioned" << endl;
	}

}
