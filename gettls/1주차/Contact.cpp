#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
// pattern = (100+1+|01)+
//		   = {1001, 01, 10001, 10011, 100001, 100111, ...}

vector<string> p_100;
vector<string> p_1;
vector<string> p_01;

vector<string> p_1001[201];

int T, flag;
string str;

void go(string param) {
	if (flag) return; // 찾은 경우 탈출

	if (param == str) {
		flag = 1; // 탈출을 위한 flag
		return;
	}
	// 접미사로 "01" 붙이기
	string nextParam = param + "01";
	// nextParam 이 str 과 일치하고 있을 때만 재귀 수행
	if (str.substr(0, nextParam.size()) == nextParam) go(nextParam);

	// 접미사로 1001 패턴 붙이기
	for (int i = 4; i + param.size() <= str.size(); i++) {
		for (int j = 0; j < p_1001[i].size(); j++) {
			string nextParam = param + p_1001[i][j];
			// nextParam 이 str 과 일치하고 있을 때만 재귀 수행
			if (str.substr(0, nextParam.size()) == nextParam) go(nextParam);
		}
	}

}

int main() {
	cin >> T;
	// ----------1001의 패턴을 만드는 작업--------- //
	p_100.resize(201); p_1.resize(201);
	p_100[3] = "100"; p_1[1] = "1";
	for (int i = 4; i <= 200; i++) p_100[i] = p_100[i - 1] + "0";
	for (int i = 2; i <= 200; i++) p_1[i] = p_1[i - 1] + "1";

	for (int length = 4; length <= 200; length++) {
		for (int i = 3; i < length; i++) {
			for (int j = length - i; j + i <= length; j++) {
				p_1001[length].push_back(p_100[i] + p_1[j]);
			}
		}
	}
	// -------------------------------------------- //

	while (T--) {
		cin >> str;
		flag = 0;
		go("");
		if (flag) printf("YES\n");
		else printf("NO\n");
	}
}

///------regex-----------///
int N;
int main()
{
	cin >> N;
	regex origin("((100+1+)|(01))+");
	while (N--) {
		string str;
		cin >> str;
		if (regex_match(str, origin))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
