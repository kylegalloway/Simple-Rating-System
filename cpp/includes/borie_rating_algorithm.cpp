#include <string>
using namespace std;

#define ITERATIONS 5000

class RatingAlgorithm
{

    public:
        int improveScores(int scoreDiff)
        {
            if (scoreDiff < 0)
            {
                if (scoreDiff > -3) { scoreDiff = -3; }
                elif (scoreDiff < -28) { scoreDiff = -28; }
                scoreDiff += -7;
            }
            elif (scoreDiff > 0)
            {
                if (scoreDiff < 3) { scoreDiff = 3; }
                elif (scoreDiff > 28) { scoreDiff = 28; }
                scoreDiff += 7;
            }

            return scoreDiff;
        }

        string[] rateTeams(string[] array, Dict dict)
        {
            int i, j;
            for (i = 0; i < len(array); i++)
            {
                place = array[i].head.next;
                total = 0;
                count = 0;
                W = 0;
                L = 0;
                T = 0;

                while (place != NULL)
                {
                    scoreDiff = place.getScoreDiff();

                    if (scoreDiff > 0) { W += 1; }
                    elif (scoreDiff < 0) { L += 1; }
                    else { T += 1; }

                    total += scoreDiff;
                    count += 1;
                    place = place.next;
                }

                /* TODO: Make sure not integer division! */
                avg = total / count;
                array[i].head.setPerformance(avg);
                array[i].head.setRating(avg);
                array[i].head.setWins(W);
                array[i].head.setLosses(L);
                array[i].head.setTies(T);

            for (i = 0; i < this->ITERATIONS; i++)
            {
                for (j = 0; j < len(array); j++)
                {
                    place = array[j].head.next;
                    total = 0;
                    count = 0;
                    while (place != NULL)
                    {
                        team2 = dict[place.getTeam2()];
                        total += array[team2].head.getRating();
                        count += 1;
                        place = place.next;
                    }

                    avg = total / count;
                    array[j].head.setScheduleFactor(avg);
                }

                for (j = 0; j < len(array); j++)
                {
                    performance = array[j].head.getPerformance();
                    scheduleFactor = array[j].head.getScheduleFactor();
                    newRating = performance + scheduleFactor;
                    array[j].head.setRating(newRating);
                }
            }

            return array;
        }
}