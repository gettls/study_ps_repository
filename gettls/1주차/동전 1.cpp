#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
using namespace std;
#pragma warning (disable:4996)

int n, k;
vector<int> unit;
vector<int> dp;
int main() {

	cin >> n >> k;
	dp.resize(k + 1, 0);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		unit.push_back(x);
	}
	dp[0] = 1;
	sort(unit.begin(), unit.end());
	for (int i = 0; i < unit.size(); i++) {
		int coin = unit[i];
		for (int j = coin; j <= k; j++) {
			dp[j] += dp[j - coin];
		}
	}
	cout << dp[k];
}