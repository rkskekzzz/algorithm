#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<std::pair<int, int> > map;
std::vector<std::pair<int, int> > results;

void output() {
	std::cout << results.size();
}

void print(std::vector<std::pair<int, int> > target) {
	std::cout << std::endl;
	for (auto m : target) {
		std::cout << m.first << " " << m.second << std::endl;
	}
}

bool comp(std::pair<int, int> a, std::pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

void solution() {
	std::sort(map.begin(), map.end(), comp);
	// print(map);
	for (auto m : map) {
		if (results.size() == 0) {
			results.push_back(m);
			continue;
		}
		if (results[results.size() - 1].second <= m.first) {
			results.push_back(m);
		}
	}
	// print(results);
}

void input_with_space() {
	std::cin >> N;
	int a, b;
	for (int i = 0 ; i < N ; ++i) {
		std::cin >> a >> b;
		map.push_back({a, b});
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
