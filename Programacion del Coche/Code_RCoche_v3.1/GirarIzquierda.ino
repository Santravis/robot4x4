void GirarIzquierda() {    // Hace que el robot gire a la DERECHA
motor1.run(BACKWARD);  // Motor 1 - Delante Derecha
motor2.run(FORWARD); // Motor 2 - Delante Izquierda
motor3.run(FORWARD); // Motor 3 - Atrás Izquierda
motor4.run(BACKWARD);  // Motor 4 - Atrás Derecha
delay(1600);          // Tiempo requerido para girar a la DERECHA 1.6 seg.
Serial.println("Girando a la Derecha"); // Escribe en el monitor serial
}
