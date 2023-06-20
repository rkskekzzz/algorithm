#include <iostream>
#include <vector>
#include <queue>

int count_of_family, from, to, relations;
std::vector<int> family[101];
int checked[101];
int links = 0;


void output() {
	std::cout << (checked[to] == 0 ? - 1 : checked[to] - 1);
}

void solution() {
	std::queue<int> queue;
	queue.push(from);
	checked[from] = 1;

	while (!queue.empty()) {
		auto front = queue.front();
		queue.pop();
		if (front == to) break;
		for (auto link : family[front]) {
			if (checked[link] == 0) {
				checked[link] = checked[front] + 1;
				queue.push(link);
			}
		}
	}
}

void input_with_space() {
	std::cin >> count_of_family;
	std::cin >> from >> to;
	std::cin >> relations;

	for (int i = 0 ; i < relations ; ++i) {
		int parent, child;
		std::cin >> parent >> child;
		family[parent].push_back(child);
		family[child].push_back(parent);
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
