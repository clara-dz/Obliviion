#include "Ente.h"
#include "Game.h"

class Menu : public Ente {

    private:
    Game* pJog;

    public:
    Menu();
    ~Menu();

    void executar();
};