//Godinez Guerrero Sandra luz
//Practica 1
//Sistema Alertizador salvaguarda humano-coche
//06/09/18

//Pines usados
#define ledVerde1 2
#define ledAmbar1 3
#define ledRojo1 4
#define ledVerde2 5
#define ledAmbar2 6
#define ledRojo2 7
#define push 8



//Variables
int tiempo = 2500;
int espera = 500;
boolean encendidoSemaforo1 = true;

void setup() {
  Serial.begin(9600);
  pinMode(ledVerde1,OUTPUT);
  pinMode(ledAmbar1,OUTPUT);
  pinMode(ledRojo1,OUTPUT);
  pinMode(ledVerde2,OUTPUT);
  pinMode(ledAmbar2,OUTPUT);
  pinMode(ledRojo2,OUTPUT);
  pinMode(push,INPUT);
  
  //Encender led verde en semaforo1, y led rojo en el del peaton
  digitalWrite(ledVerde1,HIGH);
  digitalWrite(ledRojo2,HIGH);
  //int valorPeaton = digitalRead(push);
  //int valorPeaton2 = digitalRead(S2);
}

void loop() {
   int valor = analogRead(A0);
    tiempo = map(valor,0, 1023, 10, 60)*500;
    
  //si se oprime el boton
  int state = digitalRead(push);
   if (state == HIGH) { //si se a presionado el boton se realizara el cambio de luces para el peaton 
   digitalWrite(ledRojo1,HIGH);
   digitalWrite(ledRojo2,LOW);
   digitalWrite(ledVerde1,LOW);
   digitalWrite(ledVerde2,HIGH);
   digitalWrite(ledAmbar1,LOW);
   digitalWrite(ledAmbar2,LOW);
   semaforo2();
   }
   while(state == LOW){
     if(encendidoSemaforo1){ 
//        //encender semaforo 1
        semaforo1();
        encendidoSemaforo1 = false;
        }
//  //Verificar que el semaforo 2 estara en verde 
  if(encendidoSemaforo1 == false){  
    semaforo2();
  }      
  encendidoSemaforo1 = true;    

   }
  
  }
  
     
  //}


  //Metodo para encender el primer semaforo
   void semaforo1(){
    delay(tiempo);
    digitalWrite(ledVerde1,LOW);
    digitalWrite(ledAmbar1,HIGH);
    delay(tiempo);
    digitalWrite(ledAmbar1,LOW);
    digitalWrite(ledRojo1,HIGH);
    digitalWrite(ledRojo2,LOW);
    digitalWrite(ledVerde2,HIGH);
  }

  //Metodo para encender el segundo semaforo
  void semaforo2(){
    delay(tiempo);
    digitalWrite(ledVerde2,LOW);
    digitalWrite(ledAmbar2,HIGH);
    delay(tiempo);
    digitalWrite(ledAmbar2,LOW);
    digitalWrite(ledRojo2,HIGH);
    digitalWrite(ledRojo1,LOW);
    digitalWrite(ledVerde1,HIGH);
  }



