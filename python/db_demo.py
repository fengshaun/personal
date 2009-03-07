import sqlite3 as db
import sys

conn = db.connect('/home/armin/db_demo_py.db')
cur = conn.cursor()

def create_table():
    cur.execute("""create table people
                   (name char(30),
                   job char(20),
                   pay int(6))""")

def fill_table():
    cur.execute('insert into people values (?, ?, ?)',
                ('Reza', 'App-dev', 60000))
    cur.execute('insert into people values (?, ?, ?)',
                ('Mohammad', 'Engineer', 70000))

def get_info():
    cur.execute('select * from people')
    return cur.fetchall()

if __name__ == '__main__':
    cur.execute('select name from SQLITE_MASTER where type=?', ('table',))
    if 'people' not in [name[0] for name in cur.fetchall()]:
        create_table()

    cur.execute('select * from people')
    t = cur.fetchall()
    if not t:
        # empty database
        fill_table()

    for (name, job, pay) in get_info():
        print name, job, pay
