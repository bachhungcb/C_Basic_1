#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct  Node
{
    int data;
    struct Node* leftMostChild;
    struct Node* rightSibling;
}Node;

Node* GetNewNode(int data)
{
    Node* tmp = (Node*)malloc(sizeof(Node));
    if(tmp!=NULL)
    {
    tmp->data = data;
    tmp->leftMostChild = NULL;
    tmp->rightSibling = NULL;
    }
    return tmp;
}
Node* addSibling(Node* root,int data)
{
    if(root == NULL)
    {
        root = GetNewNode(data);
        return root;
    }
    root->rightSibling = addSibling(root->rightSibling,data);
    return root;
}
// u la con cua v
Node* Find(Node* root, int data)
{
    if(root == NULL)
        return NULL;
    if(root->data == data) 
        return root;
    //Tim kiem cac con cua cay tong quat
    Node* tmp = root->leftMostChild;
    while (tmp!=NULL)
    {
        Node* res = Find(tmp,data);
        if(res != NULL) // nếu có tìm thấy ở cây con thì trả về giá trị đó
            return res;
        tmp = tmp->rightSibling;
    }
    return NULL; // nếu không tìm thấy ở một cây con nào, trả về NULL
}
// u là con cua v
void addChild(Node* root, int u,int v)
{
    if(root == NULL)
    {
        return ;
    }
    Node* tmp = Find(root,v);
    if(tmp!=NULL)
    {
    tmp->leftMostChild = addSibling(tmp->leftMostChild,u);
    }
}
void InOrder(Node* root);
void PreOrder(Node* root);
void PostOrder(Node* root);
int main()
{
    Node* root = NULL;
    char s[50];
    while (1)
    {
        
        scanf("%s", s);
        getchar();
        if(strcmp(s,"*") == 0) break;
        else if(strcmp(s,"MakeRoot") == 0)
        {
            int u;
            scanf("%d", &u);
            root = GetNewNode(u);
        }
        else if(strcmp(s,"Insert") == 0)
        {
            int u,v;
            scanf("%d%d", &u, &v);
            addChild(root,u,v);
        }
        else if(strcmp(s,"InOrder") == 0)
        {
            
            InOrder(root);
            printf("\n");
           
        }
        else if(strcmp(s,"PreOrder") == 0)
        {
            PreOrder(root);
             printf("\n");
        }
        else if(strcmp(s,"PostOrder") == 0)
        {
            PostOrder(root);
             printf("\n");
        }
    }
}
//DFS(u):
//preorder <- u
//for v in children(u): // tham tat ca cac con cua u
//DFS(v)
//Ta sẽ bắt đầu từ đỉnh gốc, mỗi đỉnh được đánh dấu đã đi qua khi được cho vào stack lần đầu(stack ở
// đây nghĩa là hàm DFS)
void PreOrder(Node* root)
{
    
    if(root == NULL) return;
    printf("%d ", root->data);
    Node* tmp = root->leftMostChild;
    while (tmp!=NULL){
    PreOrder(tmp);
    tmp = tmp->rightSibling;
    }
    //Ham While tren chi la cach viet khac cua vong for khi muon tham tat ca cac con cua root
       
}
//  DFS(u):
  //for v in children(u):
  //DFS(v)
  //postorder <- u
  //Một đỉnh được coi là đã thăm ngay khi tất cả các con của nó được thăm(Các đỉnh lá được đánh dấu
  // đã thăm ngay khi được đưa vào stack)
void PostOrder(Node* root)
{
    if(root == NULL) return;
  //Tham tất cả các con 
  Node* tmp = root->leftMostChild;
  while(tmp!=NULL){ 
    PostOrder(tmp);
    tmp = tmp->rightSibling;
  }
  printf("%d ", root->data);
}
//Một đỉnh đƯợc coi là đã thăm sau khi tất cả các đỉnh thuộc cây con trái được thăm
//Trước bất kì đỉnh nào của cây con phải được thăm
void InOrder(Node* root)
{
    if(root == NULL) return;
    Node* tmp = root->leftMostChild;
    if(tmp == NULL)//Neu khong co con 
    {
        printf("%d ", root->data);
    }
    else //Neu co con
    {
        InOrder(tmp);//Thăm con trưởng
        printf("%d ",root->data);//Tham nut goc
        tmp = tmp->rightSibling;//Sau khi thăm nut goc  song cập nhật thành con thứ
    while (tmp!=NULL)
    {
        InOrder(tmp);
        tmp = tmp->rightSibling;
    }
    }
    
}