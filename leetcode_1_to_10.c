#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// Задача 1: Two Sum
// https://leetcode.com/problems/two-sum/
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    static int result[2];
    for (uint32_t i = 0; i < numsSize - 1; i++)
    {
        for (uint32_t j = i + 1; j < numsSize; j++)
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
    *returnSize = 0; // Устанавливаем returnSize в 0, если решение не найдено
    return NULL;
}

// Функция для вывода массива
void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

// Функция для тестирования Two Sum
void testTwoSum()
{
    printf("=== Задача 1: Two Sum ===\n");

    // Пример 1
    int nums1[] = {2, 7, 11, 15};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int target1 = 9;
    int returnSize1;
    printf("Вход: nums = [");
    printArray(nums1, size1);
    printf("], target = %d\n", target1);
    int *result1 = twoSum(nums1, size1, target1, &returnSize1);
    if (returnSize1 == 2)
    {
        printf("Выход: [%d, %d]\n", result1[0], result1[1]);
    }
    else
    {
        printf("Решение не найдено\n");
    }

    // Пример 2
    int nums2[] = {3, 2, 4};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    int target2 = 6;
    int returnSize2;
    printf("\nВход: nums = [");
    printArray(nums2, size2);
    printf("], target = %d\n", target2);
    int *result2 = twoSum(nums2, size2, target2, &returnSize2);
    if (returnSize2 == 2)
    {
        printf("Выход: [%d, %d]\n", result2[0], result2[1]);
    }
    else
    {
        printf("Решение не найдено\n");
    }

    // Пример 3
    int nums3[] = {3, 3};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    int target3 = 6;
    int returnSize3;
    printf("\nВход: nums = [");
    printArray(nums3, size3);
    printf("], target = %d\n", target3);
    int *result3 = twoSum(nums3, size3, target3, &returnSize3);
    if (returnSize3 == 2)
    {
        printf("Выход: [%d, %d]\n", result3[0], result3[1]);
    }
    else
    {
        printf("Решение не найдено\n");
    }
    printf("\n");
}

// Задача 2: Add two numbers
// https://leetcode.com/problems/add-two-numbers/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode
{
    int val;
    struct ListNode *next;
};

