<h1>Classes</h1>

<h2>Jogador</h2>
<h3>Responsabilidades</h3>
<p>Armazenar informações de vida, ataque, defesa e ouro.
Restaurar a vida no início de cada batalha.
Realizar ataques contra inimigos.
Defender-se para reduzir o dano recebido.
Recuperar pontos de vida durante o combate.
Aumentar atributos (ataque, defesa, vida máxima) na loja.
Investir ouro e receber retorno financeiro.
Verificar a morte durante batalhas.
Exibir status atual.</p>
<h3>Colaborações</h3>
<p>
  <ul>
    <li>Loja: para melhorar atributos e investir ouro.</li>
    <li>Combate: para enfrentar inimigos.</li>
  </ul>
</p>


<h2>Inimigo</h2>
<h3>Responsabilidades</h3>
<p>Armazenar informações de nome, vida e ataque.
Receber dano de ataques do jogador.
Realizar ataques contra o jogador.
Exibir status atual.
Definir nível de dificuldade baseado no estágio do jogo.</p>
<h3>Colaborações</h3>
<p>
  <ul>
    <li>Jogador: para realizar combates.</li>
    <li>Combate: para controlar o fluxo de luta.</li>
  </ul>
</p>

<h2>Loja</h2>
<h3>Responsabilidades</h3>
<p>
  Exibir opções de melhoria de atributos.
Permitir compra de upgrades de ataque, defesa e vida.
Controlar o investimento de ouro.
Retornar 50% de investimento ao jogador.
Verificar disponibilidade de ouro.
Atualizar atributos do jogador.
Encerrar operações e retornar ao jogo.
</p>
<h3>Colaborações</h3>
<p>
  <ul>
    <li>Jogador: para atualizar atributos e investir ouro.</li>
    <li>Sistema: para exibir interface e controlar ciclo de jogo.</li>
  </ul>
</p>

<h2>Sistema</h2>
<h3>Responsabilidades</h3>
<p>
  Definir a sequência de inimigos e bosses.
Controlar o progresso do jogador.
Iniciar combates em ordem predefinida.
Chamar a loja após cada vitória.
Exibir mensagens e narrativas.
Finalizar o jogo após a última batalha.
Controlar reinício ou saída.
</p>
<h3>Colaborações</h3>
<p>
  <ul>
    <li>Combate: para iniciar batalhas.</li>
    <li>Loja: para exibir entre lutas.</li>
  </ul>
</p>

<h2></h2>
<h3>Responsabilidades</h3>
<p>
  
</p>
<h3>Colaborações</h3>
<p>
  <ul>
    <li></li>
    <li></li>
  </ul>
</p>

<h2></h2>
<h3>Responsabilidades</h3>
<p>
  
</p>
<h3>Colaborações</h3>
<p>
  <ul>
    <li></li>
    <li></li>
  </ul>
</p>


<h1>User Stories</h1>

<h2>User Story 1 | @Hebert2008</h2>
<p>Como jogador
Quero atacar, defender ou recuperar vida no meu turno
Para ter controle sobre a estratégia de combate

Critérios de Aceitação:
<ul>
<li>O jogador deve escolher entre atacar, defender ou curar.</li>
<li>A escolha deve produzir o efeito esperado imediatamente.</li>
</ul>
</p>

<h2>User Story 2 | @Hebert2008</h2>
<p>Como jogador
Quero restaurar minha vida antes de cada batalha
Para começar cada combate em igualdade de condições

Critérios de Aceitação:
<ul>
<li>A vida do jogador deve voltar ao valor máximo no início de cada luta.</li>
</ul>
</p>

<h2>User Story 3 | @stanciola</h2>
<p>
Como jogador
Quero visitar a loja após derrotar um inimigo
Para gastar meu ouro em melhorias
Critérios de aceitação:
  <ul>
    <li>A loja deve abrir após cada vitória.</li>
    <li>Deve exibir corretamente as opções e valores.</li>
    <li>O ouro deve ser debitado e os atributos atualizados.</li>
  </ul>
</p>

<h2>User Story 4 | @stanciola</h2>
<p>
Como jogador
Quero investir parte do meu ouro
Para receber um retorno de 10% ao voltar à loja
Critérios de aceitação:
  <ul>
    <li>O jogador deve poder escolher o valor a investir.</li>
    <li>O retorno de 10% deve ser aplicado corretamente ao retornar</li>
  </ul>
</p>

<h2>User Story 5 | @</h2>
<p>

Critérios de aceitação:
  <ul>
    <li></li>
    <li></li>
    <li></li>
  </ul>
</p>

<h2>User Storie 6 | @</h2>
<p>

Critérios de aceitação:
  <ul>
    <li></li>
    <li></li>
    <li></li>
  </ul>
</p>

<h2>User Storie 7 | @</h2>
<p>

Critérios de aceitação:
  <ul>
    <li></li>
    <li></li>
    <li></li>
  </ul>
</p>

<h2>User Storie 8 | @</h2>
<p>

Critérios de aceitação:
  <ul>
    <li></li>
    <li></li>
    <li></li>
  </ul>
</p>
