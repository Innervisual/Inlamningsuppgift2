#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "card_reader.h"
#include <winsock2.h>
#include <windows.h>
#include <conio.h>
#include "safeinput.h" // Include the new header

void invalidInputCallback() {
    printf("Invalid input, Please choose a valid option. \n");
}

int main() {
    CardsList cardsList;
    initCardsList(&cardsList);

    readCardList(&cardsList, "cards.txt");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Remote open door\n");
        printf("2. List all cards in system\n");
        printf("3. Add/remove access\n");
        printf("4. Exit\n");
        printf("9. FAKE TEST SCAN CARD\n");
        printf("Enter your choice: ");

        int choice = readIntWithCallback(invalidInputCallback);


        if (choice == 1) {
            printf("CURRENTLY LAMP IS: Green\n");
            Sleep(3);
        } else if (choice == 2) {
            listAllCards(&cardsList);
        } else if (choice == 3) {
            printf("Enter card number: ");
            int cardNum = readInt();
            Card *foundCard = findCard(cardNum, &cardsList);
            if (foundCard) {
                printCardDetails(foundCard);
                printf("Enter 1 for access, 2 for no access: ");
                int access = readInt();
                foundCard->access = access == 1;
                updateCardInFile(foundCard);
            } else {
                Card newCard;
                newCard.cardNumber = cardNum;
                printf("Enter 1 for access, 2 for no access: ");
                int access = readInt();
                newCard.access = access == 1;
                time_t timer = time(NULL);
                struct tm *date_info = localtime(&timer);
                strftime(newCard.timeAddedStr, sizeof(newCard.timeAddedStr), "%Y-%m-%d", date_info);
                addCard(&newCard, &cardsList);
                addCardToFile(&newCard, "cards.txt");
            }
        } else if (choice == 4) {
            return 0; // Exit the program
        } else if (choice == 9) {
            printf("Please scan card to enter or X to go back to admin mode.\n");
            LampStatus lampStatus = LAMP_OFF;
            printLampStatus(lampStatus);

            int cardNumber;
            while (1) {
                cardNumber = readIntWithCallbackAndExitChar(invalidInputCallback, 'x');
                if (cardNumber == -1) {
                    break;
                }
                Card *card = findCard(cardNumber, &cardsList);
                if (card != NULL && card->access) {
                    lampStatus = LAMP_GREEN;
                } else {
                    lampStatus = LAMP_RED;
                }
                printLampStatus(lampStatus);
            }
        } else {
            printf("Invalid input, going back to the admin mode.\n");
        }
    }

    //freeCardsList(&cardsList);
    return 0;
}



