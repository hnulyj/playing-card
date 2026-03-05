#include "CardView.h"

USING_NS_CC;

CardView* CardView::create(const CardModel& model, const std::string& spritePath) {
    CardView* ret = new (std::nothrow) CardView();
    if (ret != nullptr && ret->initView(model, spritePath)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}

void CardView::setOnClick(const std::function<void(int)>& onClick) {
    _onClick = onClick;
}

void CardView::playMoveTo(float x, float y, float duration) {
    runAction(MoveTo::create(duration, Vec2(x, y)));
}

int CardView::getCardId() const {
    return _cardId;
}

bool CardView::initView(const CardModel& model, const std::string& spritePath) {
    if (!Node::init()) {
        return false;
    }

    _cardId = model.cardId;
    setPosition(Vec2(model.x, model.y));
    _sprite = Sprite::create(spritePath);
    if (_sprite != nullptr) {
        addChild(_sprite);
    }

    auto* touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = [this](Touch* touch, Event*) {
        Rect rect = getBoundingBox();
        if (!rect.containsPoint(touch->getLocation())) {
            return false;
        }
        if (_onClick) {
            _onClick(_cardId);
        }
        return true;
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    return true;
}
