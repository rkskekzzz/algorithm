#include <iostream>
#include <vector>
#include <queue>

int N;
std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

void output() {

}

void solution() {

}

void input_with_space() {
	std::cin >> N;
	int a;
	for (int i = 0 ; i < N ; ++i) {
		std::cin >> a;
		if (a == 0) {
			if (pq.empty()) {
				std::cout << "0\n";
			} else {
				int num = pq.top();
				pq.pop();
				std::cout << num << "\n";
			}
		} else {
			pq.push(a);
		}
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
