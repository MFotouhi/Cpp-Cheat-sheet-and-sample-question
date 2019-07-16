/*Given an array of positive numbers and a positive number ‘k’,
find the maximum sum of any contiguous subarray of size ‘k’.

Example 1:
Input: [2, 1, 5, 1, 3, 2], k=3
Output: 9

Example 2:
Input: [2, 3, 4, 1, 5], k=2
Output: 7*/

#include <iostream>
#include <vector>
using namespace std;
class MaxSumOfSubarray { 
public:
	static int FindMax(int K, vector<int>& arr) {
		int sum = 0;
		int max = 0;
		int j = 0;
		for (int i = 0; i < arr.size(); i++) {
			sum += arr[i]; 
			if (i >= K - 1) { 	//Check if we have hit the K
				if (sum > max) max = sum;
				sum -= arr[j]; //subtracting from left
				j++;//sliding window to the right
			}
		}
		return max;
	}
};
//-------------------------------------------------------------------//
int main2() {

	cout << "\n\tMax for first example : " << 
		MaxSumOfSubarray::FindMax(3, vector<int> {3, 1, 5, 1, 3, 2});

	cout << "\n\tMax for second example : " <<
		MaxSumOfSubarray::FindMax(2, vector<int> {2, 3, 4, 1, 5});
	
	cout << "\n\t";
	system("pause");
	return 0;
}
