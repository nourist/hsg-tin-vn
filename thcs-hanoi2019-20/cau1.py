inp = open('cau1.inp', 'r')
out = open('cau1.out', 'w')

n, k = map(int, inp.readline().split())

res = 1
for i in range(1, n):
	res*=i
	while len(str(res)) > k:
		res //= 10

out.write(str(res))