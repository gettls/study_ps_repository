#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
#pragma warning (disable:4996)
int t, n, cnt;
int main() {
	cin >> t;
	// ��� ����� �� - ���� ������ ����� �� (1)
	// headgear 2, eyewear 1
	// (2+1) * (1+1) - 1 = 5
	// headgear �� �����ϴ� ����Ǽ� = 2 + headgear �� �������� �ʴ� ����� �� = 1
	// eyewear �� �����ϴ� ����Ǽ� = 1 + eyewear �� �������� �ʴ� ����� �� = 1
	while (t--) {
		cin >> n;
		map<string, int> numberOfClothes;
		for (int i = 0; i < n; i++) {
			string name, kind;
			cin >> name >> kind;
			numberOfClothes[kind]++;
		}

		cnt = 1;
		for (auto i : numberOfClothes) {
			cnt *= (i.second + 1);
		}
		cnt--;
		printf("%d\n", cnt);
	}
}