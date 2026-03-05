#pragma once

#include "../models/CardModel.h"
#include "cocos2d.h"
#include <functional>

/**
 * @brief 单张卡牌视图，负责显示与点击事件转发。
 */
class CardView : public cocos2d::Node {
public:
    /** 创建卡牌视图。 */
    static CardView* create(const CardModel& model, const std::string& spritePath);

    /** 设置点击回调。 */
    void setOnClick(const std::function<void(int)>& onClick);

    /** 播放移动到目标点动画。 */
    void playMoveTo(float x, float y, float duration);

    /** 获取对应卡牌ID。 */
    int getCardId() const;

private:
    bool initView(const CardModel& model, const std::string& spritePath);

private:
    /** 卡牌ID。 */
    int _cardId = -1;
    /** 精灵节点。 */
    cocos2d::Sprite* _sprite = nullptr;
    /** 点击回调。 */
    std::function<void(int)> _onClick;
};
