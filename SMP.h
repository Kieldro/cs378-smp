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
#include <deque>

// macros
#define DEBUG true

using namespace std;

typedef vector< vector<int> > vvec;

// globals


// prototypes
bool populateMen(istream& r, const int n, vvec& men);
bool read (istream& r, int& n, vvec& men, vvec& women);
vvec eval (int n, vvec men, vvec women);
void print (ostream& w, int n, vvec solution);
void solve (istream& r, ostream& w);

// -------------
// populateMen
/**
 * returns true if successful
 * @param r input stream
 * @param n constant integer number of preferences/marriages
 * @param men vector of vector of ints
 */
bool populateMen(istream& r, const int n, vvec& men){
	if (DEBUG) cerr << "populateMen()..." << endl;
	assert(n >= 0);

	// 0th element is fiance, 1-n elements hold the rank of the preferences, n+1 is next proposal
	men.resize(n+1);		// 0th element is always empty
	for(int i = 1; i < n+1; ++i){
		men[i].resize(n+2);
		int x = 0;
		r >> x;		// unneeded input
		men[i][0] = 0;		// engaged to no one
		for(int j = 1; j <= n; ++j){
			r >> men[i][j];
			if (DEBUG) cerr << men[i][j] << " ";
		}
		men[i][n+1] = 1;		// index of next proposal
		if (DEBUG) cerr << endl;
	}
	if (DEBUG) cerr << "end of populateMen()." << endl;
	return true;
}

// -------------
// populateWomen
/**
 * returns true if successful
 * @param r input stream
 * @param n constant integer number of preferences/marriages
 * @param women vector of vector of ints
 */
bool populateWomen(istream& r, const int n, vvec& women){
	if (DEBUG) cerr << "populateWomen()..." << endl;
	assert(n >= 0);

	// 0th element is fiance, 1-n elements hold the rank of the preferences, n+1 is next proposal
	women.resize(n+1);		// 0th element is always empty
	for(int i = 1; i < n+1; ++i){
		women[i].resize(n+1);
		int x = 0;
		r >> x;		// unneeded input
		women[i][0] = 0;		// engaged to no one
		for(int j = 0, man = -1; j < n; ++j){
			r >> man;
			women[i][man] = j;
			//if (DEBUG) cerr << women[i][j] << " ";
		}
	}
	if (DEBUG) cerr << "end of populateWomen()." << endl;
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
	if (DEBUG) cerr << "read()..." << endl;
	assert(r != NULL);

	if (!r)
		return false;
	
	r >> n;
	if (DEBUG) cerr << "n: " << n << endl;
	assert(n <= 500);
	assert(n >= 0);

	populateMen(r, n, men);
	populateWomen(r, n, women);
	if (DEBUG) cerr << "end of read()." << endl;
	return true;
}

// ------------
// eval
/**
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @return the max cycle length in the range [i, j]
 */
vvec eval (const int n, vvec men, vvec women) {
	if (DEBUG) cerr << "eval()..." << endl;
	vvec solution(n,  vector<int> (2) );
	deque<int> freeMen;

	// initialize freeMen
	for(int i = 0; i < n; ++i){
		freeMen.push_back(i+1);
	}
	// freeMen == [1, 2, ..., n]

	while(freeMen.size() > 0){
		//if (DEBUG) cerr << "freesize(): " << freeMen.size() << endl;
		int man = freeMen.front();
		freeMen.pop_front();		// O(1)
		int woman = men[man][n+1];		// next woman to propose to
		++men[man][n+1];				// set next proposal

		if(women[woman][0] == 0){	// free woman
			// engage man and woman
			women[woman][0] = man;
			men[man][0] = woman;
		}else{
			int fiance = women[woman][0];
			if(women[woman][man] < women[woman][fiance] ){
				women[woman][0] = man;
				men[man][0] = woman;
				// dump former fiance
				assert(fiance != 0);
				men[fiance][0] = 0;		// now engaged to no one
				freeMen.push_back(fiance);
			}else
				freeMen.push_back(man);		// man found no willing woman, put back in free pool
		}
	}

	if (DEBUG) cerr << "end of eval()." << endl;

	for(int i = 0; i < n; ++i){
		solution[i][0] = i+1;
		solution[i][1] = men[i+1][0];
	}


	return solution;
/*
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
    */
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
	if (DEBUG) cerr << "print()..." << endl;
	assert(n > 0);
	assert(solution.size() == unsigned(n) );
	assert(solution[0].size() == (unsigned)2 );

	for(int i = 0; i < n; ++i)
		w << solution[i][0] << " " << solution[i][1] << endl;
	if (DEBUG) cerr << "end of print()." << endl;
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
	if (DEBUG) cerr << "solve()..." << endl;
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
	if (DEBUG) cerr << "end of solve()." << endl;
}