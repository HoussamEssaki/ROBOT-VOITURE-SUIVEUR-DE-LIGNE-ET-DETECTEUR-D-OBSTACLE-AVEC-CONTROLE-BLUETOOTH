// Définition des pins pour le contrôle des moteurs

  const int in1 = 2; // Direction du moteur A
  const int in2 = 4; // Direction du moteur A
  const int enA = 3; // PWM pour le contrôle de la vitesse du moteur A

  const int in3 = 5; // Direction du moteur B
  const int in4 = 7; // Direction du moteur B
  const int enB = 6; // PWM pour le contrôle de la vitesse du moteur B

  void setup() 
{
     Serial.begin(9600); // Initialise la communication série avec le moniteur série

    // Définit les pins comme des sorties
      pinMode(enA, OUTPUT);
      pinMode(enB, OUTPUT);
      pinMode(in1, OUTPUT);
      pinMode(in2, OUTPUT);
      pinMode(in3, OUTPUT);
      pinMode(in4, OUTPUT);
}

// Fonction pour faire avancer les moteurs
  void avancer() 
{
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enA, 155); // Vitesse maximale pour le moteur A
    analogWrite(enB, 155); // Vitesse maximale pour le moteur B
}

// Fonction pour faire reculer les moteurs
  void reculer() 
{
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enA, 155); // Vitesse maximale pour le moteur A
    analogWrite(enB, 155); // Vitesse maximale pour le moteur B
}

// Fonction pour faire tourner à gauche les moteurs
  void gauche() 
{
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, HIGH);
    analogWrite(enA, 155); // Vitesse maximale pour le moteur A
    analogWrite(enB, 0); // Vitesse maximale pour le moteur B
}

// Fonction pour faire tourner à droite les moteurs
  void droite()
{
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enA, 0); // Vitesse maximale pour le moteur A
    analogWrite(enB, 155); // Vitesse maximale pour le moteur B
}

// Fonction pour arrêter les moteurs
  void arreter() 
{
    digitalWrite(in1, HIGH);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    analogWrite(enA, 0); // Arrête le moteur A
    analogWrite(enB, 0); // Arrête le moteur B
}
//
  void loop() 
{
   while (Serial.available() > 0) 
  {
      String donnee = Serial.readString(); // Lire les données reçues du module Bluetooth
      Serial.print("Donnée reçue depuis Bluetooth : ");
      Serial.println(donnee);

    if ( donnee == "F") // F = Forward
    {
        // Fait tourner les moteurs en avance 
          avancer();
        //delay(1000); // pendant 1 seconde
    }
    else if ( donnee == "L") // L = Left
    {
        // Fait tourner les moteurs à gauche 
          gauche();
        //delay(1000); // pendant 1 seconde
    }
    else if ( donnee == "R") // R = Right
    {
        // Fait tourner les moteurs à droite 
          droite();
        //delay(1000); // pendant 1 seconde
    }
    else if ( donnee == "B") // B = Backward
    {
        // Fait tourner les moteurs en arrière 
          reculer();
        //delay(1000); // pendant 1 seconde
    }
    else if ( donnee == "S") // S = Stop
    {
        // Arrête les moteurs 
          arreter();
        //delay(1000); // pendant 1 seconde
    }
  }
}



