class A:
    def __init__(self):
        self._x = None

    # Getter
    @property
    def x(self):
        """x property"""
        print('Getter called')
        return self._x
        
    @x.setter
    def x(self, n):
        print('Setter called')
        if n < 0:
            self._x = 0
        else:
            self._x = n

    @x.deleter
    def x(self):
        print('Deleter called')
        del self._x

a = A()
print(a)
print(a.x)

a.x = -2
print(a.x)

a.x = 2
print(a.x)
