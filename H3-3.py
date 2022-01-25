'''dont know how to implement big number in C++'''
cnt=1
while True:
    n,people=map(int,input().split())
    if n==0 and people==0:
        break
    sum=0
    for i in range(n):
        sum+=int(input())
    print(f"Bill #{cnt} costs {sum}: each friend should pay {sum//people}\n")
    cnt+=1