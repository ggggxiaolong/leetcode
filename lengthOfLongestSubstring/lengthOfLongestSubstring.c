#include <stdio.h>
#include <malloc.h>
#include <string.h>

void emptyOld(int *map, char *s, int start, int end, char flag)
{
    while (start < end)
    {
        map[s[start] - flag] = 0;
        start++;
    }
    map[s[end] - flag] = end + 1;
}

int lengthOfLongestSubstring(char *s)
{
    char max = s[0], min = s[0];
    int size = strlen(s), i = 0, length = 1;
    if (size < 2)
        return size;
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
        if (map[mapIndex])
        {
            int charSize = index - start;
            if (charSize > length)
            {
                length = charSize;
            }
            int old = start;
            start = map[mapIndex];
            emptyOld(map, s, old, start, min);
        }
        else
        {
            map[mapIndex] = index + 1;
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
    printf("%d\n", lengthOfLongestSubstring("abcabcbb") == 3);
    printf("%d\n", lengthOfLongestSubstring("bbbbb") == 1);
    printf("%d\n", lengthOfLongestSubstring("") == 0);
    printf("%d\n", lengthOfLongestSubstring("pwwkew") == 3);
    printf("%d\n", lengthOfLongestSubstring("dyig") == 4);
    printf("%d", lengthOfLongestSubstring("abcadefg") == 7);
}