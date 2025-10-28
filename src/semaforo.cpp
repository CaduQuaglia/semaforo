// Declaração de váriaveis
// Pinos
const int8_t LED_VERDE = 13;
const int8_t LED_AMARELO = 12;
const int8_t LED_VERMELHO = 11;

unsigned long intervaloLeitura = 0; // Intervalo inicial = 0
unsigned long ultimoTempoLeitura = 0;
int8_t estado = 0; // Começa com verde

// Inicializa as portas do arduino
void setup() {
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
}

// Roda constantemente em loop
void loop() {
  // Inicia contagem de tempo
  unsigned long tempoAtual = millis();

  // Se o intervalo de tempo já foi atingido
  if (tempoAtual - ultimoTempoLeitura >= intervaloLeitura) {
    ultimoTempoLeitura = tempoAtual; // Atualiza o último tempo para o tempo atual
    
    // Para cada estado do semaforo (verde, amarelo, vermelho)
    switch (estado){
      // VERDE
      case 0:
        digitalWrite(LED_VERMELHO, LOW);
        digitalWrite(LED_VERDE, HIGH);
        estado = 1;
        intervaloLeitura = 4000; // Intervalo da luz verde = 4 seg
        break;
      
      // AMARELO
      case 1:
        digitalWrite(LED_VERDE, LOW);
        digitalWrite(LED_AMARELO, HIGH);
        estado = 2;
        intervaloLeitura = 2000; // Intervalo da luz amarela = 2 seg
        break;

      // VERMELHO
      case 2:
        digitalWrite(LED_AMARELO, LOW);
        digitalWrite(LED_VERMELHO, HIGH);
        estado = 0;
        intervaloLeitura = 6000; // Intervalo da luz vermelha = 6 seg
        break;
    }
  }                               
}
