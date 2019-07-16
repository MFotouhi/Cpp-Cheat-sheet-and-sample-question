/*Given a string, find the length of the longest substring in it with no more than K
distinct characters.

Example 1:
Input: String="araaci", K=2
Output: 4

Example 2:
Input: String="araaci", K=1
Output: 2

Example 3:
Input: String="cbbebi", K=3
Output: 5*/
#include<iostream>
#include<string>
#include<map>
using namespace std;
class  LongestSub{
public:
	static int findLength(string ST, int K) {
		map<char, int> charFrequency;
		int windowStart = 0;
		int maxChar = 0;
		for (int windowEnd = 0; windowEnd < ST.size(); windowEnd++) {
			charFrequency[ST[windowEnd]]++;
			while (charFrequency.size() > K) {
				charFrequency[ST[windowStart]]--;
				if (charFrequency[ST[windowStart]] == 0) charFrequency.erase(ST[windowStart]);
				windowStart++;
				maxChar = maxChar > (windowEnd + 1 - windowStart) ? maxChar : (windowEnd + 1 - windowStart);
			}
		}
		return maxChar;
	}
};
//---------------------------------------------------------------//
int main4() {
	
	cout << "\n\tLength of the longest substring: " << 
		LongestSub::findLength("araaci", 2);
	cout << "\n\tLength of the longest substring: " <<
		LongestSub::findLength("araaci", 1);
	cout << "\n\tLength of the longest substring: " <<
		LongestSub::findLength("cbbebi", 3);

	cout << "\n\n\t";
	system("pause");
	return 0;
}
