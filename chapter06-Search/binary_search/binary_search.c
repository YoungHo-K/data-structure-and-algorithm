#include "point.h"


Point* binarySearch(Point point_list[], int size, double target){
    int left, right, mid;

    left = 0;
    right = size - 1;

    while(left <= right){
        mid = (left + right) / 2;

        if(target == point_list[mid].point)
            return &(point_list[mid]);
        else if (target < point_list[mid].point)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return NULL;
}

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
    Point* found = NULL;

    qsort((void*)dataset, length, sizeof(Point), comparePoint);

    found = binarySearch(dataset, length, 671.78);
    printf("Found... ID: %d, Point: %f\n", found->id, found->point);

    return 0;
}