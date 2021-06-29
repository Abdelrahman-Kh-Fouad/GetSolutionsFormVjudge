import os
import const
import time
class Problem :
    pass

def OnlyFiles(node):
    res = True
    for next in os.listdir(node):
        res = res and os.isfile(next)
    return res

def GetNameOfFile(node):
    node =node[::-1]
    result =''
    for i in node:
        if i =='/':
            break
        result +=i
    result = result[::-1]

def CheckIfCOrPy(path):
    file = open(path)
    for line in file :
        if line.find("#include") != -1:
            return True
    return False

def Getext(path):
    npath = path[::-1]
    res = ''
    for i in npath:
        if i =='.':break
        res +=i
    res = res[::-1]

    if res == "c" :
        if not CheckIfCOrPy(npath[::-1]):
            res ='py'

    return res

def DelDir(path):
    path = path[::-1]
    for i in range(len(path)):
        if path[i] =='/':
            path =path[i+1:]
            break
    return path[::-1]

def copy (source , dist ):
    print('cp '+source+" "+dist)
    os.popen('cp '+source+" "+dist)

def RemoveFile(target):
    os.popen('rm '+target)
def RemoveDir(target):
    os.popen('rmdir '+target)

def AddCountOtNot(count):
    if count == 0:return''
    else :return '_'+str(count  )


def TraverseDirs(node):
    judgelist = os.listdir(node)

    curPath = node
    for judge in judgelist:
        curPath+='/'+judge
        problems = os.listdir(curPath)
        for problem in problems:
            curPath+='/'+problem
            if not os.path.isdir(curPath):
                curPath= DelDir(curPath)
                continue

            #many solution for one problem
            numberOfSolution = 0
            for solution in os.listdir(curPath):
                solutionFileName = solution
                ext = Getext(curPath+'/'+solutionFileName)
                copy(curPath+'/'+solutionFileName , DelDir(curPath)+'/'+problem+AddCountOtNot(numberOfSolution)+'.'+ext)
                RemoveFile(curPath+'/'+solutionFileName)
                numberOfSolution+=1

            curPath = DelDir(curPath)
            os.popen('rmdir '+curPath+'/'+problem)

        curPath= DelDir(curPath)


def NamingAndReplace(root):
    TraverseDirs(root)
    print(os.popen('tree '+root).read())


if __name__ == '__main__':
    NamingAndReplace(const.unzipDirTemp)