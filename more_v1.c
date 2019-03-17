#include <stdlib.h>
#include <stdio.h>
#define SCREEN_ROWS 23
#define LINELEN 512
#define SPACEBAR 1
#define RETURN 2
#define QUIT 3
#define INVALID 4

void do_more_of(FILE *fp){
    char line[LINELEN];
    int num_of_lines=SCREEN_ROWS;
    int getmore=1;
    int reply;
    while(getmore&&fgets(line,LINELEN,fp)){
        if(num_of_lines==0){
            reply=get_user_input();
            switch (reply){
                case SPACEBAR:
                    num_of_lines=SCREEN_ROWS;
                    break;
                case RETURN:
                    num_of_lines++;
                    break;
                case QUIT:
                    getmore=0;
                    break;
                default:
                    break;
            }
        }

        if (fputs(line,stdout)==EOF)
            exit(1);
        num_of_lines--;


    }



}



int get_user_input(){
    int c;
    printf( "\033 [ 7m more? \033[m" );
    while ((c=getchar())!=EOF){
        switch (c){
            case 'q':
                return QUIT;
            case ' ':
                return SPACEBAR;
            case '\n':
                return RETURN;
            default:
                return INVALID;
        }

    }




}


int main(int argc, char *argv[])
{

    FILE *fp;
    int i=0;
    if(1==argc)
        do_more_of(stdin);
    else
        while(++i<argc){
            fp=fopen(argv[i],"r");
            if (NULL!=fp)
            {
                do_more_of(fp);
                fclose(fp);
            }
            else
                printf("Skipping %s\n",argv[i]);

        }


    return 0;
}




