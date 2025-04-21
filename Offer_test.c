#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// Дана строка, состоящая из букв 'X', 'Y' и 'O'. Необходимо найти кратчайшее
// расстояние между буквами 'X' и 'Y', либо вывести 0, если 'X' либо 'Y'
// отсутствуют.

// "YY" -> 0
// "XX" -> 0
// "XY" -> 1
// "YOX" -> 2
// "XOOYOX" -> 2 // 5 - 3
// "OOOXXOY"-> 2
// "OOOYYOX"-> 2
// "YYYYY000000XY"-> 1

#define MAX_SIZE 100

size_t minDistance(const char *input)
{
    int index_X[MAX_SIZE];
    int index_Y[MAX_SIZE];
    int min_distance = 0;
    int count_X = 0;
    int count_Y = 0;
    int i = 0;
    int distance = 0;
    while (input[i] != '\0')
    {
        if (input[i] == 'X' && count_X < MAX_SIZE)
        {
            index_X[count_X] = i;
            count_X++;
        }
        else if (input[i] == 'Y' && count_Y < MAX_SIZE)
        {
            index_Y[count_Y] = i;
            count_Y++;
        }
        i++;
    }

    // Минимальное расстояние
    if (count_X == 0 || count_Y == 0) // Если один из символов X, Y не найден
    {
        min_distance = 0;
    }
    else
    {
        min_distance = abs(index_X[0] - index_Y[0]);
        for (int x = 0; x < count_X; x++)
        {

            for (int y = 0; y < count_Y; y++)
            {
                distance = abs(index_X[x] - index_Y[y]);

                if (distance < min_distance)
                {
                    min_distance = distance;
                }
            }
        }
    }

    return min_distance;
}

int main()
{
    printf("Test_1_min_distance =  %d\n", minDistance("YY"));
    printf("Test_2_min_distance =  %d\n", minDistance("XX"));
    printf("Test_3_min_distance =  %d\n", minDistance("XY"));
    printf("Test_4_min_distance =  %d\n", minDistance("YOX"));
    printf("Test_5_min_distance =  %d\n", minDistance("XOOYOX"));
    printf("Test_6_min_distance =  %d\n", minDistance("OOOXXOY"));
    printf("Test_7_min_distance =  %d\n", minDistance("OOOYYOX"));
    printf("Test_8_min_distance =  %d\n", minDistance("YYYYY000000XY"));

    return 0;
}