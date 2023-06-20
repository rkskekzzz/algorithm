#include <iostream>
#include <vector>

int N;

void output() {

}

int cal(int num) {
	if (num / 5 > 0) return num / 5 + cal(num / 5);
	return num / 5;
}

void solution() {
	std::cout << cal(N);
}

void input_with_space() {
	std::cin >> N;
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
