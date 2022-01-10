#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <cstring>
using namespace std;
#pragma warning (disable:4996)

int n, wire[501], dp[501];

int main() {
	cin >> n;
	int maxA = -1;
	memset(wire, -1, sizeof(wire));

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		wire[a] = b;
		maxA = max(maxA, a);
	}

	for (int i = 1; i <= maxA; i++) dp[i] = 1;


	int maxNum = -1;
	for (int i = 1; i <= maxA; i++) {
		if (wire[i] == -1) continue;
		for (int j = 1; j < i; j++) {
			if (wire[j] != -1 && wire[i] > wire[j]) {
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
		maxNum = max(maxNum, dp[i]);
	}

	cout << n - maxNum;
}