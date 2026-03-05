#pragma once

#include "../models/CardTypes.h"

/**
 * @brief 卡牌规则服务，提供无状态匹配判断。
 */
class CardRuleService {
public:
    /**
     * @brief 判断两张牌点数是否相差1（A与K不首尾相连）。
     * @param a 点数A。
     * @param b 点数B。
     * @return true可匹配。
     */
    static bool canMatch(CardFaceType a, CardFaceType b);
};
