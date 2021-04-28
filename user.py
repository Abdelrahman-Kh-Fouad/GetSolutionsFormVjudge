class User :
    def __init__(self , username , password):
        self.username =username
        self.password =password
    def getDataPost(self):
        return {"username": str(self.username), "password": str(self.password)}