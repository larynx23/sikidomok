#include <CommandParser.hpp>

CommandParser::CommandParser(ShapeManager& m) : mgr(m) {}

Command CommandParser::stringToCommand(const std::string& command) {
    if (command == "add") return Add;
    if (command == "list") return List;
    if (command == "delete") return Delete;
    if (command == "contains") return Contains;
    if (command == "perimeter" || command == "p") return Perimeter;
    if (command == "area" || command == "a") return Area;
    if (command == "load") return Load;

    return Invalid;
}

void CommandParser::handle(const std::string& line) {
    std::string command = line.substr(0, line.find(' '));
    switch (stringToCommand(command))
    {
    case Add:
        // TODO
        break;
    
    case List:
        // TODO
        break;
    
    case Delete:
        // TODO
        break;
    
    case Contains:
        // TODO
        break;
    
    case Perimeter:
        // TODO
        break;
    
    case Area:
        // TODO
        break;
    
    case Load:
        // TODO
        break;

    case Invalid:
        // TODO
        break;
    
    default:
        break;
    }
}