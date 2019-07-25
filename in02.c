//linux read character in a loop without return and output ascii-value break on #
#include <stdio.h>
#include <termios.h>
#include <string.h>

int kbhit(void);
int kbhit(void) {
	struct termios term, oterm;
	int fd = 0;
	int c = 0;
	tcgetattr(fd, &oterm);
	memcpy(&term, &oterm, sizeof(term));
	term.c_lflag = term.c_lflag & (!ICANON);
	term.c_cc[VMIN] = 0;
	term.c_cc[VTIME] = 1;
	tcsetattr(fd, TCSANOW, &term);
	c = getchar();
	tcsetattr(fd, TCSANOW, &oterm);
	if (c != -1)
	ungetc(c, stdin);
	return ((c != -1) ? 1 : 0);
}

int getch();
int getch()
{
	static int ch = -1, fd = 0;
	struct termios neu, alt;
	fd = fileno(stdin);
	tcgetattr(fd, &alt);
	neu = alt;
	neu.c_lflag &= ~(ICANON|ECHO);
	tcsetattr(fd, TCSANOW, &neu);
	ch = getchar();
	tcsetattr(fd, TCSANOW, &alt);
	return ch;
}

int rechne(char v);
int rechne(char v) {
	int vback;
	vback = v;
	return vback;
}

int main() {
	char c;
	int interr;
	interr = 1;
	do {
		do {
	   		c = getch();
	   		if (c == '#') {
				interr = 0;
				break;
			}
	   	int wert;
	   	wert = rechne(c);
	   	printf("char '%c' key '%d'\n", c, wert);
	 	}
		while(kbhit());
	}
	while(interr);
printf("programmende\n");
return 0;
}
