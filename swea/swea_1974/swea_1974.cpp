#include <iostream>

using namespace std;
int sudoku[9][9];

void input() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudoku[i][j];
		}
	}
}

bool checkRow(int cur) {
	
}

bool checkCol(int cur) {
	bool check[10] = { false, };

	for (int col = 0; col < 9; col++) {
		if (check[sudoku[cur][col]]) {
			return false;
		}
		check[sudoku[cur][col]] = true;
	}

	return true;
}

bool checkBox(int r, int c) {
	bool check[10] = { false, };

	for (int row = r; row < 3; row++) {
		for (int col = c; col < 3; col++) {
			if (check[sudoku[row][col]]) {
				return false;
			}
			check[sudoku[row][col]] = true;
		}
	}

	return true;
}

bool solve() {
	for (int i = 0; i < 9; i++) {
		if (!checkRow(i)) return false;
		if (!checkCol(i)) return false;
	}

	for (int i = 0; i < 9; i += 3) {
		for (int j = 0; j < 9; j += 3) {
			if (!checkBox(i, j)) return false;
		}
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		input();
		cout << "#" << test_case << " " << solve() << '\n';
	}

	return 0;
}