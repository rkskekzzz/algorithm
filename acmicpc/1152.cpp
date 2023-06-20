#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::string str;
std::vector<std::string> array;
int n;

void output() {
	std::cout << array.size();
}

void split(std::string input, char delimiter) {
    std::stringstream ss(input);
    std::string temp;

    while (getline(ss, temp, delimiter)) {
		if (temp.length() != 0)
        	array.push_back(temp);
    }
}

void solution() {
	split(str, ' ');
}

void input_with_space() {
	std::getline(std::cin, str);
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
