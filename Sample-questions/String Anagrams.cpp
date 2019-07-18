/* Given a string and a pattern, find all anagrams of the pattern in the given string.
Anagram is actually a Permutation of a string. For example, “abc” has the following six anagrams:
abc   acb   bac   bca   cab   cba
Write a function to return a list of starting indices of the anagrams of the pattern in the given string.

Example 1:
Input: String="ppqp", Pattern="pq"
Output: [1, 2]

Example 2:
Input: String="abbcabc", Pattern="abc"
Output: [2, 3, 4] */
using namespace std;
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
class StringAnagrams {
public:
	static vector<int> findStringAnagrams(const string &str, const string &pattern) {
		vector<int> resultIndices;
		unordered_map <char, int > charFreq;
		for (auto c : pattern) charFreq[c]++;
		int count = 0; int windowStart = 0;

		for (int windowEnd = 0; windowEnd < str.size(); windowEnd++) {
			charFreq[str[windowEnd]]--;
			if (charFreq[str[windowEnd]] == 0)  count++;
			if (count == pattern.size()) resultIndices.push_back(windowStart);

			if (windowEnd >= pattern.size()-1) {
				if (charFreq[str[windowStart]] == 0) count--;
				charFreq[str[windowStart]]++;
				windowStart++;
			}
		}
		return resultIndices;
	}
};
//---------------------------------------------------------------------------//
int main(int argc, char *argv[]) {
	auto result = StringAnagrams::findStringAnagrams("ppqp", "pq");
	for (auto num : result) {
		cout << num << " ";
	}
	cout << endl;

	result = StringAnagrams::findStringAnagrams("abbcabc", "abc");
	for (auto num : result) {
		cout << num << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
