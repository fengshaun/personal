##########################################################################
# implement HTTP web server in Python which knows how to serve HTML
# pages and run server-side CGI scripts;  serves files/scripts from
# the current working dir and port 80, unless command-line args;
# Python scripts must be stored in webdir\cgi-bin or webdir\htbin;
# more than one of these may be running on the same machine to serve
# from different directories, as long as they listen on different ports;
#########################################################################

webdir = '.'   # where your HTML files and cgi-bin script directory live
port   = 80    # http://servername/ if 80, else use http://servername:xxxx/

import os, sys
from BaseHTTPServer import HTTPServer
from CGIHTTPServer  import CGIHTTPRequestHandler

if len(sys.argv) > 1: webdir = sys.argv[1]             # command-line args
if len(sys.argv) > 2: port   = int(sys.argv[2])        # else default ., 80
print 'webdir "%s", port %s' % (webdir, port)

# hack for Windows: os.environ not propagated
# to subprocess by os.popen2, force in-process
if sys.platform[:3] == 'win':
    CGIHTTPRequestHandler.have_popen2 = False
    CGIHTTPRequestHandler.have_popen3 = False          # emulate path after fork
    sys.path.append('cgi-bin')                         # else only adds my dir

os.chdir(webdir)                                       # run in HTML root dir
srvraddr = ("", port)                                  # my hostname, portnumber
srvrobj  = HTTPServer(srvraddr, CGIHTTPRequestHandler)
srvrobj.serve_forever( )                                # serve clients till exit
