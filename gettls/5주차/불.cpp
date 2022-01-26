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

int tc, w, h; // tc, 너비, 높이

char arr[1002][1002];
int cnt;
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };


bool isRange(int x, int y) {
	if (x < 0 || y < 0 || x > h + 1 || y > w + 1) return false;
	return true;
}

bool isExit(int x, int y) {
	if (x == 0 || x == h + 1 || y == 0 || y == w + 1) return true;
	return false;
}

bool bfs(queue<pii> fire, queue<pii> sg) {

	while (!sg.empty()) {
		cnt++;
		queue<pii> temp_fire;
		while (!fire.empty()) {
			int x = fire.front().first;
			int y = fire.front().second;
			fire.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (!isRange(nx, ny)) continue;
				if (arr[nx][ny] == '.' || arr[nx][ny] == '@') {
					arr[nx][ny] = '*';
					temp_fire.push({ nx,ny });
				}
			}
		}

		queue<pii> temp_sg;
		while (!sg.empty()) {
			int x = sg.front().first;
			int y = sg.front().second;
			sg.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (isExit(nx, ny)) {
					return true;
				}
				if (!isRange(nx, ny)) continue;
				if (arr[nx][ny] == '.') {
					arr[nx][ny] = '@';
					temp_sg.push({ nx,ny });
				}
			}
		}

		sg = temp_sg;
		fire = temp_fire;
	}
	return false;
}


int main() {
	cin >> tc;

	while (tc--) {
		cin >> w >> h;

		queue<pii> sg, fire;

		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == '@') sg.push({ i,j });
				else if (arr[i][j] == '*') fire.push({ i,j });
			}
		}
		cnt = 0;
		if (bfs(fire, sg)) cout << cnt << "\n";
		else cout << "IMPOSSIBLE\n";
	}
}