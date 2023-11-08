#include <iostream>
#include <cstdlib>
#include "recursive.h"
#include "p2.h"
// no other libraries
using namespace std;
// no global variables

int size(list_t list)
{
    if (list_isEmpty(list))
    {
        return 0;
    }
    else
    {
        int rest_size = size(list_rest(list));
        return 1 + rest_size;
    }
}

list_t append(list_t list1, list_t list2)
{
    if (list_isEmpty(list1))
    {
        // If the list1 is empty, simply return the list2
        return list2;
    }
    else
    {
        // Get the first element of the list1
        int first_elt = list_first(list1);

        // Recursively append the rest of the list1 with the list2
        list_t rest_appended = append(list_rest(list1), list2);

        // Create a new list with the first element and the appended rest
        return list_make(first_elt, rest_appended);
    }
}

list_t reverse(list_t list)
{
    if (list_isEmpty(list))
    {
        return list_make(); // 递归结束, 即创造的开始, 新建一个list
    }
    else
    {
        list_t list_back = list_make(list_first(list), list_make()); // 在每次添加元素后加一个新位置
        list_t list_front = reverse(list_rest(list));
        return append(list_front, list_back);
    }
}

int sum(list_t list)
{
    if (list_isEmpty(list))
    {
        return 0;
    }
    else
    {
        return list_first(list) + sum(list_rest(list));
    }
}

int product(list_t list)
{
    if (list_isEmpty(list))
    {
        return 1;
    }
    else
    {
        return list_first(list) * product(list_rest(list));
    }
}

list_t filter_odd(list_t list)
{
    if (list_isEmpty(list))
    {
        return list_make();
    }
    else
    {
        if (list_first(list) % 2 != 0)
        {
            return list_make(list_first(list), filter_odd(list_rest(list)));
        }
        else
        {
            return filter_odd(list_rest(list));
        }
    }
}

list_t filter_even(list_t list)
{
    if (list_isEmpty(list))
    {
        return list_make();
    }
    else
    {
        if (list_first(list) % 2 == 0)
        {
            return list_make(list_first(list), filter_even(list_rest(list)));
        }
        else
        {
            return filter_even(list_rest(list));
        }
    }
}

bool odd(int a)
{
    return a % 2 != 0;
}
bool even(int a)
{
    return a % 2 == 0;
}

list_t filter(list_t list, bool (*fn)(int))
{
    if (list_isEmpty(list))
    {
        return list_make();
    }
    else
    {
        if (fn(list_first(list)))
        {
            return list_make(list_first(list), filter(list_rest(list), fn));
        }
        else
        {
            return filter(list_rest(list), fn);
        }
    }
}

list_t insert_list(list_t first, list_t second, unsigned int n)
{
    if (list_isEmpty(first)) // 第一个条件
    {
        return second;
    }
    else if (n == 0) // 第二个条件n=0时, 直接把second接在first前面
    {
        return append(second, first);
    }
    else
    {
        return list_make(list_first(first), insert_list(list_rest(first), second, n - 1));
    }
}

list_t chop(list_t list, unsigned int n)
{
    if ((size(list)) <= static_cast<int>(n))
    {
        return list_make();
    }
    else
    {
        return list_make(list_first(list), chop(list_rest(list), n));
    }
}

// function for tree
// 最重要的是记住左右子树的遍历都不包括tree_elt, 根节点需要另加条件

int tree_sum(tree_t tree)
{
    if (tree_isEmpty(tree))
    {
        return 0;
    }
    else
    {
        return tree_elt(tree) + tree_sum(tree_left(tree)) + tree_sum(tree_right(tree));
    }
}

/**
 * @brief 结束条件: tree为空
 * 步骤:
 * 1. 根节点等于key直接返回
 * 2. 遍历左子树, 右子树,查找是否有key
 *
 * @param tree
 * @param key
 * @return true
 * @return false
 */
bool tree_search(tree_t tree, int key)
{
    if (tree_isEmpty(tree))
    {
        return false;
    }
    else
    {
        if (tree_elt(tree) == key)
        {
            return true;
        }
        else
        {
            return tree_search(tree_left(tree), key) || tree_search(tree_right(tree), key);
        }
    }
}

/**
 * @brief 结束条件: tree空
 * 步骤:
 * 1. 递归遍历左子树
 * 2. 递归遍历右子树
 * 3. 比较左右子树的深度, 返回较大值
 * @param tree
 * @return int
 */
int depth(tree_t tree)
{
    if (tree_isEmpty(tree))
    {
        return 0;
    }
    else
    {
        return depth(tree_left(tree)) > depth(tree_right(tree)) ? (depth(tree_left(tree)) + 1) : (depth(tree_right(tree)) + 1);
    }
}

