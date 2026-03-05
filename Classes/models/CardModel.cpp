#include "CardModel.h"

#include <sstream>

std::string CardModel::toJson() const {
    std::ostringstream ss;
    ss << "{\"cardId\":" << cardId << ",\"face\":" << static_cast<int>(face)
       << ",\"suit\":" << static_cast<int>(suit) << ",\"x\":" << x << ",\"y\":" << y
       << ",\"isFaceUp\":" << (isFaceUp ? "true" : "false")
       << ",\"isInPlayField\":" << (isInPlayField ? "true" : "false") << "}";
    return ss.str();
}

CardModel CardModel::create(int id, CardFaceType faceValue, CardSuitType suitValue, float posX, float posY) {
    CardModel model;
    model.cardId = id;
    model.face = faceValue;
    model.suit = suitValue;
    model.x = posX;
    model.y = posY;
    return model;
}
