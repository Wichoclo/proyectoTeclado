#include <Keypad.h>

const byte FILAS = 4;     // define numero de filas

const byte COLUMNAS = 4;    // define numero de columnas

char keys[FILAS][COLUMNAS] = { // define la distribucion de teclas

  {'1','2','3','A'},

  {'4','5','6','B'},

  {'7','8','9','C'},

  {'*','0','#','D'}

};



//byte pinesFilas[FILAS] = {12,11,10,9};   // pines correspondientes a las filas

//byte pinesColumnas[COLUMNAS] = {8,7,6,5}; // pines correspondientes a las columnas

byte pinesFilas[FILAS] = {9,8,7,6};   // pines correspondientes a las filas
byte pinesColumnas[COLUMNAS] = {5,4,3,2}; // pines correspondientes a las columna

Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS);  // crea objeto



char TECLA;char TECLANOVA;       // almacena la tecla presionada

char* TECLA_ESPECIAL;//teclas especiales esc shift crl

int contador;



  

void setup()

{

 Serial.begin(9600);      // inicializa comunicacion serie

}



void loop(){

  TECLA = teclado.getKey();   // obtiene tecla presionada y asigna a variable
  /*************************** teclado matriz-alfanumerico*********************/
  if (TECLA) {
  contador=0;

    for (int i=0;i<100;i++){

      TECLANOVA = teclado.getKey();

      if(TECLANOVA){

       if( TECLANOVA == TECLA){

          contador++;

          if (contador>3)contador=0;

          i=0;

       }

       else break;

      }

      delay(10);

    }

        if(contador!=0){//si se preciono almenos una ves una tecla

                switch (TECLA){

                case '0':

                  (contador==1)?

                    (TECLA='_')://espacio

                      (TECLA='0');

                  break;

                case '1':

                  (contador==1)?

                    (TECLA='a'):

                      ((contador==2)?

                        (TECLA='b'):

                          (TECLA='c'));

                  break;

                case '2':

                  (contador==1)?

                    (TECLA='d'):

                      ((contador==2)?

                        (TECLA='e'):

                          (TECLA='f'));

                  break;

                case '3':

                  (contador==1)?

                    (TECLA='g'):

                      ((contador==2)?

                        (TECLA='h'):

                          (TECLA='i'));

                  break;

                case '4':

                  (contador==1)?

                    (TECLA='j'):

                      ((contador==2)?

                        (TECLA='k'):

                          (TECLA='l'));

                  break;

                  case '5':

                  (contador==1)?

                    (TECLA='m'):

                      ((contador==2)?

                        (TECLA='n'):

                          (TECLA='ñ'));

                  break;

                  case '6':

                  (contador==1)?

                    (TECLA='o'):

                      ((contador==2)?

                        (TECLA='p'):

                          (TECLA='q'));

                  break;

                  case '7':

                  (contador==1)?

                    (TECLA='r'):

                      ((contador==2)?

                        (TECLA='s'):

                          (TECLA='t'));

                  break;

                  case '8':

                  (contador==1)?

                    (TECLA='u'):

                      ((contador==2)?

                        (TECLA='v'):

                          (TECLA='w'));

                  break;

                  case '9':

                  (contador==1)?

                    (TECLA='x'):

                      ((contador==2)?

                        (TECLA='y'):

                          (TECLA='z'));

                  break;

                }

          }
          Serial.println(TECLA);
  }
  
        
}
