# leet1114

from typing import *


import threading
from multiprocessing import pool 

printFirst = lambda: print('First')
printSecond = lambda: print('Second')
printThird = lambda: print('Third')

from threading import Lock, Semaphore

class Foo:
    def __init__(self):
        self.P12 = Semaphore(0)
        self.P23 = Semaphore(0)

    def first(self, printFirst: 'Callable[[], None]') -> None:
        printFirst()
        self.P12.release()

    def second(self, printSecond: 'Callable[[], None]') -> None:
        with self.P12:
            printSecond()
            self.P23.release()

    def third(self, printThird: 'Callable[[], None]') -> None:

        with self.P23:
            printThird()


 


foo = Foo()
tfirst = threading.Thread(target=foo.first, args=(printFirst,))
tsecond = threading.Thread(target=foo.second, args=(printSecond, ))
tthird = threading.Thread(target=foo.third, args=(printThird,))
tthird2 = threading.Thread(target=foo.third, args=(printThird,))
tthird.start()
tsecond.start()
tfirst.start()



