#include <iostream>
#include <vector>
#include <queue>

int N;
std::vector<std::vector<int> > map;
std::vector<std::vector<int> > visited;
std::vector<std::pair<int, int> > directions = {{-1, 0},{0, -1},{0, 1},{1, 0}};
int max_height = 0, max_count = 0, count = 0;

void print() {
	for (auto i: map) {
		for (auto j: i) {
			std::cout << j << " ";
		}
		std::cout << '\n';
	}
}

void reset_visited() {
	visited = std::vector(N, std::vector(N, 0));
}

bool valid_position(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < N;
}

void output() {
	std::cout << max_count;
}

void bfs(int x, int y, int height) {
	std::queue<std::pair<int, int> > queue;
	queue.push({x, y});
	visited[x][y] = 1;
	while(!queue.empty()) {
		std::pair<int, int> front = queue.front();
		queue.pop();
		for (auto direction : directions) {
			int new_x = front.first + direction.first;
			int new_y = front.second + direction.second;
			if (valid_position(new_x, new_y) && visited[new_x][new_y] == 0 && map[new_x][new_y] > height) {
				visited[new_x][new_y] = 1;
				queue.push({new_x, new_y});
			}
		}
	}
}

void solution() {
	for (int i = 0 ; i <= max_height ; ++i) {
		for (int x = 0 ; x < N ; ++x) {
			for (int y = 0 ; y < N ; ++y) {
				if (map[x][y] > i && visited[x][y] == 0) {
					bfs(x, y, i);
					++count;
				}
			}
		}
		// std::cout << "count : " << count << std::endl;
		max_count = std::max(max_count, count);
		count = 0;
		reset_visited();
	}
}

void input_with_space() {
	std::cin >> N;
	map = std::vector(N, std::vector(N, 0));
	visited = std::vector(N, std::vector(N, 0));
	for (auto &i : map) {
		for (auto &j : i) {
			std::cin >> j;
			max_height = std::max(max_height, j);
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
	input_with_space();
	solution();
	output();
}
