#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

int T;
int M, N, K, count;

std::vector<std::pair<int, int> > directions = {{1, 0}, {-1, 0},{0, 1},{0, -1}};
std::vector<std::vector<int> > map;
std::vector<std::vector<int> > visited;
std::vector<int> results;

void print() {
	for (auto v : visited) {
		for (auto _v : v) {
			std::cout << _v << " ";
		}
		std::cout << std::endl;
	}
}

void output() {
	for (auto r : results) {
		std::cout << r << "\n";
	}
}

bool valid_position(int x, int y) {
	return x >=0 && y >= 0 && x < N && y < M;
}

void bfs(int x, int y) {
	std::queue<std::pair<int, int> > queue;
	queue.push({x, y});
	visited[x][y] = 1;
	while (!queue.empty()) {
		auto front = queue.front();
		queue.pop();
		for (auto d : directions) {
			int new_x = front.first + d.first;
			int new_y = front.second + d.second;
			if (valid_position(new_x, new_y) && visited[new_x][new_y] == 0 && map[new_x][new_y] == 1) {
				visited[new_x][new_y] = 1;
				queue.push({new_x, new_y});
			}
		}
	}
}

void solution() {
	count = 0;
	for (int i = 0 ; i < N ; ++i) {
		for (int j = 0 ; j < M ; ++j) {
			if (map[i][j] == 1 && visited[i][j] == 0) {
				bfs(i, j);
				++count;
			}
		}
	}
	results.push_back(count);
}

void input_with_space() {
	std::cin >> T;
	for (int i = 0 ; i < T ; ++i) {
		std::cin >> N >> M >> K;
		map = std::vector(N, std::vector(M, 0));
		visited = std::vector(N, std::vector(M, 0));
		for (int j = 0 ; j < K ; ++j) {
			int x, y;
			std::cin >> x >> y;
			map[x][y] = 1;
		}
		solution();
		// print();
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
	output();
}
