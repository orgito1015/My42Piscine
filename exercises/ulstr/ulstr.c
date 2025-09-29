/* ************************************************************************** */
/*                                                                            */
/*                 ulstr.c for ulstr                                          */
/*                 Created on : Tue Jan 21 13:39:34 2014                      */
/*                 Made by : David "Thor" GIRON <thor@42.fr>                  */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>


void	ulstr( char * s ) {

	while( *s ) {

		if ( *s >= 'A' && *s <= 'Z' )
			*s += 32;
		else if ( *s >= 'a' && *s <= 'z' )
			*s -= 32;
		write( 1, s, 1 );
		++s;
	}

	return;
}


int		main( int ac, char **av ) {

	if ( ac == 2 )
		ulstr( av[1] );

	write( 1 ,"\n", 1 );

	return 0;
}
