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
</ul>
</div>
<ul>
O Arduino Leonardo é uma opção acessível e atende muito bem aos requisitos do projeto, mas você também pode utilizar outros modelos de Arduino. <br><br>
  

  
> [!WARNING]
> Não é recomendado o uso do Arduino UNO ou semelhantes, pois o seu baud rate não atende aos requisitos do projeto, causando problemas de latência e mau funcionamento.
</ul>

## Fita LED Endereçável: WS2812B

<div align="start">
<ul>
<kbd> <a href="#"><img src ="https://github.com/user-attachments/assets/8211fe75-e4f5-44bb-9106-f9aa4f318341" width="300px"> </a> </kbd>
</ul>
</div>
<ul>
Você pode utilizar quaisquer <a href="https://github.com/FastLED/FastLED/wiki/Chipset-reference">fitas LED suportadas</a> pela biblioteca utilizada.
</ul>

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

<kbd> <a href="#"><img src ="https://github.com/user-attachments/assets/3738a4d7-c9cc-4884-8814-cb0bdf4a693a" width="200px"> </a> </kbd> 

<a href="https://www.arduino.cc/en/software">Arduino IDE:</a> Para utilizar o código do projeto.

  
<kbd> <a href="#"><img src ="https://github.com/user-attachments/assets/f99a05d3-f861-4944-a017-013648497d58" width="200px"> </a> </kbd> 

<a href="https://www.tobias-erichsen.de/software/loopmidi.html">loopMIDI:</a> Para a criação de múltiplas portas MIDI adicionais no computador.

  <kbd> <a href="#"><img src ="https://github.com/user-attachments/assets/12de1c16-30ec-4e03-8994-f3098215ae6e" width="200px"> </a> </kbd>
  
<a href="https://www.tobias-erichsen.de/software/loopmidi.html">Midi-OX:</a> Roteia as mensagens MIDI enviadas pelo piano para as portas criadas.

  <kbd> <a href="#"><img src ="https://github.com/user-attachments/assets/49d1a5e3-0669-44a0-afe0-c71f7e7f8490" width="200px"> </a> </kbd>
  
<a href="https://www.tobias-erichsen.de/software/loopmidi.html">Hairless MIDI:</a> Transmite as mensagens MIDI do piano para a porta serial COM do Arduino.

</ul>

<h2 id="softwares-video">Softwares Para Produção de Video</h2>

<h3>Gravador MIDI / Editor de Audio</h3>

<ul>
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
  
<li><a href="https://www.seemusicapp.com">SeeMusic:</a> Visualizador de Notas MIDI (VFX)</li> 
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
  
<li><strong>O Piano:</STRONG> É Conectado por um cabo <STRONG>USB A-B</STRONG> no HubUSB.</li>

<kbd> <img src="https://github.com/user-attachments/assets/a847d7d4-9165-4da8-a5f8-19374bc844a2" width="400px"> </kbd>

*Entrada USB-B do Piano Digital.

</ul>

<h2>Arduino</h2>

<ul>

<li><strong>Arduino:</STRONG> É conectado por um cabo <STRONG>USB 2.0 A/B</STRONG> no HubUSB.</li>

<kbd> <img src="https://github.com/user-attachments/assets/a0c9eef7-392f-4216-bfeb-7e950e8d3b49" width="300px"> </kbd>

</ul>

<h2>Fita LED</h2>

<ul>

<LI>Utilize o lado da fita que possui conector <strong>Fêmea</strong>, pois o código foi estruturado com base nesse lado.</LI>

<kbd><img src="https://github.com/user-attachments/assets/c04cc648-48d3-472c-898b-933dc06eb27b" width="400px"></kbd>


<li><STRONG>A Fita Led</STRONG> Possui dois grupos de cabo separados.</li>
<h3><strong>Grupo 1:</strong> Um Cabo <strong>Branco(-)</strong> e Um Cabo <strong>Vermelho(+)</strong> (Cabos de Alimentação).</h3>
<ul>
  <li>Foi soldado em um Conector USB, e conectado no HubUSB (A Fita led precisa dessa fonte de alimentação, pois somente a do arduino não é o suficiente).</li>

  <kbd> <img src="https://github.com/user-attachments/assets/3668830c-486d-424f-a873-d288978ecc05" width="400px"> </kbd>
  
</ul>
<h3><strong>Grupo 2:</strong> Um Cabo <strong>Branco(-)</strong>, Um cabo <strong>Vermelho(+)</strong> e um cabo <strong>Verde</strong> (Cabo de Dados).</h3>
<ul>
  <li>Conectar adaptador que separa o grupo de fios, em fios individuais no conector Fêmea da Fita Led.</li>
  <kbd> <img src="https://github.com/user-attachments/assets/9a707d9c-be64-40b4-bcb5-4480620146c1" width="400px"> </kbd>
  <li>É recomendado encapar os conectores dos cabos <strong>branco e vermelho</strong> com fita isolante, para evitar curto, já que não serão utilizados.</li>
  <li>O conector <strong>Verde</strong> (Cabo de Dados) é conectado em uma das saidas <STRONG>Digital (PWM)</STRONG> do Arduino (Recomendo a 7, pois é a que foi utilizada no código).</li>

  <kbd> <img src="https://github.com/user-attachments/assets/383dc900-95ca-4546-8124-276ae191e5e7" width="400px"> </kbd>



    
</ul>

</ul>

<h2>HubUSB</h2>

<ul>
  
<li>É conectado no <strong>PC</strong>.</li>
<br>
  
> [!NOTE]  
> Você pode substituir o HubUSB por conectar diretamente no PC, porém não recomendo pois isso ocupará muitas entradas.
  
</ul>

<h1>Configurando os Softwares</h1>

<ul>
<div align="center">
<kbd> <img src="https://github.com/user-attachments/assets/bed53266-9ea8-43e8-80cf-7427a717f536" width="600px"> </kbd>
</div>
</ul>












