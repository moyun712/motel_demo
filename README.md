## 数据结构课程设计

* 只在 gcc 编译器下测试过
* 引入 git 版本控制，迭代开发

### v1
* 基本的增删改查
* 一个.c文件，完成所有功能
* 适用于小项目，快速原型搭建

### v2
* 引入三层架构，使用 .h 文件定义接口
* 引入 项目管理 具 CMake
* 项目结构较复杂
* 项目更灵活，各层可替代并组合
  * cmd 层：新增命令式交互
  * domain 层：丰富业务逻辑
  * data 层：增加邻接表存储结构

### v3
* 引入自动化测试
  * 单元测试
  * 系统测试

### 下一步
* 后端程序设计：使用对象模型替换 domain 层
* 前端程序设计：提供 Web 端用户体验，替换命令行
  * 复杂界面实现能力
  * 项目管理工具：package.json
* 数据库：使用数据库作为数据层
* 企业应用开发：提供基于 http 的 Web 应用
  * 复杂业务逻辑实现能力
  * 项目管理工具：Maven
* 企业应用测试：设计测试用例，自动化执行测试
* 软件工程：分析与设计
* 各种实习：
  * 复杂前端与后端的综合应用开发
  * 工具的使用：Git，CI/CD
* 算法