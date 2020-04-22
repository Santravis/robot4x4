void GirarDerecha() {      // Hace que el robot gire a la IZQUIERDA
motor1.run(FORWARD);  // Motor 1 - Delante Derecha
motor2.run(BACKWARD);   // Motor 2 - Delante Izquierda
motor3.run(BACKWARD);   // Motor 3 - Atrás Izquierda
motor4.run(FORWARD);  // Motor 4 - Atrás Derecha
delay(1600);           // Tiempo requerido para girar a la IZQUIERDA 1.6 seg.
Serial.println("Girando a la Izquierda");// Escribe en el monitor serial
}
