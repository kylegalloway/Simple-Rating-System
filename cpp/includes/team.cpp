class Team
{
/*
    def __init__(self,name,next = None):
        self._name = name
        self._rating, self._performance, self._scheduleFactor = 0.0, 0.0, 0.0
        self._wins, self._losses, self._ties = 0, 0, 0
        self.next = next
*/
    private:
        String name;
        double rating;
        double performance;
        double scheduleFactor;
        int wins;
        int losses;
        int ties;
        String next;

    public:
        String getTeam(this) { return this.name; }
        double getRating(this) { return this.rating; }
        double getPerformance(this) { return this.performance; }
        double getScheduleFactor(this) { return this.scheduleFactor; }
        int getWins(this) { return this.wins; }
        int getLosses(this) { return this.losses; }
        int getTies(this) { return this.ties; }

        void setRating(this, rating) { this.rating = rating; }
        void setPerformance(this, performance) { this.performance = performance; }
        void setScheduleFactor(this, factor) { this.scheduleFactor = factor; }
        void setWins(this, wins) { this.wins = wins; }
        void setLosses(this, losses) { this.losses = losses; }
        void setTies(this, ties) { this.ties = ties; }
}