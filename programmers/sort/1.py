# k번째수
array = [1, 5, 2, 6, 3, 7, 4]
commands = [[2, 5, 3], [4, 4, 1], [1, 7, 3]]

def solution(array, commands):
    answer = []
    for command in commands:
      answer.append(sorted(array[command[0] - 1:command[1]])[command[2] - 1])
    return answer


answer = solution(array, commands)

if answer == [5, 6, 3]:
  print("True")
else:
  print("False")
