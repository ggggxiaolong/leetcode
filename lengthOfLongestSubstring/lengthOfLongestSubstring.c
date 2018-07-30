#include <stdio.h>
#include <malloc.h>
#include <string.h>

void emptyOld(int *map, char *s, int start, int end, char flag)
{
    while (start < end)
    {
        map[s[start] - flag] = 0;
        start ++;
    }
    map[s[end] - flag] = 1;
}

int lengthOfLongestSubstring(char *s)
{
    char max = s[0], min = s[0];
    int size = strlen(s), i = 0, length = 1;
    if(size == 0) return 0;
    while (++i < size)
    {
        if (s[i] < min)
        {
            min = s[i];
            continue;
        }
        if (s[i] > max)
        {
            max = s[i];
        }
    }
    int *map = (int *)malloc((max - min + 1) * sizeof(int));
    int start = 0, index = 1, mapIndex = s[0] - min;
    map[mapIndex] = 1;
    while (index < size)
    {
        mapIndex = s[index] - min;
        if (map[mapIndex] == 1)
        {
            int charSize = index - start;
            if (charSize > length)
            {
                length = charSize;
            }
            emptyOld(map, s, start, index, min);
            start = index;
        } else {
            map[mapIndex] = 1;
        }
        index++;
    }
    int charSize = size - start;
            if (charSize > length)
            {
                length = charSize;
            }
    free(map);
    return length;
}

int main()
{
    printf("%d\n",lengthOfLongestSubstring("abcabcbb"));
    printf("%d\n",lengthOfLongestSubstring("bbbbb"));
    printf("%d\n",lengthOfLongestSubstring(""));
    printf("%d",lengthOfLongestSubstring("dyig"));
}