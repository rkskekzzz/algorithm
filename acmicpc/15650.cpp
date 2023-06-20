#include <iostream>
#include <vector>

#define MAX 9

int N, M;
int arr[MAX] = {0,};
bool visited[MAX] = {0,};

void output() {

}

void dfs(int pos, int depth) {
	if (depth == M) {
		for (int i = 0 ; i < depth ; ++i) {
			std::cout << arr[i] << " ";
		}
		std::cout << "\n";
	}
	for (int i = pos ; i <= N ; ++i) {
		if (!visited[i]) {
			visited[i] = true;
			arr[depth] = i;
			dfs(i, depth + 1);
			visited[i] = false;
		}
	}
}

void solution() {
	dfs(1, 0);
}

void input_with_space() {
	std::cin >> N >> M;
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
