#include <iostream>
#include <vector>
#include <queue>

int N;
std::priority_queue<int, std::vector<int>> pq;

void output() {

}

void solution() {

}

void input_with_space() {
	std::cin >> N;
	for (int i = 0 ; i < N ; ++i) {
		int num;
		std::cin >> num;
		if (num == 0) {
			if (pq.empty()) {
				std::cout << 0 << "\n";
			} else {
				int top = pq.top();
				pq.pop();
				std::cout << top << "\n";
			}
		} else{
			pq.push(num);
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
