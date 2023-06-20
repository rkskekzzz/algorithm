#include <iostream>
#include <vector>
#include <queue>

int N, r_g_b_count = 0, rg_b_count = 0;
std::vector<std::string > map;
std::vector<std::vector<int> > r_g_b_visited;
std::vector<std::vector<int> > rg_b_visited;
std::vector<std::pair<int, int> > directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void output() {
	std::cout << r_g_b_count << " " << rg_b_count;
}

bool valid_position(int i, int j) {
	return i >= 0 && j >= 0 && i < N && j < N;
}

void bfs2(int i, int j) {
	std::queue<std::pair<int, int> > queue;
	queue.push({i, j});
	rg_b_visited[i][j] = 1;
	char ch = map[i][j];
	while (!queue.empty()) {
		auto front = queue.front();
		queue.pop();
		for (auto direction : directions) {
			auto new_i = front.first + direction.first;
			auto new_j = front.second + direction.second;
			if (valid_position(new_i, new_j) && rg_b_visited[new_i][new_j] == 0 && ((map[new_i][new_j] == 'B') == (ch == 'B'))) {
				rg_b_visited[new_i][new_j] = 1;
				queue.push({new_i, new_j});
			}
		}
	}
}

void bfs(int i, int j) {
	std::queue<std::pair<int, int> > queue;
	queue.push({i, j});
	r_g_b_visited[i][j] = 1;
	char ch = map[i][j];
	while (!queue.empty()) {
		auto front = queue.front();
		queue.pop();
		for (auto direction : directions) {
			auto new_i = front.first + direction.first;
			auto new_j = front.second + direction.second;
			if (valid_position(new_i, new_j) && r_g_b_visited[new_i][new_j] == 0 && map[new_i][new_j] == ch) {
				r_g_b_visited[new_i][new_j] = 1;
				queue.push({new_i, new_j});
			}
		}
	}
}

void solution() {
	for (int i = 0 ; i < N ; ++i) {
		for (int j = 0 ; j < N ; ++j) {
			if (r_g_b_visited[i][j] == 0) {
				bfs(i, j);
				++r_g_b_count;
			}
			if (rg_b_visited[i][j] == 0) {
				bfs2(i, j);
				++rg_b_count;
			}
		}
	}
}

void input_with_space() {
	std::cin >> N;
	rg_b_visited = std::vector(N, std::vector(N, 0));
	r_g_b_visited = std::vector(N, std::vector(N, 0));
	for (int i = 0 ; i < N ; ++i) {
		std::string str;
		std::cin >> str;
		map.push_back(str);
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
	solution();
	output();
}
