/*Given an array of sorted numbers, remove all duplicates from it. You should not use
any extra space; after removing the duplicates in-place return the new length of the array.*/
using namespace std;
#include <iostream>
#include <vector>
class RemoveDuplicates {
public:
	static int remove(vector<int>& arr) {
		int left = 0;
		while (left+1<arr.size()) {
			if (arr[left] == arr[left + 1]) arr.erase(arr.begin() + left + 1, arr.begin() +left+ 2);
			else left++;
		}
		return arr.size();
	}
};
//----------------------------------------------------------------------------------------//
int main14(int argc, char* argv[]) {
	vector<int> arr = { 2, 3, 3, 3, 6, 9, 9 };
	cout << "\n\tArray new length: " << RemoveDuplicates::remove(arr);

	arr = vector<int>{ 2, 2, 2, 11 };
	cout << "\n\tArray new length: " << RemoveDuplicates::remove(arr);

	cout << "\n\n\t";
	system("pause");
	return 0;
}