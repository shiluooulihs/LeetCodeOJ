#include <iostream>
using namespace std;
int main() {

	system("pause");
	return 0;
}

//int main() {
//	int N;
//	while (cin >> N) {
//		vector<pair<int, int>> pts(N, pair<int, int>(0, 0));
//		for (int i = 0; i < N; i++) {
//			cin >> pts[i].first >> pts[i].second;
//		}
//		//for (int i = 0; i < N; i++) {
//		//	cout << pts[i].first << " " << pts[i].second << endl;
//		//}
//		vector<pair<int, int>> res;
//		for (int i = 0; i < pts.size(); i++) {
//			bool check = true;
//			for (int j = 0; j < pts.size(); j++) {
//				if (i == j) continue;
//				if (pts[j].first > pts[i].first&&pts[j].second > pts[i].second) {
//					check = false;
//					break;
//				}
//			}
//			if (check) res.push_back(pts[i]);
//		}
//		sort(res.begin(), res.end());
//		for (int i = 0; i < res.size(); i++) {
//			cout << res[i].first << " " << res[i].second << endl;
//		}
//	}
//	system("pause");
//	return 0;
//}
//#include<iostream>
//#include <algorithm>
//#include <vector>
//#include <utility>
//#include <queue>
//using namespace std;
//class mycomparison
//{
//	bool reverse;
//public:
//	mycomparison(const bool& revparam = false)
//	{
//		reverse = revparam;
//	}
//	bool operator() (const pair<int, int>& a, const pair<int, int>& b)
//	{
//		return (a.first + a.second) > (b.first + b.second) ? true : false;
//	}
//};
//int main() {
//	int N;
//	while (cin >> N) {
//		vector<pair<int, int>> pts(N, pair<int, int>(0, 0));
//		for (int i = 0; i < N; i++) {
//			cin >> pts[i].first >> pts[i].second;
//		}
//		vector<bool> check(N, false);
//		priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> myHeap(pts.begin(), pts.end());
//		int size = 3;
//		while (size--) {
//			pair<int, int> cur = myHeap.top();
//			myHeap.pop();
//			for (int i = 0; i < pts.size(); i++)
//			{
//				if (pts[i].first < cur.first&&pts[i].second < cur.second) {
//					check[i] = true;
//				}
//			}
//		}
//		for (int i = 0; i < pts.size(); i++) {
//			if (check[i]) continue;
//			for (int j = 0; j < pts.size(); j++) {
//				if (i == j) continue;
//				if (pts[j].first < pts[i].first&&pts[j].second < pts[i].second) {
//					check[j] = true;
//				}
//			}
//		}
//		vector<pair<int, int>> res;
//		for (int i = 0; i < pts.size(); i++) {
//			if (!check[i]) res.push_back(pts[i]);
//		}
//		sort(res.begin(), res.end());
//		for (int i = 0; i < res.size(); i++) {
//			cout << res[i].first << " " << res[i].second << endl;
//		}
//	}
//	system("pause");
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main() {
//	int N;
//	while (cin >> N) {
//		vector<int> nums(N, 0);
//		for (int i = 0; i < N; i++) {
//			cin >> nums[i];
//		}
//		int accSum = 0;
//		vector<int> curSum(nums.size() + 1, 0);
//		for (int i = 0; i < nums.size(); i++) {
//			accSum += nums[i];
//			curSum[i + 1] = accSum;
//		}
//		int res = -1;
//		for (int i = 0; i < nums.size(); i++) {
//			int curMin = INT_MAX;
//			for (int j = i; j < nums.size(); j++) {
//				curMin = min(curMin, nums[j]);
//				res = max(res, curMin*(curSum[j + 1] - curSum[i]));
//			}
//		}
//		cout << res << endl;
//	}
//
//	system("pause");
//	return 0;
//}