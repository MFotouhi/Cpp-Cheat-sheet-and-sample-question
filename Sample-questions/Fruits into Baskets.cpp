/* Given an array of characters where each character represents a fruit tree, you are given two baskets and your goal is to put maximum number of
fruits in each basket. The only restriction is that each basket can have only one type of fruit.
You can start with any tree, but once you have started you can’t skip a tree.
You will pick one fruit from each tree until you cannot, i.e., you will stop when you have to pick from a third fruit type.
Write a function to return the maximum number of fruits in both the baskets.

Example 1:
Input: Fruit=['A', 'B', 'C', 'A', 'C']
Output: 3

Example 2:
Input: Fruit=['A', 'B', 'C', 'B', 'B', 'C']
Output: 5     */
using namespace std;
#include <iostream>
#include <map>
#include <vector>

class MaxFruitCountOf2Types {
public:
	static int findLength(const vector<char>& arr) {
		int maxLength = 0;
		int windowStart = 0;
		map<char, int> fruitNumb;
		for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++) {
			fruitNumb[arr[windowEnd]]++;
			while (fruitNumb.size() > 2) {
				fruitNumb[arr[windowStart]]--;
				if (fruitNumb[arr[windowStart]] == 0)fruitNumb.erase(arr[windowStart]);
				windowStart++;
			}
			maxLength = maxLength > (windowEnd + 1 - windowStart) ? maxLength : (windowEnd + 1 - windowStart);
		}
		return maxLength;
	}
};
//---------------------------------------------------------------------------------------------------------//
int main5(int argc, char* argv[]) {
	cout << "\n\tMaximum number of fruits: "
		<< MaxFruitCountOf2Types::findLength(vector<char>{'A', 'B', 'C', 'A', 'C'});
	cout << "\n\tMaximum number of fruits: "
		<< MaxFruitCountOf2Types::findLength(vector<char>{'A', 'B', 'C', 'B', 'B', 'C'});
	cout << "\n\n\t";
	system("pause");
	return 0;
}
