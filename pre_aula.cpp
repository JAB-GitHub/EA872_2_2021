#include <iostream>
#include <memory>

class coord{
   private:
      int x, y;

   public:
      coord(); //Nosso construtor

      void coord_new(int new_x, int new_y);
};

class cube{
   private:
      int x, y, z;

   public:
      cube(); //Nosso construtor

      void cube_new(int new_x, int new_y, int new_z);
      
      void cube_print_volume();
};

//Vamos inicializar os nossos objetos com os valores zerados
coord::coord(){
   x = 0;
   y = 0;
}

cube::cube(){
   x = 0;
   y = 0;
   z = 0;
}

//defindo as nossas métricas
void coord::coord_new(int new_x, int new_y){
   x = new_x;
   y = new_y;
}

void cube::cube_new(int new_x, int new_y, int new_z){
   x = new_x;
   y = new_y;
   z = new_z;
}

void cube::cube_print_volume(){
   std::cout << x*y*z << std::endl;   
}

int main(){
   std::unique_ptr<coord> c1 (new coord);
   std::unique_ptr<cube> c2 (new cube);

   c1->coord_new(50,10);
   c2->cube_new(10,20,30);
   c2->cube_print_volume();


   return 0;
}
