#include <stdio.h>

int main() {

    int n , i;

    printf( "Enter Number : " ) ;
    scanf( "%d", &n ) ;

    for( i = 1 ; i <= n ; i++ ) {
        printf("[%d] Hello world \n",i) ;
    }
}