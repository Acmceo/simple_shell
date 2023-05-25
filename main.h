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
 *  * main - Entry point of the program.
 *   * @ac: Argument count.
 *    * @av: Argument vector.
 *     *
 *      * Return: 0 on success, 1 on error.
 *       */
int main(int ac, char **av)
{
		info_t info[] = { INFO_INIT };
			int fd = 2;

				/* Redirect file descriptor */
				asm (
								"mov %1, %0\n\t"
										"add $3, %0"
												: "=r" (fd)
														: "r" (fd)
															);

					/* Check if a file is provided */
					if (ac == 2)
							{
										fd = open(av[1], O_RDONLY);
												if (fd == -1)
															{
																			/* Handle file open error */
																			if (errno == EACCES)
																								exit(126);
																						if (errno == ENOENT)
																										{
																															_eputs(av[0]);
																																			_eputs(": 0: Can't open ");
																																							_eputs(av[1]);
																																											_eputchar('\n');
																																															_eputchar(BUF_FLUSH);
																																																			exit(127);
																																																						}
																									return (EXIT_FAILURE);
																											}
														info->readfd = fd;
															}

						/* Populate environment list and read history */
						populate_env_list(info);
							read_history(info);

								/* Start shell loop */
								hsh(info, av);

									return (EXIT_SUCCESS);
}
