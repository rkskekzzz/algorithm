#include <iostream>
#include <vector>
#include <algorithm>
int N;
std::vector<int> array;
std::vector<int> sum;

void output() {

}

void solution() {
	for (int i = 0 ; i < N - 1 ; ++i) {
		for (int j = 0 ; j < N - 1; ++j) {
			sum.push_back(array[i] + array[j]);
		}
	}
	std::sort(array.begin(), array.end());
	std::sort(sum.begin(), sum.end());

	for (int i = N - 1 ; i >= 0 ; --i) {
		for (int j = i ; j >= 0 ; --j) {
			int remain = array[i] - array[j];
			bool res = std::binary_search(sum.begin(), sum.end(), remain);
			if (res) {
				std::cout << array[i];
				return;
			}
		}
	}

}

void input_with_space() {
	std::cin >> N;
	for (int i = 0 ; i < N ; ++i) {
		int num;
		std::cin >> num;
		array.push_back(num);
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
