  #include <Servo.h>

// Définition des pins pour le contrôle des moteurs
    const int in1 = 2; // Direction du moteur A
    const int in2 = 4; // Direction du moteur A
    const int enA = 3; // PWM pour le contrôle de la vitesse du moteur A

    const int in3 = 5; // Direction du moteur B
    const int in4 = 7; // Direction du moteur B
    const int enB = 6; // PWM pour le contrôle de la vitesse du moteur B

// Définir les pins
    const int trigPin = 8;
    const int echoPin = 10;

// Définir les variables
    long duration;
    int distance;

//Définition des pins pour le contrôle des Leds
    const int led_vert = A0; // Utilisation de la broche analogique 0 comme broche numérique pour la led verte
    const int led_orange = A1; // Utilisation de la broche analogique 1 comme broche numérique pour la led orange
    const int led_rouge = A2; // Utilisation de la broche analogique 2 comme broche numérique pour la led rouge

//Définir la broche pour le buzzer
    const int buzzerPin = 11;
     
// Création d'un objet Servo
  Servo monServo;
//

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
  
  // Initialiser la communication série
      Serial.begin(9600);

  // Définir les modes de broche
      pinMode(trigPin, OUTPUT);
      pinMode(echoPin, INPUT);

  // Définit les pins comme des sorties pour les leds
      pinMode(led_vert, OUTPUT);
      pinMode(led_orange, OUTPUT);
      pinMode(led_rouge, OUTPUT);

  // Définir la broche du buzzer comme sortie
      pinMode(buzzerPin, OUTPUT);

  // Définition du pin de contrôle du servo
      monServo.attach(9); // Utilisez le pin 9 ou un autre pin PWM disponible sur votre carte Arduino
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

//La méthode pour calculer la distance
  int Calcul_Distance()
{
  // Effacer le trigger pin
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);

  // Envoyez une impulsion de 10 microsecondes pour déclencher la broche
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);

  // Mesurer la durée de l'impulsion sur la broche d'écho
      duration = pulseIn(echoPin, HIGH);

  // Calcule de la distance en cm
     distance = duration * 0.034 / 2;

  // Afficher la distance jusqu'au moniteur série
      Serial.print("Distance: ");
      Serial.print(distance);
      Serial.println(" cm");

  // Délai avant la prochaine mesure
      delay(500);
  // Retourner la valeure mesuré
        return(distance);
}
//
  void loop() 
{
  //Récupérer le résultat de la méthode Calcul_Distance
      int resultat = Calcul_Distance();

  // Contrôle les LEDs en fonction de la distance mesurée
    if (resultat <= 10) 
    {
        digitalWrite(led_rouge, HIGH);
        digitalWrite(led_orange, LOW);
        digitalWrite(led_vert, LOW);
        tone(buzzerPin, 1000); // Tonalité pour proximité très proche

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
    else if (resultat <= 20)
    {
        digitalWrite(led_rouge, LOW);
        digitalWrite(led_orange, HIGH);
        digitalWrite(led_vert, LOW);
        tone(buzzerPin, 800); // Tonalité pour proximité moyenne
    } 
    else 
    {
        digitalWrite(led_rouge, LOW);
        digitalWrite(led_orange, LOW);
        digitalWrite(led_vert, HIGH);
        noTone(buzzerPin); // Aucune tonalité pour distance lointaine
    }

  // Contrôle des moteurs pour éviter les obstacles
    if (distance <= 10) 
    {
      //arrêter les moteurs pour une distance inférieure ou égale à 10 cm
        arreter();
        delay(1000); // Attendre 1 seconde

      // Effectuer une manœuvre d'évitement de l'obstacle    
        // Faire tourner à gauche pour éviter l'obstacle
          droite(); 
          delay(1000); // Attendre 1 seconde

        // Faire tourner à gauche pour éviter l'obstacle
          gauche(); 
          delay(1000); // Attendre 1 seconde

        // Revenir à la direction initiale
          avancer(); // Revenir à avancer
          delay(1000); // Attendre 1 seconde
    } 
     else 
    {
      // Faire avancer les moteurs à pleine vitesse s'il n'y a pas d'obstacle
         avancer();
    }
  
  // Délai pour stabiliser les mesures
      delay(100);
}