#include <iostream>
#include <vector>
#include <algorithm>

long long N, M, ans;
std::vector<int> bosuk;

void output() {

}

long long cut(int mid) {
	long long count = 0;
	for (size_t i = 0 ; i < bosuk.size() ; ++i) {
		if (bosuk[i] <= mid) {
			++count;
		} else {
			count += (bosuk[i] - 1) / mid + 1;
		}
	}
	return count;
}

void solution() {
	std::sort(bosuk.begin(), bosuk.end());
	int bottom = 1, mid;
	int top = bosuk[bosuk.size() - 1], ans = bosuk[bosuk.size() - 1];

	while (bottom <= top) {
		mid = (bottom + top) / 2;
		long long count = cut(mid);

		if (count > N) {
			bottom = mid + 1;
		} else {
			top = mid - 1;
			ans = std::min(ans, mid);
		}
	}
	std::cout << ans;
}

void input_with_space() {
	std::cin >> N >> M;
	for (int i = 0 ; i < M ; ++i) {
		int count;
		std::cin >> count;
		bosuk.push_back(count);
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
