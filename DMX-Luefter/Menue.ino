// ------------Hauptmenü-------------------------------------------------------------------------

void HauptMenu(){
  TasterAuslesen();
  
  if(StatusTasteMODE == HIGH){
    delay(100);
    Hauptmenue = 1;
    Hauptmenuezaehler++;
    if(Hauptmenuezaehler >= 5){
      Hauptmenuezaehler = 1;
    }
  }

  switch(Hauptmenuezaehler){
    case 1:
      #ifdef FunktionSerial
        Serial.println("DMX-Modus-Nix");
      #endif
      DMX_Modus_Nix = 1;
      while(DMX_Modus_Nix == 1){
        display.setSegments(Bindestrich, 4, 0);

        #ifdef FunktionDMX
          DMXsteuern();
        #endif
        
        TasterAuslesenDMXModus();

        if(StatusTasteENTER == HIGH){   // Wenn Enter gedrückt, dann
          EEPROM.write(Adresse_10, Hauptmenuezaehler);   // Sperichere Wert im EEPROM
          delay(100);
        }
        if(StatusTasteMODE == HIGH){
          delay(100);
          DMX_Modus_Nix = 0;
          RelaisStartWerte();
          Hauptmenuezaehler++;
          if(Hauptmenuezaehler >= 4){
            Hauptmenuezaehler = 1;
          }
          return;
        }
      }
      break;
    case 2:
      #ifdef FunktionSerial
        Serial.println("DMX-Adresse");
      #endif
      DMX_Adresse_einstellen = 1;
      dmxwertzeigen();
      while(DMX_Adresse_einstellen == 1){
        TasterAuslesen();
        
        dmxBaseChberechnen();
        eepromschreiben();

        if(StatusTasteMODE == HIGH){
          delay(100);
          DMX_Adresse_einstellen = 0;
          Hauptmenuezaehler++;
          if(Hauptmenuezaehler >= 4){
            Hauptmenuezaehler = 1;
          }
          return;
        }
      }
      
      break;
    case 3:
      #ifdef FunktionSerial
        Serial.println("Autoprogramme");
      #endif
      Autoprogramme = 1;
      ModeMenue();
      while(Autoprogramme == 1){
        
        ModeFunktion();
        
        if(StatusTasteMODE == HIGH){
          delay(100);
          Autoprogramme = 0;
          RelaisStartWerte();
          Hauptmenuezaehler++;
          if(Hauptmenuezaehler >= 4){
            Hauptmenuezaehler = 1;
          }
          return;
        }
      }
      
      break;
  }
}
