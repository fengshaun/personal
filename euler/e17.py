d = {0:     '',
     1:     'one',
     2:     'two',
     3:     'three',
     4:     'four',
     5:     'five',
     6:     'six',
     7:     'seven',
     8:     'eight',
     9:     'nine',
     10:    'ten',
     11:    'eleven',
     12:    'twelve',
     13:    'thirteen',
     14:    'fourteen',
     15:    'fifteen',
     16:    'sixteen',
     17:    'seventeen',
     18:    'eighteen',
     19:    'nineteen',
     20:    'twenty',
     30:    'thirty',
     40:    'forty',
     50:    'fifty',
     60:    'sixty',
     70:    'seventy',
     80:    'eighty',
     90:    'ninety',
     100:   'hundred',
     'and': 'and'}

class VerboseNum:
    '''
    This class provides verbose numbers (one, two, etc.)
    conversions for int.  It supports up to 3 digit numbers.
    '''
    def __init__(self, num):
        self.__num = num
        self.__text = ''
        self.parse()

    def get_text(self):
        return self.__text

    def parse(self):
        s = str(self.__num)
        if self.__num in d:
            if self.__num == 100:
                self.__text = d[1] + ' ' + d[100]
            else:
                self.__text = d[self.__num]
        elif len(s) == 2:
            # 23 -> twenty three
            self.__text = d[int(s[0]) * 10] + ' ' + d[int(s[1])]
        elif len(s) == 3:
            # 465 -> four hundred and sixty five
            # 600 -> six hundred
            text = d[int(s[0])] + ' ' + d[100]
            if int(s[1]) != 0 or int(s[2]) != 0:
                text += ' ' + d['and']
            else:
                self.__text = text
                return

            if int(s[1:]) in d:
                text += ' ' + d[int(s[1:])]
                self.__text = text
                return

            text += ' ' + d[int(s[1]) * 10]
            text += ' ' + d[int(s[2])]
            self.__text = text
            return
        else:
            raise 'Cannot parse more than 3 digits'


def solve():
    text = ''

    for i in range(1, 1000):
        t = VerboseNum(i).get_text()
        text += t

    text += 'one thousand'
    text = text.replace(' ', '')
    return len(text)

if __name__ == '__main__':
    print solve()
