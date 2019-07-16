/* Given a string and a pattern, find out if the string contains any permutation of the pattern.
Permutation is defined as the re-arranging of the characters of the string. For example, �abc� has the following six permutations:
abc
acb
bac
bca
cab
cba
If a string has �n� distinct characters it will have n!n! permutations.

Example 1:

Input: String="oidbcaf", Pattern="abc"
Output: true
Explanation: The string contains "bca" which is a permutation of the given pattern.
Example 2:

Input: String="odicf", Pattern="dc"
Output: false
Explanation: No permutation of the pattern is present in the given string as a substring.
Example 3:

Input: String="bcdxabcdy", Pattern="bcdyabcdx"
Output: true
Explanation: Both the string and the pattern are a permutation of each other.
Example 4:

Input: String="aaacb", Pattern="abc"
Output: true
Explanation: The string contains "acb" which is a permutation of the given pattern.
Input: String="aaacb", Pattern="abc"
Output: true
Explanation: The string contains "acb" which is a permutation of the given pattern.

*/



using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class StringPermutation {
public:
	static bool findPermutation(const string &str, const string &pattern) {
		// TODO: Write your code here
		return false;
	}
};

int main(int argc, char *argv[]) {
	cout << "Permutation exist: " << StringPermutation::findPermutation("oidbcaf", "abc") << endl;
	cout << "Permutation exist: " << StringPermutation::findPermutation("odicf", "dc") << endl;
	cout << "Permutation exist: " << StringPermutation::findPermutation("bcdxabcdy", "bcdyabcdx") << endl;
	cout << "Permutation exist: " << StringPermutation::findPermutation("aaacb", "abc") << endl;
}
