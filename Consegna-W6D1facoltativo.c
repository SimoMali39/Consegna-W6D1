#include <stdio.h>

// Definisco una struttura per le domande
typedef struct {
    char domanda[256];
    char opzioni[3][256];
    int rispostaCorretta;
} Domanda;

int punteggioTotale = 0; // Variabile globale per memorizzare il punteggio totale

// Funzione per visualizzare il menu
void mostraMenu() {
    printf("\nMenu:\n");
    printf("A) Inizia una nuova partita\n");
    printf("B) Esci dal gioco\n");
    printf("Scegli un'opzione (A/B): ");
}

// Funzione per iniziare una nuova partita
void iniziaGioco() {
    char nomeGiocatore[50];
    int punteggioPartita = 0; // Punteggio della partita corrente
    char risposta;

    // Nome del giocatore
    printf("Inserisci il tuo nome: ");
    scanf("%s", nomeGiocatore);

    // Array di domande
    Domanda domande[3] = {
        {"Qual è la capitale d'Italia?", {"Roma", "Milano", "Venezia"}, 1},
        {"Qual è la lingua ufficiale del Brasile?", {"Portoghese", "Spagnolo", "Inglese"}, 1},
        {"Qual è il pianeta più vicino al Sole?", {"Venere", "Marte", "Mercurio"}, 3}
    };

    // Loop sulle domande
    for (int i = 0; i < 3; i++) {
        printf("\n%s\n", domande[i].domanda);
        printf("1) %s\n", domande[i].opzioni[0]);
        printf("2) %s\n", domande[i].opzioni[1]);
        printf("3) %s\n", domande[i].opzioni[2]);
        printf("Scegli una risposta (1/2/3): ");
        scanf(" %c", &risposta);

        // Controllo della risposta
        if ((risposta - '0') == domande[i].rispostaCorretta) {
            printf("Risposta corretta!\n");
            punteggioPartita++;
        } else {
            printf("Risposta sbagliata. La risposta corretta era: %s\n", domande[i].opzioni[domande[i].rispostaCorretta - 1]);
        }
    }

    // Aggiornamento del punteggio totale
    punteggioTotale += punteggioPartita;

    // Stampa del punteggio della partita corrente e del punteggio totale
    printf("\n%s, il tuo punteggio della partita è: %d su 3\n", nomeGiocatore, punteggioPartita);
    printf("Il tuo punteggio totale è: %d\n", punteggioTotale);
}

int main() {
    char scelta;

    printf("Benvenuto al gioco di domanda/risposta!\n");

    while (1) {
        mostraMenu();
        scanf(" %c", &scelta);

        if (scelta == 'A' || scelta == 'a') {
            iniziaGioco();
        } else if (scelta == 'B' || scelta == 'b') {
            printf("Grazie per aver giocato. Arrivederci!\n");
            break;
        } else {
            printf("Scelta non valida. Per favore, scegli A o B.\n");
        }
    }

    return 0;
}