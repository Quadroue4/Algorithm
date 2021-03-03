arr = [True for i in range(1000001)]
p = []
for i in range(2, 1000001):
    if arr[i]:
        p.append(i)
        k = 2
        while i * k <= 1000000:
            arr[i*k] = False
            k += 1

vmin, vmax = input().split(' ')
vmin = int(vmin)
vmax = int(vmax)

arr2 = [True for i in range(vmax - vmin + 1)]

maxPrime = int(vmax**0.5)

count = 0 # 1부터 count개수 까지의 소수로 vmin-vmax 배열을 거른다

while count < len(p) and p[count] <= maxPrime:
    count = count + 1

for i in p[:count]:
    remain = vmin%(i**2)
    k = 0
    if(remain != 0):
        k = k+1
    while k*(i**2)-remain <= vmax-vmin:
        arr2[k*(i**2)-remain] = False
        k = k + 1


count=0
for i in arr2:
    if i:
        count = count+1

print(count)
