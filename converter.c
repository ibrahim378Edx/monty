#include <stdlib.h>

char *gint(int num);
unsigned int abscon(int);
int getlen(unsigned int num, unsigned int base);
void fillbuff(unsigned int num, unsigned int base, char *buff, int buff_size);

/**
 * gint - pointer to new string
 *
 * @num: number to convert
 *
 * Return: return pointer to string
 */
char *gint(int num)
{
unsigned int temp;
int l = 0;
long nl = 0;
char *r;

temp = abscon(num);
l = getlen(temp, 10);

if (num < 0 || nl < 0)
{
l++;
}
r = malloc(l + 1); /* create new string */
if (!r)
{
return (NULL);
}
fillbuff(temp, 10, r, l);
if (num < 0 || nl < 0)
{
r[0] = '-';
}
return (r);
}

/**
 * abscon - gets abs value of number
 *
 * @i: integer to get absolute value of
 *
 * Return: number after conversion
 */
unsigned int abscon(int i)
{
if (i < 0)
{
return (-(unsigned int)i);
}
return ((unsigned int)i);
}

/**
 * getlen - gets length of buffer
 *
 * @num: number to get length
 *
 * @base: base of number
 *
 * Return: returning length of buffer needed
 */
int getlen(unsigned int num, unsigned int base)
{
int l = 1;

while (num > base - 1)
{
l++;
num /= base;
}
return (l);
}

/**
 * fillbuff - convert to base 36
 *
 * @num: number to convert
 *
 * @base: base number
 *
 * @buff: buffer to fillS
 *
 * @buff_size: size of buffer in bytes
 *
 * Return: nothing
 */
void fillbuff(unsigned int num, unsigned int base, char *buff, int buff_size)
{
int r, i = buff_size - 1;

buff[buff_size] = '\0';
while (i >= 0)
{
r = num % base;
if (r > 9)
{
buff[i] = r + 87;
}
else
{
buff[i] = r + '0';
}
num /= base;
i--;
}
}
