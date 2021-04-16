# leet1114

from typing import *



printFirst = lambda: print('First')
printSecond = lambda: print('Second')
printThird = lambda: print('Third')

from threading import Lock, Semaphore, Event, Thread
from queue import Queue

class Foo:
    def __init__(self):
        self.q1 = Queue()
        self.q2 = Queue()

    def first(self, printFirst: 'Callable[[], None]') -> None:
        printFirst()
        self.q1.put(0)

    def second(self, printSecond: 'Callable[[], None]') -> None:
        self.q1.get()
        printSecond()
        self.q2.put()

    def third(self, printThird: 'Callable[[], None]') -> None:
        self.q2.get()
        printThird()
 

 


foo = Foo()
tfirst = Thread(target=foo.first, args=(printFirst,))
tsecond = Thread(target=foo.second, args=(printSecond, ))
tthird = Thread(target=foo.third, args=(printThird,))
tthird2 = Thread(target=foo.third, args=(printThird,))
tthird.start()
tsecond.start()
tfirst.start()



