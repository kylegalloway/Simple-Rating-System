#include "file_io.h"

FileIO::FileIO(filename)
{
    inputFilename = filename;
    /* outputFilename = re.sub('[a-zA-z0-9]*/*', '', filename); */
}

FILE FileIO::readFile()
{
    println('Reading File...');
    return open(inputFilename, 'r');
}

string[] FileIO::parseLine(line = None)
{
    if (line)
    {
        /* pattern = re.compile(r'(?P<awayTeam>[^0-9]+)(?P<awayScore>[0-9]+)(?P<homeTeam>[^0-9]+)(?P<homeScore>[0-9]+)'); */
        /* game = pattern.search(str(line).strip()); */

        return game;
    }

    return None;
}

void FileIO::printRatings(array, dict)
{
    println("Printing Ratings...");
    newfilename = 'output/Ratings/ratings_' + outputFilename;

    /* with open(newfilename, 'w') as f: */
    /*     spacer = ' ' * 28; */
    /*     f.write(('Rank     Team{0}W-L-T    Rating\n').format(spacer)); */
    /*     count = 1; */
    /*     lyst = []; */
    /*     for team in sorted(dict.keys(),key=lambda team: array[dict[team]].head.getRating(),reverse=True): */
    /*         eam = dict[team]; */
    /*         rating = array[eam].head.getRating(); */
    /*         W = array[eam].head.getWins(); */
    /*         L = array[eam].head.getLosses(); */
    /*         T = array[eam].head.getTies(); */
    /*         team = team.strip(); */
    /*         spacer = ' ' * (32 - len(team)); */
    /*         f.write(('{0}        {1}{2}{3}-{4}-{5}    {6}\n').format(count,team,spacer,W,L,T,round(rating,4))); */
    /*         count += 1; */

    newfilename = 'output/SOS/strofsch_' + outputFilename;

    /* with open(newfilename, 'w') as f: */
    /*     spacer = ' ' * 28; */
    /*     f.write(('Rank     Team{0}W-L-T    Schedule Factor\n').format(spacer)); */
    /*     count = 1; */
    /*     lyst = []; */
    /*     for team in sorted(dict.keys(),key=lambda team: array[dict[team]].head.getScheduleFactor(),reverse=True): */
    /*         eam = dict[team]; */
    /*         schedule_factor = array[eam].head.getScheduleFactor(); */
    /*         W = array[eam].head.getWins(); */
    /*         L = array[eam].head.getLosses(); */
    /*         T = array[eam].head.getTies(); */
    /*         team = team.strip(); */
    /*         spacer = ' ' * (32 - len(team)); */
    /*         f.write(('{0}        {1}{2}{3}-{4}-{5}    {6}\n').format(count,team,spacer,W,L,T,round(schedule_factor,4))); */
    /*         count += 1; */

    println("Done")
}
