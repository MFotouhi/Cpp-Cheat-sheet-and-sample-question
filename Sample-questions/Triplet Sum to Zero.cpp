/* Given an array of unsorted numbers, find all unique triplets in it that add up to zero*/
using namespace std;
#include <algorithm>
#include <iostream>
#include <vector>
class TripletSumToZero {
public:
	static vector<vector<int>> searchTriplets(vector<int> &arr) {
		vector<vector<int>> triplets;
		sort(arr.begin(), arr.end());  // NlogN
		for (int i = 0; i < arr.size() - 2; i++) {
			int left = i+1;
			int right = arr.size() - 1;
			int sum = 0 - arr[i];
			while (left < right) {
				if (arr[left] + arr[right] > sum) right--;
				if (arr[left] + arr[right] < sum) left++;
				if (arr[left] + arr[right] == sum) {
					triplets.push_back({ arr[i],arr[left],arr[right] });
					right--;
				}	
			}
		}
		return triplets;
	}
};
//------------------------------------------------------------------------------------//
int main17(int argc, char *argv[]) {

	vector<int> vec = { -3, 0, 1, 2, -1, 1, -2 };
	auto result = TripletSumToZero::searchTriplets(vec);
	for (auto vec : result) {
		cout << "[";
		for (auto num : vec) {
			cout << num << " ";
		}
		cout << "]";
	}
	cout << endl;

	vec = { -5, 2, -1, -2, 3 };
	result = TripletSumToZero::searchTriplets(vec);
	for (auto vec : result) {
		cout << "[";
		for (auto num : vec) {
			cout << num << " ";
		}
		cout << "]";
	}

	system("pause");
	return 0;
}
