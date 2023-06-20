#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::string str;
int n, sum = 0;

void output() {
	std::cout << sum;
}

void solution() {
	for (int i = 0 ; i < n ; ++i) {
		sum += str[i] - '0';
	}
}

void input_with_space() {
	std::cin >> n;
	std::cin.ignore();
	std::getline(std::cin, str);
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
