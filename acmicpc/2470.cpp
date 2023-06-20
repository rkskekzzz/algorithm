#include <iostream>
#include <vector>
#include <algorithm>

int N, min;
std::vector<int> map;
int min_left, min_right;

void output() {
}

void solution() {
	min = 2000000000;
	int left = 0, min_left = 0;
	int right = map.size() - 1, min_right = map.size() - 1;
	std::sort(map.begin(), map.end());
	while (left < right) {
		int new_min = map[left] + map[right];
		if (std::abs(new_min) < min) {
			min_left = left;
			min_right = right;
			min = std::abs(new_min);
		}
		if (new_min < 0) {
			left += 1;
		} else {
			right -= 1;
		}
	}
	std::cout << map[min_left] << " " << map[min_right];
}

void input_with_space() {
	std::cin >> N;
	map = std::vector(N, 0);
	for (auto &m : map) {
		std::cin >> m;
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
