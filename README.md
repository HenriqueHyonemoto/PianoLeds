<h1 id="introduction">Piano Leds</h1> 

Bem-vindo ao meu projeto de integração entre Arduino, fita LED e um Piano!

<a href="https://www.youtube.com/watch?v=7a4QGCJzvwk"><img src ="https://github.com/user-attachments/assets/359d1bb8-9a3f-46aa-8d08-0e0f64671444"> </a>

Este projeto tem como propósito criar uma experiência imersiva e visual ao tocar piano, onde cada tecla pressionada acende LEDs correspondentes em uma fita RGB, sincronizando luz e som em uma performance única. Além disso, ele possibilita a produção de vídeos artísticos que combinam a música com efeitos de iluminação, resultando em uma obra visual e sonora cativante! <br>

Este repositório oferece um guia passo a passo para você aprender a:

<ul> 
  <li>Utilizar o Arduino: Configure e programe seu Arduino para comunicação com o piano digital via MIDI.</li> 
  <li>Conexões Físicas: Instruções detalhadas sobre como conectar o Arduino ao piano, à fita LED e ao computador, garantindo uma montagem simples e eficiente.</li> 
  <li>Controlar a Fita LED RGB: Acenda LEDs correspondentes às teclas pressionadas no piano, criando uma visualização dinâmica e colorida.</li> 
  <li>Edição de Vídeo: Dicas e técnicas para capturar e editar sua apresentação, destacando a interação entre a música e a iluminação.</li> 
</ul>
  
Sinta-se à vontade para explorar, contribuir e compartilhar suas próprias criações!

<h1 id="hardwares">Hardwares Utilizados</h1> 

## Arduino: Leonardo

<div align="start">
<ul>
  
<kbd> <a href="#"><img src ="https://github.com/user-attachments/assets/2acb8638-9ad7-4238-b9e1-4f55a3258423" width="300px"> </a> </kbd>

O Arduino Leonardo é uma opção acessível e atende muito bem aos requisitos do projeto, mas você também pode utilizar outros modelos de Arduino. <br>

</ul>
</div>
<ul>

> [!WARNING]
> Não é recomendado o uso do Arduino UNO ou semelhantes, pois o seu baud rate não atende aos requisitos do projeto, causando problemas de latência e mau funcionamento.
</ul>

## Fita LED Endereçável: WS2812B

<div align="start">
<ul>

<kbd> <a href="#"><img src ="https://github.com/user-attachments/assets/8211fe75-e4f5-44bb-9106-f9aa4f318341" width="300px"> </a> </kbd>

Você pode utilizar quaisquer <a href="https://github.com/FastLED/FastLED/wiki/Chipset-reference">fitas LED suportadas</a> pela biblioteca utilizada.

</ul>
</div>

## Piano Digital: Yamaha P-45

<div align="start">
<ul>
<kbd> <img src="https://br.yamaha.com/pt/files/P-45_119_H_P-45_540_540_2b0fd46e557ff681962a196c0e4db30e.jpg?impolicy=resize&imwid=735&imhei=735" width="300px"> </kbd>
</ul>
</div>
<ul>
Você pode utilizar qualquer piano que possua saída MIDI.
</ul>

## Hub USB (Opcional)
<div align="start">
<ul>
<kbd> <a href="#"><img src ="https://github.com/user-attachments/assets/53c2e544-1451-4162-9ff6-3c1de8e8122b" width="300px"> </a> </kbd> 
</ul>
</div>
<ul>
Pode ser utilizado qualquer HUB USB, ele servirá para facilitar a conexão entre os dispositivos e evitar a ocupação de várias entradas no computador.
</ul>

<h1 id="softwares">Softwares Utilizados</h1>
<h2 id="softwares-piano">Softwares Para Piano e Led</h2>

<ul>
  
<h3><a href="https://www.arduino.cc/en/software">Arduino IDE</a></h3>

<kbd> <a href="#"><img src ="https://github.com/user-attachments/assets/3738a4d7-c9cc-4884-8814-cb0bdf4a693a" width="200px"> </a> </kbd> 

Para utilizar o código do projeto.

<h3><a href="https://www.tobias-erichsen.de/software/loopmidi.html">loopMIDI</a></h3>

<kbd> <a href="#"><img src ="https://github.com/user-attachments/assets/f99a05d3-f861-4944-a017-013648497d58" width="200px"> </a> </kbd> 

