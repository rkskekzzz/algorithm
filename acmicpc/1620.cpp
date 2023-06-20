#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int N, M;
std::vector<std::string> map;
std::map<std::string, int> map_map;
std::vector<std::string> results;

void output() {
	// for (auto r : results) {
	// 	std::cout << r << "\n";
	// }
}

bool isNumber(const std::string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

void solution() {
	for (int i = 0 ; i < M ; ++i) {
		std::string input;
		std::cin >> input;
		if (isNumber(input)) {
			std::cout << map[std::stoi(input)- 1] << "\n";
			// results.push_back(map[std::stoi(input)- 1]);
		} else {
			std::cout << (*map_map.find(input)).second << "\n";
			// results.push_back(std::to_string((*map_map.find(input)).second));
		}
	}
}

void input_with_space() {
	std::cin >> N >> M;
	for (int i = 0 ; i < N ; ++i) {
		std::string name;
		std::cin >> name;
		map.push_back(name);
		map_map.insert({name, i + 1});
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
