# RPG Medieval

## 1. Visão Geral do Projeto

RPG Medieval é um jogo de RPG por turnos desenvolvido em C++, focado em combate estratégico contra diversos inimigos, sistema de classes, loja, efeitos de status e múltiplos desfechos narrativos. O jogador assume o papel de um herói (Guerreiro, Arqueiro ou Mago), enfrentando Cavaleiros do Apocalipse e monstros clássicos em capítulos progressivos com mecânicas de ouro, investimento, poções e moral.

## 2. Estrutura do Projeto

```
src/: arquivos .cpp de todas as classes e módulos.
musicas/: trilhas sonoras para batalha, loja e finais.
include/: headers compartilhados (Personagem, Utils, Efeitos, Finais).
main.cpp: inicialização do jogo e fluxo principal.
```

## 3. Como Executar

Compile com:
```bash
g++ -std=c++17 src/*.cpp -o RPGMedieval
# ou via makefile:
make
```

Execute:
```bash
./RPGMedieval
```

## 4. Módulos e Classes Principais

A seguir, cartões CRC (Classe, Responsabilidades, Colaborações) de cada classe do projeto.

---

### Personagem
**Responsabilidades:**
- Gerenciar nome do personagem
- Controlar pontos de vida (HP) e limite máximo
- Calcular e aplicar dano de ataque e defesa
- Aplicar e limpar efeitos de status (veneno, paralisia, maldição)
- Registrar nível e experiência para progressão de atributos

**Colaborações:** Jogador, Inimigo, Combate, Utils, Efeitos

### Jogador
**Responsabilidades:**
- Escolher e armazenar classe (Guerreiro, Arqueiro, Mago)
- Gerenciar inventário (poções, itens)
- Controlar ouro e investimentos com rendimentos
- Administrar moral e influenciar finais
- Processar uso de habilidades especiais de classe

**Colaborações:** Personagem, Musica, Loja, Utils, Combate

### Inimigo
**Responsabilidades:**
- Definir atributos básicos (vida, ataque, defesa)
- Executar ataque padrão no jogador
- Receber e processar dano
- Gerenciar habilidades especiais ao atacar ou morrer
- Determinar drop de loot ou spawn de clones

**Colaborações:** Personagem, Jogador, Combate, Efeitos

### Aranha
**Responsabilidades:**
- Aplicar paralisação de 1 turno ao jogador
- Calcular chance de efeito com base em agilidade
- Executar ataque de dano leve
- Exibir arte ASCII específica
- Notificar sistema de combate sobre efeito aplicado

**Colaborações:** Inimigo, Jogador, Combate

### Bruxa
**Responsabilidades:**
- Aplicar maldição que reduz ataque por 3 turnos
- Invocar efeito de dano ao longo do tempo
- Executar ataque mágico à distância
- Alterar propriedades de defesa do jogador
- Integrar trilha sonora temática

**Colaborações:** Inimigo, Jogador, Musica, Efeitos

### CavaleiroDaFome
**Responsabilidades:**
- Reduzir vida máxima do jogador em 5 pontos
- Executar ataque físico de médio dano
- Gerenciar cooldown de habilidade
- Acionar animação ASCII de esqueleto
- Verificar condições de morte do jogador

**Colaborações:** Inimigo, Jogador, Utils

### CavaleiroDaGuerra
**Responsabilidades:**
- Diminuir ataque do jogador em 1 ponto
- Conceder bônus de ataque em turnos pares
- Calcular chance de crítico em 20%
- Exibir efeitos visuais e sonoros
- Reportar status para classe Combate

**Colaborações:** Inimigo, Jogador, Musica, Combate

### CavaleiroDaMorte
**Responsabilidades:**
- Refletir 30% do dano recebido
- Executar ataque de alto dano raro
- Aplicar status de medo (perda de ação)
- Gerenciar probabilidade de reflexão de dano
- Integrar lógica de moral para finais

**Colaborações:** Inimigo, Jogador, Efeitos, Combate

### CavaleiroDaPeste
**Responsabilidades:**
- Reduzir defesa do jogador em 1 ponto
- Propagar veneno leve por 2 turnos
- Executar ataque corpo a corpo
- Atualizar status no HUD
- Notificar sistema de efeitos de status

**Colaborações:** Inimigo, Jogador, Combate, Efeitos

### Esqueleto
**Responsabilidades:**
- Executar ataque físico básico
- Apresentar vida baixa e defesa média
- Comportamento padrão de inimigo
- Exibir arte ASCII de esqueleto
- Servir de inimigo genérico sem efeitos especiais

**Colaborações:** Inimigo, Combate

### Goblin
**Responsabilidades:**
- Roubar 20 de ouro do jogador
- Fugir com chance de 30%
- Executar ataque rápido de baixo dano
- Interagir com inventário do jogador
- Atualizar HUD de ouro

**Colaborações:** Inimigo, Jogador, Combate

### Lobisomem
**Responsabilidades:**
- Dobrar ataque se vida < 30%
- Transformar-se alterando atributos
- Executar ataque especial com chance de sangramento
- Exibir arte temática
- Registrar estado de transformação

**Colaborações:** Inimigo, Jogador, Efeitos

