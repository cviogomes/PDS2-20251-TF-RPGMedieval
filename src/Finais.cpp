#include "Finais.hpp"
#include "Utils.hpp"
#include "Musica.hpp"

void mostrarFinal(const std::string &classe, const std::string &tipo)
{

    Musica musicaFinal;
    if (tipo == "heroico")
    {

        musicaFinal.PlayMusic("musicas/HEROICO.wav");

        if (classe == "Guerreiro")
        {
            narrativePrint("Narrador", "Quando o ceu se rompeu e o mundo tremeu, foi sua espada que ficou entre a fenda e Thyria.");
            narrativePrint("Roland", "Voce... vai mesmo fazer isso?");
            narrativePrint("Guerreiro", "Um mundo novo precisa de herois dispostos a nao voltar.");
            narrativePrint("Narrador", "O Guerreiro investe contra a fenda em chamas, espada em maos. Um clarao corta os ceus. A explosao de luz sela o abismo e consome o heroi.");
            narrativePrint("Roland", "Ele nao morreu... ele se tornou parte do que salvou.");
            narrativePrint("Narrador", "Um monumento foi erguido sobre o local. Seu nome foi esculpido no aco eterno. Dizem que nos dias de batalha... ouve se sua voz no vento.");
        }
        else if (classe == "Arqueiro")
        {
            narrativePrint("Narrador", "O ceu ruia. A esperança se apagava. Mas ainda havia uma flecha na aljava.");
            narrativePrint("Elara", "Voce nao tem que fazer isso sozinho...");
            narrativePrint("Arqueiro", "Eu sou parte da floresta. E ela... nao pode morrer.");
            narrativePrint("Narrador", "Ele sobe ao ponto mais alto, fecha os olhos, e dispara a Flecha da Aurora. A luz rasga o ceu e sela a fenda mas o Arqueiro nao esta mais ali.");
            narrativePrint("Elara", "Que os ventos o levem de volta quando precisarmos...");
            narrativePrint("Narrador", "Desde aquele dia, a cada aurora, uma flecha de luz cruza o ceu de Thyria. Dizem que e' ele  protegendo nos... em silencio.");
        }
        else if (classe == "Mago")
        {
            narrativePrint("Narrador", "Ele estudou cada runa, cada verso proibido, e entendeu o preco. Selar a fenda exigiria sua propria alma.");
            narrativePrint("Mago", "Que minha essencia seja o selo. Que meu nome seja o feitico.");
            narrativePrint("Nyx", "Voce e' tolo... mas um tolo com coracao.");
            narrativePrint("Narrador", "Com um gesto final, o Mago lanca seu grimorio ao ceu. Um clarao envolve tudo. Quando a luz some, so resta o *Codex da Harmonia*, flutuando no ar.");
            narrativePrint("Narrador", "Ate hoje, dizem que o grimorio aparece apenas para os dignos. E que, ao abri lo, sua voz sussurra: \"Conhecimento... e' sacrificio.\"");
        }
    }
    else if (tipo == "tragico")
    {

        musicaFinal.PlayMusic("musicas/TRAGICO.wav");

        if (classe == "Guerreiro")
        {
            narrativePrint("Narrador", "A fenda se fechou, mas ao retornar... so havia cinzas.");
            narrativePrint("Roland", "Voce conseguiu... e' um bom fim para mim.");
            narrativePrint("Guerreiro", "Eu prometi... que voce veria a paz...");
            narrativePrint("Narrador", "O Guerreiro cava uma sepultura com as proprias maos. Crava sua espada como lapide, e parte sem dizer palavra.");
            narrativePrint("Narrador", "Dizem que ele ainda anda pelas fronteiras de Thyria, protegendo os inocentes. Mas nunca mais sorriu.");
        }
        else if (classe == "Arqueiro")
        {
            narrativePrint("Narrador", "Elara estava ao seu lado quando Moros caiu. Mas o preco foi alto.");
            narrativePrint("Elara", "Acho... que vamos vencer...");
            narrativePrint("Arqueiro", "Nao fale. Fique comigo. Por favor...");
            narrativePrint("Narrador", "Ela fecha os olhos. O Arqueiro grita... mas ninguem responde.");
            narrativePrint("Narrador", "Ele enterra Elara debaixo de uma arvore. Nunca mais tocou em um arco. Nunca mais falou. Apenas... observava o mundo reconstruir se sem ela.");
        }
        else if (classe == "Mago")
        {
            narrativePrint("Narrador", "Voce retornou da batalha como heroi... mas encontrou a torre da Academia em ruinas.");
            narrativePrint("Mago", "N..nao... Eles... estavam seguros aqui...");
            narrativePrint("Narrador", "O vento sopra entre os escombros, levando os nomes e sorrisos dos aprendizes que nao viveriam para ver a paz.");
            narrativePrint("Mago", "Nenhum poder vale isso.");
            narrativePrint("Narrador", "Desde aquele dia, ele nunca mais conjurou um feitico. Vive nas montanhas, ouvindo os ecos dos que ensinou. E de quem nao pode proteger.");
        }
    }
    else if (tipo == "sombrio")
    {

        musicaFinal.PlayMusic("musicas/SOMBRIO.wav");

        if (classe == "Guerreiro")
        {
            narrativePrint("Narrador", "A armadura agora brilha em roxo sombrio. A fenda se mantem aberta... alimentada por sua furia.");
            narrativePrint("Nyx", "Voce abracou o abismo... com gosto.");
            narrativePrint("Guerreiro", "Eu vi o mundo tentando me usar. Agora ele me serve.");
            narrativePrint("Narrador", "Roland foi o primeiro a cair. Depois, vieram as cidades. O heroi virou carrasco. Thyria virou cinzas.");
            narrativePrint("Narrador", "Seu nome nao e' mais sussurrado com orgulho... mas com terror. 'O Rei das Cinzas' — soberano do fim.");
        }
        else if (classe == "Arqueiro")
        {
            narrativePrint("Narrador", "Com olhos vazios e passos silenciosos, ele se tornou a sombra da floresta. A flecha da esperanca, agora carrega veneno.");
            narrativePrint("Nyx", "E pensar que um dia lutou pelo bem.");
            narrativePrint("Arqueiro", "Nao existe bem. So presas que ainda nao perceberam que perderam.");
            narrativePrint("Narrador", "Elara, se viva, tentou para lo. Mas ele nao hesitou. Uma flecha. Um suspiro. Silencio.");
            narrativePrint("Narrador", "O sussurro de sua presenca congela o sangue. Ninguem entra mais na floresta. Ninguem sai. O Cacador... sempre observa.");
        }
        else if (classe == "Mago")
        {
            narrativePrint("Narrador", "O Mago ultrapassou a propria humanidade. Tornou se um com a fenda, o proprio portal vivo do abismo.");
            narrativePrint("Nyx", "Juntos... somos infinitos.");
            narrativePrint("Mago", "Eu nao quero salvar o mundo... quero refaze lo 'a minha imagem.");
            narrativePrint("Narrador", "As cidades caem. Os ceus brilham em tons impossiveis. Pesadelos andam entre os vivos.");
            narrativePrint("Narrador", "Seu nome e' proibido. Seu rosto, esquecido. Mas em cada canto escuro do mundo... seu riso ecoa.");
        }
    }
}
