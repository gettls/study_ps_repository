#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
using namespace std;
#pragma warning (disable:4996)

int t, n;
int main() {
	cin >> t;

	while (t--) {
		cin >> n;
		priority_queue<long long> q;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			q.push(-x);
		}

		long long sum = 0;
		while (q.size() != 1) {
			long long less = -q.top();
			q.pop();
			long long next_less = -q.top();
			q.pop();
			sum += next_less + less;
			q.push(-(less + next_less));
		}

		cout << sum << "\n";
	}
}