#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> results;

void output() {
	std::cout << *std::max_element(results.begin(), results.end()) << "\n";
	std::cout << std::max_element(results.begin(), results.end()) - results.begin() + 1 << "\n";
}

void solution() {
}

void input_with_space() {
	for (int i = 0 ; i < 9 ; ++i) {
		int num;
		std::cin >> num;
		results.push_back(num);
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
