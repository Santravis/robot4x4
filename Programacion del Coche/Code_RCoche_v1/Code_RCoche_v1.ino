
#include <AFMotor.h>     // Llama a la librería del Shield L293D

/*  <--motor        <-- motor 2

    <--motor        <-- motor 1
*/

AF_DCMotor motor1(1); // Motor 1 - Delante Derecha conectado al Puerto 1
AF_DCMotor motor2(2); // Motor 2 - Delante Izquierda conectado al Puerto 2
AF_DCMotor motor3(3); // Motor 3 - Atrás Izquierda conectado al Puerto 3
AF_DCMotor motor4(4); // Motor 4 - Atrás Derecha conectado al Puerto 4


void setup() {

  Serial.begin(9600);
  motor1.setSpeed(60); // Configura velocidad motor1 a 180 (de 0 (stop) a 255 (fast)
  motor2.setSpeed(60); // Configura velocidad motor2 a 180 (de 0 (stop) a 255 (fast)
  motor3.setSpeed(60); // Configura velocidad motor3 a 180 (de 0 (stop) a 255 (fast)
  motor4.setSpeed(60); // Configura velocidad motor4 a 180 (de 0 (stop) a 255 (fast)

}


void TodoParado() {      // Hace que el robot este PARADO
//  motor1.run(RELEASE);  // Motor 1 - Delante Derecha
//  motor2.run(RELEASE);  // Motor 2 - Delante Izquierda
//  motor3.run(RELEASE);  // Motor 3 - Atrás Izquierda
//  motor4.run(RELEASE);  // Motor 4 - Atrás Derecha
}
void TodoAvance() {   // Hace que el robot AVANCE
 /*  <--motor 3 BACKWARD       <-- motor 2 BACKWARD

     <--motor 4 BACKWARD       <-- motor 1 FORWARD
*/ 
  
 //motor1.run(FORWARD);  // Motor 1 - Delante Derecha
 //motor2.run(BACKWARD);  // Motor 2 - Delante Izquierda
 //motor3.run(BACKWARD);  // Motor 3 - Atrás Izquierda
 motor4.run(BACKWARD);  // Motor 4 - Atrás Derecha
 Serial.println("Hacia Adelante"); // Escribe en el monitor serial
}
void GirarDerecha() {    // Hace que el robot gire a la DERECHA
/*  <--motor 3 BACKWARD       <-- motor 2 BACKWARD

    <--motor 4 FORWARD        <-- motor 1 FORWARD
*/

  //motor1.run(BACKWARD);  // Motor 1 - Delante Derecha
  //motor2.run(BACKWARD); // Motor 2 - Delante Izquierda
  //motor3.run(BACKWARD); // Motor 3 - Atrás Izquierda
  //motor4.run(FORWARD);  // Motor 4 - Atrás Derecha
  delay(1600);          // Tiempo requerido para girar a la DERECHA 1.6 seg.
  Serial.println("Girando a la Derecha"); // Escribe en el monitor serial
}
void MarchaAtras() {        // Hace que el robot vaya marcha ATRÁS
/*  <--motor 3 FORWARD       <-- motor 2 FORWARD

    <--motor 4 FORWARD       <-- motor 1 FORWARD
*/
  motor1.run(FORWARD);  // Motor 1 - Delante Derecha
  motor2.run(FORWARD);  // Motor 2 - Delante Izquierda
  motor3.run(FORWARD);  // Motor 3 - Atrás Izquierda
  motor4.run(FORWARD);  // Motor 4 - Atrás Derecha
  delay(1600);           // Tiempo requerido para poner marcha ATRÁS 1.6 seg.
  Serial.println("Marcha Atrás"); // Escribe en el monitor serial
}
void GirarIzquierda() {      // Hace que el robot gire a la IZQUIERDA
  motor1.run(BACKWARD);  // Motor 1 - Delante Derecha
  motor2.run(FORWARD);   // Motor 2 - Delante Izquierda
  motor3.run(FORWARD);   // Motor 3 - Atrás Izquierda
  motor4.run(BACKWARD);  // Motor 4 - Atrás Derecha
  delay(1600);           // Tiempo requerido para girar a la IZQUIERDA 1.6 seg.
  Serial.println("Girando a la Izquierda");// Escribe en el monitor serial
}

void loop(){

TodoAvance();
delay(1000);

//GirarDerecha();
//delay(1000);

//MarchaAtras();
//delay(500);
//GirarIzquierda();
//delay(500);

  
  }
