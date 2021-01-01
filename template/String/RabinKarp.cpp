#include <bits/stdc++.h>
using namespace std;

// input data
string s, t; 

// consider all degrees p
const int p = 31;

void match() {
    vector <long long> p_pow (max (s.length (), t.length ()));
    p_pow [0] = 1;
    for (size_t i = 1; i <p_pow.size (); ++ i)
        p_pow [i] = p_pow [i-1] * p;

    // count hashes from all prefixes of string T
    vector <long long> h (t.length ());
    for (size_t i = 0; i <t.length (); ++ i)
    {
        h [i] = (t [i] - 'a' + 1) * p_pow [i];
        if (i) h [i] += h [i-1];
    }

    // count the hash from the string S
    long long h_s = 0;
    for (size_t i = 0; i <s.length (); ++ i)
        h_s += (s [i] - 'a' + 1) * p_pow [i];

    // iterate over all the substrings T of length | S | and compare them
    for (size_t i = 0; i + s.length () - 1 <t.length (); ++ i)
    {
        long long cur_h = h [i + s.length () - 1];
        if (i) cur_h - = h [i-1];
        // reduce hashes to one degree and compare
        if (cur_h == h_s * p_pow [i])
            cout << i << '';
    }
}


