numbers = [3, 30, 34, 5, 9]

def solution(numbers):
    answer = ''
    print(sorted(map(str, numbers), reverse=True))
    # print(''.join())

    return answer

print(solution(numbers))
