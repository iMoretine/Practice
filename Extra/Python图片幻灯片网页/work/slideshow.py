import csv
import webbrowser


def read_file(myfile):
    '''(file) -> str
    Read the open file and return as a string.'''
    all_text = myfile.read()
    return all_text


def get_header(s):
    '''(str) -> str
    Return the start of the given string upto and including
    </head>.'''
    index = s.find("</head>") + len("</head>")
    header_str = s[:index]
    return header_str


def add_div(filename, caption):
    '''(str, str) -> str
    Return a string that is: 
    
    <div><img src=filename><br><p>caption</p></div>

    where filename is the first parameter and caption is the second 
    parameter. The parameter filename is the location of an image file and
    the parameter caption is a short description of the image.'''
    result = '<div><img src="%s"><br><p>%s</p></div>' % (filename, caption)
    return result


def add_body(image_dict, s, order=None):
    '''(dict of {str:list of str}, str, list) -> str
    Given an image dictionary where each key is a filename and each value 
    is a list is of the form [location, date, caption] and a string that contains 
    the header of an html file <html><header>...</header>, return a string
    that contains the header, the body and the end </html> tag of the 
    slideshow html file. The third parameter is optional and if passed contains an 
    ordered list of filenames. If the third parameter is passed, then the filenames
    included in the body should only be those in the list and should be added
    in the same order as they are listed in the list.
    '''
    body = ""
    if order is None:
        for image in image_dict:
            body += add_div(image, image_dict[image][2]) + "\n"
    else:
        for image in order:
            body += add_div(image, image_dict[image][2]) + "\n"
    body = '\n<body>\n<div id="slideshow">\n' + body + "</div>\n</body></html>"
    return s + body


def create_image_dict(open_file):
    '''(file) -> dict of {str: list of str}
    Given open csv file with the format:
    filename,location,date,caption,keywords, ...
    Return a dictionary with key filename and value 
    [location, date, caption]]'''
    image_dict = {}
    reader = csv.reader(open_file)
    for row in reader:
        key = row[0]
        value_list = row[1:4]
        image_dict[key] = value_list
    return image_dict


def create_keyword_dict(open_file):
    '''(file) -> dict of {str: list of str}
    Given an open csv file with the format: 
    filename,location,date,caption,keywords,keywords, ... 
    return a new dictionary where the key is a keyword 
    and each value is a list of filenames that have that 
    keyword in their list of keywords.
    '''
    keyword_dict = {}
    reader = csv.reader(open_file)
    for row in reader:
        filename = row[0]
        keywords_list = row[4:]
        for keyword in keywords_list:
            if keyword in keyword_dict:
                keyword_dict[keyword].append(filename)
            else:
                keyword_dict[keyword] = [filename]
    return keyword_dict


def find_images_with_keyword(key_dict, keywords_list):
    '''(dict of {str: list of str}, list or str) -> list

    Given a keyword_dictionary and a list of keywords, 
    return a list of filenames associated with the given keywords. 
    The list of filenames should include all filenames having 
    one or more the of the specified keywords (ie, a filename 
    may be  associated with only one, not all of the keywords 
    in the list).
    '''
    filenames_list = []
    for keyword in keywords_list:
        if keyword not in key_dict:
            continue
        for filename in key_dict[keyword]:
            filenames_list.append(filename)
    return list(set(filenames_list))

    
def create_date_dict(image_dict):
    '''(dict) -> dict
    Given an image dictionary, return a new dictionary
    where the key is a date and the value  is a list
    of filenames of images taken on that date.
    
    >>> d = {'image1.jpg': ['UTSC', '2017-11-03','Happy Friday']}
    >>> date_d = create_date_dict(d)
    >>> date_d == {'2017-11-03': ['image1.jpg']}
    True
    '''
    date_dict = {}
    for filename in image_dict:
        date = image_dict[filename][1]
        if date in date_dict:
            date_dict[date].append(filename)
        else:
            date_dict[date] = [filename]
    return date_dict


def sorted_images(image_dict):
    '''(dict) -> list of str
    Given an image dictionary return a list of the filenames
    sorted by date. 
    
    >>> d = {'image1.jpg': ['UTSC', '2017-11-03','Happy Friday'], \
    'image2.jpg': ['UTSC', '2017-11-04', 'Happy Sat.']}
    >>> sorted_images(d)    
    ['image1.jpg', 'image2.jpg']
    '''
    date_dict = create_date_dict(image_dict)
    filenames_list = sum([item[1] for item in sorted(date_dict.items(), key=lambda i: i[0])], [])
    return filenames_list


def intersect_lists(L1, L2):
    '''(list, list) -> list
    Return L1 with items not in L2 removed.
    '''
    result = []
    for i in L1:
        if i in L2:
            result.append(i)
    return result


if __name__ == '__main__':
    
    # open empty slideshow html_file and read into string
    file_object = open('empty_slideshow.html')
    text = read_file(file_object)
    file_object.close()
    # print(text)
    
    # get the header informtion 
    header = get_header(text)
    # print(header)
    
    # create the image dictionary
    file_object = open('files.csv')
    image_dict = create_image_dict(file_object)
    file_object.close()
    # print(image_dict)

    # create the keyword dictionary
    file_object = open('files.csv')
    keyword_dict = create_keyword_dict(file_object)
    file_object.close()
    # print(keyword_dict)

    # get keywords from user (if desired)
    keywords_list = []
    while True:
        keyword = input("Please enter a keyword. Enter nothing to quit.\n")
        if keyword == "":
            break
        else:
            keywords_list.append(keyword)

    # ask user if chronological order desired
    chronological = input("Slide show in chronological order? (yes/no)\n")

    # write slide show to slideshow.html
    if len(keywords_list) == 0:
        keywords_list = [keyword for keyword in keyword_dict]
    filenames_list = find_images_with_keyword(keyword_dict, keywords_list)

    if chronological=='yes':
        order = intersect_lists(sorted_images(image_dict), filenames_list)
    else:
        order = filenames_list
    html = add_body(image_dict, header, order)
    f = open("slideshow.html", 'wb')
    f.write(html.encode())
    f.close()
    # print(html)

    # remove comment to make the slideshow open in a browser
    webbrowser.open_new('''slideshow.html''')
