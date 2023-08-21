#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
    //int num; metodo que pensei porem na verificação falha, no debug funcionou perfeitamente (função sortpairs)
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;
int aux[MAX];

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for(int i = 0; i<candidate_count; i++)
    {
        if(strcmp(candidates[i], name)==0)
        {
            ranks[rank] = i;
            return true;

        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO

    //alice> bob> charlie               // preferences   alice   bob    charlie
    //alice>bob = 1                           alice                                 acha alice> que x candidato
    //alice>charlie = 1                       bob                                   acha bob> que x candidato
    //bob>charlie =1                          charlie                               acha charlie> que x candidato

    //bob> alice> charlie
    //bob>alice=1
    //bob>charlie=1
    //alice>charlie=1

    // int i = preferido
    // int j = nao escolhido

    //primeiro caso
    //alice = int i = 0 (1 equivale ao local em que fica na array)
    //bob = int j = 1   (mesma coisa ^^^^)

    //alice>bob  li col
    //preferences[0][1] = ++

    //alice>charlie
    //int i||int j
    //preferences[0][2] = ++

    //bob>charlie
    //preferences[1][2] = ++

                  //   0      1        2
    // preferences   alice   bob    charlie
    //  0 | alice       0      1        1          acha alice> que x candidato
    //  1 | bob                         1          acha bob> que x candidato
    //  2 | charlie                                acha charlie> que x candidato

    //segundo caso
    // bob> alice> charlie
    //bob = int i = 1
    //alice = int j = 0
    //bob > alice ++
    //preferences[1][0]++

    //bob>charlie++
    //preferences[1][2]++

    //alice>charlie++
    //preferences[0][2]++

                   //   0      1        2
    // preferences   alice   bob    charlie
    //  0 | alice       0      1        2          acha alice> que x candidato
    //  1 | bob         1               2          acha bob> que x candidato
    //  2 | charlie                                acha charlie> que x candidato


    for(int i = 0; i<candidate_count-1; i++)
    {
        for(int j = i+1; j< candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++; //ranks[i] equivale ao escolhido, ranks[j] ao que esta abaixo
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    for(int i = 0; i<candidate_count; i++)
    {
        for(int j=i+1; j<candidate_count; j++)
        {

            if(preferences[i][j]>preferences[j][i])
            {
                pairs[pair_count].winner= i;
                pairs[pair_count].loser= j;
                //pairs[pair_count].num = preferences[i][j]; metodo para a função sortpairs que pensei porem na verificação falhou, no debug funcionou perfeitamente
                pair_count++;


            }
            else if(preferences[i][j]<preferences[j][i])
            {
                pairs[pair_count].winner=j;
                pairs[pair_count].loser=i;
                //pairs[pair_count].num = preferences[j][i]; metodo que pensei para a função sortpairs porem na verificação falha, no debug funcionou perfeitamente
                pair_count++;

            }


        }

    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{

    // TODO
 for(int i = pair_count - 1; i < candidate_count; i++)
 {
            for(int j = 0; j < i; j++)
            {
                if((preferences[pairs[j].winner][pairs[j].loser])<(preferences[pairs[j+1].winner][pairs[j+1].loser]))
                    {
                        pair temp = pairs[j];
                        pairs[j] = pairs[j+1];
                        pairs[j+1] = temp;
                    }

            }
       }

    return;
}

bool cycle(int end, int cycle_start){
    if(end == cycle_start){
        return true;
    }

    for(int i = 0; i < candidate_count; i++){
        if(locked[end][i]){
            if(cycle(i, cycle_start)){
                return true;
            }
        }
    }
    return false;
}
// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for(int i = 0; i < pair_count; i++){
        if(!cycle(pairs[i].loser, pairs[i].winner)){
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    for(int i = 0; i<candidate_count; i++)
    {
    int count = 0;
        for(int j = 0; j<candidate_count; j++)
        {
            if(locked[j][i]==false)
            {
            count++;
            if(count==candidate_count)
            {
                printf("Winner: %s\n",candidates[i]);
            }
            }
        }
    }


    return;
}

//void sort_pairs(void) função utilizando o metodo que eu pensei
//{

    // TODO
 //for(int i = pair_count - 1; i < candidate_count; i++)
 //{
   //         for(int j = 0; j < i; j++)
     //       {
       //         if(pairs[j].num<pairs[j+1].num)
         //           {
           //             pair temp = pairs[j];
             //           pairs[j] = pairs[j+1];
               //         pairs[j+1] = temp;
                 //   }
            //}
       //}
       //printf("%i\n",pair_count);
    //return;
//}
