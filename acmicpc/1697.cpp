#include <iostream>
#include <vector>
#include <queue>

int from, to;
int road[100001] = {0,};

void output() {
	std::cout << road[to] - 1;
}

int jump(int pos, int idx) {
	switch (idx) {
		case 0:
			return pos + 1;
		case 1:
			return pos - 1;
		case 2:
			return pos * 2;
		default:
			return 0;
	}
}

bool valid_position(int pos) {
	return pos >= 0 && pos < 100001;
}

void solution() {
	std::queue<int> queue;
	queue.push(from);
	road[from] = 1;
	while (!queue.empty()) {
		int cur_pos = queue.front();
		queue.pop();
		if (cur_pos == to) {
			break ;
		}
		for (int i = 0 ; i < 3 ; ++i) {
			int new_pos = jump(cur_pos, i);
			if (valid_position(new_pos) && road[new_pos] == 0) {
				road[new_pos] = road[cur_pos] + 1;
				queue.push(new_pos);
			}
		}
	}
}

void input_with_space() {
	std::cin >> from >> to;
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
