# playing-card

基于 Cocos2d-x 3.17 的纸牌匹配玩法示例工程骨架，采用 MVC + Manager + Service 架构。

## 当前状态

- ✅ 已实现：匹配规则、抽牌替换、回退记录与回退动画接口。
- ⚠️ 注意：本仓库不包含完整 Cocos 引擎壳工程（没有 `proj.*` / `AppDelegate` 等模板入口），
  需要把 `Classes/` 代码集成到一个 Cocos2d-x 3.17 空项目后运行。

## 目录

```text
Classes/
├── configs/
├── models/
├── views/
├── controllers/
├── managers/
├── services/
├── utils/
└── docs/
```

## 文档

- 设计文档：`Classes/docs/Design.md`
- 运行指南：`Classes/docs/RunGuide.md`
