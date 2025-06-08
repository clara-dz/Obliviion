1 - menu de opções:
	= fases 
	= ranking
	= demais opções pertinentes (previstas nos demais requisitos):
		++ salvar nome do usuário
		++ manter/salvar pontuação
		++ Pausar
		++ Save/load 

2 - Um ou dois jogadores (com representação gráfica):
	= 2p joguem mesmo tempo	(classe Jogador cujos objetos são agregados em jogo)

3 - 3+ tipos de inimigos (com suas rep. gráficas)
	= ao menos um deve lançar projétil
	= 1 Boss

4 - 3+ tipos de obstáculos (representação gráfica)
	= 1+ causa dano se colidir

5 - Duas fases distintas:
	= jogadas sequencialmente ou selecionadas (via menu)
	= cada fase: 
		++ um cenário de jogo constituído por obstáculos
			* parte deles devem ser plataformas. Nelas:
				** pode haver inimigos e subir jogadores. 
		++ 2+ tipos de inimigos (um deles exclusivo)
			* # aleatório de instâncias (definindo um máximo)
			* 3+ instâncias para cada tipo que estiver na fase
			--> jogadores tentam neutralizar inimigos por meio de algum artifício e vice-versa
		++ 2+ tipos de obstáculos (um deles exclusivo)
			* # aleatório de instâncias (definindo um máximo)
			* 3+ instâncias por tipo
	= As fases só podem ter coincidentes: um tipo de inimigo e um tipo de obstáculo

6 -	Gerenciar colisões entre:
	= jogador e inimigos
	= jogador e projéteis
	= jogador e obstáculos. 
	--> todos devem sofrer o efeito da gravidade (menos projéteis)

7 - RULES:
	= neutralizar inimigos deve pontuar


How to install:
	mkdir build
	cd build
	cmake ..
	cmake --build .
	./Obliviion
