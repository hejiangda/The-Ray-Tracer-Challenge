# The-Ray-Tracer-Challenge

这是我阅读《The Ray Tracer Challenge》时写的练习代码，该书在oreilly在线图书馆的地址为：

https://learning.oreilly.com/library/view/the-ray-tracer/9781680506778/

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

