#ifndef PS_HOMECINEMA_H
#define PS_HOMECINEMA_H
#include "CinemaSystem.h"


class HomeCinema {
private:
    Projector projector_;
    Sound sound_;
    Light light_;
public:
    void startMovie() const;
    void endMovie() const;
};


#endif //PS_HOMECINEMA_H