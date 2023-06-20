#include <iostream>
#include <vector>

int N, M;
std::vector<int> map;

void output() {
	// for (auto m : map) {
	// 	std::cout << m << " ";
	// }
}

void solution() {
	for (int i = 0 ; i < M ; ++i) {
		int from, to;
		std::cin >> from >> to;
		std::cout << map[to] - map[from - 1] << "\n";
	}
}

void input_with_space() {
	std::cin >> N >> M;
	int num;
	std::cin >> num;
	map.push_back(0);
	map.push_back(num);
	for (int i = 1 ; i < N ; ++i) {
		std::cin >> num;
		map.push_back(map[i] + num);
	}
	// output();
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
	// output();
}
