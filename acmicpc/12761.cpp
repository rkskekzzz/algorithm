#include <iostream>
#include <vector>
#include <queue>

int A, B, N, M;
int line[100001];

void output() {
	std::cout << line[M] - 1;
}

bool valid_position(int pos) {
	return pos >= 0 && pos <= 100000;
}

int jump(int pos, int idx) {
	switch (idx) {
		case 0:
			return pos + 1;
		case 1:
			return pos - 1;
		case 2:
			return pos + A;
		case 3:
			return pos - A;
		case 4:
			return pos + B;
		case 5:
			return pos - B;
		case 6:
			return pos * A;
		case 7:
			return pos * B;
		default:
			return 0;
	}
}

void solution() {
	std::queue<int> queue;
	queue.push(N);
	line[N] = 1;
	while(!queue.empty()) {
		int front = queue.front();
		queue.pop();
		if (front == M) break;
		for (int i = 0 ; i < 8 ; ++i) {
			int new_pos = jump(front, i);
			if (valid_position(new_pos) && line[new_pos] == 0) {
				queue.push(new_pos);
				line[new_pos] = line[front] + 1;
			}
		}
	}
}

void input_with_space() {
	std::cin >> A >> B >> N >> M;
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
