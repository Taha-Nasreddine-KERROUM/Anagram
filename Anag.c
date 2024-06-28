#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int isanagram( char *str1, char *str2 ){
    int n1 = strlen(str1),
        n2 = strlen(str2);
        
    if ( n1 != n2 )
        return 0;
    for ( int i = 0; i < n1; ++i ){
        int f1 = 0,
            f2 = 0;
            
        char *p = strchr( str1, str1[i] );
        while (p){
            f1++;
            p = strchr( p + 1, str1[i] );
        }
        
        p = strchr( str2, str1[i] );
        while (p){
            f2++;
            p = strchr( p + 1, str1[i] );
        }
        
        if ( f1 != f2 )
            return 0;
    }
    
    return 1;
}

int main(){
    int N;
    char **str;
    
    printf(" enter number of words: ");
    scanf("%d%*c",&N);
    
    str = ( char** ) malloc ( N * sizeof(char*));
    
    for( char **s = str; s < str + N; ++s ) {
        char temp[400];
        printf(" string %ld: ", s - str);
        gets(temp);
        
        *s = ( char* ) malloc ( strlen(temp) + 1 );
        strcpy(*s, temp);
    }
    
    puts(" anagram pairs: ");
    
    for( char **s = str; s < str + N; ++s ) {
        if ( strlen( *s ) == 0 ) continue;
        
        int i = 0;
        
        for( char **p = str; p < str + N; ++p ) {
            if ( *p != *s )
                if ( isanagram(*s, *p) ) {
                    if ( !i )
                        printf(" %s ", *s);
                        
                    printf("-");
                    printf(" %s ", *p);
                    **p = '\0';
                    i++;
                }
        }
        
        printf("\n");
    }
}
