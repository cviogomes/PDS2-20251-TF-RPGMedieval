<h1>RPG Medieval</h1>

<h2>Integrantes<h2>

<ul>
  <li>Caio Gomes</li>
  <li>Hebert Campos Silva</li>
  <li>Vitor Henrique Stanciola dos Santos</li>
  <li>Joshua Denny Cabral Roque</li>
</ul>

<h2>Visão geral do projeto</h2>

<p>
RPG Medieval é um jogo de RPG por turnos desenvolvido em C++, focado em combate estratégico contra diversos inimigos, sistema de classes, loja, efeitos de status e múltiplos desfechos narrativos. O jogador assume o papel de um herói (Guerreiro, Arqueiro ou Mago), enfrentando Cavaleiros do Apocalipse e monstros clássicos em capítulos progressivos com mecânicas de ouro, investimento, poções e moral.
</p>

<h1>Classes</h1>

<h2>Jogador</h2>
<h3>Responsabilidadeasçldkfjasçldjfs</h3>
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

<h2>Combate</h2>
<h3>Responsabilidades</h3>
<p>
  Iniciar batalhas entre jogador e inimigo.
Controlar turnos do jogador e do inimigo.
Definir ações possíveis: atacar, defender, recuperar vida.
Atualizar status de vida dos participantes.
Determinar resultado da batalha (vitória ou derrota).
Calcular danos e efeitos das ações.
Anunciar vencedor e distribuir recompensas.
Encerrar combate e retornar ao menu/loja.
</p>
<h3>Colaborações</h3>
<p>
  <ul>
    <li>Jogador: para realizar ações.</li>
    <li>Inimigo: para processar os ataques e ações.</li>
  </ul>
</p>

<h2>Inventário</h2>
<h3>Responsabilidades</h3>
<p>
  Exibir as habilidades e itens disponíveis para batalha.
Selecionar habilidades e itens para batalha.
Controlar quantidade itens e habilidades utilizadas pelo jogador.
</p>
<h3>Colaborações</h3>
<p>
  <ul>
    <li>Loja: Para verificar itens adquiridos </li>
    <li>Jogador: Para controlar ataques e efeitos de habilidades</li>
    <li>Combate: Para processar efeitos durante a batalha</li>
  </ul>
</p>


<h2>Habilidade</h2>
<h3>Responsabilidades</h3>
<p>
  Armazenar nome, descrição, custo de mana (ou outro recurso), dano/cura e outros efeitos (ex: atordoamento, envenenamento).
  Aplicar o efeito da habilidade ao alvo (jogador ou inimigo).
  Verificar se o jogador possui recursos suficientes para usar a habilidade.
  Exibir informações da habilidade para o jogador.
</p>
<h3>Colaborações</h3>
<p>
  <ul>
    <li>Jogador: para acessar e usar as habilidades.</li>
    <li>Inimigo: para receber os efeitos das habilidades.</li>
    <li>Combate: para processar a utilização e os efeitos durante a batalha.</li>
    <li>Inventário: para gerenciar as habilidades disponíveis.</li>
  </ul>
</p>

<h2>Item</h2>
<h3>Responsabilidades</h3>
<p>
  Armazenar nome, descrição e tipo (consumível, equipamento, etc.).
  Definir o efeito do item ao ser usado (ex: cura, aumento temporário de ataque/defesa).
  Aplicar o efeito do item ao jogador.
  Controlar a quantidade de itens que o jogador possui.
  Exibir informações do item para o jogador.
</p>
<h3>Colaborações</h3>
<p>
  <ul>
    <li>Jogador: para usar os itens.</li>
    <li>Loja: para comprar itens (se aplicável).</li>
    <li>Inventário: para gerenciar os itens possuídos.</li>
    <li>Combate: para processar o uso de itens durante a batalha.</li>
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
Para receber um retorno de 50% ao voltar à loja

Critérios de aceitação:
  <ul>
    <li>O jogador deve poder escolher o valor a investir.</li>
    <li>O retorno de 50% deve ser aplicado corretamente ao retornar</li>
  </ul>
</p>

<h2>User Story 5 | @cviogomes</h2>
<p>
Como jogador
Quero enfrentar os Cavaleiros do Apocalipse em ordem
Para seguir a história e aumentar a dificuldade.

Critérios de aceitação:
  <ul>
    <li>Os bosses devem aparecer na ordem correta.</li>
    <li>Os bosses devem ter atributos superiores aos inimigos comuns.</li>
  </ul>
</p>

<h2>User Storie 6 | @cviogomes</h2>
<p>
Como jogador
Quero ganhar ouro após vencer batalhas
Para comprar melhorias na loja

Critérios de aceitação:
  <ul>
    <li>O jogador deve receber X de ouro após cada vitória.</li>
    <li>O valor do ouro deve ser atualizado corretamente.</li>
  </ul>
</p>

<h2>User Storie 7 | @joshuadcr</h2>
<p>
Como jogador
Quero usar habilidades especiais em combate
Para ter mais opções estratégicas contra os inimigos

Critérios de aceitação:
  <ul>
    <li>O jogador deve ter acesso a uma lista de habilidades no combate.</li>
    <li>Ao usar uma habilidade, o custo de mana (ou outro recurso) deve ser descontado.</li>
    <li>O efeito da habilidade (dano, cura, etc.) deve ser aplicado ao alvo corretamente.</li>
    <li>O jogador deve receber uma mensagem indicando o uso e o efeito da habilidade.</li>
  </ul>
</p>

<h2>User Storie 8 | @joshuadcr</h2>
<p>
Como jogador
Quero usar itens do meu inventário durante o combate ou fora dele
Para obter benefícios como cura ou buffs

Critérios de aceitação:
  <ul>
    <li>O jogador deve ter acesso ao seu inventário de itens.</li>
    <li>Ao usar um item consumível, sua quantidade deve diminuir.</li>
    <li>O efeito do item deve ser aplicado ao jogador (ou outro alvo, se aplicável).</li>
    <li>O jogador deve receber uma mensagem indicando o uso e o efeito do item.</li>
  </ul>
</p>
