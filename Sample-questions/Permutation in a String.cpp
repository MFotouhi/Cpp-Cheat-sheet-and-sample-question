/* Given a string and a pattern, find out if the string contains any permutation of the pattern.
Permutation is defined as the re-arranging of the characters of the string. For example, “abc” has the following six permutations:
abc  acb  bac  bca  cab  cba  If a string has ‘n’ distinct characters it will have n!n! permutations.
Example 1:

Input: String="oidbcaf", Pattern="abc"
Output: true
Example 2:

Input: String="odicf", Pattern="dc"
Output: false
Example 3:

Input: String="bcdxabcdy", Pattern="bcdyabcdx"
Output: true
Example 4:

Input: String="aaacb", Pattern="abc"
Output: true*/
using namespace std;
#include <iostream>
#include <string>
#include <unordered_map>
class StringPermutation {
public:
	static bool findPermutation(const string &str, const string &pattern) {
		unordered_map<char, int> Patt;
		for (auto c : pattern)  Patt[c] ++;
		int windowStart=0;
		for (int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
			Patt[str[windowEnd]]--;
			if (Patt[str[windowEnd]]== 0) Patt.erase(str[windowEnd]);
			if (windowEnd >= pattern.size()) {
				Patt[str[windowStart]]++;
				if (Patt[str[windowStart]] == 0) Patt.erase(str[windowStart]);
				windowStart++;
			}
			if (Patt.size() == 0) return true;
		}
		return false;
	}
};
//-------------------------------------------------------------------------//
int main9(int argc, char *argv[]) {

	cout << "\n\tPermutation exist: " << StringPermutation::findPermutation("oidbcaf", "abc");
	cout << "\n\tPermutation exist: " << StringPermutation::findPermutation("odicf", "dc");
	cout << "\n\tPermutation exist: " << StringPermutation::findPermutation("bcdxabcdy", "bcdyabcdx");
	cout << "\n\tPermutation exist: " << StringPermutation::findPermutation("aaacb", "abc");
	cout << "\n\n\t";
	system("pause");
	return 0;
}

