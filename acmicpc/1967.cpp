#include <iostream>
#include <vector>
#include<cstring>

int N;
std::vector<std::pair<int, int> > map[10001];
bool visited[10001] = {false, };
int result = 0;
int endPoint = 0;

void output() {
	std::cout << result;
}

void dfs(int pos, int length) {
	if (visited[pos]) return;

	visited[pos] = true;

	if (result < length) {
		result = length;
		endPoint = pos;
	}

	for (auto m : map[pos]) {
		dfs(m.first, length + m.second);
	}
}

void solution() {
	dfs(1, 0);
	std::memset(visited, false, sizeof(visited));
	dfs(endPoint, 0);
}

void input_with_space() {
	std::cin >> N;
	for (int i = 0 ; i < N - 1 ; ++i) {
		int left, right, value;
		std::cin >> left >> right >> value;
		map[left].push_back({right, value});
		map[right].push_back({left, value});
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
