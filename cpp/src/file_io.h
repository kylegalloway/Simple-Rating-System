#pragma once

/* import re */

class FileIO
{
    FileIO(string Filename);

public:
    FILE readfile();
    string[] parseLine(string line = None);
    void printRatings(string[] array, Dict dict);
};
