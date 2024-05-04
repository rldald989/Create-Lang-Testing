#include <iostream>
#include <string>
#include <vector>

template <typename T>

class Console
{
private:
    T m_console_name;
    std::vector<T*> m_ins;

public:
    // Constructor
    Console(const T& name) : m_console_name(name)
    {

    }
    // Destructor
    ~Console(){
        for(auto& i : m_ins){
            delete i;
        }
    }

    // Basic out function with no new line
    void Out(const T& input)
    {
        std::cout << m_console_name << ": " << input;
    }

    // Basic out function that allows you to specify the amount of new lines you want
    void Out(const T& input, int new_lines)
    {
        std::cout << m_console_name << ": " << input;
        for(int i = 0; i < new_lines; i++){
            std::cout << std::endl;
        }
    }

    // Basic In function
    void In(T& input)
    { 
        std::cout << m_console_name << ": ";
        std::cin >> input;
    }

    // In function that allows you to create and store inputs within the console
    void In(int index)
    { 
        if(index + 1 > m_ins.size()){
            while(index + 1 > m_ins.size())
                m_ins.push_back(new T());
        }
        std::cout << m_console_name << ": ";
        std::cin >> *m_ins[index];
    }

    T GetIn(int index){
        return *m_ins[index];
    }
};