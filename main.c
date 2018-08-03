#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct list{
    struct list *prev;
    struct list *next;
    int value;
}list;
 
int main(int argc, char *argv[]) 
{
    char str[7];
    list *header =  NULL;
    list *footer =  NULL;
    
    while(fgets(str, sizeof(str), stdin)){
        int n = atoi(str);
        if(n == 0){
            // リストを表示
            list *p = header;
            while(p){
                printf("%d", p->value);
                p = p->next;
                if(p){printf(",");}
            }
            printf("\n");
        }else if(n == 100){
            // 先頭を削除
            list *p = header;
            if(p){
                printf("%d\n", p->value);
                header = p->next;
                if(header) header->prev = NULL;
                if(footer == p) footer = NULL;
                free(p);
            }
        }else if(n == -100){
            // 末尾を削除
            list *p = footer;
            if(p){
                printf("%d\n", p->value);
                footer = p->prev;
                if(footer) footer->next = NULL;
                if(header == p) header = NULL;
                free(p);
            }
        }else if(0 < n){
            // 要素を先頭に追加
            list *p = (list*)malloc(sizeof(list));
            if(p){
                p->value = n;
                p->next = header;
                p->prev = NULL;
                if(footer == NULL) {
                    footer = p;
                }
                if(header != NULL){
                    header->prev = p;
                }
                header = p;
            }
        }else{
            // 要素を末尾に追加
            list *p = (list*)malloc(sizeof(list));
            if(p){
                p->value = -n;
                p->prev = footer;
                p->next = NULL;
                if(header == NULL) {
                    header = p;
                }
                if(footer != NULL){
                    footer->next = p;
                }
                footer = p;
            }
        }
    }
 
    return 0;
}
