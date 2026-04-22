# TermôPets: Sistema Iot para Monitoramento da Temperatura do Asfalto a fim de proteger animais em ambientes urbanos.

**Faculdade de Computação e Informática Universidade Presbiteriana Mackenzie (UPM) – São Paulo, SP – Brazil**

Grupo: 5

Integrantes:
- Aline Soares Cordeiro
- Fernanda Sther Magalhães Lopes
- Mayara Alves da Silva
  
# 1. Descrição 
Esse trabalho tem como finalidade desenvolver um sistema com base na Internet das Coisas (IoT) intitulado “TermôPets”, dedicado ao acompanhamento de temperatura em tempo real da principal superfície urbana, o asfalto. 

## 1.1 Funcionamento 
O sistema utiliza sensores infravermelhos de temperatura, instalados em pontos estratégicos urbanos como postes, aptos a medir a temperatura do terreno sem precisar de ter uma proximidade física. As informações obtidas serão direcionadas para uma plataforma digital que indicará a temperatura no trajeto desejado, mostrará um trajeto seguro  e enviará alertas para os tutores, se necessário. Além disso, pretendemos utilizar ícones visuais urbanos, como placas de LEDs nos postes, que indicarão a temperatura atual. O propósito do sistema é auxiliar na construção de uma cidade mais acessível, saudável e sustentável, impulsionando uma atividade mais segura para pessoas e animais.

# 2. Estrutura do projeto
- code/ --> código do ESP32
- docs/ --> documentação do projeto
- images/ --> diagrama e imagens

# 3. Sobre o código
O código foi desenvolvido para o ESP32 e realiza a seguintes tarefas:

- Conexão com Wi-fi
- Se comunicar com o broker MQTT
- Enviar as informações de temperatura
- Controlas o LED como atuador

# 4. Hardware escolhido
- ESP32
- Sensor de tempertura chamado MLX90614
- Módulo de LEDs
- Fonte de alimentação

# 5. Comunicação MQTT
No TermôPets, o ESP32 atuará como cliente MQTT, publicando os valores de temperatura em tópicos específicos. Um broker MQTT na nuvem armazenará e distribuirá as mensagens para assinantes, como a plataforma de visualização e aplicativos móveis. A utilização de mensagens retidas permitirá que novos clientes recebam a última temperatura publicada imediatamente após a conexão.

# 6. Como executar ?
1. Configurar Wi-fi no código
2. Configurar o broker MQTT
3. Fazer upload do código no ESP32
4. Monitorar os dados

# 7. Imagens


# 8. Vídeo

