/*Given an array, find the average of all subarrays of size ‘K’ in it.*/
#include <iostream>
#include <vector>
using namespace std;
class FindTheAverageOfSubarray2 { //Sliding Window sum: O(N)
public:
	static vector<double> FindTheAverage(int K, vector<int>& arr) {
		vector<double> result;
		double sum = 0;
		int j = 0;
		for (int i = 0; i < arr.size(); i++) {
			sum += arr[i];//adding new elemans
			if (i >= K-1) {
				result.push_back(sum/K);
				sum -= arr[j];//removing from left
				j++;
			}
		}
		return result;
	}
};
class FindTheAverageOfSubarray {//Brute forth method O(N*K)
public:
	static vector<double> FindTheAverage(int K, vector<int>& arr) {
		vector<double> result;
		for (int i = 0; i <= arr.size() - K; i++) {
			//Summing K elements up
			double sum = 0;
			for (int j = i; j < i + K; j++)  sum += arr[j];
			result.push_back(sum / K); // Calculated 
		}
		return result;
	}
};
//--------------------------------------------------------------------------------------//
int main() {
	vector <int> arr = { 1, 3, 2, 6, -1, 4, 1, 8, 2 };
	int K = 5;
	vector <double> ans = FindTheAverageOfSubarray2::FindTheAverage(K, arr);
	cout << "\n\tThe Averages are: ";
	for (auto a : ans)
		cout << a << " ";
	cout << "\n\n\t";
	system("pause");
	return 0;
}