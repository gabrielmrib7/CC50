import sys

tam = 0
num = 0
num1=0
num2=0
dig1 = 0
dig2 = 0

num = input("INSIRA O NUMERO DO CARTÃO: ")
tam = len(str(num))

if(tam < 13 or tam > 16):
    print("INVALID")
    sys.exit()

for i in range(-2, -(tam+1), -2):
    num1 = int(num[i])*2
    dig1 = str(dig1)+str(num1)


for y in range(-1, -(tam+1),-2):
    dig2 = int(num[y])+int(dig2)
    print(y,num[y])


for x in range(len(dig1)):
    num2 = int(dig1[x])+int(num2)

soma = num2+dig2
aux = str(soma)
print(num[0],num[1])
print(soma)

if (aux[len(aux)-1] == '0'):
    if(num[0] == '5' and num[1] == '1' or num[1] == '2' or num[1] == '3' or num[1] == '4' or num[1] == '5'):
        print("MASTERCARD")
    elif(num[0] == '3' and num[1] == '7' or num[0] == '3' and num[1] == '4'):
        print("AMEX")
    elif(num[0] == '4'):
        print("VISA")
    else:
        print("INVALID")



