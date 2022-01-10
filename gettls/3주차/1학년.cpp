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


int arr[100], dp[100][21];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dp[0][arr[0]] = 1;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= 20; j++) {
			if (dp[i - 1][j] != 0) {
				if (j + arr[i] <= 20) {
					dp[i][j + arr[i]] += dp[i - 1][j];
				}
				if (j - arr[i] >= 0) {
					dp[i][j - arr[i]] += dp[i - 1][j];
				}
			}
		}
	}



	cout << dp[n - 2][arr[n - 1]];

}