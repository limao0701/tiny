def string_to_num(aString):
    validNum=('0','1','2','3','4','5','6','7','8','9','.')
    aList=list(aString)
    print aList
    length=len(aList)
    sign=1
    divide=1
    result=0
    isFloat=1
    if aList[0]=='-':
        sign=-1
        length-=1
        aList.pop(0)
    if aList[0]=='+':
        length-=1
        aList.pop(0)
    if aList[0]=='.':
        length-=1
        divide=10**length
        aList.pop(0)
        isFloat-=1
    length=len(aList)
    for i in range(0,length):
        if aList[i] not in validNum:
            print "Not a valid number string"
            return 0
        if aList[i]=='.':
            isFloat-=1
            divide=10**(length-i)
            length+=1
            continue
        result+=validNum.index(aList[i])*10**(length-i-1)
    if isFloat<0:
        return 0
    if divide!=1:
        return sign*float(result)/divide
    else:
        return sign*result/divide

ss='--12345000000'
print string_to_num(ss)
