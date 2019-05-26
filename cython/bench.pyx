cpdef double test(double[:] mat):
    cdef double s = 0
    cdef unsigned size = mat.shape[0]

    for i in range(size):
        s += (mat[i] ** 2)
    return s

