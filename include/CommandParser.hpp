#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include <iostream>
#include <string>

#include "ShapeManager.hpp"

class CommandParser {
private:
    ShapeManager& mgr;

public:
    CommandParser(ShapeManager& m);

    void handle(const std::string& line);

    friend std::istream& operator>>(std::istream& is, CommandParser& parser);
};

#endif
