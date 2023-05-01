class A:
    def __init__(self, x=None) -> None:
        self._x = x

    def __get__(self):
        return self._x
    
    def __set__(self, n):
        self._x = n

a = A()
a.x = 2 # set
print(a.x) # get