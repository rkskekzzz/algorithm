#include <iostream>
#include <vector>

int N, count;
std::vector<int> map;

void output() {
	std::cout << count;
}

void solution() {
	for (auto num : map) {
		if (num == 1) {--count; continue;}
		if (num == 2) {continue;}
		for (int i = 2 ; i < num ; ++i) {
			if (num % i == 0) {
				--count;
				break;
			}
		}
	}
}

void input_with_space() {
	std::cin >> N;
	count = N;
	map = std::vector(N, 0);
	for (auto &i : map)
		std::cin >> i;

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
