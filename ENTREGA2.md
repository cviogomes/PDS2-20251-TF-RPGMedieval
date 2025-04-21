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
<p>Loja: para melhorar atributos e investir ouro.
Combate: para enfrentar inimigos.</p>


<h2>Inimigo</h2>
<h3>Responsabilidades</h3>
<p>Armazenar informações de nome, vida e ataque.
Receber dano de ataques do jogador.
Realizar ataques contra o jogador.
Exibir status atual.
Definir nível de dificuldade baseado no estágio do jogo.</p>
<h3>Colaborações</h3>
<p>Jogador: para realizar combates.
Combate: para controlar o fluxo de luta.</p>


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
#Classe: Loja

Responsabilidades:
Exibir opções de melhoria de atributos.
Permitir compra de upgrades de ataque, defesa e vida.
Controlar o investimento de ouro.
Retornar 50% de investimento ao jogador.
Verificar disponibilidade de ouro.
Atualizar atributos do jogador.
Encerrar operações e retornar ao jogo.

Colaborações:
Jogador: para atualizar atributos e investir ouro.
Sistema: para exibir interface e controlar ciclo de jogo.

#Classe: Sistema

Responsabilidades:
Definir a sequência de inimigos e bosses.
Controlar o progresso do jogador.
Iniciar combates em ordem predefinida.
Chamar a loja após cada vitória.
Exibir mensagens e narrativas.
Finalizar o jogo após a última batalha.
Controlar reinício ou saída.

Colaborações:
Combate: para iniciar batalhas.
Loja: para exibir entre lutas.

<ul>

#User Story 3 @stanciola
Como jogador
Quero visitar a loja após derrotar um inimigo
Para gastar meu ouro em melhorias

Critérios de Aceitação:

A loja deve abrir após cada vitória.

Deve exibir corretamente as opções e valores.

O ouro deve ser debitado e os atributos atualizados.

#User Story 4 @stanciola
Como jogador
Quero investir parte do meu ouro
Para receber um retorno de 10% ao voltar à loja

Critérios de Aceitação:

O jogador deve poder escolher o valor a investir.

O retorno de 10% deve ser aplicado corretamente ao retornar
