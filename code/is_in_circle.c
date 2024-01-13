#include <stdio.h>
#include <stdlib.h>

typedef struct point{
    double x;
    double y;
}point_t;

typedef struct circle{
    point_t center;
    double radius;  //半径
}circle_t;

int is_in_circle(point_t *p, circle_t *c){
    double x_dist, y_dist;
    x_dist = p->x - c->center.x;
    y_dist = p->y - c->center.y;
    return (x_dist * x_dist + y_dist * y_dist < c->radius * c->radius);
}

int main(){
    point_t p;
    circle_t c;

    printf("Nhap vao toa do cua diem: \n");
    printf("x: "); scanf("%lf", &p.x);
    printf("y: "); scanf("%lf", &p.y);

    printf("Nhap vao toa do tam cua duong tron: \n");
    printf("x: "); scanf("%lf", &c.center.x);
    printf("y: "); scanf("%lf", &c.center.y);

    printf("Nhap vao duong kinh cua duong tron: ");
    scanf("%lf", &c.radius);

    if(is_in_circle(&p, &c)) printf("Diem nam trong duong tron");
    else printf("Diem KHONG nam trong duong tron");

    return 0;
}