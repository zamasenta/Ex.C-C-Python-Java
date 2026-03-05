/*************************************************
 *
 *      Titolo: Gestione dei file in C In ambiente Linux 
 *
 *      Autori: Gramazio Lorenzo
 *
 *      Data di modifica: 05/03/2026
 *
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *      Descrizione progetto:realizzare un semplice programma in linguaggio C che utilizzi un file di testo per scrivere e leggere dati. Il programma dovrà aprire un file di testo in modalità scrittura, verificare che l’apertura sia avvenuta correttamente e scrivere al suo interno alcuni dati (ad esempio nome, cognome o altre informazioni a scelta). Dopo aver chiuso il file, il programma dovrà riaprirlo in modalità lettura, leggere i dati precedentemente salvati e stamparli a video.
 *							 
 ************************************************/

#include <stdio.h>
#include <stdlib.h>  /* standard library for EXIT_SUCCESS/EXIT_FAILURE, malloc, etc. */

int main(void) {
    /* nome del file su disco che useremo per leggere e scrivere */
    const char *filename = "dati.txt";
    /* puntatore a struct FILE, rappresenta il file aperto
       dalle funzioni di libreria come fopen() */
    FILE *fp;

    /* apri il file in modalita` scrittura: "w" crea il file
       se non esiste o lo trunca se esiste gia` (cancella il contenuto) */
    fp = fopen(filename, "w");
    /* fopen ritorna NULL se c'e` stato un errore (per esempio
       permessi insufficienti o cartella inesistente) */
    if (fp == NULL) {
        perror("Errore apertura file in scrittura");
        /* EXIT_FAILURE e` una macro standard che indica un fallimento */
        return EXIT_FAILURE;
    }

    /* scrivi alcuni dati nel file aperto. fprintf funziona come printf
       ma invia l'output al file puntato da fp invece che allo stdout */
    fprintf(fp, "Nome: Lorenzo\n");
    fprintf(fp, "Cognome: Gramazio\n");
    fprintf(fp, "Eta: 17\n");
    fprintf(fp, "Classe: 4IA\n");
    /* dopo aver finito di scrivere per chiudere il file
       si usa fclose*/
    fclose(fp);

    /* riapri il file in modalita` lettura: "r" richiede che il file
       esista gia` (diversa da "w" che lo crea). Controlla nuovamente
       eventuali errori di apertura. */
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Errore apertura file in lettura");
        return EXIT_FAILURE;
    }

    /* stampa un messaggio prima di lettura */
    printf("Contenuto del file '%s':\n", filename);

    /* buffer temporaneo per leggere le righe dal file */
    char buffer[256];
    /* fgets legge una riga (o fino a sizeof(buffer)-1 caratteri) e
       la memorizza in buffer, restituendo NULL quando si raggiunge
       la fine del file (EOF) o in caso di errore. */
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        /* fputs invia la stringa al flusso stdout, equivalente a
           printf("%s", buffer)*/
        fputs(buffer, stdout);
    }

    /* chiudi di nuovo il file dopo la lettura */
    fclose(fp);
    /* EXIT_SUCCESS indica che il programma e` terminato correttamente */
    return EXIT_SUCCESS;
}
