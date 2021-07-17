import getpass
import network
import filesManger
import const
import user
import datetime
from github import Github

def CreateUser():
    print("Enter your Data\nName: ", end='')
    name = input().strip()
    password = (getpass.getpass("Password: ").strip())
    return user.User(name, password)

if __name__ == '__main__':
    myUser = CreateUser()
    network.sessionAndFiles(myUser)
    filesManger.NamingAndReplace(const.unzipDirTemp)

    time = datetime.datetime.now()
    readmeFile = open('tmpfiles/README.md' ,'w')
    readmeFile.truncate(0)
    readmeFile.write(f"# About\nProblems automated from vjudge {time.strftime('%d/%m/%Y - %I:%M %p')} and manually pushed to git")



#TODO: partioning script to 1-files class 2-Network session module 3 - Github module