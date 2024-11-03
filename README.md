<h1 id="introduction">Piano LEDs</h1>

Bem-vindo ao meu projeto de integração entre Arduino, fita LED e um piano digital!

<a href="https://www.youtube.com/watch?v=7a4QGCJzvwk">
  <img src="https://github.com/user-attachments/assets/359d1bb8-9a3f-46aa-8d08-0e0f64671444" alt="Vídeo demonstrativo">
</a>

Este projeto tem como propósito criar uma experiência imersiva e visual ao tocar piano, onde cada tecla pressionada acende LEDs correspondentes em uma fita RGB, sincronizando luz e som em uma performance única. Além disso, possibilita a produção de vídeos artísticos que combinam música e efeitos de iluminação, resultando em uma obra visual e sonora cativante!<br>

Este repositório oferece um guia passo a passo para você aprender a:

<ul>
  <li>Utilizar o Arduino: Configurar e programar seu Arduino para comunicação com o piano digital via MIDI.</li>
  <li>Conexões Físicas: Instruções detalhadas sobre como conectar o Arduino ao piano, à fita LED e ao computador, garantindo uma montagem simples e eficiente.</li>
  <li>Controlar a Fita LED RGB: Acender LEDs correspondentes às teclas pressionadas no piano, criando uma visualização dinâmica e colorida.</li>
  <li>Edição de Vídeo: Dicas e técnicas para capturar e editar sua apresentação, destacando a interação entre música e iluminação.</li>
</ul>

Sinta-se à vontade para explorar, contribuir e compartilhar suas próprias criações!

<!-- TOC -->
<h1>Índice</h1>

