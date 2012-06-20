/*
Ian Buitrago
6-18-2012
CS 378
Project 2: Stable Marriage Problem
*/

// --------
// includes
#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <vector>

// macros
#define DEBUG true

using namespace std;

typedef vector< vector<int> > vvec;

// globals


// prototypes
bool populate(istream& r, const int n, vvec& humans);
bool read (istream& r, int& n, vvec& men, vvec& women);
vvec eval (int n, vvec men, vvec women);
void print (ostream& w, int n, vvec solution);
void solve (istream& r, ostream& w);

// -------------
// populate
/**
 * returns true if successful
 * @param r input stream
 * @param n constant integer number of preferences/marriages
 * @param humans vector of vector of ints
 */
bool populate(istream& r, const int n, vvec& humans){
	assert(n >= 0);

	humans.resize(n+1);		// 0th element is always empty
	for(int i = 1; i < n+1; ++i){
		humans[i].resize(n);
		int x = 0;
		r >> x;		// unneeded input
		for(int j = 0; j < n; ++j){
			r >> humans[i][j];
			if (DEBUG) cerr << humans[i][j] << " ";
		}
		if (DEBUG) cerr << endl;
	}

	return true;
}

// ------------
// read
/*
reads two ints into i and j
@param r a istream
@param men is 2d array
@return true if that succeeds, false otherwise
*/
bool read (istream& r, int& n, vvec& men, vvec& women){
	assert(r != NULL);

	if (!r)
		return false;
	
	r >> n;
	if (DEBUG) cerr << "n: " << n << endl;
	assert(n <= 500);
	assert(n >= 0);

	populate(r, n, men);
	populate(r, n, women);

	return true;
}

// ------------
// eval
/**
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @return the max cycle length in the range [i, j]
 */
vvec eval (int n, vvec men, vvec women) {
	vvec solution(n,  vector<int> (2) );

	//if (DEBUG) cerr << "men size: " << men.size() << endl;
	assert(men.size() == (n+1) );
	for(int i = 1; i <= n; ++i){
		//if (DEBUG) cerr << "men[i].size: " << men[i].size() << endl;
		//assert(men[i].size() == n);
		solution[i-1][0] = i;
		solution[i-1][1] = men[i][0];
	}

	assert(true);
	return solution;
	{
    Initialize all m ∈ M and w ∈ W to free
    while ∃ free man m who still has a woman w to propose to {
       w = m's highest ranked such woman to whom he has not yet proposed
       if w is free
         (m, w) become engaged
       else some pair (m', w) already exists
         if w prefers m to m'
           (m, w) become engaged
           m' becomes free
         else
           (m'', w) remain engaged
    }

}


// -------------
// print
/**
 * prints the values of i, j, and v
 * @param w a std::ostream
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @param v the max cycle length
 */
void print (ostream& w, int n, vvec solution) {
	assert(n > 0);
	assert(solution.size() == (unsigned)n );
	assert(solution[0].size() == (unsigned)2 );

	for(int i = 0; i < n; ++i)
		w << solution[i][0] << " " << solution[i][1] << endl;

/* initialize vector
	static const int arr[] = {16,2,77,29};
	vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );
	for(vector<int>::iterator i = vec.begin(); i != vec.end(); ++i)
		if (DEBUG) cerr << "vec: " << *i << endl;
*/
}

// -------------
// solve
/**
 * read, eval, print loop
 * @param r a std::istream
 * @param w a std::ostream
 */
void solve (istream& r, ostream& w) {
	int t = 0;		// number of test cases
	int n = 0;		// number of marriages
	vvec solution;
	vvec men, women;


	r >> t;		// number of test cases
	if (DEBUG) cerr << "t: " << t << endl;
	assert(t <= 100);
	assert(t >= 0);

	for(int i = 0; i < t; ++i){
		read(r, n, men, women);
		if (DEBUG) cerr << "men size: " << men.size() << endl;
		solution = eval(n, men, women);
		print(w, n, solution);
	}
}