// Функция для создания узла (для удобства тестирования)
struct ListNode *createNode(int val)
{
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Функция для создания списка из массива (для тестирования)
struct ListNode *createList(int *arr, int size)
{
    if (size == 0)
        return NULL;
    struct ListNode *head = createNode(arr[0]);
    struct ListNode *current = head;
    for (int i = 1; i < size; i++)
    {
        current->next = createNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Функция для вывода списка (для отладки и проверки)
void printList(struct ListNode *head)
{
    printf("[");
    while (head != NULL)
    {
        printf("%d", head->val);
        head = head->next;
        if (head != NULL)
            printf(",");
    }
    printf("]\n");
}

// Функция для освобождения памяти списка
void freeList(struct ListNode *head)
{
    struct ListNode *current = head;
    while (current != NULL)
    {
        struct ListNode *temp = current;
        current = current->next;
        free(temp);
    }
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *result = NULL;  // Указатель на начало результата
    struct ListNode *current = NULL; // Указатель для добавления узлов
    int carry = 0;                   // Перенос
    while (l1 != NULL || l2 != NULL || carry)
    {
        int sum = carry;
        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;     // Новый перенос
        int digit = sum % 10; // Цифра для текущего узла
        // Создание нового узла
        struct ListNode *newNode = malloc(sizeof(struct ListNode));
        newNode->val = digit;
        newNode->next = NULL;

        // Добавление узла в результат
        if (result == NULL)
        {
            result = newNode;
            current = newNode;
        }
        else
        {
            current->next = newNode;
            current = newNode;
        }
    }

    return result;
}

void test_addTwoNumbers()
{
    // Тест 1: l1 = [2,4,3], l2 = [5,6,4] → [7,0,8]
    printf("Тест 1:\n");
    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 4};
    struct ListNode *l1 = createList(arr1, 3);
    struct ListNode *l2 = createList(arr2, 3);
    printf("l1 = ");
    printList(l1);
    printf("l2 = ");
    printList(l2);
    struct ListNode *result = addTwoNumbers(l1, l2);
    printf("Результат = ");
    printList(result);
    freeList(l1);
    freeList(l2);
    freeList(result);

    // Тест 2: l1 = [0], l2 = [0] → [0]
    printf("\nТест 2:\n");
    int arr3[] = {0};
    int arr4[] = {0};
    l1 = createList(arr3, 1);
    l2 = createList(arr4, 1);
    printf("l1 = ");
    printList(l1);
    printf("l2 = ");
    printList(l2);
    result = addTwoNumbers(l1, l2);
    printf("Результат = ");
    printList(result);
    freeList(l1);
    freeList(l2);
    freeList(result);

    // Тест 3: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9] → [8,9,9,9,0,0,0,1]
    printf("\nТест 3:\n");
    int arr5[] = {9, 9, 9, 9, 9, 9, 9};
    int arr6[] = {9, 9, 9, 9};
    l1 = createList(arr5, 7);
    l2 = createList(arr6, 4);
    printf("l1 = ");
    printList(l1);
    printf("l2 = ");
    printList(l2);
    result = addTwoNumbers(l1, l2);
    printf("Результат = ");
    printList(result);
    freeList(l1);
    freeList(l2);
    freeList(result);
}

// Задача 3: Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

// Подход 1: Скользящее окно с флаговым массивом
int lengthOfLongestSubstring(char *s)
{
    // s = "abcabcbb"
    int max_substring = 0;

    char seen[256] = {0};
    int start = 0;
    int end = 0;
    if (s[0] == '\0')
    {
        max_substring = 0;
    }
    while (s[end] != '\0')
    {
        if (seen[s[end]] == 0)
        {
            seen[s[end]] = 1;
        }
        else
        {
            while (seen[s[end]])
            {
                seen[s[start]] = 0;
                start++;
            }
            seen[s[end]] = 1;
        }
        if ((end - start) + 1 > max_substring)
        {
            max_substring = (end - start) + 1;
        }
        printf("Window: %.*s, length=%d, max_substring=%d\n", end - start + 1, s + start, end - start + 1, max_substring);
        end++;
    }

    return max_substring;
}

// Подход 2: Скользящее окно с массивом последних позиций
int lengthOfLongestSubstring_another(char *s)
{
    // s = "abcabcbb"
    int max_substring = 0;

    int last_seen[256] = {0};
    int start = 0;
    int end = 0;
    if (s[0] == '\0')
    {
        max_substring = 0;
    }
    while (s[end] != '\0')
    {
        if (last_seen[s[end]] >= start)
        {
            start = last_seen[s[end]] + 1;
        }
        last_seen[s[end]] = end;
        if (end - start + 1 > max_substring)
        {
            max_substring = end - start + 1;
        }
        end++;
    }

    return max_substring;
}

// Задача 4: Median of Two Sorted Arrays
// https://leetcode.com/problems/median-of-two-sorted-arrays/description/
// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5
double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    double median = 0;
    printf("num1Size %d\n", nums1Size);
    printf("num2Size %d\n", nums2Size);
    int size_merged_array = nums1Size + nums2Size;
    printf("num2Size %d\n", size_merged_array);
    int merged_array[size_merged_array];
    return size_merged_array;
}

int main()
{
    // Тестирование всех задач
    // testTwoSum();                                                          // Task 1
    // test_addTwoNumbers();                                                  // Task 2
    // printf("Test_1 Task_3 =  %d\n", lengthOfLongestSubstring("abcabcbb")); // Task 3_Подход 1
    // printf("Test_1 Task_3 =  %d\n", lengthOfLongestSubstring_another("abcabcbb")); // Task 3_Подход 2
    int nums1[2] = {1,2}; 
    int nums2[2] = {3,4};
    printf("Test_1 Task_4 =  %d\n", findMedianSortedArrays(nums1, 2, nums2, 2)); // Task 3_Подход 2
    return 0;
}