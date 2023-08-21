# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 1000


def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")


    # TODO: Read teams into memory from file
    with open(sys.argv[1], "r") as file:
        dict = csv.DictReader(file)
        header = dict.fieldnames
        teams = []
        for row in dict:
            rating = {}
            for i in range(1, len(header)):
                rating[header[i]] = int(row[header[i]])
            teams.append({"team": row["team"], "rating": rating})




    counts = {}
    # TODO: Simulate N tournaments and keep track of win counts
    for i in range(N): #loop
        winner = simulate_tournament(teams) #loopando a simulação de torneios e retornando os vencedores
        if winner in counts: #se o vencedor tiver na contagem
            counts[winner] += 1 #adiciona +1
        else:
            counts[winner] = 1 #se nao adiciona ele na contagem


    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2["rating"] - rating1["rating"]) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # TODO
    rounds = len(teams)
    if rounds >= 2: #se os rounds forem > ou = a 2
        teams = simulate_round(teams) #chama a função simulate_round para simular os rounds e retornar uma lista de vencedores e armazena na variavel teams
        return simulate_tournament(teams) #loopa na função ate a condição da linha 73 for falsa
    else:
        w = teams[0]["team"]
        return w #retorna o vencedor




if __name__ == "__main__":
    main()
