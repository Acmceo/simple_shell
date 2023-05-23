nclude <stdio.h>
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
 *  * bfree - Frees a pointer and NULLs the address.
 *   * @ptr: Address of the pointer to free.
 *    *
 *     * Return: 1 if freed, otherwise 0.
 *      */
int bfree(void **ptr)
{
		if (ptr && *ptr)
				{
							free(*ptr);
									*ptr = NULL;
											return (1);
												}
			return (0);
}

