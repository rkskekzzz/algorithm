#include <iostream>
#include <vector>

int N, connections, count = 0;
std::vector<int> list[101];
bool visited[101];

void print() {
	std::cout << "\n";
	for (auto e : list) {
		if (e.size() == 0) continue;
		for (auto atom : e) {
			std::cout << atom << " ";
		}
		std::cout << "\n";
	}
}

void output() {
	std::cout << count;
}

void solution(int idx) {
	visited[idx] = true;
	for (auto cpu : list[idx]) {
		if (!visited[cpu]) {
			solution(cpu);
			++count;
		}
	}
}

void input_with_space() {
	std::cin >> N;
	std::cin >> connections;
	for (int i = 0 ; i < connections ; ++i) {
		int cpu_first, cpu_second;
		std::cin >> cpu_first >> cpu_second;
		list[cpu_first].push_back(cpu_second);
		list[cpu_second].push_back(cpu_first);
	}
	// print();
}

void preset() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

int main() {
	preset();
	input_with_space();
	solution(1);
	output();
}
