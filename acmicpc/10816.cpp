#include <iostream>
#include <vector>
#include <algorithm>

int N, M;
std::vector<int> map;
std::vector<int> find_list;

void output() {

}

// vector, array : 1 1 4 4 4 5 5 7 7 7 8 8 8
// 4, 7

void solution() {
	std::sort(map.begin(), map.end());
	for (auto f : find_list) {
		auto lb = std::lower_bound(map.begin(), map.end(), f);
		auto ub = std::upper_bound(map.begin(), map.end(), f);
		std::cout << ub - lb << " ";
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
