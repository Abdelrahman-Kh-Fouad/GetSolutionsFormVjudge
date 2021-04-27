import os
import const
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


def Getext(path):
    path = path[::-1]
    res = ''
    for i in path:
        if i =='.':break
        res +=i
    res = res[::-1]
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

            solutionFileName = os.listdir(curPath)[0]
            ext = Getext(solutionFileName)
            os.popen('touch '+DelDir(curPath)+'/'+problem+'.'+ext)
            copy(curPath+'/'+solutionFileName , DelDir(curPath)+'/'+problem+'.'+ext)
            RemoveFile(curPath+'/'+solutionFileName)
            curPath = DelDir(curPath)
            os.popen('rmdir '+curPath+'/'+problem)
        curPath= DelDir(curPath)


def NamingAndReplace(root):
    TraverseDirs(root)
    print(os.popen('tree '+root).read())


if __name__ == '__main__':
    NamingAndReplace(const.root+'/files')