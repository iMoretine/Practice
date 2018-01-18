import sqlite3


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


def get_course_instructors(db, course):
    """Return the Course number, sections and instructors for the given course number.
    :param db: Data base file.
    :param course: Course number.
    :return: A list of tuples, each tuple contains the course number, sections and instructors.
    """
    result = run_query(db, '''SELECT Course,Sections,Name FROM Courses WHERE Course = "%s"''' % course)
    return result


def get_course_time(db, course):
    """Return the course number, ID, the date and start time of the given
    course's exam for all sections.
    Note there are only multiple sections if the course IDs are different.
    :param db: Data base file.
    :param course: Course number.
    :return: A list of tuples, each tuple contains the course number, ID, the date and start time.
    """
    result = run_query(db, '''SELECT DISTINCT Courses.ID, Courses.Course, Courses.Sections, Time.Date, Time.Start
                                FROM Courses, Time 
                                WHERE Courses.Course = "%s"
                                AND Courses.ID = Time.ID''' % course)
    return result


def get_course_time_section(db, course, section):
    """
    Return the course number, section, the date and start time of the given course's exam.
    :param db: Data base file.
    :param course: Course number.
    :param section: section.
    :return: A list of tuples, each tuple contains the course number, section, the date and start time.
    """
    result = run_query(db, '''SELECT DISTINCT Courses.Course, Courses.Sections, Time.Date, Time.Start
                                FROM Courses, Time 
                                WHERE Courses.Course = "%s"
                                AND Courses.Sections = "%s"
                                AND Courses.ID = Time.ID''' % (course, section))
    return result


def courses_multi_instructors(db):
    """Return the course number and instructor names for courses with more
    than one instructor. Note that this means the ID must be
    the same for each instructor.
    :param db: Data base file.
    :return: A list of tuples, each tuple contains the course number and instructor names.
    """
    result = run_query(db, '''SELECT Course, Name FROM Courses WHERE ID IN 
                                (SELECT ID FROM Courses GROUP BY ID HAVING COUNT(ID) >= 2)''')
    return result


def courses_how_many_instructors(db):
    """Return the course number and the number of instructors for courses with more
    than one instructor. Note that this means the ID must be
    the same for each instructor.
    :param db: Data base file.
    :return: A list of tuples, each tuple contains the course number and the number of instructors.
    """
    result = run_query(db, '''SELECT Course, COUNT(ID) FROM Courses GROUP BY ID HAVING COUNT(ID) >= 2''')
    return result


def find_dept_courses(db, dept):
    """Return the courses from the given department.  Use  the "LIKE"
    clause in your SQL query for the course name.
    :param db: Data base file.
    :param dept: department of course.
    :return: A list of tuples, each tuple contains the course.
    """
    result = run_query(db, "SELECT Course FROM Courses WHERE Course LIKE '%"+dept+"%'")
    return result


def get_locations(db, course):
    """Return the course, section and locations of the exam for the given course.
    :param db: Data base file.
    :param course: Course number.
    :return: A list of tuples, each tuple contains the course, section and locations of the exam/
    """
    result = run_query(db, '''SELECT DISTINCT Courses.Course, Courses.Sections, Locations.Room
                                FROM Courses, Locations 
                                WHERE Courses.Course = "%s"
                                AND Courses.ID = Locations.ID''' % course)
    return result


# challenge!
def check_conflicts(db, course):
    """Return  a list of course numbers of courses that have conflicts with the given course.
    A conflict is the same date and same start time.
    HINT: this may require more than one search.
    :param db: Data base file.
    :param course: Course number.
    :return:
    """
    exam_time = run_query(db, '''SELECT DISTINCT Date,Start FROM Time WHERE ID IN 
                            (SELECT ID FROM Courses WHERE Course = "%s")''' % course)
    result = []
    for time in exam_time:
        result += run_query(db, '''SELECT DISTINCT Course FROM Courses WHERE ID IN 
                                (SELECT ID FROM Time WHERE Date = "%s" AND Start = "%s")''' % (time[0], time[1]))
    return result


if __name__ == '__main__':
    # write your program here
    # you may assume the database has been made and has the name
    # DO NOT CHANGE THIS LINE
    db = 'exams.db'

    course = input("Please enter your course or return to quit. ")
    if course == "":
        exit()
    while True:
        while not get_course_time(db, course):
            course = input("Not a valid course code, please re-enter or return to quit.")
            if course == "":
                exit()

        course_time_list = get_course_time(db, course)

        if len(course_time_list) > 1:
            section_dict = {i[2]:i for i in course_time_list}
            section = input("There are multiple sections of %s. What is your section?" % course)
            while section not in section_dict:
                section = input("Not a valid section, please re-enter or return to quit.")
                if section == "":
                    exit()
            course_time = section_dict[section]
            print("Course %s section %s has exam on %s at %s. "
                  % (course_time[1], course_time[2], course_time[3], course_time[4]))
        else:
            course_time = course_time_list[0]
            print("Course %s has exam on %s at %s."
                  % (course_time[1], course_time[3], course_time[4]))

        course = input("Please enter the next course or return to quit. ")
        if course == "":
            exit()

    # Function test.
    # print(get_course_instructors(db, "STAB22H3F"))
    # print(get_course_time(db, "STAB22H3F"))
    # print(get_course_time_section(db, "STAB22H3F", "LEC01"))
    # print(courses_multi_instructors(db))
    # print(courses_how_many_instructors(db))
    # print(find_dept_courses(db, "B57"))
    # print(get_locations(db, "STAB22H3F"))
    # print(check_conflicts(db, "ANTA01H3F"))

