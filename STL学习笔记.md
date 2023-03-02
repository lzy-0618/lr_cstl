# STL学习笔记

- 适配器：一种用来修饰容器、仿函数或迭代器接口的东西。
例如STL 提供的 queue 和 stack，虽然看似容器，
其实只能算是一种容器适配器，
因为它们的底部完全借助 deque，所有操作都由底层的 deque 供应。

[STL常识知识快速复习](https://zhuanlan.zhihu.com/p/476016358)

[STL面试复习](https://blog.csdn.net/daaikuaichuan/article/details/80717222)


# **基础STL的实现**

- string ok
- vector
- map
- priority-queue
- unordered_map
- 智能指针


## 报错
mystring.cpp:74:35: error: default argument given for parameter 1 of 'my::string::string(const char*)' [-fpermissive]
 string::string(const char* str= "")
                                   ^
mystring.cpp:15:2: note: previous specification in 'my::string::string(const char*)' here
  string(const char* str = "");   // 构造函数

原因：
声明时带有默认参数的函数在定义时又将默认参数指定一次。
编译器判断这种情况非法。
解决办法：
在定义时不指定默认参数值。

 error: invalid use of 'this' in non-member function
原因：类函数写成了普通的函数


g++ ：
-o 生成文件命名
-l 链接库 常用链接库 pthread gtest
-std=c++11 规定C++标准


google test学习链接：
- [google test知乎基本教程](https://zhuanlan.zhihu.com/p/544491071)
- [google test csdn教程](https://blog.csdn.net/CrackLewis/article/details/129179719)
- [google test专栏](https://cloud.tencent.com/developer/article/1471006)
- [google test常用断案GitHub](https://github.com/AngryHacker/articles/blob/master/src/open_source_components/google_gtest.md)



linux 环境（系统编程 + 网络编程）编程：
- [ftp 服务器实现](https://download.csdn.net/download/weixin_26731219/19593678?ops_request_misc=&request_id=&biz_id=103&spm=1018.2226.3001.4451.3)
- [linux 网络聊天器](https://download.csdn.net/download/scanf_linux/10889095?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522167759050216800215092767%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fdownload.%2522%257D&request_id=167759050216800215092767&biz_id=1&spm=1018.2226.3001.4451.3)
- [c语言实现shell命令解释器](https://download.csdn.net/download/weixin_42172572/15734864?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522167759039416800222836060%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fdownload.%2522%257D&request_id=167759039416800222836060&biz_id=1&spm=1018.2226.3001.4451.19)
- [银行管理账户](https://download.csdn.net/download/baimashaokun/11647119?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522167759039416800222836060%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fdownload.%2522%257D&request_id=167759039416800222836060&biz_id=1&spm=1018.2226.3001.4451.16)
- [linux 媒体音乐播放器项目设计](https://download.csdn.net/download/dhyuan_88/20009811?ops_request_misc=&request_id=&biz_id=103&spm=1018.2226.3001.4451.3)




