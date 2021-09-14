#include<stdio.h>
int main(void)
{
    int n,length = 1,point = 0;
    scanf("%d",&n);
    int map[n][n];
    for(int i = 0 ; i < n ; i ++){
        for(int p = 0 ; p < n ;p ++){
            scanf("%d",&map[i][p]);
        }
    }
    char move[100];
    scanf("%s", move);
    int hang,lie;
    scanf("%d%d",&hang, &lie);
    for(int k = 0 ;k < 100 ; k ++){
        if(move[k] == '2'){
            hang = hang - 1;
            if(map[hang][lie] > 0){
                length ++;
                point = point + map[hang][lie];
                map[hang][lie] = 0;
            }
        }
        if(move[k] == '4'){
            lie --;
            if(map[hang][lie] > 0){
                length ++;
                point = point + map[hang][lie];
                map[hang][lie] = 0;
            }

        }
        if(move[k] == '6'){
            lie ++;
            if(map[hang][lie] > 0){
                length ++;
                point = point + map[hang][lie];
                map[hang][lie] = 0;
            }
        }
        if(move[k] == '8'){
            hang ++;
            if(map[hang][lie] > 0){
                length ++;
                point = point + map[hang][lie];
                map[hang][lie] = 0;
            }
        }
    }
    printf("%d %d\n" ,hang,lie);
    printf("%d %d",length,point);
    return 0;
}