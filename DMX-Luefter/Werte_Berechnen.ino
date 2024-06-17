void zaehlen(){     // DMX Adresse bei Wert Überschreitung (Hoch / Runter zählen) verändern 
  dmxwertzeigen();
  if(dmxBaseCh < 1){
    dmxBaseCh = 512;
  }
  if(dmxBaseCh >= 513){
    dmxBaseCh = 1;
  }
  #ifdef FunktionSerial
    Serial.print("DMX-Adresse: ");
    Serial.println(dmxBaseCh);
  #endif
}

// -------------------------------------------------------------------------------------


void dmxBaseChberechnen(){
  if(StatusTasteUP == HIGH){
    dmxBaseCh++;
  }
  if(StatusTasteDOWN == HIGH){
    dmxBaseCh--;  
  }
  zaehlen();
}
