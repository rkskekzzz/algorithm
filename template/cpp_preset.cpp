#include <iostream>
#include <vector>

int N, M;
std::vector<std::vector<int>> map;

void print() {
	for (auto i: map) {
		for (auto j: i) {
			std::cout << j << " ";
		}
		std::cout << '\n';
	}
}


void output() {

}

void solution() {

}

void input_with_space() {
	std::cin >> N >> M;
	map = std::vector(N, std::vector(M, 0));
	for (auto &i : map)
		for (auto &j : i)
			std::cin >> j;
	print();
}

void input_without_space() {
	std::cin >> N >> M;
	map = std::vector(N, std::vector(M, 0));
	for (auto &i : map) {
		std::string input_str;
		std::cin >> input_str;
		for (int j = 0 ; j < M ; ++j) {
			i[j] = input_str[j] - '0';
		}
	}
	print();
}

void preset() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

int main() {
	preset();
	// input_with_space();
	input_without_space();
	solution();
	output();
}
