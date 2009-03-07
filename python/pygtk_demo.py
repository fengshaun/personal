import pygtk
import gtk

class HelloWorld:
    def __init__(self):
        print 'HelloWorld.__init__()'
        self.__window = gtk.Window(gtk.WINDOW_TOPLEVEL)
        self.__window.set_border_width(10)
        self.__window.connect('destroy', self.destroy)
        self.__btn = gtk.Button('Hello World')
        self.__btn.connect('clicked', self.sayHello)
        self.__window.add(self.__btn)
        self.__btn.show()
        self.__window.show()

    def __del__(self):
        print "I'm being destroyed!"

    def sayHello(self, widget, data=None):
        print 'Hello World from pyGTK!'

    def destroy(self, widget, data=None):
        print 'gtk.main_quit()'
        gtk.main_quit()

    def main(self):
        print 'HelloWorld.main()'
        gtk.main()

if __name__ == '__main__':
    h = HelloWorld()
    h.main()
