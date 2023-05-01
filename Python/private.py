# An underscore before mean private, for convention

# https://stackoverflow.com/a/7456865/16461323

class A:
    _name = 'Hi'
    def __init__(self, name) -> None:
        self._name = name
    def show(self):
        print(self._name)

    def set(self, name):
        self._name = name

a = A('Hi')
a.show()
a.name = 'Hello' #icant
a.show()
a.set('Hello')
a.show() #sogud