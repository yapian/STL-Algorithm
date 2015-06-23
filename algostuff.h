/*
*文件中包含后面示例用到的所有头文件
*以及三个辅助函数，用来生成测试数据或者打印相应的容器元素
*/
#ifndef ALGOSTUFF_H
#define ALGOSTUFF_H
#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <list>
#include <forward_list>
#include <memory>
#include <set>
#include <unordered_set>
#include <numeric>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include <limits>
#include <chrono>
#include <map>
#include <functional>
template<typename T>
inline void insert_elements(T& coll, int first, int last)
{
	for (int i = first; i <= last; ++i)
		coll.insert(coll.end(), i);
}
template<typename T>
inline void print_elements(const T& coll, const string& optcstr = "")
{
	cout << optcstr;
	for (auto elem : coll)
		cout << elem << ' ';
	cout << endl;
}

template<typename T>
inline void print_mapped_elements(const T& coll, const string& optcstr = "")
{
	cout << optcstr;
	for (auto elem : coll)
		cout << '[' << elem.first << ',' << elem.second << '] ';
	cout << endl;
}
#endif
