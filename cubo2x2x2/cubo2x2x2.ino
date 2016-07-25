
/* Código de ejemplo para un cubo de 2x2x2

  Es una versión muy simple del código, que nada tiene
  que ver con el código para un cubo superior. En este
  caso, un arduino uno ya tiene suficientes pines como
  para controlar los 8 leds de este cubo. Solo 6 pines
  son necesarios, 2 para las capas y 4 para los leds de
  cada capa.
*/

int n = 2;		// Tamaño del cubo = n*n*n
int ledpins[] = {4, 5, 6, 7}; // Pines por columna (nxn)
int groundpins[] = {2, 3};    // Pines por fila (n)

int paso=100;	// Tiempo entre pasos

void setup () {
  for(int i = 0; i < n*n; i++)
    pinMode(ledpins[i],OUTPUT);

  for (int i= 0; i<n; i++)
  	pinMode(groundpins[i],OUTPUT);

  completo();
}

void loop() {
  twist();
  drop();
  diagonal();
}

void completo() {
  // Enciende la lampara tmp * dl * 10 milisegundos (aprox.)
  int tmp = 1;
  for (int dl = 0; dl < 100; dl++){
    for (int i= 0; i<n; i++) {
    	digitalWrite(groundpins[i], LOW);
      for (int j = 0; j < n*n; j++) {
        digitalWrite(ledpins[j], HIGH);
        delay(tmp);
        digitalWrite(ledpins[j], LOW);
      }
    	digitalWrite(groundpins[i], HIGH);
    }
  }
}

void twist() {

  digitalWrite(groundpins[0], HIGH);
  delay(paso);
  digitalWrite(ledpins[0], HIGH);
  delay(paso);
  digitalWrite(ledpins[1], HIGH);
  delay(paso);
  digitalWrite(ledpins[2], HIGH);
  delay(paso);
  digitalWrite(ledpins[3], HIGH);
  delay(paso);

  digitalWrite(ledpins[0], LOW);
  delay(paso);
  digitalWrite(ledpins[1], LOW);
  delay(paso);
  digitalWrite(ledpins[2], LOW);
  delay(paso);
  digitalWrite(ledpins[3], LOW);
  delay(paso);
  digitalWrite(groundpins[0], LOW);

  digitalWrite(groundpins[1], HIGH);
  delay(paso);
  digitalWrite(ledpins[1], HIGH);
  delay(paso);
  digitalWrite(ledpins[2], HIGH);
  delay(paso);
  digitalWrite(ledpins[3], HIGH);
  delay(paso);
  digitalWrite(ledpins[0], HIGH);
  delay(paso);

  digitalWrite(ledpins[1], LOW);
  delay(paso);
  digitalWrite(ledpins[2], LOW);
  delay(paso);
  digitalWrite(ledpins[3], LOW);
  delay(paso);
  digitalWrite(ledpins[0], LOW);
  delay(paso);
  digitalWrite(groundpins[1], LOW);


  digitalWrite(groundpins[0], HIGH);
  delay(paso);
  digitalWrite(ledpins[2], HIGH);
  delay(paso);
  digitalWrite(ledpins[3], HIGH);
  delay(paso);
  digitalWrite(ledpins[0], HIGH);
  delay(paso);
  digitalWrite(ledpins[1], HIGH);
  delay(paso);

  digitalWrite(ledpins[2], LOW);
  delay(paso);
  digitalWrite(ledpins[3], LOW);
  delay(paso);
  digitalWrite(ledpins[0], LOW);
  delay(paso);
  digitalWrite(ledpins[1], LOW);
  delay(paso);
  digitalWrite(groundpins[0], LOW);

  digitalWrite(groundpins[1], HIGH);
  delay(paso);
  digitalWrite(ledpins[3], HIGH);
  delay(paso);
  digitalWrite(ledpins[0], HIGH);
  delay(paso);
  digitalWrite(ledpins[1], HIGH);
  delay(paso);
  digitalWrite(ledpins[2], HIGH);
  delay(paso);

  digitalWrite(ledpins[3], LOW);
  delay(paso);
  digitalWrite(ledpins[0], LOW);
  delay(paso);
  digitalWrite(ledpins[1], LOW);
  delay(paso);
  digitalWrite(ledpins[2], LOW);
  delay(paso);
  digitalWrite(groundpins[1], LOW);
}