Para a criação de múltiplas portas MIDI adicionais no computador.

<h3><a href="http://www.midiox.com">Midi-OX</a> </h3>

<kbd> <a href="#"><img src ="https://github.com/user-attachments/assets/12de1c16-30ec-4e03-8994-f3098215ae6e" width="200px"> </a> </kbd>

Roteia as mensagens MIDI enviadas pelo piano para as portas criadas.

<h3><a href="https://projectgus.github.io/hairless-midiserial/">Hairless MIDI</a></h3>

<kbd> <a href="#"><img src ="https://github.com/user-attachments/assets/49d1a5e3-0669-44a0-afe0-c71f7e7f8490" width="200px"> </a> </kbd>

Transmite as mensagens MIDI do piano para a porta serial COM do Arduino.

</ul>

<h2 id="softwares-video">Softwares Para Produção de Video</h2>

<ul>
  
<h3>Gravador MIDI / Editor de Audio</h3>

  <kbd> <a href="#"><img src ="https://github.com/user-attachments/assets/5701b300-ebec-4603-a015-e0e26693a472" width="200px"> </a> </kbd>
  
  <a id="reaper" href="https://www.reaper.fm/">Reaper:</a> Gravador MIDI e Editor de Audio. <br>
  
Você precisará para gravar sua performance em formato MIDI (nota por nota tocada) para gerar a visualização em vídeo, e também precisará renderizar o audio (Caso não grave o som fisicamente).
<br><br>
Você pode utilizar outros programas para realizar essa função.
</ul>

<h3>Biblioteca / Piano VST</h3>
<ul>
<kbd> <a href="#"><img src ="https://github.com/user-attachments/assets/95e7d65a-0c0d-43bd-9375-22628bd457fd" width="600px"> </a> </kbd>

Caso não haja possibilidade de gravar um som de qualidade do seu piano, você pode utilizar bibliotecas ou VST de piano para gerar um audio limpo e claro. Você pode pesquisar por "Free Piano VST", para encontrar softwares gratuitos, ou utilizar um pago.
A Instalação de cada um pode variar, porém para importar no <a href="/#reaper">Reaper</a> você precisará que a instalação do seu VST inclua salvar como plugin.
</ul>

<H3>Visualizador MIDI</H3>

<ul>
<kbd> <img src="https://github.com/user-attachments/assets/69144623-7cbd-47d6-9c5a-bb1d4a670feb" width="600px"> </kbd>
  
<a href="https://www.seemusicapp.com">SeeMusic:</a> Visualizador de Notas MIDI (VFX)
<br>
Você também pode utilizar outros visualizadores, como <a href="https://synthesiagame.com/download">Synthesia</a> e <a href="https://embers.app/">Embers</a> mas tenha em mente que esses softwares são pagos, embora você possa usar o Embers e o SeeMusic com marca d'água.

</ul>

<h3>Editor de Video</h3>

<ul>
<kbd><img src="https://github.com/user-attachments/assets/124a451e-4805-4fa5-83c7-1c541ae90f35" width="600px"></kbd>

<a href="https://www.blackmagicdesign.com/br/products/davinciresolve">Davinci Resolve: </a> Utilizado para criar o video final, juntando todos os arquivos produzidos anteriormente.

A versão gratuita desse software permite fazer todas as edições necessárias para a produção de um vídeo, como o exemplo apresentado neste repositório. Porém, se você tiver experiência, pode utilizar qualquer outro editor de vídeo para realizar essa função.

</ul>

<h1>Configurando o Hardware</h1>

<ul>
<div align="center">
<kbd> <img src="https://github.com/user-attachments/assets/e02bffd7-d3c7-4d57-ae8a-f942f9e9a6fc" width="600px"> </kbd>
</div>
<br>
</ul>

<h2>Piano</h2>

<ul>
  
<kbd> <img src="https://github.com/user-attachments/assets/a847d7d4-9165-4da8-a5f8-19374bc844a2" width="400px"> </kbd>
*Entrada USB-B do Piano Digital.

<li><strong>O Piano:</STRONG> É Conectado por um cabo <STRONG>USB A-B</STRONG> no HubUSB.</li>

</ul>

<h2>Arduino</h2>

<ul>

<kbd> <img src="https://github.com/user-attachments/assets/a0c9eef7-392f-4216-bfeb-7e950e8d3b49" width="300px"> </kbd>

