#include <stdio.h>


/*If you want you can implement the compare function inside the cbsearch  
Which i already included in the arguments of the cbsearch*/
int compar(int a , int b){
    if(a == b) return 0;
    if (a<b) return -1
    if (a>b) return 1;
}

/*Ik it the weired thing i came up with
Bascially there is a index var which is initalized to size/2 and it will half itself in every iteration
To track of the current index i used t_idx 

As per we know bsearch can be done only in sorted array so it must in ascending order
frist we set t_index to the index which is size/2
Let's walks through the example if array size = 100
index will be 100/2 = 50
so t_idex = 50

after entering the loop we half the index, it will be 25 but t_idx is 50
if element is less than arr[t_idx] so that mean the index of the target will be less than t_idx;
  so we decrease the t_idx with the current index which is 25 so it t_idx will be 50-25 = 25
else element is greater than arr[t_idx]
  so we increase t_idx with current index it will be 75

so we do this thing again and again until we found the element or the index become 0;

If index become 0 i just look the adjacent element of the t_idx and check if they are the targert.
if yea return it else return a -ve number

Ik after doing all of these i didn't cover and check all the of element in the array where there is a chance the element might be.

yeah it sometimes return -ve number even the element is in the array. It's beacuse it couldn't reach (lol). 

replace it in main, we know 997 will be in the array but it will return -ve number

    int arr[1000];
    int num = 997;
    for (int i = 0;i<1000;i++){
        arr[i] = i;
    }
    int index = cbsearch(arr, num, 1000, compar);
    printf("\nindex : %d", index);
    if(index < 0){
        printf("\nElement not found");
        return 0;
    }
    if(arr[index] == num){
        printf("\n vola we got it");
    }
    printf("\n num : %d", arr[index]);

*/

int cbsearch(int arr[],int x,int size, int (*compar)(int a,int b)){
    int index = size/2;
    int t_idx = index;
    int result = -3; // to contiue the loop for initial state
    while(result  != 0){
        index = index/2;
        if(arr[t_idx] ==x) return t_idx;
        if (arr[t_idx] < x){
            t_idx += index;
        }else if(arr[t_idx] > x){
            t_idx -= index;
        }
        if (index == 0){
          goto end;

        }
        printf("\nindex: %d  corres  : %d", t_idx, index);
    }
    end:
        if (t_idx > 0 && arr[t_idx - 1] == x) return t_idx - 1;
        if (t_idx < size - 1 && arr[t_idx + 1] == x) return t_idx + 1;
        return -2;

}

int main() {
    int arr[1000];
    int num = 986;
    for (int i = 0;i<1000;i++){
        arr[i] = i;
    }
    int index = cbsearch(arr, num, 1000, compar);
    printf("\nindex : %d", index);
    if(index < 0){
        printf("\nElement not found");
        return 0;
    }
    if(arr[index] == num){
        printf("\n vola we got it");
    }
    printf("\n num : %d", arr[index]);
    
    return 0;
}

