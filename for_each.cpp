#include "algostuff.h"

template<typename T>
class AddValue
{
private:
	T theValue;
public:
	AddValue(const T& v) :theValue(v){}
	void operator()(T& elem) const
	{
		elem += theValue;
	}
};


void print(int elem)
{
	cout << elem << ' ';
}
int main()
{
	vector<int> coll;
	insert_elements(coll, 1, 9);
	//使用lambda打印元素
	for_each(coll.begin(), coll.end(), [](int elem){cout << elem << ' '; });
	cout << endl;
	for_each(coll.begin(), coll.end(), print);
	cout << endl;

	//在C++11中使用range-base for更方便
	for (auto elem : coll)
		cout << elem << ' ';
	cout << endl;

	// 更改元素
	for_each(coll.begin(), coll.end(), [](int &elem){elem += 10; });
	print_elements(coll);
	for_each(coll.begin(), coll.end(), [=](int &elem){elem += *coll.begin(); });
	print_elements(coll);

	//传递函数对象
	for_each(coll.begin(), coll.end(),AddValue<int>(10));
	print_elements(coll);

	//for_each能够通过返回值回传函数对象，double mv = for_each(coll.begin(), coll.end(), MeanValue());会调用类的operator double()方法
}

