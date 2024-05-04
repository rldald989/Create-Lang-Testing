#include "CuIO.h"

enum LogLevel{
    ERROR,
    WARNING,
    DEBUG
};

struct Log
{
    LogLevel log_level;
    std::string message;
};

class Handler
{
private:
    std::vector<Log> m_logs;
    Console<std::string> m_log_manager_console;
public:
    Handler() : m_log_manager_console("App")
    {

    }
    ~Handler()
    {

    }

    
    void CollectLog(Log _log)
    {
        m_logs.push_back(_log);
    }

    void LogCollected()
    {
        for(auto& i : m_logs)
        {
            if(i.log_level == ERROR){
                m_log_manager_console.Out("ERROR: " + i.message, 1);
            }
            if(i.log_level == WARNING){
                m_log_manager_console.Out("WARNING: " + i.message, 1);
            }
            if(i.log_level == DEBUG){
                m_log_manager_console.Out("DEBUG: " + i.message, 1);
            }
        }
    }
};