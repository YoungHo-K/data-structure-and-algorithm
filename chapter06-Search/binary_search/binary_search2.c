#include "point.h"


int comparePoint(const void *_elem1, const void *_elem2){
    Point* elem1 = (Point*)_elem1;
    Point* elem2 = (Point*)_elem2;

    if(elem1->point > elem2->point)
        return 1;
    else if(elem1->point < elem2->point)
        return -1;
    else
        return 0;
}

int main(void){
    int length = sizeof(dataset) / sizeof(dataset[0]);
    Point target;
    Point* found = NULL;

    qsort((void*)dataset, length, sizeof(Point), comparePoint);

    target.id = 0;
    target.point = 671.78;

    found = bsearch(
        (void*)&target,
        (void*)dataset,
        length,
        sizeof(Point),
        comparePoint
    );

    printf("Found... ID: %d, Point: %f\n", found->id, found->point);

    return 0;
}