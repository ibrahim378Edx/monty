
#include <stdlib.h>

char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);

/**
 * strtow - takes a string and seperates its words
 *
 * @str: string
 *
 * @delims: delimitors
 *
 * Return: 2D array
 */

char **strtow(char *str, char *delims)
{
char **letters = NULL;
int wc, wordLen, n, i = 0;

if (str == NULL || !*str)
{
return (NULL);
}
wc = get_word_count(str, delims);

if (wc == 0)
{
return (NULL);
}
letters = malloc((wc + 1) * sizeof(char *));
if (letters == NULL)
{
return (NULL);
}
while (i < wc)
{
wordLen = get_word_length(str, delims);
if (is_delim(*str, delims))
{
str = get_next_word(str, delims);
}
letters[i] = malloc((wordLen + 1) * sizeof(char));
if (letters[i] == NULL)
{
while (i >= 0)
{
i--;
free(letters[i]);
}
free(letters);
return (NULL);
}
n = 0;
while (n < wordLen)
{
letters[i][n] = *(str + n);
n++;
}
letters[i][n] = '\0';
str = get_next_word(str, delims);
i++;
}
letters[i] = NULL;
return (letters);
}

/**
 * is_delim - checks for delimiter
 *
 * @ch: character
 *
 * @delims: Pointer to array
 *
 * Return: 1 on success 0 on fail
 */

int is_delim(char ch, char *delims)
{
int i = 0;
while (delims[i])
{
if (delims[i] == ch)
{
return (1);
}
i++;
}
return (0);
}

/**
 * get_word_length - get word length
 *
 * @str: string
 *
 * @delims: delimitors
 *
 * Return: word length
 */

int get_word_length(char *str, char *delims)
{
int len = 0, z = 1, i = 0;
while (*(str + i))
{
if (is_delim(str[i], delims))
{
z = 1;
}
else if (z)
{
len++;
}
if (len > 0 && is_delim(str[i], delims))
{
break;
}
i++;
}
return (len);
}

/**
 * get_word_count - word counter
 *
 * @str: string
 *
 * @delims: delimitors
 *
 * Return: the word count of the string
 */

int get_word_count(char *str, char *delims)
{
int count = 0, z = 1, i = 0;

while (*(str + i))
{
if (is_delim(str[i], delims))
{
z = 1;
}
else if (z)
{
z = 0;
count++;
}
i++;
}
return (count);
}

/**
 * get_next_word - gets the next word in a string
 *
 * @str: string
 *
 * @delims: delimitors
 *
 * Return: pointer to next word
 */

char *get_next_word(char *str, char *delims)
{
int z = 0;
int i = 0;

while (*(str + i))
{
if (is_delim(str[i], delims))
{
z = 1;
}
else if (z)
{
break;
}
i++;
}
return (str + i);
}
