/* determine if two binary trees are identical */
bool isEqual(BTree t1, BTree t2)
{
    return (!t1 && !t2) || (t1 && t2 && (t1->data == t2->data) &&
    isEqual(t1->left, t2->left) && isEqual(t1->right, t2->right));
}