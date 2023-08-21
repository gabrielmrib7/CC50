from cs50 import get_int



def main():
    tamanho = 0
    while tamanho > 8 or tamanho <= 0:
        tamanho = get_int("Altura de 1 a 8: ")
    imprimir(tamanho)



def imprimir(tamanho):

    for i in range(tamanho):
        i = i+1
        j = (tamanho-i)
        print(" " *j, end="#" *i)
        j =- 1
        print("  ", end="")
        print("#" *i, end="")
        print()


main()