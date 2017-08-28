#pragma once
#include<vector>
#include<unordered_map>
using namespace std;
//class Solution {
//public:
//	int numberOfArithmeticSlices(vector<int>& A) {
//		if (A.size() < 3) return 0;
//		int res = 0;
//		vector<unordered_multimap<long long, int>> mp(A.size());
//		for (int i = 1; i < A.size(); i++) {
//			for (int j = 0; j < i; j++) {
//				long long tmp = (long long)A[i] - A[j];
//				if (mp[j].find(tmp) == mp[j].end()) {
//					mp[i].insert(make_pair(tmp, 0));
//				}
//				else {
//					int cur = 0;
//					auto p = mp[j].equal_range(tmp);
//					for (auto i = p.first; i != p.second; i++) {
//						cur += i->second + 1;
//					}
//					mp[i].insert(make_pair(tmp, cur));
//					res += cur;
//				}
//			}
//		}
//		return res;
//	}
//};
class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		if (A.size() < 3) return 0;
		int res = 0;
		vector<unordered_map<int, int>> mp(A.size());
		for (int i = 1; i < A.size(); i++) {
			for (int j = 0; j < i; j++) {
				long long diff = (long long)A[i] - A[j];
				if (diff > INT_MAX || diff < INT_MIN) continue;
				int d = (int)diff;
				if (mp[j].find(d) == mp[j].end()) {
					mp[i][d] = 1;
				}
				else {
					mp[i][d] += mp[j][d] + 1;
					res += mp[j][d];
				}
			}
		}
		return res;
	}
};