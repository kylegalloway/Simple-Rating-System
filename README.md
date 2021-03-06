Operational notes in each language's README.md file.

Only tested on Linux/OSX.

# Simple Rating System

### Some Links to explanations of how it works
* http://www.pro-football-reference.com/blog/?p=37
* http://smartfootball.com/chase-stuart/the-simple-rating-system-bringing-order-kinda-to-chaos#sthash.3yVxxp8E.dpbs
* http://www.footballperspective.com/category/srs/
* http://fivethirtyeight.com/tag/simple-rating-system/
* http://www.sports-reference.com/blog/2015/03/srs-calculation-details/

I used an adjusted simple rating system.

1. I took each team's score difference for each game and applied some adjustements
  * Any scores with a difference of less than 3 or more than 28 were changed to 3 and 28 respectively (or -3 and -28).
  * If a team won, they were given an extra 7 points; If a team lost, they were given an extra -7 points.
2. I added a schedule factor to each team.
  * The schedule factor was determined by adding the ratings of all of their past competitors ratings.

Finally, this adjustment is iterated over 5000 times (Starts to converge really smoothly at ~3000-4000), to allow the ratings to level out.

Each team’s rating is simply the sum of their (adjusted) margin of victory (MOV) and their sum of their opponent’s average (adjusted) MOV.
The SRS puts equal weight on all games, something the brain is not good at doing.

It takes a bit to run on the larger files.

The final results are not perfect. So if you have any ideas on how to improve it please submit an issue/pull request.

# Elo Rating System
Coming soon!
