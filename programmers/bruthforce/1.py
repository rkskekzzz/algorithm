
# answers = [1,2,3,4,5]
# ret = [1]
answers = [1,3,2,4,2]
ret = [1,2,3]

supo1 = [1, 2, 3, 4, 5]
supo2 = [2, 1, 2, 3, 2, 4, 2, 5]
supo3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]

def solution(answers):
    answer = []
    supoCount = [0,0,0]
    for idx, aws in enumerate(answers):
      if aws == supo1[idx % len(supo1)]:
        supoCount[0] += 1
      if aws == supo2[idx % len(supo2)]:
        supoCount[1] += 1
      if aws == supo3[idx % len(supo3)]:
        supoCount[2] += 1

    for idx, cnt in enumerate(supoCount):
      if cnt == max(supoCount):
        answer.append(idx + 1)
    return answer

if solution(answers) == ret:
  print("True")
else:
  print("False")
