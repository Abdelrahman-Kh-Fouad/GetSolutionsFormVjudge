import requests
import const
import zipfile
import io
import os
import re
import bs4

def GetIdOfFiles(page):
    page = bs4.BeautifulSoup(page , 'html.parser')
    allLine =  page.findAll(name='a' , text='AC')[0]
    res = ""
    cnt =0
    for i in str(allLine):
        if i =='"':
            cnt +=1
            continue
        if cnt ==1:
            res+=i
    return res

    
#TODO:handling network connection errors
def sessionAndFiles(myUser):
    with requests.session() as  mainRequest:
        response = mainRequest.get(const.websiteUrl, headers=const.Basic_headers)
        print(response)
        response = mainRequest.post(const.checkStateState, headers=const.Basic_headers)
        print(response)
        response = mainRequest.post(const.logInUrl, data=myUser.getDataPost(), headers=const.Basic_headers)
        print(response.content)
        response = mainRequest.get(const.usersUrl+str(myUser.username) ,headers=const.Basic_headers )

        filesUrl =const.websiteUrl+GetIdOfFiles(response.content)
        file_byte = mainRequest.get(filesUrl, stream=True)
        file_zip = zipfile.ZipFile(io.BytesIO(file_byte.content))
        file_zip.extractall(path=const.unzipDirTemp)
        print(os.popen('tree '+const.unzipDirTemp).read())