#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N, M, H;
std::vector<std::vector<std::vector<int> > > map;
std::vector<std::vector<std::vector<int> > > visited;
std::queue<std::vector<int> > queue;
int max_day = 0;
int directions[6][3] = {
	{0, 0, 1},
	{0, 0, -1},
	{0, 1, 0},
	{0, -1, 0},
	{1, 0, 0},
	{-1, 0, 0},
};

void output() {
	std::cout << std::endl;
	for (auto &i : map) {
		for (auto &j : i) {
			for (auto &k : j)
				std::cout << k << " ";
			std::cout << std::endl;
		}
	}
}

void reset_visited() {
	visited = std::vector(H, std::vector(M, std::vector(N, 0)));
}

bool valid_position(int new_x, int new_y, int new_z) {
	return new_x >= 0 && new_y >= 0 && new_z >= 0 && new_x < H && new_y < M && new_z < N;
}


void bfs() {
	while (!queue.empty()) {
		auto front = queue.front();
		queue.pop();
		for (auto direction : directions) {
			int new_x = front[0] + direction[0];
			int new_y = front[1] + direction[1];
			int new_z = front[2] + direction[2];
			if (valid_position(new_x, new_y, new_z) && map[new_x][new_y][new_z] == 0) {
				map[new_x][new_y][new_z] = map[front[0]][front[1]][front[2]] + 1;
				queue.push({new_x, new_y, new_z});
			}
		}
	}
}

void solution() {
	for (int x = 0 ; x < H ; ++x) {
		for (int y = 0 ; y < M ; ++y) {
			for (int z = 0 ; z < N ; ++z) {
				if (map[x][y][z] == 1) {
					queue.push({x, y, z});
				}
			}
		}
	}
	bfs();
	for (int x = 0 ; x < H ; ++x) {
		for (int y = 0 ; y < M ; ++y) {
			for (int z = 0 ; z < N ; ++z) {
				if (map[x][y][z] == 0) {
					std::cout << -1;
					return;
				}
				if (map[x][y][z] > 0) {
					max_day = std::max(max_day, map[x][y][z]);
				}
			}
		}
	}
	std::cout << max_day - 1;
}

void input_with_space() {
	std::cin >> N >> M >> H;
	map = std::vector(H, std::vector(M, std::vector(N, 0)));
	visited = std::vector(H, std::vector(M, std::vector(N, 0)));
	for (auto &i : map)
		for (auto &j : i)
			for (auto &k : j)
				std::cin >> k;
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
