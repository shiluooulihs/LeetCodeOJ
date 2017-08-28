#pragma once
#include<vector>
#include <iostream>
using namespace std;
class Solution {
	void dfs(vector<int>& nums, int beg, vector<int>& index, int& sum, int& target, bool& check, vector<int>& indexFinal) {
		if (check||sum > target) return;
		if (sum == target) {
			indexFinal = index;
			check = true;
			return;
		}
		for (int i = beg; i < nums.size(); i++) {
			index.push_back(i);
			sum += nums[i];
			dfs(nums, i + 1, index, sum, target, check, indexFinal);
			sum -= nums[i];
			index.pop_back();
		}
	}
public:
	bool makesquare(vector<int>& nums) {
		int sum = 0;
		for (auto elem : nums) sum += elem;
		if (nums.size() < 4 || sum % 4 != 0) return false;
		vector<int> index;
		vector<int> indexFinal;
		bool check = false;
		int target = sum / 2;
		sum = 0;
		dfs(nums, 0, index, sum, target, check, indexFinal);
		if (!check) return false;
		vector<int> cur;
		for (int i = 0; i < indexFinal.size(); i++) {
			cur.push_back(nums[indexFinal[i]]);
		}

		dfs(cur, 0, index, sum, target, check, indexFinal);
	}
};