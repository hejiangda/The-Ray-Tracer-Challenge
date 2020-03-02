# The-Ray-Tracer-Challenge

这是我阅读 **《The Ray Tracer Challenge》** 时写的练习代码，该书在oreilly在线图书馆的地址为：

https://learning.oreilly.com/library/view/the-ray-tracer/9781680506778/

官方地址：

https://pragprog.com/book/jbtracer/the-ray-tracer-challenge

这本书没有给出参考的代码，它完全要求读者自己写出代码完成挑战。它使用cucumber这个BDD（行为驱动开发）工具来给读者一个自测的环境。

## 0. 环境搭建

### 安装cucumber-cpp

参考《Mastering C++ Programming》中的相应章节：

https://www.oreilly.com/library/view/mastering-c-programming/9781786461629/7bf9b089-a842-432f-ba70-02aad6b29f16.xhtml

```shell
git clone https://github.com/cucumber/cucumber-cpp.git
sudo apt install ruby
sudo apt install ruby-dev
sudo gem install bundler
bundle install
git submodule init
git submodule update
sudo apt install ninja-build
sudo apt-get install libboost-all-dev
cmake -E make_directory build
cmake -E chdir build cmake --DCUKE_ENABLE_EXAMPLES=on ..
cmake --build build
cmake --build build --target test
cmake --build build --target features
```

**HelloBDD**文件夹是安装cucumber-cpp后写的一个建立BDD项目的模板，用于熟悉cucumber的使用

Then create your step definition runner (an example is available [here](https://github.com/cucumber/cucumber-cpp/blob/master/examples/Calc/features/step_definitions/BoostCalculatorSteps.cpp)). In order to compile the step definition runner, make sure to add [cucumber include directory](https://github.com/cucumber/cucumber-cpp/blob/master/includes) to the include path and link with *libcucumber-cpp.a* and additional testing libraries (boost unit test).

**已经放弃使用cucumber-cpp改用googletest了，cucumber-cpp的资料太少了，之后在java上用cucumber吧。**

### 在qt中使用googletest进行单元测试

qt文档中关于如何使用googletest的说明：

https://doc.qt.io/qtcreator/creator-autotest.html

googletest官方文档：

https://github.com/google/googletest/blob/master/googletest/docs/primer.md