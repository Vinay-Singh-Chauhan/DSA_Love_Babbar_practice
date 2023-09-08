#include <bits/stdc++.h>
using namespace std;

string subsequence(string s, int binary, int len)
{
	string sub = "";
	for (int j = 0; j < len; j++)

		// check if jth bit in binary is 1
		if (binary & (1 << j))

			// if jth bit is 1, include it
			// in subsequence
			sub += s[j];

	return sub;
}

void possibleSubsequences(string s){

	// map to store subsequence
	// lexicographically by length
	map<int, set<string> > sorted_subsequence;

	int len = s.size();
	
	// Total number of non-empty subsequence
	// in string is 2^len-1
	int limit = pow(2, len);
	
	// i=0, corresponds to empty subsequence
	for (int i = 1; i <= limit - 1; i++) {
		
		// subsequence for binary pattern i
		string sub = subsequence(s, i, len);
		
		// storing sub in map
		sorted_subsequence[sub.length()].insert(sub);
	}

	for (auto it : sorted_subsequence) {
		
		// it.first is length of Subsequence
		// it.second is set<string>
		cout << "Subsequences of length = "
			<< it.first << " are:" << endl;
			
		for (auto ii : it.second)
			
			// ii is iterator of type set<string>
			cout << ii << " ";
		
		cout << endl;
	}
}

// abc is string
// 101== ac
// 001== c

// driver function
int main()
{
	string s = "aabc";
	possibleSubsequences(s);
	return 0;
}
