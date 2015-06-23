#include <random>
#include "algostuff.h"

class MyRandom {
public:
	ptrdiff_t operator() (ptrdiff_t max) {
		double tmp;
		tmp = static_cast<double>(rand())
			/ static_cast<double>(RAND_MAX);
		return static_cast<ptrdiff_t>(tmp * max);
	}
};


int main()
{
	vector<int> coll;

	insert_elements(coll, 1, 9);
	print_elements(coll, "coll:     ");

	// shuffle all elements randomly
	random_shuffle(coll.begin(), coll.end());

	print_elements(coll, "shuffled: ");

	// sort them again
	sort(coll.begin(), coll.end());
	print_elements(coll, "sorted:   ");

	// shuffle elements with default engine
	default_random_engine dre;
	shuffle(coll.begin(), coll.end(), dre);                      

	print_elements(coll, "shuffled: ");


	MyRandom rd;
	random_shuffle(coll.begin(), coll.end(), rd);                 

	print_elements(coll, "own random engine shuffled result: ");
}
/*
coll:     1 2 3 4 5 6 7 8 9
shuffled: 9 2 7 3 1 6 8 4 5
sorted:   1 2 3 4 5 6 7 8 9
shuffled: 5 1 4 2 6 8 7 3 9
own random engine shuffled result: 9 1 3 7 8 6 5 4 2
请按任意键继续. . .
*/

