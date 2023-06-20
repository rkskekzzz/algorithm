#include <iostream>
#include <vector>
#include <algorithm>

int k;

void output() {

}

void solution() {
	std::string str = std::to_string(k);
	for (int i = 0 ; i <= 9 ; ++i) {
		int count = 0;
		for (size_t j = 0 ; j < str.length() ; ++j) {
			if (str[j] - '0' == i) ++count;
		}
		std::cout << count << "\n";
	}

}

void input_with_space() {
	int a, b, c;
	std::cin >> a >> b >> c;
	k = a * b * c;
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
