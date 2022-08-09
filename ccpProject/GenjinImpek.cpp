#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void logoASCII()
{
    FILE *fptr = fopen("title.txt", "r");
    if (fptr == NULL)
    {
        printf("Error opening a file");
    }
    char line[100];
    while (fgets(line, sizeof(line), fptr))
    {
        printf("%s", line);
    }
    printf("\nGenshin Impact gacha simulator\n");
}
void gameRules()
{
}
void characterRNG(int pull)
{
    int number;
    int start = 0, max = 10;
    char Character[][100] = {"Diluc", "Jean", "Mona", "Cupang", "Dull Blade", "Waster Greatsword", "Qiqi", "Silver Sword", "Debate CLub", "Hunter's Bow", "Iron Point"};
    srand(time(NULL));
    for (int i; i <= pull; i++)
    {
        number = (rand() % (max - start + 1)) + start;
        printf("%s\n", Character[number]);
    }
}
void weaponRNG(int pull)
{
    int number;
    int start = 0, max = 10;
    char weapon[][100] = {"Dull Blade", "Yenfei", "waster Greatsword", "Iron Point", "Noelle", "Hunter's Bow", "Silver Sword", "Freedom Sworn Sword", "Debate Club", "Lost Prayer"};
    srand(time(NULL));
    for (int i; i <= pull; i++)
    {
        number = (rand() % (max - start + 1)) + start;
        printf("%s\n", weapon[number]);
    }
}
int main()
{
    int choose, select, increasePrimogems;
    int mainAgain = 1;
    int primogems{50};
    do
    {
        logoASCII();
        printf("1) Character\n2) Weapon\nChoose banner: ");
        scanf("%i", &choose);
        system("cls");
        if (choose == 1)
        {
            int again1 = 1;
            do
            {
                logoASCII();
                printf("Primogems: %i\n", primogems);
                printf("1) pull X1\n2) pull X10\n3) more primogems\n4) help\n");
                printf("Choose how many pull: ");
                scanf("%i", &select);

                if (select == 1)
                {
                    if (primogems <= 0)
                    {
                        primogems *= 0;
                        printf("You don't have enough primogems");
                    }
                    else if (primogems >= 1)
                    {
                        primogems -= 1;
                        characterRNG(1);
                    }
                }
                if (select == 2)
                {
                    if (primogems <= 0)
                    {
                        primogems *= 0;
                        printf("You don't have enough primogems");
                    }
                    else if (primogems < 10)
                    {
                        printf("You don't have enough primogems");
                    }
                    else if (primogems >= 10)
                    {
                        primogems -= 10;
                        characterRNG(10);
                    }
                }
                if (select == 3)
                {
                    printf("How many primogems you want?\n");
                    printf("add Primogems: ");
                    scanf("%i", &increasePrimogems);
                    primogems += increasePrimogems;
                }
                if (select == 4)
                {
                    FILE *fhelp = fopen("gamerule.txt", "r");
                    if (fhelp == NULL)
                    {
                        printf("Message failed to load");
                    }
                    char list[100];
                    while (fgets(list, sizeof(list), fhelp))
                    {
                        printf("%s", list);
                    }
                }
                else if (select > 4)
                {
                    printf("\nSelection is not valid\nPlease choose the following selection\n");
                    printf("1) pull X1\n2) pull X10\n3) more primogems");
                }

                again1 = 0;
                while (again1 != 1 && again1 != 2)
                {
                    printf("\nDo you want to try again?");
                    printf("\n1) yes\n2) no\nChoose: ");
                    scanf("%i", &again1);
                }
            } while (again1 == 1);
        }
        else if (choose == 2)
        {
            int again2 = 1;
            do
            {
                logoASCII();
                printf("Primogems: %i\n", primogems);
                printf("1) pull X1\n2) pull X10\n3) more primogems\n4) help\n");
                printf("Choose how many pull: ");
                scanf("%i", &select);

                if (select == 1)
                {
                    if (primogems <= 0)
                    {
                        primogems *= 0;
                        printf("You don't have enough primogems");
                    }
                    else if (primogems >= 1)
                    {
                        primogems -= 1;
                        weaponRNG(1);
                    }
                }
                if (select == 2)
                {
                    if (primogems <= 0)
                    {
                        primogems *= 0;
                        printf("You don't have enough primogems");
                    }
                    else if (primogems < 10)
                    {
                        printf("You don't have enough primogems");
                    }
                    else if (primogems >= 10)
                    {
                        primogems -= 10;
                        weaponRNG(10);
                    }
                }
                if (select == 3)
                {
                    printf("How many primogems you want?\n");
                    printf("add Primogems: ");
                    scanf("%i", &increasePrimogems);
                    primogems += increasePrimogems;
                }
                if (select == 4)
                {
                    FILE *fhelp = fopen("gamerule.txt", "r");
                    if (fhelp == NULL)
                    {
                        printf("Message failed to open");
                    }
                    char list[100];
                    while (fgets(list, sizeof(list), fhelp))
                    {
                        printf("%s", list);
                    }
                }
                else if (select > 4)
                {
                    printf("\nSelection is not valid\nPlease choose the following selection\n");
                    printf("1) pull X1\n2) pull X10\n3) more primogems\n");
                }

                again2 = 0;
                while (again2 != 1 && again2 != 2)
                {
                    printf("\nDo you want to try again?");
                    printf("\n1) yes\n2) no\nChoose: ");
                    scanf("%i", &again2);
                }
            } while (again2 == 1);
        }
        mainAgain = 0;
        while (mainAgain != 1 && mainAgain != 2)
        {
            printf("\nDo you want to play again?");
            printf("\n1) yes\n2) no\nChoose: ");
            scanf("%i", &mainAgain);
        }
    } while (mainAgain == 1);
    system("cls");
    logoASCII();
    printf("Thank you for playing");

    return 0;
}