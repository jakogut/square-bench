import time
import random

COUNT = 32000000

def test(mat):
    s = 0
    for i in mat:
        s += (i ** 2)
    return s

if __name__ == '__main__':
    mat = [random.random() for _ in range(COUNT)]

    start = time.time()
    result = test(mat)
    end = time.time()

    print(f'Result: {result}')
    print(f'Completed in {(end - start) * 1000} ms')
