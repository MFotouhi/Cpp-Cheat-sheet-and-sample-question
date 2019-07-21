/* Given a string and a list of words, find all the starting indices of substrings in the 
given string that are a concatenation of all the given words exactly once without any
overlapping of words. You can assume that all words are of the same length.
Example 1:
Input: String="catfoxcat", Words=["cat", "fox"]
Output: [0, 3]

Example 2:
Input: String="catcatfoxfox", Words=["cat", "fox"]
Output: [3] */
using namespace std;
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
class WordConcatenation {
public:
	static vector<int> findWordConcatenation(const string &str, const vector<string> &words) {
		vector<int> resultIndices;
	//to be soled
			return resultIndices;
	}
};
//------------------------------------------------------------------------------------//
int main12(int argc, char *argv[]) {
	vector<int> result =
		WordConcatenation::findWordConcatenation("catfoxcat", vector<string>{"cat", "fox"});
	for (auto num : result) {
		cout << num << " ";
	}
	cout << endl;
	result = WordConcatenation::findWordConcatenation("catcatfoxfox", vector<string>{"cat", "fox"});
	for (auto num : result) {
		cout << num << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
