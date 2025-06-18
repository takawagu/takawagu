/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:29:39 by gicomlan          #+#    #+#             */
/*   Updated: 2025/06/11 16:25:03 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_search_and_replace(char *string, char search, char replace)
{
	while (*string)
	{
		if (*string == search)
			ft_putchar_fd(replace);
		else
			ft_putchar_fd(*string);
		string++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		if (argv[2][1] == '\0' && argv[3][1] == '\0')
			ft_search_and_replace(argv[1], argv[2][0], argv[3][0]);
	}
	return (0);
}

// #include <unistd.h> // For write
// #include <stdlib.h> // For exit && EXIT_SUCCESS
//
// void	ft_putchar(char c)
// {
// 	write(STDOUT_FILENO, &c, sizeof(char));
// }
//
// void	search_and_replace(char *string, char search, char replace)
// {
// 	int	index;
//
// 	index = 0;
// 	while (string[index] != '\0')
// 	{
// 		if (string[index] == search)
// 			ft_putchar(replace);
// 		else
// 			ft_putchar(string[index]);
// 		index++;
// 	}
// }
//
// int	main(int argc, char **argv)
// {
// 	if (argc == 4)
// 		if (argv[2][1] == '\0' && argv[3][1] == '\0')
// 			search_and_replace(argv[1], argv[2][0], argv[3][0]);
// 	return (EXIT_SUCCESS);
// }
