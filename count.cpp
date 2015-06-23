#include "algostuff.h"


int main()
{
	// 关联容器和无序容器提供了类似的成员函数count

	vector<int> coll;
	int num;
	insert_elements(coll, 1, 9);
	print_elements(coll, "coll : ");
	num = count(coll.begin(), coll.end(), 4);
	cout << "number of elements equal to 4:  " << num << endl;

	num = count_if(coll.cbegin(), coll.cend(), [](int elem){return elem % 2 == 0; });
	cout << "number of elements with even value: " << num << endl;
	num = count_if(coll.cbegin(), coll.cend(), [](int elem){return elem > 4; });
	cout << "number of elements greater than 4: " << num << endl;
}
