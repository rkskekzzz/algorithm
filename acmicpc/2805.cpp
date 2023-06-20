#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 2000000000
int N, M;
std::vector<int> map;

void output() {

}

long long remain(long long mid) {
	long long remain = 0;
	for (auto a : map) {
		if (a - mid > 0) {
			remain += a - mid;
		}
	}
	return remain;
}

void solution() {
	long long bottom = 0;
	long long top = MAX;
	long long mid;
	while (bottom <= top) {
		mid = (bottom + top) / 2;

		if (remain(mid) >= M) {
			bottom = mid + 1;
		} else {
			top = mid - 1;
		}
	}
	std::cout << top;
}

void input_with_space() {
	std::cin >> N >> M;
	map = std::vector(N, 0);
	for (auto &i : map)
		std::cin >> i;
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
