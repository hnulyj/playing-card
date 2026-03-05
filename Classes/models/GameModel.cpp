#include "GameModel.h"

#include <sstream>

CardModel* GameModel::getCard(int cardId) {
    auto it = cards.find(cardId);
    if (it == cards.end()) {
        return nullptr;
    }
    return &it->second;
}

std::string GameModel::toJson() const {
    std::ostringstream ss;
    ss << "{\"trayTopCardId\":" << trayTopCardId << ",\"cards\":[";
    bool first = true;
    for (const auto& pair : cards) {
        if (!first) {
            ss << ",";
        }
        first = false;
        ss << pair.second.toJson();
    }
    ss << "]}";
    return ss.str();
}
