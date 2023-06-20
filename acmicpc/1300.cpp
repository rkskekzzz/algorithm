#include <iostream>
#include <vector>
#include <algorithm>

int N, M;
std::vector<int> map;

/**
 * 1  2  3  4
 * 2  4  6  8
 * 3  6  9 12
 * 4  8 12 16
*/

void output() {
}

void solution() {
	std::sort(map.begin(), map.end());
	std::cout << map[M];
}

void input_with_space() {
	std::cin >> N >> M;
	for (int i = 1 ; i <= N ; ++i) {
		for (int j = 1 ; j <= N ; ++j) {
			map.push_back(i * j);
		}
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
