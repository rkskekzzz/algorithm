#include <iostream>
#include <vector>
#include <algorithm>

int N, M;
std::vector<std::string> list1;
std::vector<std::string> list2;
std::vector<std::string> result;

void output() {
	std::cout << result.size() << "\n";
	for (auto r : result) {
		std::cout << r << "\n";
	}
}

void solution() {
	std::sort(list1.begin(), list1.end());
	std::sort(list2.begin(), list2.end());
	for (auto l : list2) {
		if (std::binary_search(list1.begin(), list1.end(), l)) {
			result.push_back(l);
		}
 	}
}

void input_with_space() {
	std::cin >> N >> M;
	std::string name;
	for (int i = 0 ; i < N ; ++i) {
		std::cin >> name;
		list1.push_back(name);
	}
	for (int i = 0 ; i < M ; ++i) {
		std::cin >> name;
		list2.push_back(name);
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
