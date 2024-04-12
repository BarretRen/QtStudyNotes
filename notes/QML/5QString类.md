
# 1 字符串转换为数字

## 1.1 转换为整型
```cpp
int toInt(bool * ok = Q_NULLPTR, int base = 10) const
long toLong (bool * ok = Q_NULLPTR, int base = 10) const
short toShort (bool * ok = Q_NULLPTR, int base = 10) const
uint toUInt (bool *ok = Q_NULLPTR, int base = 10) const
ulong toULong (bool *ok = Q_NULLPTR, int base = 10) const
```
默认十进制，可以通过指定base设置其他进制。

## 1.2 转换为浮点数
```cpp
double toDouble(bool *ok = Q_NULLPTR) const
float toFloat (bool * ok = Q_NULLPTR) const
```

# 2 数字转换为字符串
默认十进制，可以设置其他进制
```cpp
Qstring &setNum (int n, int base = 10)
QString number (int n, int base = 10)
```

# 3 QString类基本功能
QString 存储字符串釆用的是 Unicode 码，每一个字符是一个 16 位的 QChar，而不是 8 位的 char，所以 QString 处理中文字符没有问题，而且一个汉字算作是一个字符。常用成员函数如下：

- append、prepend：在字符串后面和前面添加字符串
- toUpper、toLower：转换为大小写
- count、size、lenght：返回字符串的字符个数，汉字算一个字符
- trimmed：去除字符串首尾的空格
- simplified：去除首位空格，中间连续空格用一个空格替换
- indexOf、lastIndexOf：查找子字符串出现的位置、最后出现的位置
- isNUll：字符串是否为空，"\0"返回false，未赋值的字符串返回true
- isEmpty：字符串是否为空，"\0"返回true
- contains：字符串内是否包含某个字符串
- left、right：从字符串左右边取多少个字符串
- section：分割字符串
