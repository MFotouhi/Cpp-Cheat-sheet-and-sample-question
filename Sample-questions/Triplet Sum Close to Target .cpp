/*Given an array of unsorted numbers and a target number,
find a triplet in the array whose sum is as close to the 
target number as possible.*/
using namespace std;
#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
class TripletSumCloseToTarget {
public:
	static int searchTriplet(vector<int>& arr, int targetSum) {
		sort(arr.begin(), arr.end());
		int closest= INT_MAX;
		for (int i = 0; i <= arr.size()- 3; i++) {
			int left = i + 1;
			int right = arr.size() - 1;
			int sum = targetSum - arr[i];
			while (left < right) {
				int temp = arr[i] + arr[left] + arr[right];
				closest = abs(temp - targetSum) >= abs(closest - targetSum) ? closest : temp;
				if (arr[left] + arr[right] > sum) right--;
				else if (arr[left] + arr[right] < sum) left++;
				else return targetSum;
			}
		}
		return closest;
	}
};
//---------------------------------------------------------//
int main18(int argc, char* argv[]) {
	vector<int> vec = { -2, 0, 1, 2 };
	cout << TripletSumCloseToTarget::searchTriplet(vec, 2) << endl;
	vec = { -3, -1, 1, 2 };
	cout << TripletSumCloseToTarget::searchTriplet(vec, 1) << endl;
	vec = { 1, 0, 1, 1 };
	cout << TripletSumCloseToTarget::searchTriplet(vec, 100) << endl;
	system("pause");
	return 0;
}
