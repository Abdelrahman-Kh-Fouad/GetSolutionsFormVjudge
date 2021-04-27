import requests
import const
import zipfile
import io
def sessionAndFiles():
    with requests.session() as  mainRequest:
        response = mainRequest.get(const.websiteUrl, headers=const.Basic_headers)
        print(response)
        response = mainRequest.post(const.checkStateState, headers=const.Basic_headers)
        print(response)
        response = mainRequest.post(const.logInUrl, data=const.LoginData, headers=const.Basic_headers)
        print(response.content)
        file_byte = mainRequest.get(const.fileUrl, stream=True)
        file_zip = zipfile.ZipFile(io.BytesIO(file_byte.content))
        file_zip.extractall(path=const.unzipDirTmp)
