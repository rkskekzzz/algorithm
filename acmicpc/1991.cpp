#include <iostream>
#include <vector>

int N;
struct node {
	char left;
	char right;
};

std::vector<node> map(26);



void preOrder(char node) {
	if (node == '.') return;

	std::cout << node;
	preOrder(map[node].left);
	preOrder(map[node].right);
}

void inOrder(char node) {
	if (node == '.') return;

	inOrder(map[node].left);
	std::cout << node;
	inOrder(map[node].right);
}

void postOrder(char node) {
	if (node == '.') return;

	postOrder(map[node].left);
	postOrder(map[node].right);
	std::cout << node;
}

void output() {
	preOrder('A');
	std::cout << std::endl;
	inOrder('A');
	std::cout << std::endl;
	postOrder('A');
}

void input_with_space() {
	std::cin >> N;
	for (int i = 0 ; i < N ; ++i) {
		char ch, left, right;
		std::cin >> ch >> left >> right;
		map[ch].left = left;
		map[ch].right = right;
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
	output();
}
