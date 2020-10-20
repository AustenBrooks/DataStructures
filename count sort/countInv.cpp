// Count inversions - homework
// Based off of mergesort
#include <vector>
#include <algorithm> // For copy

using namespace std;


int mergeInv(vector<int>& nums, vector<int>& left, vector<int>& right) {
// You will need this helper function that calculates the inversion while merging
// Your code here
	int i = 0;
	int j = 0;
	int k = 0;
	int count = 0;

	while (j < left.size() && k < right.size()) {
		//if the left value is less than the right value (right order)
		if (left.at(j) <= right.at(k)) {
			nums.at(i) = left.at(j);
			++i;
			++j;
		}
		//if the left value is greater than the right value (wrong order)
		else {
			nums.at(i) = right.at(k);
			++i;
			++k;
			count += left.size() - j;
		}
	}
	//if the right half was exhausted before the left
	while (j < left.size()) {
		nums.at(i) = left.at(j);
		++i;
		++j;
	}
	//if the left half was exhausted before the right
	while (k < right.size()) {
		nums.at(i) = right.at(k);
		++i;
		++k;
	}
	return count;
}

int countInv(vector<int>&nums) {
// Your code here
	int count = 0;
	if (nums.size() > 1) {
		vector<int> left;
		vector<int> right;
		int midpoint = nums.size() / 2;
		for (int i = 0; i < nums.size(); i++) {
			if (i < midpoint)
				left.push_back(nums.at(i));
			else
				right.push_back(nums.at(i));
		}
		count += countInv(left);
		count += countInv(right);
		count += mergeInv(nums, left, right);
	}
	return count;
}



