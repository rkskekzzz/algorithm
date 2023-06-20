#include <iostream>
#include <vector>

int N, M, count = 0;
std::vector<int> map[1001];
int visited[1001] = {0, };

void output() {
	std::cout << count;
}

void dfs(int i) {
	if (visited[i] == 1) return;
	visited[i] = 1;
	for (auto m : map[i]) {
		dfs(m);
	}
}

void solution() {
	for (int i = 1 ; i <= N ; ++i) {
		if (visited[i] == 0) {
			++count;
			dfs(i);
		}
	}
}

void input_with_space() {
	std::cin >> N >> M;
	int a, b;
	for (int i = 0 ; i < M ; ++i) {
		std::cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
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
