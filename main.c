#include <stdio.h>
#include <stdint.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    static int result[2];
    for (uint32_t i = 0U; i < (numsSize - 1); i++)
    {
        for (uint32_t j = i + 1U; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    return NULL;
}

int main()
{
    int nums[] = {2, 7, 11, 15};
    int size = sizeof(nums) / sizeof(nums[0]); // Размер массива
    int target = 9;
    int returnSize;
    for (int i = 0; i < size; i++)
    {
        printf("%d ", nums[i]); // Вывод каждого элемента
    }
    int *result = twoSum(nums, size, target, &returnSize);

    if (returnSize == 2)
    {
        printf("Индексы: [%d, %d]\n", result[0], result[1]);
    }
    else
    {
        printf("Решение не найдено\n");
    }

    int nums_1[] = {3, 2, 4};
    int size_1 = sizeof(nums_1) / sizeof(nums_1[0]); // Размер массива
    int target_1 = 6;

    for (int i = 0; i < size_1; i++)
    {
        printf("%d ", nums_1[i]); // Вывод каждого элемента
    }
    int *result_1 = twoSum(nums_1, size_1, target_1, &returnSize);

    if (returnSize == 2)
    {
        printf("Индексы: [%d, %d]\n", result_1[0], result_1[1]);
    }
    else
    {
        printf("Решение не найдено\n");
    }

    int nums_2[] = {3, 3};
    int size_2 = sizeof(nums_2) / sizeof(nums_2[0]); // Размер массива
    int target_2 = 6;

    for (int i = 0; i < size_2; i++)
    {
        printf("%d ", nums_2[i]); // Вывод каждого элемента
    }
    int *result_2 = twoSum(nums_2, size_2, target_2, &returnSize);

    if (returnSize == 2)
    {
        printf("Индексы: [%d, %d]\n", result_2[0], result_2[1]);
    }
    else
    {
        printf("Решение не найдено\n");
    }

    return 0;
}