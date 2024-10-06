# closeUntrustedTouchEventsAreBlocked
## 介绍
本项目是为了处理安卓12新增的“不受信任的触摸事件被屏蔽”这个特性的
<br>
因为官方给的解除方法只能在安卓13及以下使用，故写出此工具
## 原理
hook InputDispatcher::isTouchTrustedLocked(这是安卓系统判断触摸是否可信的函数),使其一直返回true
## 使用
执行启动.sh
<br>
## 关于
[注入器来自鸿清](https://github.com/SsageParuders/AndroidPtraceInject)
<br>
InputDispatcher::isTouchTrustedLocked的导出符号部分机型可能发送改变(极小概率，只要oem不动这部分代码一般都不会变)，这个方法在libinputflinger.so里，如果不能使用请手动查找导出符号
