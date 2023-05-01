class Pet:
    def __init__(self, name) -> None:
        self.name = name

    def show(self):
        print(f"I'm {self.name}")

    def speak(self):
        print('I have no clue')

class Cat(Pet):
    def speak(self):
        print(super().speak())
        print("Meow")

class Dog(Pet):
    def speak(self):
        print("Bark")

cat = Cat('C')
cat.show()
cat.speak()

dog = Dog('D')
dog.show()
dog.speak()

print(isinstance(dog, Pet))