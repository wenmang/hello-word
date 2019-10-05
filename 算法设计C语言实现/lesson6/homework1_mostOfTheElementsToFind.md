### 寻找多数元素

#### 题目描述

寻找整数数组中的多数元素（**多数元素：** 即数组中出现次数多于一半的数）

#### 算法描述及代码

**解法一：暴力求解法**

- 将数组中元素逐个比较，找出出现次数最多的元素 `i`
- 通过数组的元素个数判断该数 `i` 是否是多数元素。

`Java` **代码如下**：

```java
private void getMostNum(int[] a) {
    int len = a.length;
    int count = 0, maxNum = a[0], maxCount = 0;
    for (int i = 0; i < len; i++) {
        int tmp = a[i];
        for (int j = 0; j < len; j++) {
            if (tmp == a[j]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxNum = a[i];
            maxCount = count;
        }
        count = 0;
    }

    if (maxCount > len/2)
        System.out.println("多数元素为：" + maxNum);
    else
        System.out.println("多数元素不存在！");
}
```

**解法二：排序后直接判断**

- 将原数组从小到大排序
- 根据数组**元素个数的奇偶**，可分为两种情况：
  - 如为奇数：数组中间元素只要和左右两边任意一边相等，便可以超过一半，从而确定多数元素。
  - 如为偶数：数组中间元素需和数组两边均相等，才能超过一半，从而确定多数元素。

`Java` **代码如下：**

```java
private void getMostNum(int[] a) {
    Arrays.sort(a);
    int mid = a.length / 2;
    if (a.length % 2 == 1) {
        if (a[mid] == a[mid-1] || a[mid] == a[mid+1])
            System.out.println("多数元素为：" + a[mid]);
        else
            System.out.println("多数元素不存在！");
    } else {
        if (a[mid] == a[mid-1] && a[mid] == a[mid+1])
            System.out.println("多数元素为：" + a[mid]);
        else
            System.out.println("多数元素不存在！");
    }
}
```

- 排序部分，直接调用库函数完成

**解法三：利用哈希表寻找**

- 由于哈希表的存储特性是按照**键值对**的方式存储的，刚好可以**存储元素的值以及出现的次数。**
- 所以两次遍历即可解决，**第一次遍历数组**统计数组元素及其出现次数，第二次遍历哈希表，判断是否存在多数元素。

`Java` **代码如下：**

```java
private void getMostNum(int[] nums) {
    HashMap<Integer, Integer> hashMap = new HashMap<>();
    for (int num : nums) {
        if (!hashMap.containsKey(num)) {
            hashMap.put(num, 1);
        } else {
            hashMap.put(num, hashMap.get(num)+1);
        }
    }

    Map.Entry<Integer, Integer> entry = null;
    for (Map.Entry<Integer, Integer> e : hashMap.entrySet()) {
        if (entry == null || e.getValue() > entry.getValue()) {
            entry = e;
        }
    }

    if (entry.getValue() > nums.length/2) {
        System.out.println("多数元素为：" + entry.getKey());
    } else {
        System.out.println("多数元素不存在！");
    }
}
```

**解法四：Boyer-Moore 投票算法**

- 此算法即书上最后介绍的算法。
- 我们首先将多数元素`mostNumber`设置为数组头元素，并设置一个变量 `count = 0` 用于计数，然后从头到尾扫描：
  - 如果 `mostNumber` 等于数组元素，`count+1`
  - 如果 `mostNumber` 不等于数组元素，`count-1`
- 一旦 `count = 0` ，则重新设置多数元素。

`java` **代码如下：**

```java
private void getMostNum(int[] nums) {
    int mostNumber = nums[0];
    int count = 0;
    for (int num : nums) {
        if (count == 0) {
            mostNumber = num;
        }
        count += (num == mostNumber) ? 1 : -1;
    }

    count = 0;
    for (int num : nums) {
        if (num == mostNumber) {
            count++;
        }
    }

    if (count > nums.length/2)
        System.out.println("多数元素为：" + mostNumber);
    else
        System.out.println("多数元素不存在！");
}
```

#### 举例分析

**解法一：**

暴力解法，正确性显而易见，时间复杂度为 $O(N^2)$ ，空间复杂度为 $O(1)$

**解法二：**

排序后取中值，正确性也很显然，但是有两种特殊情况需要举例分析：

- 当数组元素个数为偶数时，设排序后数组为：`[1, 2, 3, 4, 4, 4]`
  - 此时求数组的中值下标为`6/2 = 3` ，也就是 `4` 。
  - 如果仅和一边的值判断是否相等，不足以判断出该数是否为多数元素
- 当数组元素个数为奇数时，设排序后数组为：`[1, 2, 3, 4, 4, 4, 4]`
  - 此时求数组的中值下标为`7/2 = 3` （整数除法向下取整），也就是 `4` 。
  - 仅和一边的值判断是否相等，就可以判断出该数是否为多数元素

自带库排序是快排，其时间复杂度为 $O(N\ logN)$ ，空间复杂度为 $O(1)$

**解法三：**

利用哈希表进行辅助求解：

- 其原理就是统计出数组中所有元素出现的次数
- 然后从所有次数中找出现次数最多的，再进行判断。

正确性也毋庸置疑。

由于**哈希表操作的时间复杂度为** $O (1)$ ，故该算法的时间复杂度为 $O(N+K)$ （$N$ 为数组元素数，$K$ 为数组不重复元素的个数），由于使用了哈希表，其空间复杂度为 $O(N) $ 

**解法四：**

最优算法，其原理也很好理解，数组中如果存在多数元素，数组中多数元素多于一半，最后一定能落到多数元素上。假如数组为：`[1, 4, 2, 4, 3, 4, 4]`，将多数元素插开更有代表性，执行过程中变量变化情况如下：

```
初始化变量：
mostNumber = 1;
count = 0;

循环开始：
i = 0;
mostNumber = 1;
count = 1;

i = 1;
mostNumber = 1;
count = 0;

i = 2;
mostNumber = 2;
count = 1;

i = 3;
mostNumber = 2;
count = 0;

i = 4;
mostNumber = 3;
count = 1;

i = 5;
mostNumber = 3;
count = 0;

i = 6;
mostNumber = 4;
count = 1;
```

显然可见，其时间复杂度为 $O(N)$ ，空间复杂度为 $ O(1) $