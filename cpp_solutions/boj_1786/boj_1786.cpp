#include <iostream>
#include <vector>
#include <string>

using namespace std;
int failure[1000000];
string T, P;

void input() {
	getline(cin, T);
	getline(cin, P);
}

// prefix, suffix 일치 숫자 테이블 생성
void makeTable() {
	int j = 0;
	for (int i = 1; i < P.size(); i++) {
		while (j > 0 && P[i] != P[j]) {
			j = failure[j - 1];
		}

		if (P[i] == P[j]) {
			failure[i] = ++j;
		}
	}
}

void kmp() {
	makeTable();
	vector<int> findAt;

	int textSize = T.size();
	int patSize = P.size();

	int j = 0;

	for (int i = 0; i < textSize; i++) {

		while (j > 0 && T[i] != P[j]) {
			j = failure[j - 1];
		}

		if (T[i] == P[j]) {
			if (j == patSize - 1) {
				findAt.push_back(i - patSize + 1);
				j = failure[j];
			}
			else {
				j++;
			}
		}
	}

	cout << findAt.size() << '\n';
	for (auto& i : findAt) cout << i + 1 << ' ';
}

void solution() {
	input();
	kmp();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	solution();
}