<li><strong>Arduino:</STRONG> É conectado por um cabo <STRONG>USB 2.0 A/B</STRONG> no HubUSB.</li>

</ul>

<h2>Fita LED</h2>

<ul>

<kbd><img src="https://github.com/user-attachments/assets/c04cc648-48d3-472c-898b-933dc06eb27b" width="400px"></kbd>

<LI>Utilize o lado da fita que possui conector <strong>Fêmea</strong>, pois o código foi estruturado com base nesse lado.</LI>

<li><STRONG>A Fita Led</STRONG> Possui dois grupos de cabo separados.</li>
<h3><strong>Grupo 1:</strong> Um Cabo <strong>Branco(-)</strong> e Um Cabo <strong>Vermelho(+)</strong> (Cabos de Alimentação).</h3>
<ul>

  <kbd> <img src="https://github.com/user-attachments/assets/3668830c-486d-424f-a873-d288978ecc05" width="400px"> </kbd>

  <li>Foi soldado em um Conector USB, e conectado no HubUSB (A Fita led precisa dessa fonte de alimentação, pois somente a do arduino não é o suficiente).</li>
  
</ul>
<h3><strong>Grupo 2:</strong> Um Cabo <strong>Branco(-)</strong>, Um cabo <strong>Vermelho(+)</strong> e um cabo <strong>Verde</strong> (Cabo de Dados).</h3>
<ul>
  
  <kbd> <img src="https://github.com/user-attachments/assets/9a707d9c-be64-40b4-bcb5-4480620146c1" width="400px"> </kbd>
  
  <li>Conectar o adaptador que separa o grupo de fios, em fios individuais, no conector Fêmea da Fita Led.</li><br>

  <kbd> <img src="https://github.com/user-attachments/assets/383dc900-95ca-4546-8124-276ae191e5e7" width="400px"> </kbd>

  <li>É recomendado encapar os conectores dos cabos <strong>branco e vermelho</strong> com fita isolante, para evitar curto, já que não serão utilizados.</li>
  <li>O conector <strong>Verde</strong> (Cabo de Dados) é conectado em uma das saidas <STRONG>Digital (PWM)</STRONG> do Arduino (Recomendo a 7, pois é a que foi utilizada no código).</li>

</ul>

</ul>

<h2>HubUSB</h2>

<ul>
  
<li>É conectado no <strong>PC</strong>.</li>
<br>
  
> [!NOTE]  
> Você pode substituir o HubUSB por conectar diretamente no PC, porém não recomendo pois isso ocupará muitas entradas.
  
</ul>

<h1>Configurando os Softwares para controle de LEDS</h1>

<ul>
<div align="center">
<kbd> <img src="https://github.com/user-attachments/assets/bed53266-9ea8-43e8-80cf-7427a717f536" width="600px"> </kbd>
</div>

<h2>Arduino IDE</h2>

Abra o arquivo "sketch_PianoLeds.ino" dentro da <a href="https://www.arduino.cc/en/software">Arduino IDE.</a><br>

Vá em Tools -> Board -> Arduino AVR Boards -> (Selecione seu Arduino)

<kbd> <a href=""><img src ="https://github.com/user-attachments/assets/e56f029e-04ab-4a2b-9bff-9bf29674181f" width="600px"> </a> </kbd> 

Em seguida, nomamente em Tools -> Port -> (Selecione a COM na qual seu Arduino foi conectado)

<kbd> <a href=""><img src ="https://github.com/user-attachments/assets/d94b0a55-065f-4ae6-acf3-6347d7e26439" width="600px"> </a> </kbd> 

Você pode verificar se está tudo certo, se o simbolo do USB estiver Verde, (conforme a figura abaixo).

<kbd> <a href=""><img src ="https://github.com/user-attachments/assets/45f6dd6e-be03-4b07-aba3-0f9c42d817d3" width="600px"> </a> </kbd> 

Agora, vamos baixar as bibliotecas para controlar a fita e receber comandos do piano.

Clique no simbolo de livros, e pesquise o nome das duas bibliotecas, e as instale.

<kbd> <a href=""><img src ="https://github.com/user-attachments/assets/2d10d170-0ea6-4e49-b5ee-0fae146e1120" width="600px"> </a> </kbd> 

FastLED

