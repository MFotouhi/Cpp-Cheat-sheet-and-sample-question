/* Given a sorted array, create a new array containing squares of all the number of the input
array in the sorted order. */
using namespace std;
#include <iostream>
#include <vector>
class SortedArraySquares {
public:
	static vector<int> makeSquares(const vector<int>& arr) {
		int n = arr.size();
		vector<int> squares(n);
		int left = 0; int right = arr.size() - 1;
		int indice = arr.size() - 1;
		while (indice >=0) {
			if (abs(arr[right]) >= abs(arr[left])) {
				squares[indice] = arr[right]*arr[right];
				right--;
				indice--;
			}
			else {
				squares[indice] = arr[left] * arr[left];
				left++;
				indice--;
			}
		}
		return squares;
	}
};
//--------------------------------------------------------------------------//
int main15(int argc, char* argv[]) {
	vector<int> result = SortedArraySquares::makeSquares(vector<int>{-2, -1, 0, 2, 3});
	for (auto num : result) {
		cout << num << " ";
	}
	cout << endl;
	result = SortedArraySquares::makeSquares(vector<int>{-3, -1, 0, 1, 2});
	for (auto num : result) {
		cout << num << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}