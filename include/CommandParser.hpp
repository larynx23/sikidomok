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

    Command stringToCommand(const std::string& command);
    void handle(const std::string& line);
};

enum Command {
    Add, List, Delete, Contains, Perimeter, Area, Load, Invalid
};

#endif
