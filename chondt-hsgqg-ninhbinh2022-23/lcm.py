import sys

sys.stdin = open('lcm.inp', 'r')
sys.stdout = open('lcm.out', 'w')

a,b = map(int, input().split())

p = [1]*int(1e6+6)
f = [0]*int(1e6+6)

p[0]=p[1]=0;    
for i in range(2,int(1e3)+1):
    if(p[i]):
        for j in range(i*i,int(1e6+1),i):
            p[j]=0

res = 1

for pr in range(1,int(1e6+1)):
    if(p[pr]==0):
        continue
    
    cur = pr
    cnt = 0
    
    while cur<=b:
        cnt+=b//cur-(a-1)//cur
        cur *= pr
    
    res*=(cnt*2+1)

print(res)