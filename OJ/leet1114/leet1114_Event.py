# leet1114

from typing import *



printFirst = lambda: print('First')
printSecond = lambda: print('Second')
printThird = lambda: print('Third')

from threading import Lock, Semaphore, Event, Thread


class Foo:
    def __init__(self):
        self.e1 = Event()
        self.e2 = Event()

    def first(self, printFirst: 'Callable[[], None]') -> None:
        printFirst()
        self.e1.set()

    def second(self, printSecond: 'Callable[[], None]') -> None:
        self.e1.wait()
        printSecond()
        self.e2.set()

    def third(self, printThird: 'Callable[[], None]') -> None:
        self.e2.wait()
        printThird()
 

 


foo = Foo()
tfirst = Thread(target=foo.first, args=(printFirst,))
tsecond = Thread(target=foo.second, args=(printSecond, ))
tthird = Thread(target=foo.third, args=(printThird,))
tthird2 = Thread(target=foo.third, args=(printThird,))
tthird.start()
tsecond.start()
tfirst.start()



