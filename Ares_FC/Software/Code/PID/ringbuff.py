
class Ringbuffer:
    def __init__(self, members) -> None:
        self.buff: list = [0.0 for i in range(members)]
        self.nextIndex: int = 0
        self.MAXMEMBERS = members

    def __getitem__(self, index):
        # Called to retrieve an item from the list
        return self.buff[index]

    def __str__(self) -> str:
        return str([round(value, 2) for value in self.buff])

    def add(self, num: float) -> int:
        self.buff[self.nextIndex] = num
        self.nextIndex = (self.nextIndex + 1) % self.MAXMEMBERS
        # return index of newest value
        return self.nextIndex - 1

    def getNewestValueIndex(self) -> int:
        return self.nextIndex - 1


if __name__ == "__main__":
    r = Ringbuffer(5)
    print(r[3])

    for i in range(100):
        r.add(i)
        print(r)
    print(r[4])
