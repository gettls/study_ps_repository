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

int n, m, h;

struct pos {
	int x, y;
};

pos home;
vector<int> mincho;

int main() {
	cin >> n >> m >> h; // 크기, 초기체력, 증가 체력

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			if (x == 1) {
				home.x = i;
				home.y = j;
			}
			else if (x == 2) {
				mincho.push_back(i * n + j);
			}
		}
	}

	sort(mincho.begin(), mincho.end());

	int ans = 0;
	do {
		pos cur = home;
		int leftHealth = m, cnt = 0;
		for (int i = 0; i < mincho.size(); i++) {
			int x = mincho[i] / n;
			int y = mincho[i] % n;
			int dist_Mincho = abs(x - cur.x) + abs(y - cur.y);
			int dist_Home = abs(home.x - cur.x) + abs(home.y - cur.y);
			if (dist_Home <= leftHealth) {
				ans = max(ans, cnt);
			}
			if (dist_Mincho > leftHealth) break;
			cur.x = x;
			cur.y = y;
			leftHealth = leftHealth - dist_Mincho + h;
			cnt++;
			if (i == mincho.size() - 1) {
				dist_Home = abs(home.x - cur.x) + abs(home.y - cur.y);
				if (dist_Home <= leftHealth) {
					ans = max(ans, cnt);
				}
			}
		}
	} while (next_permutation(mincho.begin(), mincho.end()));

	cout << ans;
}
