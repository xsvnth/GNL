/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eoftest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmelamr <ahmelamr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 20:38:17 by ahmelamr          #+#    #+#             */
/*   Updated: 2026/11/23 21:06:57 by ahmelamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	FILE	*file;
	int		c;

	file = fopen("eof.txt", "r");
	c = fgetc(file);
	if (c == EOF)
		write(1, "EOF\n", 4);
	fclose(file);
}
