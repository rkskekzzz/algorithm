#include <iostream>
#include <vector>
#include <queue>

#define MAX 100001

int N;
std::vector<int> map[MAX];
int result[MAX] = {0, };
bool visited[MAX] = {false, };

void output() {
	for (int i = 2 ; i <= N ; ++i) {
		std::cout << result[i] << "\n";
	}
}

void solution() {
	std::queue<int> queue;
	queue.push(1);
	visited[1] = true;
	while (!queue.empty()) {
		auto front = queue.front();
		queue.pop();

		for (auto m : map[front]) {
			if (!visited[m]) {
				visited[m] = true;
				result[m] = front;
				queue.push(m);
			}
		}
	}
}

void input_with_space() {
	std::cin >> N;
	for (int i = 0 ; i < N - 1 ; ++i) {
		int left, right;
		std::cin >> left >> right;
		map[left].push_back(right);
		map[right].push_back(left);
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
