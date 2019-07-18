/*Given a string and a pattern, find the smallest substring in the
given string which has all the characters of the given pattern.
Example 1:
Input: String="aabdec", Pattern="abc"
Output: "abdec"

Example 2:
Input: String="abdabca", Pattern="abc"
Output: "abc"

Example 3:
Input: String="adcad", Pattern="abc"
Output: "" */
using namespace std;
#include <iostream>
#include <string>
#include <unordered_map>
class MinimumWindowSubstring {
public:
	static string findPermutation(const string &str, const string &pattern) {
		string response=str;
		string substr="";
		int windowStart = 0;
		int count = 0;
		int check = 0;
		unordered_map <char,int> charFreq;
		for (auto c : pattern) charFreq[c]++;
	
		for (int windowEnd = 0; windowEnd < str.size(); windowEnd++) {
			substr.push_back(str[windowEnd]);
			charFreq[str[windowEnd]]--;
			if (charFreq[str[windowEnd]] == 0) count++;
			while (count == pattern.size()) {
				check = 1;
				response = response.size() <= substr.size() ? response : substr;
				if (charFreq[str[windowStart]] == 0) count--;
				charFreq[str[windowStart]]++;
				windowStart++;
				substr.erase(substr.begin(), substr.begin() + 1);
			}
		}
		if (check ==1) return response;
		else return "";
	}
};

int main(int argc, char *argv[]) {
	cout <<"\n\tMinumum sub: "<<MinimumWindowSubstring::findPermutation("aabdec","abc");
	cout <<"\n\tMinumum sub: "<< MinimumWindowSubstring::findPermutation("abdabca","abc");
	cout <<"\n\tMinumum sub: "<< MinimumWindowSubstring::findPermutation("adcad","abc");

	cout <<"\n\n\t";
	system("pause");
	return 0;
}
