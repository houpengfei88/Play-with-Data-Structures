# Algorithm-With-C

**大家好，欢迎大家来到我在[慕课网](https://www.imooc.com/t/108955)上购买的实战课程[《玩儿转数据结构》](https://coding.imooc.com/class/207.html)的C++代码仓库。[官方代码仓库](https://github.com/liuyubobobo/Play-with-Data-Structures)为刘宇波老师使用JAVA语言所写。欢迎大家购买和观看。波波老师的课非常实用，而且性价比极高。**

#### 使用环境

* Debian (WSL)
* g++ 8.3.0
* CMake 3.13.4
* VSCode 
* VSCode 插件 Remote WSL
* C++17

#### 说明

* 目录下假如是LeetCode的题目,则直接拷贝代码到LeetCode相应的题目下,直接可以运行,代码都经过验证
* 目录下假如没有CMakeLists.txt 则该目录下代码无需编译
* 仿照波波老师的目录而做一一对应
* 最后两章的代码不完善，以及我在改前面的代码，大家多担待

#### 个人联系方式

* 邮箱：2597457485@qq.com
* QQ：2597457485

## 课程源码目录 

| **第一章 欢迎大家学习《玩儿转数据结构》** | [无代码] | 
| :--- | :---: | 
| 1-1 欢迎学习《玩儿转数据结构》 | [无代码] |
| 1-2 学习数据结构（和算法）到底有没有用？ | [无代码] |
| 1-3 关于课程学习的更多注意事项 | [无代码] |
| 1-4 课程编程环境搭建 | [无代码] |
| 1-5 关于课程的其他语言支持:Python, C++, JS, Go | [无代码] |
| 1-6 在学习数据结构的具体知识前，你可能想读一读这两篇文章 | [无代码] |
| **第二章 不要小瞧数组** | [章节C++源码](02-Arrays/) |
| 2-1 使用Java中的数组 | [C++](02-Arrays/01-Array-Basics/) |
| 2-2 二次封装属于我们自己的数组 | [C++](02-Arrays/02-Create-Our-Own-Array/) |
| 2-3 向数组中添加元素 | [C++](02-Arrays/03-Add-Element-in-Array/) |
| 2-4 数组中查询元素和修改元素 | [C++](02-Arrays/04-Query-and-Update-Element/) |
| 2-5 包含，搜索和删除 | [C++](02-Arrays/05-Contain-Find-and-Remove/) |
| 2-6 使用泛型 | [C++](02-Arrays/06-Generic-Data-Structures/) |
| 2-7 动态数组 | [C++](02-Arrays/07-Dynamic-Array/) |
| 2-8 简单的复杂度分析 | [无代码] |
| 2-9 均摊复杂度和防止复杂度的震荡 | [C++](02-Arrays/09-Amortized-Time-Complexity/) |
| **第三章 栈和队列** | [章节C++源码](03-Stacks-and-Queues/) |
| 3-1 栈和栈的应用：撤销操作和系统栈 | [无代码] |
| 3-2 栈的基本实现 | [C++](03-Stacks-and-Queues/02-Array-Stack/) |
| 3-3 栈的另一个应用：括号匹配 | [C++](03-Stacks-and-Queues/03-A-Stack-Problem-in-Leetcode/) |
| 3-4 关于Leetcode的更多说明 | [C++](03-Stacks-and-Queues/04-More-about-Leetcode/) |
| 3-5 数组队列 | [C++](03-Stacks-and-Queues/05-Array-Queue/) |
| 3-6 循环队列 | [C++](03-Stacks-and-Queues/06-Loop-Queue/) |
| 3-7 循环队列的实现 | [C++](03-Stacks-and-Queues/07-Implementation-of-Loop-Queue/) |
| 3-8 数组队列和循环队列的比较 | [C++](03-Stacks-and-Queues/08-Queues-Comparison/) |
| 补充代码1: 不浪费一个空间的循环队列 | [在3-6小节已经实现没有size成员变量的循环队列故不提供] |
| 补充代码2: 没有size成员变量的循环队列 | [请看3-8小节]) |
| **第四章 最基础的动态数据结构：链表** | [章节C++源码](04-Linked-List/) |
| 4-1 什么是链表 | [C++](04-Linked-List/01-Linked-List-Basics/) | 
| 4-2 在链表中添加元素 | [C++](04-Linked-List/02-Add-Elements-in-LinkedList/) | 
| 4-3 使用链表的虚拟头结点 | [C++](04-Linked-List/03-DummyHead-in-LinkedList/) | 
| 4-4 链表的遍历，查询和修改 | [C++](04-Linked-List/04-Query-and-Update-in-LinkedList/) | 
| 4-5 从链表中删除元素 | [C++](04-Linked-List/05-Remove-Element-in-LinkedList/) | 
| 4-6 使用链表实现栈 | [C++](04-Linked-List/06-Implement-Stack-in-LinkedList/) | 
| 4-7 带有尾指针的链表：使用链表实现队列 | [C++](04-Linked-List/07-Implement-Queue-in-LinkedList/) | 
| **第五章 透过链表看递归** | [章节C++源码](05-Recursion/) |
| 5-1 Leetcode中和链表相关的问题 | [C++](05-Recursion/01-Linked-List-Problems-in-Leetcode/) |
| 5-2 测试自己的Leetcode链表代码 | [C++](05-Recursion/02-Test-Your-LinkedList-Solution/) | 
| 5-3 递归基础与递归的宏观语意 | [C++](05-Recursion/03-Recursion-Basics/) | 
| 5-4 链表与递归 | [C++](05-Recursion/04-LinkedList-and-Recursion/) | 
| 5-5 递归运行的机制：递归的微观解读 | [无代码] | 
| 5-6 递归算法的调试 | [C++](05-Recursion/06-Debug-Recursive-Solution/) | 
| 5-7 更多和链表相关的问题 | [无代码] |
| 补充代码1: 单链表的递归实现 | [C++](05-Recursion/Optional-01-Recursive-LinkedList/) |
| 补充代码2: 斯坦福大学单链表的18个问题 | [PDF](05-Recursion/Optional-02-Stanford-LinkedList-Problems/)<br/>[代码整理中，敬请期待] |
| 补充代码3: 双链表 | [整理中，敬请期待] |
| 补充代码4: 循环双链表 | [整理中，敬请期待] |
| 补充代码5: 数组链表 | [整理中，敬请期待] |
| **第六章 二分搜索树** | [章节C++源码](06-Binary-Search-Tree/) |
| 6-1 为什么要研究树结构 | [无代码] |
| 6-2 二分搜索树基础 | [C++](06-Binary-Search-Tree/02-Binary-Search-Tree-Basics/) |
| 6-3 向二分搜索树中添加元素 | [C++](06-Binary-Search-Tree/03-Add-Elements-in-BST/) |
| 6-4 改进添加操作：深入理解递归终止条件 | [C++](06-Binary-Search-Tree/04-Improved-Add-Elements-in-BST/) |
| 6-5 二分搜索树的查询操作 | [C++](06-Binary-Search-Tree/05-Search-in-BST/) |
| 6-6 二分搜索树的前序遍历 | [C++](06-Binary-Search-Tree/06-PreOrder-Traverse-in-BST/) |
| 6-7 二分搜索树的中序遍历和后序遍历 | [C++](06-Binary-Search-Tree/07-InOrder-and-PostOrder-Traverse-in-BST/) |
| 6-8 深入理解二分搜索树的前中后序遍历 | [无代码] |
| 6-9 二分搜索树前序遍历的非递归实现 | [C++](06-Binary-Search-Tree/09-Non-Recursion-Preorder-Traverse-in-BST/) |
| 6-10 二分搜索树的层序遍历 | [C++](06-Binary-Search-Tree/10-Level-Traverse-in-BST/) |
| 6-11 删除二分搜索树的最大元素和最小元素 | [C++](06-Binary-Search-Tree/11-Remove-Min-and-Max-in-BST/) |
| 6-12 删除二分搜索树的任意元素 | [C++](06-Binary-Search-Tree/12-Remove-Elements-in-BST/) |
| 6-13 更多二分搜索树相关话题 | [无代码] |
| 补充代码1: 斯坦福大学Binary Tree相关问题 | [PDF](06-Binary-Search-Tree/Optional-01-Standford-Binary-Tree/)<br/>[代码整理中，敬请期待] |
| 补充代码2: 斯坦福大学Tree List相关问题 | [PDF](06-Binary-Search-Tree/Optional-02-Standford-TreeList/)<br/>[代码整理中，敬请期待] |
| 补充代码3: 二叉树前中后序非递归遍历的经典实现 | [C++](06-Binary-Search-Tree/Optional-03-Binary-Tree-Classic-Nonrecursive-Traversal/) |
| 补充代码4: 模拟系统栈前中后序遍历的非递归实现 | [玩转算法面试，第六章2，3小节](https://coding.imooc.com/lesson/82.html#mid=2675) |
| 补充代码5: 二叉树Morris遍历前中后序实现 | [C++](06-Binary-Search-Tree/Optional-05-Binary-Tree-Morris-Traversal/) |
| 补充代码6: 二分搜索树其他方法的非递归实现 | [整理中，敬请期待] |
| 补充代码7: 前驱和后继操作 | [整理中，敬请期待] |
| 补充代码8: floor和ceil操作 | [整理中，敬请期待] |
| 补充代码9: 节点内维护size的二分搜索树 | [整理中，敬请期待] |
| 补充代码10: rank和select操作 | [整理中，敬请期待] |
| 补充代码11: 节点内维护depth的二分搜索树 | [整理中，敬请期待] |
| 补充代码12: 节点内维护count的二分搜索树<br/>(支持重复元素的二分搜索树) | [整理中，敬请期待] |
| 补充代码13: 有重复元素节点的二分搜索树<br/>(另一种支持重复元素的二分搜索树实现) | [整理中，敬请期待] |
| **第七章 集合和映射** | [章节C++源码](07-Set-and-Map/) |
| 7-1 集合基础和基于二分搜索树的集合实现 | [C++](07-Set-and-Map/01-Set-Basics-and-BSTSet/) |
| 7-2 基于链表的集合实现 | [C++](07-Set-and-Map/02-LinkedListSet/) |
| 7-3 集合类的复杂度分析 | [C++](07-Set-and-Map/03-Time-Complexity-of-Set/) |
| 7-4 Leetcode中的集合问题和更多集合相关问题 | [C++](07-Set-and-Map/04-TreeSet-and-Set-Problems-in-Leetcode/) |
| 7-5 映射基础 | [C++](07-Set-and-Map/05-Map-Basics/) |
| 7-6 基于链表的映射实现 | [C++](07-Set-and-Map/06-LinkedListMap/) |
| 7-7 基于二分搜索树的映射实现 | [C++](07-Set-and-Map/07-BSTMap/) |
| 7-8 映射的复杂度分析和更多映射相关问题 | [C++](07-Set-and-Map/08-More-about-Map/) |
| 7-9 Leetcode上更多集合和映射的问题 | [C++](07-Set-and-Map/09-Leetcode-Problems-about-Map-and-Set/) |
| 补充代码1: 更完整的基于二分搜索树的有序集合 | [整理中，敬请期待] |
| 补充代码2: 不同底层实现的有序集合对比 | [整理中，敬请期待] |
| 补充代码3: 更完整的基于二分搜索树的有序映射 | [整理中，敬请期待] |
| 补充代码4: 不同底层实现的有序映射对比 | [整理中，敬请期待] |
| 补充代码5: 多重集合 | [整理中，敬请期待] |
| 补充代码6: 多重映射 | [整理中，敬请期待] |
| 补充代码7: 基于映射实现的集合 | [整理中，敬请期待] |
| **第八章 堆和优先队列** | [章节C++源码](08-Heap-and-Priority-Queue/) |
| 8-1 什么是优先队列 | [无代码] |
| 8-2 堆的基础表示 | [C++](08-Heap-and-Priority-Queue/02-Heap-Basics/) |
| 8-3 向堆中添加元素和Sift Up | [C++](08-Heap-and-Priority-Queue/03-Add-and-Sift-Up-in-Heap/) |
| 8-4 从堆中取出元素和Sift Down | [C++](08-Heap-and-Priority-Queue/04-Extract-and-Sift-Down-in-Heap/) |
| 8-5 Heapify 和 Replace | [C++](08-Heap-and-Priority-Queue/05-Heapify-and-Replace-in-Heap/) |
| 8-6 基于堆的优先队列 | [C++](08-Heap-and-Priority-Queue/06-Priority-Queue/) |
| 8-7 Leetcode上优先队列相关问题 | [C++](08-Heap-and-Priority-Queue/07-Priority-Queue-Problems-in-Leetcode/) |
| 8-8 Java中的PriorityQueue | [C++](08-Heap-and-Priority-Queue/08-Priority-Queue-in-Java/) |
| 8-9 和堆相关的更多话题和广义队列 | [无代码] |
| 补充代码1: 普通线性结构和顺序线性结构实现的优先队列 | [整理中，敬请期待] |
| 补充代码2: 最小堆 | [整理中，敬请期待] |
| 补充代码3: 堆排序 | [整理中，敬请期待] |
| 补充代码4: 索引堆 | [整理中，敬请期待] |
| 补充代码5: 双向优先队列 | [整理中，敬请期待] |
| 补充代码6: 多叉堆 | [整理中，敬请期待] |
| 补充代码7: 二项堆 | [整理中，敬请期待] |
| 补充代码8: 斐波那契堆 | [整理中，敬请期待] |
| 补充代码9: 基于事件堆的粒子检测碰撞 | [整理中，敬请期待] |
| **第九章 线段树** | [章节C++源码](09-Segment-Tree/) |
| 9-1 什么是线段树 | [无代码] |
| 9-2 线段树基础表示 | [C++](09-Segment-Tree/02-Segment-Tree-Basics/) |
| 9-3 创建线段树 | [C++](09-Segment-Tree/03-Building-Segment-Tree/) |
| 9-4 线段树中的区间查询 | [C++](09-Segment-Tree/04-Query-in-Segment-Tree/) |
| 9-5 Leetcode上线段树相关的问题 | [C++](09-Segment-Tree/05-Segment-Tree-Problems-in-Leetcode/) |
| 9-6 线段树中的更新操作 | [C++](09-Segment-Tree/06-Update-Single-Element-in-Segment-Tree/) |
| 9-7 更多线段树相关的话题 | [无代码] |
| 补充代码1: 使用节点表示的线段树 | [整理中，敬请期待] |
| 补充代码2: 链式存储的线段树 | [整理中，敬请期待] |
| 补充代码3: 动态线段树 | [整理中，敬请期待] |
| 补充代码4: 线段树的懒惰传播 | [整理中，敬请期待] |
| 补充代码5: 二维线段树 | [整理中，敬请期待] |
| 补充代码6: 树状数组(Binary Index Tree) | [整理中，敬请期待] |
| 补充代码7: RMQ问题 | [整理中，敬请期待] |
| **第十章 Trie** | [章节C++源码](10-Trie/) |
| 10-1 什么是Trie字典树 | [无代码] |
| 10-2 Trie字典树基础 | [C++](10-Trie/02-Trie-Basics/) |
| 10-3 Trie字典树的查询 | [C++](10-Trie/03-Searching-in-Trie/) | 
| 10-4 Trie字典树的前缀查询 | [C++](10-Trie/04-Prefix-in-Trie/) |
| 10-5 Trie字典树和简单的模式匹配 | [C++](10-Trie/05-Trie-and-Pattern-Match/) |
| 10-6 Trie字典树和字符串映射 | [C++](10-Trie/06-Trie-and-Map/) |
| 10-7 更多和Trie字典树相关的话题 | [无代码] |
| 10-8 [文字补充] 基于哈希表或者数组的Trie | [C++](10-Trie/08-Trie-Using-HashMap-and-Array/) |
| 补充代码1: Trie的递归实现 | [C++](10-Trie/Optional-01-Trie-in-Recursion/) |
| 补充代码2: 使用Trie删除元素 | [整理中，敬请期待] |
| 补充代码3: TrieSet和TrieMap | [整理中，敬请期待] |
| 补充代码4: 压缩字典树 | [整理中，敬请期待] |
| 补充代码5: 三分搜索Trie (Ternary Search Trie) | [整理中，敬请期待] |
| 补充代码6: 子串查询算法 | [整理中，敬请期待] |
| 补充代码7: 文件压缩算法 | [整理中，敬请期待] |
| 补充代码8: 模式匹配算法 | [整理中，敬请期待] |
| **第十一章 并查集** | [章节C++源码](11-Union-Find/) |
| 11-1 什么是并查集 | [C++](11-Union-Find/01-What-is-UnionFind/) |
| 11-2 Quick Find | [C++](11-Union-Find/02-Quick-Find/) |
| 11-3 Quick Union | [C++](11-Union-Find/03-Quick-Union/) |
| 11-4 基于size的优化 | [C++](11-Union-Find/04-Optimized-by-Size/) |
| 11-5 基于rank的优化 | [C++](11-Union-Find/05-Optimized-by-Rank/) |
| 11-6 路径压缩 | [C++](11-Union-Find/06-Path-Compression/) |
| 11-7 更多和并查集相关的话题 | [C++](11-Union-Find/07-More-about-Union-Find/) |
| **第十二章 平衡树和AVL** | [章节C++源码](12-AVL-Tree/) |
| 12-1 平衡树和AVL | [无代码] |
| 12-2 计算节点的高度和平衡因子 | [C++](12-AVL-Tree/02-Calculating-Balance-Factor/) |
| 12-3 检查二分搜索树性质和平衡性 | [C++](12-AVL-Tree/03-Checking-Balancing-and-Binary-Search-Property/) |
| 12-4 旋转操作的基本原理 | [C++](12-AVL-Tree/04-Rotation-Operations/) |
| 12-5 左旋转和右旋转的实现 | [C++](12-AVL-Tree/05-The-Implementation-of-Left-Rotation-and-Right-Rotation/) |
| 12-6 LR 和 RL | [C++](12-AVL-Tree/06-LR-and-RL/) |
| 12-7 从AVL树中删除元素 | [C++](12-AVL-Tree/07-Remove-Elements-in-AVL-Tree/) |
| 12-8 基于AVL树的集合和映射 | [C++](12-AVL-Tree/08-Map-and-Set-in-AVL-Tree/) |
| 补充代码1: AVL树的优化 | [整理中，敬请期待] |
| **第十三章 红黑树** | [章节C++源码](13-Red-Black-Tree/) |
| 13-1 红黑树与2-3树 | [无代码] |
| 13-2 2-3树的绝对平衡性 | [无代码] |
| 13-3 红黑树与2-3树的等价性 | [C++](13-Red-Black-Tree/03-The-Equivalence-of-RBTree-and-2-3-Tree/) |
| 13-4 红黑树的基本性质和复杂度分析 | [无代码] |
| 13-5 保持根节点为黑色和左旋转 | [C++](13-Red-Black-Tree/05-Keep-Root-Black-and-Left-Rotation/) |
| 13-6 颜色翻转和右旋转 | [C++](13-Red-Black-Tree/06-Flip-Colors-and-Right-Rotation/) |
| 13-7 红黑树中添加新元素 | [C++](13-Red-Black-Tree/07-Adding-Elements-in-Red-Black-Tree/) |
| 13-8 红黑树的性能测试 | [C++](13-Red-Black-Tree/08-The-Performance-of-Red-Black-Tree/) |
| 13-9 更多红黑树相关的话题 | [无代码] |
| 13-10 [文字补充] 红黑树任何不平衡都可以在三次旋转内解决？ | [无代码] |
| 补充代码1: 红黑树中的删除最大元素 | [整理中，敬请期待] |
| 补充代码2: 红黑树中的删除最小元素 | [整理中，敬请期待] |
| 补充代码3: 红黑树中的删除任意元素 | [整理中，敬请期待] |
| 补充代码4: 基于红黑树的集合和映射 | [整理中，敬请期待] |
| 补充代码5: 右倾红黑树 | [整理中，敬请期待] |
| 补充代码6: 《算法导论》中红黑树的实现 | [整理中，敬请期待] |
| 补充代码7: 2-3 树的实现 | [整理中，敬请期待] |
| 补充代码8: 伸展树 Splay Tree | [整理中，敬请期待] |
| **第十四章 哈希表** | [章节C++源码](14-Hash-Table/) |
| 14-1 哈希表基础 | [C++](14-Hash-Table/01-Hash-Table-Basics/) |
| 14-2 哈希函数 | [无代码] |
| 14-3 Java中的hashCode方法 | [C++](14-Hash-Table/03-Hash-Function-in-Java/) |
| 14-4 链地址法 Seperate Chaining | [无代码] |
| 14-5 实现属于我们自己的哈希表 | [C++](14-Hash-Table/05-Hash-Table-Implementation/) |
| 14-6 哈希表的动态空间处理与复杂度分析 | [C++](14-Hash-Table/06-Resizing-in-Hash-Table/) |
| 14-7 哈希表更复杂的动态空间处理方法 | [C++](14-Hash-Table/07-More-About-Resizing-in-Hash-Table/) |
| 14-8 更多哈希冲突的处理方法 | [无代码] |
| 补充代码1: 每个地址存储链表的哈希表 | [整理中，敬请期待] |
| 补充代码2: 每个地址可以从链表转换到红黑树的哈希表 | [整理中，敬请期待] |
| 补充代码3: 基于哈希表的无序映射和无序集合 | [整理中，敬请期待] |
| 补充代码4: 开放地址线性探测解决哈希冲突 | [整理中，敬请期待] |
| 补充代码5: 开放地址二次探测解决哈希冲突 | [整理中，敬请期待] |
| 补充代码6: 开放地址双重哈希解决哈希冲突 | [整理中，敬请期待] |
| 补充代码7: 再哈希法解决哈希冲突 | [整理中，敬请期待] |
| 补充代码8: Coalesced Hashing | [整理中，敬请期待] |
| **第十五章 结语** | [无代码] |
| 15-1 更广阔的数据结构的世界，大家加油！ | [无代码] |
| 15-2 [文字补充]更多数据结构的练习：） | [无代码] |
| **第十六章 补充章节：B类树** | [更新中，敬请期待] |
| [由于B类树不是课程最初规划内容] | [更新时间待定，敬请期待] |

---

由于慕课网规定，课程不再提供PPT下载，仅提供ppt转pdf水印版，请谅解。具体文件在各章文件夹下。


