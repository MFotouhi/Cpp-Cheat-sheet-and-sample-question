/*Given an array containing 0s and 1s, if you are allowed to replace no more than ‘k’ 0s with 1s, 
find the length of the longest subarray having all 1s.

Example 1:
Input: Array=[0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1], k=2
Output: 6
Explanation: Replace the '0' at index 5 and 8 to have the longest subarray of 1s having length 6.

Example 2:
Input: Array=[0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1], k=3
Output: 9
Explanation: Replace the '0' at index 6, 9, and 10 to have the longest subarray of 1s having length 9.*/
using namespace std;
#include <iostream>
#include <vector>
class ReplacingOnes {
public:
	static int findLength(const vector<int>& arr, int k) {
		int  maxLength = 0;
		int windowStart = 0;
		int count = 0;
		for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++) {
			if (arr[windowEnd] == 0) count++;
			while (count > k) {
				if (arr[windowStart] == 0) count--;
				windowStart++;
		     }
			maxLength = maxLength > windowEnd - windowStart + 1 ? maxLength : windowEnd - windowStart + 1;
		}
		return maxLength;
	}
};
//--------------------------------------------------------------------------------------------------//
int main8(int argc, char* argv[]) {

	cout << "\n\t"<< ReplacingOnes::findLength(vector<int>{0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1}, 2);
	cout << "\n\t"<< ReplacingOnes::findLength(vector<int>{0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1}, 3);
	
	cout << "\n\n\t";
	system("pause");
	return 0;
}
