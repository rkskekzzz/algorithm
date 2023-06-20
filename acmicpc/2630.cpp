#include <iostream>
#include <vector>

int N;
std::vector<std::vector<int> > map;

void output() {

}

int cut(int x, int y, int delim) {

}

void solution() {
	cut(0, 0, N / 2);
	cut(0, N / 2, N / 2);
	cut(N / 2, 0, N / 2);
	cut(N / 2, N / 2, N / 2);
}

void input_with_space() {
	std::cin >> N;
	map = std::vector(N, std::vector(N, 0));
	for (auto &i : map)
		for (auto &j : i)
			std::cin >> j;

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
