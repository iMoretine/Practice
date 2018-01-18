import csv
import numpy as np
import matplotlib.pyplot as plt


def read_data(filename):
    data = dict()
    with open(filename, mode='r', encoding='utf-8') as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            student_list = list()
            for i in row:
                if row[i] != '':
                    student_list.append((i, row[i]))
            student_list = [row['Name']] + student_list[2:]
            data[row['ID']] = student_list
    return data


def bar_chart(student):
    name = student[0]
    modules = [i[0] for i in student[1:]]
    marks = [i[1] for i in student[1:]]
    N = len(student) - 1

    ind = np.arange(N)  # the x locations for the groups
    width = 0.9  # the width of the bars

    fig, ax = plt.subplots()
    ax.bar(ind, marks, width, color='b')

    # add some text for labels, title and axes ticks
    ax.set_title('Term 1 Performance for %s' % name)
    ax.set_xlabel('Modules')
    ax.set_ylabel('Mark')
    ax.set_xticks(ind)
    ax.set_xticklabels(modules)

    plt.show()
    pass


def scatter_plot(data, module):
    module_mark = []
    other_modules_average = []
    for ID in data:
        average = 0
        flag = False
        student = data[ID]
        for j in student[1:]:
            if j[0] == module:
                module_mark.append(j[1])
                flag = True
            else:
                average += int(j[1])
        if flag:
            average = average / float(len(student) - 2)
            other_modules_average.append(average)

    x = np.array(module_mark)
    y = np.array(other_modules_average)

    plt.scatter(x, y, marker='.', color='k', alpha=0.5)

    plt.plot([0, 100], [0, 100])

    # add some text for labels, title and axes ticks
    plt.title('Term 1 Performance for %s' % module)
    plt.xlabel('Module mark')
    plt.ylabel('Average in other modules')

    plt.show()
    pass


def choose():
    op_str = "Foundation Year Student Information System\n" \
             "Please choose one of:\n" \
             "1 - display student's marks\n" \
             "2 - display scatter plot of module's mark\n" \
             "3 - exit the system\n" \
             "Your choice?"
    print(op_str)
    c = input()
    while c != "" and c[0] not in ['1', '2', '3']:
        print("Invalid option, enter again.")
        print(op_str)
        c = input()
    return c[0]


if __name__ == '__main__':
    data = read_data('module_marks.csv')
    while True:
        c = choose()
        if c == '1':
            print("Please enter student ID number?")
            ID = input()
            while ID not in data:
                print("Invalid student ID number, enter again.")
                ID = input()
            bar_chart(data[ID])
        if c == '2':
            print("Please enter module?")
            module = input()
            while module not in ["module%d" % i for i in range(1,8)]:
                print("Invalid module name, enter again.")
                module = input()
            scatter_plot(data, module)
        if c == '3':
            print("End")
            exit()
    pass