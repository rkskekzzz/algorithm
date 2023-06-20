const permutations = (lines: string[], size: number): string[][] => {
  const result: string[][] = []
  if (size === 1) return lines.map((character) => [character])

  for (let index = 0 ; index < lines.length ; ++index) {
      const rest = [...lines.slice(0, index), ...lines.slice(index + 1)];
      const permutation = permutations(rest, size - 1);
      const attached = permutation.map((el) => [lines[index], ...el])
      result.push(...attached);
  }
  return result;
}

const calculateB = (s: string[]) => {
  return s.reduce((acc, cur) => {
      acc.push(cur)
      acc.reverse();
      return acc;
  }, [])
}

const sortByB = (a: string, b: string): number => {
  return a > b ? -1 : 1;
}

function solution(s: string): string {
  // Write your code here
  const sPermutations = permutations(s.split(''), s.length);
  const results = sPermutations.map((sPermutation) => {
          return { b : calculateB(sPermutation).join('') , s : sPermutation.join('') }
      }

  )
  results.sort((result1, result2) => sortByB(result1.b, result2.b));
  return results[0].s
}



def dfs(visited, student, arr):
    val = 0
    for index, _ in enumerate(arr[student]):
        if visited[index] == False and arr[student][index] == 1:
            visited[index] = True
            val += dfs(visited, index, arr) + 1
    return val


def getGroupSize(student, arr):
    visited = [False for _ in range(len(arr) + 1)]
    visited[student] = True
    return dfs(visited, student, arr) + 1


def solution(n, queryType, students1, students2):
    result = []
    arr = [[0] * (n + 1)  for _ in range(n + 1)]
    for i in range(len(queryType)):
        if queryType[i] == "Friend":
            arr[students1[i]][students2[i]] = 1
            arr[students2[i]][students1[i]] = 1
        if queryType[i] == "Total":
            result.append(getGroupSize(students1[i], arr) + getGroupSize(students2[i], arr))
    return result
