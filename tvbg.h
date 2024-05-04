#include <IRremote.h>

#define IRLED 13  // Définir le GPIO utilisé pour envoyer le signal IR

// Déclaration des constantes pour les commandes IR
#define POWER_ADDRESS 0x84F40000
#define POWER_COMMAND 0x0BF40000

#define INPUT_ADDRESS 0x84F40000
#define INPUT_COMMAND 0x0AF50000

#define MENU_ADDRESS 0x84F40000
#define MENU_COMMAND 0x0CF30000

#define ZOOM_UP_ADDRESS 0x84F40000
#define ZOOM_UP_COMMAND 0x1BE40000

#define ZOOM_DWN_ADDRESS 0x84F40000
#define ZOOM_DWN_COMMAND 0x1AE50000

#define FREEZE_ADDRESS 0x84F40000
#define FREEZE_COMMAND 0x3BC40000

#define FOCUS_UP_ADDRESS 0x84F40000
#define FOCUS_UP_COMMAND 0x1DE20000

#define FOCUS_DWN_ADDRESS 0x84F40000
#define FOCUS_DWN_COMMAND 0x1CE30000

#define UP_ADDRESS 0x84F40000
#define UP_COMMAND 0x4AB50000

#define DOWN_ADDRESS 0x84F40000
#define DOWN_COMMAND 0x4BB40000

#define LEFT_ADDRESS 0x84F40000
#define LEFT_COMMAND 0x4DB20000

#define RIGHT_ADDRESS 0x84F40000
#define RIGHT_COMMAND 0x4EB10000

#define ENTER_ADDRESS 0x84F40000
#define ENTER_COMMAND 0x4CB30000

// Initialisation de l'émetteur IR
IRsend irsend(IRLED);

void setup() {
  Serial.begin(9600); // Initialisation de la communication série

  // Ajouter ici d'autres initialisations si nécessaire
}

void loop() {
  // Afficher le menu
  Serial.println("Menu:");
  Serial.println("1. POWER");
  Serial.println("2. Input");
  Serial.println("3. Menu");
  Serial.println("4. Zoom Up");
  Serial.println("5. Zoom Down");
  Serial.println("6. Freeze");
  Serial.println("7. Focus Up");
  Serial.println("8. Focus Down");
  Serial.println("9. Up");
  Serial.println("10. Down");
  Serial.println("11. Left");
  Serial.println("12. Right");
  Serial.println("13. Enter");
  Serial.println("Choisissez une option:");

  // Lire l'entrée de l'utilisateur depuis le moniteur série
  while (!Serial.available()); // Attendre jusqu'à ce qu'une entrée soit disponible
  int option = Serial.parseInt(); // Lire l'option choisie

  // Envoyer la commande IR correspondante en fonction de l'option choisie
  switch (option) {
    case 1:
      sendIRCommand(POWER_ADDRESS, POWER_COMMAND);
      break;
    case 2:
      sendIRCommand(INPUT_ADDRESS, INPUT_COMMAND);
      break;
    case 3:
      sendIRCommand(MENU_ADDRESS, MENU_COMMAND);
      break;
    case 4:
      sendIRCommand(ZOOM_UP_ADDRESS, ZOOM_UP_COMMAND);
      break;
    case 5:
      sendIRCommand(ZOOM_DWN_ADDRESS, ZOOM_DWN_COMMAND);
      break;
    case 6:
      sendIRCommand(FREEZE_ADDRESS, FREEZE_COMMAND);
      break;
    case 7:
      sendIRCommand(FOCUS_UP_ADDRESS, FOCUS_UP_COMMAND);
      break;
    case 8:
      sendIRCommand(FOCUS_DWN_ADDRESS, FOCUS_DWN_COMMAND);
      break;
    case 9:
      sendIRCommand(UP_ADDRESS, UP_COMMAND);
      break;
    case 10:
      sendIRCommand(DOWN_ADDRESS, DOWN_COMMAND);
      break;
    case 11:
      sendIRCommand(LEFT_ADDRESS, LEFT_COMMAND);
      break;
    case 12:
      sendIRCommand(RIGHT_ADDRESS, RIGHT_COMMAND);
      break;
    case 13:
      sendIRCommand(ENTER_ADDRESS, ENTER_COMMAND);
      break;
    default:
      Serial.println("Option invalide !");
  }
}

// Fonction pour envoyer une commande IR
void sendIRCommand(unsigned long address, unsigned long command) {
  // Créer une instance de la structure IRsendData pour stocker les données à envoyer
  IRsendData irData;
  
  // Remplir les données avec l'adresse et la commande
  irData.address = address;
  irData.command = command;
  
  // Envoyer la commande IR
  irsend.send(irData);
  
  // Attendre un court instant avant de revenir
  delay(1000);
}
