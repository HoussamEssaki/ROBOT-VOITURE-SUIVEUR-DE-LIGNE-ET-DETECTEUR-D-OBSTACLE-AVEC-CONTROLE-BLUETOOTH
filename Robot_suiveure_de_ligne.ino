// Définition des pins pour le contrôle des moteurs
    const int in1 = 2; // Direction du moteur A
    const int in2 = 4; // Direction du moteur A
    const int enA = 3; // PWM pour le contrôle de la vitesse du moteur A

    const int in3 = 5; // Direction du moteur B
    const int in4 = 7; // Direction du moteur B
    const int enB = 6; // PWM pour le contrôle de la vitesse du moteur B

// Définition des pins
    const int pinCapteur1 = 12; // Connectez le capteur infrarouge 1 au pin 12 de la carte Arduino
    const int pinCapteur2 = 13; // Connectez le capteur infrarouge 2 au pin 13 de la carte Arduino
//
  void setup() 
{
  // Définit les pins comme des sorties
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);

    Serial.begin(9600); // Initialise la communication série à une vitesse de 9600 bauds

    pinMode(pinCapteur1, INPUT); // Définit le pin du capteur infrarouge 1 comme une entrée
    pinMode(pinCapteur2, INPUT); // Définit le pin du capteur infrarouge 2 comme une entrée
}

// Fonction pour faire avancer les moteurs
  void avancer()
{
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enA, 60); // Vitesse maximale pour le moteur A
    analogWrite(enB, 60); // Vitesse maximale pour le moteur B
}

// Fonction pour faire reculer les moteurs
  void reculer() 
{
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enA, 60); // Vitesse maximale pour le moteur A
    analogWrite(enB, 60); // Vitesse maximale pour le moteur B
}

// Fonction pour faire tourner à gauche les moteurs
  void gauche() 
{
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, HIGH);
    analogWrite(enA, 60); // Vitesse maximale pour le moteur A
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
    analogWrite(enB, 60); // Vitesse maximale pour le moteur B
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
  // Lecture de la valeur du capteur
    int Capteur_Droit = digitalRead(pinCapteur1);
    int Capteur_Gauche = digitalRead(pinCapteur2);

  // Affichage de la valeur du capteur sur le moniteur série
    Serial.println("Valeur du capteur Droit : ");
    Serial.println(Capteur_Droit);
    Serial.println("Valeur du capteur Gauche : ");
    Serial.println(Capteur_Gauche);
    delay(1000); // Attend 500 millisecondes avant la prochaine lecture

  if( Capteur_Droit == 0 && Capteur_Gauche == 0)
  {
      // Faire tourner les moteurs en avance 
       avancer();
  }
  else if( Capteur_Droit == 1 && Capteur_Gauche == 0)
  {
      // Faire tourner les moteurs à droite
       droite();
  }
  else if( Capteur_Droit == 0 && Capteur_Gauche == 1)
  {
      // Faire tourner les moteurs à gauche
       gauche();
  }
  else if( Capteur_Droit == 1 && Capteur_Gauche == 1)
  {
      // Faire tourner les moteurs en arrière
       reculer();
  }
    // Arrête les moteurs
    //arreter();
}



