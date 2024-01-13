/*
Bài tâp Một hồ sơ sinh viên có 2 thông tin chính như sau
 • Name
 • Email
 • Hãy viết một chương trình chạy trên chế độ interactive với các lệnh sau:
 • Load <filename>: Nạp dữ liệu từ 1 file văn bản
 • Find <student_name>: Trả về hồ sơ của sinh viên có tên được nhập
 vào
 • Insert <student_name> <email>: Chèn một hồ sơ sinh viên mới vào
 cuối danh sách
 • Remove <student_name>: loại bỏ hồ sơ sinh viên
 • Store <filename>: Lưu trữ danh sách hồ sơ lên file văn bản
 • Quit: thoát khỏi chương trình
 • Yêu cầu: sử dụng bảng băm kết hợp cây nhị phân tìm kiếm, xử lý xung
 đột theo cơ chế nhóm chuỗi (chaining)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_L 256;
#define MAX 100000
#define M 100

typedef struct Node{
    char name[256];
    char email[256];
    struct Node* leftChild;
    struct Node* rightChild;
}Node;

Node* root[M];

//hash fuction
int hash(char* s){
    int rs = 0;     int n = strlen(s);
    for(int i =0; i < n; i++)       rs = (rs * 255 + s[i])%M;
    return rs;
}

Node* makeNode(char* _name, char* _email){
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->name, _name); strcpy(p->email, _email);
    p->leftChild = NULL; p->rightChild = NULL;
    return p;
}

Node* insert(Node* r, char* _name, char* _email){
    if(r == NULL) return makeNode(_name, _email);
    int c = strcmp(r->name, _name);
    if(c == 0){
        printf("Da co hoc sinh %s, khong thuc hien chen\n", _name); return r;
    }

    else if(c < 0){
        r->rightChild = insert(r->rightChild, _name, _email); return r;
    }

    else{
        r->leftChild = insert(r->leftChild, _name, _email);
    }
}

Node* find (Node* r, char* _name){
    if(r == NULL) return NULL;
    int c = strcmp(_name, r->name);
    if(c == 0) return r;
    if(c < 0) return find(r->rightChild, _name);
    return find(r->leftChild, _name);
}

Node* findMin(Node* r){
    if(r == NULL) return NULL;
    Node* lmin = findMin(r->leftChild);
    if(lmin != NULL) return lmin;
    return r;
}

Node* removeStudent(Node* r, char* _name){

    if(r == NULL) return NULL;
    int c = strcmp(r->name, _name);

    if(c > 0) r->leftChild = removeStudent(r->leftChild, _name);
    else if (c < 0) r->rightChild = removeStudent(r->rightChild, _name);

    else{

        if(r->leftChild != NULL && r->rightChild != NULL){
            Node* tmp = findMin(r->rightChild);
            strcpy(r->name, tmp->name); strcpy(r->email, tmp->email);
            r->rightChild = removeStudent(r->rightChild, _name);
        }

        else{
            Node* tmp = r;
            if(r->leftChild = NULL) r = r->rightChild; else r = r->leftChild;
            free(tmp);
        }
    }

    return r;
}

void freeTree(Node* r){
    if(r == NULL)return;
    freeTree(r->leftChild);     freeTree(r->rightChild);
    free(r);
}

void load(char* filename){
    FILE* f = fopen(filename, "r");
    if(f == NULL) printf("Lay du lieu tu file khong thanh cong, do khong tim thay file\n");
    for(int i = 0; i < M; i++) root[i] = NULL;
    while(!feof(f)){
        char _name[256], _email[256];
        fscanf(f, "%s %s", _name, _email);
        int idx= hash(_name);
        root[idx] = insert(root[idx], _name, _email);
    }
    fclose(f);
}

void inOrder(Node* r){
    if(r == NULL) return;
    inOrder(r->leftChild);
    printf("%s %s\n", r->name, r->email);
    inOrder(r->rightChild);
}

void inOrderF(Node* r, FILE* f){
    if(r == NULL)return;
    inOrderF(r->leftChild, f);
    fprintf(f, "%s %s\n",r->name, r->email);
    inOrderF(r->rightChild, f);
}

void printList(){
    for(int i = 0; i < M; i++)
        inOrder(root[i]);
    printf("\n");
}

void processLoad(){
    char filename[256];
    scanf("%s", filename);
    FILE* f = fopen(filename, "r");
    load(filename);
}

void processStore(){
    char filename[256];
    scanf("%s", filename);
    FILE* f = fopen(filename, "w");
    for(int i = 0; i < M; i++)
        inOrderF(root[i],f);
    fclose(f);
}

void processInsert(){
    char _name[256], _email[256];
    scanf("%s%s", _name, _email);
    int idx = hash(_name);
    root[idx] = insert(root[idx], _name, _email);
}

void processRemove(){
    char _name[256];
    scanf("%s", _name);
    int idx = hash(_name);
    root[idx] = removeStudent(root[idx], _name);
}

void processFind() {
    char name[256];
   scanf("%s", name);

    int index = hash(name); // calculate the hash value of the name
    Node* student = find(root[index], name); // find the student's record

    if (student != NULL) {
        printf("Name: %s, Email: %s\n", student->name, student->email); // print the student's record
    } else {
        printf("No student with the name %s found.\n", name); // print a message if the student's record is not found
    }
}

void main(){
    while(1){
        printf("Enter command: ");
        char cmd[256];
        scanf("%s", cmd);
        if(strcmp(cmd, "Quit") == 0) break;
        else if(strcmp(cmd, "Load") == 0) processLoad();
        else if(strcmp(cmd ,"Printf") == 0) printList();
        else if(strcmp(cmd ,"Find") == 0) processFind();
        else if(strcmp(cmd ,"Insert") == 0) processInsert();
        else if(strcmp(cmd ,"Remove") == 0) processRemove();
        else if(strcmp(cmd ,"Store") == 0) processStore();
        
    }

    for(int i = 0; i < M; i++)
        freeTree(root[i]);
}