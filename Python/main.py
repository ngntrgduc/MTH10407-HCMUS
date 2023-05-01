class Hello:
    def __init__(self, name) -> None:
        self.name = name

    def __str__(self):
        return f'name is {self.name}'

    def __repr__(self):
        return f"Hello('{self.name}')"

    def hello(self):
        print(f"Hello {self.name}")

    def set(self, name):
        self.name = name

bruh = Hello('World')
bruh.hello()
bruh.set('bruh')
bruh.hello()
bruh.name = 'World'
bruh.hello()
print(bruh) # = print(str(bruh)) 
print(repr(bruh))