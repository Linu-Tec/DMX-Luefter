// ------------Autoprogramme-------------------------------------------------------------------------

void ModeFunktion(){
  TasterAuslesen();
  if(StatusTasteUP == HIGH){
    DrehzahlstufeZaehler++;
  }
  if(StatusTasteDOWN == HIGH){
    DrehzahlstufeZaehler--;
  }
  pruefenModeMenu();
  ModeMenue();
  
  if(StatusTasteENTER == HIGH){   // Wenn Enter gedrückt, dann
    EEPROM.write(Adresse_10, Hauptmenuezaehler);   // Speichere Wert Hauptmenü im EEPROM
    EEPROM.write(Adresse_11, DrehzahlstufeZaehler);   // Speichere Wert Autoprogramm im EEPROM
    #ifdef FunktionSerial
      Serial.println(Hauptmenuezaehler);
      Serial.println(DrehzahlstufeZaehler);
    #endif
    delay(100);
  }

  switch(DrehzahlstufeZaehler){
    case 1:
      RelaisStartWerte();   // Aus
      break;
    case 2:
      RelaisDrehzahlStellung_1();   // Stufe 1
      break;
    case 3:
      RelaisDrehzahlStellung_2();   // Stufe 2
      break;
    case 4:
      RelaisDrehzahlStellung_3();   // Stufe 3
      break;
  }
}
