#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<int> map;
std::vector<int> sequence;

void output() {
	std::cout << sequence.size();
}

bool comp(std::pair<int, int> a, std::pair<int, int> b) {
	return a.second < b.second;
}
// 10 20 25 28 29 30 :  15
void binary_push(int m) {
	int left = 0, right = sequence.size() - 1, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (sequence[mid] >= m) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	sequence[left] = m;
}

void solution() {
	sequence.push_back(map[0]);
	for (auto m : map) {
		if (m > sequence.back()) {
			sequence.push_back(m);
		} else {
			binary_push(m);
		}
	}

}

void input_with_space() {
	std::cin >> N;
	map = std::vector(N, 0);
	for (auto &m : map) {
		std::cin >> m;
	}
	// print();
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
