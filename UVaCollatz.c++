// ----------------------------
// projects/collatz/UVaCollatz.c++
// Copyright (C) 2014
// Glenn P. Downing
// ----------------------------
// --------
// includes
// --------
#include <cassert> // assert
#include <iostream> // endl, istream, ostream
#include <utility> // make_pair, pair
 
// ------------
// collatz_read
// ------------
std::pair<int, int> collatz_read (std::istream& r) {
	int i;
	r >> i;
	if (!r)
		return std::make_pair(0, 0);
	int j;
	r >> j;
		return std::make_pair(i, j);
}

// ------------
// collatz_eval
// ------------
int collatz_eval (int i, int j) {
	/*
		i is the beginning of the range, inclusive
		j is the end of the range, inclusive
		return the max cycle length in the range [i, j]
	*/
	assert (i > 0);
	assert (j > 0);
 
	int table [20] = {1, 2, 8, 3, 6, 9, 17, 4, 20, 7, 15, 10, 10, 18, 18, 5, 13, 21, 21, 8};
 
	int myMin;
	int myMax;
 
	if (i <= j) {
		int temp = j / 2;
		if (temp > i) 
			i = temp;
		myMin = i;
		myMax = j;
	}

	else {
		int temp = i / 2;
		if (temp > j) 
			j = temp;
		myMin = j;
		myMax = i;
	}

	int trueMax = 1;
 
	for (i = myMin; i <= myMax; i++) {

		int currentCycleLength = 0;

		j = i;
		
		while (j != 1) {

			if (j < 20) {

				//value is already in cache
				currentCycleLength += table [j - 1];
				j = 1;

			}

			else {

				//compute
				if (j % 2 != 1) {

					currentCycleLength++;
					j /= 2;

				}

				else {

					currentCycleLength += 2;
					j = ((3 * j) + 1) / 2;

				}

			}

		}

		if (currentCycleLength > trueMax)
			trueMax = currentCycleLength;
	}
	 
	assert (trueMax > 0);
	return trueMax;

}

// -------------
// collatz_print
// -------------
void collatz_print (std::ostream& w, int i, int j, int v) {
	w << i << " " << j << " " << v << std::endl;
}

// -------------
// collatz_solve
// -------------
void collatz_solve (std::istream& r, std::ostream& w) {
	while (true) {
		const std::pair<int, int> p = collatz_read(r);
		if (p == std::make_pair(0, 0))
			return;
		const int i = p.first;
		const int j = p.second;
		const int v = collatz_eval(i, j);
		collatz_print(w, i, j, v);
	}
}

int main () {
	using namespace std;
	collatz_solve(cin, cout);
	return 0;
}






