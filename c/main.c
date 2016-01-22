#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define K_VALUE 16
#define HF_ADV 65

struct
team
{
    char[100] name;
    double rating;
    int num_of_games;
    int wins;
    int losses;
    int ties;
}

int
main()
{
    FILE *ptr_file;
    char buf[1000];

    ptr_file = fopen("input.txt","r");
    if (!ptr_file)
        return 1;

    while (fgets(buf,1000,ptr_file)!=NULL)
        printf("%s",buf);

    fclose(ptr_file);
    return 0;
}

void
play_game(team1, team2, scorediff)
{
    int elo_diff1 = team1.rating - team2.rating;
    int elo_diff2 = team2.rating - team1.rating;
    double AMOV1 = log(fabs(scorediff + 1)) * (2.2 / (elo_diff1 * 0.001 + 2.2));
    double AMOV2 = log(fabs(-(scorediff + HF_ADV) + 1)) * (2.2 / (elo_diff2 * 0.001 + 2.2));
    int r1 = team1.rating + K_VALUE * (AMOV1);
    int r2 = team2.rating + K_VALUE * (AMOV2);
}
