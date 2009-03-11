#!/usr/bin/python

import cgi

form = cgi.FieldStorage()

print 'Content-type: text/html\n'
print '<title>Reply Page</title>'

if not form.has_key('user'):
    print '<h1>Who are you?</h1>'
else:
    print '<h1>Hello %s</h1>' % cgi.escape(form['user'].value)
