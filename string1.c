#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include "shell.h"

/**
 *_strcpy - Copies a string.
 *@dest: The destination string.
 *@src: The source string to be copied.
 *Returns: A pointer to the destination string.
 */
char *_strcpy(char *dest, char *src)
{
int i = 0;

if (dest == src || src == NULL)
return (dest);

while (src[i] != '\0')
{
dest[i] = src[i];
i++;
}
dest[i] = '\0';
return (dest);

 *stdrup- Duplicates a string.
 *@str: The string to be duplicated.
 *Returns: A pointer to the duplicated string.
 */
char *_strdup(const char *str)
{
int length = 0;
char *ret;

if (str == NULL)
return(NULL);

while (str[length] != '\0')
length++;

ret = malloc(sizeof(char) * (length + 1));
if (ret == NULL)
return (NULL);

for (length = 0; str[length] != '\0'; length++)
ret[length] = str[length];
ret[length] = '\0';

return (ret);
}

/**
 *puts - Prints a string.
 *@str: The string to be printed.
 *does not return a value.
 */
void _puts(char *str)
{
int i = 0;

if (str == NULL)
return;

while (str[i] != '\0')
{
_putchar(str[i]);
i++;
}
}

/**
 *putchar - Writes a character to the standard output.
 *@c: The character to be printed.
 *Returns: On success, 1. On error, -1 is returned, and `errno` is set appropriately.
 */
int _putchar(char c)
{
static int i = 0;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(1, buf, i);
i = 0;
}

if (c != BUF_FLUSH)
buf[i++] = c;

return (1)
}