<kbd> <a href="https://github.com/FastLED/FastLED"><img src ="https://github.com/user-attachments/assets/ee872414-dd45-4972-af64-44a987092159" width="400px"> </a> </kbd> 

MIDI Library

<kbd> <a href="https://github.com/FortySevenEffects/arduino_midi_library"><img src ="https://github.com/user-attachments/assets/7b98d116-bd52-4f5c-87f0-02796186e582" width="400px"> </a> </kbd> 

> [!WARNING]
> Feche todos os outros programas que utilizem o Arduino (Como o Hairless MIDI), pois se não o código não vai conseguir ser enviado para ele.

Agora pressione o botão Verify/Compile (Seta 1, Para compilar e verificar se o código está funcionando) e em seguida o botão Upload (Seta 2, Para enviar o código para dentro do Arduino).

<kbd> <a href=""><img src ="https://github.com/user-attachments/assets/030068bc-08c4-4330-b7b2-4a57ffeee5d1" width="400px"> </a> </kbd> 

Apesar de parecer uma mensagem de erro, é assim que aparece quando esta tudo certo.

<kbd> <a href=""><img src ="https://github.com/user-attachments/assets/a02d5cb9-e14d-4275-bd33-5f062c91d6c8" width="800px"> </a> </kbd> 

<ul>
</ul>
<h2>loopMIDI</h2>
<ul>

O loopMIDI é utilizado para criar as portas MIDI, conforme ilustrado na Figura abaixo, você deve clicar no botão "Add Port", de acordo com a seta 1, isso adicionará novas portas MIDI ao conjunto disponível no computador.<br>
  
<kbd> <img src="https://github.com/user-attachments/assets/3c498acb-eaf5-43f2-a5ef-241b51f5613c" width="600px"> </kbd>

Feito isso, para renomear as portas, selecione a porta desejada, indicado pela seta 1, ilustrado na figura abaixo, e defina um novo nome no campo "New port-name", conforme indicado pela seta 2. A criação de duas portas é suficiente para garantir o funcionamento do sistema de LEDs e permitir o uso das mensagens MIDI por todos os programas que as utilizam.<br>

<kbd> <img src="https://github.com/user-attachments/assets/4b29a9c3-29d7-4681-9388-e661e02ab6fe" width="600px"> </kbd>

Para apagar uma porta, basta selecioná-la e clicar no botão de menos, O botão com símbolo de quadrado muta a porta selecionada, fazendo com que ela não receba mais inputs MIDI

</ul>
<h2>Midi-OX</h2>
<ul>
  
Para realizar a configuração do MIDI-OX, primeiramente, clique no menu suspenso em “Options”, conforme indicado pela seta 1, de acordo com a ilustração da Figura abaixo, selecionando em seguida a opção “MIDI Devices”.

<kbd> <img src="https://github.com/user-attachments/assets/2486d56e-ca28-4565-b262-b073e08d458b" width="600px"> </kbd>
<li>Ao clicar na opção "MIDI Device", no menu suspenso “Options”, selecione a entrada do instrumento em "MIDI Inputs", conforme indicado pela seta 1, na figura abaixo. </li>
<li>No campo "MIDI Outputs", indicado pelas setas 2, selecione as entradas criadas com o loopMIDI. </li>
<li>Após a configuração, oclique no botão “OK”, conforme indicado pela seta 3. </li>
<li>Este procedimento configura corretamente o direcionamento das mensagens MIDI do piano digital para as entradas criadas pelo loopMIDI, permitindo a comunicação adequada com o sistema do microcontrolador.</li>

<kbd> <img src="https://github.com/user-attachments/assets/0cdedb9c-b693-45cb-a257-c1344cfaafd5" width="600px"> </kbd>

Feito isso, pressione as teclas do seu instrumento, as notas devem aparecer no prompt conforme a figura abaixo.

<kbd> <img src="https://github.com/user-attachments/assets/03d2442f-a1c7-4057-b692-8fe89d70a1fb" width="600px"> </kbd>

</ul>
<h2>HairlessMIDI</h2>
<ul>
  
No software Hairless MIDI, selecione a porta COM do Arduino no campo "Serial Port", de acordo com a indicação da seta 1 na Figura abaixo. Isso configura a comunicação entre o Hairless MIDI e o Arduino através da porta serial selecionada.

<kbd> <img src="https://github.com/user-attachments/assets/616cc65d-1c80-4385-a221-94370376dd2e" width="600px"> </kbd>

