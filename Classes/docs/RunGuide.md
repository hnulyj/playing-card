# 运行指南（Cocos2d-x 3.17）

> 当前仓库只包含 `Classes/` 业务代码，不包含 Cocos2d-x 引擎工程壳。
> 因此需要先创建一个 Cocos2d-x 空项目，再把本仓库代码拷贝进去运行。

## 1. 准备环境

- Cocos2d-x: 3.17
- CMake: 3.16+
- Android Studio（如跑 Android）
- Xcode（如跑 iOS/macOS）

## 2. 创建 Cocos 空项目

在你本地（非本仓库）执行：

```bash
cocos new CardDemo -l cpp -d /path/to/work
```

进入项目：

```bash
cd /path/to/work/CardDemo
```

## 3. 拷贝业务代码

将本仓库 `Classes/` 下内容整体复制到新工程 `Classes/`：

- `configs/`
- `controllers/`
- `docs/`
- `managers/`
- `models/`
- `services/`
- `utils/`
- `views/`

## 4. 创建启动场景（示例）

在新工程 `Classes/` 新增 `GameScene.h/.cpp`，并在 `AppDelegate::applicationDidFinishLaunching` 里运行该场景。

核心逻辑是：

- 创建 `Scene`
- 创建一个根 `Node`
- `GameController::startGame(root, 1)`
- `Director::getInstance()->runWithScene(scene)`

> 说明：这一步是因为本仓库之前只实现了架构与模块，没有绑定到模板项目的入口场景。

## 5. 资源准备

当前默认卡图路径由 `CardResConfig` 生成：

- 正面：`cards/<suit>_<face>.png`
- 背面：`cards/back.png`

请将这些图片放到 `Resources/cards/` 下，否则会显示空白精灵。

## 6. 运行

### macOS / iOS

```bash
cmake -S . -B build
cmake --build build -j
```

或用 Xcode 打开工程运行。

### Android

使用 `proj.android` / `proj.android-studio` 打开并运行。

## 7. 交互验证清单

1. 点击主牌区且点数差 1 的牌，牌应 MoveTo 到手牌顶部并替换。
2. 点击备用堆区域，应抽一张牌到手牌顶部。
3. 连续操作后多次点 Undo，应按逆序动画回退到原位置。

