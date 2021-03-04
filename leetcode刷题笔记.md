[toc]

# 1. 贪心算法

### 贪心算法证明

1. 面对题目，初步判定可以用贪心算法，则尝试举出几个反例，看看是否提出的贪心算法是错的
2. 如果举不出反例，则基本是对的。可以使用贪心。接下来可以用反证法证明贪心算法的正确性。
   - 在第i步，按照提出的贪心算法策略选择某个元素，或者作出某个决定。
   - 反证，假设当前第i步提出的决定不是最优的，则。。。顺着往下推，发现矛盾。说明贪心算法策略是正确的。

### 贪心 + 动态维护最远距离

1. [763. 划分字母区间](https://leetcode-cn.com/problems/partition-labels/)
   - 预先扫描数组并统计一遍信息（频率、个数、最后一次出现的位置等），可以帮助降低复杂度

2. [45. 跳跃游戏II](https://leetcode-cn.com/problems/jump-game-ii/)
   - 动态维护最右端最大距离

### 贪心 + 仅考虑左右相邻位置

1. [122. 买卖股票的最佳时机II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)
2. [135. 分发糖果](https://leetcode-cn.com/problems/candy/)
   - 考虑左右位置的复杂版。两次扫描，一次仅考虑左邻居，一次考虑右邻居，然后合并考虑结果

### 贪心 + interval

1. 特点：
   - 这类题一般要对【区间排序】。可能按照左端点排序，也可能按照右端点。这是关键问题。
2. [435. 无重叠区间](https://leetcode-cn.com/problems/non-overlapping-intervals/)
   - 给n个区间，返回需要移除的区间的最小数量，使得剩下的区间不重叠。
   - 移除k，反过来想，就是选择n - k个不重叠的区间，使得n - k最大。把删除问题变成插入问题。
3. [406. 根据身高重建队列](https://leetcode-cn.com/problems/queue-reconstruction-by-height/?utm_source=LCUS&utm_medium=ip_redirect&utm_campaign=transfer2china)
   - 给定n个元素，重建成n个。我们不一定要新建一个vector[n]来想每个元素究竟应该放置在哪。我们可以用一个list，考虑每个元素应该插在哪里即可。

### 贪心 + 排序 + 优先队列

1. [253. 会议室II](https://leetcode-cn.com/problems/meeting-rooms-ii/)
   - 小顶堆用优先队列pirority_queue<>

### 贪心 + 优先队列 + 窗口（非滑动窗口）

1. 特点：
   - 任务调度类题目；
   - 优先队列是一个大顶堆，用于维护字符的频率，频率最高的在上。
   - 窗口用于实现间隔，比如要求相同字符的间隔为k，则窗口的大小设置为k + 1。
   - 贪心体现在我们每次都要求先安排频率最高的元素
2. [621. 任务调度器](https://leetcode-cn.com/problems/task-scheduler/)
3. [358. K距离间隔重排字符串](https://leetcode-cn.com/problems/rearrange-string-k-distance-apart/)
4. [767. 重构字符串](https://leetcode-cn.com/problems/reorganize-string/)

### 贪心 + 单调栈

1. 特点：
   - 从一个n个元素的序列里选出k个元素
   - 要求选出的k个元素组成的字符串、数字最大
   - 保持原来元素的相对顺序（可以是暗含的条件，如从"10623"中去除两个数字，要求数字最大）

2. [316. 去除重复字母](https://leetcode-cn.com/problems/remove-duplicate-letters/)
   - 维持一个单调递增栈。即如果待入栈元素比栈顶元素小，就把栈顶元素pop掉(因为越小的元素越要往前放)。但如果栈顶元素已经是最后一次出现了，就不能pop。
3. [402. 移掉k位数字](https://leetcode-cn.com/problems/remove-k-digits/)
   - 从长度为n的数字字符串中删除k位数字。需要返回一个最小的结果
   - 移除k个数字反过来想，相当于于选择n - k个数字
4. [321. 拼接最大数](https://leetcode-cn.com/problems/create-maximum-number/)
   - 要求：从2个数组中，一共选出k个数字，拼在一起，返回最大结果。
   - 相当于把基本的【从单个序列里选出k个元素，使之最大】变成了两个序列。分别从两个序列里，A序列选出能组成最大元素的i个元素，B序列选择k - i 个元素。枚举i。然后把A和B的结果merge。

### 杂

1. [134. 加油站](https://leetcode-cn.com/problems/gas-station/)

2. [376. 摆动序列](https://leetcode-cn.com/problems/wiggle-subsequence/)

3. [484. 寻找排列](https://leetcode-cn.com/problems/find-permutation/)

   

# 2. 双指针

### 头尾双指针

1. [167. 两数之和](https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted)

   对数组进行双指针搜索

2. [633. 平方数之和](https://leetcode-cn.com/problems/sum-of-square-numbers/)

   对数字/解空间进行双指针搜索

3. [454. 四数相加](https://leetcode-cn.com/problems/4sum-ii/submissions/)

   两个一组，把枚举结果存入map。没必要用双指针

4. [680. 验证回文字符串II](https://leetcode-cn.com/problems/valid-palindrome-ii/?utm_source=LCUS&utm_medium=ip_redirect&utm_campaign=transfer2china)

5. [42. 接雨水](https://leetcode-cn.com/problems/trapping-rain-water/) n刷

稍微变体



### 同向双指针（滑动窗口，关注点在[ll, rr]窗口）

1. [76. 最小覆盖子串](https://leetcode-cn.com/problems/minimum-window-substring)

   滑动窗口 + 两个数组哈希表记录目标字符串；

2. [340. 最多包含K个不同字符的最长子串](https://leetcode-cn.com/problems/longest-substring-with-at-most-k-distinct-characters/)

   滑动窗口 + 两个哈希数组辅助记录目标字符串；

3. [30. 串联所有单词的子串](https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/)

   滑动窗口 + 两个map，一个记录目标字典，一个记录当前探测情况 + 一个计数器维持窗口大小为答案的目标长度

4. [424. 替换后的最长重复字符](https://leetcode-cn.com/problems/longest-repeating-character-replacement/)  n刷

   滑动窗口 + 一个哈希数组辅助记录 + 一个max 变量判断窗口内的主要元素（非替换元素） 

### 同向双指针：删除重复元素（关注点在[0, ll]区间如何维护）

1. 特点：循环不变量(ll和rr的定义、意义)

2. [26. 删除排序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)

   ```cpp
   【循环不变量是本题的核心】
   ​```
   class Solution {
   public:
       int removeDuplicates(vector<int>& nums) {
           //ll: [0, ll]为不重复元素
           //rr:遍历到第rr个元素时，保证[0, rr]内的不重复元素都被放置在[0, ll]中
           if(nums.empty())
               return 0;
           int ll = 0;
           for(int rr = 1; rr < nums.size(); rr++){
               if(nums[rr] != nums[ll] && ll + 1 < nums.size()){
                   swap(nums[++ll], nums[rr]);
               }
           }
           return ll + 1;
       }
       int removeDuplicates2(vector<int>& nums) {
           //ll: [0, ll)为不重复元素
           //rr:遍历到第rr个元素时，保证[0, rr]内的不重复元素都被放置在[0, ll)中
           int ll = 0;
           for(int rr = 0; rr < nums.size(); rr++){
              if(ll == 0 || nums[rr] != nums[ll - 1]){
                  swap(nums[ll++], nums[rr]);
              }
           }
           return ll;
       }
   };
   ​```
   ```

   

   

3. [80. 删除排序数组中的重复项II](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/solution/shuang-zhi-zhen-zhi-tong-xiang-zhi-zhen-che-di-jie/)

4. [27. 移除元素](https://leetcode-cn.com/problems/remove-element/solution/yi-chu-yuan-su-by-leetcode/)

5. [283. 移动零](https://leetcode-cn.com/problems/move-zeroes/)

6. [75. 颜色分类](https://leetcode-cn.com/problems/sort-colors/)

   荷兰国旗问题；[关于区间定义和不变式设计](https://leetcode-cn.com/problems/sort-colors/solution/kuai-su-pai-xu-partition-guo-cheng-she-ji-xun-huan/)

   ```cpp
   ​```
   class Solution {
   public:
       void sortColors(vector<int>& nums) {
           int ll = 0, rr = nums.size() - 1;
           //ll: [0, ll)区间内全部为0元素
           //rr: (rr, nums.size() - 1]内全部为2元素
           //【关键】i:[ll, i)内全部为1元素
           int i = ll;
         	//接下来的循环的任务是：维持我们定义的循环不变量的含义
           while(i <= rr){
               if(nums[i] == 0){
                   swap(nums[ll++],nums[i++]);
               }else if(nums[i] == 2){
                   swap(nums[rr--], nums[i]);
               }else
                   i++;
           }
       }
   };
   ​```
   ```

   


### 快慢指针

1. [142. 环形链表II](https://leetcode-cn.com/problems/linked-list-cycle-ii)

### merge两个数组

1. [88. 合并两个有序数组](https://leetcode-cn.com/problems/merge-sorted-array)

### 杂

1. [28. 实现strStr()](https://leetcode-cn.com/problems/implement-strstr/)

   【kmp算法】

   ```cpp
   vector<int> getNext(string& pattern){
           int n = pattern.size();
           vector<int> next(n, 0);
           next[0] = -1;
           int k = -1, j = 0;
           while(j < n - 1){
             	//k是next数组的内容，表示j位置以前的最长公共前后缀；
             	//k也是一个计数器，记录当前时刻，前缀和后缀的公共长度达到了多少
               if(k == -1 || pattern[k] == pattern[j])
                   next[++j] = ++k;
               else k = next[k];
           }
           return next;
       }
   };
   
   int kmp(string &txt, string &pattern){
     	int j = 0, k = -1;
     	vector<int> next = getNext(pattern);
     	//注意k可能为-1，而pattern.size()是无符号数
     	//j是text的指针，永不回退
     	while(j < txt.size() && k < (int)pattern.size()){
       		if(k == -1 || txt[j] == pattern[k]){
             	k++; j++;
           }else{
             	k = next[k];
           }
     	}
     	//如果k遍历到pattern的尾部，说明匹配了
     	if(k == pattern.size()){
         	return j - k;
       }else{
         	//j到达了text的尾部，k未到达pattern的尾部，不匹配
         	return -1;
       }
   }
   ```

   

# 3. 二分查找

### 基础

1. 查找target是否存在

   ```cpp
   //二分搜索
   int binary_search(vector<int> arr, int target){
     	int n = arr.size();
     	//循环不变量的含义：在[ll,...,rr]区间搜索target
     	int ll = 0, rr = n - 1; 
     	/**
     		之所以是 <=, 是因为我们的任务是在区间[ll, rr]搜索target
     		当ll == rr时，我们仍然有待搜索的区间
     	*/
     	while(ll <= rr){
         	int mid = ll + (rr - ll) / 2;
         	if(arr[mid] == target) return mid;
         	else if(arr[mid] < target){
             	/**
             		ll到底更新为 mid 还是mid + 1呢?
             		考虑到循环不变量，mid显然不是target，因此我们将区间变为[mid + 1, rr]
             	*/
             	ll = mid + 1;
           }else{
             	rr = mid - 1;
           }
       }
     	//当搜索完整个空间后，说明未找到。
     	return -1;
   }
   
   //二分搜索
   int binary_search(vector<int> arr, int target){
     	int n = arr.size();
   		int ll = 0, rr = n; 
     	//循环不变量的含义：在[ll, rr)搜索target
     	//我们的任务是在合法区间搜索target,当ll == rr时，[ll, rr)内没有元素了
     	//因此ll < rr
     	while(ll < rr){
         	int mid = ll + (rr - ll) / 2;
         	if(arr[mid] == target) return mid;
         	else if(arr[mid] < target){
             	ll = mid + 1;
           }else{
             	//因为rr是开区间端点，我们排除了mid是答案，因此rr取mid
             	rr = mid;
           }
       }
     	return -1;
   }
   ```

2. Upper（相当于取上界）: 查找大于target的最小值的索引

   ```cpp
   int upper(vector<int>arr, int target){
     	/*搜索空间是闭区间[ll, rr] = [0, arr.size()]
     		之所以右区间不是arr.size() - 1,是因为当arr元素全部小于target时，
     		答案就是arr.size()这个空位置。
     		这样初始区间就包含了所有待求空间；
     		循环不变量：循环不变量：在[ll, rr]中寻找解
     	**/
     	int ll = 0, rr = arr.size();
     	/**
     		用ll < rr：因为我们定义的搜索区间覆盖了所有情况，所以本算法一定有解
     		因此当ll = rr时，待搜索区间元素只有一个了，类似夹逼，剩下的一个元素一定是答案
     	*/
     	while(ll < rr){
         	int mid = ll + (rr - ll) / 2;
         	if(arr[mid] <= target) ll = mid + 1;
         	else rr = mid;
       }
     	return ll;
   }
   ```

3. upper_ceil: 取上界。

   如果存在target，则返回这个元素对应的最大的索引(因为target可能有重复)。

   如果不存在target，返回upper

   ```cpp
   /**
   	可以复用upper; 先查找大于target的最小值的索引idx
   	如果arr[idx - 1]为target，说明target是存在的，则返回idx - 1；
   	如果arr[idx - 1]不是target，说明target不存在，则返回idx
   */
   int ceil(vector<int>arr, int target){
     	int u = upper(arr, target);
     	if(u - 1 >= 0 && arr[u - 1] == target) return u - 1;
     	return u;
   }
   ```

4. lower_ceil: (>=target的最小索引)

   如果存在target，则返回这个元素的最小索引

   如果不存在，返回upper

5. Lower（相当于取下界）: 查找小于target的最大索引

   ```cpp
   int lower(vector<int>arr, int target){
     	/**
     		搜索区间为闭区间:[ll, rr] = [-1, arr.size() - 1];
     		之所以左区间端点为-1，因为当target小于arr的所有元素时，-1即为答案。
     		利用这个区间，我们也实现了覆盖全部搜索空间
     		循环不变量：在[ll, rr]中寻找解
     	*/
     	int ll = -1, rr = arr.size() - 1;
     	//ll < rr在解决复杂问题时最常用， ll <= rr用在解决简单问题时
     	while(ll < rr){
         	/**
         		mid = ll + (rr - ll) / 2是向下取整：
         		当ll和rr相差1时，由于向下取整，mid取值为ll。
         		此时如果arr[mid] < target时，进入第一个分支，ll、mid、rr都不会变化，搜索区间就永远不会变了
         		出现死循环
         		解决方法：
         		1. 当ll = mid时，意味着左边界有可能不会更新，因此我们计算mid时向rr靠近：mid = ll + (rr - ll + 1) / 2;
         		2. 当rr - mid时，意味着右边界可能不会更新，因此我们计算mid时，向ll靠近，mid = ll +(rr - ll) / 2;
         		3. 对于二分搜索来说，本质上mid取哪个都无所谓。我们关注mid取左或者取右，主要是为了避免死循环
         	*/
         	int mid = ll + (rr - ll + 1) / 2;
         	if(arr[mid] < target) ll = mid;
         	else rr = mid - 1;
       }
     	return ll;
   }
   ```

   

6. lower_floor:

   如果存在target，返回这个元素的最小索引

   如果不存在：返回lower

7. upper_floor:(<=target 的最大索引)

   如果存在target，返回最大索引

   如果不存在，返回lower

### 常规搜索

1. [34. Find First and Last Position of Element in Sorted Array (Medium)](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

   - 尽量在初始化时，将循环不变量定为：在[ll, rr]的左闭右闭区间搜索答案。并在循环的过程中始终维持这个循环不变量。

   - 尽量用while(ll < rr)来做，而非 while(ll <= rr)。

     【当搜索的target一定在区间中】时，循环退出时有 ll == rr。

     但如果不保证target一定存在，或者初始化ll和rr时，没有将target确保纳入搜索空间，则退出时不一定有ll == rr，此时需要特判：在循环结束后，如果搜索到target，则有ll == rr，否则，ll < rr

### 在旋转数组中搜索

1. [81. 搜索旋转排序数组II](https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/)

   在一个两部分分别有序的数组中进行二分搜索

2. [153. 寻找旋转数组中的最小值](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)

3. [154. 寻找旋转排序数组中的最小值 II](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/)

   出现重复元素，rr--即可

### 在两个有序数组中搜索一个target

1. [4. 寻找两个正序数组的中位数](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/submissions/)(n刷)

### 不明显的二分搜索

1. [540. 有序数组中的单一元素](https://leetcode-cn.com/problems/single-element-in-a-sorted-array/)

2. [875. 爱吃香蕉的珂珂](https://leetcode-cn.com/problems/koko-eating-bananas/)

   关键在于寻找单调性

3. [162. 寻找峰值](https://leetcode-cn.com/problems/find-peak-element/submissions/) n刷

4. [240. 搜索二维矩阵](https://leetcode-cn.com/problems/search-a-2d-matrix-ii/solution/sou-suo-er-wei-ju-zhen-ii-by-leetcode-2/)

5. [275. H指数II](https://leetcode-cn.com/problems/h-index-ii/)

   关键在于寻找单调性

6. [378. 有序矩阵中第k小元素](https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/)

   - 相当于搜索二维矩阵II

   - 假设左上角最小元素为ll，右下角最大元素为rr。在这个区间内二分搜索，即看看矩阵中，小于等于mid的元素个数是不是k个，如果大于k个，向[ll, mid - 1]搜索，否则向[mid + 1, rr]搜索。（这个说法不严谨，其实是在待搜索区间内，寻找第一个【比自己小的元素个数】大于等于【k个元素】的数字）

   - ```cpp
     //注意二者的区别
     if(cnt >= k){
         rr = mid;
     }else{
         ll = mid + 1;
     }
     
     if(cnt > k){
         rr = mid - 1;
     }else{
         ll = mid;
     }
     ```

   - 

### 快速幂之类的算法（不算二分）

1. [29. 两数相除](https://leetcode-cn.com/problems/divide-two-integers/)

   减法，正向做

2. [50. pow(x,n)](https://leetcode-cn.com/problems/powx-n/)

   递归

   

# 4. 排序算法

### 基础

1. 选择排序

   ```cpp
   void select_sort(vector<int>& nums, int n){
     	/**
     		循环不变量：
     		[0, i)为已排好序的区间
     		[i, n)为待排序区间
     		每次从待排序区间中找到一个最小的元素，扩充到i位置
     	*/
     	for(int i = 0; i < n; i++){
         	int min_idx = i, min_val = nums[i];
         	for(int j = i; j < n; j++){
             	if(nums[j] < min_val){
                 	min_val = nums[j];
                 	min_idx = j;
               }
           }
         	swap(nums[i], nums[min_idx]);
       }
   }
   ```

   - 选择排序得到的[0, i）区间是全局有序的，即最终结果

2. 插入排序

   ```cpp
   void insert_sort(vector<int>& nums, int n){
     	/**
     		循环不变量：
     		[0, i)为已排好序的区间
     		[i, n)为待排序区间
     		每次把待排序区间的第一个元素，即i，插入到[0, i)的有序区间中
     	*/
     	for(int i = 0; i < n; i++){
         	for(int j = 1; j > 0 && nums[j] < nums[j - 1]; j--){
             	swap(nums[j], nums[j - 1]);
           }
       }
   }
   ```

   - 插入排序得到的[0, i) 局部序列，是局部有序，而非全局有序
   - 当序列基本有序的时候，选用插入排序可以的到近似O(n)的复杂度

3. 归并排序

   ```cpp
   void merge_sort(vector<int>& nums, int l, int r, vector<int>& temp){
     	if(l >= r){
         	return;
       }
     	/**
     		优化2：当[l, r]区间长度很短时，还进行递归比较浪费时间，而且当区间很短时，
     					一般都接近有序了，因此可以不再递归下去，直接用插入排序;
     					不要忘记return
     					if(r - l <= 100){
     							insert_sort(nums, l, r);
     							return;
     					}
     	*/
     	int mid = l + (r - l) / 2;
     	merge_sort(nums, l, mid, temp);
     	merge_sort(nums, mid + 1, r, temp);
     	/**
     		优化1：当nums[mid] < nums[mid + 1]时
     		表示前一半元素和后一半元素刚好合起来已经有序了，不需要合并；
     		即改为： if(nums[mid] > nums[mid + 1])  
     							merge(nums, l, mid, r, temp);
     	*/
     	merge(nums, l, mid, r, temp);
   }
   
   /**
   	优化3：本来temp数组时在merge函数内临时创建的，但由于递归次数太多，每次都创建数组开销太大
   				因此改为在外部仅仅创建一个temp
   */
   void merge(vector<int>& nums, int l, int mid, int r, vector<int>& temp){
     	int p = l, q = mid + 1, i = l;
     	while(p <= r || q <= r){
         	if(q > r || (p <= r && nums[p] <= nums[q])){
             	temp[i++] = nums[p++];
           }else{
             	temp[i++] = nums[q++];
           }
       }
     	copy(temp.begin() + l, temp.begin() + r + 1, nums.begin() + l);
   }
   ```

   - 归并排序的时间复杂度：每次二分mid，复杂度为O(logn)，merge复杂度O(n)，所以复杂度为nlogn

     当采取优化1时，如果本身数组近似有序，则可以得到logn的复杂度

   - 归并排序可以用来计算逆序对，计算的过程在merge内部

     ```cpp
     //merge_sort计算逆序对个数
     int merge_sort(vector<int>& nums, int l, int r, vector<int>& temp){
       	int cnt = 0;
       	if(l >= r){
           	return 0;
         }
       	int mid = l + (r - l) / 2;
       	cnt += merge_sort(nums, l, mid, temp);
       	cnt += merge_sort(nums, mid + 1, r, temp);
       	cnt += merge(nums, l, mid, r, temp);
       	return cnt;
     }
     /**
     	1. 主要计算逆序对在merge函数中，merge[1,4,5,7] 和 [2,3,6]
     	2. 当i指向1，j指向2，没有逆序对，正常将i拷贝至temp数组；i++
     	3. i指向4，j指向2，这时，2 < 4，而2却在后一半数组中，因此有逆序。有几个逆序呢？
     		因为4后面的元素5，7都比4大，因此2会对4、5、7都产生逆序。个数为 mid - i + 1
     */
     int merge(vector<int>& nums, int l, int mid, int r, vector<int>& temp){
       	int p = l, q = mid + 1, i = l;
       	int cnt = 0;
       	while(p <= mid || q <= r){
           	if(q > r || (p <= mid && nums[p] <= nums[q])){
               	temp[i++] = nums[p++];
             }else{
               	cnt += mid - p + 1;
               	temp[i++] = nums[q++];
             }
         }
       	copy(temp.begin() + l, temp.begin() + r + 1, nums.begin() + l);
       	return cnt;
     }
     ```

   - 归并排序的非递归算法

     ```cpp
     void merge_sort(vector<int>& nums, int l, int r, vector<int>& temp){
       	//len表示需要合并的单个区间长度，所以是 < r - l + 1 而非 <= r - l + 1
       	for(int len = 1; len < r - l + 1; len *= 2){
           	//i + len < r: 表示i+第一个区间长度小于r，则第二个区间至少有一个元素，即r
           	for(int i = l; i + len < r; i += (2 * len)){
               	//min是因为，第二个区间长度可能不足len
               	merge(nums, i, i + len - 1, min(i + 2 * len - 1, r));
             }
         }
     }
     ```

4. 快速排序

   ```cpp
   void quick_sort(vector<int>& nums, int ll, int rr){
     	if(ll >= rr)
         return;
     	//快速排序的核心是partition函数
     	int mid = partition(nums, ll, rr);
     	sort(nums, ll, mid - 1);
     	sort(nums, mid + 1, rr);
   }
   
   /**
   	partition算法1:选择nums开头的元素ll作为枢纽v
     将数组划分为: < v | v单个元素 | >= v 的元素
   */
   int partition1(vector<int>& nums, int ll, int rr){
     	/**
     		循环不变量：两个指针：ll | j | i | rr
     		ll为枢轴元素，跳过
     		[ll + 1, j]元素 < v | [j + 1, i] >= v | i + 1 到rr未探索元素
     	*/
    		/**
    			此处可以优化，random选择ll到rr的一个元素作为枢轴元素,放在最前面，然后继续正常流程
    			int idx = random(ll, rr);
    			swap(nums[ll], nums[idx]);
    		*/
     	int j = ll;
     	for(int i = ll + 1; i <= r; i++){
         	if(nums[i] < nums[ll]){
             	swap(nums[++j], nums[i]);
           }
       }
     	//将枢轴元素放置到[ll + 1, j]的末尾
     	swap(nums[ll], nums[j]);
     	//返回枢轴的位置
     	return j;
   }
   
   /**
   	partition算法2：二路快速排序
   	把数组划分为 <= v | v单个元素 | >= v 两个区间，然后分别对左右区间快排
   */
   int partition2(vector<int>&nums, int ll, int rr){
     	/**
     		循环不变量：两个指针：ll | i | j | rr
     		ll为枢轴元素，跳过
     		[ll + 1, i] 元素 <= v | 未探索元素 | [j, rr]元素 >= v
     	*/
     	int i = ll + 1, j = rr;
     	while(i < j){
         	while(i < j && nums[i] < nums[ll]) i++;
         	while(i < j && nums[j] > nums[ll]) j--;
         	swap(nums[i], nums[j]);
         	//i未++时，[ll+1, i]区间保证 <= v，循环不变量正常
         	i++; j--;
         	//i++后i指向的是新的未探索元素，此时[ll+1, i - 1]内才保证 <= v
       }
     	//循环退出时，i指向未探索的新元素位置，此时[ll+1, i - 1]内才保证 <= v
     	swap(nums[ll], nums[i - 1]);
     	return i - 1;
   }
   
   /**
   	partition算法3：三路快速排序
   	将数组划分为： < v | = v 的所有元素| > v 三个区间；然后仅仅对<v和>v的区间做递归排序
   */
   pair<int, int> partition2(vector<int>& nums, int ll, int rr){
     	/**
     		循环不变量：三个指针： small ，i， large
     		ll为枢轴元素，跳过
     		[ll + 1, small] 元素 < v;  [small + 1, i]元素 = v； [large, rr]元素 > v
     		i作为探索指针，i到large - 1的元素是未探索元素
     	*/
     	int small = ll, i = ll + 1, large = rr + 1;
     	//i到large - 1的元素是未探索元素，因此当i没碰到large，说明还有没探索的元素存在
     	while(i < large){
         	if(nums[i] < nums[ll]){
             	swap(nums[++small], nums[i++]);
           }else if(nums[i] == nums[ll]){
             	i++;
           }else{
             	swap(nums[--large], nums[i]);
           }
       }
     	return make_pair(small, large);
   }
   ```

   - 最简单的partition算法可能退化为O(n^2)，当元素全部有序的时候。因为每次都把序列划分成左边空数组，右边n - 1元素的情况。如果采取随机取枢轴元素，则可以解决这一问题

   - random之后，仍然会存在算法退化的可能：当所有元素都相等的时候，仍然会退化到n^2。如果采用三路排序则可解决这一问题。

   - 快速排序的两个应用：

     - 荷兰国旗问题：可用三路排序的partition的思路

     - [215. 数组中的第K个最大元素](https://leetcode-cn.com/problems/kth-largest-element-in-an-array)    

       选择未排序数组中第K大的元素，达到O(n)的复杂度

       ```cpp
       int quick_sort(vector<int>&nums, int ll, int rr, int k){
         	/**
         		mid是枢轴元素的索引，表示第mid大的枢轴元素已经排好序了
         	*/
         	int mid = partition(nums, ll, rr);
         	//如果mid刚好是第k个元素，则刚好
         	if(mid == k){
             	return nums[mid];
           }else if(mid < k){ // mid的序列比k小，只能在后面的数组找
             	quick_sort(nums, mid + 1, rr, k);
           }else{ //在前面的数组中找
             	quick_sort(nums, ll, mid - 1, k);
           }
       }
       ```

     - [462. 最少移动次数使数组元素相等II](https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements-ii)

       - 利用 quick_sort 找第k大的数的原理找中位数
       - quick_sort 的random优化特别有用，加速性能很强

5. 冒泡排序

   ```cpp
   void bubble_sort(vector<int>&num, int n){
     	bool swapped;
     	for(int i = 1; i < n; i++){
         	//如果某一轮检测到最后，都没有发生交换，说明已经完全有序了
         	swapped = false;
         	/**
         		循环不变量：
         		每一轮，将[0, n - i]中的一个最大元素冒泡到 n - i的位置
         	*/
         	for(int j = 1; j <= n - i; j++){
             	if(nums[j - 1] > nums[j]){
                 	swap(nums[j - 1], nums[j]);
                 	swapped = true;
               }
           }
         	if(!swapped){
             	break;
           }
       }
   }
   ```

6. 希尔排序

   ```cpp
   void shell_sort(vector<int>& nums, int n){
     	int h = n / 2;
     	//h为间距
     	while(h >= 1){
         	for(int start = 0; start < h; start++){
         		//对[start, start + h, start +2h...进行插入排序]
           		for(int i = start + h; i < n; i += h){
               		for(int j = i; j - h >= 0 && nums[j - h] > nums[j]; j -= h){
                   		swap(nums[j - h], nums[j]);
                 	}
             	}
           }
         	h /= 2;
       }
   }
   ```

7. 桶排序

   ```cpp
       int maximumGap(vector<int>& nums) {
           int n = nums.size();
           if(n <= 1)
               return 0;
           int max_num = *max_element(nums.begin(), nums.end());
           int bits_num = 0;
         	//获取最大的数字的位数
           while(max_num > 0){
               max_num /= 10;
               bits_num++;
           }
           vector<int> buf(n, 0);
         	//从个位开始排序，一直排到最高位
           for(int i = 0, base = 1; i < bits_num; i++, base *= 10){
               vector<int> bucket(10, 0);
             	//求出每个数字的当前位，统计个数
               for(int j = 0; j < nums.size(); j++){
                   int digit = (nums[j] / base) % 10;
                   bucket[digit]++;
               }
             	//求offset
               for(int j = 1; j < 10; j++){
                   bucket[j] += bucket[j - 1]; 
               }
             	//倒着写回buff数组。因为经过上一次排序，个位数小的排在前面
             	//而我们的offset是递减的，因此让个位数大的数字先写入buff
               for(int j = n - 1; j >= 0; j--){
                   int digit = (nums[j] / base) % 10;
                   int idx = --bucket[digit];
                   buf[idx] = nums[j];
               }
             	//拷贝到nums
               copy(buf.begin(), buf.end(), nums.begin());
           }
       }
   ```

   

### 链表排序

1. [147. 对链表进行插入排序](https://leetcode-cn.com/problems/insertion-sort-list/solution/)

   新开一个头结点。遍历原链表，取一个节点，用插入排序插入新开头结点的链表。

2. [148. 排序链表](https://leetcode-cn.com/problems/sort-list/submissions/)

   对链表进行merge_sort，可以用快慢指针求中点位置

### 桶排序

1. [164. 最大间距](https://leetcode-cn.com/problems/maximum-gap/submissions/)

   先把某一位哈希。所有数字都哈希后，求offset，然后重排。如此反复

   [答案](https://leetcode-cn.com/problems/maximum-gap/solution/c-ji-shu-pai-xu-guan-fang-dai-ma-zhu-shi-by-lljj54/)

### 摆动排序

1. [280. 摆动排序](https://leetcode-cn.com/problems/wiggle-sort/submissions/)

   关键是正确性证明

### 归并算法merge求逆序对

1. [315. 计算右侧小于当前元素的个数](https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/submissions/)

   - A = {3,5} B = {2,4}；i指向3，j指向4；此时i < j，先拷贝i到目标数组，此时i右侧比i小的元素个数为 j - B.begin()
   - 可以使用index数组，和temp数组，实现元素不移动而下标移动。index和temp都记录下标

2. [327. 区间和的个数](https://leetcode-cn.com/problems/count-of-range-sum/)

   前缀和 + 归并merge

3. [493. 翻转对](https://leetcode-cn.com/problems/reverse-pairs/)

### 快速排序：3路partition

1. [324. 摆动排序II](https://leetcode-cn.com/problems/wiggle-sort-ii/submissions/)

   - STL：nth_element(begin_iter, mid_iter, end_iter )

- n刷



# 5. 深搜+广搜+回溯(93)

### dfs

1. [133. 克隆图](https://leetcode-cn.com/problems/clone-graph/submissions/)

2. [306. 累加数](https://leetcode-cn.com/problems/additive-number/)
   - 答案[d](https://leetcode-cn.com/problems/additive-number/solution/xia-biao-zuo-wei-fen-duan-dian-dfs-by-over-lord/)
   - 三个参数的dfs，不需要回溯。

### dfs + memo

1. [329. 矩阵中的最长递增路径](https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/)
   - 纯dfs，可以摆脱back_trace的框架
2. [351. 安卓系统手势解锁](https://leetcode-cn.com/problems/android-unlock-patterns/)
   - memo：预先枚举出所有i和j会跨越中间数字的组合（包括中间数字是几）
   - 由于待搜索的数字有限，可以直接搜索1-9而非枚举offset上下左右。
   - 由于对称性，只需要搜索顶点、中心、边缘个一个元素
3. [494. 目标和](https://leetcode-cn.com/problems/target-sum/)
   - dfs是一棵树型结构。因为树形结构中会有很多重复运算，我们可以把这些重复结构存储在memo中

### 回溯 + 对边进行回溯 + 结束条件是什么

1. [332. 重新安排行程](https://leetcode-cn.com/problems/reconstruct-itinerary/)
   - 使用回溯法，一般题目都是对点进行回溯，设置visit数组记录点的访问情况。本题是对边进行回溯，允许点的重复访问，不允许边的重复访问（一条边只能用一次，当然如果题目中同一条边多给了很多条的话则可以重复访问）。
   - 看清结束条件：题目给了有n条边，当访问到累计n+1个点时，说明访问结束。

### 回溯 + 如何选择分支

1. [22. 括号生成](https://leetcode-cn.com/problems/generate-parentheses/)

   - 用两个变量（左括号数量和右括号数量）控制应该选择左括号还是选择右括号

2. [40. 组合总和II](https://leetcode-cn.com/problems/combination-sum-ii/)

   - 在for循环里判断，使得同一层之间的选择不能重复，但本层和下一层之间的选择可以重复

     ```cpp
     void back_trace(vector<int>& candidates, vector<int>& path, int idx, int sum, int target){
             if(sum >= target){
                 ...
                 return;
             }
       			// 此for循环遍历的是搜索树中同一层之间的不同选择
             for(int i = idx; i < candidates.size(); i++){
               	//此if控制同一层之间不可重复
                 if(i > idx && candidates[i] == candidates[i - 1])
                     continue;
                 path.push_back(candidates[i]);
               	//递归进入的是下一层的选择
                 back_trace(candidates, path, i + 1, sum + candidates[i], target);
                 path.pop_back();
             }
         }
     ```

3. [401. 二进制手表](https://leetcode-cn.com/problems/binary-watch/)

   - 也可以不用dfs搜索灯的个数，直接遍历12小时和60分钟（双循环），然后判断这个时间对应的灯是否符合要求。

### 回溯 + 需要预先存储待搜索空间 + 对是否visit过回溯

1. [37. 解数独](https://leetcode-cn.com/problems/sudoku-solver/)

### 回溯 + 对选择结果path回溯

1.  [39. 组合总和](https://leetcode-cn.com/problems/combination-sum/submissions/)

### 回溯 + 对元素排列位置回溯

1. [46. 全排列](https://leetcode-cn.com/problems/permutations/)

   ```cpp
   void back_trace(vector<int>& nums, int idx){
           if(idx == nums.size()){
               ans.push_back(nums);
               return;
           }
     			
           for(int i = idx; i < nums.size(); i++){
               //对idx位置的元素位置进行回溯
             	swap(nums[idx], nums[i]);
               back_trace(nums, idx + 1);
               swap(nums[idx], nums[i]);
           }
       }
   ```

2. [47. 全排列II](https://leetcode-cn.com/problems/permutations-ii/)

   在回溯的过程中需要去重，不能用 num[i] == nums[i - 1]去重，因为本题排列是直接在nums数组上排列的，元素顺序都已经改变了。

### 回溯 + 组合出回文序列

1. [267. 回文排列II](https://leetcode-cn.com/problems/palindrome-permutation-ii/)
   - 利用map记录每个字符的个数，然后对这个map进行分支选择（即每次选择不同的字母），回溯

### 可以不用回溯递归的题

1. [60. 排列序列](https://leetcode-cn.com/problems/permutation-sequence/submissions/)
2. [89. 格雷编码](https://leetcode-cn.com/problems/gray-code/)
3. [254. 因子的组合](https://leetcode-cn.com/problems/factor-combinations/)
   - 本题不需要回溯，可以直接递归，性能要远好于回溯

### 剪枝

1. [93. 复原IP地址](https://leetcode-cn.com/problems/restore-ip-addresses/)

2. 

### BFS

1. [126. 单词接龙II](https://leetcode-cn.com/problems/word-ladder-ii/submissions/)
   - 单词建模为图
   - bfs求最短路：每次记录queue中的size，然后一次性全部出队；类似于tree的层序遍历中计算层数
   - 求出具体路径
   - bfs别忘记用visit数组标记是否曾入队
2. [286. 墙与门](https://leetcode-cn.com/problems/walls-and-gates/)
   - 多个src到多个dst的最短距离，可用bfs。只需要在初始queue中把所有src加入队列即可。
3. [317. 离建筑物最近的距离](https://leetcode-cn.com/problems/shortest-distance-from-all-buildings/)
   - 多个src到某个dst的最短距离之和，用bfs。与286题有区别。
4. [490. 迷宫](https://leetcode-cn.com/problems/the-maze/submissions/)
   - 入栈的不是距离为1的周围邻居，而是上下左右的最远端
5. [505. 迷宫II](https://leetcode-cn.com/problems/the-maze-ii/)
   - 用dfs：需要一个记录起始点到当前点的距离的二维数组，**它也充当visit数组的作用**。但不是只要visit过就不会再次访问，而是如果当前访问到A点时的距离比上次访问到A点的距离短，就可以再次访问，不管A点访问过几次。**dfs的缺点是：求最短路时可能会超时**
   - bfs：也是一个记录距离的二维数组，**也充当visit数组的作用**。但同理：不是记录是否入栈过。而是**只要当前访问到A点的时候的距离比以前访问到A点的距离小，就可以再次将A入栈**。优点是**极其不容易超时**
6. [499. 迷宫III](https://leetcode-cn.com/problems/the-maze-iii/submissions/)
   - 综合难度
   - (x, y) 坐标的哈希可以采用： x * n + y 变为一维
7. [463. 岛屿的周长](https://leetcode-cn.com/problems/island-perimeter/)
   - bfs，遇到大海，周长+1，遇到边界，周长+1

### BFS + 最小堆作为bfs的queue

1. [407. 接雨水II](https://leetcode-cn.com/problems/trapping-rain-water-ii/)
   - 利用priority queue 最小堆 作为 bfs的queue。x点的雨水值由它四周的最低点决定。而用最小堆保证每次出队的都是值最小的点，因此它就是x点的最低的围墙。



# 6. 动态规划

### 基础(dynamic programing 和 dfs+memo等效)

1. 一般流程：先识别出解决问题的**递归结构**，然后识别**重叠子问题**（递归过程中重复计算的问题），然后用**memo**记录

   自顶向下：dfs + memo

   自底向上：动态规划

2. 对状态的定义：198题

   对状态的定义：【考虑】偷取[x, ..., n - 1]范围里的房子

   也可以定义成：【考虑】偷取[0, ..., x]范围的房子

3. 300 LCS：最长公共子序列

   - 想知道公共子序列是什么，怎么做：倒着追溯

4. 地杰斯特拉最短路也是动态规划

5. 类背包问题：[416]

### 裸题

1. [64. 最小路径和](https://leetcode-cn.com/problems/minimum-path-sum/)         [542. 01矩阵](https://leetcode-cn.com/problems/01-matrix)
   - 前者是裸题，求从最左上角到最右下角的最短距离，用dp
   - 后者是前者的加强版。既可以BFS多源最短路，又可以求两次dp，一次从左上角到右下角，一次从右下角到左上角。

### 多个数组记录dp

1. [152. 乘积最大数组](https://leetcode-cn.com/problems/maximum-product-subarray/)
   - 最大和子序列的升级版，需要两个dp数组才能完成。dp_max 和dp_min数组
2. [256. 粉刷房子]
   - 本题**需要多个dp数组记录状态**
3. [264. 丑数II](https://leetcode-cn.com/problems/ugly-number-ii/)  n刷
   - 本题是多个指针在同一个memo数组上做记录
4. [265. 粉刷房子II](https://leetcode-cn.com/problems/paint-house-ii/)
   - 如何求min和second_min需要注意

### 杂

1. [276. 栅栏涂色](https://leetcode-cn.com/problems/paint-fence/)
2. [514. 自由之路](https://leetcode-cn.com/problems/freedom-trail/)

### 分割类问题

1. 此类问题，一般i位置的状态不是依赖于相邻的i-1或i-2，而是依赖于分割点的位置。分割点可能位于[0,....i-1]的任何位置
2. [279. 完全平方数](https://leetcode-cn.com/problems/perfect-squares/)
3. [91. 解码方法](https://leetcode-cn.com/problems/decode-ways/)  n刷题
4. [312. 戳气球](https://leetcode-cn.com/problems/burst-balloons/)
   - 假设k是区间[i, j]中**除端点外**最后一个被戳破的气球，即此时区间内只剩下i、j、k三个气球。从而将[i, j] 区间分割为 [i, k] 和 [k, j]
5. [410. 分割数组的最大值](https://leetcode-cn.com/problems/split-array-largest-sum/)
6. [471. 编码最短长度的字符串](https://leetcode-cn.com/problems/encode-string-with-shortest-length/)

### 数字类问题

1. [338. 比特位计数](https://leetcode-cn.com/problems/counting-bits/)
2. [357. 计算各个位数不同的数字个数](https://leetcode-cn.com/problems/count-numbers-with-unique-digits/)

### 前缀和prefix类问题

1. [363. 矩形区域不超过K的最大数值和](https://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k/)
   - Lower_bound(elem), 查找第一个大于等于elem的元素；upper_bound，查找第一个大于elem的元素

### 字符串类问题

1. [1143. 最长公共子序列](https://leetcode-cn.com/problems/longest-common-subsequence/)
2. [72. 编辑距离](https://leetcode-cn.com/problems/edit-distance/)
   - **把s1变成s2和把s2变成s1是一样的**。为了方便起见，我们统一看**如何把s1变成s2**。s1=acfG，s2=btC；现在指针都指向最后一位i=3，j=2；G!=C，因此我们有```dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1```; 因为我们是**把s1变成s2**，
     - 因此```dp[i-1][j-1] + 1```表示先考虑 s1 = acf 变成 s2 = bt 需要的次数，然后把s1的末尾G改成s2的末尾C，增加了一次编辑次数。
     - ```dp[i-1][j] + 1```表示先考虑 s1 = acf 变成 s2 = btC 的需要的次数，然后再给s1添加一个字符G，增加了一次编辑次数。
     - ```dp[i][j-1] + 1```表示先考虑 s1 = acfG 变成 s2 = bt 需要的次数，然后再把G删除掉，s1就和s2一样了
3. [10. 正则表达式匹配](https://leetcode-cn.com/problems/regular-expression-matching/)  n刷
4. [87. 扰乱字符串](https://leetcode-cn.com/problems/scramble-string/) n刷
5. [91. 解码方法](https://leetcode-cn.com/problems/decode-ways/) n刷
6. [97. 交错字符串](https://leetcode-cn.com/problems/interleaving-string/)
   - 其实不必管“交错”这个词语。只要len1 + len2 = len3，并且s1 s2能组成s3，那就可以形成交错
7. [115. 不同的子序列](https://leetcode-cn.com/problems/distinct-subsequences/)

### 股票问题

1. [121. 买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)
   - 关键是建模：```dp[i][0]```表示第i天未持有股票的最大利润，```dp[i][1]```表示第i天持有股票的最大利润
2. [123. 买卖股票的最佳时机III](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/)
   - 关键是非法值的初始化，必须初始化成-INF/2， 除以2是为了防溢出。不可初始化成0。
3. [188. 买卖股票的最佳时机IV](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/submissions/)
   - 状态压缩
4. [309. 最佳买卖股票时间含冷冻期](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/submissions/)

### 打家劫舍

1. [213. 打家劫舍II](https://leetcode-cn.com/problems/house-robber-ii)
   - 处理环状数组

### 树类问题

1. [95. 不同的二叉搜索树II](https://leetcode-cn.com/problems/unique-binary-search-trees-ii/)

### dp作为解决问题的一个子环节

1. [85. 最大矩形](https://leetcode-cn.com/problems/maximal-rectangle/)
2. [132. 分割回文串II](https://leetcode-cn.com/problems/palindrome-partitioning-ii/)
3. [140. 单词拆分II](https://leetcode-cn.com/problems/word-break-ii/)  n刷
   - 回溯法+ dp：用单词拆分I中的dp提前判断是否需要进入该分支，相当于剪枝了

### 背包问题

1. 0-1背包

   - N个物品分别体积为w，价值为v。背包容量W。如果每个物品只能选择0个或1个，求装哪些使得背包所装物品的价值最大。

     ```cpp
     //dp[i][j]表示考虑[0, i-1]范围的物品，装满背包容量为j时的价值
     //dp[0][0]表示第0个物品装到容量为0的包，的价值，显然为0
     dp[0][0] = 0;
     for(int i = 1; i <= N; i++){
       	for(int j = 0; j <= W; j++){
           	int w = W[i-1], v = 
           	dp[i][j] = j - w[i] >= 0 ? max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]) : dp[i-1][j];
         }  
     }
     return dp[N-1][W];
     
     //空间压缩
     //dp[j]表示在本轮（第i轮）考虑第i-1个元素的时候，容量为j的背包的最大价值
     dp[0] = 0;
     for(int i = 1; i <= N; i++){
       	for(int j = W; j >= w[i]; j--){
           	dp[j] = max(dp[j], dp[j-w[i]] + v[i-1]);
         }
     }
     return dp[N][W];
     ```

   - 0-1背包的注意：

     - 初始化：如果要求物品必须刚好填满背包，则初始化时```dp[0][0]为0，其它的dp[1...N][0]都为无穷小```，因为dp 0 0 表示第-1个物品填满容量为0的背包，这是合法的，价值为0。 如果不要求物品恰好填满背包，则```dp[0...N][0]都为0```
     - 空间压缩：**注意 j 需要倒序遍历**。因为正向的话，dp[j-w[i]]可能访问到的是本轮更新的新值，而我们想要的是上一轮的值。
     - 空间压缩：空间压缩时，被压缩的需要放在循环外层。不空间压缩时，谁在外层都可。但最好还是物品遍历在外层，容量遍历在内层。

2. 完全背包

   - N个物品分别体积为w，价值为v。背包容量W。如果每个物品能选择0到无穷个，求装哪些使得背包所装物品的价值最大。

     ```cpp
     //dp[i][j]表示考虑[0, i-1]范围的物品，装满背包容量为j时的价值
     //dp[0][0]表示第0个物品装到容量为0的包，的价值，显然为0
     dp[0][0] = 0;
     for(int i = 1; i <= N; i++){
       	int w = W[i-1], v = V[i-1];
       	//顺序遍历
       	for(int j = 1; j <= W; j++){
           	dp[i][j] = j-w>=0 ? max(dp[i-1][j], dp[i][j-w] + v) : dp[i-1][j];
         }
     }
     return dp[N][W];
     
     
     //空间压缩
     //dp[j]表示本轮（i）时，[0,i-1]的元素放入大小为j的背包的最大价值
     dp[0] = 0;
     for(int i = 1; i <= N; i++){
       	int w = W[i-1], v = V[i-1];
       	//顺序遍历
       	for(int j = w; j <= W; j++){
           	dp[j] = max(dp[j], dp[j-w] + v); 
         }
     }
     ```

   - 完全背包注意：

     - 遍历：**完全背包的遍历是顺序的**。这样会导致dp[j-w]访问到本轮更新的值。但这样却没有错，因为本轮内的所有遍历的意义是：第i-1个物品尝试放入各种容量的背包。而第i-1个物品可以放无穷个，因此重复了刚好为我们所利用。原本不重复的时候，我们需要遍历k：使得```dp[j] = max(dp[j], dp[j - k * w] + k * v), k需要在合法范围内```,但利用重复效应，我们可以```dp[j] = max(dp[j], dp[j-w] + v)```，仅往前1个，因为前面的元素都已经考虑过放入几个i-1号物品了，因此我们不必重复k个。

3. [37. 组合总和](https://leetcode-cn.com/problems/combination-sum-iv/)

   - 给定n个数字nums[n]，和一个目标和target，求从n个数中选若干使得和为target，有多少种组合，其中数字顺序不同的视为2个组合。如1，2，3和1，3，2
   - 原本的背包问题把枚举num或者target放在循环的内外层都可以，但**本题只能把target放在循环外层**。因为如果把num放在外层，则限制了num的顺序，即当遍历到num[3]的时候，只考虑了放置nums[3]和它前面的数字，后面的数字则还没考虑。列一个dfs的树形图也可以帮助理解。
   - 组合问题，如果考虑nums的顺序(顺序不同的1,2,3和1,3,2视为两个序列)，则需要把num放在内层枚举。不考虑顺序，则把nums放在外层枚举
   - 原始的背包问题target和nums这两个枚举可以随便放在内外层，是因为我们只考虑最大value即nums的和，不考虑nums的顺序有多少种组合，和本题的问题有所不同。

### 游戏博弈类题目

1. [375. 猜数字大小](https://leetcode-cn.com/problems/guess-number-higher-or-lower-ii)

2. [464. 我能赢吗](https://leetcode-cn.com/problems/can-i-win/)

   - dfs + memo

   - 核心思路

     ```cpp
     //判断A是否能赢
     bool dfs(){
       	for(遍历A能做出的所有选择){
           	判断A能不能在这个选择下稳赢或者稳输，返回true或者false
            	if(无法在这一步作出判断){
               	//进一步递归
               	先给A作出当前的选择
                 //这里的dfs是A作出当前选择后，假设角色互换，看B能不能在A的这副牌的情况下赢得比赛，如果B输了，则A赢了
                 bool flag = dfs(当前选择);  //核心步骤
               	if(flag == false)
                   	返回A赢
             }
         }
       	返回A输
     }
     ```

3. [486. 预测赢家](https://leetcode-cn.com/problems/predict-the-winner/)

### 理解题意

1. [467. 环绕字符串中唯一的子字符串](https://leetcode-cn.com/problems/unique-substrings-in-wraparound-string/)



# 7. 分治算法

- 分治算法的核心方法是递归。

- 核心思路是：将问题A分成**2个**或多个同样的但规模更小的子问题，分别递归解决，然后再将这些子问题的答案综合处理(并不一定是合并两个数组，有可能只是综合一个答案)，得到A问题的答案。

1. [241. 为运算表达式设计优先级](https://leetcode-cn.com/problems/different-ways-to-add-parentheses)

2. [932. 漂亮数组](https://leetcode-cn.com/problems/beautiful-array)

   - 用放缩把规模为N的问题变成规模N/2和规模(N + 1) / 2的子问题

3. [169. 多数元素](https://leetcode-cn.com/problems/majority-element/)

   - 分治法找众数。分成两半，左一半的众数和右一半的众数。然后再在整个序列中判断比较它俩谁是众数。

   - 摩尔投票法也很好

4. [395. 至少有k个重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters)

   

# 8. 数学问题

### 素数

1. [204. 计数质数](https://leetcode-cn.com/problems/count-primes/)
   - 筛法判断素数十分有用。可以在判断n是否是素数的时候，顺便判断所有小于n的数字是否是素数

### 进制

1. [168. Excel表列名称](https://leetcode-cn.com/problems/excel-sheet-column-title/)
   - 新型26进制，看笔记
2. [483. 最小好进制](https://leetcode-cn.com/problems/smallest-good-base/)
   - 二分法求进制

### 计算0的个数

1. [172. 阶乘后的0](https://leetcode-cn.com/problems/factorial-trailing-zeroes)
2. [233. 数字1的个数](https://leetcode-cn.com/problems/number-of-digit-one)
3. [357. 计算各个位数不同的数字的个数](https://leetcode-cn.com/problems/count-numbers-with-unique-digits/)
   - 排列组合，3位数，第一位有9种(0不行)，第二位有9种(不和第一位重复)，第三位8种，第四位7种...
4. [400. 第N位数字](https://leetcode-cn.com/problems/nth-digit/)
   - 难题

### 大整数相加

1. [415. 字符串相加](https://leetcode-cn.com/problems/add-strings/)

### 随机与采样

1. [384. 打乱数组](https://leetcode-cn.com/problems/shuffle-an-array/)
   - 关键是shuffle算法
2. [528. 按权重随机选择](https://leetcode-cn.com/problems/random-pick-with-weight/)
   - 累积分布采样
   - Lower_bound 函数
3. [382. 链表随机节点](https://leetcode-cn.com/problems/linked-list-random-node/)
   - **水库采样算法**

4. [470. 用rand7()实现rand10()](https://leetcode-cn.com/problems/implement-rand10-using-rand7/)
   - 拒绝采样
5. [478. 在圆内随机生成点](https://leetcode-cn.com/problems/generate-random-point-in-a-circle/)
   - 拒绝采样

### 利用加减法实现除法

1. [29. 两数相除](https://leetcode-cn.com/problems/divide-two-integers)

### 快速幂

1. [50. pow(x, n)](https://leetcode-cn.com/problems/powx-n/)

   经典的快速幂算法。
   计算x的n次方，只需要先计算n的 n / 2次方为temp。
   如果n为偶数，则答案就是 temp * temp；
   如果n为奇数，则由于n/2时向下取整损失一个，需要temp * temp * x

2. [372. 超级次方](https://leetcode-cn.com/problems/super-pow/)

   - 快速幂

   - 关于mod的定律：a * b的模等于 a的模乘b的模再模。即一个数的模等于它的若干个因子的模的乘积再取模。

     ```
     a = B * c = b1 * b2 * c 其中 B = b1 * b2
     mod(a) = mod( mod(B) * mod(c) ) = mod( mod(b1) * mod(b2) * mod(c) )
     ```

     

### 全排列计数

1. [60. 排列序列](https://leetcode-cn.com/problems/permutation-sequence/)

   - n刷
   - n = 6， k = 373，**首先k--， 因为题目是从1开始计数，我们是从0开始计数**。
   - nums = [1,2,3,4,5,6]；全排列的第一个数字应该为 nums[k / 5!]，然后 k = k % (5!)；

   - List，移动迭代器 advance(begin_iter, n_step)

### 几何题

1. [149. 直线上最多的点数](https://leetcode-cn.com/problems/max-points-on-a-line/)
2. [223. 矩形面积](https://leetcode-cn.com/problems/rectangle-area/)
3. [296. 最佳碰头地点](https://leetcode-cn.com/problems/best-meeting-point)
   - 曼哈顿距离：中位数是最短距离
4. [469. 凸多边形](https://leetcode-cn.com/problems/convex-polygon/)
   - 判断凸多边形用叉乘

### 字符串模拟数字的题

1. [166. 分数到小数](https://leetcode-cn.com/problems/fraction-to-recurring-decimal/)

2. [224. 基本计算器](https://leetcode-cn.com/problems/basic-calculator/)
3. [273. 整数转英文表示](https://leetcode-cn.com/problems/integer-to-english-words/)
4. [423. 从英文中重建数字](https://leetcode-cn.com/problems/reconstruct-original-digits-from-english/)
   - 利用某些英文字母仅仅只出现在某数字中，可以确定这些数字的出现个数。然后再逐一推算

### 数字的规律

1. [258. 各位相加](https://leetcode-cn.com/problems/add-digits/)
   - 数根
2. [319. 灯泡开关](https://leetcode-cn.com/problems/bulb-switcher/)
3. [396. 旋转函数](https://leetcode-cn.com/problems/rotate-function/)

4. [453. 最小操作次数使数组元素相等](https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements/)

   - n刷

5. [365. 水壶问题](https://leetcode-cn.com/problems/water-and-jug-problem)

   - n刷
   - 用栈实现的dfs

6. [458. 可怜的小猪](https://leetcode-cn.com/problems/poor-pigs/)

   - 信息论



# 9. 位运算

###  常用技巧

```cpp
x ^ 0x0000 = x;
x ^ 0xffff = ~x; //注意：~x表示x的补数，不是纯取反。如0b0101的补数是0b10，而纯取反会得到0xfff_1010
x ^ x = 0;

//二进制：0b10010
//八进制：0123567
//16进制: 0xff1cb
```

#### 汉明距离

1. [461. 汉明距离](https://leetcode-cn.com/problems/hamming-distance)
   - 直接异或

### 位运算判断是否是4的次方

1. [342. 4的幂](https://leetcode-cn.com/problems/power-of-four)
   - 先判断是否是2的次方。如果是，则二进制一定为 0b000..010..的形式，利用 **n & (n - 1)可以去除一个数的最低位1的技巧，判断二进制是否仅有1个bit的1**
   - 在2的次方基础上，如果是4的次方，则二进制中1的位置一定在奇数位置，我们让这个数字和0b0101010101(1全在偶数位上的数字)按位与一下，如果结果不为0，说明原数的一些偶数位上有1存在，说明不是4的幂，否则是4的幂

### 用作给单词做字母出现与否的哈希

1. [318. 最大单词长度乘积](https://leetcode-cn.com/problems/maximum-product-of-word-lengths)

### 利用异或找仅出现一次的数字

1. [268. 丢失的数字](https://leetcode-cn.com/problems/missing-number/)
2. [260. 仅出现一次的数字III](https://leetcode-cn.com/problems/single-number-iii)

### 0和1的跳变

1. [201. 数字范围按位与](https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/)

### 异或和&实现加减法

1. [371. 两整数之和](https://leetcode-cn.com/problems/sum-of-two-integers/)

   - ```cpp
         int getSum(int a, int b) {
             unsigned a_ = a, b_ = b;
             do{
               	// (a & b) << 1是两个数字的进位
                 unsigned carry = (a_ & b_) << 1;
               	// a ^ b 是两个数字的不带进位的运算结果
                 a_ ^= b_;
                 b_ = carry;
             }while(b_ != 0);
           	//迭代，直到不含有进位
             return a_;
         }
     ```

### 补码原码相关

1. [405. 数字转换成16进制数](https://leetcode-cn.com/problems/convert-a-number-to-hexadecimal)
   - 直接把int转成unsigned int考虑即可

### 异或

1. [421. 数组中两个数的最大异或值](https://leetcode-cn.com/problems/maximum-xor-of-two-numbers-in-an-array/)
2. [477. 汉明距离总和](https://leetcode-cn.com/problems/total-hamming-distance/)

### 检查是否溢出

1. [7. 整数反转](https://leetcode-cn.com/problems/reverse-integer/)

   - 在不适用long long的情况下的检验溢出方法

     ```cpp
     if(newNum > INT_MAX / 10 || newNum == INT_MAX / 10 && digit > 7)
         return 溢出;
     if(newNum < INT_MIN / 10 || newNum == INT_MIN / 10 && digit < -8)
         return 溢出;
     ```

     

  

# 10. 数据结构

### 数组

1. [48. 旋转矩阵](https://leetcode-cn.com/problems/rotate-image)
2. [769. 最多能完成排序的块](https://leetcode-cn.com/problems/max-chunks-to-make-sorted)

### 栈和队列

1. [20. 有效的括号](https://leetcode-cn.com/problems/valid-parentheses)
2. [71. 简化路径](https://leetcode-cn.com/problems/simplify-path/)
3. [155. 最小栈](https://leetcode-cn.com/problems/min-stack/)
   - 利用两个栈，一个数据栈，一个min元素栈

### 栈 + 递归解析字符串or计算表达式（n刷）

- 此类题目就两种思路：1）利用栈，尤其是遇到括号类题目   2）利用递归

1. [341. 扁平化嵌套迭代器](https://leetcode-cn.com/problems/flatten-nested-list-iterator/)
   - 利用栈实现多叉树的先序遍历，的迭代器
   - 关键在于：list内的元素要逆序入栈
2. [394. 字符串解码](https://leetcode-cn.com/problems/decode-string/)
   - 这类解析括号的题目，最好利用栈解决
3. [493. 三元表达式解析器](https://leetcode-cn.com/problems/ternary-expression-parser/)
   - 本题使用递归做最简单
   - 关于？和：的匹配：使用cnt1记录问号个数，cnt2记录冒号个数，当两者相等的时候，就是匹配的时候，类似于括号的L计数和R计数

### 单调栈

单调栈主要寻找每个元素在数组中的下一个更大元素，或者下一个更小元素

1. [739. 每日温度](https://leetcode-cn.com/problems/daily-temperatures)

   - 栈内存储**数组索引**即可，具体温度可以通过索引查找原数组。
2. [503. 下一个更大的元素II](https://leetcode-cn.com/problems/next-greater-element-ii)
3. [42. 接雨水](https://leetcode-cn.com/problems/trapping-rain-water/)
4. [84. 柱状图中最大的矩形](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/)

- 单调递增栈

5. [456. 132模式](https://leetcode-cn.com/problems/132-pattern/)
   - min的dp + 单调栈
   - 单调栈反向扫描
6. [496. 下一个更大的元素I](https://leetcode-cn.com/problems/next-greater-element-i/)

### 单调队列

单调队列可以用deque改造而成。单调队列和优先队列不一样，单调队列类似单调栈，为了维持有序性，可能会删除一些队列内元素。

1. [239. 滑动窗口最大值](https://leetcode-cn.com/problems/sliding-window-maximum)
   - 同样存储index而非元素比较方便
   - 维持队列内部元素由队尾到队首单调递增，这样队首就是最大元素的index

### 优先队列

1. [218. 天际线](https://leetcode-cn.com/problems/the-skyline-problem)
   - 本题主要要用到堆，大顶堆来维护当前楼房轮廓的最大高度。可以使用priority_queue，但也可以使用multiset，这里使用multiset
   - 最后一个元素可以用 rbegin() 迭代器
   - multiset删除元素时，erase(x)代表删除所有值为x的元素，erase(find(x))代表删除查找到的第一个x元素

### 双端队列

1. [239. 滑动窗口最大值](https://leetcode-cn.com/problems/sliding-window-maximum/)
   - 双端队列 ，做成 单调栈 的形式。其中单调栈为从左到右单调递减，内部仅存储元素索引
2. [353. 贪吃蛇](https://leetcode-cn.com/problems/design-snake-game)
   - 双端队列可以模拟贪吃蛇，内部存放蛇的整个身体

### 堆

1. [295. 数据流中位数](https://leetcode-cn.com/problems/find-median-from-data-stream/)
   - 两个堆维持前一半的最大值，和后一半的最小值
   - 数据到来后，先进入前一半，然后前一半再pop一个最大值给后一半。然后如果前一半的size太小，再从后一半匀一个给前面
2. [358. K距离间隔重拍字符串](https://leetcode-cn.com/problems/rearrange-string-k-distance-apart)
   - 既然不要求顺序，就把每个字母的频率记录下来，然后建堆重新拍字符串即可。
3. [373. 查找和最小的K对数字](https://leetcode-cn.com/problems/find-k-pairs-with-smallest-sums/)

### 哈希表

1. [128. 最长连续序列](https://leetcode-cn.com/problems/longest-consecutive-sequence)
2. [560. 和为K的子数组](https://leetcode-cn.com/problems/subarray-sum-equals-k/)
   - 哈希表 + 前缀和
3. [697. 数组的度](https://leetcode-cn.com/problems/degree-of-an-array/)
   - 下标位置也可以存为哈希表，且可以分为l_idx 和 r_idx 分别存储
4. [594. 最长和谐子序列](https://leetcode-cn.com/problems/longest-harmonious-subsequence/)
5. [870. 优势洗牌](https://leetcode-cn.com/problems/advantage-shuffle/)
   - 最好存储原数组的idx，而非原数组的元素，因为可能出现重复
6. [249. 移位字符串分组](https://leetcode-cn.com/problems/group-shifted-strings/)
   - 把所有数据都归一化为标准的key，再存储到哈希表。本题是把所有字符串都归一化到以'a'开头，然后在存储。
7. [380. 常数时间插入、删除、获取随机元素](https://leetcode-cn.com/problems/insert-delete-getrandom-o1)

### 欧拉回路

1. [332. 重新安排行程](https://leetcode-cn.com/problems/reconstruct-itinerary/)

   - 欧拉路径：通过所有边恰好一次，且通过了所有顶点（不要求刚好1次），的路径称为欧拉路径

     欧拉回路：通过所有边恰好一次，且通过了所有顶点（不要求刚好1次），的**回路**称**欧拉回路**

   - 求欧拉路径的Hierholzer 算法：

     ```cpp
     //1. 从起点src出发，进行深度优先搜索。
     //2. 每次沿着某条边从src移动到另外一个顶点dst的时候，都需要【删除这条边】（删除dst）。
     //3. 深搜完src的所有邻居后，则将src加入到栈中，并返回。
     ```

   - 注意

     - 3中，节点也可以按照push_back加入到vector中，只需要最后得到答案后reverse即可
     - 删除边的时候，注意迭代器失效问题。



# 11. 字符串

1. [468. 验证IP地址](https://leetcode-cn.com/problems/validate-ip-address/)

   - 正则表达式的C++用法

     ```cpp
     class Solution {
     public:
       	//正则表达式的用法
         string validIPAddress(string IP) {
             string ipv4_num = "([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])";
             regex ipv4_pattern("^(" + ipv4_num + "\\.){3}" + ipv4_num + "$");
             string ipv6_num = "[0-9a-fA-F]{1,4}";
             regex ipv6_pattern("^(" + ipv6_num + "\\:){7}" + ipv6_num + "$");
             if(regex_match(IP, ipv4_pattern)){
                 return "IPv4";
             }else if(regex_match(IP, ipv6_pattern)){
                 return "IPv6";
             }else{
                 return "Neither";
             }
         }
     };
     ```

   - getline + stringstream：可以读取指定字符分割的字符串

     ```cpp
     //getline + stringstream：可以读取指定字符分割的字符串
     stringstream ss(str);
     string word;
     while(getline(ss, word, ':')){
       	//以冒号分割，读取字符串
     }
     ```

2. [521. 最长特殊序列I](https://leetcode-cn.com/problems/longest-uncommon-subsequence-i/)

   - 脑筋急转弯

3. [459. 重复的子字符串](https://leetcode-cn.com/problems/repeated-substring-pattern/)

   - 判断一个字符串s能否由他自己的一个子字符串重复多次构成

     ```cpp
     return (s + s).find(s, 1) == s.size(); //从idx = 1位置开始在s+s中查找s
     ```

4. [434. 字符串中的单词数](https://leetcode-cn.com/problems/number-of-segments-in-a-string/)

   - stringstream >> string的时候，自动以空白符作为间隔

5. [696. 计数二进制子串](https://leetcode-cn.com/problems/count-binary-substrings/)

6. [647. 回文子串](https://leetcode-cn.com/problems/palindromic-substrings/)

   - 中心向两边扩展的暴力枚举法
   - 回文串的通用算法：中心向两边扩展



# 12. 链表

1. [206. 反转链表](https://leetcode-cn.com/problems/reverse-linked-list/)

   - 双指针法
   - 递归法
   - 保底的头插法

2. [21. 合并两个有序链表](https://leetcode-cn.com/problems/merge-two-sorted-lists/)

   - 注意合并有序链表的while 内部条件

     ```cpp
     if(listA == nullptr || listB != nullptr && listB->val < listA->val)
       	接入B
     else 接入A
     ```

3. [24. 两两交换链表中的节点](https://leetcode-cn.com/problems/swap-nodes-in-pairs/)

   - 递归法好用

4. [160. 相交链表](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/)

   - 经典的快慢指针法追赶法求重合交点。详见答案

5. [83. 删除排序链表中的重复元素](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/)

   - 记得使用dummy节点

6. [19. 删除链表的倒数第N个节点](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list)

   - 经典的快慢指针法

7. [141. 环形链表](https://leetcode-cn.com/problems/linked-list-cycle/)

   - 快慢指针法，查找是否存在环形。快指针走2步，慢指针走1步。如果他们相遇，说明有环。如果快指针走到nullptr，说明无环

8. [142. 环形链表](https://leetcode-cn.com/problems/linked-list-cycle-ii)

   - 环形链表 找入环的第一个节点的方法

9. [143. 重排链表](https://leetcode-cn.com/problems/reorder-list/)

   - 涉及到找链表中点+逆序链表+合并链表
   - 找中点：最好也先用一个dummy node，这样可以使slow指针停留在中点的前一个元素上。

10. [430. 扁平化多级双向链表](https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list/)

    - 可以看做左子树右子树



# 13. 树

### 树的递归、求深度

1. [104. 二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)

2. [543. 二叉树的直径](https://leetcode-cn.com/problems/diameter-of-binary-tree/)

   - 必要时，答案可以用过引用参数传递，而函数返回值用于传递一些递归必要的中间结果；比如本题中，返回值可以传递单链的结果。ans在引用中，传递综合的答案

3. [437. 路径总和](https://leetcode-cn.com/problems/path-sum-iii/)

   - 递归+递归。两个递归函数
   - 同理题 [124. 二叉树中的最大路径和](https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/)

4. [572. 另一个树的子树](https://leetcode-cn.com/problems/subtree-of-another-tree/)

   - 递归 + 递归。两个递归函数

5. [101. 对称二叉树](https://leetcode-cn.com/problems/symmetric-tree/)

6. [1110. 删点成林](https://leetcode-cn.com/problems/delete-nodes-and-return-forest/)

7. [105. 从前序和中序遍历中建立二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

   - 可以搞个中序的map，方便查找root的index

8. [144. 二叉树的先序非递归遍历](https://leetcode-cn.com/problems/binary-tree-preorder-traversal/)

   - 先序非递归遍历有两种；目前只记得一种

   

### BST

1. [450. 删除二叉搜索树中的节点](https://leetcode-cn.com/problems/delete-node-in-a-bst/)

   - BST的基本问题：删除节点；注意

     ```cpp
     TreeNode* deleteNode(TreeNode* root, int key) {
             if(root == nullptr)
                 return root;
             if(root->val > key){
                 root->left = deleteNode(root->left, key);
             }else if(root->val < key){
                 root->right = deleteNode(root->right, key);
             }else if(root->left && root->right){
                 TreeNode* temp = root->right;
                 while(temp->left){
                     temp = temp->left;
                 }
               	//这里不能 temp和root的val交换，然后在root的右子树继续删除key
               	//因为交换后，右子树就不符合bst的性质了
               	//应该是：root的值改为temp的值。然后再右子树中删除【temp的值】
                 root->val = temp->val;
                 root->right = deleteNode(root->right, temp->val);
             }else{
                 TreeNode* del = root;
           			//这里必须是如果left空，则为right；
               	//不能：如果left非空，则left；如果right非空，则right；因为存在left和right都空的情况
                 if(root->left == nullptr) root = root->right;
                 else if(root->right == nullptr) root = root->left;
                 delete del;
             }
             return root;
         }
     ```

2. [99. 恢复二叉树](https://leetcode-cn.com/problems/recover-binary-search-tree/)

   - 中序遍历bst，并且使用带引用的pre参数记录上一个节点。从而找到逆序的节点pair。注意，pre必须带引用

3. [669. 修剪二叉树](https://leetcode-cn.com/problems/trim-a-binary-search-tree/)

   - 运用了bst的性质：如果root大于[a, b]的右边界b，则root、包括其右子树都肯定大于b，因此直接返回root->left的修剪结果即可。同理于左子树

4. [538. 二叉搜索树转化为累加树](https://leetcode-cn.com/problems/convert-bst-to-greater-tree/)

   - 中序递归遍历的创新： 右子树->root->左子树

5. [235. 二叉搜索树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)

6. [897. 递增顺序查找树](https://leetcode-cn.com/problems/increasing-order-search-tree/)

7. [95. 不同的二叉搜索树II](https://leetcode-cn.com/problems/unique-binary-search-trees-ii/)

   - 递归法
   - dp

8. [98. 验证二叉搜索树](https://leetcode-cn.com/problems/validate-binary-search-tree/)

   - 不可仅仅验证：root的左孩子小于root，右孩子大于root；而应该验证root的前驱(左子树的最右边)小于root，后继(右子树的最左边)大于root

   

### TRIE前缀树

1. [208. 实现TRIE](https://leetcode-cn.com/problems/implement-trie-prefix-tree/)

### 前中后序建树、遍历

1. [889. 前序和后序遍历建立二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/)

   - 前序[pre_l, pre_r]， 后序[post_l, post_r]；
   - 根据前序，pre_l为根节点，pre_l + 1为它的左子树的根节点。而这个左子树根节点在后序中的索引为idx，则后序序列中[post_l, idx]为左子树；
   - 由此，左子树llen就知道了，因此可以区分左右子树，然后递归建树

2. [145. 二叉树的后序遍历](https://leetcode-cn.com/problems/binary-tree-postorder-traversal/)

   ```cpp
   class Solution {
   public:
       vector<int> postorderTraversal(TreeNode* root) {
           stack<TreeNode*> stk;
           TreeNode* pre = nullptr;
           vector<int> ans;
           while(!stk.empty() || root){
               while(root){
                   stk.push(root);
                   root = root->left;
               }
               root = stk.top(); stk.pop();
               if(root->right == nullptr || root->right == pre){
                   ans.push_back(root->val);
                   pre = root;
                   root = nullptr;
               }else{
                   stk.push(root);
                   root = root->right;
               }
           }
           return ans;
       }
   };
   ```

3. [236. LCA](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/)

   ```cpp
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
           if(root == nullptr || root == p || root == q){
               return root;
           }
           TreeNode* lresult = lowestCommonAncestor(root->left, p, q);
           TreeNode* rresult = lowestCommonAncestor(root->right, p, q);
           if(lresult == nullptr)  return rresult;
           else if(rresult == nullptr) return lresult;
           else return root;
     }
   ```

4. [109. 有序链表转换为二叉搜索树](https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/)

   - 快慢指针法找中点
   - dummy节点很好用

### 关于树的其它

1. [116. 填充每个节点的下一个右侧节点指针](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/)
2. [117. 填充每个节点的下一个右侧节点指针II](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/)
3. [156. 上下翻转二叉树](https://leetcode-cn.com/problems/binary-tree-upside-down/)
4. [250. 统计同值子树](https://leetcode-cn.com/problems/count-univalue-subtrees/)
5. [255. 验证前序遍历序列二叉搜索树](https://leetcode-cn.com/problems/verify-preorder-sequence-in-binary-search-tree/)
6. [297. 二叉树的序列化和反序列化](https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/)
   - 先序递归
   - iostringstream 的i和o是以用户为中心（用户就是string）说的。i指的是istringstream >> string, o指的是string >> stringstream;
7. [428. 序列化与反序列化N叉树](https://leetcode-cn.com/problems/serialize-and-deserialize-n-ary-tree/submissions/)
   - 先序，先序列化根。然后记录一个孩子节点个数
8. [431. N叉树和二叉树的互相转化](https://leetcode-cn.com/problems/encode-n-ary-tree-to-binary-tree/)



# 14. 图

### 图的BFS和DFS遍历

1. [785. 判断二分图](https://leetcode-cn.com/problems/is-graph-bipartite/)
2. [1059. 从起点到终点的所有路径](https://leetcode-cn.com/problems/is-graph-bipartite/)

### 最小生成树

1. [1135. 最低成本联通所有城市](https://leetcode-cn.com/problems/connecting-cities-with-minimum-cost/)
   - 用到了并查集，并查集的易错点：合并u和v，应该是 【u的father = v的father】，而非 【u的father = v】

### 拓扑排序

1. [210. 课程表II](https://leetcode-cn.com/problems/course-schedule-ii/)
   - 邻接表 + indegree数组 + 度数为0的node可以放入queue

### 树的最小高度

1. [310. 最小高度树](https://leetcode-cn.com/problems/minimum-height-trees)
   - 使用BFS，从叶节点向根节点一层一层遍历。需要inDegree数组辅助

