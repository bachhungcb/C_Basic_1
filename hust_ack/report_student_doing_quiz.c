#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char date[256];
    char time[256];
    char student_id[256];
    char question[256];
    struct *Node next;
}