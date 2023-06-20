#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<int> array;
std::vector<int> mirror_array;
std::vector<int> results;

void output() {
	for (size_t i = 0 ; i < results.size() ; ++i) {
		std::cout << results[i];
		if (i != results.size() -1)
			std::cout << " ";
	}
}

void solution() {
	std::sort(array.begin(), array.end());
	array.erase(std::unique(array.begin(), array.end()), array.end());
	for (auto e : mirror_array) {
		std::cout << std::lower_bound(array.begin(), array.end(), e) - array.begin() << " ";
	}
}

void input_with_space() {
	std::cin >> N;
	for (int i = 0 ; i < N ; ++i) {
		int num;
		std::cin >> num;
		array.push_back(num);
	}
	mirror_array = array;
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
