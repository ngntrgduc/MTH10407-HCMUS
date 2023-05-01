class A:
    def __init__(self) -> None:
        pass

    def __init_subclass__(cls) -> None:
        print(f'A subclass {cls} of class A was created')

class B(A):
    def __init__(self) -> None:
        pass