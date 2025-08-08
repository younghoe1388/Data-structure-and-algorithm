#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 二分查找，每轮缩小一半查找范围，时间复杂度为log2(n)
int binarySearch(int arr[], int size, int target) {
	int left = 0;
	int right = size - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;  // 防溢出
		if (arr[mid] < target) {
			left = mid + 1;
		}
		else if (arr[mid] > target) {
			right = mid - 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}

// 二分查找插入点（找到插入点）
int binarySearchInsertion(int arr[], int size, int target) {
	int left = 0;
	int right = size - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;  // 防溢出写法
		if (arr[mid] < target) {
			left = mid + 1;  // 目标在右半部分
		}
		else {
			right = mid - 1; // 目标在左半部分（包括 arr[mid] == target 的情况）
		}
	}
	return left;  // left 指向第一个 >= target 的位置
}

// 二分查找最左侧的target
int findLeftEdge(int arr[], int size, int target) {
	int result = binarySearchInsertion(arr, size, target);

	// 若result == size，代表target比数组内所有的数字都要大
	if (result == size || arr[result] != target) {
		return -1;
	}
	return result;
}

// 二分查找最右侧的target
int findRightEdge(int arr[], int size, int target) {
	// 要找最右边的target，则找比target大一的数的插入点
	int res = binarySearchInsertion(arr, size, target + 1);
	int result = res - 1;

	// 若result < 0，代表target比数组内所有的数字都要小
	if (result < 0 || arr[result] != target) {
		return -1;
	}
	return result;
}

// 跳跃搜索
int jumpSearch(const vector<int>& arr, int target) {
	int n = arr.size();
	int step = sqrt(n);
	int prev = 0;

	while (arr[min(step, n) - 1] < target) {
		prev = step;
		step += sqrt(n);
		if (prev >= n) {
			return -1;
		}
	}

	while (arr[prev] < target) {
		prev++;
		// 如果到达下一个块或数组末尾仍未找到
		if (prev == min(step, n)) {
			return -1;
		}
	}

	// 检查是否找到目标值
	if (arr[prev] == target) {
		return prev;
	}

	return -1;
}

int main() {
	system("chcp 65001");
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Binary Search: " << binarySearch(arr, size, 5) << endl;
    cout << "Binary Search Insertion: " << binarySearchInsertion(arr, size, 5) << endl;

	system("pause");
	return 0;
}