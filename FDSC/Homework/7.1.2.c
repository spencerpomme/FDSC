// excercise 7.1.2 on P206
#include <stdio.h>
#define SIZE 5
typedef struct {
    int key;
    // any other possible fields
} element;

int movesearch(element list[], int len, int target);
void showlist(element *list, int len);

int main(void)
{
    element list[SIZE] = {{5},{3},{2},{6},{1}};
    printf("first element before search: %d\n", list[0].key);
    showlist(list, 5);
    movesort(list, 5, 6);
    printf("first element after search: %d\n", list[0].key);
    showlist(list, 5);

    return 0;
}

int movesearch(element list[], int len, int target)
{
    int temp;
    for (int i = 0; i < len; i++)
        if (list[i].key == target)
        {
            for (int j = i; j > 0; j--)
                list[j] = list[j-1];
            list[0].key = target;
            return i;
        }
    printf("%d is not in list.\n", target);
    return -1;
}

void showlist(element *list, int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", list[i]);
}