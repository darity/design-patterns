#ifndef PS_SINGLETON_H
#define PS_SINGLETON_H
#include <iostream>
#include <string>


class Logger {
private:

    int numOfMessages;
    static Logger* instance;
    Logger(): numOfMessages(0){}

public:

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    static Logger* getInstance();
    void log(std::string message);
};

#endif //PS_SINGLETON_H