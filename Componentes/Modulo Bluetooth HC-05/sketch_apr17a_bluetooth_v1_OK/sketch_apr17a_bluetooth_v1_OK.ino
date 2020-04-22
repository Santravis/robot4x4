
// Bluetooth
const int LED = 13;
const int BTPWR = 10;

char nombreBT[11] = "Car_San";
char pin[5] = "0000";
char velocidad = '4'; // la velocidad 9600 se corresponde con el num. 4
char modo='1';        // '0' para esclavo y '1' para maestro

void setup(){
  pinMode(LED, OUTPUT);
  pinMode(BTPWR, OUTPUT);

  Serial.begin(38400);  // velocidad de BT en modo de configuración.
  
  /*solo pulsador */
  // bluetooth con pulsador y sin conectar por cable EN ó KEY
  digitalWrite(LED, HIGH);
  delay(4000);
  digitalWrite(LED, LOW);
  //++++++++++++++++++++++/

  digitalWrite(BTPWR, HIGH);
  delay(3000);
  Serial.print("AT\r\t");  // con \r\t le indicamos que ha terminado la linea de codigo

  Serial.print("AT+NAME:");
  Serial.print(nombreBT);
  Serial.print("\r\t");

  Serial.print("AT+PIN:");  // ó AT+PSWD:
  Serial.print(pin);
  Serial.print("\r\t");

  Serial.print("AT+BAUD:");
  Serial.print(velocidad);
  Serial.print("\r\t");

  Serial.print("AT+Mode:");
  Serial.print(modo);
  Serial.print("\r\t");

  digitalWrite(LED, HIGH);

  
}

void loop(){

 
}
