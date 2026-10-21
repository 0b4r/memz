#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

int main(void)
{
    uint16_t health = 6969;
    printf("pid: %d\n", getpid());
    printf("addr: %p\n", (void *)&health);


    while (1) {
        printf("Aguardando ENTER no alvo para mudar...\n");
        getchar(); 
        
        health = 420; // Mudou na memória!
        
        printf("Mudei! Agora vá no scanner correndo e faça o scan ANTES de apertar ENTER aqui de novo.\n");
        getchar(); // <--- TRAVE O PROGRAMA AQUI
    }
    return 0;
}
