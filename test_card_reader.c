#include <stdio.h>
#include <stdlib.h>
#include "card_reader.h"

void test_findCard() {
    CardsList testList;
    initCardsList(&testList);

    Card testCard = {1212, true, "2019-10-19"};
    testList.cards[0] = testCard;
    testList.count = 1;

    Card *foundCard = findCard(1212, &testList);
    if (foundCard != NULL && foundCard->cardNumber == 1212) {
        printf("Test findCard: SUCCESS\n");
    } else {
        printf("Test findCard: FAIL\n");
    }
}

/*void test_addCardToFile_and_readCardList() {
    CardsList testList;
    initCardsList(&testList);

    Card testCard = {1213, false, "2019-10-19"};
    addCardToFile(&testCard);

    readCardList(&testList);
*/

void test_addCardToFile_and_readCardList() {
    CardsList testList;
    initCardsList(&testList);

    Card testCard = {1213, false, "2019-10-19"};
    addCardToFile(&testCard, "test_cards.txt");

    readCardList(&testList, "test_cards.txt");
    Card *foundCard = findCard(1213, &testList);
    if (foundCard != NULL && foundCard->cardNumber == 1213) {
        printf("Test addCardToFile and readCardList: SUCCESS\n");
    } else {
        printf("Test addCardToFile and readCardList: FAIL\n");
    }
}

int main() {
    test_findCard();
    test_addCardToFile_and_readCardList();
    return 0;
}
