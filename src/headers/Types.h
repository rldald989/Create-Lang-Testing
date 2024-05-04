#pragma once

#include "Handling.h"
#include <typeinfo>
#include <algorithm>

template <typename T>

class Type
{
private:
    T m_value;
    std::string m_name;
    int m_scope;
public:
    Type(const T& value, const char* name, int scope) : m_value(value), m_name(name), m_scope(scope)
    {
        
    }

    ~Type()
    {

    }

    T GetValue(){
        return m_value;
    }
    
    std::string GetName(){
        return m_name;
    }

};


struct Identifier{
    std::string name;
    int line;
};


template <typename V>
void VariableAdder(std::vector<Type<V>>& VARIABLES, std::vector<Identifier>& identifiers, const char* variable_type_name, Console<std::string>& console, Handler& handler)
{
    for(int i = 0; i < identifiers.size(); i++){
        if(identifiers[i].name == variable_type_name){
            //console.Out("variable found", 1);
            handler.CollectLog(Log{DEBUG, "variable found"});
            if(identifiers[i + 2].name == "="){
                if (std::is_same<V, int>::value)
                {
                    VARIABLES.push_back(Type<V>(std::atoi(identifiers[i + 3].name.c_str()), identifiers[i + 1].name.c_str(), 0));
                }
                else if (std::is_same<V, float>::value)
                {
                    VARIABLES.push_back(Type<V>(std::atof(identifiers[i + 3].name.c_str()), identifiers[i + 1].name.c_str(), 0));
                }
                else if(std::is_same<V, bool>::value){
                    if(identifiers[i + 3].name == "true" || identifiers[i + 3].name == "1"){
                        VARIABLES.push_back(Type<V>(true, identifiers[i + 1].name.c_str(), 0));
                    }
                    else if(identifiers[i + 3].name == "false" || identifiers[i + 3].name == "0"){
                        VARIABLES.push_back(Type<V>(false, identifiers[i + 1].name.c_str(), 0));
                    }
                    else{
                        handler.CollectLog(Log{ERROR, ("Variable " + identifiers[i + 1].name + " defined incorrectly or undefined.")});
                    }
                }
                
                
            }
            else{
                handler.CollectLog(Log{ERROR, "ERROR: identifier \"=\" not found"});
                //console.Out("ERROR: identifier \"=\" not found", 1);
            }
        }
    }

    //for(int j = 0; j < VARIABLES.size(); j++){
    //    if(identifiers[i].name == VARIABLES[j].GetName()){
    //        console.Out(std::string("ERROR: Redefinition of variable ") + VARIABLES[j].GetName() + " not allowed.", 1);
    //    }
    //}

}

template <typename R>
void FindRedefinition(std::vector<Type<R>>& VARIABLES, Console<std::string>& console, Handler& handler)
{
    for (size_t i = 0; i < VARIABLES.size(); i++)
    {
        for(size_t j = 0; j < i; j++){
            if(VARIABLES[j].GetName() == VARIABLES[i].GetName())
            {
                handler.CollectLog(Log{ERROR, std::string("ERROR: Redefinition of variable ") + VARIABLES[i].GetName() + " not allowed."});
                //console.Out(std::string("ERROR: Redefinition of variable ") + VARIABLES[i].GetName() + " not allowed.", 1);
            }
        }
    }
    
}
    
bool CompareTypes(Type<float>& a, Type<int>& b)
{
    if(a.GetName() == b.GetName()){
        return false;
    }
    else{
        return true;
    }
}
