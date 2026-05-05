#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include <iostream>
#include <string>

#include "ShapeManager.hpp"
enum Command {
    Add, List, Delete, Contains, Perimeter, Area, Load, Invalid
};

class CommandParser {
private:
    ShapeManager& mgr;

public:
    CommandParser(ShapeManager& m);

    Command stringToCommand(const std::string& command);
    void handle(const std::string& line);
};

#endif
