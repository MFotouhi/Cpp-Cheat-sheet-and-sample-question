/*Given an array arr of unsorted numbers and a target sum,
count all triplets in it such that arr[i] + arr[j] + arr[k] < target where i, j, and k are three different indices.
Write a function to return the count of such triplets.
Input: [-1, 0, 2, 3], target=3
Output: 2
Explanation: There are two triplets whose sum is less than the target: [-1, 0, 3], [-1, 0, 2]
*/
using namespace std;
#include <algorithm>
#include <iostream>
#include <vector>
class TripletWithSmallerSum {
public:
	static int searchTriplets(vector<int> &arr, int target) {
		int count = -1;
		// TODO: Write your code here
		return count;
	}
};
//---------------------------------------------------------------------------------//
int main(int argc, char *argv[]) {
	vector<int> vec = { -1, 0, 2, 3 };
	cout << TripletWithSmallerSum::searchTriplets(vec, 3) << endl;
	vec = { -1, 4, 2, 1, 3 };
	cout << TripletWithSmallerSum::searchTriplets(vec, 5) << endl;

	system("pause");
	return 0;
}

