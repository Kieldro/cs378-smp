/*
To test the program:
    % ls /usr/include/cppunit/
    ...
    HelperMacros.h
    ...
    % locate libcppunit.a
    /usr/lib/libcppunit.a
    % g++ -ansi -pedantic -lcppunit -ldl -Wall TestCollatz.c++ -o TestCollatz.c++.app
    % valgrind TestCollatz.c++.app >& TestCollatz.c++.out
*/

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#include "SMP.h"

using namespace std;

// -----------
// TestCollatz
// -----------

struct TestSMP : CppUnit::TestFixture {
    // ----
    // populate
    void test_populate_1 () {
        int n = 3;
        istringstream r("1 1 2 3\n2 2 1 3\n3 3 2 1\n");
        vector< vector<int> > humans;
        populate(r, n, humans);
        CPPUNIT_ASSERT(humans.size() == (unsigned int)n+1);
    }
/*
    // ----
    // read
    void test_read_1 () {
        istringstream r("1\n3\n1 1 2 3\n2 2 1 3\n3 3 2 1\n");
        int t, n = -1;
        cin >> t;
        vector< vector<int> > men, women;
        read(r, n, men, women);
        if (DEBUG) cerr << "men: " << 1 << endl;
        CPPUNIT_ASSERT(n == 3);
        CPPUNIT_ASSERT( (int)men.size() == n+1);
        CPPUNIT_ASSERT( (int)women.size() == n+1);
    }

    // ----
    // eval
    void test_eval_1 () {
        int n = 3;
        vector< vector<int> > men, women;
        const vector< vector<int> > sol = eval(n, men, women);
        CPPUNIT_ASSERT( (int)sol.size() == n);
    }

    // -----
    // print
    void test_print_1 () {
        ostringstream w;
        int n = 3;
        static const int arr[] = {16,2,77,29};
        vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );
        if (DEBUG) cerr << "vec.size(): " << vec.size() << endl;
        const vector< vector<int> > sol;
        print(w, n, sol);
        CPPUNIT_ASSERT(w.str() == "1 2\n2 1\n3 3\n");
    }

    // -----
    // solve
    void test_solve_1 () {
        istringstream r("1 3\n1 1 2 3\n2 2 3 1\n3 3 2 1\n1 3 2 1\n2 2 3 1\n3 3 2 1\n");
        ostringstream w;
        solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 2\n2 1\n3 3\n");
    }
*/
    // -----
    // suite
    CPPUNIT_TEST_SUITE(TestSMP);

 /*   CPPUNIT_TEST(test_populate_1);

 /*   CPPUNIT_TEST(test_read_1);
    CPPUNIT_TEST(test_read_2);
    CPPUNIT_TEST(test_read_3);

    CPPUNIT_TEST(test_eval_1);
    CPPUNIT_TEST(test_eval_2);
    CPPUNIT_TEST(test_eval_3);

    CPPUNIT_TEST(test_print_1);
    CPPUNIT_TEST(test_print_2);
    CPPUNIT_TEST(test_print_3);

    CPPUNIT_TEST(test_solve_1);
    CPPUNIT_TEST(test_solve_2);
    CPPUNIT_TEST(test_solve_3);
*/
    CPPUNIT_TEST_SUITE_END();
};

// ----
// main
int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);  // turn off synchronization with C I/O
    cout << "TestSMP.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestSMP::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;
}