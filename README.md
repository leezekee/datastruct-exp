# 数据结构实验大作业
## 图的深度优先遍历算法演示
### 依赖
项目使用EGE图形库
### 工程结构
`bin`:存放编译生成的exe文件
> 由于git是不支持exe和dll文件的，所以bin目录下的exe文件就存放在`bin.zip`中

`example`:存放演示代码

`include`:存放头文件

`lib`:存放编译产生的库文件

`src`:存放源文件

### 基本思路
使用`Graph`类存放图的基本信息：邻接矩阵、结点信息
使用`GraphNode`类存放结点的信息

实现BFS、DFS可视化思路基本为：

1. 将所有结点`visibility`设置为false，即全不可见

2. 进行BFS\DFS，将获得的结果依次放入一个数组中，并且将再次将所有结点设为不可见

3. 定义指针指向数组中元素，从而依次画出0下标到index下标中的元素，模拟BFS\DFS操作，通过控制index数值即可实现单步双向操作

### 实例代码: `example/visualization-of-bfs-and-dfs.cpp`
