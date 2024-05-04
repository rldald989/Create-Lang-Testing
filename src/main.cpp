#include "headers/Types.h"
#include <fstream>
#include <vector>



int main(){
    Console<std::string> console("Console");
    Handler handler;

    std::ifstream file;
    std::string temp;
    std::vector<Identifier> identifiers;
    file.open("main.gcrt");

    std::vector<Type<int>> INTS;
    std::vector<Type<float>> FLOATS;
    std::vector<Type<bool>> BOOLS;
    std::vector<Type<std::string>> STRINGS;

    int line = 0;

    while(file >> temp >> std::ws)
    {
        if(temp == "\0"){
            
        }
        else
        {
            identifiers.push_back(Identifier{temp, line}); 
        }
    }

    file.close();

    VariableAdder<int>(INTS, identifiers, "int", console, handler);
    VariableAdder<float>(FLOATS, identifiers, "float", console, handler);
    VariableAdder<bool>(BOOLS, identifiers, "bool", console, handler);

    for(int i = 0; i < identifiers.size(); i++){
        //if(identifiers[i].name == "int"){
        //    console.Out("int found", 1);
        //    if(identifiers[i + 2].name == "="){
        //        INTS.push_back(Type<int>(std::atoi(identifiers[i + 3].name.c_str()), identifiers[i + 1].name.c_str(), 0));
        //    }
        //    else{
        //        console.Out("ERROR: identifier \"=\" not found", 1);
        //    }
        //}
        
    }

    FindRedefinition<int>(INTS, console, handler);
    FindRedefinition<float>(FLOATS, console, handler);
    FindRedefinition<bool>(BOOLS, console, handler);

    //TODO: make functions

    for(auto& i : INTS){
        console.Out(i.GetName() + std::string(": ") + std::to_string(i.GetValue()).c_str(), 1);
    }

    for(auto& i : FLOATS){
        console.Out(i.GetName() + std::string(": ") + std::to_string(i.GetValue()).c_str(), 1);
    }

    for(auto& i : BOOLS){
        console.Out(i.GetName() + std::string(": ") + std::to_string(i.GetValue()).c_str(), 1);
    }

    for(auto& i : STRINGS){
        console.Out(std::string(i.GetName()) + std::string(": ") + i.GetValue(), 1);
    }

    handler.LogCollected();

    return 0;
}