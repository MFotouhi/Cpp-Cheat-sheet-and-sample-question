/* Given a string with lowercase letters only, if you are allowed to replace no more than ‘k’ letters with any letter,
find the length of the longest substring having the same letters after replacement.
Example 1:

Input: String="aabccbb", k=2
Output: 5

Example 2:
Input: String="abbcb", k=1
Output: 4

Example 3:
Input: String="abccde", k=1
Output: 3     */
using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class CharacterReplacement {
public:
	static int findLength(const string& str, int K) {
		int maxLength = 0;
		unordered_map<char, int> charFrequency;
		int windowStart = 0; 
		int maxRepeatedChar = 0;
		for (int windowEnd = 0; windowEnd < str.size(); windowEnd++) {
			charFrequency[str[windowEnd]]++;
			maxRepeatedChar = maxRepeatedChar > charFrequency[str[windowEnd]] ? maxRepeatedChar : charFrequency[str[windowEnd]];

			if(windowEnd - windowStart + 1 - maxRepeatedChar > K) {
				charFrequency[str[windowStart]]--;
				windowStart++;
			}
			maxLength= maxLength > (windowEnd-windowStart+1)? maxLength: (windowEnd - windowStart + 1);		
		}
		return maxLength;
	}
};

int main7(int argc, char* argv[]) {
	cout <<"\n\t{\"aabccbb\" ,2}:" <<CharacterReplacement::findLength("aabccbb", 2);
	cout <<"\n\t{\"abbcb\"   ,1}:" << CharacterReplacement::findLength("abbcb", 1);
	cout <<"\n\t{\"abccde\"  ,1}:" << CharacterReplacement::findLength("abccde", 1);
	cout << "\n\n\t";
	system("pause");
	return 0;
	}