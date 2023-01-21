#include <iostream>
#include <vector>
#include <string>
#include "FileLoader.h"
#include "HtmlMaker.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
    vector<vector<string>> tokenizedFile = FileLoader::ReadFileIntoTokens("words.csv");

    HtmlMaker::MakeHtmlFile(tokenizedFile, "woo.html");

    return 0;
}