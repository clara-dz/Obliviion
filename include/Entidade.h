#pragma once

#include "Ente.h"


class Entidade : public Ente {
    protected:
        int x;
        int y;

    public:
        Entidade();
        Entidade(int x, int y);
        virtual ~Entidade();

        // virtual void initBackground();
        // virtual void updateEvents();

        int getX() const;
        int getY() const;
        void setX(int x);
        void setY(int y);
};