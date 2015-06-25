import os
import re

def isMatch(filename):
    pattern = re.compile(r'\d+-\w+')
    m  = pattern.match(filename)

    if m:
        return True
    return False
def getNum(filenum):
    m = re.search(r'(\d+)-\w+', filenum)
    return m.group(1)

def listDir(dir, donefile, todofile):
    #file.write(dir + '\n')
    filenum = 0
    numlist = []
    list = os.listdir(dir)
    for line in list:
        filepath=os.path.join(dir, line)
        #if os.path.isdir(filepath):
            #myfile.write(' ' + line + '//' + '\n')
            #for li in os.listdir(filepath):
                #myfile.write(' ' + li + '\n')
                #filenum =filenum + 1
        if os.path:
            #myfile.write(' ' + line + '\n')
            if isMatch(line):
                numlist.append(int(getNum(line)))
                #myfile.write(' ' + getNum(line) + '\n')
                filenum = filenum + 1
    numlist.sort()
    for num in numlist:
        donefile.write(str(num) + '\n')

    donefile.write('all the file num is ' + str(filenum))
    
    for i in range(1, numlist[len(numlist) - 1]):
        if (i in numlist) == False:
            todofile.write(str(i) + '\n')

dir = raw_input('please input the path:\n')
donefile = open('done.txt', 'w')
todofile = open('todo.txt', 'w')
listDir(dir, donefile, todofile)
donefile.close()
todofile.close()
