#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>
struct node_
{
    int c;
    int e;
    struct node_* next;
};
typedef struct node_ NODE;
NODE* P[10001] = { NULL };

NODE* MakeNode(int c, int e)
{
    NODE* newNode = (NODE*)calloc(1, sizeof(NODE));
    newNode->c = c;
    newNode->e = e;
    newNode->next = NULL;
    return newNode;
}

void AddTerm(int id, int c, int e)
{
    NODE* newNode = MakeNode(c, e);
    NODE* tmp = P[id];
    NODE* prev = NULL;
    if (tmp == NULL)
    {
        P[id] = newNode;
    }else
    {
        while (tmp != NULL)
        {
            if (tmp->e <= e)
                break;
            else
            {
                prev = tmp;
                tmp = tmp->next;
            }
        }
        if (tmp == NULL)
        {
            prev->next = newNode;
        }else
        {
            if (tmp->e == e)
            {
                tmp->c += c;
            }else
            {
                newNode->next = tmp;
                if (prev != NULL)
                {
                    prev->next = newNode;
                }else{
                    P[id] = newNode;
                }
            }
        }
    }
}

int Eval(int id, int v)
{
    NODE* tmp = P[id];
    if (tmp == NULL)
        return 0;
    else
    {
        int result = 0;
        while (tmp != NULL)
        {
            result += tmp->c * pow(v, tmp->e);
            tmp = tmp->next;
        }
        return result;
    }
}

void Destroy(int id)
{
    NODE* tmp = P[id];
    NODE* next = NULL;
    while (tmp != NULL)
    {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    P[id] = NULL;
}

void AddPoly(int id1, int id2, int id3)
{
    Destroy(id3);
    NODE* tmp = P[id1];
    while (tmp != NULL)
    {
        AddTerm(id3, tmp->c, tmp->e);
        tmp = tmp->next;
    }
    tmp = P[id2];
    while (tmp != NULL)
    {
        AddTerm(id3, tmp->c, tmp->e);
        tmp = tmp->next;
    }
}

void PrintPoly(int id)
{
    NODE* tmp = P[id];
    while (tmp != NULL)
    {
        printf("%d %d ", tmp->c, tmp->e);
        tmp = tmp->next;
    }
    printf("\n");
}

int main()
{
    char command[32] = { 0 };

    while (0 == 0)
    {
        scanf("%s", command);
        if (strcmp(command,"Create") == 0)
        {
        }else if (strcmp(command,"AddTerm") == 0)
        {
            int id, c, e;
            scanf("%d%d%d",&id, &c, &e);
            AddTerm(id, c, e);
        }else if (strcmp(command,"EvaluatePoly") == 0)
        {
            int id, v;
            scanf("%d%d",&id, &v);
            printf("%d\n", Eval(id, v));    
        }else if (strcmp(command,"AddPoly") == 0)
        {
            int id1, id2, id3;
            scanf("%d%d%d",&id1, &id2, &id3);
            AddPoly(id1, id2, id3);
        }else if (strcmp(command,"PrintPoly") == 0)
        {
            int id;
            scanf("%d", &id);
            PrintPoly(id);
        }else if (strcmp(command,"Destroy") == 0)
        {
            int id;
            scanf("%d", &id);
            Destroy(id);
        }else
            break;       
    }
}
