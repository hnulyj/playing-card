#include "CardResConfig.h"

#include <sstream>

std::string CardResConfig::getCardFaceSprite(CardFaceType face, CardSuitType suit) {
    std::ostringstream ss;
    ss << "cards/" << static_cast<int>(suit) << "_" << static_cast<int>(face) << ".png";
    return ss.str();
}

std::string CardResConfig::getCardBackSprite() {
    return "cards/back.png";
}
