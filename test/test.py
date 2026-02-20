#!/usr/bin/python3.12

import ctypes
import unittest

mylib = ctypes.CDLL('./libtest.so')
mylib.square.restype = ctypes.c_int
mylib.square.argtypes = [ctypes.c_int]

class SquareTest(unittest.TestCase):
   def test_square_positive(self):
      self.assertEqual(mylib.square(2), 4)
      self.assertEqual(mylib.square(0), 0)
      self.assertEqual(mylib.square(42), 1764)

   def test_square_negative(self):
      self.assertEqual(mylib.square(-3), 9)

if __name__ == '__main__':
   unittest.main()
