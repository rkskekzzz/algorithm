#include <iostream>
#include <vector>

int N, K, max;
std::vector<int> map;

void output() {
	std::cout << max;
}

void solution() {
	for (int i = 0 ; i <= N - K ; ++i) {
		int left = i, right = i + K;
		max = std::max(max, map[right] - map[left]);
	}
}

void input_with_space() {
	std::cin >> N >> K;
	max = -2147483647 -1;
	map = std::vector(N + 1, 0);
	map[0] = 0;
	for (int i = 1 ; i <= N ; ++i) {
		int num;
		std::cin >> num;
		map[i] = map[i - 1] + num;
	}
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
