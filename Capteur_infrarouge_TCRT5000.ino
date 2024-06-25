  // Définition des pins
    const int pinCapteur1 = 12; // Connectez le capteur infrarouge 1 au pin 12 de la carte Arduino
    const int pinCapteur2 = 13; // Connectez le capteur infrarouge 2 au pin 13 de la carte Arduino

  void setup()
{
    Serial.begin(9600); // Initialise la communication série à une vitesse de 9600 bauds
    pinMode(pinCapteur1, INPUT); // Définit le pin du capteur infrarouge 1 comme une entrée
    pinMode(pinCapteur2, INPUT); // Définit le pin du capteur infrarouge 2 comme une entrée
}
//
  void loop() 
{
  // Lecture de la valeur du capteur
    int valeurCapteur1 = digitalRead(pinCapteur1);
    int valeurCapteur2 = digitalRead(pinCapteur2);

  // Affichage de la valeur du capteur sur le moniteur série
    Serial.println("Valeur du capteur 1 : ");
    Serial.println(valeurCapteur1);
    Serial.println("Valeur du capteur 2 : ");
    Serial.println(valeurCapteur2);

  if( valeurCapteur1 == HIGH  && valeurCapteur2 == HIGH)
  {
     Serial.println("Nous sommes dans la ligne noire");
  }
  else
  {
      Serial.println("Nous sommes Hors la ligne noire");
  }
    delay(1000); // Attend 1000 millisecondes avant la prochaine lecture
}
