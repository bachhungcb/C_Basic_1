
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
//-----------Sử dụng double linklist_Bien_cuc_bo-----//
// Thuật toán:
// Đưa trạng thái xuất phát vào hàng đợi
// Lặp :
//   Lấy 1 trạng thái ra khỏi hàng đợi,sinh ravà đưa các trạng thái lân cận vào hàng đợi 
//    nếu các trạng thái này chưa được sinh ra
// Thuật toán kết thúc khi đến trạng thái đích
typedef struct Node
{
    int row;
    int col;
    int step;//Số bước di chuyển từ trạng thái xuất phát đến trạng thái hiện tại
    struct Node* next;//con trỏ trỏ đến phần tử tiếp theo của hàng đợi
    struct Node* prev;//con trỏ trỏ đến trạng thái sinh ra trạng thái hiện tại
}Node;

Node *front = NULL;
Node *rear = NULL;
Node *listNode[MAX * MAX];//Mảng lưu các phần tử được cấp phát động để giải phóng bộ nhớ
// Mối listNode[n] = Địa chỉ
int szList = 0;//So phan tu cua listNode
int A[MAX][MAX];
int n,m;//Biến cục bộ
int r0,c0;//Biến cục bộ
int r1,c1;
int visited[MAX][MAX];//visited = 0 nếu chưa đi qua, = 1 nếu đi qua rồi

const int dr[4]={1,-1,0,0};//
const int dc[4]={0,0,1,-1};
Node* finalNode;
//---- Giai phóng bộ nhớ---------//
void finalize(){
    for(int i = 0; i < szList; i++){
        free(listNode[i]);
    }
}
void addList(Node* node){// them phan tu vao listNode de thuc hien giai phong bo nho
listNode[szList] = node;
szList++;
}
//-----------------------------------

//----------Đọc dữ liệu vào---------
void input()
{
    scanf("%d%d%d%d",&n,&m,&r0,&c0);
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
    scanf("%d",&A[i][j]);
}
//------------------------------------
Node* makeNode(int row, int col, int step, Node* prev){
        Node* node = (Node*)malloc(sizeof(Node));
        node->row = row; 
        node->col = col; 
        node->next = NULL;
        node->prev = prev; 
        node->step = step;
        return node;
}
int IsEmpty()
{
    if(front == NULL && rear == NULL)
    return 1;
    else 
    return 0;
}
void Enqueue(Node* node)
{
    if(IsEmpty())
    {
        front = rear = node;
        return;
    }
    else{
    rear->next = node;
    rear = node;
}
}
void Dequeue()//vừa xoá vừa lấy
{
    Node* tmp = front;
    if(IsEmpty())
    {
        return;
    }
    if(front == rear)
    {
        front = rear = NULL;
        free(tmp);
    }
    else{
    front = tmp->next;
    free(tmp);
    }
}
Node* Topqueue()
{
    return front;
}

int main()
{
        input();
       for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        visited[i][j] = 0;
        Node* start = makeNode(r0,c0,0,NULL);
        addList(start);
        Enqueue(start);
        visited[r0][c0] = 1;
        //Duyet chieu rong
        while(IsEmpty() != 0)
        {
                Node* tmp = Topqueue();
                if(tmp->row < 1 || tmp->row > n || tmp->col < 1 || tmp->col > m)
                {
                        finalNode = tmp;
                        break;
                }
                for(int k = 0; k < 4; k++)
                {
                        int next_c = tmp->col + dc[k];
                        int next_r = tmp->row + dr[k];
                    if(A[next_r][next_c] == 0 && visited[next_r][next_c] == 0)
                    {
                        visited[next_r][next_c] = 1;
                        Node* newNode = makeNode(next_r,next_c,tmp->step + 1, tmp);
                        addList(newNode);
                        Enqueue(newNode);
                    }
                }
                Dequeue();
        }
        printf("%d", finalNode->step);
        finalize();
        
    
}