### Slime
**Responsabilidades:**
- Dividir-se em 2 Slimes menores ao morrer (uma vez)
- Atribuir vida reduzida aos clones
- Executar ataque simples de contato
- Gerenciar flag de divisão
- Integrar lógica de spawn no Combate

**Colaborações:** Inimigo, Combate, Utils

### Vampiro
**Responsabilidades:**
- Sugar vida do jogador em 50% do dano causado
- Recuperar vida própria com base no dano
- Executar ataque mágico de vampirismo
- Aplicar status de drenagem de vida
- Registrar efeitos de cura no sistema de status

**Colaborações:** Inimigo, Jogador, Efeitos

### Zumbi
**Responsabilidades:**
- Autocurar-se uma vez ao ficar com vida < 30%
- Executar ataque lento de alto dano
- Acionar animação de cura
- Gerenciar flag de cura única
- Atualizar HUD com nova vida

**Colaborações:** Inimigo, Jogador, Combate

### Musica
**Responsabilidades:**
- Carregar trilhas sonoras de batalha, loja e finais
- Tocar e parar música de forma assíncrona
- Controlar volume e transições
- Sincronizar efeitos sonoros com eventos de jogo
- Liberar recursos ao encerrar reprodução

**Colaborações:** Jogador, Combate, Utils

### Efeitos
**Responsabilidades:**
- Definir e categorizar tipos de status
- Aplicar e decrementar duração de efeitos
- Executar penalidades a cada turno
- Notificar jogador e atualizar HUD
- Integrar processamento com Combate

**Colaborações:** Jogador, Inimigo, Combate

### Utils
**Responsabilidades:**
- Formatar texto e aplicar cores no console
- Imprimir narrativas e menus interativos
- Gerenciar delays e limpeza de tela
- Validar e parsear entradas do usuário
- Fornecer funções de aleatoriedade e cálculos auxiliares

**Colaborações:** Todos os módulos

### Combate
**Responsabilidades:**
- Gerenciar loop de turnos completo
- Alternar ações entre jogador e inimigo
- Processar comandos de ataque, defesa e itens
- Invocar habilidades e efeitos especiais
- Determinar resultado e spawn de novos inimigos

**Colaborações:** Jogador, Inimigo, Utils, Efeitos

### Finais
**Responsabilidades:**
- Avaliar moral e registrar escolhas do jogador
- Selecionar trilha sonora apropriada
- Exibir narrativa final com arte ASCII
- Salvar resultado em log para estatísticas
- Oferecer opção de reiniciar ou encerrar jogo

**Colaborações:** Jogador, Musica, Utils, Combate

## 5. User Stories

1. Como Jogador, quero escolher minha classe (Guerreiro, Arqueiro ou Mago) para experimentar habilidades únicas desde o início.
2. Como Jogador, quero enfrentar inimigos variados com habilidades especiais para garantir que cada encontro seja desafiador.
3. Como Jogador, desejo usar poções de cura e itens de suporte para manter-me vivo em batalhas difíceis.
4. Como Jogador, desejo investir meu ouro para obter retornos e estratégias de longo prazo.
5. Como Jogador, quero visitar a loja entre capítulos para comprar equipamentos e melhorar meu personagem.
6. Como Jogador, quero que efeitos de status (veneno, paralisia, maldição) afetem minha estratégia de combate.
7. Como Jogador, quero múltiplos desfechos (heroico, trágico, sombrio) baseados em minhas escolhas e moral.
8. Como Jogador, desejo visualizar estatísticas de combate (dano causado, dano recebido, usos de habilidade) ao final de cada encontro.

## 6. Detalhamento do Projeto

### Fluxo de Jogo
- Seleção de classe
- Capítulos com encontros por turnos contra inimigos
- Acesso à loja ao final de cada capítulo
- Final narrativo baseado na moral

### Sistema de Combate
- Turnos alternados entre jogador e inimigo
- Ações: atacar, defender, usar item/habilidade
- Efeitos de status aplicados e verificados por turno
- Combate termina por derrota, vitória ou novos spawns

### Loja e Investimentos
- Loja acessível após cada capítulo
- Compra de poções, equipamentos e habilidades
- Investimentos retornam 50% adicionais no capítulo seguinte

### Efeitos de Status
- Tipos: veneno, paralisia, maldição
- Cada efeito tem duração e penalidade específica
- Gerenciado via Efeitos::processar
- HUD exibe efeitos e ícones

### Sistema de Spawn e Drops
- Slime e similares geram clones ao morrer
- Clones têm atributos reduzidos
- Memória gerenciada em Combate para múltiplos inimigos
- Drops configurados por classe de inimigo

### Moral e Finais
- Moral depende de escolhas e desempenho
- Três desfechos com arte e trilha exclusiva: heroico, trágico, sombrio
- Final baseado em limiares de moral
- Log do final salvo para análise futura

- 
<<<<<<< master

## 7. Como visualizar os resultados do gcovr
```
Para visualizar os resultados dos testes do gcovr, tudo o que você precisa fazer é localizar a pasta de testes que foi criada.
Dentro dela, você encontrará um arquivo chamado cobertura.html.

Basta abrir esse arquivo no seu navegador web preferido (como Chrome, Firefox, Edge, etc.).
Ele exibirá um relatório detalhado da cobertura do seu código, mostrando quais partes foram testadas e quais não foram, de uma forma visualmente fácil de entender.
```
=======
>>>>>>> main
