void eepromauslesen(){
  #ifdef FunktionSerial
    Serial.print(EEPROM.read(Adresse_0));Serial.print(EEPROM.read(Adresse_1));Serial.print(EEPROM.read(Adresse_2));Serial.print(EEPROM.read(Adresse_3));Serial.print(EEPROM.read(Adresse_4));Serial.print(EEPROM.read(Adresse_5));Serial.print(EEPROM.read(Adresse_6));Serial.print(EEPROM.read(Adresse_7));Serial.print(EEPROM.read(Adresse_8));Serial.println(EEPROM.read(Adresse_9));
  #endif
  dmxBaseCh = (EEPROM.read(Adresse_0) * 1) + (EEPROM.read(Adresse_1) * 2) + (EEPROM.read(Adresse_2) * 4) + (EEPROM.read(Adresse_3) * 8) + (EEPROM.read(Adresse_4) * 16) + (EEPROM.read(Adresse_5) * 32) + (EEPROM.read(Adresse_6) * 64) + (EEPROM.read(Adresse_7) * 128) + (EEPROM.read(Adresse_8) * 256) + (EEPROM.read(Adresse_9) * 512);
  #ifdef FunktionSerial
    Serial.println(dmxBaseCh);
  #endif
}

// -------------------------------------------------------------------------------------

