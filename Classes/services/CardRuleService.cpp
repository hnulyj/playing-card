#include "CardRuleService.h"

#include <cstdlib>

bool CardRuleService::canMatch(CardFaceType a, CardFaceType b) {
    if (a == CFT_NONE || b == CFT_NONE) {
        return false;
    }
    int diff = std::abs(static_cast<int>(a) - static_cast<int>(b));
    return diff == 1;
}
