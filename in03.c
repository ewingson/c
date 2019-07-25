//windows read character in a loop without return and output ascii-value break on #
#include<stdio.h>
#include<conio.h>
#include<windows.h>

int main() {
 
int countdown;
char ch;
int wert;
char b;
do {
    while(countdown++ <= 1000)
    {  
            if(b=kbhit())            
            break;             
            Sleep(1);   
    }
    ch = getch();
    wert = ch;
    if (b != 0)        
            { printf("key %c ascii %d\n", ch, wert);}
} while (ch != '#');
printf ("programmende\n");
return 0;
}
