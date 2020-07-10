import pybind11_openmp
import time

class Generator(pybind11_openmp.IGenerator):

    def compute(self, i):
        time.sleep(0.1)
        return i

gen = Generator()
pybind11_openmp.Matrix(10,gen)