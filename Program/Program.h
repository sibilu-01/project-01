#ifndef PROGRAM_H
#define PROGRAM_H

#include <string>
#include <QJsonObject>
#include <QJsonDocument>



// Identifiers
#include "Program/Identifier.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <QFile>
#include <iterator>
#include <map>

class Statement;
class Program {
    private:
        std::map<std::string, Identifier*> identifier;
        std::map<int, Statement*> statements;
        std::string filename;
        int comparisonFlag;
        int error_code = 0;
        int index = 0;
        bool executing = false;
    public:
        Program();
        Program(std::string);
        ~Program();
        bool is_number(std::string);
        std::vector<std::string> splitString(std::string);
        std::string compile();
        void execute();
        void print();

        Identifier* getIdentifier(std::string);
        bool identifierExists(std::string);
        void addIdentifier(Identifier*);

        void setIndex(int);

        int getComparison();
        void setComparison(int);

        bool getExecuting();
        void setExecuting(bool);

        Statement* getStatement(int);
        void addStatement(int, Statement*);
};

#endif
