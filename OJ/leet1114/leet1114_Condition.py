# leet1114

from typing import *


import threading
from multiprocessing import pool 

printFirst = lambda: print('First')
printSecond = lambda: print('Second')
printThird = lambda: print('Third')

class Foo:
    def __init__(self):
        self.cv = threading.Condition()
        self.t = 0

    def first(self, printFirst: 'Callable[[], None]') -> None:
        self.res(0, printFirst)

    def second(self, printSecond: 'Callable[[], None]') -> None:
        self.res(1, printSecond)

    def third(self, printThird: 'Callable[[], None]') -> None:
        self.res(2, printThird)
        
    def res(self, val: int, func: 'Callable[[], None]') -> None:
        with self.cv:
            self.cv.wait_for(lambda: val == self.t) #参数是函数对象，返回值是bool类型
            func()
            self.t += 1
            self.cv.notify_all()
 


foo = Foo()
tfirst = threading.Thread(target=foo.first, args=(printFirst,))
tsecond = threading.Thread(target=foo.second, args=(printSecond, ))
tthird = threading.Thread(target=foo.third, args=(printThird,))
tthird2 = threading.Thread(target=foo.third, args=(printThird,))
tthird.start()
tsecond.start()
tfirst.start()



