# include <iostream>
# include <vector>
using namespace std;

int dfs(vector<int>& nums, int target, int left, int right) {
	if (left > right) {
		return -1;
	}

	int mid = left + (right - left) / 2;
	if (nums[mid] < target) {
		return dfs(nums, target, mid + 1, right);
	}
	else if (nums[mid] > target) {
		return dfs(nums, target, left, mid - 1);
	}
	else {
		return mid;
	}
}

int binarySearch(vector<int>& nums, int target) {
	int n = nums.size();
	return dfs(nums, target, 0, n - 1);
}


int main() {
	system("chcp 65001");
	vector<int> nums = { 1, 3, 5, 7, 9, 11, 13, 15 };
	int target = 7;

	int result = binarySearch(nums, target);
	cout << result << endl;

	system("pause");
	return 0;
}