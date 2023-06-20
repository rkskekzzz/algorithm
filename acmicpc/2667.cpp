#include <iostream>
#include <vector>
#include <algorithm>

int N, count = 0;
std::vector<std::pair<int, int> > directions = {{-1, 0},{0, -1},{0, 1},{1, 0}};
std::vector<std::vector<int> > map;
std::vector<std::vector<int> > visited;
std::vector<int> counts;

void print() {
	for (auto i: map) {
		for (auto j: i) {
			std::cout << j << " ";
		}
		std::cout << '\n';
	}
}


void output() {
	std::cout << counts.size() << "\n";
	std::sort(counts.begin(), counts.end());
	for (auto count : counts) {
		std::cout << count << "\n";
	}
}

bool valid_position(int x, int y) {
	return x >= 0 && y >=0 && x < N && y < N;
}

void dfs (int x, int y) {
	if (visited[x][y] || map[x][y] == 0) return;
	++count;
	visited[x][y] = true;
	for (auto direction : directions) {
		int new_x = x + direction.first;
		int new_y = y + direction.second;
		if (valid_position(new_x, new_y)) {
			dfs(new_x, new_y);
		}
	}
}

void solution() {
	for (int i = 0 ; i < N ; ++i) {
		for (int j = 0 ; j < N ; ++j) {
			count = 0;
			dfs(i, j);
			if (count > 0) {
				counts.push_back(count);
			}
		}
	}
}

void input_without_space() {
	std::cin >> N;
	map = std::vector(N, std::vector(N, 0));
	visited = std::vector(N, std::vector(N, 0));
	for (auto &i : map) {
		std::string input_str;
		std::cin >> input_str;
		for (int j = 0 ; j < N ; ++j) {
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
	// input_with_space();
	input_without_space();
	solution();
	output();
}
