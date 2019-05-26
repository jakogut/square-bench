import time
import numpy

import pyximport; pyximport.install()
import bench

COUNT = 32000000

if __name__ == '__main__':
    mat = numpy.random.rand(COUNT)

    start = time.time()
    result = bench.test(mat)
    end = time.time()

    print(f'Result: {result}')
    print(f'Completed in {(end - start) * 1000} ms')

