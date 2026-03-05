#pragma once

#include "CardView.h"
#include "../models/GameModel.h"
#include "cocos2d.h"
#include <functional>
#include <unordered_map>

/**
 * @brief 游戏总视图，负责主牌区、手牌区、备用牌区展示与动画。
 */
class GameView : public cocos2d::Node {
public:
    /** 创建游戏视图。 */
    static GameView* create(const GameModel& gameModel);

    /** 设置主牌点击回调。 */
    void setOnPlayFieldCardClick(const std::function<void(int)>& onClick);

    /** 设置备用堆点击回调。 */
    void setOnStackClick(const std::function<void()>& onClick);

    /** 设置回退按钮点击回调。 */
    void setOnUndoClick(const std::function<void()>& onClick);

    /** 播放替换顶部牌动画。 */
    void playCardMoveToTray(int movedCardId, float trayX, float trayY);

    /** 播放回退动画。 */
    void playCardMoveBack(int movedCardId, float x, float y);

private:
    bool initView(const GameModel& gameModel);
    void addUndoButton();

private:
    /** 卡牌视图字典。 */
    std::unordered_map<int, CardView*> _cardViews;
    /** 主牌点击回调。 */
    std::function<void(int)> _onPlayFieldCardClick;
    /** 堆牌点击回调。 */
    std::function<void()> _onStackClick;
    /** 回退点击回调。 */
    std::function<void()> _onUndoClick;
};
