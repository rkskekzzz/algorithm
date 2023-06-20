#include <iostream>
#include <vector>

#define MAX 1000000000

long long X, Y, result;

void output() {


}

long long win_rate(long long x, long long y) {
	return (y * 100) / x;
}

void solution() {
	long long left = 0;
	long long right = MAX;
	long long mid;
	int destination = win_rate(X, Y) + 1;
	// std::cout << destination << std::endl;
	if (destination >= 100) {
		std::cout << -1;
		return;
	}
	while (left <= right) {
		mid = (left + right) / 2;
		int source = win_rate(X + mid, Y + mid);
		// std::cout << "s : " << source << std::endl;
		if (source >= destination) {
			right = mid - 1;
		} else {
			result = mid + 1;
			left = mid + 1;
		}
	}
	std::cout << result;
}

void input_with_space() {
	std::cin >> X >> Y;
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
