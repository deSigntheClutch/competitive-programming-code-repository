#include <bits/stdc++.h>
using namespace std;
// Z-function (“Z-function”) from this string is an array of length n, 
// the ith element of which is equal to the largest number of characters, 
// starting from the position imatching the first characters of the string s.
vector<int> z_function (string s) {
	int n = (int) s.length();
	vector<int> z (n);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	return z;
}