# class Dataset:
#     def __init__(self, data):
#         self.data = data
#         self.elements = 0

#     def __iter__(self):
#         return self.data[0]

#     def __next__(self, batch: int = 0):
#         if batch > 0:
#             self.elements = self.elements + batch
#             return self.data[self.elements : self.elements + batch]
#         else:
#             self.elements = self.elements + 1
#             return self.data[self.elements]

# def model(n):
#     print(n)

# dataset = Dataset([1, 2, 3, 4, 0])


# for batch in dataset:
#     # model(batch)
#     print(batch)

class Iterator:
    def __init__(self) -> None:
        pass
