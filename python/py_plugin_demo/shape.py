class Shape:
    def __init__(self):
        self._fill = '*'
        
    def set_fill(self, f):
        self._fill = f

    def draw(self):
        assert 0, 'Shape.draw() has to be implemented'

def register(d):
    assert 0, 'register has to be implemented'
