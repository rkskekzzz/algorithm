#include <iostream>
#include <vector>

int N;
std::vector<std::string> map;


void output() {

}

std::string to_linear(int i, int j) {
	std::string res;
	if (map[i][j] == map[i][j + 1] &&
		map[i][j] == map[i + 1][j] &&
		map[i][j] == map[i + 1][j + 1]) {
			res += map[i][j];
			return res;
		}
	res += "(";
	res += map[i][j];
	res += map[i][j + 1];
	res += map[i + 1][j];
	res += map[i + 1][j + 1];
	res += ")";
	return res;
}

void print_inner(std::vector<std::string> inner) {
	std::cout << "-----------------------\n";
	for (auto i : inner) {
		std::cout << i << std::endl;
	}
	std::cout << "-----------------------\n";
}

std::string solution(int idx, int jdx, int delim) {
	std::vector<std::string> inner;
	for (int i = idx ; i <= idx + delim; i += delim) {
		for (int j = jdx ; j <= jdx + delim; j += delim) {
			if (delim > 2) {
				inner.push_back(solution(i, j, delim / 2));
			}
			if (delim == 2) {
				inner.push_back(to_linear(i, j));
			}
		}
	}
	if (inner[0].length() == 1 && inner[0] == inner[1] &&
		inner[0] == inner[2] &&
		inner[0] == inner[3]) {
			return inner[0];
		} else {
			return "(" + inner[0] + inner[1] + inner[2] + inner[3] + ")";
		}
}

void input_with_space() {
	std::cin >> N;
	for (int i = 0 ; i < N ; ++i) {
		std::string str;
		std::cin >> str;
		map.push_back(str);
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
	if (N == 1) {
		std::cout << map[0][0];
	} else if (N == 2) {
		std::cout << to_linear(0, 0);
	} else {
		std::cout << solution(0, 0, N / 2);
	}
	output();
}
