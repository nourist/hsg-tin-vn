n, k = map(int, input().split())
s = input()

dp = [[0]*(k+1) for _ in range(n+1)]
dp[n][0] = 1
for i in range(n-1, -1, -1):
    for j in range(k,-1,-1):
        if j!=k:
            dp[i][j] += dp[i+1][j+1]*3
        if j!=0:
            dp[i][j] += dp[i+1][j-1]

def isOpen(ch):
    return ch =='(' or ch == '[' or ch == '{'

def isMatch(op, en):
    return (op == '(' and en == ')') or (op == '[' and en == ']') or (op == '{' and en == '}')

order = "()[]{}"
res = 1
st = []

for i in range(0, n):
    for c in order:
        if c==s[i]:
            break
        
        if isOpen(c) and len(st) == k:
            continue
        
        if not isOpen(c) and len(st)==0:
            continue
        
        if not isOpen(c) and not isOpen(st[-1]):
            continue
        
        if not isOpen(c) and not isMatch(st[-1], c):
            continue
        
        if isOpen(c):
            res += dp[i+1][len(st)+1]
        else:
            res += dp[i+1][len(st)-1]
    if isOpen(s[i]):
        st.append(s[i])
    else :
        st.pop()

print(res)