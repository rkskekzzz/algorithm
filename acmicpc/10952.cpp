#include <iostream>
#include <vector>
#include <string>
#include <sstream>


void output() {
}

void solution() {
}

void input_with_space() {
	int a, b;
	while (std::cin >> a >> b) {
		std::cout << a + b << "\n";
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
