#include <iostream>
#include <vector>
#include <algorithm>

int N, M;
std::vector<int> map;
std::vector<int> find_list;

void output() {

}

void solution() {
	std::sort(map.begin(), map.end());
	for (auto f : find_list) {
		if (std::binary_search(map.begin(), map.end(), f)) {
			std::cout << 1 << "\n";
		} else {
			std::cout << 0 << "\n";
		}
	}
}

void input_with_space() {
	std::cin >> N;
	map = std::vector(N, 0);
	for (auto &i : map)
		std::cin >> i;
	std::cin >> M;
	find_list = std::vector(M, 0);
	for (auto &i : find_list)
		std::cin >> i;
	// print();
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
