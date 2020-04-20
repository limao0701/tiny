def bub_sort_a(a):
    print a
    for i in range(0,len(a)-1):
        for j in range(i+1,len(a)):
            if(a[i]<a[j]):
                (a[i],a[j])=(a[j],a[i])
    print a
            

def insert_sort_a():
    pass


def bub_sort2_a(a):
    print a
    for i in range(0,len(a)-1):
        for j in range(0,len(a)-i-1):
            if a[j]<a[j+1]:
                a[j],a[j+1]=a[j+1],a[j]
    print a


def merge_sort_a(a):
    print a
    length=len(a)
    if (length==2):
        if(a[0]<a[1]):
            (a[0],a[1])=(a[1],a[0])
        return a
    if (length<=1):
        return a   
    mid=length/2
    left=a[0:mid]
    right=a[mid:]
    left=merge_sort_a(left)
    right=merge_sort_a(right)
    i=0
    j=0
    c=[]
    while(i<len(left) and j <len(right)):
        if (left[i]>=right[j]):
            c.append(left[i])
            i=i+1
        else:
            c.append(right[j])
            j=j+1
    while(i<len(left)):
        c.append(left[i])
        i=i+1

    while(j <len(right)):
        c.append(right[j])
        j=j+1
    return c
 
a=[1, 5, 7, 3, 9, 2, 6, 8]
bub_sort_a(a)
b=[1, 5, 7, 3, 9, 2, 6, 8]
bub_sort2_a(b)
c=[1, 5, 7, 3, 9, 2, 6, 8,4,3,2,4,54,65,47,6,64,434,523,45345243,53245]

c=merge_sort_a(c)
print c
