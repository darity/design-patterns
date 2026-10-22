#ifndef PS_SINGLETON_H
#define PS_SINGLETON_H
#include <iostream>
#include <string>


class Singleton {
private:

    int numOfMessages;
    static Singleton* instance;
    Singleton(): numOfMessages(0){}

public:

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* getInstance();
    void log(std::string message);
};

#endif //PS_SINGLETON_H