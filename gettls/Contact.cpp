#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
#pragma warning (disable:4996)
set<string> wearings;
string clothes[30][2];
int t, n, cnt;
void go(int idx) {
	if (idx == n) {
		cnt++;
		return;
	}

	for (int i = idx; i < n; i++) {
		string kind = clothes[i][0];
		string name = clothes[i][1];
		if (wearings.find(kind) != wearings.end()) {
			wearings.insert(kind);
			go(idx + 1);
			wearings.erase(kind);
		}
	}
}

int main() {
	cin >> t;

	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			string name, kind;
			scanf("%s %s",name,kind);
			clothes[i][0] = kind;
			clothes[i][1] = name;
		}
		cnt = 0;
		wearings.clear();
		go(0);
		printf("%d\n", cnt);
	}
}