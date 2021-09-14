#include<stdio.h>
void down(int vk);
void up(int k);
int main(void)
{
    while (1){
        down(86);
        up(86);
    }
}
void up(int vk)
{
keybd_event(vk,0,KEYEVENTF_KEYUP,0);
}
void down(int vk)
{
    keybd_event(vk,0,0,0);
}