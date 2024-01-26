import numpy


def markov(gamma):
    identity = numpy.identity(7)

    p = numpy.asarray(
        [[0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.5],
         [0.0, 0.0, 0.8, 0.0, 0.2, 0.0, 0.0],
         [0.0, 0.0, 0.0, 0.4, 0.0, 0.6, 0.0],
         [0.2, 0.4, 0.4, 0.0, 0.0, 0.0, 0.0],
         [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0],
         [0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0],
         [0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.9]]
    )

    r = numpy.asarray([-2, -2, -2, -1, 10, 0, 1])

    m = identity - gamma * p
    v = numpy.linalg.inv(m) * r

    return v
