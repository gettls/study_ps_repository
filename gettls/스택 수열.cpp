#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
#pragma warning (disable:4996)

int main() {
	int n;
	cin >> n;
	queue<int> q;
	stack<int> s;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		q.push(x);
	}

	int num = 1;
	while (!q.empty()) {
		if (num == n + 1 && q.front() != s.top()) {
			printf("NO\n");
			break;
		}
		if (s.empty()) {
			printf("+ %d \n", num);
			s.push(num++); continue;
		}
		if (q.front() == s.top()) {
			printf("- %d \n", s.top());
			q.pop();
			s.pop();
		}
		else if (q.front() >= num) {
			printf("+ %d \n", num);
			s.push(num++);
		}
		else {
			printf("+ %d \n", num);
			s.push(num++);
		}
	}
}