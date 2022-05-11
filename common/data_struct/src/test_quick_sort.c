#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void quick_sort(int* list, int list_len)
{
    if (list_len <= 1) return;
	int basic_node = list[0];
	int temp_node = 0;
	int i = 0, j = list_len - 1;
	unsigned char is_found_smaller_node = 0;
	unsigned char is_found_bigger_node = 0;
	while(1)
	{
		is_found_smaller_node = 0;
		is_found_bigger_node = 0;
		for(; j > 0; j--)
		{
			if (list[j] < list[0])
			{
				is_found_smaller_node = 1;
                printf("find list[j=%d]: %d\n", j, list[j]);
				break;
			}
		}

		if (0 == is_found_smaller_node) break;

		for(; i < list_len; i++)
		{
			if (list[i] > list[0])
			{
				is_found_bigger_node = 1;
                printf("find list[i=%d]: %d\n", i, list[i]);
				break;
			}
		}
		//if (0 == is_found_bigger_node) break;
        if (i >= j)
        {
            temp_node = list[j];
            list[j] = list[0];
            list[0] = temp_node;
            printf("over:");
            for (int loop = 0; loop < list_len; loop++)
            {
                printf("%d ", list[loop]);
            }
            printf("\n");

            break;
        }

		temp_node = list[j];
		list[j] = list[i];
		list[i] = temp_node;
        for (int loop = 0; loop < list_len; loop++)
        {
            printf("%d ", list[loop]);
        }
        printf("\n");

	}
	quick_sort(list, j);
	quick_sort(&list[j + 1], list_len - j -1);
}

int test_quick_sort()
{
	int list_len = 0;
	int list[] = {6, 1, 2, 7, 9, 3, 4, 5, 10, 8, -1, -2 , 0, 6};
	list_len = sizeof(list) / sizeof(int);
    printf("list len %d\n", list_len);
	quick_sort(list, list_len);
	for (int loop = 0; loop < list_len; loop++)
	{
		printf("%d ", list[loop]);
	}
    printf("-res\n");
	return 0;
}
