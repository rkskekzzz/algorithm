#include <iostream>
#include <vector>
#include <algorithm>

int N, minL, minR;
std::vector<int> map;

void output() {
	std::cout << map[minL] << " " << map[minR];

}

void solution() {
	int left = 0, right = N - 1;
	minL = left;
	minR = right;
	int sum = std::abs(map[left] + map[right]);
	while (left < right) {
		int newsum = map[left] + map[right];
		if (sum > std::abs(newsum)) {
			sum = std::abs(newsum);
			minL = left;
			minR = right;
		}
		if (newsum < 0) {
			++left;
		} else {
			--right;
		}
	}
}

void input_with_space() {
	std::cin >> N;
	map = std::vector(N, 0);
	for (auto &i : map)
		std::cin >> i;

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
