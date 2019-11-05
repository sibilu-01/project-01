#include "Program.h"
#include <typeinfo>
using namespace std;

//Compiles the input json.
void Program::compile(string filename) {
    ifstream file;
    string line;
    cout << "Opening file " << filename << ".\n";
    file.open(filename);
    if(file.is_open()) {
        cout << "File Opened.\n";
        QJsonObject compiled;
        QJsonObject jsonStats;
        QJsonObject jsonLabelIdentifiers;
        int index = 0;
        while(getline(file, line)) {
            //ADD SYNTAX CHECKER
            size_t words = 0;
            string* arr = splitString(line, words);
            Statement* stat;
            string firstarg = arr[0];
            
            // Cuts the label out of the line and adds it to the list of identifiers as well as the line it exists at.
            if(firstarg.back() == ':') {
                firstarg.pop_back();
                jsonLabelIdentifiers.insert(QString::fromStdString(firstarg), index);
                firstarg = arr[1];
                line = arr[1];
                for(int i = 2; i < words; i++) {
                    line += " " + arr[i];
                }
                words--;
            }

            if(firstarg == "dci") {
                if(words > 2) {
                    cout << "SYNTAX ERROR: Too many arguments.";
                } else {
                    stat = new DeclIntStmt();
                }
            } else if(firstarg == "rdi") {

            } else if(firstarg == "prt") {

            } else if(firstarg == "cmp") {

            } else if(firstarg == "jmr") {

            } else if(firstarg == "jmp") {

            } else if(firstarg == "end") {

            } else if(firstarg[0] == "#") {
                continue;
            } else {
                cout << "SYNTAX OF LINE INCORRECT: " << line;
                break;
            }

            jsonStats.insert(QString::number(index), stat->compile(line));
            index++;
        }
        compiled.insert("objects", jsonStats);
        compiled.insert("labels", jsonLabelIdentifiers);

        QJsonDocument doc(compiled);
        QFile jsonFile("example.json");
        jsonFile.open(QFile::WriteOnly);
        jsonFile.write(doc.toJson(QJsonDocument::Indented));

        file.close();
    }
}

void Program::execute() {

}

void Program::print() {

}

// cuts up a string of unknown size into parts.
string* Program::splitString(string str, size_t& size) {
    string toParse = str;

    size = 0;
    stringstream ssin(str);

    while(ssin >> str) {
        ++size;
    }

    string *arr = new string[size];
    stringstream ssin2(toParse);
    int i = 0;
    while (i < size){
        ssin2 >> arr[i];
        ++i;
    }

    return arr;
}
