#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

int N, M, max = 0;
std::vector<std::pair<int, int> > directions = {{1, 0}, {-1, 0},{0, 1},{0, -1}};
std::vector<std::vector<int> > map;
std::queue<std::pair<int, int> > queue;

void output() {
	for (int i = 0 ; i < M ; ++i) {
		for (int j = 0 ; j < N ; ++j) {
			if (map[i][j] == 0) {
				std::cout << -1;
				return;
			}
			max = std::max(max, map[i][j]);
		}
	}
	std::cout << max - 1;
}

bool valid_position(int x, int y) {
	return x >=0 && y >= 0 && x < M && y < N;
}

void bfs() {
	while (!queue.empty()) {
		auto front = queue.front();
		queue.pop();
		for (auto d : directions) {
			int new_x = front.first + d.first;
			int new_y = front.second + d.second;
			if (valid_position(new_x, new_y) && map[new_x][new_y] != -1 && (map[front.first][front.second] + 1 < map[new_x][new_y] || map[new_x][new_y] == 0)) {
				map[new_x][new_y] = map[front.first][front.second] + 1;
				queue.push({new_x, new_y});
			}
		}
	}
}

void solution() {
	bfs();
}

void input_with_space() {
	std::cin >> N >> M;
	map = std::vector(M, std::vector(N, 0));
	for (int i = 0 ; i < M ; ++i) {
		for (int j = 0 ; j < N ; ++j) {
			int num;
			std::cin >> num;
			map[i][j] = num;
			if (num == 1) {
				queue.push({i,j});
			}
		}
	}
	solution();
}

void preset() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

int main() {
	preset();
	input_with_space();
	output();
}
