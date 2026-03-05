#pragma once

#include "../../models/CardTypes.h"
#include <string>

/**
 * @brief 卡牌资源配置，负责根据点数和花色拼出资源路径。
 */
class CardResConfig {
public:
    /**
     * @brief 获取卡牌正面资源路径。
     * @param face 点数。
     * @param suit 花色。
     * @return 资源路径。
     */
    static std::string getCardFaceSprite(CardFaceType face, CardSuitType suit);

    /**
     * @brief 获取卡牌背面资源路径。
     * @return 资源路径。
     */
    static std::string getCardBackSprite();
};
