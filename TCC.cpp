#include <Keypad.h>

#define dir 11   //determina a direção de rotação
#define pul 13   //borda de descida ou subida
#define ena 12   //habilita o desabilita o driver

#define dir2 45
#define pul2 46
#define ena2 47


#define motor1 22 // pin rotação sentido horário
#define motor2 23
#define motor3 24
#define motor4 25 //esteira do elevador
#define motor5 26
#define motor6 27
#define motor7 28
#define motor8 29 //esteira do elevador

const int vel1 = 9;  //pino para definir velocidade do motor 
const int vel2 = 2;  
const int vel3 = 3;
const int vel4 = 4;
const int vel5 = 5;
const int vel6 = 6;
const int vel7 = 7;
const int vel8 = 8;


#define sensor1 30
#define sensor2 31
#define sensor3 32
#define sensor5 34
#define sensor6 35
#define sensor7 36 

// Defina o número de passos por revolução
const int passosPorRevolucao = 200;
const int passosPorRevolucao2 = 200;

// Defina a velocidade do motor
const int velocidade = 100;
const int velocidade2 = 50;

// Defina a direção do movimento (0 = horário, 1 = anti-horário)
int direcao = 0;
int direcao1 = 1;

const byte linhas = 4;
const byte colunas = 4;
char keys[linhas][colunas] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// Conecte as linhas do teclado à porta digital do Arduino
byte rowPins[linhas] = { 38, 39, 40, 41 };

// Conecte as colunas do teclado à porta digital do Arduino
byte colPins[colunas] = { 50, 51, 52, 53 };

// Inicialize o objeto Keypad
Keypad teclado = Keypad(makeKeymap(keys), rowPins, colPins, linhas, colunas);

bool b1state = false;
bool b2state = false;
bool b3state = false;
bool b4state = false;
bool b5state = false;
bool b6state = false;

void setup() {
  pinMode(ena, OUTPUT);
  pinMode(dir, OUTPUT);
  pinMode(pul, OUTPUT);
  
  pinMode(ena2, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(pul2, OUTPUT);
  

  pinMode(motor1, OUTPUT);  //define entradas e saidas
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);
  pinMode(motor5, OUTPUT);
  pinMode(motor6, OUTPUT);
  pinMode(motor7, OUTPUT);
  pinMode(motor8, OUTPUT);

  pinMode(vel1, OUTPUT);
  pinMode(vel2, OUTPUT);
  pinMode(vel3, OUTPUT);
  pinMode(vel4, OUTPUT);
  pinMode(vel5, OUTPUT);
  pinMode(vel6, OUTPUT);
  pinMode(vel7, OUTPUT);
  pinMode(vel8, OUTPUT);
  
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor5, INPUT);
  pinMode(sensor6, INPUT);
  pinMode(sensor7, INPUT);
}   

void loop() {
  liga();
  esteira();
  sobe1();
  sobe2();
  desce1();
  desce2();
}

void liga() {
char key = teclado.getKey();
 if (key != NO_KEY) {
    if (key == '3') {
      if (b6state) {}
}
    } 
  char keys = teclado.getKey();
   if (key == '6'){
    if (b1state){}
    if (b2state){}
    if (b3state){}
    if (b4state){}
    if (b5state){}
  }
  }
}

