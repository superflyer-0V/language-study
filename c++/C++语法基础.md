# C++语法基础
> 对比C语言：C++兼容C全部语法，增加面向对象、引用、类、STL、命名空间等特性，**全程不使用`using namespace std;`**。

## 1. 第一个C++程序
```cpp
#include <iostream>   // C++输入输出头文件，替代c的stdio.h

int main()
{
    std::cout << "Hello C++" << std::endl;  // std::cout输出，std::endl换行刷新缓冲区
    return 0;
}
```
- `std::cout`：标准输出对象
- `<<`：输出运算符
- `std::cin`：标准输入对象，`>>`输入运算符

输入示例：
```cpp
int a;
std::cin >> a;
```

## 2. 命名空间 namespace
用来解决命名冲突，C语言没有。
```cpp
namespace MySpace{
    int num = 10;
}

int main(){
    std::cout << MySpace::num;   // 域解析运算符 ::
    return 0;
}
```

## 3. 数据类型
### 基础内置类型
|类型|说明|
|---|---|
|`int`|整型|
|`short`|短整型|
|`long long`|长长整型|
|`float`|单精度|
|`double`|双精度|
|`char`|字符|
|`bool`|布尔，`true/false`，C语言没有bool|

```cpp
bool flag = true;
```

### 常量
1. `const` 常量（推荐C++）
```cpp
const int MAX = 100;
```
2. `#define MAX 100` 宏（C风格，简单文本替换，不做类型检查）

### auto自动推导类型(C++11)
```cpp
auto x = 3.14; // x推导为double
```

## 4. 引用 &（C++特有，重点）
> 引用：变量的别名，**不是新变量**，必须初始化，不能空，不能改指向。
```cpp
int a = 10;
int &b = a;   // b是a的别名，b、a操作同一块内存
b = 20;
// 此时a也变成20
```
> 和指针区别：引用更安全，不能为NULL；指针可以空，可以改指向。

**函数中使用引用，实现传参修改实参，不需要指针**
```cpp
void swap(int &x, int &y){
    int t = x;
    x = y;
    y = t;
}
```

const引用：禁止修改
```cpp
const int &r = a;
```

## 5. 函数
### 函数默认参数（C++新增）
```cpp
void func(int a, int b = 10){ // b默认值10
    std::cout << a+b;
}
//调用 func(5); 等价 func(5,10)
```
> 默认参数必须放在参数列表靠右位置。

### 函数重载
同一个作用域，**函数名相同，参数列表不同（个数/类型/顺序）**，返回值不能作为重载区分条件。
```cpp
void show(int a){}
void show(double a){}
void show(int a,int b){}
```

### 内联函数 inline
减少函数调用开销，编译器直接把代码嵌入调用处。
```cpp
inline int add(int a,int b){
    return a+b;
}
```

## 6. 内存管理 new / delete（C++，替代malloc/free）
```cpp
//单个对象
int *p = new int;    //堆上分配int
*p = 100;
delete p;            //释放

//数组
int *arr = new int[5];
delete[] arr;        //数组释放要加[]
```
> new失败默认抛异常；malloc失败返回NULL。

## 7. 结构体 struct增强
C++的struct和class几乎一样，struct默认**public**访问权限。
```cpp
struct Student{
    int id;
    void print(){   // C++结构体可以写成员函数，C不行
        std::cout << id;
    }
};
```

## 8. 面向对象基础：类 class
- `class` 默认访问权限 **private私有**
- `public`：公开，外部可访问
- `private`：私有，仅类内部访问
- `protected`：保护，子类可以访问

```cpp
class Person{
private:
    int age;    //私有成员
public:
    //构造函数：和类同名，无返回值，创建对象自动调用
    Person(int a){
        age = a;
    }
    //成员函数
    void show(){
        std::cout << age;
    }
};

int main(){
    Person p(18); //创建对象，调用构造函数
    p.show();
    return 0;
}
```

- 构造函数：对象创建自动执行，初始化成员
- 析构函数 `~Person()`：对象销毁自动调用，做资源释放，无参数无返回值

## 9. 字符串 std::string（C++字符串，替代char[]）
```cpp
#include <string>

int main()
{
    std::string s = "hello";
    s += " world";
    std::cout << s.size();   //长度
    return 0;
}
```

## 10. STL简单介绍（标准模板库）
```cpp
#include <vector>

int main()
{
    std::vector<int> v;  //动态数组
    v.push_back(10);
    return 0;
}
```

## 11. 指针补充
```cpp
int a=10;
int *p = &a;    //普通指针
int *const q = &a; //指针常量：指针本身不可修改，值可以改
const int *r = &a; //常量指针：指向的值不可改，指针可以改
```

## 12. 输入输出完整示例
```cpp
#include <iostream>
#include <string>

int main()
{
    int num;
    std::string name;
    std::cout << "请输入数字：";
    std::cin >> num;
    std::cout << "请输入名字：";
    std::cin >> name;
    std::cout << num << "," << name << std::endl;
    return 0;
}
```

## C++与C核心差异速记
1. 输入输出：`std::cin/std::cout` 替代 `scanf/printf`
2. 新增**引用 &**
3. `new/delete` 代替 `malloc/free`
4. 函数重载、默认参数
5. `bool`类型
6. 类、面向对象、访问控制
7. `std::string`字符串
8. STL容器、模板template