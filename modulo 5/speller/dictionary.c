// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <cs50.h>

#include "dictionary.h"
#define N 26

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
unsigned int words=0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int id = hash(word); //chama hash para descobrir id
    node *cursor = table[id]; //cursor vai pegar todos os dados de table[id]
    while(cursor!=NULL)//enquanto diferente de NULL
    {
        if(strcasecmp(cursor->word, word)==0) //compara as palavras de table[id] em cursor com a palavra que foi deu entrada na função
        {
            return true; //retorna true caso ache
        }
        cursor = cursor->next; //caso nao ache vai para a proxima palavra
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    //retorna o id da tabela hash da palavra
    //ex: Abobora, word[0] = A, word[0] = 97; x = 97 - 97 = 0; table[0] = Abobora
    //abobora, word[0] = a, word[0] = 65; x = 65 - 65 = 0; table[0] = abobora
    if (isupper(word[0])) //maiusculas
    {
        int x = word[0] - 65;
        return x;
    }
    if (islower(word[0])) // minusculas
    {
        int x = word[0] - 97;
        return x;
    }
    return 0;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    for (int i = 0; i<N; i++) //limpando valores lixo
    {
        table[i] = NULL;
    }
    FILE *dictionary_p = fopen(dictionary, "r"); //abrindo dicionary
    if(dictionary_p == NULL)
    {
        printf("Cannot open the file\n");
        return false;
    }
    char word2[LENGTH + 1];
    while(fscanf(dictionary_p, "%s", word2)!= EOF) //enquanto a palavra for diferente de EOF
    {
        unsigned int hash_num = hash(word2); //chama função hash
        node *newnode = malloc(sizeof(node)); //cria um novo no
        if(newnode== NULL) // verifica se o no foi feito
        {
            return false;
        }
        strcpy(newnode->word, word2); //copia o novo no apontando para a word em word2
        newnode->next = table[hash_num]; //novo no apontando para next e setando next com seu table[id].   newnode{word = b, next = null} -> next = table[2]
        table[hash_num] = newnode; //seta a tabela hash no id sem perder dados.       table[2] = newnode{word = b, next = null}
        words++; //contador de palavras
    }
    fclose(dictionary_p);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i<N; i++) // repete ate correr em toda a tabela usando a variavel i
    {
        node *cursor = table[i]; //cursor pega o endereço da tabela[i]
        while(cursor!=NULL)
        {
            node *tmp = cursor; //tmp pega o endereço de cursor. tmp->cursor->table[1] (salvando endereço para limpar)
            cursor = cursor->next; //cursor aponta para o proximo dado
            free(tmp); // limpa o endereço de memoria que esta em tmp.
        }
    }


    return true;
}
