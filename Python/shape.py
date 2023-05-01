class Shape:
    def __init__(self, x, y) -> None:
        self.x = x
        self.y = y

class Rectangle(Shape):
    def __init__(self, x, y) -> None:
        super().__init__(x, y)

    def show(self):
        print('I\'m a Rectangle')

    def area(self):
        return self.x * self.y
    
class Square(Rectangle):
    def __init__(self, x) -> None:
        super().__init__(x, x)

    def show(self):
        print('I\'m a Square')

    def area(self):
        return self.x**2
    
a = Rectangle(1, 2)
a.show()
b = Square(2)
b.show()
print(b.area())