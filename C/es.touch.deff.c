/*************************************************
 *
 *      Titolo: Comando touch sotto linux con help
 *
 *      Autori: Gramazio Lorenzo
 *
 *      Data di modifica: 18/01/2026
 *
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *      Descrizione progetto:Realizzare una propria versione del comando touch sotto Linux in C. 
 *       Si suggerisce di implementare un  sistema di help per il comando stesso.
 ************************************************/
 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>  // Per la funzione strcmp()

    // Funzione che visualizza il messaggio di aiuto
    // Spiega l'utilizzo del programma e le opzioni disponibili
    void help(){
        printf("Uso: touch [OPZIONI]... FILE...\n");
        printf("Aggiorna la data di accesso e modifica dei FILE specificati.\n\n");
        printf("Opzioni:\n");
        printf("  -h, --help      Mostra questo messaggio di aiuto e termina\n");
        printf("  -v, --version   Mostra le informazioni sulla versione e termina\n");
        printf("\nEsempio:\n");
        printf("  touch file.txt  Crea un nuovo file chiamato file.txt o aggiorna la data di accesso e modifica se esiste già.\n");
    }
    
    // Funzione che visualizza le informazioni sulla versione del programma
    void version(){
        printf("touch versione 1.0\n");
        printf("Autore: Gramazio Lorenzo\n");
        printf("Data di rilascio: 01/2026\n");
    }
    
    // Funzione principale del programma
    // Parametri:
    //   argc: numero di argomenti da riga di comando (incluso il nome del programma)
    //   argv: array di stringhe con gli argomenti
    // Ritorno: 0 se esecuzione corretta, 1 se errore
    int main(int argc, char *argv[]){
        // Verifica se sono stati forniti argomenti da riga di comando
        // Se argc < 2, significa che nessun file è stato specificato
        if(argc != 2){
            printf("Errore: Nessun argomento fornito. Usa --help per assistenza.\n");
            return 1;  // Esce dal programma con codice di errore
        }
        
        // Itera attraverso tutti gli argomenti forniti (partendo da 1, saltando il nome del programma)
            // Verifica se l'argomento è l'opzione help
            if(strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0){
                help();  // Mostra il messaggio di aiuto
                return 0;  // Esce dal programma normalmente
            } 
            // Verifica se l'argomento è l'opzione version
            else if(strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--version") == 0){
                version();  // Mostra le informazioni sulla versione
                return 0;  // Esce dal programma normalmente
            } 
            // Se l'argomento non è un'opzione, viene trattato come nome di un file
            else {
                // Apre il file in modalità append (aggiunta)
                // Se il file non esiste, viene creato; se esiste, non viene modificato
                FILE *file = fopen(argv[i], "w+");
                
                // Verifica se il file è stato aperto/creato correttamente
                if(file == NULL){
                    printf("Errore: Impossibile creare o aprire il file %s\n", argv[i]);
                    return 1;  // Esce dal programma con codice di errore
                }
                
                // Chiude il file dopo aver completato l'operazione
                fclose(file);
            }
        
        return 0;  // Esce dal programma normalmente
    }

