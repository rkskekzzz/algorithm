#include <iostream>
#include <vector>
#include <set>

int N, M, count = 0;
std::set<std::string> tree;
std::vector<std::string> find;

void output() {
	std::cout << count;
}

void solution() {
	for (auto f : find) {
		if (tree.find(f) != tree.end()) {
			++count;
		}
	}
}

void input_with_space() {
	std::cin >> N >> M;
	for (int i = 0 ; i < N ; ++i) {
		std::string str;
		std::cin >> str;
		tree.insert(str);
	}
	for (int i = 0 ; i < M ; ++i) {
		std::string str;
		std::cin >> str;
		find.push_back(str);
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
