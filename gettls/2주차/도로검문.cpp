#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
using namespace std;
#pragma warning (disable:4996)

int n, m;
int d[1001], parent[1001];
int city1, city2, flag = 1;
vector<vector<pair<int, int>>> v;
void dijkstra() {
	fill(d, d + n + 1, 1e9);
	priority_queue<pair<int, int>> q;
	q.push({ 0, 1 });
	d[1] = 0;
	while (!q.empty()) {
		int cur = q.top().second;
		int dist = -q.top().first;
		q.pop();
		if (d[cur] < dist) continue;
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int nextDist = dist + v[cur][i].second;
			if (cur == city1 && next == city2) continue;
			if (cur == city2 && next == city1) continue;
			if (nextDist < d[next]) {
				if (flag) {
					parent[next] = cur;
				}
				d[next] = nextDist;
				q.push({ -nextDist, next });
			}
		}
	}
}

int main() {
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}

	int before, after = -1;
	parent[1] = 1;
	dijkstra();
	flag = 0;
	before = d[n];

	int cur = n;
	// 모든 간선을 검문한다.
	// city1 <-> city2 를 봉쇄하고 최단경로를 찾아 최댓값을 찾는다
	while (cur != 1) {
		city1 = cur;
		city2 = parent[cur];
		dijkstra();
		after = max(d[n], after);
		if (after == 1e9) break;
		cur = parent[cur];
	}

	if (after == 1e9) cout << "-1";
	else cout << after - before;
}