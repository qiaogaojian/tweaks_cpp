
## 准备

1. 安装vscode
2. 为VS Code安装C/C++ Extension Pack 扩展组件，其他插件会附带安装
3. Ubuntu系统自带g++和gdb，查看一下
```sh
g++ -V
gdb -V
```

## 配置环境

VS Code 与 Visual Studio或其他的大型IDE的工作机制类似，一般都是每个project有一个单独的工作空间（也就是目录），可以为每个工作空间配置定制的环境，也可以配置默认的环境。在配置C/C++开发环境时，基本会配置3个文件，
- **tasks.json**
- **launch.json**
- **c_cpp_properties.json**
三个文件都在 `.vscode`目录下。

### 1. 编译配置 tasks.json 

为当前工作目录配置编译环境，我们需要创建一个tasks.json文件来告诉VS Code如何来编译源文件，选择 Terminal --> Configure Tasks，然后点击C/C++: g++ build active file，会自动生成一个tasks.json，根据自己的需求来修改，tasks.json是为整个目录配置环境，不需要修改诸如 **“${fileDirname}”** 这样的变量，“type”可以改成“shell”，不能任意;  “label”是task的名称，可以随意，但要与launch.json文件中的变量“preLaunchTask”设置一致; “command” 来指定编译器名，可以不带绝对路径。变量参考详见[官方文档](https://code.visualstudio.com/docs/editor/variables-reference)
```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "type": "cppbuild",
      "label": "g++ build",
      "command": "g++",
      "args": [
        "-fdiagnostics-color=always",
        "-g",
        "${file}",
        "-std=c++11",
        "-o",
        "${fileDirname}/${fileBasenameNoExtension}"
      ],
      "options": {
        "cwd": "${fileDirname}"
      },
      "problemMatcher": ["$gcc"],
      "group": {
        "kind": "build",
        "isDefault": true
      },
      "detail": "compiler: /usr/bin/g++"
    }
  ]
}
```
配置完成后，可以选择 Terminal --> Run Build Task 来编译源文件，生成可执行文件。

### 2. 调试 launch.json

创建一个launch.json文件来配置调试环境，选择Run --> Add Configuration，会自动生成一个launch.json，点击右下角的Add Configuration来选定要加入的配置C/C++: (gdb) Launch（VS Code版本不同，方式有些变化），“program”表示需要调试的文件，下面设置为工作目录 `${fileDirname}` 中的 `${fileBasenameNoExtension}` ，当test.cc处于打开状态时，编译得到的test会被调试，“stopAtEntry”默认为false, 运行调试时，debugger不会在源文件中添加断点，设置为true时，调试会在main函数入口处等待。
```json
{
  "version": "0.2.0",
  "configurations": [
    {
      "name": "Debug C++",
      "type": "cppdbg",
      "request": "launch",
      "program": "${fileDirname}/${fileBasenameNoExtension}",
      "args": [],
      "stopAtEntry": false,
      "cwd": "${fileDirname}",
      "environment": [],
      "externalConsole": false,
      "MIMode": "gdb",
      "preLaunchTask": "g++ build",
      "miDebuggerPath": "/usr/bin/gdb",
      "targetArchitecture": "x86_64",
      "setupCommands": [
        {
          "description": "Enable pretty-printing for gdb",
          "text": "-enable-pretty-printing",
          "ignoreFailures": true
        },
        {
          "description": "Set Disassembly Flavor to Intel",
          "text": "-gdb-set disassembly-flavor intel",
          "ignoreFailures": true
        }
      ]
    }
  ]
}
```

### 3. 补充配置 c_cpp_properties.json

想要进行更多的配置，例如设置编译器路径、改变C++标准等，可以创建一个c_cpp_properties.json文件，使用 ctrl+shift+P 打开命令搜索，找到并选择C/C++：Edit Configurations(JSON)，会自动创建一个c_cpp_properties.json文件，按自己需要修改变量即可。

```json
{
  "configurations": [
    {
      "name": "Linux",
      "includePath": ["${workspaceFolder}/**"],
      "defines": [],
      "compilerPath": "/usr/bin/g++", // from gcc to g++
      "cStandard": "c11", // from c17 to c11
      "cppStandard": "c++11", // from gnu++14 to c++11
      "intelliSenseMode": "linux-gcc-x64"
    }
  ],
  "version": 4
}
```

## 运行和Debug

Create a sample C++ file (main.cpp):
```cpp
// main.cpp
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

### 运行

打开 main.cpp, 右上角点击三角符号 Run C/C++ File

### Debug 

打开 main.cpp, 右上角点击三角符号 Debug C/C++ File

## 参考

[ubuntu 20.04系统下安装VSCode（配置C/C++开发环境） - 夏天/isummer - 博客园](https://www.cnblogs.com/icmzn/p/16244665.html)
[Linux/Ubuntu系统下使用VS Code配置C/C++开发环境 - BooTurbo - 博客园](https://www.cnblogs.com/booturbo/p/17379178.html)
[3.1. C++开发环境搭建 — Ubuntu环境搭建 1.0 documentation](https://ubuntu-develop-document.readthedocs.io/en/latest/Ubuntu-develop/cplusplus.html#id5)