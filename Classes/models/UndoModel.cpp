#include "UndoModel.h"

#include <sstream>

std::string UndoModel::toJson() const {
    std::ostringstream ss;
    ss << "{\"actionType\":" << static_cast<int>(actionType) << ",\"movedCardId\":" << movedCardId
       << ",\"previousTrayTopCardId\":" << previousTrayTopCardId
       << ",\"newTrayTopCardId\":" << newTrayTopCardId << ",\"fromX\":" << fromX
       << ",\"fromY\":" << fromY << "}";
    return ss.str();
}
