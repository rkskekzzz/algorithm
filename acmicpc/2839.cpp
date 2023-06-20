#include <iostream>
#include <vector>
#include <algorithm>

int N;
int sugar[5001] = {0, };

void output() {
	std::cout << sugar[N];
}

void solution() {
	sugar[1] = -1;
	sugar[2] = -1;
	sugar[3] = 1;
	sugar[4] = -1;
	sugar[5] = 1;
	for (int i = 6 ; i <= N ; ++i) {
		if (sugar[i - 3] > 0 && sugar[i - 5] > 0) {
			sugar[i] = std::min(sugar[i - 3], sugar[i - 5]) + 1;
		} else if (sugar[i - 3] > 0) {
			sugar[i] = sugar[i - 3] + 1;
		} else if (sugar[i - 5] > 0) {
			sugar[i] = sugar[i - 5] + 1;
		} else {
			sugar[i] = -1;
		}
	}
}

void input_with_space() {
	std::cin >> N;
}

void preset() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

int main() {
	preset();
	input_with_space();
	solution();
	output();
}