/**
 * @brief 结束条件: 遍历完, tree为空, 返回特征值-1
 * 步骤:
 * 1. 递归遍历左子树
 * 2. 递归遍历右子树
 * 3. 比较左右子树的最小值, 返回最小值
 * 4. 比较根节点和最小值, 返回最小值
 * 5. 如果是-1, 说明左右子树都为空, 直接返回根节点
 * @param tree
 * @return int
 */
int tree_min(tree_t tree)
{
    int max = 10000;
    if (tree_isEmpty(tree))
    {
        return max;
    }
    else
    {
        int compare = tree_min(tree_left(tree)) < tree_min(tree_right(tree)) ? tree_min(tree_left(tree)) : tree_min(tree_right(tree));
        if (compare != max) // 如果不是-1, 说明左右子树至少有一个不为空
        {
            return tree_elt(tree) < compare ? tree_elt(tree) : compare;
        }
        else
        {
            return tree_elt(tree); // 如果是-1, 说明左右子树都为空, 直接返回根节点
        }
    }
}

/**
 * @brief 结束条件: 遍历完, tree为空
 * 步骤:
 * 1. 递归遍历左子树
 * 2. 将根节点加入list
 * 3. 递归遍历右子树
 *
 * @param tree
 * @return list_t
 */
list_t traversal(tree_t tree) // 左->根->右
{
    if (tree_isEmpty(tree))
    {
        return list_make();
    }
    else
    {
        list_t tempt = append(traversal(tree_left(tree)), list_make(tree_elt(tree), list_make())); // 先遍历左子树, 把根节点加入list
        return append(tempt, traversal(tree_right(tree)));                                         // 再遍历右子树
    }
}

/**
 * @brief 结束条件: 遍历完, tree为空
 * 步骤:
 * @return false
 */
bool tree_hasPathSum(tree_t tree, int sum)
{
    if (tree_isEmpty(tree)) // 空树的路径上元素和为0, 递归结束
    {
        return false;
    }
    else
    {

        if (tree_isEmpty(tree_left(tree)) && tree_isEmpty(tree_right(tree)))
        {
            return tree_elt(tree) == sum; // 如果是叶子节点, 判断是否等于sum
        }
        else
        {
            int new_sum = sum - tree_elt(tree);
            return tree_hasPathSum(tree_left(tree), new_sum) || tree_hasPathSum(tree_right(tree), new_sum);
        }
    }
}

/**
 * @brief 结束条件: 遍历完
 * 步骤:
 * 1. 判断A 是否为空, 如果为空, 返回true
 * 2. 判断B 是否为空, 如果为空, 返回false
 * 3. 判断A的根节点是否等于B的根节点
 * 4. 如果相等, 判断A的左子树是否被B的左子树覆盖, A的右子树是否被B的右子树覆盖
 * 5. 如果不相等, 判断A是否被B的左子树覆盖, A是否被B的右子树覆盖
 *
 *
 * @param A
 * @param B
 * @return true
 * @return false
 */
bool covered_by(tree_t A, tree_t B)
{
    if (tree_isEmpty(A))
    {
        return true;
    }
    if (tree_isEmpty(B))
    {
        return false;
    }
    else
    {
        return (tree_elt(A) == tree_elt(B)) && covered_by(tree_left(A), tree_left(B)) && covered_by(tree_right(A), tree_right(B));
    }
}

bool contained_by(tree_t A, tree_t B)
{
    if (covered_by(A, B))
    {
        return true;
    }
    if (tree_isEmpty(A))
    {
        return true;
    }
    if (tree_isEmpty(B))
    {
        return false;
    }
    else
    {
        return contained_by(A, tree_left(B)) || contained_by(A, tree_right(B));
    }
}

tree_t insert_tree(int elt, tree_t tree)
{
    if (tree_isEmpty(tree))
    {
        return tree_make(elt, tree_make(), tree_make());
    }
    if (elt < tree_elt(tree))
    {
        return tree_make(tree_elt(tree), insert_tree(elt, tree_left(tree)), tree_right(tree));
    }
    else
    {
        return tree_make(tree_elt(tree), tree_left(tree), insert_tree(elt, tree_right(tree)));
    }
}

