#include "GameView.h"

#include "../configs/models/CardResConfig.h"

USING_NS_CC;

GameView* GameView::create(const GameModel& gameModel) {
    auto* ret = new (std::nothrow) GameView();
    if (ret != nullptr && ret->initView(gameModel)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}

void GameView::setOnPlayFieldCardClick(const std::function<void(int)>& onClick) {
    _onPlayFieldCardClick = onClick;
}

void GameView::setOnStackClick(const std::function<void()>& onClick) {
    _onStackClick = onClick;
}

void GameView::setOnUndoClick(const std::function<void()>& onClick) {
    _onUndoClick = onClick;
}

void GameView::playCardMoveToTray(int movedCardId, float trayX, float trayY) {
    auto it = _cardViews.find(movedCardId);
    if (it != _cardViews.end()) {
        it->second->playMoveTo(trayX, trayY, 0.2F);
    }
}

void GameView::playCardMoveBack(int movedCardId, float x, float y) {
    auto it = _cardViews.find(movedCardId);
    if (it != _cardViews.end()) {
        it->second->playMoveTo(x, y, 0.2F);
    }
}

bool GameView::initView(const GameModel& gameModel) {
    if (!Node::init()) {
        return false;
    }

    for (const auto& pair : gameModel.cards) {
        const CardModel& model = pair.second;
        auto spritePath = CardResConfig::getCardFaceSprite(model.face, model.suit);
        auto* cardView = CardView::create(model, spritePath);
        if (cardView == nullptr) {
            continue;
        }

        if (model.isInPlayField) {
            cardView->setOnClick([this](int cardId) {
                if (_onPlayFieldCardClick) {
                    _onPlayFieldCardClick(cardId);
                }
            });
        }
        addChild(cardView);
        _cardViews[pair.first] = cardView;
    }

    auto* stackTouchArea = DrawNode::create();
    stackTouchArea->drawSolidRect(Vec2(60.0F, 160.0F), Vec2(280.0F, 420.0F), Color4F::GRAY);
    addChild(stackTouchArea);

    auto* stackListener = EventListenerTouchOneByOne::create();
    stackListener->onTouchBegan = [this, stackTouchArea](Touch* touch, Event*) {
        if (!stackTouchArea->getBoundingBox().containsPoint(touch->getLocation())) {
            return false;
        }
        if (_onStackClick) {
            _onStackClick();
        }
        return true;
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(stackListener, stackTouchArea);

    addUndoButton();
    return true;
}

void GameView::addUndoButton() {
    auto* undoLabel = Label::createWithSystemFont("Undo", "Arial", 48);
    undoLabel->setPosition(Vec2(900.0F, 240.0F));
    addChild(undoLabel);

    auto* undoListener = EventListenerTouchOneByOne::create();
    undoListener->onTouchBegan = [this, undoLabel](Touch* touch, Event*) {
        if (!undoLabel->getBoundingBox().containsPoint(touch->getLocation())) {
            return false;
        }
        if (_onUndoClick) {
            _onUndoClick();
        }
        return true;
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(undoListener, undoLabel);
}
