#include "algostuff.h"

bool lessLength(const string& s1, const string& s2)
{
	return s1.length() < s2.length();
}

int main()
{
	deque<int> coll;

	insert_elements(coll, 1, 9);
	insert_elements(coll, 1, 9);

	print_elements(coll, "on entry: ");

	// sort elements
	sort(coll.begin(), coll.end());

	print_elements(coll, "sorted:   ");

	// sorted reverse
	sort(coll.begin(), coll.end(), greater<int>());        

	print_elements(coll, "sorted >: ");

	/*
	*more
	*/

	// fill two collections with the same elements
	vector<string> coll1 = { "1xxx", "2x", "3x", "4x", "5xx", "6xxxx",
		"7xx", "8xxx", "9xx", "10xxx", "11", "12",
		"13", "14xx", "15", "16", "17" };
	vector<string> coll2(coll1);

	print_elements(coll1, "on entry:\n ");

	// sort (according to the length of the strings)
	sort(coll1.begin(), coll1.end(), lessLength); 
	stable_sort(coll2.begin(), coll2.end(), lessLength);      

	print_elements(coll1, "\nwith sort():\n ");
	print_elements(coll2, "\nwith stable_sort():\n ");
}
/*
on entry: 1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9
sorted:   1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9
sorted >: 9 9 8 8 7 7 6 6 5 5 4 4 3 3 2 2 1 1
on entry:
1xxx 2x 3x 4x 5xx 6xxxx 7xx 8xxx 9xx 10xxx 11 12 13 14xx 15 16 17

with sort():
2x 3x 4x 11 12 13 15 16 17 5xx 7xx 9xx 1xxx 8xxx 14xx 6xxxx 10xxx

with stable_sort():
2x 3x 4x 11 12 13 15 16 17 5xx 7xx 9xx 1xxx 8xxx 14xx 6xxxx 10xxx
请按任意键继续. . .
*/
