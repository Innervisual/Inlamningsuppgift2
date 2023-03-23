#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "card_reader.h"
#include <winsock2.h>
#include <windows.h>
#include <conio.h>


int main() {
    CardsList cardsList;
    initCardsList(&cardsList);

    readCardList(&cardsList);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Remote open door\n");
        printf("2. List all cards in system\n");
        printf("3. Add/remove access\n");
        printf("4. Exit\n");
        printf("9. FAKE TEST SCAN CARD\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            printf("CURRENTLY LAMP IS: Green\n");
            Sleep(3);
        } else if (choice == 2) {
            listAllCards(&cardsList);
        } else if (choice == 3) {
            printf("Enter card number: ");
            int cardNum;
            scanf("%d", &cardNum);
            Card *foundCard = findCard(cardNum, &cardsList);
            if (foundCard) {
                printCardDetails(foundCard);
                printf("Enter 1 for access, 2 for no access: ");
                int access;
                scanf("%d", &access);
                foundCard->access = access == 1;
                updateCardInFile(foundCard);
            } else {
                Card newCard;
                newCard.cardNumber = cardNum;
                printf("Enter 1 for access, 2 for no access: ");
                int access;
                scanf("%d", &access);
                newCard.access = access == 1;
                time_t timer = time(NULL);
                struct tm *date_info = localtime(&timer);
                strftime(newCard.timeAddedStr, sizeof(newCard.timeAddedStr), "%Y-%m-%d", date_info);
                addCard(&newCard, &cardsList);
                addCardToFile(&newCard);
            }
        } else if (choice == 4) {
            return 0; // Exit the program
        } else if (choice == 9) {
            printf("Please scan card to enter or X to go back to admin mode.\n");
            int inputAvailable = waitForInputWithTimeout(5000);

            if (inputAvailable > 0) {
                char input = getchar();
                getchar(); // Consume the newline character
                if (input == 'X' || input == 'x') {
                    // Do nothing, it will automatically go back to the admin mode
            }
            }
        } else {
            printf("Timeout, going back to the admin mode.\n");
    }
}


    //freeCardsList(&cardsList);
    return 0;
}

