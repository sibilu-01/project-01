#ifndef IDENTIFIER_H
#define IDENTIFIER_H

#include <string>
using namespace std;

class Identifier {
    private:
        string name;
    public:
        Identifier(string name) {
            this->name = name;
        }
        virtual ~Identifier() {

        }
        string getName() {
            return name;
        }
        virtual int getValue() {
            return 0;
        }
};

class Variable: public Identifier {
    private:
        int value;
    public:
        Variable(string name, int val): Identifier(name), value(val) {}
        ~Variable() override {

        }

        int getValue() override {
            return this->value;
        }
        void setValue(int i) {
            this->value = i;
        }
};

class Label: public Identifier {
    private:
        int index_pos;
    public:
        Label(string name, int index): Identifier(name), index_pos(index) {}
        ~Label() override {

        }

        int getValue() override {
            return this->index_pos;
        }
};

#endif
