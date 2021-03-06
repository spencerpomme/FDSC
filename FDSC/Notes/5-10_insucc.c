/* learning binary tree with thread from FDSC on page 133-137 */
/* code list 5-10 and 5-11 */
typedef struct threaded_tree *thread_pointer;
struct threaded_tree {
	bool left_thread;
	bool right_thread;
	ElementType data;
	threaded_pointer left_child;
	threaded_pointer right_child;
}

threaded_pointer insucc(threaded_pointer node)
{
	/* find the inorder sucessor of node in a threaded binary tree */
	threaded_pointer temp;
	temp = node->right_child;
	if (!tree->right_thread)
		while (!temp->left_child)
			temp = temp->left_child;
	return temp;
}

void tinorder(threaded_pointer tree)
{
	/* traversal the threaded binary tree inorder */
	threaded_pointer temp = tree;
	for (;;)
	{
		temp = insucc(temp); 
		if (temp == tree) break;
		printf("%d ", temp->data);
	}
}