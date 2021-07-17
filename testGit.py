import github



if __name__ == '__main__':
    git = github.Github(base_url="https://Abdelrahman-Kh-Fouad/api/v3")

    for repo in git.get_user().get_repos():
        print(repo)