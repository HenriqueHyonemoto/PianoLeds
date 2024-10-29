<h1 id="introduction">Piano Leds</h1> 

<a href="https://www.youtube.com/watch?v=7a4QGCJzvwk"><img src ="https://github.com/user-attachments/assets/359d1bb8-9a3f-46aa-8d08-0e0f64671444"> </a>

Bem-vindo ao meu projeto de integração entre Arduino, fita LED RGB e piano digital! Este repositório oferece um guia passo a passo para você aprender a:

<ul> 
  <li>Utilizar o Arduino: Configure e programe seu Arduino para comunicação com o piano digital via MIDI.</li> 
  <li>Conexões Físicas: Instruções detalhadas sobre como conectar o Arduino ao piano, à fita LED e ao computador, garantindo uma montagem simples e eficiente.</li> 
  <li>Controlar a Fita LED RGB: Acenda LEDs correspondentes às teclas pressionadas no piano, criando uma visualização dinâmica e colorida.</li> 
  <li>Edição de Vídeo: Dicas e técnicas para capturar e editar sua apresentação, destacando a interação entre a música e a iluminação.</li> 
</ul>
  
Neste projeto, cada tecla pressionada acionará um LED correspondente, permitindo uma experiência visual que complementa sua performance musical. Perfeito para músicos, criadores e entusiastas de tecnologia!

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
  
  <a id="reaper" href="https://www.reaper.fm/">Reaper:</a> Gravador MIDI e Editor de Audio <br>
  
Você precisará para gravar sua performance em formato MIDI (nota por nota tocada) para gerar a visualização em vídeo, e também precisará renderizar o audio. (Caso não grave o som fisicamente)<br>
Você pode utilizar outros programas para realizar essa função.
</ul>

<h3>Biblioteca / Piano VST</h3>
<ul>
<kbd> <a href="#"><img src ="https://github.com/user-attachments/assets/95e7d65a-0c0d-43bd-9375-22628bd457fd" width="300px"> </a> </kbd>

Caso não haja possibilidade de gravar um som de qualidade do seu piano, você pode utilizar bibliotecas ou VST de piano para gerar um audio limpo e claro. Você pode pesquisar por "Free Piano VST", para encontrar softwares gratuitos, ou utilizar um pago.
A Instalação de cada um pode variar, porém para importar no <a href="/#reaper">Reaper</a> você precisará que a instalação do seu VST inclua salvar como plugin.
</ul>

<H3>Visualizador MIDI</H3>
<ul>
<li><a href="https://www.seemusicapp.com">SeeMusic:</a> Visualizador de Notas MIDI (VFX)</li>
</ul>
Você também pode utilizar outros visualizadores, como <a href="https://synthesiagame.com/download">Synthesia</a> e <a href="https://embers.app/">Embers</a> mas tenha em mente que esses softwares são pagos, embora você possa usar o Embers e o SeeMusic com marca d'água.

<h3>Editor de Video</h3>

<ul>
  
<a href="https://www.seemusicapp.com">Davinci Resolve: </a> Utilizado para criar o video final, juntando todos os arquivos produzidos anteriormente.
</ul>

A versão gratuita desse software permite fazer todas as edições necessárias para a produção de um vídeo, como o exemplo apresentado neste repositório. Porém, se você tiver experiência, pode utilizar qualquer outro editor de vídeo para realizar essa função.





