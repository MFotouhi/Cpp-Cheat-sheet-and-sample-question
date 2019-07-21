/*Given an array of sorted numbers and a target sum, find a pair in the array whose sum is equal to the
given target.
Write a function to return the indices of the two numbers (i.e. the pair) such that
they add up to the given target.

Example 1:
Input: [1, 2, 3, 4, 6], target=6
Output: [1, 3]
Explanation: The numbers at index 1 and 3 add up to 6: 2+4=6
Example 2:
Input: [2, 5, 9, 11], target=11
Output: [0, 2]
Explanation: The numbers at index 0 and 2 add up to 11: 2+9=11 */
using namespace std;
#include <iostream>
#include <vector>
class PairWithTargetSum {
public:
	static pair<int, int> search(const vector<int>& arr, int targetSum) {
		int left = 0; int right = arr.size() - 1;
		
		while (left < right) {
			if (arr[left] + arr[right] > targetSum) right--;
			if (arr[left] + arr[right] < targetSum) left++;
			if (arr[left] + arr[right] == targetSum) return make_pair(left, right);
		}
		 return make_pair(-1, -1);
	}
};
//--------------------------------------------------------------------------//
int main13(int argc, char* argv[]) {
	auto result = PairWithTargetSum::search(vector<int>{1, 2, 3, 4, 6}, 6);
	cout << "\n\tPair with target sum: [" << result.first << ", " << result.second << "]" ;
	result = PairWithTargetSum::search(vector<int>{2, 5, 9, 11}, 11);
	cout << "\n\tPair with target sum: [" << result.first << ", " << result.second << "]" ;
	cout << "\n\n\t";
	system("pause");
	return 0;
}