#include <iostream>
#include <vector>
#include <queue>

int N, M;
std::vector<std::vector<int>> map;
std::vector<std::pair<int, int> > directions = {{-1, 0},{0, -1},{0, 1},{1, 0}};

void print() {
	for (auto i: map) {
		for (auto j: i) {
			std::cout << j << " ";
		}
		std::cout << '\n';
	}
}


void output() {
	// print();
	std::cout << map[N - 1][M - 1];
}

bool valid_position(int new_n, int new_m) {
	return new_n >=0 && new_n < N && new_m >=0 && new_m < M;
}

bool valid_value(int new_n, int new_m) {
	return map[new_n][new_m] == 1;
}

void solution() {
	std::queue<std::pair<int, int> > queue;
	queue.push({0, 0});
	// map[0][0] = 0;
	while (!queue.empty()) {
		auto position = queue.front();
		queue.pop();
		if (position.first == N - 1 && position.second == M - 1) break;

		for (auto direction : directions) {
			int new_n = position.first + direction.first;
			int new_m = position.second + direction.second;
			if (valid_position(new_n, new_m) && valid_value(new_n, new_m)) {
				map[new_n][new_m] = map[position.first][position.second] + 1;
				queue.push({new_n, new_m});
			}
		}
	}
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
	// print();
}

void preset() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

int main() {
	preset();
	input_without_space();
	solution();
	output();
}
