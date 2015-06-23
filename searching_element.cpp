
#include "algostuff.h"

int main()
{
	/*
	*查找前n个连续匹配值
	*/
	deque<int> coll{ 1, 2, 7, 7, 6, 3, 9, 5, 7, 7, 7, 3, 6 };
	print_elements(coll);
	deque<int>::iterator pos;
	pos = search_n(coll.begin(), coll.end(), 3, 7); // 连续3个元素都等于7
	cout << *pos << " " << *(pos + 3) << endl; // 7  3

	// 连续4个元素使得判别式为真， value是无用的，这是基于“历史原因"遗留的
	pos = search_n(coll.begin(), coll.end(), 4, 0, [](int elem, int value){return elem % 2 == 1; });

	//如果未找到相应区间，那么将返回end()

	/*
	*查找第一个子区间
	*/
	coll.clear();
	list<int> subcoll;
	insert_elements(coll, 1, 7);
	insert_elements(coll, 1, 7);
	insert_elements(subcoll, 3, 6);
	print_elements(coll, "coll: ");
	print_elements(subcoll, "subcoll: ");
	pos = search(coll.begin(), coll.end(), subcoll.begin(), subcoll.end());
	while (pos != coll.end())
	{
		cout << "subcoll found starting with element " << distance(coll.begin(), pos) + 1 << endl;
		++pos;
		pos = search(pos, coll.end(), subcoll.begin(), subcoll.end());
	}

	// 还有一种是上述begin()再加一个BinaryPredicate operator参数的版本，两个区间的对应元素使得表达式结果为真

	/*
	*查找最后一个子区间
	*/

	pos = find_end(coll.begin(), coll.end(), subcoll.begin(), subcoll.end());
	if(pos != coll.end())
		cout << "subcoll found the lasted position: " << distance(coll.begin(), pos) + 1 << endl;

	/*
	*查找某些元素的第一次出现地点, 即子集合中的任一元素出现在原集合中的迭代器位置
	*/
	subcoll.assign({ 2, 4, 6, 8 });
	pos = find_first_of(coll.begin(), coll.end(), subcoll.begin(), subcoll.end());
	while (pos != coll.end())
	{
		cout << "we found it starting with element " << distance(coll.begin(), pos) + 1 << endl;
		pos = find_first_of(++pos, coll.end(), subcoll.begin(), subcoll.end());
	}
	
	/*
	* 查找两个连续且相等的元素, 返回值是第一对匹配的第一个元素的位置
	*/
	print_elements(coll); // 1 2 3 4 5 6 7 1 2 3 4 5 6 7 
	coll.push_back(7); // 1 2 3 4 5 6 7 1 2 3 4 5 6 7 7
	pos = adjacent_find(coll.begin(), coll.end());
	if (pos != coll.end())
		cout << *pos << " " << *(pos+1)<< endl; // 7

	// 连续两个为基数
	pos = adjacent_find(coll.begin(), coll.end(), [](int a, int b){ return a % 2 == 1 && b % 2 == 1; });
	if (pos != coll.end())
		cout << *pos <<" " << *(pos+1)<< endl;
}


