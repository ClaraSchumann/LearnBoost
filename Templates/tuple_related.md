1. `integer_sequence`类，把一个整型类型(type) 和一堆非类型参数打包(non-type)
   1. 相关名称
      1. make_integer_sequence
      2. index_sequence 及 make_index_sequence
      3. index_sequence_for
   2. 相关概念
      1. 别名模板
      2. 偏特化
      3. 非类型模板参数包的展开
   3. practice
      1. 把detail放在内层的命名空间里
         1. 内层命名空间得到的东西在外层的命名空间里，detail的存在应该和用户的使用完全无关
   4. 细节
      1. 连续使用using创建中间类型，类似于对变量作运算
      2. 分治思想，减少模板实例化层数
      3. 负责具体实现的detail类，应该通过成员类型之类的东西返回运算结果
      4. 某个特化里，参数包可以不出现在template parameter的末尾。
      5. 目前基本用编译期__builtin来造这个类型，不用手写
   5. 感受
      1. 如果两个模板有互相使用的关系，则其中之一必须为类模板，从而允许前向声明？
      2. 别名不能是别名的别名
         1. 整个alias chain中必须至少涉及到一个类
      3. 生成的过程里是不是不能有`N + 1` `N - 1`之类的东西，否则一定会爆栈？