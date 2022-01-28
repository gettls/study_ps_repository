#include <string>
#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int ans;
pii matches[15] = { {0,1}, {0,2}, {0,3}, {0,4}, {0,5},
					{1,2}, {1,3}, {1,4}, {1,5}, {2,3},
					{2,4}, {2,5}, {3,4}, {3,5}, {4,5} };

int result[6][3], input[6][3];

void dfs(int idx) {
	if (idx == 15) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				if (result[i][j] != input[i][j]) return;
			}
		}
		ans = 1;
		return;
	}

	int t1 = matches[idx].first;
	int t2 = matches[idx].second;

	// t1 ½Â
	result[t1][0]++; result[t2][2]++;
	dfs(idx + 1);
	result[t1][0]--; result[t2][2]--;
	// t2 ½Â
	result[t1][2]++; result[t2][0]++;
	dfs(idx + 1);
	result[t1][2]--; result[t2][0]--;
	// ¹«½ÂºÎ
	result[t1][1]++; result[t2][1]++;
	dfs(idx + 1);
	result[t1][1]--; result[t2][1]--;
}

int main() {
	for (int t = 0; t < 4; t++) {
		ans = 0;
		for (int i = 0; i < 6; i++) {
			result[i][0] = result[i][1] = result[i][2] = 0;
			cin >> input[i][0] >> input[i][1] >> input[i][2];
		}
		dfs(0);
		cout << ans << "\n";
	}
}