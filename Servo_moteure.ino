#include <Servo.h>

// Création d'un objet Servo
  Servo monServo;
//
  void setup() 
{
  // Définition du pin de contrôle du servo
    monServo.attach(9); // Utilisez le pin 9 ou un autre pin PWM disponible sur votre carte Arduino
}
//
  void loop() 
{
  //Déplace le servo de 0 degrés à 180 degrés
      for (int angle = 0; angle <= 180; angle+=20) 
      {
          monServo.write(angle); // Envoie la position au servo
          delay(20); // Attente pour le mouvement fluide
      }

        delay(1000); // Attente d'une 110 milisecondes

   //Déplace le servo de 180 degrés à 0 degrés
        for (int angle = 180; angle >= 0; angle-=20)
      {
          monServo.write(angle); // Envoie la position au servo
          delay(20); // Attente pour le mouvement fluide
      }

        delay(1000); // Attente d'une 110 milisecondes
}
