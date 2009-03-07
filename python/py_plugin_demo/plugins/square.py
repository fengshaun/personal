from shape import Shape, register

class Square(Shape):
    def __init__(self):
        Shape.__init__(self)
        self._fill = '*'

    def set_fill(self, f):
        self._fill = f

    def draw(self):
        print '''
        *****
        *   *
        *****'''

def register(d):
    d[Square.__name__] = Square()
