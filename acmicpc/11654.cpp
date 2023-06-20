#include <iostream>
#include <vector>
#include <string>
#include <sstream>

char ascii;

void output() {
	std::cout << ascii + 0;
}

void solution() {
}

void input_with_space() {
	std::cin >> ascii;
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
