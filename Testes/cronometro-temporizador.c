#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define MAX_VOLTAS 10
#define CLEAN_BUFFER {char c; while((c=getchar()) != '\n' && c != EOF);}


typedef struct {
    short horas;
    short minutos;
    short segundos;
} Hora;


int menu();
void help();
void cronometro();
void temporizador();
void lerHora(Hora *h);
void zerarHora(Hora* h);
bool horaZerada(Hora* h);
void incrementaHora(Hora* h);
void decrementaHora(Hora* h);
void imprimeHora(Hora h, int qnt, Hora* vet);


void main(){
    setlocale(LC_ALL, "ptb");
    int escolhaMenu;
    do {
        escolhaMenu = menu();
        switch(escolhaMenu){
            case 1: system("cls"); cronometro();   if(getche()) system("cls"); break;
            case 2: system("cls"); temporizador(); if(getche()) system("cls"); break;
            case 3: system("cls"); help();         if(getche()) system("cls"); break;
            case 4: break;
            default: printf("Opção inválida! "); if(getche()) system("cls");
        }
    } while (escolhaMenu != 4);
}

int menu(){
    int opcao;
    printf("======= Menu de escolha =======\n");
    printf("[1] - Cronômetro\n");
    printf("[2] - Temporizador\n");
    printf("[3] - Ajuda - atalhos\n");
    printf("[4] - Sair\n");
    printf("===============================\n");
    printf("Opção escolhida: ");    scanf("%d", &opcao);
    return opcao;
}

void help(){
    printf("\n");
    printf("Informe 'p' para pausar o cronômetro/temporizador\n");
    printf("Informe 'r' para reiniciar o cronômetro\n");
    printf("Informe 'r' para realizar uma nova contagem no temporizador\n");
    printf("Informe 'R' para reiniciar todas as voltas do cronômetro\n");
    printf("Informe 'v' para criar uma nova volta no cronômetro\n");
    printf("Informe 'e' para voltar ao menu\n");
}

bool horaZerada(Hora* h){
    return (h->horas==0 && h->minutos==0 && h->segundos==0);
}

void imprimeHora(Hora h, int qnt, Hora* vet){
    printf("\n\t%02d:%02d:%02d", h.horas, h.minutos, h.segundos);
    for(int i=0 ; i<qnt ; i++) printf("\n\t%02d:%02d:%02d", vet[i].horas, vet[i].minutos, vet[i].segundos);
}

void lerHora(Hora* h){
    system("cls");
    printf("   Horas: ");  scanf("%d", &h->horas);
    printf(" Minutos: ");  scanf("%d", &h->minutos);
    printf("Segundos: ");  scanf("%d", &h->segundos);
    if(h->segundos>=60) {
        h->minutos += (h->segundos/60);
        h->segundos = h->segundos%60;
    }
    if(h->minutos>=60){
        h->horas += (h->minutos/60);
        h->minutos = h->minutos%60;
    }
    system("cls");
}

void incrementaHora(Hora* h){
    if((h->segundos += 1) == 60) {
        h->minutos++;
        h->segundos = 0;
    }
    if(h->minutos == 60) {
        h->horas++;
        h->minutos = 0;
    }
    if(h->horas == 24) h->horas = 0;
}

void decrementaHora(Hora* h){
    if(h->segundos == 0){
        if(h->minutos>0) {
            h->segundos = 59;
            h->minutos--;
        }
    } else h->segundos--;
    if(h->minutos == 0)
        if(h->horas>0){
            h->horas--;
            h->minutos = 59;
        }
}

void zerarHora(Hora* h){
    h->horas = 0;
    h->minutos = 0;
    h->segundos = 0;
}

void cronometro(){
    char atalho = 0;
    bool pausado = true;
    static int qntVoltas = 0;
    static Hora voltas[MAX_VOLTAS];
    static Hora hora = {.segundos=0, .minutos=0, .horas=0};
    while(true) {
        if(kbhit()){
            atalho = getche();
            if(atalho == 'p') pausado = !pausado;
            if(atalho == 'r') zerarHora(&hora);
            if(atalho == 'R') {zerarHora(&hora); qntVoltas=0;}
            if(atalho == 'e') break;
            if(atalho == 'v' && qntVoltas<MAX_VOLTAS) {voltas[qntVoltas] = hora; qntVoltas++; zerarHora(&hora);}
        }
        imprimeHora(hora, qntVoltas, voltas);
        Sleep(1000);
        if(!pausado) incrementaHora(&hora);
        system("cls");
    }
}

void temporizador() {
    char atalho = 0;
    bool pausado = true;
    static Hora hora = {.horas=0, .minutos=0, .segundos=0};
    if(horaZerada(&hora)) lerHora(&hora);
    while(true) {
        if(kbhit()){
            atalho = getche();
            if(atalho == 'p') pausado = !pausado;
            if(atalho == 'r') lerHora(&hora);
            if(atalho == 'e') break;
        }
        imprimeHora(hora, 0, NULL);
        Sleep(1000);
        if(horaZerada(&hora)) {
            system("cls");
            imprimeHora(hora, 0, NULL);
            break;
        }
        if(!pausado) decrementaHora(&hora);
        system("cls");
    }
}
