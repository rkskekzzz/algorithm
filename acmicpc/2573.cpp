#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N, M, year = 0;
std::vector<std::vector<int> > map;
std::vector<std::vector<int> > mirror_map;
std::vector<std::pair<int, int> > directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void print() {
	std::cout << std::endl;
	for (auto i: map) {
		for (auto j: i) {
			std::cout << j << " ";
		}
		std::cout << '\n';
	}
}

void output() {

}

void reset_mirror() {
	mirror_map = std::vector(N, std::vector(M, 0));
}

bool valid_position(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < M;
}

void melt() {
	reset_mirror();
	for (int x = 0 ; x < N ; ++x) {
		for (int y = 0 ; y < M ; ++y) {
			if (map[x][y] > 0) {
				int water_count = 0;
				for (auto direction : directions) {
					int new_x = x + direction.first;
					int new_y = y + direction.second;
					if (valid_position(new_x, new_y) && map[new_x][new_y] == 0)
						++water_count;
				}
				mirror_map[x][y] = water_count;
			}
		}
	}
	for (int x = 0 ; x < N ; ++x) {
		for (int y = 0 ; y < M ; ++y) {
			map[x][y] = std::max(0, map[x][y] - mirror_map[x][y]);
		}
	}
	// print();
}

void bfs(int x, int y) {
	std::queue<std::pair<int, int> > queue;

	queue.push({x, y});
	mirror_map[x][y] = 1;
	while (!queue.empty()) {
		auto front = queue.front();
		queue.pop();

		for (auto direction : directions) {
			int new_x = front.first + direction.first;
			int new_y = front.second + direction.second;
			if (valid_position(new_x, new_y) && map[new_x][new_y] > 0 && mirror_map[new_x][new_y] == 0) {
				mirror_map[new_x][new_y] = 1;
				queue.push({new_x, new_y});
			}
		}
	}
}

int check_island() {
	int island_count = 0;
	reset_mirror();
	for (int x = 0 ; x < N ; ++x) {
		for (int y = 0 ; y < M ; ++y) {
			if (map[x][y] > 0 && mirror_map[x][y] == 0) {
				bfs(x, y);
				++island_count;
			}
		}
	}
	// std::cout << "is : " << island_count << std::endl;
	return island_count;
}



void solution() {
	while (true) {
		++year;
		melt();
		int island_count = check_island();
		if (island_count == 0) {
			std::cout << 0;
			return;
		}
		if (island_count > 1) {
			std::cout << year;
			return;
		}
	}
}

void input_with_space() {
	std::cin >> N >> M;
	map = std::vector(N, std::vector(M, 0));
	mirror_map = std::vector(N, std::vector(M, 0));
	for (auto &i : map)
		for (auto &j : i)
			std::cin >> j;
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
