/* ************************************************************************** */
/*                                                                            */
/*                 wdmatch.c for wdmatch                                      */
/*                 Created on : Tue Jan 21 13:58:14 2014                      */
/*                 Made by : David "Thor" GIRON <thor@42.fr>                  */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>


void	wdmatch( char * s1, char * s2 ) {

	int		i = 0;
	int		j = 0;

	while ( s1[i] && s2[j] ){

		if ( s1[i] == s2[j] )
			++i;
		++j;
	}

	if ( s1[i] == '\0' ) {
		for ( i=0; s1[i]; ++i )
			write( 1 , &s1[i], 1 );
	}

	return;
}


int		main( int ac, char **av ) {

	if ( ac == 3 )
		wdmatch( av[1], av[2] );

	write( 1, "\n", 1 );

	return 0;
}
