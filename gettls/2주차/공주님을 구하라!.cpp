#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
using namespace std;
#pragma warning (disable:4996)

int m, n, t, INF = 1e9;
int arr[100][100], d[100][100][2];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };

void bfs() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			d[i][j][0] = INF;
			d[i][j][1] = INF;
		}
	}
	queue<pair<pair<int, int>, bool>> q;
	q.push({ {0,0},false });
	d[0][0][0] = 0;


	while (!q.empty()) {
		int x = q.front().first.first, y = q.front().first.second;
		bool gram = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (gram) {
				if (d[x][y][1] + 1 > t) continue;
				if (d[nx][ny][1] > d[x][y][1] + 1) {
					d[nx][ny][1] = d[x][y][1] + 1;
					q.push({ {nx,ny} ,gram });
				}
			}
			else {
				if (d[x][y][0] + 1 > t) continue;
				if (arr[nx][ny] == 2 &&
					d[nx][ny][1] > d[x][y][0] + 1) {
					d[nx][ny][1] = d[x][y][0] + 1;
					q.push({ {nx,ny}, true });
				}
				else if (arr[nx][ny] == 0
					&& d[nx][ny][0] > d[x][y][0] + 1) {
					d[nx][ny][0] = d[x][y][0] + 1;
					q.push({ {nx,ny} ,gram });
				}
			}
		}
	}
}

int main() {
	cin >> n >> m >> t;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	bfs();
	int res = min(d[n - 1][m - 1][0], d[n - 1][m - 1][1]);
	if (res == INF) cout << "Fail";
	else cout << res;
}