void eepromschreiben(){
  if(StatusTasteENTER == HIGH){
    int speicher = dmxBaseCh / 2;
    int zs = speicher *2;
    int neu = dmxBaseCh - zs;    // Speichern in bit
    #ifdef FunktionSerial
      Serial.print("dmxBaseCh ist: "); Serial.print(dmxBaseCh);
      Serial.print("\t"); Serial.println(speicher);
      Serial.print("\t"); Serial.println(zs);
      Serial.print("\t"); Serial.println(neu);
      Serial.println("--------------");
    #endif
    if(speicher == 0 && zs == 0){
      stelle = 0;
      goto bailout;
    }
    
    int speicher1;
    speicher1 = speicher / 2;
    int zs1 = speicher1 *2;
    int neu1 = speicher - zs1;    // Speichern in bit
    #ifdef FunktionSerial
      Serial.print("\t"); Serial.println(speicher1);
      Serial.print("\t"); Serial.println(zs1);
      Serial.print("\t"); Serial.println(neu1);
      Serial.println("--------------");
    #endif
    if(speicher1 == 0 && zs1 == 0){
      stelle = 1;
      goto bailout;
    }

    int speicher2;
    speicher2 = speicher1 / 2;
    int zs2 = speicher2 *2;
    int neu2 = speicher1 - zs2;    // Speichern in bit
    #ifdef FunktionSerial
      Serial.print("\t"); Serial.println(speicher2);
      Serial.print("\t"); Serial.println(zs2);
      Serial.print("\t"); Serial.println(neu2);
      Serial.println("--------------");
    #endif
    if(speicher2 == 0 && zs2 == 0){
      stelle = 2;
      goto bailout;
    }

    int speicher3;
    speicher3 = speicher2 / 2;
    int zs3 = speicher3 *2;
    int neu3 = speicher2 - zs3;    // Speichern in bit
    #ifdef FunktionSerial
      Serial.print("\t"); Serial.println(speicher3);
      Serial.print("\t"); Serial.println(zs3);
      Serial.print("\t"); Serial.println(neu3);
      Serial.println("--------------");
    #endif
    if(speicher3 == 0 && zs3 == 0){
      stelle = 3;
      goto bailout;
    }

    int speicher4;
    speicher4 = speicher3 / 2;
    int zs4 = speicher4 *2;
    int neu4 = speicher3 - zs4;    // Speichern in bit
    #ifdef FunktionSerial
      Serial.print("\t"); Serial.println(speicher4);
      Serial.print("\t"); Serial.println(zs4);
      Serial.print("\t"); Serial.println(neu4);
      Serial.println("--------------");
    #endif
    if(speicher4 == 0 && zs4 == 0){
    stelle = 4;
      goto bailout;
    }

    int speicher5;
    speicher5 = speicher4 / 2;
    int zs5 = speicher5 *2;       // Wenn beide hier null dann abbruch
    int neu5 = speicher4 - zs5;    // Speichern in bit
    #ifdef FunktionSerial
      Serial.print("\t"); Serial.println(speicher5);
      Serial.print("\t"); Serial.println(zs5);
      Serial.print("\t"); Serial.println(neu5);
      Serial.println("--------------");
    #endif
    if(speicher5 == 0 && zs5 == 0){
      stelle = 5;
      goto bailout;
    }

    int speicher6;
    speicher6 = speicher5 / 2;
    int zs6 = speicher6 *2;       // Wenn beide hier null dann abbruch
    int neu6 = speicher5 - zs6;    // Speichern in bit
    #ifdef FunktionSerial
      Serial.print("\t"); Serial.println(speicher6);
      Serial.print("\t"); Serial.println(zs6);
      Serial.print("\t"); Serial.println(neu6);
      Serial.println("--------------");
    #endif
    if(speicher6 == 0 && zs6 == 0){
      stelle = 6;
      goto bailout;
    }

    int speicher7;
    speicher7 = speicher6 / 2;
    int zs7 = speicher7 *2;       // Wenn beide hier null dann abbruch
    int neu7 = speicher6 - zs7;    // Speichern in bit
    #ifdef FunktionSerial
      Serial.print("\t"); Serial.println(speicher7);
      Serial.print("\t"); Serial.println(zs7);
      Serial.print("\t"); Serial.println(neu7);
      Serial.println("--------------");
    #endif
    if(speicher7 == 0 && zs7 == 0){
      stelle = 7;
      goto bailout;
    }

    int speicher8;
    speicher8 = speicher7 / 2;
    int zs8 = speicher8 *2;       // Wenn beide hier null dann abbruch
    int neu8 = speicher7 - zs8;    // Speichern in bit
    #ifdef FunktionSerial
      Serial.print("\t"); Serial.println(speicher8);
      Serial.print("\t"); Serial.println(zs8);
      Serial.print("\t"); Serial.println(neu8);
      Serial.println("--------------");
    #endif
    if(speicher8 == 0 && zs8 == 0){
      stelle = 8;
      goto bailout;
    }

    int speicher9;
    speicher9 = speicher8 / 2;
    int zs9 = speicher9 *2;       // Wenn beide hier null dann abbruch
    int neu9 = speicher8 - zs9;    // Speichern in bit
    #ifdef FunktionSerial
      Serial.print("\t"); Serial.println(speicher9);
      Serial.print("\t"); Serial.println(zs9);
      Serial.print("\t"); Serial.println(neu9);
      Serial.println("--------------");
    #endif
    if(speicher9 == 0 && zs9 == 0){
      stelle = 9;
      goto bailout;
    }

    
    bailout:
    #ifdef FunktionSerial
      Serial.print("Bit: ");
    #endif
    
    if(stelle == 9){
      #ifdef FunktionSerial
        Serial.print(neu9);Serial.print(neu8);Serial.print(neu7);Serial.print(neu6);Serial.print(neu5);Serial.print(neu4);Serial.print(neu3);Serial.print(neu2);Serial.print(neu1);Serial.println(neu);
      #endif
      EEPROM.write(Adresse_9, neu9);EEPROM.write(Adresse_8, neu8);EEPROM.write(Adresse_7, neu7);EEPROM.write(Adresse_6, neu6);EEPROM.write(Adresse_5, neu5);EEPROM.write(Adresse_4, neu4);EEPROM.write(Adresse_3, neu3);EEPROM.write(Adresse_2, neu2);EEPROM.write(Adresse_1, neu1);EEPROM.write(Adresse_0, neu);
    }
    if(stelle == 8){
      #ifdef FunktionSerial
        Serial.print(neu8);Serial.print(neu7);Serial.print(neu6);Serial.print(neu5);Serial.print(neu4);Serial.print(neu3);Serial.print(neu2);Serial.print(neu1);Serial.println(neu);
      #endif
      EEPROM.write(Adresse_9, 0);EEPROM.write(Adresse_8, neu8);EEPROM.write(Adresse_7, neu7);EEPROM.write(Adresse_6, neu6);EEPROM.write(Adresse_5, neu5);EEPROM.write(Adresse_4, neu4);EEPROM.write(Adresse_3, neu3);EEPROM.write(Adresse_2, neu2);EEPROM.write(Adresse_1, neu1);EEPROM.write(Adresse_0, neu);
    }
    if(stelle == 7){
      #ifdef FunktionSerial
        Serial.print(neu7);Serial.print(neu6);Serial.print(neu5);Serial.print(neu4);Serial.print(neu3);Serial.print(neu2);Serial.print(neu1);Serial.println(neu);
      #endif
      EEPROM.write(Adresse_9, 0);EEPROM.write(Adresse_8, 0);EEPROM.write(Adresse_7, neu7);EEPROM.write(Adresse_6, neu6);EEPROM.write(Adresse_5, neu5);EEPROM.write(Adresse_4, neu4);EEPROM.write(Adresse_3, neu3);EEPROM.write(Adresse_2, neu2);EEPROM.write(Adresse_1, neu1);EEPROM.write(Adresse_0, neu);
    }
    if(stelle == 6){
      #ifdef FunktionSerial
        Serial.print(neu6);Serial.print(neu5);Serial.print(neu4);Serial.print(neu3);Serial.print(neu2);Serial.print(neu1);Serial.println(neu);
      #endif
      EEPROM.write(Adresse_9, 0);EEPROM.write(Adresse_8, 0);EEPROM.write(Adresse_7, 0);EEPROM.write(Adresse_6, neu6);EEPROM.write(Adresse_5, neu5);EEPROM.write(Adresse_4, neu4);EEPROM.write(Adresse_3, neu3);EEPROM.write(Adresse_2, neu2);EEPROM.write(Adresse_1, neu1);EEPROM.write(Adresse_0, neu);
    }
    if(stelle == 5){
      #ifdef FunktionSerial
        Serial.print(neu5);Serial.print(neu4);Serial.print(neu3);Serial.print(neu2);Serial.print(neu1);Serial.println(neu);
      #endif
      EEPROM.write(Adresse_9, 0);EEPROM.write(Adresse_8, 0);EEPROM.write(Adresse_7, 0);EEPROM.write(Adresse_6, 0);EEPROM.write(Adresse_5, neu5);EEPROM.write(Adresse_4, neu4);EEPROM.write(Adresse_3, neu3);EEPROM.write(Adresse_2, neu2);EEPROM.write(Adresse_1, neu1);EEPROM.write(Adresse_0, neu);
    }
    if(stelle == 4){
      #ifdef FunktionSerial
        Serial.print(neu4);Serial.print(neu3);Serial.print(neu2);Serial.print(neu1);Serial.println(neu);
      #endif
      EEPROM.write(Adresse_9, 0);EEPROM.write(Adresse_8, 0);EEPROM.write(Adresse_7, 0);EEPROM.write(Adresse_6, 0);EEPROM.write(Adresse_5, 0);EEPROM.write(Adresse_4, neu4);EEPROM.write(Adresse_3, neu3);EEPROM.write(Adresse_2, neu2);EEPROM.write(Adresse_1, neu1);EEPROM.write(Adresse_0, neu);
    }
    if(stelle == 3){
      #ifdef FunktionSerial
        Serial.print(neu3);Serial.print(neu2);Serial.print(neu1);Serial.println(neu);
      #endif
      EEPROM.write(Adresse_9, 0);EEPROM.write(Adresse_8, 0);EEPROM.write(Adresse_7, 0);EEPROM.write(Adresse_6, 0);EEPROM.write(Adresse_5, 0);EEPROM.write(Adresse_4, 0);EEPROM.write(Adresse_3, neu3);EEPROM.write(Adresse_2, neu2);EEPROM.write(Adresse_1, neu1);EEPROM.write(Adresse_0, neu);
    }
    if(stelle == 2){
      #ifdef FunktionSerial
        Serial.print(neu2);Serial.print(neu1);Serial.println(neu);
      #endif
      EEPROM.write(Adresse_9, 0);EEPROM.write(Adresse_8, 0);EEPROM.write(Adresse_7, 0);EEPROM.write(Adresse_6, 0);EEPROM.write(Adresse_5, 0);EEPROM.write(Adresse_4, 0);EEPROM.write(Adresse_3, 0);EEPROM.write(Adresse_2, neu2);EEPROM.write(Adresse_1, neu1);EEPROM.write(Adresse_0, neu);
    }
    if(stelle == 1){
      #ifdef FunktionSerial
        Serial.print(neu1);Serial.println(neu);
      #endif
      EEPROM.write(Adresse_9, 0);EEPROM.write(Adresse_8, 0);EEPROM.write(Adresse_7, 0);EEPROM.write(Adresse_6, 0);EEPROM.write(Adresse_5, 0);EEPROM.write(Adresse_4, 0);EEPROM.write(Adresse_3, 0);EEPROM.write(Adresse_2, 0);EEPROM.write(Adresse_1, neu1);EEPROM.write(Adresse_0, neu);
    }
    if(stelle == 0){
      #ifdef FunktionSerial
        Serial.println(neu);
      #endif
      EEPROM.write(Adresse_9, 0);EEPROM.write(Adresse_8, 0);EEPROM.write(Adresse_7, 0);EEPROM.write(Adresse_6, 0);EEPROM.write(Adresse_5, 0);EEPROM.write(Adresse_4, 0);EEPROM.write(Adresse_3, 0);EEPROM.write(Adresse_2, 0);EEPROM.write(Adresse_1, 0);EEPROM.write(Adresse_0, neu);   // Wert in den EEPROM schreiben
    }
  }
}

// -------------------------------------------------------------------------------------

void EEPROMschreibenErstesMal(){
  // DMX-Adresse
  EEPROM.write(Adresse_9, 0);EEPROM.write(Adresse_8, 0);EEPROM.write(Adresse_7, 0);EEPROM.write(Adresse_6, 0);EEPROM.write(Adresse_5, 0);EEPROM.write(Adresse_4, 0);EEPROM.write(Adresse_3, 0);EEPROM.write(Adresse_2, 0);EEPROM.write(Adresse_1, 0);EEPROM.write(Adresse_0, 1);   // Wert in den EEPROM schreiben
  EEPROM.write(Adresse_10, 1);    // Speicher Hauptmenü DMX-Modus oder Autoprogramm
  EEPROM.write(Adresse_11, 1);    // Speicher Autoprogramm
  EEPROM.write(Adresse_12, 7);    // Speicher Channel Auswahl
}
