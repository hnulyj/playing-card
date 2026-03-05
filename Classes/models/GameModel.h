#pragma once

#include "CardModel.h"
#include <string>
#include <unordered_map>
#include <vector>

/**
 * @brief 游戏运行时总模型，持有主牌区与堆牌区数据。
 */
class GameModel {
public:
    /** 主牌区卡牌ID列表。 */
    std::vector<int> playFieldCardIds;
    /** 备用堆卡牌ID列表（队头为下次抽取）。 */
    std::vector<int> stackCardIds;
    /** 当前手牌区顶部卡牌ID。 */
    int trayTopCardId = -1;
    /** 全部卡牌存储。 */
    std::unordered_map<int, CardModel> cards;

    /**
     * @brief 按ID查询卡牌。
     * @param cardId 卡牌ID。
     * @return 卡牌指针，找不到返回nullptr。
     */
    CardModel* getCard(int cardId);

    /**
     * @brief 序列化游戏状态。
     * @return JSON字符串。
     */
    std::string toJson() const;
};
