#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <cstring>
using namespace std;
#pragma warning (disable:4996)

long long dp[31][31];

long long go(int w, int h) {
	if (w == 0) return 1;

	if (dp[w][h] != -1) return dp[w][h];

	dp[w][h] = 0;
	if (w > 0) dp[w][h] += go(w - 1, h + 1);
	if (h > 0) dp[w][h] += go(w, h - 1);

	return dp[w][h];
}

int main() {
	int t = 1000;
	while (t--) {
		int n;
		cin >> n;
		if (n == 0) break;

		memset(dp, -1, sizeof(dp));
		cout << go(n - 1, 1) << "\n";
	}
}