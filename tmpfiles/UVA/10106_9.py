while True:
    try:
        x=int (input())
    except EOFerror:
        break
    try:
        y=int (input())
        print (str ( x*y))
    except EOFerror:
        break