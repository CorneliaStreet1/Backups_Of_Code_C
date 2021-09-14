#include<stdio.h>
int main(void)
{
    int goal,guess,max;
    scanf("%d%d",&goal,&max);
    scanf("%d",&guess);
    int i = 1;
    while(guess != goal ){
        if(guess < 0){
            printf("Game Over\n");
            goto end;
        }
        else if(guess < goal){
            printf("Too small\n");
        }
        else if(guess > goal){
            printf("Too big\n");
        }
        else if(guess == goal){
            break;
        }
        scanf("%d",&guess);
        i ++;
    }
        if(i == 1){
            printf("Bingo!\n");
        }
        else if(i > 1 && i <= 3){
            printf("Lucky You!\n");
            }
        else if(i > 3 && i <= max){
            printf("Good Guess!\n");
        }
        else if(i > max){
            printf("Game Over\n");
            goto end;
        }
    end:
    return 0;
}