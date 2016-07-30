/*
二叉树的遍历：
1.先序遍历
void PreOrderTraversal(BinTree BT)
{
  if(BT)
  {
    printf("%d",BT->Data);
    PreOrderTraversal(BT->Left);
    PreOrderTraversal(BT->Right);
  }
}
2.中序遍历
void InOrderTraversal(BinTree BT)
{
  if(BT)
  {
    InOrderTraversal(BT->Left);
    printf("%d",BT->Data);
    InOrderTraversal(BT->Right);
  }
}
3.后序遍历
void PostOrderTraversal(BinTree BT)
{
  if(BT)
  {
    PostOrderTraversal(BT->Left);
    PostOrderTraversal(BT->Right);
    printf("%d",BT->Data);
  }
}
先序、中序和后序遍历过程：遍历过程中经过结点的路线一样，只是访问各结点的时机不同。
*/

/*
二叉树的非递归遍历：
中序非递归：
实现的基本思路：使用堆栈
实现算法：
  *遇到一个结点就把它压入栈，并去遍历它的左子树；
  *当左子树遍历结束后，从栈顶弹出这个结点并访问它；
  *然后按照其右指针再去中序遍历该结点的右子树。
void InOrderTraversal(BinTree BT)
{
  BinTree T=BT;
  Stack S = CreatStack(MaxSize);
  while(T || !IsEmpty(S))
  {
    while(T){
      Push(S,T);
      T=T->Left;
    }
    if(!IsEmpty(S))
    {
      T=Pop(S);
      printf("%5d",T->Data);
      T=T->Right;
    }
  }
}
层次遍历的基本过程：
  *先根结点入队，然后从队列中取出一个元素，访问该元素所指向的结点，若该元素所指结点的左、右孩子结点非空，则将其左、右孩子的指针顺序入队。
void LevelOrderTraversal(BinTree BT)
{
  Queue Q;
  BinTree T;
  if(!BT)
    return;
  Q = CreatQueue(MaxSize);
  AddQ(Q,BT);
  while(!IsEmpty(Q))
  {
    T=Delete(Q);
    printf("%d\n",T->Data);
    if(T->Left)
      AddQ(Q, T->Left);
    if(T->Right)
      AddQ(Q, T->Right);
  }
}
*/
void InorderTraversal(BinTree BT) {
  if (BT) {
    InorderTraversal(BT->Left);
    /* 此处假设对BT结点的访问就是打印数据 */
    printf("%d ", BT->Data); /* 假设数据为整型 */
    InorderTraversal(BT->Right);
  }
}

void PreorderTraversal(BinTree BT) {
  if (BT) {
    printf("%d ", BT->Data);
    PreorderTraversal(BT->Left);
    PreorderTraversal(BT->Right);
  }
}

void PostorderTraversal(BinTree BT) {
  if (BT) {
    PostorderTraversal(BT->Left);
    PostorderTraversal(BT->Right);
    printf("%d ", BT->Data);
  }
}

void LevelorderTraversal(BinTree BT) {
  Queue Q;
  BinTree T;

  if (!BT)
    return; /* 若是空树则直接返回 */

  Q = CreatQueue(); /* 创建空队列Q */
  AddQ(Q, BT);
  while (!IsEmpty(Q)) {
    T = DeleteQ(Q);
    printf("%d ", T->Data); /* 访问取出队列的结点 */
    if (T->Left)
      AddQ(Q, T->Left);
    if (T->Right)
      AddQ(Q, T->Right);
  }
}
