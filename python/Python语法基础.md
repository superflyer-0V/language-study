# Python语法基础
## 1. 输出 print()
```python
print("Hello Python")   # 输出字符串，双引号/单引号都可以
print(123)              # 输出数字
print(1+2)              # 输出运算结果
print("a", 10, True)    # 多个输出，逗号分隔，默认空格隔开
```

## 2. 变量
变量不需要声明类型，赋值即创建
```python
a = 10          # 整数 int
b = 3.14        # 浮点数 float
c = "python"    # 字符串 str
d = True        # 布尔 bool：True / False

print(a,b,c,d)
```
> 变量命名：字母、数字、下划线，不能数字开头，区分大小写，不能用关键字

## 3. 数据类型
|类型|说明|示例|
|---|---|---|
|`int`|整数|`10, -5`|
|`float`|浮点数|`3.14`|
|`str`|字符串|`"abc"` `'abc'`|
|`bool`|布尔|`True` `False`|
|`list`|列表|`[1,2,3]`|
|`tuple`|元组|`(1,2,3)`|
|`dict`|字典|`{"name":"Tom"}`|
|`set`|集合|`{1,2,3}`|

查看类型：`type(变量)`
```python
print(type(10))
```

## 4. 输入 input()
input 获取的**永远是字符串**
```python
name = input("请输入名字：")
num = int(input("请输入数字："))  # 转整数
```

## 5. 运算符
### 算术运算符
```python
a = 7
b = 2
print(a + b)   # 加 9
print(a - b)   # 减 5
print(a * b)   # 乘 14
print(a / b)   # 除 3.5
print(a // b)  # 整除 3
print(a % b)   # 取余 1
print(a ** b)  # 幂 7的2次方=49
```

### 比较运算符，返回布尔值
`> < >= <= == !=`
```python
print(10 > 5)   # True
print(3 == 3)   # True
print(2 != 5)   # True
```

### 逻辑运算符
`and` 并且；`or` 或者；`not` 取反
```python
print(1>0 and 2>1)
print(1>10 or 2>1)
print(not True)
```

## 6. 条件判断 if
**Python靠缩进（4空格）代表代码块，不用大括号**
```python
age = 18
if age >= 18:
    print("成年")
elif age >= 12:
    print("青少年")
else:
    print("小孩")
```

## 7. 循环
### while循环
```python
i = 1
while i <= 5:
    print(i)
    i = i + 1
```

### for循环
```python
# range(起始,结束,步长)，左闭右开
for i in range(1,6):
    print(i)

# 遍历字符串
for s in "python":
    print(s)
```

- `break`：跳出整个循环
- `continue`：跳过本次，直接进入下一轮

```python
for i in range(5):
    if i == 2:
        continue
    print(i)
```

## 8. 字符串 str
```python
s = "hello world"
print(s[0])          # 下标取值 h
print(len(s))        # 字符串长度
print(s[0:5])        # 切片 hello [起始:结束]

#常用方法
print(s.upper())     #大写
print(s.lower())     #小写
print(s.split(" "))  #分割
```

## 9. 列表 list，可变数组
```python
lst = [10,20,30,"abc"]
lst.append(40)      #末尾添加
lst.pop()           #删除末尾
lst[0] = 99         #修改元素
print(lst[1])       #取元素
print(len(lst))     #长度
```

## 10. 字典 dict，键值对
```python
d = {"name":"小明","age":16}
print(d["name"])
d["age"] = 17           #修改
d["sex"] = "男"         #新增
print(d.keys())         #所有键
print(d.values())       #所有值
```

## 11. 函数 def
```python
def add(x,y):
    """函数注释"""
    res = x + y
    return res

result = add(3,5)
print(result)
```

## 12. 注释
```python
# 单行注释

'''
多行注释
多行注释
'''
```

## 13. 导入模块 import
```python
import math
print(math.sqrt(4))

from math import pi
print(pi)
```

## 易错点小结
1. 缩进！if/for/while/def 后面代码必须缩进，缩进混乱直接报错
2. `=`赋值，`==`判断相等，不要搞混
3. `input()`得到字符串，做计算需要int/float转换
4. 字符串单双引号成对，不能混用