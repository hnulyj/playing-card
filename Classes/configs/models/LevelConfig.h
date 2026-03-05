#pragma once

#include "../../models/CardTypes.h"
#include <vector>

/**
 * @brief 关卡中的单张卡牌静态配置。
 */
struct CardSpawnConfig {
    /** 点数。 */
    CardFaceType face = CFT_NONE;
    /** 花色。 */
    CardSuitType suit = CST_NONE;
    /** X坐标。 */
    float x = 0.0F;
    /** Y坐标。 */
    float y = 0.0F;
};

/**
 * @brief 关卡配置数据，包含主牌区与备用堆初始卡牌列表。
 */
class LevelConfig {
public:
    /** 主牌区配置列表。 */
    std::vector<CardSpawnConfig> playField;
    /** 堆牌区配置列表。 */
    std::vector<CardSpawnConfig> stack;
};
