#Nhân Bắc Mỹ
L1,L2 = map(float,input().split())
dem=0
volume = 0
while L2 > 0:
    n = (L2%10)*L1
    dem+=1
    for _ in range(1,dem):
        n *= 10
    volume +=n
    L2 //=10
print(int(volume))