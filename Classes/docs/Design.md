# 纸牌匹配Demo设计文档（Cocos2d-x 3.17）

## 1. 已实现需求映射
- 点击手牌区替换：`GameController::handleStackClick` 从 `stackCardIds` 抽牌并调用 `moveCardToTray`，`GameView::playCardMoveToTray` 执行 MoveTo。
- 桌面牌与手牌顶部匹配：`GameController::handlePlayFieldCardClick` 使用 `CardRuleService::canMatch` 校验点数差1后替换顶部牌。
- 回退功能：`UndoManager` 维护栈，`GameController::handleUndoClick` 反向恢复模型并播放反向 MoveTo。

## 2. 架构分层说明
- `configs/`：静态关卡与资源映射。
- `models/`：运行时数据结构，支持 `toJson()` 便于存档。
- `views/`：纯展示和输入回调。
- `controllers/`：业务编排与模型更新。
- `managers/`：有状态能力（Undo栈）。
- `services/`：无状态规则与模型生成。
- `utils/`：通用工具。

## 3. 新增一张卡牌如何扩展
1. 在关卡 JSON（或 `LevelConfigLoader`）新增 `CardSpawnConfig`。
2. `GameModelFromLevelGenerator` 会自动分配 `cardId` 并创建 `CardModel`。
3. `GameView` 初始化时自动遍历 `gameModel.cards` 生成 `CardView`，无需改业务代码。

## 4. 新增一种回退类型如何扩展
1. 在 `UndoActionType` 新增枚举值（如 `UAT_AUTO_HINT_MOVE`）。
2. 在产生动作的 Controller 方法中创建 `UndoModel` 记录必要字段并 `pushUndo`。
3. 在 `GameController::handleUndoClick` 增加 `if/else` 分支处理新类型的模型恢复与动画。

## 5. 可继续演进建议
- 接入真实 JSON 解析器读取关卡。
- 把主牌区“覆盖->翻开”规则拆到 `PlayFieldRevealService`。
- 将动画回调串联，保证连续快速操作时的一致性。
