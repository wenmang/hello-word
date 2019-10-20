### Lesson6

本节课讲了归纳法的应用【生成排列】，即全排列的生成，并布置了第一次作业！即【寻找多数元素】，也被称之为【寻找众数】。

之后，为第六章开了个头，讲了一下【最大最小元素】。

相关代码和文件详情，见本目录。

#### 全排列

全排列算法，说实话，课本上讲的两种方式我都没看懂。于是我就去维基百科看了一下，发现全排列的算法是真的多！然后就挑选了两种最为简便的算法，进行了实现。

**邻位对换法**

这种利用回溯思想的算法，据维基百科，是由Johnson-Trotter首先提出的，其可以快速生成排列，算法原理就是一个排列中的将数两两交换，就能得到一个新的排列，例如：

`1 2 3` 交换 `2 3` 后变为 `1 3 2` 再交换 `1 2` 变为 `2 3 1`  再交换变为 `2 1 3`

`1 2 3` 交换 `1 3` 后变为 `3 2 1` 再交换 `2 1` 变为 `3 1 2` 

看上去毫无规律，但其实有迹可循，也就是两两逐个交换一遍即可，此时代码如下：

```java
private void helper(int n, ArrayList<Integer> nums, List<List<Integer>> ret, int index) {
    if (index == n)
        ret.add(new ArrayList(nums));

    for (int i = index; i < n; i++) {
        Collections.swap(nums, i, index);
        helper(n, nums, ret, index+1);
        Collections.swap(nums, i, index);
    }
}
```

**字典序法**

上面的零位对换法，有着其缺陷，那就是输出的全排列是并不是按照字典序排列的，而要想按照字典序排列，那么便需要重新写一个算法。

按照字典序排列的过程，其实是最符合人类自己的书写过程的，我们自己写全排列时，都是从 `1 2 3` 逐渐增大至 `3 2 1` ，从而不遗漏地写出所有排列，编程实现也是如此：

- 从排列的右端开始，找出第一个比右边数字小的数字的序号 `j`
- 在序号 `j` 的右边的数字中，找出所有 比序号为 `j` 的数字大 的数中最小的数字，序号为 `k`
- 交换 `j` 和 `k` 所对应的数字
- 最后将序号 `j` 之后的数字倒转

重复上述四步骤，直至排列完全逆序为止，`java` 代码如下：

```java
private static void swap(int[] arry, int i, int j) {
    int tmp = arry[i];
    arry[i] = arry[j];
    arry[j] = tmp;
}

private static void PermutationList(int[] arry) {
    int j, k, len = arry.length;

    while (true) {
        for (int i:arry)
            System.out.print(i);
        System.out.println();

        for (j = len - 2; j >= 0 && arry[j] >= arry[j + 1]; j--) ;

        if (j < 0)
            return;

        for (k = len - 1; k > j && arry[k] <= arry[j]; k--);

        swap(arry, k, j);

        for (int l = j + 1, r = len - 1; l < r; l++, r--)
            swap(arry, l, r);
    }
}
```

