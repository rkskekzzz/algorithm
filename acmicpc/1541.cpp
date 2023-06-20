#include <iostream>
#include <vector>

// 10+20-30-40-(50+60)-(70+90)-(100+110)
std::string str;

void output() {

}

int cal(bool isMinus, std::string num_stack) {
	if (isMinus) {
		return -std::stoi(num_stack);
	} else {
		return std::stoi(num_stack);
	}
}

void solution() {
	std::string num_stack;
	int sum = 0;
	bool isMinus = false;
	for (size_t i = 0 ; i < str.length() ; ++i) {
		if (str[i] == '+') {
			sum += cal(isMinus, num_stack);
			num_stack = "";
		} else if (str[i] == '-') {
			sum += cal(isMinus, num_stack);
			isMinus = true;
			num_stack = "";
		} else {
			num_stack += str[i];
		}
	}
	sum += cal(isMinus, num_stack);
	std::cout << sum;
}

void input_with_space() {
	std::cin >> str;
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
