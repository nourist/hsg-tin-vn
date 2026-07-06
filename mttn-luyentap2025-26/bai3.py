n, k = map(int, input().split())
arr = list(map(int, input().split()))

class Fenwick:
    def __init__(self, n):
        self.n = n
        self.bit = [0] * (n + 1)

    def clear(self):
        for i in range(1, self.n + 1):
            self.bit[i] = 0

    def update(self, i, val):
        while i <= self.n:
            self.bit[i] += val
            i += i & -i

    def query(self, i):
        res = 0
        while i > 0:
            res += self.bit[i]
            i -= i & -i
        return res
    
    def findKth(self, k):
        pos = 0
        bitMask = 1 << (self.n.bit_length() - 1)
        while bitMask > 0:
            nextPos = pos + bitMask
            if nextPos <= self.n and self.bit[nextPos] < k:
                k -= self.bit[nextPos]
                pos = nextPos
            bitMask >>= 1
        return pos + 1

fw = Fenwick(n)

fact = [1] * 25
for i in range(2,21):
	fact[i] = fact[i - 1] * i

def getRank(a):
	fw.clear()
	n = len(a)
	for i in range(n):
		fw.update(a[i], 1)
	
	res = 0
	for i in range(n):
		smaller = fw.query(a[i] - 1)
     
		subTreeRank = fact[n-i-1]*smaller
		
		res += subTreeRank
  
		fw.update(a[i], -1)
	return res + 1

def getTree(rank, a):
	fw.clear()
	n = len(a)
	for i in range(n):
		fw.update(a[i],1)
    
	tree = []
	rank -= 1
	for i in range(n):
		subTreeSize = fact[n-i-1]
		pos = fw.findKth(rank//subTreeSize + 1)
		rank %= subTreeSize
		tree.append(pos)
		fw.update(pos, -1)
	return tree

if(len(arr)<=20):
	currentRank = getRank(arr)
	newRank = currentRank+k

	print(' '.join(map(str, getTree(newRank, arr))))
else:
    prefix = arr[:n-20]
    suffix = arr[n-20:]
    
    currentRank = getRank(suffix)
    newRank = currentRank + k
    
    newSuffix = getTree(newRank, suffix)
    print(' '.join(map(str, prefix + newSuffix)))
