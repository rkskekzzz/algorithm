#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int T, n;
std::string str;
std::vector<std::string> results;

void output() {
	for (auto r : results) {
		std::cout << r << "\n";
	}
}

void solution() {
	std::string new_str;
	for (size_t i = 0 ; i < str.length() ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			new_str += str[i];
		}
	}
	results.push_back(new_str);
}

void input_with_space() {
	std::cin >> T;
	for (int i = 0 ; i < T ; ++i) {
		std::cin >> n;
		std::cin >> str;
		solution();
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
	output();
}
