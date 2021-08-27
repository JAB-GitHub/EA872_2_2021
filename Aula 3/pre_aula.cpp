#include <iostream>
#include <memory>

//Model
class Bloco {
    private: 
        float v, x, m;
    public:
        Bloco(float v_novo, float x_novo);
        float get_v();
        float get_x();
        float get_m();
        
        void set_v(float v_novo);
        void set_x(float x_novo);
};

float Bloco::get_v() {
    return v;
}

float Bloco::get_x() {
    return x;
}

float Bloco::get_m() {
    return m;
}

void Bloco:: set_v(float v_novo) {
    v = v_novo;
}

void Bloco:: set_x(float x_novo) {
    x = x_novo;
}

Bloco::Bloco(float v_novo, float x_novo) {
    v = v_novo;
    x = x_novo;
    m = 1;
}

class Mola {
    private:
        float k, b, T;
    public:
        Mola();   
        float get_k();
        float get_b();
        float get_t();
};


float Mola::get_k() {
    return k;
}

float Mola::get_b() {
    return b;
}

float Mola::get_t(){
    return T;
}

Mola::Mola() {
    k = 1;
    b = 0;
    T = 0.1;
}

//Viwer
class Imprimir{
    private:
        Bloco &bloco;
    public:
        Imprimir(Bloco &bloco);
        void imprimir();
};

Imprimir::Imprimir(Bloco &bloco):
    bloco(bloco)

{
    std::cout << "Está montado o Imprimir!\n";
}

void Imprimir::imprimir(){
    std:: cout << bloco.get_x() << std::endl;
}
//Controler
class Sistema{
    private:
        Mola &mola;
        Bloco &bloco;
    public:
        Sistema(Mola &mola, Bloco &bloco);
        void posicao();

};

Sistema::Sistema(Mola &mola, Bloco &bloco):
    mola(mola),
    bloco(bloco)
{
    std:: cout << "Está montado o Sistema!\n";
}

void Sistema::posicao(){
    float x, f, a, v;
    v = bloco.get_v();
    std:: cout << v << std::endl;
    x = bloco.get_x();
    std:: cout << x << std::endl;

    f = -bloco.get_x()*mola.get_k() - bloco.get_v()*mola.get_b();
    std:: cout << f << std::endl;
    a = f/bloco.get_m();
    std:: cout << a << std::endl;
    v = v + a * mola.get_t();
    std:: cout << v << std::endl;
    x = x + v * mola.get_t();
    std:: cout << x << std::endl;

    bloco.set_v(v);
    bloco.set_x(x);
}


int main() {
    Bloco bloco = Bloco(0, 1);
    Mola mola = Mola();
    Imprimir imprimir = Imprimir(bloco);
    Sistema sistema = Sistema(mola, bloco);

    for (int n = 0; n<100; n++){
        imprimir.imprimir();
    }
        
    return 0;
}
