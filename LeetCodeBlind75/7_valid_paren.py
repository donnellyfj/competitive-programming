# 20. Valid Parentheses
def isValid(self, s: str) -> bool:
    stack = []
    for i in s:
        if i in ['(', '[', '{']:
            stack.append(i)
        elif len(stack) > 0:
            if i == ')':
                if stack[-1] == '(':
                    stack.pop()
                else:
                    return False
            elif i == ']':
                if stack[-1] == '[':
                    stack.pop()
                else:
                    return False
            elif stack[-1] == '{':
                    stack.pop()
            else:
                return False
        else:
            return False

    return stack == []
