#include <stdio.h>
#include <ctype.h>
int word_count(const char s[])
{
    int count = 0, inside = 0, i;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') inside = 0;
        else if (!inside) { count++; inside = 1; }
    }
    return count;
}
int is_palindrome(const char s[])
{
    int left = 0, right = 0;
    while (s[right] != '\0') right++;
    right--;
    while (left < right) {
        while (left < right && !isalpha((unsigned char)s[left])) left++;
        while (left < right && !isalpha((unsigned char)s[right])) right--;
        if (tolower((unsigned char)s[left]) != tolower((unsigned char)s[right])) return 0;
        left++;
        right--;
    }
    return 1;
}
int main(void)
{
    printf("Words: %d\n", word_count(" Meet at the library at 5 PM "));
    printf("%d %d\n", is_palindrome("Madam, I'm Adam"), is_palindrome("Hello"));
    printf("Tab test words: %d\n", word_count("Hi\tthere"));
    return 0;
}
