#include <stdlib.h>
#include <stdio.h>
#include <time.h>
void population(int game[30][30])
{
    for(int i=0; i<30; i++)
        for(int j=0; j<30; j++) game[i][j]=rand()%2;
}
void printGame(int game[30][30])
{
    for(int i=0; i<30; i++)
        {
            for(int j=0; j<30; j++)
                printf("%d ", game[i][j]);
            printf("\n");
        }
}
void turncheck(int game[30][30], int temp[30][30])
{
    int life=0;
    for(int i=0; i<30; i++)
        for(int j=0; j<30; j++)
            {
                for(int di=-1; di<=1; di++)
                    for(int dj=-1; dj<=1; dj++)
                        {
                            if(di==0 && dj==0) continue;
                            int neighbour1=i+di; int neighbour2=j+dj;
                            if(neighbour1>=0 && neighbour1<30 && neighbour2>=0 && neighbour2<30) life+=game[neighbour1][neighbour2];
                        }
                if(life<2 && game[i][j]) temp[i][j]=0;
                else if(life>3 && game[i][j]) temp[i][j]=0;
                else if(life==3 && game[i][j]==0) temp[i][j]=1;
                else temp[i][j]=game[i][j];
                life=0;
            }
}
void copy(int game[30][30], int temp[30][30])
{
    for(int i=0; i<30; i++)
        for(int j=0; j<30; j++)
            game[i][j]=temp[i][j];
}
int main()
{
    srand(time(NULL));
    int game[30][30], temp[30][30], n=1000000;
    population(game);
    do{
        turncheck(game, temp);
        copy(game, temp);
        printGame(game);
        printf("\n\n\n");
        n--;
    } while(n);
}