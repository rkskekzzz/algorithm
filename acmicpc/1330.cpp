#include <iostream>
#include <vector>
#include <algorithm>


int a, b;

void output() {

}

void solution() {
	if (a > b) {
		std::cout << '>';
	} else if (a < b){
		std::cout << '<';
	} else {
		std::cout << "==";
	}
}

void input_with_space() {
	std::cin >> a >> b;
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
