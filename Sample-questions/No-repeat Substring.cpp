/*Given a string, find the length of the longest substring which has no repeating characters.
Example 1:
Input: String = "aabccbb"
	Output : 3
	Explanation : The longest substring without any repeating characters is "abc".
	Example 2 :

	Input : String = "abbbb"
	Output : 2
	Explanation : The longest substring without any repeating characters is "ab".
	Example 3 :

	Input : String = "abccde"
	Output : 3
	Explanation : Longest substrings without any repeating characters are "abc" & "cde".
	Input : String = "abccde"
	Output : 3
	Explanation : Longest substrings without any repeating characters are "abc" & "cde".
	*/

using namespace std;

#include <iostream>
#include <string>
#include <map>

class NoRepeatSubstring {
public:
	static int findLength(const string& str) {
		int maxLength = 0;
		map<char, int>charFrequency;
		int windowStart = 0;
		for (int windowEnd = 0; windowEnd < str.size(); windowEnd++) {
			charFrequency[str[windowEnd]]++;
			while (charFrequency[str[windowEnd]] > 1) {
				charFrequency[str[windowStart]]--;
				windowStart++;
			}
			maxLength = maxLength > (windowEnd - windowStart + 1) ? maxLength : (windowEnd - windowStart + 1);
		
		}
		return maxLength;
	}
};
//----------------------------------------------------------------------------------------------//
int main6(int argc, char* argv[]) {
	cout << "\n\tLength of the longest substring: " << NoRepeatSubstring::findLength("aabccbb");
	cout << "\n\tLength of the longest substring: " << NoRepeatSubstring::findLength("abbbb");
	cout << "\n\tLength of the longest substring: " << NoRepeatSubstring::findLength("abccde");
	cout << "\n\n\t";
	system("pause");
	return 0;
}
