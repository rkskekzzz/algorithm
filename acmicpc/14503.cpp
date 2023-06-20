#include <iostream>
#include <vector>

int N, M, count = 0;
int order_index;
std::pair<int, int> start;
std::vector<std::vector<int> > map;
std::vector<std::pair<int, int> > directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int orders[4] = {
	0, 3, 2, 1
};
void print() {
	std::cout << '\n';
	for (auto i: map) {
		for (auto j: i) {
			std::cout << j << " ";
		}
		std::cout << '\n';
	}
}
int order_idx(int idx) {
	return (idx + 1) % 4 ;
}

bool valid_position(std::pair<int, int> pos) {
	return map[pos.first][pos.second] != 1;
}

bool is_dirty(std::pair<int, int> pos) {
	for (auto direction : directions) {
		int new_x = pos.first + direction.first;
		int new_y = pos.second + direction.second;
		if (valid_position({new_x, new_y}) && map[new_x][new_y] == 0) {
			return true;
		}
	}
	return false;
}

void solution() {
	std::pair<int, int> pos = start;
	while (true) {
		// 1
		if (map[pos.first][pos.second] == 0) {
			map[pos.first][pos.second] = 2;
			++count;
			// print();
		}
		// 2
		if (is_dirty(pos)) {
			order_index = order_idx(order_index);
			int new_x = pos.first + directions[orders[order_index]].first;
			int new_y = pos.second + directions[orders[order_index]].second;
			if (valid_position({new_x, new_y}) && map[new_x][new_y] == 0) {
				pos = {new_x, new_y};
			}
		} else {
			int new_x = pos.first + directions[orders[order_idx(order_index + 1)]].first;
			int new_y = pos.second + directions[orders[order_idx(order_index + 1)]].second;
			if (valid_position({new_x, new_y})) {
				pos = {new_x, new_y};
			}
			else {
				return ;
			}
		}

	}
}

void input_with_space() {
	int start_x, start_y, direction;
	std::cin >> N >> M;
	std::cin >> start_x >> start_y >> direction;
	for (int i = 0 ; i < 4 ; ++i) {
		if (orders[i] == direction) {
			order_index = i;
			break ;
		}
	}
	start = {start_x, start_y};
	map = std::vector(N, std::vector(M, 0));
	for (auto &i : map)
		for (auto &j : i)
			std::cin >> j;

}

void preset() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void output() {
	std::cout << count;
}

int main() {
	preset();
	input_with_space();
	solution();
	output();
}
