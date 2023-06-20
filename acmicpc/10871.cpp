#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<int> results;

void output() {
	for (auto r : results) {
		std::cout << r << " ";
	}
}

void solution() {
}

void input_with_space() {
	int n, x;
	std::cin >> n >> x;
	for (int i = 0 ; i < n ; ++i) {
		int num;
		std::cin >> num;
		if (num < x) results.push_back(num);
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