int main()
{
    tree_t start = tree_make(9, tree_make(4, tree_make(8, tree_make(), tree_make()), tree_make()), tree_make());//case1
    // tree_t start = tree_make(30, tree_make(25, tree_make(), tree_make(35, tree_make(), tree_make())), tree_make());//case2
    // tree_t start = tree_make(
    //     19,
    //     tree_make(17,
    //               tree_make(15,
    //                         tree_make(13,
    //                                   tree_make(11,
    //                                             tree_make(9,
    //                                                       tree_make(7,
    //                                                                 tree_make(5,
    //                                                                           tree_make(3,
    //                                                                                     tree_make(),
    //                                                                                     tree_make()),
    //                                                                           tree_make(6,
    //                                                                                     tree_make(),
    //                                                                                     tree_make())),
    //                                                                 tree_make(8,
    //                                                                           tree_make(),
    //                                                                           tree_make())),
    //                                                       tree_make(10,
    //                                                                 tree_make(),
    //                                                                 tree_make())),
    //                                             tree_make()),
    //                                   tree_make()),
    //                         tree_make()),
    //               tree_make(20,
    //                         tree_make(),
    //                         tree_make())),
    //     tree_make(17,
    //               tree_make(15,
    //                         tree_make(13,
    //                                   tree_make(11,
    //                                             tree_make(9,
    //                                                       tree_make(7,
    //                                                                 tree_make(5,
    //                                                                           tree_make(3,
    //                                                                                     tree_make(),
    //                                                                                     tree_make()),
    //                                                                           tree_make(6,
    //                                                                                     tree_make(),
    //                                                                                     tree_make())),
    //                                                                 tree_make(8,
    //                                                                           tree_make(),
    //                                                                           tree_make())),
    //                                                       tree_make(10,
    //                                                                 tree_make(),
    //                                                                 tree_make())),
    //                                             tree_make()),
    //                                   tree_make()),
    //                         tree_make()),
    //               tree_make(20,
    //                         tree_make(),
    //                         tree_make())));//case3
    //     tree_t start = tree_make(
    //     1,
    //     tree_make(2,
    //         tree_make(3,
    //             tree_make(4,
    //                 tree_make(5,
    //                     tree_make(),
    //                     tree_make()
    //                 ),
    //                 tree_make(6,
    //                     tree_make(),
    //                     tree_make()
    //                 )
    //             ),
    //             tree_make(7,
    //                 tree_make(8,
    //                     tree_make(),
    //                     tree_make()
    //                 ),
    //                 tree_make(9,
    //                     tree_make(),
    //                     tree_make()
    //                 )
    //             )
    //         ),
    //         tree_make(10,
    //             tree_make(11,
    //                 tree_make(12,
    //                     tree_make(),
    //                     tree_make()
    //                 ),
    //                 tree_make(13,
    //                     tree_make(),
    //                     tree_make()
    //                 )
    //             ),
    //             tree_make(14,
    //                 tree_make(15,
    //                     tree_make(),
    //                     tree_make()
    //                 ),
    //                 tree_make(16,
    //                     tree_make(),
    //                     tree_make()
    //                 )
    //             )
    //         )
    //     ),
    //     tree_make(17,
    //         tree_make(18,
    //             tree_make(19,
    //                 tree_make(20,
    //                     tree_make(),
    //                     tree_make()
    //                 ),
    //                 tree_make(21,
    //                     tree_make(),
    //                     tree_make()
    //                 )
    //             ),
    //             tree_make(22,
    //                 tree_make(23,
    //                     tree_make(),
    //                     tree_make()
    //                 ),
    //                 tree_make(24,
    //                     tree_make(),
    //                     tree_make()
    //                 )
    //             )
    //         ),
    //         tree_make(25,
    //             tree_make(26,
    //                 tree_make(27,
    //                     tree_make(),
    //                     tree_make()
    //                 ),
    //                 tree_make(28,
    //                     tree_make(),
    //                     tree_make()
    //                 )
    //             ),
    //             tree_make(29,
    //                 tree_make(30,
    //                     tree_make(),
    //                     tree_make()
    //                 ),
    //                 tree_make(31,
    //                     tree_make(),
    //                     tree_make()
    //                 )
    //             )
    //         )
    //     )
    // );

    tree_t end = tree_make(9, tree_make(4, tree_make(8, tree_make(), tree_make()), tree_make()), tree_make());
    int minend = tree_min(end);
    cout << tree_isEmpty(tree_right(end)) << endl;
    cout << "minend" << minend << endl;
    tree_t empty = tree_make();
    // tree_t candidate = insert_tree(3, start);
    cout << "tree_start" << endl;
    // tree_print(start);
    cout << endl;
    cout << "tree_end" << endl;
    tree_print(end);
    cout << endl
         << endl;
    // cout << "sum of tree start " << tree_sum(start) << endl;
    // cout << "whether there is 21 in tree start? " << tree_search(start, 21) << endl; // 0 means false
    // cout << "depth of start: " << depth(start) << endl;
    // cout << "min of start: " << tree_min(start) << endl;
    cout << "traversal of start: ";
    // list_print(traversal(start));
    cout << endl;
    cout << "traversal of end: ";
    list_print(traversal(end));
    cout << endl;
    // cout << "whether there is a path sum of 21 in start? " << tree_hasPathSum(start, 21) << endl;
    // cout << "whether start is covered by end? " << covered_by(start, end) << endl;
    // cout << "whether start is contaied by end? " << contained_by(start, end) << endl;
    cout << "insert 5 into end" << endl;
    tree_t new_end = insert_tree(5, end);
    cout << "traversal of new end: ";
    tree_print(new_end);

    list_print(traversal(new_end));
    cout << endl;
    return 0;
}