#pragma once

#include "../models/LevelConfig.h"

/**
 * @brief 关卡配置加载器。
 */
class LevelConfigLoader {
public:
    /**
     * @brief 读取关卡配置（示例中使用内置数据，可替换为JSON文件解析）。
     * @param levelId 关卡ID。
     * @return 关卡配置。
     */
    static LevelConfig loadLevelConfig(int levelId);
};
