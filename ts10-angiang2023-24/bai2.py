n = int(input())

s = 1
for i in range(2, n):
	if i*i>n:
		break
	if n%i==0:
		if i%2==0:
			s*=i
		if i*i!=n and n/i%2==0:
			s*=n/i

if(s==1):
	print(0)
else:
	print(int(s))