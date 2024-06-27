#include <Servo.h>
 
#define echoPin 2 //pinos do sensor ultrassonico
#define trigPin 3 //pinos do sensor ultrassonico
 
Servo motor1;
Servo motor2;
Servo motor3;
 
void setup(){
    motor1.attach(11);
    motor2.attach(12);
    motor3.attach(13);
}
 
void loop(){
    controlaAgua();
}
 
int distanciaAgua(){    
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    long duration = pulseIn(echoPin, HIGH);
    return  duration * 0.034 / 2; 
}
 
void controlaAgua(){
    // 3 distâncias para acionar ou desligar os motores
    // se distancia >= 50 significa que existem menos de 6 mil litros
    // se distancia  < 50 e distancia > 30 sig. existem entre 6 e 9 mil litros
    // se distancia <= 30 e distancia > 15 sig. existem menos que 9 mil litros
    // se distancia <= 15 desligue os motores
    int distancia = distanciaAgua();
 
    if (distancia >= 50){
        controla_motor1(1);
        controla_motor2(1);
        controla_motor3(1);
    }
    else if (distancia < 50 && distancia > 30){
        controla_motor1(1);
        controla_motor2(1);
        controla_motor3(0);
    }    
    else if (distancia <= 30 && distancia > 15){
        controla_motor1(1);
        controla_motor2(0);
        controla_motor3(0);
    }
    else{ //desliga os 3 motores para evitar o transbordo da caixa d'água
        controla_motor1(0);
        controla_motor2(0);
        controla_motor3(0);
    }
}
 
void controla_motor1(int estado){ //1 ligado ou 0 desligado
    if (estado == 1){
        //abre o registro
        for (int pos = 0; pos <= 180; pos +=2){
                motor1.write(pos);
                delay(15);
        }
    }
    else{
        //fecha o registro
        for (int pos = 180; pos > 0; pos -=2){
                motor1.write(pos);
                delay(15);
        }
    }
} 
 
void controla_motor2(int estado){ //1 ligado ou 0 desligado
    if (estado == 1){
        //abre o registro
        for (int pos = 0; pos <= 180; pos +=2){
                motor2.write(pos);
                delay(15);
        }
    }
    else{
        //fecha o registro
        for (int pos = 180; pos > 0; pos -=2){
                motor2.write(pos);
                delay(15);
        }
    }
} 
void controla_motor3(int estado){ //1 ligado ou 0 desligado
    if (estado == 1){
        //abre o registro
        for (int pos = 0; pos <= 180; pos +=2){
                motor3.write(pos);
                delay(15);
        }
    }
    else{
        //fecha o registro
        for (int pos = 180; pos > 0; pos -=2){
                motor3.write(pos);
                delay(15);
        }
    }
}
