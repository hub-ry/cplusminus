class MyQueue:

    def __init__(self):
        self.out = []
        self.input = []

    def push(self, x: int) -> None:
        # move current stack to output and put the new val at the base
        while self.out:
            self.input.append(self.out.pop())
        self.input.append(x)
        while self.input:
            self.out.append(self.input.pop())

    def pop(self) -> int:
        return self.out.pop()

    def peek(self) -> int:
        return self.out[-1]

    def empty(self) -> bool:
        return not self.out


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()