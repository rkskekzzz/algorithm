#include <iostream>
#include <vector>

int N, M, minLength;
std::vector<int> map;

// 5  1  3  5 10  7  4  9  2  8
// 5  6  9 14 24 31 35 44 46 54


void output() {
	if (minLength != N + 1) {
		std::cout << minLength;
	} else {
		std::cout << 0;
	}
}

void solution() {
	int sum = 0;
	int left = 0, right = 1;
	while(right <= N) {
		sum = map[right] - map[left];
		// std::cout << left << ", " << right << std::endl;
		// std::cout << "sum : " << sum << std::endl;
		if (sum >= M) {
			minLength = std::min(minLength, right - left);
			 if (left < right) {
				++left;
			 } else {
				++right;
			 }
		} else {
			++right;
		}
	}
	while (left <= N) {
		sum = map[right] - map[left];
		if (sum >= M) {
			minLength = std::min(minLength, right - left);
			++left;
		} else {
			break;
		}
	}
}

void input_with_space() {
	int num;
	std::cin >> N >> M;
	minLength = N + 1;
	map = std::vector(N + 1, 0);

	map[0] = 0;
	for (int i = 1 ; i <= N ; ++i) {
		std::cin >> num;
		map[i] = map[i - 1] + num;
	}
	// for (auto m : map) {
	// 	std::cout << m << " ";
	// }
	// std::cout << std::endl;
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
