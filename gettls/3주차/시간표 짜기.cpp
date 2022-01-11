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
typedef unsigned long long ull;
int n, m;
vector<ull> lecture;

int main() {

	cin >> n;
	lecture.resize(n);

	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int x; cin >> x;
			lecture[i] |= ((ull)1 << x);
		}

	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		int p; cin >> p;
		ull tmp = 0;
		for (int j = 0; j < p; j++) {
			int q; cin >> q;
			tmp |= ((ull)1 << q);
		}

		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (lecture[j] == (lecture[j] & tmp)) {
				cnt++;
			}
		}
		cout << cnt << "\n";
	}

}