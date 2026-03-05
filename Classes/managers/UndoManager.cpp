#include "UndoManager.h"

void UndoManager::pushUndo(const UndoModel& undoModel) {
    _undoRecords.push_back(undoModel);
}

bool UndoManager::popUndo(UndoModel& outUndo) {
    if (_undoRecords.empty()) {
        return false;
    }
    outUndo = _undoRecords.back();
    _undoRecords.pop_back();
    return true;
}

bool UndoManager::canUndo() const {
    return !_undoRecords.empty();
}
