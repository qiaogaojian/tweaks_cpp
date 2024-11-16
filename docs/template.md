# C++ Project Template

## 构建要求
- CMake 3.10+
- C++11 兼容的编译器
- Git

## 构建步骤

```bash
#创建并进入构建目录
mkdir build && cd build
#配置项目
cmake ..
#构建项目
cmake --build .
#运行测试
ctest
```

## 项目结构说明
- `src/`: 源代码文件
- `include/`: 头文件
- `tests/`: 单元测试
- `docs/`: 文档
- `third_party/`: 第三方依赖
- `scripts/`: 构建脚本

## 开发指南
1. 所有头文件放在 `include/` 目录下
2. 源文件放在 `src/` 目录下
3. 测试文件放在 `tests/` 目录下
4. 使用 CMake 进行构建管理

