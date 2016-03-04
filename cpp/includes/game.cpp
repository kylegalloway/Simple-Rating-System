class Game
{
/*
    def __init__(self, team2, scoreDiff, next = None):
        self._team2 = team2
        self._scoreDiff = scoreDiff
        self.next = next
*/
    private:
        /* String or Team?? */
        String team2;
        int scoreDiff;
        String next;

    public:
        String getTeam2(this)
        {
            return this._team2
        }

        int getScoreDiff(this)
        {
            return self._scoreDiff
        }
};