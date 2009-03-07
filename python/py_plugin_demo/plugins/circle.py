from shape import Shape, register

class Circle(Shape):
    def __init__(self):
        Shape.__init__(self)

    def set_fill(self, c):
        self.__fill = c

    def draw(self):
        print '''
         ****
        *    *
        *    *
         ****
        '''

def register(d):
    d[Circle.__name__] = Circle()
