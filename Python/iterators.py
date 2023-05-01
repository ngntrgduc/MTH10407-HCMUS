class A:
    def __init__(self) -> None:
        pass

    def __iter__(self):
        self.number = 1
        return self
    
    def __next__(self):
        if self.number < 3:
            x = self.number
            self.number += 1
            return x
        else:
            raise StopIteration

a = A()
i = iter(a)

print(next(i))
print(next(i))
print(next(i))
print(next(i))