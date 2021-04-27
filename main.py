import getpass
import zipfile
import io

import os

def getDataFromUser():
    print("Enter your Data\nName: ", end='')
    name = input().strip()
    pas = (getpass.getpass("Password: ").strip())
    return {"username" : str(name),  "password" : str(pas)}

LoginData = getDataFromUser()


# mainRequest.get("https://vjudge.net/user/exportSource?m   inRunId=0&maxRunId=99999999&ac=true" , headers=vJudge_headers )
# print(mainRequest)




#TODO: partioning script to 1-files class 2-Network session module 3 - Github module