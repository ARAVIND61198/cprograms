#if _WIN32
	#include<conio.h>
	#define left 75
	#define right 77
	#define interuptor 0xE0
	void ignore_function(){
	}
#elif __linux__
	#define left 68
	#define right 67
	#define interuptor 27
	#include"linux_header.h"
	void ignore_function(){
	char c = getch();
	}
#else
	void system(){
		printf("system not defined");
	}
#endif
