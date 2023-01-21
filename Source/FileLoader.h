#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using std::string;
using std::vector;

class FileLoader
{
    public:
        static vector<vector<string>> ReadFileIntoTokens(const string& fileName);
        static vector<string> ReadAllLines(const string& fileName);
        static void WriteAllLines(const vector<string>& linesToWrite, const string& fileName);
    private:
        static vector<vector<string>> TokenizeLines(const vector<string>& linifiedFile);
};