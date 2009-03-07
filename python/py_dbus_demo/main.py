import dbus
from dbus.mainloop.glib import DBusGMainLoop

dbus_loop = DBusGMainLoop()

bus = dbus.SessionBus(mainloop = dbus_loop)

'''
# playing with krunner a little bit
krunner_mainapp = bus.get_object('org.kde.krunner', '/MainApplication')

krunner_mainapp_iface = dbus.Interface(krunner_mainapp, 'org.kde.krunner.App')
krunner_mainapp_iface.query('qdbusinterface')

krunner_ssaver = bus.get_object('org.kde.krunner', '/ScreenSaver')
krunner_ssaver_freedesktop_iface = dbus.Interface(krunner_ssaver,
                                                  'org.freedesktop.ScreenSaver')
krunner_ssaver_freedesktop_iface.SetActive(True)
'''
# and demoing signals.  Needs loops
kmail = bus.get_object('org.kde.kmail', '/KMail')
kmail_iface = dbus.Interface(kmail, 'org.kde.kmail.kmail')

def kmail_signal_handler(sender = None):
    print 'gotsignal from %r' % sender

kmail_iface.connect_to_signal('unreadCountChanged', kmail_signal_handler,
                               sender_keyword = 'sender')

