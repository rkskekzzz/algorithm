#include <iostream>
#include <vector>
#include <algorithm>
int N, M;
std::vector<int> set_a, set_b, results;


void output() {
	std::sort(results.begin(), results.end());
	std::cout << results.size() << "\n";
	if (results.size() == 0) return;
	for (auto r : results) {
		std::cout << r << " ";
	}
}

void solution() {
	std::sort(set_b.begin(), set_b.end());
	for (auto a : set_a){
		bool result = std::binary_search(set_b.begin(), set_b.end(), a);
		if (!result)
			results.push_back(a);
	}
}

void input_with_space() {
	std::cin >> N >> M;
	for (int i = 0 ; i < N ; ++i) {
		int num;
		std::cin >> num;
		set_a.push_back(num);
	}
	for (int i = 0 ; i < M ; ++i) {
		int num;
		std::cin >> num;
		set_b.push_back(num);
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
