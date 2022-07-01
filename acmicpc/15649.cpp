#include <iostream>
#include <vector>
#include <string>

// std::vector<int> temp;
int N, M;
int temp[9];
bool used[9];

void req(int depth)
{
  if (depth == M)
  {
    for (int i = 1; i <= M; i++) {
      std::cout << temp[i] << " ";
    }
    std::cout << '\n';
    return;
  }
  ++depth;
  for (int i = 1 ; i <= N ; ++i) {
    if(used[i] == false) {
      used[i] = true;
      temp[depth] = i;
      req(depth);
      used[i] = false;
    }
  }
}

void solution()
{
  req(0);
}

void input()
{
  std::cin >> N >> M;
}


void preset()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

int main()
{
  preset();
  input();
  solution();
}
