#include "HtmlMaker.h"
#include "FileLoader.h"

namespace 
{
    string MakeTableHeaderString(const vector<string>& headerRow) 
    {
        string tableHeaderOutput = "<tr>";
        
        for (size_t column = 0; column < headerRow.size(); ++column)
            tableHeaderOutput += "<th onclick=\"sortTable(" + std::to_string(column) + ")\">" + headerRow[column] + "</th>";
        
        tableHeaderOutput += "</tr>";

        return tableHeaderOutput;
    }

    string MakeTableDataRowString(const vector<string>& dataRow) 
    {
        string output;
        output += "<tr>";
        
        for (size_t column = 0; column < dataRow.size(); ++column) 
            output += "<td>" + dataRow[column] + "</td>";

        output += "</tr>";
        
        return output;
    }    

    void InsertDataAfterTag(vector<string>& htmlToInsertInto, const string& tag, const string& data) 
    {
        for (size_t lineNumber = 0; lineNumber < htmlToInsertInto.size(); ++lineNumber)
        {
            if (htmlToInsertInto[lineNumber].find(tag) == string::npos)
                continue;
                
            htmlToInsertInto.insert(htmlToInsertInto.begin() + lineNumber + 1, data);
            break;
        }


        return;
    }
};

void HtmlMaker::MakeHtmlFile(const vector<vector<string>> &tokenizedFile, const string &fileName)
{
    MakeHtmlFile(MakeTableData(tokenizedFile), fileName);
    return;
}

void HtmlMaker::MakeHtmlFile(const string &tableData, const string &fileName)
{   
    vector<string> fileAsLines = FileLoader::ReadAllLines("SortableIndexPageTemplate.html");

    InsertDataAfterTag(fileAsLines, "INSERTION_POINT_TABLE", tableData);

    FileLoader::WriteAllLines(fileAsLines, fileName);
}

string HtmlMaker::MakeTableData(const vector<vector<string>> &tokenizedFile)
{
    string htmlOutput = "";
    htmlOutput += MakeTableHeaderString(tokenizedFile[0]);

    for (size_t row = 1; row < tokenizedFile.size(); ++row)
        htmlOutput += MakeTableDataRowString(tokenizedFile[row]);

    return htmlOutput;
}


