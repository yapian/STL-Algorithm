#include "algostuff.h"
using namespace placeholders;
// 1；如果没有找到匹配元素，它们都返回end
// 2. 如果是已排序区间，使用效率更高的lower_bound(), upper_bound(), equal_range(), binary_search()等
// 3. 关联容器和未排序容器使用成员函数find()
int main()
{
	list<int> coll;
	insert_elements(coll, 1, 9);
	insert_elements(coll, 1, 9);
	print_elements(coll, "coll: ");
	list<int>::iterator pos1;
	pos1 = find(coll.begin(), coll.end(), 4);

	list<int>::iterator pos2;
	if (pos1 != coll.end())
		pos2 = find(++pos1, coll.end(), 4);

	if (pos1 != coll.end() && pos2 != coll.end())
		copy(--pos1, ++pos2, ostream_iterator<int>(cout, " "));
	cout << endl;

	// find_if() 和 find_id_not() 的用法
	pos1 = find_if(coll.begin(), coll.end(), bind(greater<int>(), _1, 3)); // 第一个大于3的元素
	cout << "the " << distance(coll.begin(), pos1) + 1 << ". element is the first greater than 3. " << endl;

	pos2 = find_if_not(coll.begin(), coll.end(), bind(less<int>(), _1, 3)); // 使得小于3为假的第一个元素
	cout << *pos2 << endl;
}
