#include "GameModelFromLevelGenerator.h"

GameModel GameModelFromLevelGenerator::generateGameModel(const LevelConfig& levelConfig) {
    GameModel gameModel;
    int nextId = 1;

    for (const auto& card : levelConfig.playField) {
        const int cardId = nextId++;
        gameModel.cards[cardId] = CardModel::create(cardId, card.face, card.suit, card.x, card.y);
        gameModel.playFieldCardIds.push_back(cardId);
    }

    bool isFirstStackCard = true;
    for (const auto& card : levelConfig.stack) {
        const int cardId = nextId++;
        gameModel.cards[cardId] = CardModel::create(cardId, card.face, card.suit, card.x, card.y);
        gameModel.cards[cardId].isInPlayField = false;
        gameModel.stackCardIds.push_back(cardId);
        if (isFirstStackCard) {
            gameModel.trayTopCardId = cardId;
            isFirstStackCard = false;
        }
    }

    if (!gameModel.stackCardIds.empty()) {
        gameModel.stackCardIds.erase(gameModel.stackCardIds.begin());
    }

    return gameModel;
}
