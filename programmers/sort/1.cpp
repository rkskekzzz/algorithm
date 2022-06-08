// k번쨰수
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (auto i = commands.begin() ; i != commands.end() ; ++i) {
      vector<int> newArray;
      newArray.resize((*i)[1] - (*i)[0] + 1);
      copy(array.begin() + (*i)[0] - 1, array.begin() + (*i)[1], newArray.begin());
      sort(newArray.begin(), newArray.end());
      answer.push_back(newArray[(*i)[2] - 1]);
    }
    return answer;
}

int main() {
  vector<int> array = {1, 5, 2, 6, 3, 7, 4};
  vector<vector<int>> commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};;
  vector<int> answer = solution(array, commands);

  for (auto i : answer) {
    cout << i << " ";
  }
}
