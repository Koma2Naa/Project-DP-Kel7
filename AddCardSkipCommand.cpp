#include "AddCardSkipCommand.h"
#include "GameManager.h"
#include <random>
#include <iostream>

std::string AddCardSkipCommand::getDescription() const {
    return "Add a random card to deck";
}

void AddCardSkipCommand::execute(GameManager& gm) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::uniform_int_distribution<> rankDis(2, 14);
    std::uniform_int_distribution<> suitDis(0, 3);

    char suits[] = {'H', 'D', 'C', 'S'};
    int rank = rankDis(g);
    char suit = suits[suitDis(g)];

    gm.addCardToDeck({rank, suit});
    std::cout << "[TAG] Added random card: Rank " << rank << ", Suit " << suit << " to your deck!\n";
}
