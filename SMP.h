/*
Ian Buitrago
6-18-2012
CS 378
Project 2: Stable Marriage Problem
*/


// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream

// globals
const static int DEBUG = true;

// ------------
// read
// ------------

/*
reads two ints into i and j
@param r a  std::istream
@param i an int by reference
@param j an int by reference
@return true if that succeeds, false otherwise
*/
bool read (std::istream& r, int& i, int& j) {
	r >> i;
	if (!r)
		return false;
	r >> j;


	assert(i > 0);
	assert(j > 0);
	return true;}

// -------------
// cycleLength
// -------------

/**
 * returns v, the cycle length
 * @param n positive integer
 */
int cycleLength (int n) {
	assert(n > 0);

	
	assert(1 > 0);
	return 0;
}

// ------------
// eval
// ------------

/**
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @return the max cycle length in the range [i, j]
 */
int eval (int i, int j) {
	assert(i > 0);
	assert(j > 0);

	int v = 1;

	assert(v > 0);

	return v;
}


// -------------
// print
// -------------

/**
 * prints the values of i, j, and v
 * @param w a std::ostream
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @param v the max cycle length
 */
void print (std::ostream& w, int i, int j, int v) {
	assert(i > 0);
	assert(j > 0);
	assert(v > 0);

	w << i << " " << j << " " << v << std::endl;
}

// -------------
// solve
// -------------

/**
 * read, eval, print loop
 * @param r a std::istream
 * @param w a std::ostream
 */
void solve (std::istream& r, std::ostream& w) {
	int i;
	int j;
	while (read(r, i, j)) {
		const int v = eval(i, j);
		print(w, i, j, v);
	}
}