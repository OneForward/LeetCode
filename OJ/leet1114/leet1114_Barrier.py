# leet1114

from typing import *



printFirst = lambda: print('First')
printSecond = lambda: print('Second')
printThird = lambda: print('Third')

from threading import Lock, Semaphore, Event, Thread, Barrier


class Foo:
    def __init__(self):
        self.b1 = Barrier(2)
        self.b2 = Barrier(2)

    def first(self, printFirst: 'Callable[[], None]') -> None:
        printFirst()
        self.b1.wait()

    def second(self, printSecond: 'Callable[[], None]') -> None:
        self.b1.wait()
        printSecond()
        self.b2.wait()

    def third(self, printThird: 'Callable[[], None]') -> None:
        self.b2.wait()
        printThird()
 

 


foo = Foo()
tfirst = Thread(target=foo.first, args=(printFirst,))
tsecond = Thread(target=foo.second, args=(printSecond, ))
tthird = Thread(target=foo.third, args=(printThird,))
tthird2 = Thread(target=foo.third, args=(printThird,))
tthird.start()
tsecond.start()
tfirst.start()



