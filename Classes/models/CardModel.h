#pragma once

#include "CardTypes.h"
#include <string>

/**
 * @brief 运行时卡牌数据模型，记录点数、花色、位置和可见性。
 */
class CardModel {
public:
    /** 卡牌唯一ID。 */
    int cardId = -1;
    /** 点数类型。 */
    CardFaceType face = CFT_NONE;
    /** 花色类型。 */
    CardSuitType suit = CST_NONE;
    /** X坐标。 */
    float x = 0.0F;
    /** Y坐标。 */
    float y = 0.0F;
    /** 是否翻开可点击。 */
    bool isFaceUp = true;
    /** 是否仍在主牌区。 */
    bool isInPlayField = true;

    /**
     * @brief 将模型序列化成JSON片段字符串（轻量实现）。
     * @return JSON字符串。
     */
    std::string toJson() const;

    /**
     * @brief 从简化字段创建模型。
     * @param id 卡牌ID。
     * @param faceValue 点数。
     * @param suitValue 花色。
     * @param posX X坐标。
     * @param posY Y坐标。
     * @return 卡牌模型。
     */
    static CardModel create(int id, CardFaceType faceValue, CardSuitType suitValue, float posX, float posY);
};
