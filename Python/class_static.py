class A:
    def __init__(self) -> None:
        pass

    def hi(self, x):
        print(f'Hi({x})')

    # can modify class state that applies across all instances of the class
    @classmethod
    def class_method(cls, x):
        print(f'classmethod({cls}, {x})')

    # neither modify object state nor class state
    @staticmethod
    def static_method(x):
        print(f'staticmethod({x})')

a = A()
a.hi(0)
a.class_method(1)
a.static_method(2)