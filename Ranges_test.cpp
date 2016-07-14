//
//  MyRange.cpp
//
//  Created by ForceBru on 13.07.16.
//  Copyright © 2016 ForceBru. All rights reserved.
//

#include <iostream>
#include <typeinfo>
#include <vector>

#include "Ranges.hpp"

using namespace std;
using namespace Range;

template<typename T>
ostream& operator<<(ostream& out, const std::vector<T> data) {
    for(const T& a: data)
        out << a;
    
    return out;
}


int main () {
    cout << "1. Testing with smaller (unsigned) to greater (unsigned)..." << endl;
    {
        const vector<int> correct = {0,1,2,3,4,5,6,7,8};
        vector<int> ret;
        cout << '\t';
        for (const auto& i: 0_r, 9_r) {
            cout << i << ' ';
            ret.push_back(i);
        }
        cout << endl;
        
        if (ret != correct) {
            cout << "[1] ERROR" << endl;
            cout << "\tGot: " << ret << endl;
            cout << "\tCorrect: " << correct << endl;
        } else cout << "[1] OK" << endl;
    }
    
    cout << "\n2. Testing with smaller (signed) to greater (unsigned)..." << endl;
    {
        const vector<int> correct = {-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8};
        vector<int> ret;
        cout << '\t';
        for (const auto& i: -5_r, 9_r) {
            cout << i << ' ';
            ret.push_back(i);
        }
        cout << endl;
        
        if (ret != correct) {
            cout << "[2] ERROR" << endl;
            cout << "\tGot: " << ret << endl;
            cout << "\tCorrect: " << correct << endl;
        } else cout << "[2] OK" << endl;
    }
    
    cout << "\n3. Testing with equal values..." << endl;
    {
        const vector<int> correct = {};
        vector<int> ret;
        cout << '\t';
        for (const auto& i: 0_r, 0_r) {
            cout << i << ' ';
            ret.push_back(i);
        }
        cout << endl;
        
        if (ret != correct) {
            cout << "[3] ERROR" << endl;
            cout << "\tGot: " << ret << endl;
            cout << "\tCorrect: " << correct << endl;
        } else cout << "[3] OK" << endl;
    }
    
    cout << "\n4. Testing with greater(unsigned) to smaller(unsigned)..." << endl;
    {
        const vector<int> correct = {9,8,7,6,5,4,3,2,1};
        vector<int> ret;
        cout << '\t';
        for (const auto& i: 9_r, 0_r) {
            cout << i << ' ';
            ret.push_back(i);
        }
        cout << endl;
        
        if (ret != correct) {
            cout << "[4] ERROR" << endl;
            cout << "\tGot: " << ret << endl;
            cout << "\tCorrect: " << correct << endl;
        } else cout << "[4] OK" << endl;
    }
}
