void TasterAuslesen(){
  StatusTasteUP = digitalRead(TasteUP);
  StatusTasteDOWN = digitalRead(TasteDOWN);
  StatusTasteMODE = digitalRead(TasteMODE);
  StatusTasteENTER = digitalRead(TasteENTER);

  // Werte Invertieren
  StatusTasteUP = !StatusTasteUP;
  StatusTasteDOWN = !StatusTasteDOWN;
  StatusTasteMODE = !StatusTasteMODE;
  StatusTasteENTER = !StatusTasteENTER;

  #ifdef FunktionSerial
    Serial.print("UP"); Serial.print("\t");
    Serial.print("DOWN"); Serial.print("\t");
    Serial.print("MODE"); Serial.print("\t");
    Serial.print("Enter"); Serial.println("\t");
    Serial.print(StatusTasteUP); Serial.print("\t");
    Serial.print(StatusTasteDOWN); Serial.print("\t");
    Serial.print(StatusTasteMODE); Serial.print("\t");
    Serial.print(StatusTasteENTER); Serial.println("\t");
  #endif
  
  delay(100);
}

// -------------------------------------------------------------------------------------

void TasterAuslesenDMXModus(){
  StatusTasteMODE = digitalRead(TasteMODE);
  StatusTasteENTER = digitalRead(TasteENTER);

  // Werte Invertieren
  StatusTasteMODE = !StatusTasteMODE;
  StatusTasteENTER = !StatusTasteENTER;
  
  #ifdef FunktionSerial
    Serial.println(StatusTasteMODE);
    Serial.println(StatusTasteENTER);
  #endif
  delay(50);
}
