#pragma once

#include "../models/UndoModel.h"
#include <vector>

/**
 * @brief 回退管理器，维护可撤销操作栈。
 */
class UndoManager {
public:
    /**
     * @brief 压入新的回退记录。
     * @param undoModel 回退记录。
     */
    void pushUndo(const UndoModel& undoModel);

    /**
     * @brief 弹出最新回退记录。
     * @param outUndo 输出记录。
     * @return true表示有记录。
     */
    bool popUndo(UndoModel& outUndo);

    /**
     * @brief 是否存在可回退记录。
     * @return true存在。
     */
    bool canUndo() const;

private:
    /** 回退记录栈。 */
    std::vector<UndoModel> _undoRecords;
};
