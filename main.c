#include<stdio.h>
#include<stdlib.h>

#define MAX_CMD_LEN  128
#define HISTORY_COUNT 20

int main(){

    int floors [16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int size = sizeof(floors)/sizeof(floors[0]);

    int storage[5];
    int storageSize = sizeof(storage)/sizeof(storage[0]);

    int currentFloor;
    int playerFloor;
    int checkValidFloor = 0;

    int playerCount = 0;

    int count = 1;

    char cmd[MAX_CMD_LEN];
    char *hist[HISTORY_COUNT];
    int i, current = 0;

    //for (i = 0; i < HISTORY_COUNT; i++)
    //hist[i] = NULL;
    
    while(playerCount < 5)
    {   
        do
        {
            printf("Choose a floor: ");
            scanf("\n%d", &playerFloor);
            
        }while(playerFloor < 0 || playerFloor > 16);

        for(int i = playerCount; i < storageSize; i++)
        {  
           storage[i] = playerFloor;
           break;
        }

        for(int i = 0; i < size; i++)
        {
            if(playerFloor == floors[i])
            {
                checkValidFloor = 1;
            }
        }

        if(checkValidFloor == 1)
        {
            for(int i = 0; i < size; i++)
            {
                if(playerFloor > i)
                {
                    printf("%d\n",i);   
                }
                else if(playerFloor == i)
                {
                    printf("%d\n",i);
                    printf("DING!\n");
                    playerCount++;
                }
            }
        }
        else
        {
            printf("Invalid Floor Inserted !");
        }        
    }

    for(int i = 0; i < storageSize; i++)
    {
        if(i == 0)
        {
            printf("\nHistory\n");
        }
        printf("%d", storage[i]);
    }

    return 0;    
}

// int history(char *hist[], int current)
// {
//         int i = current;
//         int hist_num = 1;

//         do {
//                 if (hist[i]) {
//                         printf("%4d  %s\n", hist_num, hist[i]);
//                         hist_num++;
//                 }

//                 i = (i + 1) % HISTORY_COUNT;

//         } while (i != current);

//         return 0;
// }
