#pragma once

#include <string>

/**
 * @brief 回退记录类型。
 */
enum UndoActionType {
    UAT_NONE = 0,
    UAT_PLAYFIELD_TO_TRAY,
    UAT_STACK_TO_TRAY
};

/**
 * @brief 回退模型，记录一次操作前后的状态。
 */
class UndoModel {
public:
    /** 回退动作类型。 */
    UndoActionType actionType = UAT_NONE;
    /** 操作卡牌ID。 */
    int movedCardId = -1;
    /** 操作前托盘顶部卡牌ID。 */
    int previousTrayTopCardId = -1;
    /** 操作后托盘顶部卡牌ID。 */
    int newTrayTopCardId = -1;
    /** 操作前卡牌X坐标。 */
    float fromX = 0.0F;
    /** 操作前卡牌Y坐标。 */
    float fromY = 0.0F;

    /**
     * @brief 序列化回退记录。
     * @return JSON字符串。
     */
    std::string toJson() const;
};
