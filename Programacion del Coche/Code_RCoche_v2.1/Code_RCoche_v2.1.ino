
#include <NewPing.h>

     #define TRIGGER_PIN 13  
     #define ECHO_PIN 2    
     #define MAX_DISTANCE 200
     
     /*
      * Hasta ahora habíamos visto que podíamos definir una variable como int, por ejemplo, 
      * y también como una constante (const int pin). 
      * Aquí utilizamos otro método, el #define que es una directiva para el compilador.

      Esto solo significa que el compilador (en rigor el pre procesador) cambiará todas las ocurrencias de estos 
      #define en nuestro programa por su valor antes de compilar. 
      Esta es la forma clásica de C de hacer esto y tiene la virtud de que no ocupa memoria definiendo una variable 
      (y con un Arduino UNO, que va muy corto de memoria, esto puede ser crítico en ocasiones).
      */
     
     NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // Iniciamos la librería
 
     void setup() 
        {
           Serial.begin(115200); // Iniciamos el Monitor Serial para poder ver los datos.
           Serial.println("Serial test!"); // Test the Serial communication
                    
        }
 
     void loop()
       {
           delay(50); 
           unsigned int uS = sonar.ping(); //  Medimos la distancia
           Serial.print("Ping: ");  // Mostramos los datos recibidos por el Monitor Serial
           Serial.print(uS / US_ROUNDTRIP_CM); 
           Serial.println("cm");
       }
