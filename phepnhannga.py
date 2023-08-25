# Nhân Của Nga
def nhanNga(a, b):
    result = 0
    while a > 0:
        if a % 2 == 1:
            result += b
        a //= 2
        b *= 2
    return result

num1 = int(input("Nhập số nguyên thứ nhất: "))
num2 = int(input("Nhập số nguyên thứ hai: "))
print(nhanNga(num1,num2))
