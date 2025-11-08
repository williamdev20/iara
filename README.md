# IARA - Inteligência Assistiva de Reconhecimento Auditivo e gestual

## Visão geral

A **IARA (Inteligência Assistiva de Reconhecimento Auditivo e gestual)** é um colar inteligente que utiliza o ESP32-CAM para capturar sinais em Libras e enviá-los a um backend em Python, onde um modelo de visão computacional identifica os gestos e os converte em **fala em tempo real**.  
O projeto busca reduzir barreiras comunicativas entre pessoas surdas e ouvintes, oferecendo uma solução **portátil, acessível e de baixo custo**, promovendo **autonomia e inclusão** na interação cotidiana e mercado de trabalho.

> Este repositório contém apenas a **simulação no Wokwi**. A versão final será implementada no hardware real.

---

## Materiais utilizados (simulação)

| Componentes   | Função                                                                 |
|---------------|------------------------------------------------------------------------|
| ESP32         | Microcontrolador responsável pelo processamento, controle e conexão    |
| Buzzer        | Indica que o áudio mp3 foi recebido corretamente                       |
| LEDs          | Sinaliza a conexão com o WiFi                                          |
| MicroSD Card  | Armazena os áudios recebidos da API                                    |
| Resistores    | Garantem funcionamento seguro dos LEDs e buzzer no circuito            |
| Protoboard    | Facilita a montagem experimental e validação no simulador              |

---

## Fluxo

### Fluxo Principal: Usuário PCD (Libras) para Ouvinte (Voz)

Este é o fluxo central do dispositivo wearable (colar) e opera da seguinte forma:

1. Captura (Usuário): O usuário surdo-mudo realiza os gestos em Libras em frente à câmera do colar.
2. Transmissão (ESP32-CAM): O módulo ESP32-CAM captura os frames de vídeo (no formato MJPEG) dos gestos.
3. Envio (API): As imagens capturadas são enviadas via rede para uma API de backend desenvolvida em Python.
4. Processamento (IA): No backend, o modelo de Visão Computacional (IA) processa os gestos, identifica os sinais correspondentes em Libras e os converte para texto.
5. Síntese de Voz (TTS): O texto processado é então enviado a uma API de Text-to-Speech (Síntese de Voz).
6. Resposta (Áudio): O ESP32-CAM recebe o arquivo de áudio resultante e o reproduz através de um alto-falante integrado, permitindo que o interlocutor ouvinte compreenda a mensagem.

---

### Fluxo Inverso: Ouvinte (Voz) para Usuário PCD (Via App)

Para permitir que o ouvinte responda ao usuário PCD, um aplicativo móvel complementar (App Mobile) será utilizado:

1. Entrada de Voz (Ouvinte): O interlocutor ouvinte informa uma frase verbalmente no microfone do smartphone onde o aplicativo está instalado.
2. Transcrição (App): O aplicativo utiliza um serviço de reconhecimento de fala (Speech-to-Text) para converter a voz do ouvinte em texto.
3. Tradução (App/Backend): O texto é processado e traduzido para a estrutura da Libras.
4. Exibição (App): O aplicativo exibe a tradução para o usuário PCD, podendo utilizar texto, imagens dos sinais correspondentes ou, idealmente, um avatar 3D que realiza os gestos em Libras.
