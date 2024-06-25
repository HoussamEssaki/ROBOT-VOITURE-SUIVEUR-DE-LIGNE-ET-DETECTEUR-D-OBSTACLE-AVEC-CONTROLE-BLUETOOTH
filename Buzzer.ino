  //Définir la broche pour le buzzer
    const int buzzerPin = 11;
//
  void setup() 
{
  // Définir la broche du buzzer comme sortie
   pinMode(buzzerPin, OUTPUT);
}
//
  void loop() 
{
  // Jouer un ton
    tone(buzzerPin, 1000); // Jouer une tonalité de 1 000 Hz
    delay(1000); //Attendre 1 seconde
  
  // Arrêtez le ton
    noTone(buzzerPin);
    delay(1000); //Attendre 1 seconde
}
