#include "Statement.h"

jmrStmt::jmrStmt(): varName("") {}
jmrStmt::jmrStmt(Operand in): varName(in) {}

void jmrStmt::run() {

}

QJsonObject jmrStmt::compile(Program *program, string instr) {
    string *arr = Program::splitString(instr);

    QJsonObject statementObject;
    statementObject.insert("stmt", QString::fromStdString(arr[0]));
    statementObject.insert("op1", QString::fromStdString(arr[1]));
    program->jsonVariableIdentifiers.insert(QString::fromStdString(arr[1]), 0);

    return statementObject;
}
