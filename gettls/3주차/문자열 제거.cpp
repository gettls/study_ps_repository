#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <bitset>
#include <cstring>
using namespace std;
#pragma warning (disable:4996)
typedef unsigned long long ull;
typedef pair<int, int> pii;

string s; int M;
string a[100]; int x[100];
int dp[1000];

int main() {

	cin >> s;
	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> a[i] >> x[i];
	}

	for (int i = s.length() - 1; i >= 0; i--) {
		for (int j = 0; j < M; j++) {
			if (s.substr(i, a[j].size()) == a[j]) {
				if (i + a[j].size() >= s.length()) dp[i] = max(dp[i], x[j]);
				else dp[i] = max(dp[i], dp[i + a[j].size()] + x[j]);
			}
			else {
				if (i + 1 >= s.length()) dp[i] = max(dp[i], 1);
				else dp[i] = max(dp[i], dp[i + 1] + 1);
			}
		}
	}

	cout << dp[0];
}