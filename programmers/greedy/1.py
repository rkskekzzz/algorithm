# 5	[2, 4]	[1, 3, 5]	5
# 5	[2, 4]	[3]	4
# 3	[3]	[1]	2

n = 5
lost = [2, 4]
reserve = [1, 3, 5]
answer = 5

# n = 5
# lost = [1, 2, 3]
# reserve = [4, 5]
# answer = 3

n = 3
lost = [1, 2]
reserve = [2, 3]
answer = 2

def solution(n, lost, reserve):
    newReserve = [r for r in reserve if r not in lost]
    newLost = [l for l in lost if l not in reserve]

    newReserve.sort()
    newLost.sort()

    for l in newReserve:
      if l - 1 in newLost:
        newLost.remove(l - 1)
      elif l + 1 in newLost:
        newLost.remove(l + 1)

    return n - len(newLost)

if solution(n, lost, reserve) == answer:
  print("True")
else:
  print("False")
