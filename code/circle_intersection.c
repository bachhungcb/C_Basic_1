#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point{
    double x;
    double y;
}point_t;

typedef struct circle{
    point_t center;
    double radius;
}circle_t;

int circle_intersection(circle_t *c1, circle_t *c2){
    double x_dist, y_dist, distance;
    x_dist = fabs(c1 -> center.x - c2->center.x);
    y_dist = fabs(c1->center.y - c2->center.y);
    distance = sqrt(x_dist * x_dist + y_dist * y_dist);
    if(distance < fabs(c1->radius - c2->radius)){
        return 1;
    }

    if(distance > c1->radius + c2->radius){
        return 1;
    }

    if (distance == fabs(c1->radius - c2->radius))
    {
        return 0;
    }

    if (distance == c1->radius + c2->radius)
    {
        return 0;
    }
    
}

int main(){
    circle_t c1, c2;
    printf("Nhap vao toa do tam cua duong tron 1: \n");
    printf("x: "); scanf("%lf", &c1.center.x);
    printf("y: "); scanf("%lf", &c1.center.y);

    printf("Nhap vao ban kinh cua duong tron 1: ");
    scanf("%lf", &c1.radius);

    printf("Nhap vao toa do tam cua duong tron 2: \n");
    printf("x: "); scanf("%lf", &c2.center.x);
    printf("y: "); scanf("%lf", &c2.center.y);

    printf("Nhap vao ban kinh cua duong tron 2: ");
    scanf("%lf", &c2.radius);

    if (circle_intersection(&c1, &c2) == 0)
    {
        printf("Hai duong tron giao nhau");
    }else printf("Hai duong trong KHONG giao nhau");
    
    return 0;
}