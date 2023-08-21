from cs50 import get_string

text = get_string("Text: ")

# Contagem de letras
n_letras = len([letra for letra in text if letra.isalpha()])


# Contagem de palavras
n_palavras = len(text.split())

# Contagem de frases
n_frases = text.count('.')+text.count('!')+text.count('?')

L = n_letras * 100 / n_palavras
S = n_frases * 100 / n_palavras

index = (0.0588 * L) - (0.296 * S) - 15.8

print("Número de letras:", n_letras)
print("Número de palavras:", n_palavras)
print("Número de frases:", n_frases)
print("")

if round(index) > 16:
    print("Grade 16+")
elif round(index) < 1:
    print("Before Grade 1")
else:
    print("Grade", round(index))
