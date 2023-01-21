#include "FileLoader.h"

vector<vector<string>> FileLoader::ReadFileIntoTokens(const string &fileName)
{
    return TokenizeLines(ReadAllLines(fileName));
}

vector<string> FileLoader::ReadAllLines(const string &fileName)
{
    vector<string> fileAsLines;

    std::ifstream input(fileName);

    string line;

    while (std::getline(input, line))
    {
        fileAsLines.push_back(line);
    }

    return fileAsLines;
}

void FileLoader::WriteAllLines(const vector<string> &linesToWrite, const string& fileName)
{
    std::ofstream output(fileName);

    if(output.is_open())
    {
        for (const string& line : linesToWrite)
            output << line << '\n';

        output.close();
    }

    return;
}

vector<vector<string>> FileLoader::TokenizeLines(const vector<string> &linifiedFile)
{
    vector<vector<string>> tokenizedResult;
    string currentLine;
    vector<string> currentLineTokens;

    for (size_t i = 0; i < linifiedFile.size(); ++i)
    {
        currentLineTokens.clear();
        currentLine = linifiedFile[i];

        for (size_t i = 0; i < currentLine.length(); ++i)
        {
            if (currentLine[i] != ',')
                continue;

            currentLineTokens.push_back(currentLine.substr(0, i));
            currentLine = currentLine.substr(i + 1);
            i = 0;
        }

        if (currentLine.find('\n') != string::npos)
            currentLine.erase(currentLine.end() - 1);
        if (currentLine.find('\r') != string::npos)
            currentLine.erase(currentLine.end() - 1); 

        currentLineTokens.push_back(currentLine);
        tokenizedResult.push_back(currentLineTokens);
    }

    return tokenizedResult;
}
