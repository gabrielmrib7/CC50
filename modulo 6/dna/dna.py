import sys
import csv

def main():

    if len(sys.argv) != 3:
        print("Invalid Input")
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)
    with open(sys.argv[1], "r") as file:
        dict = csv.DictReader(file) #transforma cade linha de file em um dicionario
        header = dict.fieldnames #le e retorna uma lista do cabecalho, name, dnas...
        people = [] #cria uma lista vazia
        for row in dict: #para cada linha no 'dicionario' de file, percorrera...
            person = {} #criando um dicionario vazio para armazenar as informações de cada pessoa
            for i in range(1, len(header)): #percorrendo todas as colunas do arquivo csv atribuindo valores as chaves STR (apartir da 1, ignorando o nome)
                person[header[i]] = int(row[header[i]]) #armazenando o valor da contagem STR em um str, chave sendo o nome STR(AGATC, AATC...)
            people.append({"name": row["name"], "counts": person}) #adicionando um novo dicionario com os nomes e as contagens STR à lista people


    with open(sys.argv[2], "r") as txt_file:
        sequence = txt_file.read()


    counts = {}
    for key in people[0]["counts"]: #loopa todas as chaves do dicionario counts
        l = len(key) #armazena o tamanho da chave
        max_c = 0 #variavel para checar o maximo de repetições consecutivas
        i = 0 #variavel para o loop abaixo
        while i < len(sequence): #enquanto i for menor que a sequencia de dna fazer...
            count = 0 #contador
            while sequence[i:i+l] == key: #enquanto a subsequencia de i ate i+l for igual a chave
                count += 1 #aumenta o contador                                                                                                                                                  i:5+4
                i += l #soma de variavel para ir para a proxima sequencia de dna, exemplo: i = 1, l = 4, 1:5, sequence[1:5] == ABCD e key == ABCD, i = 1+4, i = 5 voltando e repetindo sequence[5:9]==key (lembrando que o 5 e 9 sao os indices limite, ou seja a sequencia nao vai ate eles, sendo assim, 5:'9' = 5,6,7,8)
            if count>max_c: #se o contador for maior que o contador maximo
                max_c = count #atribua o valor do contador no contador maximo
            i += 1 #aumenta o contador para verificar a proxima subsequencia
        counts[key] = max_c #armazena para a chave no dicionario counts a contagem maxima


    for person in people:
        if person["counts"] == counts:
            print(person["name"])
            sys.exit(0)
    print("No Match")







main()