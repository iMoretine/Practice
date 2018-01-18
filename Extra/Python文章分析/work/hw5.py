
def create_words_list(text):
    """
    :param text: string of text
    :return: list of words
    """
    text = text.replace("\n", " ")
    words_list = text.split()
    return words_list


def remove_stop_words(words_list, stop_words_list):
    """
    :param words_list: list of words
    :param stop_words_list: list of words
    :return: list of words
    """
    for stop_word in stop_words_list:
        while stop_word in words_list:
            words_list.remove(stop_word)
    return words_list


def frequent_words(words_list):
    """
    :param words_list: list of words
    :return: list of tuples
    """
    words_set = set(words_list)
    words_count = {}
    for word in words_set:
        words_list.count(word)
        words_count[word] = words_list.count(word)
    return sorted(words_count.items(), key=lambda i: i[1], reverse=True)[:10]


def create_bigrams(words_list):
    """
    :param words_list: list of words
    :return: list of tuples
    """
    bigrams_list = []
    for index in range(len(words_list)-1):
        bigrams_list.append((words_list[index], words_list[index+1]))
    return bigrams_list


def frequent_bigrams(bigrams_list):
    """
    :param bigrams_list: list of tuples
    :return: list of tuples
    """
    bigrams_set = set(bigrams_list)
    bigrams_count = {}
    for bigram in bigrams_set:
        bigrams_list.count(bigram)
        bigrams_count[bigram] = bigrams_list.count(bigram)
    frequent = []
    for i in sorted(bigrams_count.items(), key=lambda i: i[1], reverse=True):
        if i[1] >= 2:
            frequent.append(i)
    return frequent


if __name__ == '__main__':
    # 读取DemocraticDebate_NYT.txt
    file = open('DemocraticDebate_NYT.txt', 'r', encoding='UTF-8')
    nyt_text = file.read()
    file.close()

    # 读取DemocraticDebate_WSJ.txt
    file = open('DemocraticDebate_WSJ.txt', 'r', encoding='UTF-8')
    wsj_text = file.read()
    file.close()

    # 读取stop words
    file = open('stopwords_en.txt', 'r', encoding='UTF-8')
    stop_words = file.read()
    file.close()
    stop_words_list = stop_words.split()

    # 生成词表
    nyt_words_list = create_words_list(nyt_text)
    wsj_words_list = create_words_list(wsj_text)

    # 去除stop word
    nyt_clean_words_list = remove_stop_words(nyt_words_list, stop_words_list)
    wsj_clean_words_list = remove_stop_words(wsj_words_list, stop_words_list)

    # 出现频率最高的10个词
    print("The 10 most frequent words in DemocraticDebate_NYT.txt:")
    for i in frequent_words(nyt_clean_words_list):
        print(i[0])
    print()
    print("The 10 most frequent words in DemocraticDebate_WSJ.txt:")
    for i in frequent_words(wsj_clean_words_list):
        print(i)
    print()

    # 出现频率超过两次的bigrams
    nyt_bigrams_list = create_bigrams(nyt_words_list)
    wsj_bigrams_list = create_bigrams(wsj_words_list)
    print("The bigrams appearing together more than 2 times in DemocraticDebate_NYT.txt:")
    for i in frequent_bigrams(nyt_bigrams_list):
        print(i)
    print()

    print("The bigrams appearing together more than 2 times in DemocraticDebate_WSJ.txt:")
    for i in frequent_bigrams(wsj_bigrams_list):
        print(i)
    print()
