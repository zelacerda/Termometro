/*
Termômetro digital
v 1.0 - 21/07/2013
by Zé Lacerda
*/

#include <LiquidCrystal.h> // Biblioteca de funções para o display
LiquidCrystal lcd(12, 11, 2, 3, 4, 5); // Portas que serão usadas pelo display

const int sensorPin = A0; // Porta analógica do sensor de temperatura
float temperatura[3];

int atual = 0; // Temperatura atual
int minima = 0; // Mínima registrada
int maxima = 0; // Máxima registrada

// Função para retornar a leitura do sensor em ºC
float mede() {
  int sensorVal = analogRead(sensorPin);
  float voltagem = (sensorVal/1024.0) * 5.0;
  return (voltagem - .5) * 100;
}

void setup() {
  lcd.begin(16, 2); // Configura o display para 16 colunas e 2 linhas
  lcd.clear(); // Limpa a tela
  
  // Inicia mínima e máxima com a temperatura inicial
  minima = mede();
  maxima = minima;

}

void loop() {

  // Executa três leituras e armazena na variável temperatura
  for (int i=0; i<3; i++) {
    temperatura[i] = mede();
    delay (1000); 
  }
  
  // Pega a média das três leituras
  int atual = (temperatura[0] + temperatura[1] + temperatura[2])/3;
  
  // Verifica se atingiu a máxima ou mínima e ajusta a variável
  if (atual <= minima) {
    minima = atual;
  }
  if (atual >= maxima) {
    maxima = atual;
  }

  // Atualiza o display
  
  lcd.setCursor(0,0); //Posiciona o cursor na primeira linha
  lcd.print("Atual:");
  lcd.print(atual);
  lcd.print(" C  ");
  
  lcd.setCursor(0,1); //Posiciona o cursor na segunda linha
  lcd.print("Min:");
  lcd.print(minima);
  lcd.print("  Max:");
  lcd.print(maxima);
  lcd.print("  ");
}
