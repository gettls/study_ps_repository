#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
using namespace std;
#pragma warning (disable:4996)


int main() {
	int n;
	cin >> n;
	vector<pair<long long, long long>> v;
	for (int i = 0; i < n; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		v.push_back({ b,c });
	}
	// 시작 시간 순 정렬 
	sort(v.begin(), v.end());

	// 끝나는 시간 순 정렬 큐
	priority_queue<long long> pq;
	pq.push(-v[0].second);
	for (int i = 1; i < v.size(); i++) {
		long long start = v[i].first, end = v[i].second;

		long long eariier = -pq.top();

		// 시작 시간이 가장 빨리 끝나는 강의실과 같거나 늦다면
		if (eariier <= start) {
			pq.pop();
			pq.push({ -end });
		}
		// 시작 시간이 가장 빨리 끝나는 강의실의 시간보다 더 빠르다면
		else {
			pq.push({ -end });
		}
	}
	cout << pq.size();
}