#include <vector>
#include <string>

using std::string;
using std::vector;

class HtmlMaker 
{
    public:
        static void MakeHtmlFile(const vector<vector<string>>& tokenizedFile, const string& fileName);
    private:
        static void MakeHtmlFile(const string& tableData, const string& fileName);
        static string MakeTableData(const vector<vector<string>>& tokenizedFile);
        

};