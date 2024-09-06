# closeUntrustedTouchEventsAreBlocked
##介绍
本项目是为了处理安卓12新增的“不受信任的触摸事件被屏蔽”这个特性的
<br>
因为官方给的解除方法只能在安卓13及以下使用，故写出此工具
## 原理
hook InputDispatcher::isTouchTrustedLocked(这是判断是否安卓系统判断是否屏蔽触摸的),使其一直返回true
## 使用
./Inject -n system_server -so ./hookInput.so
<br>
注入器来自鸿清