Uma das suas entradas criadas pelo loopMIDI deve ser selecionada no campo "MIDI In", como evidenciado pela seta 1 da Figura abaixo. Isso garantirá que as mensagens MIDI sejam direcionadas corretamente para o sistema do Microcontrolador.

<kbd> <img src="https://github.com/user-attachments/assets/5666aa94-1dde-4286-a89b-77c2837892b2" width="600px"> </kbd>

</ul>
<h1>Configurando os Softwares para edição de video.</h1>
<ul>
<h2>Reaper</h2>

<h3>Gravando e Exportando um Arquivo MIDI</h3>
  
De acordo com a ilustração da Figura Abaixo, clique duplo na região vazia, ou com o botão direito, e escolha a opção "Insert New Track" para criar uma faixa onde o MIDI será gravado, conforme orientado na seta 1.

<kbd> <img src="https://github.com/user-attachments/assets/6ab0fa56-c768-432f-882c-b188672cf037" width="600px"> </kbd>

Em seguida, conforme demonstrado na Figura abaixo, clique no botão "Record Arm/Disarm", acessar as opções de configuração de entrada do instrumento, conforme indicado na seta 1.

<kbd> <img src="https://github.com/user-attachments/assets/35d1b5ed-d591-4f16-9b3e-fe09ea09162d" width="600px"> </kbd>

A tela do sistema, ilustrada na Figura abaixo, orienta sobre a configuração do instrumento. Ao clicar no botão "IN FX", conforme indicado pela seta 1, selecione o tipo de entrada de mídia de áudio, escolhendo a opção "Input Midi" e marcando uma das portas criadas pelo loopMIDI e MIDI-OX que estejam disponíveis, seguindo a indicação da seta 2. Em seguida, é possível escolher qualquer canal (Channel) para realizar a gravação.

<kbd> <img src="https://github.com/user-attachments/assets/e56717f3-daf3-4cd9-9155-a255c221f510" width="600px"> </kbd>

Para iniciar a gravação das notas do instrumento, clique no botão de gravação localizado ao lado dos controles de reprodução de áudio ou usar o atalho CTRL+L, conforme indicado na seta 1 na Figura abaixo.

<kbd> <img src="https://github.com/user-attachments/assets/983a73f2-a690-4e29-846f-afffb649c67d" width="600px"> </kbd>

Após finalizar a gravação (Aperte novamente o botão de gravação), para salvar o arquivo, clique na opção 'File' no menu suspenso e, em seguida, em 'Export Project MIDI'. Essa operação é indicada pela seta 1 na figura abaixo..

<kbd> <img src="https://github.com/user-attachments/assets/7ebaafc5-1221-4bd9-aa36-2326035f50b1" width="600px"> </kbd>

Conforme a Figura abaixo, uma janela de opções para exportação é aberta, você pode escolher quais faixas deseja renderizar, alterar o nome e o diretório do arquivo, além de outras opções disponíveis.

<kbd> <img src="https://github.com/user-attachments/assets/6d2815cc-02cc-4413-adf7-4268c110f678" width="600px"> </kbd>

<h3>Renderizando o Audio da Performance</h3>

Nesta etapa, vamos utilizar a biblioteca/VST que você escolheu anteriormente. (Você pode pular esta etapa caso tenha gravado o áudio do seu instrumento com sua câmera ou microfone).

Clique no botão "FX"

<kbd> <img src="https://github.com/user-attachments/assets/c8bc6925-1640-4850-9a76-72df723cc7e0" width="600px"> </kbd>

Pesquise pelo nome do seu VST, e clique sobre ele duas vezes.

<kbd> <img src="https://github.com/user-attachments/assets/e5b6f33f-f964-4862-8a88-98b183cbb333" width="600px"> </kbd>

> [!NOTE]  
> Você pode pesquisar como adicionar e configurar a sua Biblioteca/VST especifica no Youtube ou na sua ferramenta de pesquisa, provavelmente você vai encontrar um tutorial pra isso!

Feito as configurações necessarias, va em File -> Render (CTRL + ALT + R)

<kbd> <img src="https://github.com/user-attachments/assets/1153635e-43e7-4105-99a0-41bbb4c75b48" width="600px"> </kbd>

