/*
Given an array of positive numbers and a positive number ‘S’,
find the length of the smallest subarray whose sum is greater than or equal to ‘S’.
Return 0, if no such subarray exists.

Example 1:
Input: [2, 1, 5, 2, 3, 2], S=7
Output: 2

Example 2:
Input: [2, 1, 5, 2, 8], S=7
Output: 1

Example 3:
Input: [3, 4, 1, 1, 6], S=8
Output: 3
*/
#include<iostream>
#include<vector>
using namespace std;
class MinSizeSubarr {
public:
	static int FindMinSubb(int K, vector<int>&arr) {
		int WindowSum = 0;
		int j = 0;
		int SmallestSize = INT_MAX;

		for (int i = 0; i < arr.size(); i++) {
			WindowSum += arr[i];
			while (WindowSum >= K) {
				if (SmallestSize > i - j + 1) SmallestSize = i - j + 1;
				WindowSum -= arr[j];
				j++;
			}
		}
		return SmallestSize == INT_MAX ? 0 : SmallestSize;
	}
};
//----------------------------------------------------------------------//
int main3() {
	int result = MinSizeSubarr::FindMinSubb(7, vector<int>{2, 1, 5, 2, 3, 2});
	cout << "\n\tSmallest subarray length: " << result;
	result = MinSizeSubarr::FindMinSubb(7, vector<int>{2, 1, 5, 2, 8});
	cout << "\n\tSmallest subarray length: " << result;
	result = MinSizeSubarr::FindMinSubb(8, vector<int>{3, 4, 1, 1, 6});
	cout << "\n\tSmallest subarray length: " << result;

	cout << "\n\t";
	system("pause");
	return 0;
}