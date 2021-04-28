memo=dict()
def fib(n):
    if memo.get(n,0)!=0 :
        return memo[n]
    if n==1 or n==2:
        return 1

    res = fib(n-1)+fib(n-2)
    try:
        memo[n]=res
    except:
        memo[n]=0
    return res

while True:
    try :
        n=int(input())
    except:
        break
    print(fib(n))