Agora, selecione o Diretorio (Indicado pela Seta 1), De um nome pro seu arquivo (Seta 2), e escolha um formato (Seta 3), em seguida, clique em Render File.

<kbd> <img src="https://github.com/user-attachments/assets/03392b6c-c098-4c1f-97f4-9fccd245c986" width="600px"> </kbd>

<h2>See Music</h2>

Para importar o arquivo MIDI previamente salvo pelo REAPER, siga as instruções na interface do software. Isso envolve clicar no ícone de adição ("+") localizado no canto superior esquerdo da tela, seguindo a indicação da seta 1 na figura abaixo. Em seguida, selecione o arquivo MIDI desejado para importação. Essa ação permite integrar o conteúdo musical gravado anteriormente ao ambiente de trabalho do software, facilitando o prosseguimento das etapas de edição e visualização sincronizada com a performance musical.

<kbd> <img src="https://github.com/user-attachments/assets/a318700d-1dc9-47ce-88d8-1008c2469454" width="600px"> </kbd>

Após importar o arquivo MIDI, acessível através da ação evidenciada pela seta 1 da figura abaixo, na interface do software, você poderá personalizar as cores das notas e das partículas clicando no ícone de figuras coloridas. É possível escolher entre uma cor única, degradê, várias cores alternadas, cores separadas por região das teclas ou por canais. Essa funcionalidade oferece amplas possibilidades de ajuste visual para a representação das notas musicais dentro do ambiente do software.

<kbd> <img src="https://github.com/user-attachments/assets/2ccb907c-b66b-4623-8853-7dfee03129c2" width="600px"> </kbd>

Para ajustar a quantidade de partículas, velocidade, direção na qual as notas caem, brilho, textura, formatos e outras opções, é possível acessar o quarto item do menu, de acordo com a representação da seta 1 na Figura abaixo, que disponibiliza diversas opções de personalização.

<kbd> <img src="https://github.com/user-attachments/assets/d7af2b94-c04d-421f-ab76-0b8f54c46705" width="600px"> </kbd>

Feitas as configurações e ajustes visuais no SeeMusic, você pode renderizar o vídeo clicando no ícone da câmera e depois em "Render". Se necessário, é possível alterar as configurações de vídeo clicando no botão de configurações (botão do meio).

<kbd> <img src="https://github.com/user-attachments/assets/6dc9a8f4-a43e-4b78-b631-de5f59b910ea" width="600px"> </kbd>

Caso esteja utilizando a versão gratuita do programa, o vídeo será renderizado com uma marca d'água.

<h2>DaVinciResolve</h2>

No software, importamos o vídeo da gravação do piano e o vídeo gerado pelo SeeMusic. Foi necessário cortar a parte inferior do vídeo de visualização utilizando a função de "cropping", de modo que ele pudesse ser posicionado acima do piano para criar uma conexão visual coesa.

<kbd> <img src="https://github.com/user-attachments/assets/cddf7f7d-ea6f-4784-91ae-4f0ebc903705" width="600px"> </kbd>

<kbd> <img src="https://github.com/user-attachments/assets/2d6534fb-230d-4b19-b790-d31c04c161a1" width="600px"> </kbd>

Em seguida, realizamos ajustes na saturação para tornar as cores mais vivas ou mais escuras. Também é possível alterar a matriz de cores e ajustar o brilho conforme necessário.

<kbd> <img src="https://github.com/user-attachments/assets/1dcd58f1-1284-4696-b367-584817ceb795" width="600px"> </kbd>

Para renderizar o vídeo, clique no ícone conforme indicado na seta 1 da Figura abaixo. O segundo passo é a seleção das predefinições de vídeo, que podem ser para redes mais comuns como o Youtube e TikTok, de acordo com a ilustração da seta 2. Em seguida, ao clicar em "Add to Render Queue", conforme indicado pela seta 3, adicione o vídeo à fila de renderização. Finalmente, ao clicar em "Render All", de acordo com seta 4, iniciará o processo de salvamento do vídeo. É importante observar que este processo pode ser demorado, dependendo da qualidade e das configurações de vídeo selecionadas.

<kbd> <img src="https://github.com/user-attachments/assets/2cf93ff0-b67b-4e72-bc4b-9c7747fab600" width="600px"> </kbd>

Essas foram algumas dicas de como produzir seu vídeo. Em caso de dúvidas sobre esses programas específicos, use sua criatividade e pesquise bastante!

</ul>













