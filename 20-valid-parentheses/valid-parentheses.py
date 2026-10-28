class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for op in s:
            if op in "([{":
                stack.append(op)
            else:
                if stack:
                    if stack[-1] == '{' and op == '}':
                        stack.pop()
                    elif stack[-1] == '(' and op == ')':
                        stack.pop()
                    elif stack[-1] == '[' and op == ']':
                        stack.pop()
                    else:
                        return False
                else:
                    return False
        return len(stack) == 0
        