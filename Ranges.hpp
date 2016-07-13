//
//  MyRange.hpp
//  Inform
//
//  Created by Mia on 13.07.16.
//  Copyright © 2016 ForceBru. All rights reserved.
//

#ifndef MyRange_h
#define MyRange_h

namespace Range {
    class __Range;
    
    class __Number {
        __Number(const long long& a) { this->nmb = a; }
        
        friend __Range operator, (const __Number& a, const __Number& b);
        friend __Number operator "" _r(unsigned long long k);
        
        long long nmb;
        
    public:
        __Number operator- () { return __Number(-nmb); }
        const __Number operator- () const { return __Number(-nmb); }
    };
    
    class __Iter {
        __Iter(const long long& a) { this->data = a; }
        
        void fwd(const bool f) { this->forward = f; }
        
        long long data;
        bool forward;
        
        friend class __Range;
        
    public:
        inline long long& operator* () { return this->data; }
        inline bool operator!= (const __Iter rhs) { return this->data != rhs.data; }
        
        inline const long long& operator* () const { return this->data; }
        inline const bool operator!= (const __Iter rhs) const { return this->data != rhs.data; }
        
        inline __Iter operator++ () {
            if (forward) ++this->data;
            else         --this->data;
            return *this;
        }
    };
    
    class __Range {
        __Range(const long long& a, const long long& b): forward(1), st(a), en(b) {
            if (a > b) forward = 0;
            this->st.fwd(forward), this->en.fwd(forward);
        }
        
        friend __Range operator, (const __Number& a, const __Number& b) {
            return __Range(a.nmb, b.nmb);
        }
        
        __Iter st, en;
        bool forward;
        
    public:
        inline __Iter begin() { return this->st;}
        inline __Iter end() { return this->en; }
        
        inline const __Iter begin() const { return this->st; }
        inline const __Iter end() const { return this->en; }
    };
    
    __Number operator "" _r(unsigned long long k) {
        return __Number(k);
    }
    
}

#endif /* MyRange_h */
