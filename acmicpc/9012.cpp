#include <iostream>
#include <vector>
#include <stack>

int N;
std::vector<std::string> vec;
void output() {

}

void solution() {
	for (auto str : vec) {
		std::stack<char> stack;
		for (size_t i = 0 ; i < str.length() ; ++i) {
			if (str[i] == '(') {
				stack.push(str[i]);
			} else {
				if (!stack.empty() && stack.top() == '(') {
					if (!stack.empty()) {
						stack.pop();
					} else {
						std::cout << "NO\n";
						continue;
					}
				} else {
					stack.push(str[i]);
				}
			}
		}
		if (stack.empty()) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}
}

void input_with_space() {
	std::cin >> N;
	for (int i = 0 ; i < N ; ++i) {
		std::string str;
		std::cin >> str;
		vec.push_back(str);
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
