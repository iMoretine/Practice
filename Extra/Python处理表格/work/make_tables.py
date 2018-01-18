# create the tables

import sqlite3
import csv


def create_location_table(db, loc_file):
    """Location table has format ID, Room"""

    con = sqlite3.connect(db)
    cur = con.cursor()
    cur.execute('''DROP TABLE IF EXISTS Locations''')

    # create the table
    cur.execute('''CREATE TABLE Locations
    (
    ID varchar(255),
    Room varchar(255)
    )''')

    # Add the rows
    reader = csv.DictReader(loc_file)
    for row in reader:
        cur.execute('''INSERT INTO Locations VALUES ('%s','%s')'''
                    % (row['ID'], row['ROOMS...']))
        if None in row:
            for room in row[None]:
                cur.execute('''INSERT INTO Locations VALUES ('%s','%s')'''
                            % (row['ID'], room))

    # commit and close cursor and connection
    con.commit()
    cur.close()
    con.close()


def create_course_table(db, course_file):
    """Courses Table should be ID,Course,Section,Name"""

    con = sqlite3.connect(db)
    cur = con.cursor()

    cur.execute('''DROP TABLE IF EXISTS Courses''')

    # create the table
    cur.execute('''CREATE TABLE Courses 
    (
    ID varchar(255),
    Course varchar(255),
    Sections varchar(255),
    Name varchar(255)
    )''')

    # Insert the rows
    reader = csv.DictReader(course_file)
    for row in reader:
        cur.execute('''INSERT INTO Courses VALUES ('%s','%s','%s','%s')'''
                    % (row['ID'], row['Course'], row['Section'],
                       row['First Initial Last Name'].replace("'", "''")))
        if None in row:
            for name in row[None]:
                cur.execute('''INSERT INTO Courses VALUES ('%s','%s','%s','%s')'''
                            % (row['ID'], row['Course'], row['Section'],
                               name.replace("'", "''")))

    # commit and close the cursor and connection
    con.commit()
    cur.close()
    con.close()


def create_time_table(db, time_file):
    """Time Table should be ID,Date,Start,End,DurationS"""

    con = sqlite3.connect(db)
    cur = con.cursor()

    cur.execute('''DROP TABLE IF EXISTS Time''')

    # create the table
    cur.execute('''CREATE TABLE Time
    (
    ID varchar(255),
    Date varchar(255),
    Start varchar(255),
    End varchar(255),
    Duration varchar(255)
    )''')

    # insert the rows
    reader = csv.DictReader(time_file)
    for row in reader:
        cur.execute('''INSERT INTO Time VALUES ('%s','%s','%s','%s','%s')'''
                    % (row['ID'], row['Date'], row['Start Time'], row['End Time'], row['Duration']))

    # commit and close the cursor and connection
    con.commit()
    cur.close()
    con.close()


def run_query(db, q, args=None):
    """(str, str, tuple) -> list of tuple
        Return the results of running query q with arguments args on
        database db."""

    conn = sqlite3.connect(db)
    cur = conn.cursor()
    # execute the query with the given args passed
    # if args is None, we have only a query
    if args is None:
        cur.execute(q)
    else:
        cur.execute(q, args)

    results = cur.fetchall()
    cur.close()
    conn.close()
    return results


def check_courses(db):
    """Return the entire Courses table """
    return run_query(db, '''SELECT * FROM Courses''')


def check_time(db):
    """Return the entire Time table """

    return run_query(db, '''SELECT * FROM Time''')


def check_rooms(db):
    """Return the entire Locations table """

    return run_query(db, '''SELECT * FROM Locations''')


if __name__ == '__main__':
    # open the necessary files
    loc_file = open('locations.csv', 'r', encoding="utf8")
    course_file = open('courses.csv', 'r', encoding="utf8")
    time_file = open('time.csv', 'r', encoding="utf8")

    # create the tables
    create_location_table('exams.db', loc_file)
    create_course_table('exams.db', course_file)
    create_time_table('exams.db', time_file)

    # close the files
    loc_file.close()
    course_file.close()
    time_file.close()

    # test
    # print(check_rooms('exams.db'))
    # print(check_courses('exams.db'))
    # print(check_time('exams.db'))
