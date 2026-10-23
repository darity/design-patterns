#ifndef PS_DRINKBAR_H
#define PS_DRINKBAR_H


class Beverage {
public:
    virtual ~Beverage(){}
    //Template Method: the order of steps is fixed
    void prepare();

protected:
    static void boilWater();
    static void pourIntoCup();
    virtual void brew() = 0;
    virtual void addCondiment() = 0;
};

class Tea final: public Beverage {
protected:
    void brew() override;
    void addCondiment() override;
};

class Coffee final: public Beverage {
protected:
    void brew() override;
    void addCondiment() override;
};

#endif //PS_DRINKBAR_H