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
#include <vector>

using namespace std;

// globals
const static int DEBUG = true;

// ------------
// read
// ------------

/*
reads two ints into i and j
@param r a  std::istream
@param men is 2d array
@return true if that succeeds, false otherwise
*/
bool read (istream& r, vector< vector<int> > men, vector< vector<int> > women){
	assert(r != NULL);

	if (!r)
		return false;
	
	int n;		// number of marriages
	r >> n;
	if (DEBUG) cerr << "n: " << n << endl;
	assert(n <= 500);
	assert(n >= 0);

	men.resize(n+1);		// 0th element is always empty
	for(int i = 1; i < n+1; ++i){
		men[i].resize(n+1);
		int x;
		r >> x;		// unneeded input
		//if (DEBUG) cerr << "men[0][0]: " << men[0][0] << endl;
		for(int j = 1; j < n+1; ++j){
			r >> men[i][j];
			if (DEBUG) cerr << men[i][j] << " ";
		}
		if (DEBUG) cerr << endl;
	}
	
	women.resize(n+1);		// 0th element is always empty
	for(int i = 1; i < n+1; ++i){
		women[i].resize(n+1);
		int x;
		r >> x;		// unneeded input
		for(int j = 1; j < n+1; ++j){
			r >> women[i][j];
			if (DEBUG) cerr << women[i][j] << " ";
		}
		if (DEBUG) cerr << endl;
	}




	return true;
}

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
int eval (int t, int n) {
	assert(t <= 100);
	assert(t >= 0);
	assert(n <= 500);

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
void print (ostream& w, int i, int j, int v) {
	assert(i > 0);
	assert(j > 0);
	assert(v > 0);

	w << i << " " << j << " " << v << endl;
}

// -------------
// solve
// -------------

/**
 * read, eval, print loop
 * @param r a std::istream
 * @param w a std::ostream
 */
void solve (istream& r, ostream& w) {
	int t;
	vector< vector<int> > men, women;

	r >> t;		// number of test cases
	if (DEBUG) cerr << "t: " << t << endl;
	assert(t <= 100);
	assert(t >= 0);

	for(int i = 0; i < t; ++i){
		read(r, men, women);
	//	const int v = eval(t, men, women);
	//	print(w, t, n, v);
	}
}