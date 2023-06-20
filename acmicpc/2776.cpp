#include <iostream>
#include <vector>
#include <algorithm>

int T, N, M;
std::vector<int> note_1, note_2;

void solution() {
	std::sort(note_1.begin(), note_1.end());
	for (auto n : note_2) {
		bool result = std::binary_search(note_1.begin(), note_1.end(), n);
		if (result) {
			std::cout << 1 << "\n";
		} else {
			std::cout << 0 << "\n";
		}
	}
}

void input_with_space() {
	std::cin >> T;
	for (int i = 0 ; i < T ; ++i) {
		std::cin >> N;
		for (int j = 0 ; j < N ; ++j) {
			int num;
			std::cin >> num;
			note_1.push_back(num);
		}
		std::cin >> M;
		for (int j = 0 ; j < M ; ++j) {
			int num;
			std::cin >> num;
			note_2.push_back(num);
		}
		solution();
		note_1.clear();
		note_2.clear();
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
}
