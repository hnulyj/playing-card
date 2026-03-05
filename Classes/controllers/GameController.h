#pragma once

#include "../managers/UndoManager.h"
#include "../models/GameModel.h"
#include "../views/GameView.h"
#include "cocos2d.h"

/**
 * @brief 游戏主控制器，协调模型、视图、规则与回退流程。
 */
class GameController {
public:
    /**
     * @brief 初始化并启动关卡。
     * @param parent 挂载父节点。
     * @param levelId 关卡ID。
     * @return true初始化成功。
     */
    bool startGame(cocos2d::Node* parent, int levelId);

    /**
     * @brief 处理主牌区卡牌点击。
     * @param cardId 卡牌ID。
     * @return true已处理。
     */
    bool handlePlayFieldCardClick(int cardId);

    /**
     * @brief 处理点击备用堆抽新牌。
     * @return true已处理。
     */
    bool handleStackClick();

    /**
     * @brief 处理回退按钮。
     * @return true存在回退并执行成功。
     */
    bool handleUndoClick();

private:
    bool moveCardToTray(int cardId, UndoActionType actionType);
    cocos2d::Vec2 getTrayPosition() const;

private:
    /** 游戏运行时模型。 */
    GameModel _gameModel;
    /** 回退管理器。 */
    UndoManager _undoManager;
    /** 游戏视图。 */
    GameView* _gameView = nullptr;
};
