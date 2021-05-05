import getpass
import zipfile
import io
import os
import network
import filesManger
import const
import user
def CreateUser():
    print("Enter your Data\nName: ", end='')
    name = input().strip()
    password = (getpass.getpass("Password: ").strip())
    return user.User(name, password)


myUser = CreateUser()
network.sessionAndFiles(myUser)
filesManger.NamingAndReplace(const.unzipDirTemp)



#TODO: partioning script to 1-files class 2-Network session module 3 - Github module