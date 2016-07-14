//
//  MyRange.hpp
//
//  Created by ForceBru on 13.07.16.
//  Copyright © 2016 ForceBru. All rights reserved.
//

#ifndef Ranges_hpp
#define Ranges_hpp

namespace Ranges {
#include <type_traits>
    template<typename Integer>
    class __Range;
    
    class __Number {
        __Number(const long long& a) { this->nmb = a; }
        
        friend __Range<signed int> operator, (const __Number& a, const signed int& b);
        friend __Range<signed long> operator, (const __Number& a, const signed long& b);
        friend __Range<signed long long> operator, (const __Number& a, const signed long long& b);
        
        friend __Range<unsigned int> operator, (const __Number& a, const unsigned int& b);
        friend __Range<unsigned long> operator, (const __Number& a, const unsigned long& b);
        friend __Range<const unsigned long long> operator, (const __Number& a, const unsigned long long& b);
        
        template<typename Int>
        friend __Range<signed int> operator, (const __Range<Int>& a, const signed int& b);
        template<typename Int>
        friend __Range<signed long> operator, (const __Range<Int>& a, const signed long& b);
        template<typename Int>
        friend __Range<signed long long> operator, (const __Range<Int>& a, const signed long long& b);
        
        template<typename Int>
        friend __Range<unsigned int> operator, (const __Range<Int>& a, const unsigned int& b);
        template<typename Int>
        friend __Range<unsigned long> operator, (const __Range<Int>& a, const unsigned long& b);
        template<typename Int>
        friend __Range<const unsigned long long> operator, (const __Range<Int>& a, const unsigned long long& b);
        
        friend __Number operator "" _r(unsigned long long k);
        
        friend class __Iter;
        
        long long nmb;
        
    public:
        
        template <typename Integer, typename = std::enable_if<std::is_integral<Integer>::value>>
        operator Integer() const {
            return Integer(nmb);
        }
        
        __Number operator- () { return __Number(-nmb); }
        const __Number operator- () const { return __Number(-nmb); }
    };
    
    class __Iter {
        __Iter(const long long& a): data(__Number(a)) {}
        
        void fwd(const bool f) { this->forward = f; }
        void stp(const long long& s) { this->step = s; }
        
        __Number data;
        bool forward;
        long long step;

        template<typename Integer>
        friend class __Range;
        
    public:
        
        inline __Number& operator* () { return this->data; }
        inline bool operator!= (const __Iter rhs) {
            if (forward) return this->data.nmb < rhs.data.nmb;
            else return this->data.nmb > rhs.data.nmb;
        }
        
        inline const __Number& operator* () const { return this->data; }
        inline const bool operator!= (const __Iter rhs) const {
            if (forward) return this->data.nmb < rhs.data.nmb;
            else return this->data.nmb > rhs.data.nmb;
        }
        
        inline __Iter operator++ () {
            if (forward) this->data.nmb += step;
            else         this->data.nmb -= step;
            return *this;
        }
    };
    
    template<typename Integer>
    class __Range {
        __Range(const long long& a, const long long& b, const long long& step = 1): st(a), en(b) {
            bool forward = 1;
            if (a > b) forward = 0;
            this->st.fwd(forward), this->en.fwd(forward);
            this->st.stp(step), this->en.stp(step);
        }
        
        friend __Range operator, (const __Number& a, const Integer& b) { return __Range(a.nmb, b); }
        
        template<typename Int>
        friend __Range operator, (const __Range<Int>& a, const Integer& stp) { return __Range(*(a.st), *(a.en), stp); }
        
        __Iter st, en;
        
    public:
        inline __Iter begin() { return this->st;}
        inline __Iter end() { return this->en; }
        
        inline const __Iter begin() const { return this->st; }
        inline const __Iter end() const { return this->en; }
    };
    
    __Number operator "" _r(const unsigned long long k) {
        return __Number(k);
    }

    template<typename integer>
    using Range = __Range<integer>;
}


#endif /* Ranges_hpp */
