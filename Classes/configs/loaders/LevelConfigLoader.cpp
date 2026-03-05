#include "LevelConfigLoader.h"

LevelConfig LevelConfigLoader::loadLevelConfig(int levelId) {
    (void)levelId;
    LevelConfig config;
    config.playField = {
        {CFT_KING, CST_CLUBS, 250.0F, 1000.0F},
        {CFT_THREE, CST_CLUBS, 300.0F, 800.0F},
        {CFT_THREE, CST_DIAMONDS, 350.0F, 600.0F},
        {CFT_THREE, CST_CLUBS, 850.0F, 1000.0F},
        {CFT_THREE, CST_CLUBS, 800.0F, 800.0F},
        {CFT_TWO, CST_SPADES, 750.0F, 600.0F},
    };
    config.stack = {
        {CFT_THREE, CST_CLUBS, 0.0F, 0.0F},
        {CFT_ACE, CST_HEARTS, 0.0F, 0.0F},
        {CFT_FOUR, CST_CLUBS, 0.0F, 0.0F},
    };
    return config;
}
