class Solution:
    def calPoints(self, operations: list[str]) -> int:
        stack = []
        sum = 0
        for i in operations:
            if i == '+':
                num = stack[-1] + stack[-2]
                stack.append(num)
                sum += num
            elif i == 'D':
                num = stack[-1]
                stack.append(num * 2)
                sum += stack[-1]
            elif i == 'C':
                num = stack.pop()
                sum -= num
            else:
                num = int(i)
                stack.append(num)
                sum += num
        return sum
        