void esteira() {   //1° andar

  int sen1=digitalRead(sensor1); //variável que armazena valor dos sensores
  int sen2=digitalRead(sensor2);
  int sen3=digitalRead(sensor3);
  int sen5=digitalRead(sensor5);
  int sen6=digitalRead(sensor6);
  int sen7=digitalRead(sensor7);
  
   if(sen1==LOW && sen2==LOW && sen3==LOW){ //condição de quando o motor deve girar
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, LOW); 
    digitalWrite(motor3, LOW);
    analogWrite(vel1, 80); //escolhe velocidade entre 0 a 255
    analogWrite(vel2, 80);
    analogWrite(vel3, 80);
  }
   if(sen1==LOW && sen2==LOW && sen3==HIGH || sen1==LOW && sen2==HIGH && sen3==HIGH || sen1==HIGH && sen2==LOW && sen3==HIGH || sen1==HIGH && sen2==HIGH && sen3==HIGH){
    digitalWrite(motor1, HIGH); //horário 
    digitalWrite(motor2, HIGH);
    digitalWrite(motor3, HIGH);
    analogWrite(vel1, 80);
    analogWrite(vel2, 80);
    analogWrite(vel3, 80);
  }
   if(sen1==LOW && sen2==HIGH && sen3==LOW || sen1==HIGH && sen2==HIGH && sen3==LOW ){
    digitalWrite(motor1, HIGH); //horário 
    digitalWrite(motor2, HIGH); //horário 
    digitalWrite(motor3, LOW);
    analogWrite(vel1, 80);
    analogWrite(vel2, 80);
    analogWrite(vel3, 80);
  }
   if(sen1==HIGH && sen2==LOW && sen3==LOW) {
    digitalWrite(motor1, HIGH); //horário 
    digitalWrite(motor2, LOW); //horário 
    digitalWrite(motor3, LOW);
    analogWrite(vel1, 80);
    analogWrite(vel2, 80);
    analogWrite(vel3, 80);
    }

    // 2°andar
    if(sen5==LOW && sen6==LOW && sen7==LOW){ //condição de quando o motor deve girar
    digitalWrite(motor5, LOW);
    digitalWrite(motor6, LOW); 
    digitalWrite(motor7, LOW);
    analogWrite(vel5, 80); //escolhe velocidade entre 0 a 255
    analogWrite(vel6, 80);
    analogWrite(vel4, 80);
  }
   if(sen5==LOW && sen6==LOW && sen7==HIGH || sen5==LOW && sen6==HIGH && sen7==HIGH || sen5==HIGH && sen6==LOW && sen7==HIGH || sen5==HIGH && sen6==HIGH && sen7==HIGH){
    digitalWrite(motor5, HIGH); //horário 
    digitalWrite(motor6, HIGH);
    digitalWrite(motor4, HIGH);
    analogWrite(vel5, 80);
    analogWrite(vel6, 80);
    analogWrite(vel4, 80);
  }
   if(sen5==LOW && sen6==HIGH && sen7==LOW || sen5==HIGH && sen6==HIGH && sen7==LOW ){
    digitalWrite(motor5, HIGH); //horário 
    digitalWrite(motor6, HIGH); //horário 
    digitalWrite(motor4, LOW);
    analogWrite(vel5, 80);
    analogWrite(vel6, 80);
    analogWrite(vel4, 80);
  }
   if(sen5==HIGH && sen6==LOW && sen7==LOW) {
    digitalWrite(motor5, HIGH); //horário 
    digitalWrite(motor6, LOW); //horário 
    digitalWrite(motor4, LOW);
    analogWrite(vel5, 80);
    analogWrite(vel6, 80);
    analogWrite(vel4, 80);
    }
}
void sobe1() {
  int sen1=digitalRead(sensor1);
  int sen3=digitalRead(sensor3);
  int sen5=digitalRead(sensor5);
  int sen6=digitalRead(sensor6);
  int sen7=digitalRead(sensor7);
  char key = teclado.getKey();
  if (key != NO_KEY) {
    if (key == '1' && sen1==HIGH ){
      if(b2state){}
      if(b4state){}
      if(b5state){}
      digitalWrite(motor7, HIGH);
      analogWrite(vel7, 80);
  }
  }
}

  void desce1() {
  int sen1=digitalRead(sensor1);
  int sen3=digitalRead(sensor3);
  int sen5=digitalRead(sensor5);
  int sen6=digitalRead(sensor6);
  int sen7=digitalRead(sensor7);
  char key = teclado.getKey();
  if (key != NO_KEY) {
    if (key == '4' && sen1==HIGH ){
      if(b2state){}
      if(b4state){}
      if(b5state){}
      digitalWrite(motor8, HIGH);
      analogWrite(vel8, 80);
  }
  }
  }
//função sobe 2 
void sobe2() {
    int sen1=digitalRead(sensor1);
    int sen3=digitalRead(sensor3);
    int sen5=digitalRead(sensor5);
    int sen6=digitalRead(sensor6);
    int sen7=digitalRead(sensor7);
  digitalWrite(ena, HIGH);
 char key = teclado.getKey();
 if (key != NO_KEY) {
  if (key == '2' && sen5==HIGH ){
    if(b1state){}
    if(b4state){}
    if(b5state){}
    digitalWrite(ena, LOW);  
    digitalWrite(dir, direcao);
    for(int i = 0; i < passosPorRevolucao*2; i++){       
      digitalWrite(pul, HIGH);            
      delayMicroseconds(500000 / velocidade);
      digitalWrite(pul, LOW);
      delayMicroseconds(500000 / velocidade);  

      delay(1000);
      digitalWrite(motor7, HIGH);
      analogWrite(vel7, 80);
      }
  }
    delay(3000);
    digitalWrite(motor7, LOW);
    analogWrite(vel7, 80);

    digitalWrite(dir, direcao1);
      for(int i = 0; i < passosPorRevolucao*2; i++){
        digitalWrite(pul, HIGH);
        delayMicroseconds(500000 / velocidade);
        digitalWrite(pul, LOW);
        delayMicroseconds(500000 / velocidade);
  }
}
}

  //função desce 2
void desce2() {
    int sen1=digitalRead(sensor1);
    int sen3=digitalRead(sensor3);
    int sen5=digitalRead(sensor5);
    int sen6=digitalRead(sensor6);
    int sen7=digitalRead(sensor7);
   
  digitalWrite(ena2, HIGH);
 char key = teclado.getKey();
 if (key != NO_KEY) {
  if (key == '5' && sen7==HIGH ){
    if(b2state){}
    if(b4state){}
    if(b1state){}
    digitalWrite(ena2, LOW);
    digitalWrite(dir2, direcao);
      for(int i = 0; i < passosPorRevolucao*2; i++){
        digitalWrite(pul2, HIGH);            
        delayMicroseconds(500000 / velocidade);
        digitalWrite(pul2, LOW);
        delayMicroseconds(500000 / velocidade);

        delay(1000);
        digitalWrite(motor8, HIGH);
        analogWrite(vel8, 80);
      }
  }
    delay(3000);
    digitalWrite(motor8, LOW);
    analogWrite(vel8, 80);    
    
    digitalWrite(dir2, direcao1);
      for(int i = 0; i < passosPorRevolucao*2; i++){
        digitalWrite(pul2, HIGH);
        delayMicroseconds(500000 / velocidade);
        digitalWrite(pul2, LOW);
        delayMicroseconds(500000 / velocidade);
  }
  }
}
