#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <cstring>
using namespace std;
#pragma warning (disable:4996)
typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<int> v;
map<int, int> m;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());
	ll cnt = 0;
	for (int i = 0; i < n - 2; ++i) {
		for (int j = i + 1; j < n - 1; ++j) {
			int temp = (-1) * (v[i] + v[j]);
			int idx = lower_bound(v.begin() + j + 1, v.end(), temp) - v.begin();
			int idx2 = upper_bound(v.begin() + j + 1, v.end(), temp) - v.begin();
			cnt += idx2 - idx;
		}
	}

	cout << cnt;
}