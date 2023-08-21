from cs50 import get_float

cents = 0
cent25 = 0
cent10 = 0
cent5 = 0
cent1 = 0

while (cents <= 0):
    cents = get_float("QUANTIA DE TROCO? ")

cents = cents*100
while(cents > 0):
    if(cents >= 25):
        cents = (cents - 25)
        cent25 = cent25 + 1
    elif(cents>=10 and cents< 25):
        cents = (cents - 10)
        cent10 = cent10 + 1
    elif(cents>=5 and cents < 10):
        cents = (cents - 5)
        cent5 = cent5 + 1
    elif(cents>=1 and cents <= 4):
        cents = (cents-1)
        cent1 = cent1 + 1


resultado = cent25+cent10+cent5+cent1
print("25 Centavos: " ,cent25)
print("10 Centavos: " ,cent10)
print("5 Centavos: " ,cent5)
print("1 Centavo: " ,cent1)


print("Quantidade minimas de moedas: " ,resultado)
