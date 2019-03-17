#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//okunan dosyadaki satırların saklanması için
//bir stack yapısı tanımladım.

struct stack{
	char strings[100];

};

void main(int argc , char *argv[]){

	struct stack s[100];
	FILE *file_pointer;
	char line[100];
	int n=0,count=0,i=0;
	int row_num=0;
	row_num=atoi(argv[2]);
	file_pointer=fopen(argv[1],"r");
	while(fscanf(file_pointer,"%[^\n]\n",line)!=EOF)
	{
		strcpy(s[i].strings,line);
		i++;
		n=i;
	}
	

	for(i=n;i>0;i--){
		
		if(count==row_num)
			break;
		else
			printf("%s\n",s[i].strings);
		count++;
	}
		
	
}	





