import os
Basic_headers={"User-Agent"
	:"Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:87.0) Gecko/20100101 Firefox/87.0"
}

vJudge_headers= {
"authority": "www.codechef.com",
"method": "POST"
,"path": "/"
,"scheme": "https"
,"accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9"
,"accept-encoding": "gzip, deflate, br"
,"accept-language": "en-US,en;q=0.9"
,"cache-control": "max-age=0"
,"content-length": "181"
,"content-type": "application/x-www-form-urlencoded"

,"origin": "https://www.codechef.com"
,"referer": "https://www.codechef.com/"
,"sec-ch-ua": '"Google Chrome";v="89", "Chromium";v="89", ";Not A Brand";v="99"'
,"sec-ch-ua-mobile": "?0"
,"sec-fetch-dest": "document"
,"sec-fetch-mode": "navigate"
,"sec-fetch-site": "same-origin"
,"sec-fetch-user": "?1"
,"upgrade-insecure-requests": "1"
,"user-agent": "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4389.114 Safari/537.36"

}

websiteUrl= "https://vjudge.net/"
checkStateState ="https://vjudge.net/user/checkLogInStatus"
logInUrl="https://vjudge.net/user/login"
fileUrl ="https://vjudge.net/user/exportSource?minRunId=0&maxRunId=99999999&ac=true";
usersUrl = "https://vjudge.net/user/"
root = os.popen("pwd").read()
root =root[0:len(root)-1]


unzipDirTemp = root + "/tmpfiles"