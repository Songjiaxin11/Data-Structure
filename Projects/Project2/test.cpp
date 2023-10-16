
// bool contained_by(tree_t A, tree_t B)
// {
    
// }

// int main()
// {
//     tree_t start = tree_make(9, tree_make(4, tree_make(8, tree_make(), tree_make()), tree_make()), tree_make());
//     tree_t end = tree_make(9, tree_make(4, tree_make(8, tree_make(), tree_make()), tree_make()), tree_make(5, tree_make(20, tree_make(), tree_make()), tree_make()));
//     tree_t empty = tree_make();
//     // tree_t candidate = insert_tree(3, start);
//     cout << "tree_start" << endl;
//     tree_print(start);
//     cout << endl;
//     cout << "tree_end" << endl;
//     tree_print(end);
//     cout << endl
//          << endl;
//     cout << "sum of tree start " << tree_sum(start) << endl;
//     cout << "whether there is 21 in tree start? " << tree_search(start, 21) << endl; // 0 means false
//     cout << "depth of start: " << depth(start) << endl;
//     cout << "min of start: " << tree_min(start) << endl;
//     cout << "traversal of start: ";
//     list_print(traversal(start));
//     cout << endl;
//     cout << "whether there is a path sum of 21 in start? " << tree_hasPathSum(start, 21) << endl;
//     cout << "whether start is covered by end? " << covered_by(start, end) << endl;
//     cout << "whether start is contaied by end? " << contained_by(start, end) << endl;
//     cout<<"insert 3 into start"<<endl;
//     tree_print(insert_tree(3, start));
//     return 0;
// }
/*main for list
int main()
{
    int i;
    list_t listA;
    list_t listB;
    list_t listE;
    listA = list_make();
    listB = list_make();
    listE = list_make(); // An empty list
    for (i = 5; i > 0; i--)
    {
        listA = list_make(i, listA);
        listB = list_make(i + 10, listB);
    }

    cout << "listA";
    list_print(listA);
    cout << endl;
    cout << "product of A " << product(listA) << endl;
    cout << "product of E " << product(listE) << endl; // 空的难道是1吗?

    cout << "listB";
    list_print(listB);
    cout << endl;
    cout << "listE";
    list_print(listE);
    cout << endl;

    listA = append(reverse(listA), listB);
    cout << endl;
    cout << "new listA";
    list_print(listA);
    cout << endl;
    cout << "size_of A: " << size(listA) << endl;
    cout << "size_of E: " << size(listE) << endl;
    cout << "sum_of A: " << sum(listA) << endl;
    // cout << "filter_odd of A: ";
    // list_print(filter_odd(listA));
    // cout << endl;
    // cout << "filter_even of A: ";
    // list_print(filter_even(listA));
    // cout << endl;
    // cout << "filter_even of E: ";
    // list_print(filter_even(listE));
    // cout << endl;
    cout << "filter of A odd: ";
    list_print(filter(listA, odd));
    cout << endl;
    cout << "filter of A even: ";
    list_print(filter(listA, even));
    cout << endl;
    cout << "insert_list(listA, listB,3):";
    list_print(insert_list(listA, listB, 3));
    cout << endl;
    cout << "chop(listB,3):";
    list_print(chop(listB, 3));
    cout << endl;
}
*/