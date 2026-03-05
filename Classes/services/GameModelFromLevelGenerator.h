#pragma once

#include "../configs/models/LevelConfig.h"
#include "../models/GameModel.h"

/**
 * @brief 将静态关卡配置转换为运行时游戏模型。
 */
class GameModelFromLevelGenerator {
public:
    /**
     * @brief 生成游戏模型。
     * @param levelConfig 关卡配置。
     * @return 游戏模型。
     */
    static GameModel generateGameModel(const LevelConfig& levelConfig);
};
