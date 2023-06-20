#include <iostream>
#include <vector>
#include <queue>

int max_floor, from, to, up, down;
int floors[10000001] = {0,};
std::vector<int> dirs;

void output() {
	if (floors[to] == 0) {
		std::cout << "use the stairs";
	} else {
		std::cout << floors[to] - 1;
	}
}

bool valid_floor(int floor) {
	return floor > 0 && floor <= max_floor;
}

void solution() {
	std::queue<int> queue;
	queue.push(from);
	floors[from] = 1;
	while (!queue.empty()) {
		int cur_floor = queue.front();
		queue.pop();
		if (cur_floor == to) {
			return;
		}
		for (auto dir : dirs) {
			int new_floor = cur_floor + dir;
			if (valid_floor(new_floor) && floors[new_floor] == 0) {
				floors[new_floor] = floors[cur_floor] + 1;
				queue.push(new_floor);
			}
		}
	}
}

void input_with_space() {
	std::cin >> max_floor >> from >> to >> up >> down;
	dirs.push_back(up);
	dirs.push_back(-down);
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