void drop() {
  int dtime = 75;
  digitalWrite(groundpins[0], HIGH);
  digitalWrite(ledpins[0], HIGH);
  delay(dtime);
  digitalWrite(groundpins[0], LOW);
  digitalWrite(groundpins[1],HIGH);
  delay(dtime);
  digitalWrite(groundpins[1], LOW);
  digitalWrite(ledpins[0], LOW);

  digitalWrite(groundpins[0], HIGH);
  digitalWrite(ledpins[1], HIGH);
  delay(dtime);
  digitalWrite(groundpins[0], LOW);
  digitalWrite(groundpins[1], HIGH);
  delay(dtime);
  digitalWrite(groundpins[1], LOW);
  digitalWrite(ledpins[1], LOW);

  digitalWrite(groundpins[0], HIGH);
  digitalWrite(ledpins[2], HIGH);
  delay(dtime);
  digitalWrite(groundpins[0], LOW);
  digitalWrite(groundpins[1], HIGH);
  delay(dtime);
  digitalWrite(groundpins[1], LOW);
  digitalWrite(ledpins[2], LOW);

  digitalWrite(groundpins[0], HIGH);
  digitalWrite(ledpins[3], HIGH);
  delay(dtime);
  digitalWrite(groundpins[0], LOW);
  digitalWrite(groundpins[1], HIGH);
  delay(dtime);
  digitalWrite(groundpins[1], LOW);
  digitalWrite(ledpins[3], LOW);


  //second time down
  digitalWrite(groundpins[0], HIGH);
  digitalWrite(ledpins[0], HIGH);
  delay(dtime);
  digitalWrite(groundpins[0], LOW);
  digitalWrite(groundpins[1],HIGH);
  delay(dtime);
  digitalWrite(groundpins[1], LOW);
  digitalWrite(ledpins[0], LOW);

  digitalWrite(groundpins[0], HIGH);
  digitalWrite(ledpins[1], HIGH);
  delay(dtime);
  digitalWrite(groundpins[0], LOW);
  digitalWrite(groundpins[1], HIGH);
  delay(dtime);
  digitalWrite(groundpins[1], LOW);
  digitalWrite(ledpins[1], LOW);

  digitalWrite(groundpins[0], HIGH);
  digitalWrite(ledpins[2], HIGH);
  delay(dtime);
  digitalWrite(groundpins[0], LOW);
  digitalWrite(groundpins[1], HIGH);
  delay(dtime);
  digitalWrite(groundpins[1], LOW);
  digitalWrite(ledpins[2], LOW);

  digitalWrite(groundpins[0], HIGH);
  digitalWrite(ledpins[3], HIGH);
  delay(dtime);
  digitalWrite(groundpins[0], LOW);
  digitalWrite(groundpins[1], HIGH);
  delay(dtime);
  digitalWrite(groundpins[1], LOW);
  digitalWrite(ledpins[3], LOW);
}

void diagonal() {
	int dtime= 100;
	//bottom pin 0 on
	digitalWrite(groundpins[1], HIGH);
	digitalWrite(ledpins[0], HIGH);
	delay(dtime);
	//bottom pin 0 off
	digitalWrite(groundpins[1], LOW);
	digitalWrite(ledpins[0], LOW);
	delay(dtime);
	//top pin 1 on
	digitalWrite(groundpins[0], HIGH);
	digitalWrite(ledpins[1], HIGH);
	delay(dtime);
	//top pin 1 off
	digitalWrite(groundpins[0], LOW);
	digitalWrite(ledpins[1], LOW);
	//bottom pin 2 on
	digitalWrite(groundpins[1], HIGH);
	digitalWrite(ledpins[2], HIGH);
	delay(dtime);
	//bottom pin 2 off
	digitalWrite(groundpins[1], LOW);
	digitalWrite(ledpins[2], LOW);
	  //top pin 3 on
	digitalWrite(groundpins[0], HIGH);
	digitalWrite(ledpins[3], HIGH);
	delay(dtime);
	//top pin 3 off
	digitalWrite(groundpins[0], LOW);
	digitalWrite(ledpins[3], LOW);


	//top pin 0 on
	digitalWrite(groundpins[0], HIGH);
	digitalWrite(ledpins[0], HIGH);
	delay(dtime);
	//top pin 0 off
	digitalWrite(groundpins[0], LOW);
	digitalWrite(ledpins[0], LOW);
	delay(dtime);
	//bottom pin 1 on
	digitalWrite(groundpins[1], HIGH);
	digitalWrite(ledpins[1], HIGH);
	delay(dtime);
	//bottom pin 1 off
	digitalWrite(groundpins[1], LOW);
	digitalWrite(ledpins[1], LOW);
	//top pin 2 on
	digitalWrite(groundpins[0], HIGH);
	digitalWrite(ledpins[2], HIGH);
	delay(dtime);
	//top pin 2 off
	digitalWrite(groundpins[0], LOW);
	digitalWrite(ledpins[2], LOW);
	  //bottom pin 3 on
	digitalWrite(groundpins[1], HIGH);
	digitalWrite(ledpins[3], HIGH);
	delay(dtime);
	//bottom pin 3 off
	digitalWrite(groundpins[1], LOW);
	digitalWrite(ledpins[3], LOW);
}
