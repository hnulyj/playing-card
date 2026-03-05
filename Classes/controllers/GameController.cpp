#include "GameController.h"

#include "../configs/loaders/LevelConfigLoader.h"
#include "../services/CardRuleService.h"
#include "../services/GameModelFromLevelGenerator.h"
#include "../utils/VectorUtils.h"

USING_NS_CC;

bool GameController::startGame(Node* parent, int levelId) {
    LevelConfig levelConfig = LevelConfigLoader::loadLevelConfig(levelId);
    _gameModel = GameModelFromLevelGenerator::generateGameModel(levelConfig);

    _gameView = GameView::create(_gameModel);
    if (_gameView == nullptr || parent == nullptr) {
        return false;
    }

    _gameView->setOnPlayFieldCardClick([this](int cardId) {
        handlePlayFieldCardClick(cardId);
    });
    _gameView->setOnStackClick([this]() {
        handleStackClick();
    });
    _gameView->setOnUndoClick([this]() {
        handleUndoClick();
    });
    parent->addChild(_gameView);
    return true;
}

bool GameController::handlePlayFieldCardClick(int cardId) {
    CardModel* clicked = _gameModel.getCard(cardId);
    CardModel* trayTop = _gameModel.getCard(_gameModel.trayTopCardId);
    if (clicked == nullptr || trayTop == nullptr || !clicked->isInPlayField) {
        return false;
    }
    if (!CardRuleService::canMatch(clicked->face, trayTop->face)) {
        return false;
    }
    return moveCardToTray(cardId, UAT_PLAYFIELD_TO_TRAY);
}

bool GameController::handleStackClick() {
    if (_gameModel.stackCardIds.empty()) {
        return false;
    }
    int cardId = _gameModel.stackCardIds.front();
    _gameModel.stackCardIds.erase(_gameModel.stackCardIds.begin());
    return moveCardToTray(cardId, UAT_STACK_TO_TRAY);
}

bool GameController::handleUndoClick() {
    UndoModel undo;
    if (!_undoManager.popUndo(undo)) {
        return false;
    }

    _gameModel.trayTopCardId = undo.previousTrayTopCardId;
    CardModel* movedCard = _gameModel.getCard(undo.movedCardId);
    if (movedCard == nullptr) {
        return false;
    }

    movedCard->x = undo.fromX;
    movedCard->y = undo.fromY;

    if (undo.actionType == UAT_PLAYFIELD_TO_TRAY) {
        movedCard->isInPlayField = true;
        _gameModel.playFieldCardIds.push_back(undo.movedCardId);
    } else if (undo.actionType == UAT_STACK_TO_TRAY) {
        _gameModel.stackCardIds.insert(_gameModel.stackCardIds.begin(), undo.movedCardId);
    }

    if (_gameView != nullptr) {
        _gameView->playCardMoveBack(undo.movedCardId, undo.fromX, undo.fromY);
    }
    return true;
}

bool GameController::moveCardToTray(int cardId, UndoActionType actionType) {
    CardModel* movedCard = _gameModel.getCard(cardId);
    if (movedCard == nullptr) {
        return false;
    }

    UndoModel undo;
    undo.actionType = actionType;
    undo.movedCardId = cardId;
    undo.previousTrayTopCardId = _gameModel.trayTopCardId;
    undo.newTrayTopCardId = cardId;
    undo.fromX = movedCard->x;
    undo.fromY = movedCard->y;
    _undoManager.pushUndo(undo);

    _gameModel.trayTopCardId = cardId;
    movedCard->isInPlayField = false;
    VectorUtils::removeValue(_gameModel.playFieldCardIds, cardId);

    Vec2 trayPos = getTrayPosition();
    movedCard->x = trayPos.x;
    movedCard->y = trayPos.y;
    if (_gameView != nullptr) {
        _gameView->playCardMoveToTray(cardId, trayPos.x, trayPos.y);
    }
    return true;
}

Vec2 GameController::getTrayPosition() const {
    return Vec2(520.0F, 290.0F);
}
