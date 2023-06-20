#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int test_count;
std::vector<std::pair<int, int> > stores;
std::vector<std::pair<int, int> > visited;
std::vector<std::string> results;

bool distance(std::pair<int, int> from, std::pair<int, int> to) {
	return std::abs(from.first - to.first) + std::abs(from.second - to.second) <= 1000;
}

bool is_visited(std::pair<int, int> store) {
	auto it = std::find(visited.begin(), visited.end(), store);
    if (it == visited.end()) {
		return false;
    }
    else {
        return true;
    }

}

void bfs(std::pair<int, int> from, std::pair<int, int> to) {
	std::queue<std::pair<int, int> > queue;
	queue.push({from.first, from.second});

	while(!queue.empty()) {
		auto front = queue.front();
		queue.pop();

		if (distance(front, to)) {
			results.push_back("happy");
			return ;
		}
		for (auto store : stores) {
			if (distance(front, store) && !is_visited(store)) {
				visited.push_back(store);
				queue.push(store);
			}
		}
	}
	results.push_back("sad");
}

void input_with_space() {
	std::cin >> test_count;
	for (int i = 0 ; i < test_count ; ++i) {
		int cu_count, x, y;
		std::pair<int, int> from;
		std::pair<int, int> to;

		std::cin >> cu_count;
		std::cin >> x >> y;
		from = {x, y};
		for (int j = 0 ; j < cu_count ; ++j) {
			std::cin >> x >> y;
			stores.push_back({x, y});
		}
		std::cin >> x >> y;
		to = {x, y};
		bfs(from, to);
		stores.clear();
		visited.clear();
	}
}

void output() {
	for (auto result : results) {
		std::cout << result << "\n";
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
