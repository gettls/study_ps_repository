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
	// ���� �ð� �� ���� 
	sort(v.begin(), v.end());

	// ������ �ð� �� ���� ť
	priority_queue<long long> pq;
	pq.push(-v[0].second);
	for (int i = 1; i < v.size(); i++) {
		long long start = v[i].first, end = v[i].second;

		long long eariier = -pq.top();

		// ���� �ð��� ���� ���� ������ ���ǽǰ� ���ų� �ʴٸ�
		if (eariier <= start) {
			pq.pop();
			pq.push({ -end });
		}
		// ���� �ð��� ���� ���� ������ ���ǽ��� �ð����� �� �����ٸ�
		else {
			pq.push({ -end });
		}
	}
	cout << pq.size();
}