- [Hardwares Utilizados](#hardwares-utilizados)
  - [Arduino: Leonardo](#arduino-leonardo)
  - [Fita LED Endereçável: WS2812B](#fita-led-endereçável-ws2812b)
  - [Piano Digital: Yamaha P-45](#piano-digital-yamaha-p-45)
  - [Hub USB (Opcional)](#hub-usb-opcional)
- [Softwares Utilizados](#softwares-utilizados)
  - [Softwares Para Piano e LED](#softwares-para-piano-e-led)
    - [Arduino IDE](#arduino-ide)
    - [loopMIDI](#loopmidi)
    - [Midi-OX](#midi-ox)
    - [Hairless MIDI](#hairless-midi)
  - [Softwares para Produção de Vídeo](#softwares-para-produção-de-vídeo)
    - [Gravador MIDI e Editor de Áudio](#gravador-midi-e-editor-de-áudio)
    - [VST](#vst)
    - [Visualizador MIDI](#visualizador-midi)
    - [Editor de Vídeo](#editor-de-vídeo)
- [Configurando o Hardware](#configurando-o-hardware)
  - [Piano](#piano)
  - [Arduino](#arduino)
  - [Fita LED](#fita-led)
    - [Grupo 1](#grupo-1)
    - [Grupo 2](#grupo-2)
  - [Hub USB](#hub-usb)
- [Configurando os Softwares para Controle de LEDs](#configurando-os-softwares-para-controle-de-leds)
  - [Configurando o Arduino IDE](#configurando-o-arduino-ide)
  - [Configurando o loopMIDI](#loopmidi-1)
  - [Configurando o Midi-OX](#midi-ox-1)
  - [Configurando o HairlessMIDI](#hairlessmidi-1)
- [Configurando os Softwares para Edição de Vídeo](#configurando-os-softwares-para-edição-de-vídeo)
  - [Configurando o Reaper](#reaper)
    - [Gravando e Exportando um Arquivo MIDI](#gravando-e-exportando-um-arquivo-midi)
    - [Renderizando o Áudio da Performance](#renderizando-o-áudio-da-performance)
  - [Configurando o See Music](#see-music)
  - [Configurando o DaVinci Resolve](#davinci-resolve)
- [Escolhendo o Modo, Cores e Intensidade dos LEDs](#escolhendo-o-modo-cores-e-intensidade-dos-leds)
    - [Mudar a Cor](#mudar-a-cor)
    - [Mudar a Intensidade](#mudar-a-intensidade)
  - [Modos](#modos)
    - [sketch1: Cor Única](#sketch1-cor-única)
    - [sketch2: Uma Cor para Teclas Brancas e Outra para Teclas Pretas](#sketch2-uma-cor-para-teclas-brancas-e-outra-para-teclas-pretas)
    - [sketch3: Duas Cores Específicas Aleatórias](#sketch3-duas-cores-específicas-aleatórias)
    - [sketch4: Cores Aleatórias](#sketch4-cores-aleatórias)
- [Como Colocar o Sistema para Funcionar Novamente?](#como-colocar-o-sistema-para-funcionar-novamente)


<!-- /TOC -->

<h1>Hardwares Utilizados</h1>

## Arduino: Leonardo

<div align="start">
<ul>
  
<kbd> <a href="#"><img src="https://github.com/user-attachments/assets/2acb8638-9ad7-4238-b9e1-4f55a3258423" width="300px" alt="Arduino Leonardo"> </a> </kbd>

O Arduino Leonardo é uma opção acessível e atende muito bem aos requisitos do projeto, mas você também pode utilizar outros modelos de Arduino.<br>

</ul>
</div>

<ul>

> [!WARNING]
> Não é recomendado o uso do Arduino UNO ou modelos semelhantes, pois sua taxa de baud não atende aos requisitos do projeto, causando problemas de latência e mau funcionamento.
</ul>

## Fita LED Endereçável: WS2812B

<div align="start">
<ul>

<kbd> <a href="#"><img src="https://github.com/user-attachments/assets/8211fe75-e4f5-44bb-9106-f9aa4f318341" width="300px" alt="Fita LED WS2812B"> </a> </kbd>

Você pode utilizar qualquer <a href="https://github.com/FastLED/FastLED/wiki/Chipset-reference">fita LED compatível</a> com a biblioteca FastLED utilizada no projeto.

</ul>
</div>

## Piano Digital: Yamaha P-45

<div align="start">
<ul>
<kbd> <img src="https://br.yamaha.com/pt/files/P-45_119_H_P-45_540_540_2b0fd46e557ff681962a196c0e4db30e.jpg?impolicy=resize&imwid=735&imhei=735" width="300px" alt="Piano Yamaha P-45"> </kbd>
</ul>
</div>
<ul>
Você pode utilizar qualquer piano digital que possua saída MIDI.
</ul>

## Hub USB (Opcional)

<div align="start">
<ul>
<kbd> <a href="#"><img src="https://github.com/user-attachments/assets/53c2e544-1451-4162-9ff6-3c1de8e8122b" width="300px" alt="Hub USB"> </a> </kbd> 
</ul>
</div>
<ul>
Qualquer hub USB pode ser utilizado para facilitar a conexão entre os dispositivos, evitando a ocupação de várias portas no computador.
</ul>

<h1 id="softwares">Softwares Utilizados</h1>
<h2 id="softwares-piano">Softwares Para Piano e LED</h2>

<ul>
  
<h3><a href="https://www.arduino.cc/en/software">Arduino IDE</a></h3>

<kbd> <a href="#"><img src="https://github.com/user-attachments/assets/3738a4d7-c9cc-4884-8814-cb0bdf4a693a" width="200px" alt="Arduino IDE"> </a> </kbd>

Para programar o Arduino com o código do projeto.

<h3><a href="https://www.tobias-erichsen.de/software/loopmidi.html">loopMIDI</a></h3>

<kbd> <a href="#"><img src="https://github.com/user-attachments/assets/f99a05d3-f861-4944-a017-013648497d58" width="200px" alt="loopMIDI"> </a> </kbd>

Utilizado para criar múltiplas portas MIDI adicionais no computador.

<h3><a href="http://www.midiox.com">Midi-OX</a> </h3>

<kbd> <a href="#"><img src="https://github.com/user-attachments/assets/12de1c16-30ec-4e03-8994-f3098215ae6e" width="200px" alt="Midi-OX"> </a> </kbd>

Roteia as as mensagens MIDI enviadas pelo piano para as portas MIDI criadas.

<h3><a href="https://projectgus.github.io/hairless-midiserial/">Hairless MIDI</a></h3>

<kbd> <a href="#"><img src="https://github.com/user-attachments/assets/49d1a5e3-0669-44a0-afe0-c71f7e7f8490" width="200px" alt="Hairless MIDI"> </a> </kbd>

Transmite as mensagens MIDI do piano para a porta serial COM do Arduino.

<h2 id="softwares-video">Softwares para Produção de Vídeo</h2>

<ul>
  
<h3>Gravador MIDI e Editor de Áudio</h3>

<kbd> <a href="#"><img src="https://github.com/user-attachments/assets/5701b300-ebec-4603-a015-e0e26693a472" width="200px" alt="Reaper"> </a> </kbd>

<a id="reaper" href="https://www.reaper.fm/">Reaper:</a> Gravador MIDI e editor de áudio. <br>
  
Você precisará do Reaper para gravar sua performance em formato MIDI (nota por nota tocada), gerando a base para a visualização em vídeo. Ele também permite renderizar o áudio, caso não grave o som fisicamente.<br><br>
Outros programas podem ser utilizados para essas funções.

</ul>

<h3>VST</h3>

<ul>
<kbd> <a href="#"><img src="https://github.com/user-attachments/assets/95e7d65a-0c0d-43bd-9375-22628bd457fd" width="600px" alt="Piano VST"> </a> </kbd>

Caso não consiga gravar um áudio de alta qualidade do seu piano, você pode utilizar bibliotecas ou VSTs de piano para obter um som limpo e claro. Busque por "Free Piano VST" para encontrar softwares gratuitos, ou opte por opções pagas.<br><br>
Para importar no <a href="#reaper">Reaper</a>, o VST precisa ser instalado como plugin. O processo de instalação pode variar conforme o software.

</ul>

<h3>Visualizador MIDI</h3>

<ul>
<kbd> <img src="https://github.com/user-attachments/assets/69144623-7cbd-47d6-9c5a-bb1d4a670feb" width="600px" alt="Visualizador MIDI"> </kbd>
  
<a href="https://www.seemusicapp.com">SeeMusic:</a> Visualizador de notas MIDI (VFX).<br><br>
Você também pode usar outros visualizadores, como <a href="https://synthesiagame.com/download">Synthesia</a> e <a href="https://embers.app/">Embers</a>. Esses softwares são pagos, embora o Embers e o SeeMusic ofereçam versões com marca d'água.

</ul>

<h3>Editor de Vídeo</h3>

<ul>
<kbd><img src="https://github.com/user-attachments/assets/124a451e-4805-4fa5-83c7-1c541ae90f35" width="600px" alt="Davinci Resolve"> </kbd>

<a href="https://www.blackmagicdesign.com/br/products/davinciresolve">DaVinci Resolve:</a> Usado para criar o vídeo final, reunindo todos os arquivos produzidos pelos programas anteriores.

A versão gratuita permite fazer todas as edições necessárias para a produção de um vídeo, como o exemplo apresentado neste repositório. Caso prefira, qualquer outro editor de vídeo também pode ser utilizado para essa função.

</ul>


<h1>Configurando o Hardware</h1>

<ul>
<div align="center">
<kbd> <img src="https://github.com/user-attachments/assets/e02bffd7-d3c7-4d57-ae8a-f942f9e9a6fc" width="600px" alt="Diagrama do Hardware"> </kbd>
</div>
<br>
</ul>

<h2>Piano</h2>

<ul>
  
<kbd> <img src="https://github.com/user-attachments/assets/a847d7d4-9165-4da8-a5f8-19374bc844a2" width="400px" alt="Entrada USB-B do Piano Digital"> </kbd>
<p>*Entrada USB-B do Piano Digital.</p>

<li><strong>Piano:</strong> conectado por um cabo <strong>USB A-B</strong> ao Hub USB.</li>

</ul>

<h2>Arduino</h2>

<ul>

<kbd> <img src="https://github.com/user-attachments/assets/a0c9eef7-392f-4216-bfeb-7e950e8d3b49" width="300px" alt="Arduino"> </kbd>

<li><strong>Arduino:</strong> conectado por um cabo <strong>USB 2.0 A-B</strong> ao Hub USB.</li>

</ul>

<h2>Fita LED</h2>

<ul>

<kbd><img src="https://github.com/user-attachments/assets/c04cc648-48d3-472c-898b-933dc06eb27b" width="400px" alt="Conector da Fita LED"> </kbd>

<li>Utilize o lado da fita que possui o conector <strong>Fêmea</strong>, pois o código foi estruturado com base nesse lado.</li>

<li><strong>Fita LED:</strong> possui dois grupos de cabos separados.</li>

<h3><strong>Grupo 1</strong></h3>
<ul>
<h4>Cabo <strong>Branco (-)</strong> e Cabo <strong>Vermelho (+)</strong> (cabos de alimentação).</h2>

  <kbd> <img src="https://github.com/user-attachments/assets/3668830c-486d-424f-a873-d288978ecc05" width="400px" alt="Cabos de Alimentação da Fita LED"> </kbd>

  <li>Esses cabos foram soldados a um conector USB, que é conectado ao Hub USB. A fita LED precisa dessa fonte de alimentação, pois a energia fornecida pelo Arduino não é suficiente.</li>
  
</ul>

<h3><strong>Grupo 2</strong></h3>

<ul>
  <h4>Cabo <strong>Branco (-)</strong>, Cabo <strong>Vermelho (+)</strong> e Cabo <strong>Verde</strong> (cabo de dados).</h2>
  
  <kbd> <img src="https://github.com/user-attachments/assets/9a707d9c-be64-40b4-bcb5-4480620146c1" width="400px" alt="Cabos de Dados da Fita LED"> </kbd>
  
  <li>Conecte o adaptador que separa o grupo de fios em fios individuais ao conector fêmea da fita LED.</li><br>

  <kbd> <img src="https://github.com/user-attachments/assets/383dc900-95ca-4546-8124-276ae191e5e7" width="400px" alt="Fios Isolados da Fita LED"> </kbd>

  <li>Recomenda-se encapar os conectores dos cabos <strong>branco e vermelho</strong> com fita isolante para evitar curto-circuito, já que esses não serão utilizados.</li>
  <li>O cabo <strong>Verde</strong> (cabo de dados) é conectado a uma das saídas <strong>Digitais (PWM)</strong> do Arduino (recomenda-se a porta 7, conforme utilizada no código).</li>

</ul>

</ul>

<h2>Hub USB</h2>

<ul>
  
<li>Conectado ao <strong>PC</strong>.</li>
<br>
  
> [!NOTE]  
> Você pode substituir o Hub USB conectando os dispositivos diretamente ao PC, mas isso ocupará muitas entradas e pode não ser prático.
  
</ul>


<h1>Configurando os Softwares para Controle de LEDs</h1>

<ul>
<div align="center">
<kbd> <img src="https://github.com/user-attachments/assets/bed53266-9ea8-43e8-80cf-7427a717f536" width="600px" alt="Diagrama de Software"> </kbd>
</div>

<h2>Configurando o Arduino IDE</h2>

Escolha algum <a href="#">"sketch"</a> deste repositório e abra-o na <a href="https://www.arduino.cc/en/software">Arduino IDE</a>.<br>

Vá em Tools -> Board -> Arduino AVR Boards -> (Selecione o seu Arduino).

<kbd> <a href="#"><img src="https://github.com/user-attachments/assets/e56f029e-04ab-4a2b-9bff-9bf29674181f" width="600px" alt="Selecionando a placa Arduino"> </a> </kbd>

Em seguida, vá novamente em Tools -> Port -> (Selecione a porta COM na qual seu Arduino está conectado).

<kbd> <a href="#"><img src="https://github.com/user-attachments/assets/d94b0a55-065f-4ae6-acf3-6347d7e26439" width="600px" alt="Selecionando a porta COM do Arduino"> </a> </kbd>

Verifique se o Arduino está corretamente conectado, (Selecione neste menu, caso necessário) — o símbolo do USB deve estar verde, como na figura abaixo.

<kbd> <a href="#"><img src="https://github.com/user-attachments/assets/45f6dd6e-be03-4b07-aba3-0f9c42d817d3" width="600px" alt="Conexão bem-sucedida do Arduino"> </a> </kbd>

Agora, vamos instalar as bibliotecas para controlar a fita LED e receber comandos MIDI do piano.

Clique no ícone de "Bibliotecas" e pesquise os nomes das bibliotecas necessárias para o projeto, depois instale-as.

<kbd> <a href="#"><img src="https://github.com/user-attachments/assets/2d10d170-0ea6-4e49-b5ee-0fae146e1120" width="600px" alt="Instalando bibliotecas no Arduino IDE"> </a> </kbd>

**FastLED**

<kbd> <a href="https://github.com/FastLED/FastLED"><img src="https://github.com/user-attachments/assets/ee872414-dd45-4972-af64-44a987092159" width="400px" alt="Biblioteca FastLED"> </a> </kbd>

**MIDI Library**

<kbd> <a href="https://github.com/FortySevenEffects/arduino_midi_library"><img src="https://github.com/user-attachments/assets/7b98d116-bd52-4f5c-87f0-02796186e582" width="400px" alt="Biblioteca MIDI"> </a> </kbd>

> [!WARNING]
> Feche todos os outros programas que utilizem o Arduino (como o Hairless MIDI), pois o código não conseguirá ser enviado caso estejam abertos.

Pressione o botão "Verify/Compile" (ícone 1) para compilar e verificar o código, e em seguida o botão "Upload" (ícone 2) para enviar o código para o Arduino.

<kbd> <a href="#"><img src="https://github.com/user-attachments/assets/030068bc-08c4-4330-b7b2-4a57ffeee5d1" width="400px" alt="Botões de Compilar e Upload"> </a> </kbd>

Se essa mensagem que <ins>parece</ins> um erro for mostrada, isso indica que o código foi carregado com sucesso.

<kbd> <a href="#"><img src="https://github.com/user-attachments/assets/a02d5cb9-e14d-4275-bd33-5f062c91d6c8" width="800px" alt="Mensagem de erro bem-sucedido"> </a> </kbd>

</ul>

<h2>Configurando o loopMIDI</h2>
<ul>

O loopMIDI é utilizado para criar portas MIDI virtuais. Clique no botão "Add Port" (seta 1), como mostrado abaixo, para adicionar novas portas MIDI.

<kbd> <img src="https://github.com/user-attachments/assets/3c498acb-eaf5-43f2-a5ef-241b51f5613c" width="600px" alt="Adicionando portas MIDI"> </kbd>

Para renomear as portas, selecione a porta desejada (seta 1) e insira um novo nome no campo "New port-name" (seta 2). Duas portas são suficientes para garantir o funcionamento do sistema de LEDs e permitir o uso das mensagens MIDI em todos os programas.

<kbd> <img src="https://github.com/user-attachments/assets/4b29a9c3-29d7-4681-9388-e661e02ab6fe" width="600px" alt="Renomeando portas MIDI"> </kbd>

Para excluir uma porta, selecione-a e clique no botão de menos. O botão quadrado desativa a porta, impedindo que ela receba mensagens MIDI.

</ul>

<h2>Configurando o Midi-OX</h2>
<ul>
  
Para configurar o MIDI-OX, abra o menu “Options” e selecione “MIDI Devices” (seta 1).

<kbd> <img src="https://github.com/user-attachments/assets/2486d56e-ca28-4565-b262-b073e08d458b" width="600px" alt="Configurando dispositivos MIDI"> </kbd>

<li>No campo "MIDI Inputs", selecione a entrada do piano digital (seta 1, na figura abaixo).</li>
<li>Em "MIDI Outputs", selecione as portas criadas com o loopMIDI (setas 2).</li>
<li>Finalize a configuração clicando em “OK” (seta 3), permitindo que as mensagens MIDI do piano digital sejam redirecionadas para o sistema do microcontrolador.</li>

<kbd> <img src="https://github.com/user-attachments/assets/0cdedb9c-b693-45cb-a257-c1344cfaafd5" width="600px" alt="Configuração de dispositivos MIDI"> </kbd>

Toque as teclas do seu instrumento; as notas devem aparecer no prompt, conforme ilustrado abaixo.

<kbd> <img src="https://github.com/user-attachments/assets/03d2442f-a1c7-4057-b692-8fe89d70a1fb" width="600px" alt="Prompt mostrando notas MIDI"> </kbd>

</ul>

<h2>Configurando o HairlessMIDI</h2>
<ul>
  
No Hairless MIDI, selecione a porta COM do Arduino em "Serial Port" (seta 1), conforme ilustrado na figura abaixo.

<kbd> <img src="https://github.com/user-attachments/assets/616cc65d-1c80-4385-a221-94370376dd2e" width="600px" alt="Configurando porta serial no Hairless MIDI"> </kbd>

Em "MIDI In", escolha uma das portas criadas pelo loopMIDI (seta 1, na figura abaixo), garantindo o direcionamento correto das mensagens MIDI para o sistema do microcontrolador.

<kbd> <img src="https://github.com/user-attachments/assets/5666aa94-1dde-4286-a89b-77c2837892b2" width="600px" alt="Configurando MIDI In no Hairless MIDI"> </kbd>

Após realizar essas configurações iniciais, não será necessário repeti-las em cada uso. Basta abrir os programas na sequência correta (ver instruções no final da página).

</ul>

<h1>Configurando os Softwares para Edição de Vídeo</h1>
<ul>
  <h2>Configurando o Reaper</h2>
  
  <h3>Gravando e Exportando um Arquivo MIDI</h3>
  
  De acordo com a ilustração da figura abaixo, clique duas vezes na região vazia ou, com o botão direito, escolha a opção "Insert New Track" para criar uma faixa onde o MIDI será gravado, conforme indicado pela seta 1.
  
  <kbd><img src="https://github.com/user-attachments/assets/6ab0fa56-c768-432f-882c-b188672cf037" width="600px"></kbd>
  
  Em seguida, conforme demonstrado na figura abaixo, clique no botão "Record Arm/Disarm" para acessar as opções de configuração de entrada do instrumento, conforme indicado pela seta 1.
  
  <kbd><img src="https://github.com/user-attachments/assets/35d1b5ed-d591-4f16-9b3e-fe09ea09162d" width="600px"></kbd>
  
  Na tela do sistema, ilustrada na figura abaixo, configure o instrumento clicando no botão "IN FX" (seta 1), selecione o tipo de entrada de mídia de áudio e escolha "Input MIDI". Marque uma das portas criadas pelo loopMIDI e MIDI-OX que estejam disponíveis (seta 2). Em seguida, escolha qualquer canal (Channel) para realizar a gravação.
  
  <kbd><img src="https://github.com/user-attachments/assets/e56717f3-daf3-4cd9-9155-a255c221f510" width="600px"></kbd>
  
  Para iniciar a gravação das notas do instrumento, clique no botão de gravação ao lado dos controles de reprodução de áudio ou use o atalho CTRL+L, conforme indicado na seta 1 da figura abaixo.
  
  <kbd><img src="https://github.com/user-attachments/assets/983a73f2-a690-4e29-846f-afffb649c67d" width="600px"></kbd>
  
  Após finalizar a gravação (aperte novamente o botão de gravação), para salvar o arquivo, clique em "File" no menu suspenso e, em seguida, em "Export Project MIDI", conforme indicado pela seta 1 na figura abaixo.
  
  <kbd><img src="https://github.com/user-attachments/assets/7ebaafc5-1221-4bd9-aa36-2326035f50b1" width="600px"></kbd>
  
  Na figura abaixo, uma janela de opções para exportação é aberta. Você pode escolher quais faixas deseja renderizar, alterar o nome e o diretório do arquivo, além de outras opções disponíveis.
  
  <kbd><img src="https://github.com/user-attachments/assets/6d2815cc-02cc-4413-adf7-4268c110f678" width="600px"></kbd>
  
  <h3>Renderizando o Áudio da Performance</h3>
  
  Nesta etapa, vamos utilizar a biblioteca/VST que você escolheu anteriormente. (Você pode pular esta etapa caso tenha gravado o áudio do seu instrumento com sua câmera ou microfone).
  
  Clique no botão "FX".
  
  <kbd><img src="https://github.com/user-attachments/assets/c8bc6925-1640-4850-9a76-72df723cc7e0" width="600px"></kbd>
  
  Pesquise pelo nome do seu VST e clique sobre ele duas vezes.
  
  <kbd><img src="https://github.com/user-attachments/assets/e5b6f33f-f964-4862-8a88-98b183cbb333" width="600px"></kbd>
  
  > [!NOTE]  
  > Você pode pesquisar como adicionar e configurar a sua biblioteca/VST específica no YouTube ou na sua ferramenta de pesquisa. Provavelmente você encontrará um tutorial sobre isso!
  
  Após fazer as configurações necessárias, vá em "File -> Render" (CTRL + ALT + R).
  
  <kbd><img src="https://github.com/user-attachments/assets/1153635e-43e7-4105-99a0-41bbb4c75b48" width="600px"></kbd>
  
  Agora, selecione o diretório (indicado pela seta 1), dê um nome para o seu arquivo (seta 2) e escolha um formato (seta 3). Em seguida, clique em "Render File".
  
  <kbd><img src="https://github.com/user-attachments/assets/03392b6c-c098-4c1f-97f4-9fccd245c986" width="600px"></kbd>
  
  <h2>Configurando o See Music</h2>
  
  Para importar o arquivo MIDI previamente salvo pelo REAPER, siga as instruções na interface do software. Clique no ícone de adição ("+") localizado no canto superior esquerdo da tela (seta 1) e selecione o arquivo MIDI desejado para importação. Essa ação permite integrar o conteúdo musical gravado anteriormente ao ambiente de trabalho do software, facilitando o prosseguimento das etapas de edição e visualização sincronizada com a performance musical.
  
  <kbd><img src="https://github.com/user-attachments/assets/a318700d-1dc9-47ce-88d8-1008c2469454" width="600px"></kbd>
  
  Após importar o arquivo MIDI, acessível através da ação evidenciada pela seta 1 da figura abaixo, você poderá personalizar as cores das notas e das partículas clicando no ícone de figuras coloridas. É possível escolher entre uma cor única, degradê, várias cores alternadas, cores separadas por região das teclas ou por canais, oferecendo amplas possibilidades de ajuste visual.
  
  <kbd><img src="https://github.com/user-attachments/assets/2ccb907c-b66b-4623-8853-7dfee03129c2" width="600px"></kbd>
  
  Para ajustar a quantidade de partículas, velocidade, direção, brilho, textura, formatos e outras opções, acesse o quarto item do menu, conforme representado pela seta 1 na figura abaixo.
  
  <kbd><img src="https://github.com/user-attachments/assets/d7af2b94-c04d-421f-ab76-0b8f54c46705" width="600px"></kbd>
  
  Feitas as configurações no SeeMusic, você pode renderizar o vídeo clicando no ícone da câmera e depois em "Render". Se necessário, altere as configurações de vídeo clicando no botão de configurações (botão do meio).
  
  <kbd><img src="https://github.com/user-attachments/assets/6dc9a8f4-a43e-4b78-b631-de5f59b910ea" width="600px"></kbd>
  
  Caso esteja utilizando a versão gratuita do programa, o vídeo será renderizado com uma marca d'água.
  
  <h2>Configurando o DaVinci Resolve</h2>
  
  No software, importe o vídeo da gravação do piano e o vídeo gerado pelo SeeMusic. É necessário cortar a parte inferior do vídeo de visualização utilizando a função de "cropping", de modo que ele possa ser posicionado acima do piano para criar uma conexão visual coesa.
  
  <kbd><img src="https://github.com/user-attachments/assets/cddf7f7d-ea6f-4784-91ae-4f0ebc903705" width="600px"></kbd>
  <kbd><img src="https://github.com/user-attachments/assets/2d6534fb-230d-4b19-b790-d31c04c161a1" width="600px"></kbd>
  
  Em seguida, ajuste a saturação para tornar as cores mais vivas ou mais escuras. Também é possível alterar a matriz de cores e ajustar o brilho conforme necessário.
  
  <kbd><img src="https://github.com/user-attachments/assets/1dcd58f1-1284-4696-b367-584817ceb795" width="600px"></kbd>
  
  Para renderizar o vídeo, clique no ícone conforme indicado pela (seta 1) da figura abaixo. O segundo passo é a seleção das predefinições de vídeo, que podem ser para redes como YouTube e TikTok (seta 2). Em seguida, clique em "Add to Render Queue" (seta 3) para adicionar o vídeo à fila de renderização. Finalmente, clique em "Render All" (seta 4) para iniciar o processo de salvamento do vídeo. Observe que esse processo pode ser demorado, dependendo das configurações de vídeo selecionadas.

  Você também pode alterar o nome do arquivo em 'File Name', e o diretório em que ele será salvo em 'Location' (próximo às setas 2)
  
  <kbd><img src="https://github.com/user-attachments/assets/2cf93ff0-b67b-4e72-bc4b-9c7747fab600" width="600px"></kbd>
  
  Essas foram algumas dicas de como produzir seu vídeo. Em caso de dúvidas sobre esses programas específicos, use sua criatividade e pesquise bastante!
</ul>


<h1>Escolhendo o Modo, Cores e Intensidade dos LEDs</h1>
<ul>
<p>Cada pasta "sketch" deste repositório contém um modo específico de cor.</p>
</ul>

<h3>Mudar a Cor</h3>
<ul>
<p>Para alterar a cor, pesquise o código RGB desejado na sua ferramenta de pesquisa de cores, e em seguida, ajuste os valores de R, G e B nas funções "cor()" ou nas variáveis relacionadas.</p>

<a href="https://g.co/kgs/r2wHJD8">Seletor de Cores do Google</a>

<kbd><img src="https://github.com/user-attachments/assets/ff7929b9-782b-451a-b7a1-7404aee37693" width="600px"></kbd>

</ul>

<h3>Mudar a Intensidade</h3>
<p>Você também pode alterar o brilho usando valores entre 0 e 255. (Não é recomendado aumentar muito esse valor, pois pode prejudicar sua visão durante a performance.)</p>

<h2>Modos</h2>
<ul>
<h3>sketch1: Cor Única</h3>
<ul>
<p>Nessa configuração, você pode escolher uma cor, e todas as teclas acenderão com a mesma cor.</p>
<li>Para alterar a cor, modifique os valores de R, G e B na função "cor()".</li>
<kbd><img src="https://github.com/user-attachments/assets/93dcd754-87bd-4d65-a607-98d3f5812459" width="400px"></kbd>
</ul>

<h3>sketch2: Uma Cor para Teclas Brancas e Outra para Teclas Pretas</h3>
<ul>
<li>Para alterar a cor das teclas <strong>pretas</strong>, ajuste os valores de R, G e B na função "cor1()".</li>
<li>Para alterar a cor das teclas <strong>brancas</strong>, ajuste os valores de R, G e B na função "cor2()".</li>
<kbd><img src="https://github.com/user-attachments/assets/f3b0ee1b-3dda-4f30-b00a-c6ea408b86d9" width="400px"></kbd>
</ul>

<h3>sketch3: Duas Cores Específicas Aleatórias</h3>
<ul>
<p>Neste modo, você escolhe duas cores, e cada vez que uma tecla é pressionada, há 50% de chance de acender com a "cor1()" ou a "cor2()".</p>
<li>Para escolher a primeira cor, altere os valores de R, G e B na função "cor1()".</li>
<li>Para escolher a segunda cor, altere os valores de R, G e B na função "cor2()".</li>
<kbd><img src="https://github.com/user-attachments/assets/c0b958e5-f94e-48be-9fba-714fac698d97" width="400px"></kbd>
</ul>

<h3>sketch4: Cores Aleatórias</h3>
<ul>
<p>Cada tecla pressionada acenderá com uma cor aleatória.</p>
<li>Você pode definir valores mínimos e máximos de RGB para evitar que todos os valores fiquem muito baixos, o que poderia resultar em uma cor "apagada".</li>
<kbd><img src="https://github.com/user-attachments/assets/fdfce029-edfd-49b0-b62b-700b20aefa90" width="400px"></kbd>
</ul>
  <br>
  
  > [!NOTE]
  > O arquivo "sketch_PianoLeds" é apenas o arquivo original, onde eu testei todos os códigos juntos, antes de separá-los para deixar mais organizado e fácil de utilizar. Ignore este arquivo!
</ul>

<h1>Como Colocar o Sistema para Funcionar Novamente?</h1>
<ul>
<p>Agora que todos os hardwares estão montados e conectados, o código foi enviado para o Arduino, e o loopMIDI, MIDI-OX e Hairless MIDI estão configurados, execute os programas na seguinte ordem e os deixe abertos:</p>
  <ul>
    <li><strong>loopMIDI</strong>: Apenas deixe aberto.</li>
    <li><strong>MIDI-OX</strong>: Normalmente, é suficiente deixar aberto (pressione algumas teclas do instrumento; se aparecerem mensagens de saída, está tudo certo). Caso contrário, pode ser necessário reconfigurá-lo.</li>
    <li><strong>Hairless MIDI</strong>: Às vezes, é preciso selecionar a porta em "MIDI In" e o Arduino em "Serial Port".</li>
  </ul>

</ul>


<h1>Obrigado!</h1>
<p>Sinta-se à vontade para criar forks com melhorias nos códigos ou criar novos modos de cores!</p>
<br>
<div align="center">
<img src="https://github.com/user-attachments/assets/fc3682d2-b593-4157-a1cd-f69ccf1a0b1a" width="400px">
</div>




















