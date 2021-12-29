#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
using namespace std;
#pragma warning (disable:4996)

int a, b; // a to b
int n, m; // 문자수 n, 문자쌍 수 m

vector<vector<int>> character;
int bfs() {
	vector<int> visited(n + 1, 0);
	queue<pair<int, int>> q; // <charcater ,depth>
	q.push({ a, 0 });
	visited[a] = 1;
	while (!q.empty()) {
		int cur = q.front().first;
		int depth = q.front().second;
		if (cur == b) return depth;
		q.pop();
		for (int i = 0; i < character[cur].size(); i++) {
			int next = character[cur][i];
			if (visited[next] == 0) {
				visited[next] = 1;
				q.push({ next,depth + 1 });
			}
		}
	}

	return -1;
}

int main() {
	cin >> a >> b;
	cin >> n >> m;

	character.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		character[x].push_back(y);
		character[y].push_back(x);
	}

	cout << bfs();
}