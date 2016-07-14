//
//  Ranges_test.cpp
//
//  Created by ForceBru on 13.07.16.
//  Copyright © 2016 ForceBru. All rights reserved.
//

#include <iostream>
#include <typeinfo>
#include <vector>
#include <chrono>
#include <cassert>

#include "Ranges.hpp"

using namespace std;
using namespace Ranges;

template<typename T>
ostream& operator<<(ostream& out, const std::vector<T> data) {
    for(const T& a: data)
        out << a << ' ';
    
    return out;
}

#define TEST_IT { \
    if (ret != correct) { \
        cout << "[" << tests << "] ERROR" << endl; \
        cout << "\tGot: " << ret << endl; \
        cout << "\tCorrect: " << correct << endl; \
        ++fail;\
    } else cout << "[" << tests << "] OK" << endl, ++success; \
}

#define SETUP(type) vector<type> ret; cout << '\t';

int main () {
    unsigned tests = 0, success = 0, fail = 0;
    
    
    cout << ++tests << ". Testing with smaller (unsigned) to greater (unsigned)..." << endl;
    {
        const vector<int> correct = {0,1,2,3,4,5,6,7,8};
        SETUP(int);
        for (const int& i: 0_r, 9) {
            cout << i << ' ';
            ret.push_back(i);
        }
        cout << endl;
        
        TEST_IT;
    }
    
    cout << "\n" << ++tests << ". Testing with smaller (signed) to greater (unsigned)..." << endl;
    {
        const vector<long> correct = {-9,-8,-7,-6,-5,-4,-3,-2,-1};
        SETUP(long);
        for (const long& i: -9_r, 0) {
            cout << i << ' ';
            ret.push_back(i);
        }
        cout << endl;
        
        TEST_IT;
    }
    
    cout << "\n" << ++tests << ". Testing with equal values..." << endl;
    {
        const vector<unsigned> correct = {};
        SETUP(unsigned);
        for (const unsigned& i: 0_r, 0) {
            cout << i << ' ';
            ret.push_back(i);
        }
        cout << endl;
        
        TEST_IT;
    }
    
    cout << "\n" << ++tests << ". Testing with greater(unsigned) to smaller(unsigned)..." << endl;
    {
        const vector<int> correct = {9,8,7,6,5,4,3,2,1};
        SETUP(int);
        for (const int& i: 9_r, 0) {
            cout << i << ' ';
            ret.push_back(i);
        }
        cout << endl;
        
        TEST_IT;
    }
    
    cout << "\n" << ++tests << ". Testing with variables instead of literals..." << endl;
    {
        auto a = 9_r;
        int b = 0;
        const vector<int> correct = {9,8,7,6,5,4,3,2,1};
        SETUP(int);
        for (const int& i: a, b) {
            cout << i << ' ';
            ret.push_back(i);
        }
        cout << endl;
        
        TEST_IT;
    }
    
    cout << "\n" << ++tests << ". Testing with steps (backward)..." << endl;
    {
        const vector<int> correct = {9,7,5,3,1};
        SETUP(int);
        for (const int& i: 9_r, 0, 2) {
            cout << i << ' ';
            ret.push_back(i);
        }
        cout << endl;
        
        TEST_IT;
    }
    
    cout << "\n" << ++tests << ". Testing with steps (forward)..." << endl;
    {
        const vector<int> correct = {0,2,4,6,8};
        SETUP(int);
        for (const int& i: 0_r, 9, 2) {
            cout << i << ' ';
            ret.push_back(i);
        }
        cout << endl;
        
        TEST_IT;
    }
    
    cout << "\n\n\tTotal tests: " << tests << endl;
    cout << "\tSucceeded: " << success;
    if  (fail) cout << endl << "\tFailed: " << fail << endl;
    else cout << " (100%)" << endl;
    
    cout << endl << string(40, '-') << endl;
    
    
    cout << "Performance test" << endl;
    
    auto started = chrono::high_resolution_clock::now();
    
    Range<int> myRange = (-100000_r, 100000, 3);
    
    for (volatile int i: myRange) {
        cout << i << ' ';
    }
    
    cout << endl << endl << "Looping lasted for " << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - started).count() << " milliseconds" << endl;
    
    cout << "Considering that the above test was simply measuring the speed of std::cout, looping over a range is lightning-fast" << endl;
}