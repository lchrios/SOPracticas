#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void processSignal(int s) {
    printf("Señal recibida %d\n", s);
}

void notKill(int s) {
    printf("Ningún hombre puede matarme así\n");
}

int main() {
    signal(10, processSignal);
    signal(15, notKill);
    while(1) {
        sleep(3);
        printf("Procesando...\n");
    }
    return 0;
}