/* ************************************************************************** */
/*                                                                            */
/*                 hello_world.c for hello_world                              */
/*                 Created on : Tue Jul 23 16:32:17 2013                      */
/*                 Made by : David "Thor" GIRON <thor@42.fr>                  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main() {

	write(1, "Hello World!\n", 13);
	return 0;
}

