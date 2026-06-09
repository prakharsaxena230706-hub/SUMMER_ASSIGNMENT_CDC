#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxArea(int* height, int heightSize){
    int low=0;
    int high=heightSize-1;
    int max_val=0;

    while(low<high){
        int current_height=MIN(height[low],height[high]);
        int current_width=high-low;
        max_val=MAX(max_val,current_height*current_width);

        if (height[low]<height[high]){
            low+=1;
        } 
        else{
            high-=1;
        }
    }
    return max_val;
}

int main(){
    int test_height[]={1,8,6,2,5,4,8,3,7};
    int size=sizeof(test_height)/sizeof(test_height[0]);

    int result=maxArea(test_height,size);
    printf("Container With Most Water - Maximum Area: %d\n", result);
    return 0;
}
