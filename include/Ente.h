#pragma once

class Ente {
    protected:
        int id;
        static int id_count;
        // static *Gerenciador_Grafico PGG;
        // *Figura pFig;
    
    public:
        Ente();
        virtual ~Ente();

        virtual void executar() = 0;
        virtual void desenhar() = 0;
        // void static setGG(pG *Gerenciador_Grafico);
};
