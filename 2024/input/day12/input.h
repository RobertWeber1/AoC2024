#pragma once
#include <string_view>

using namespace std::literals;

namespace day12 {

struct Input
{
	static constexpr std::string_view data[] = {
		"WEEEEEFFFFFFFFFFFTTTTTTTTTTOBBBBQGGGQQQQQQQQQQQQQQQEEGGGGGGGGGGGGGOEMMMMMMMMMMMCMMMIIIIINWWWWWWDDDDDDDDDDDOOOOOOOOOOOOOOOOOXXXXWWWWWWWWWWWWW",
		"WWEEEEWWFFFFFFFFFFFNNNTTTTOOOBBBQQQGGQQQQQQQQQQQQQEEEEGGGGGGGGGGGGOOOMMMMMMMMMMMMMMIIIINNVNNWWWDDDDDDDDDOOOOOOOOOOOOOOOOOOOXXXXCQWWWWWWWWWWW",
		"WWWEEEWFFFFFFFFFFFNNNNNNTTOOOOBOQQQQQQQQQQQQQQQQQQEEEEEEGGGGGGGGGXOOOMMMMMMMMMMMMMMMINNNNNNNWWWDDDDDDDDDVQOOOOOOOOOOOOOOOOOXXXXCCCWWWWWWWWWW",
		"WWWWWWWFFFFFFFFFFFNNNNNNNTOOOOOOUUQQQQQQQQQQQQQQQQEEEEGGGGGGGGGGROOBBMMMMMMMMMMMMMMMINNNNNNNWWDDDDDDDDDDVVVOOOOOOOOOOOOOOOGXXXXCCWWWWWWWWWWW",
		"WWWWWWWTWFFFFFFFFNNFNNJJNNOOOOOUUUUNNNQQQQQQQQQQEEEEEEEEEGGGGGRGRRRRBMMMMMMMMMMMMMMMNNNNNNNNNNDDDDDDDDVVVVVHOOOOOOOOOOOOOOGGXXXXXWWWWWWWWWWW",
		"WWWWWWWWWWFFFFGFFFFFFNOOOOOOOOUUUNNNNNQQQQQQQQQQEEEEEEEEGGYGYRRRRRRRBMMMMMMMMMMMMMMNNNNNNNNFFFDDDDDDDDDVUUUUUUUOOOOOOOOOOGGGGXXXXWWWWWWWWWWW",
		"WWWWWWWWWWWWWGGGFFFFFFOOOOOOOOUNNNNNNNNNQQQQQQQEEEEEEEDGGYYYYRRRRRRRBUUMMMMMMMMMMMMCCNNNNNNFFDDDDDDDDDDDUUUUUUUOOOOOOOORGGGGGGGGGGWWWWWWWWWW",
		"WWWWWWWWWWWWGGGGGFFFFFOOOOOOONNNNNNNNNNNNNQQQQQEEEEEEEEGGRRRRRRRRRUTUUUUUMMMMMMMMCMCCNNNNNNFFFDDDDDDDDDDUUUUUUUOOOORRORRRRRGGGGGGGGKKKWKWWWW",
		"WWWWWWWWWWWGGGGGGFFFHFOOOOOONNNNNNNNNNNNNNNNQQQQEEEEEEEEERRRRRRRRRUUUUUUUMMMMMCCMCCCNNNNNNNNNFDDDDDDDDDGUUUUUUURORRRRRRRRGGGGGGGGGGKKKKKWWWW",
		"WWWWWWWVGGGGGGGGGGGFVFOOOOOOOOONNNNNNNNNNNNNNWWQEEEEUEEERRRCCCCCCCUUUUUUTMIIIMCCCCCCNNNNNNNNNDDDUUDDDRDGUUUUUUURORRRRRRRRRGGGGGGGGGGKKKKKWWW",
		"WWWWWWWGGGGGGGGGGGHVVBOOOOOOOOOONNNNNNNNNNTTWWHQEEEEUUEERRRCCCCCCCUUUUUUUIIIIMMCCCCNNNNNNNNNHDAANUNNNNNNUUUUUUURRRRRRRRRRRGGGGGGGGGAKKKKKWWW",
		"WWWWWWWWWGGGGGYYGGVVVBOOOOVVVOOONNNNNNNNNNTWWWTTTEEUUUUURRRCCCCCCCUUUUUUUIIICCCCCCNNNNWWNNNNNNAANUNNNNNNUUUUUUUUUUUUUUUUHGGGGGGGGGGGKKKKKKWW",
		"WWWWWWWWWGGGGYYYYYVVVBVOOVVVVVNNNNFFNNNNNNTTWWTTTTTUUUUUUURRRRRUUUUUUUUUUIICCCCCCCCCCCCCANNNNNAANNNNNNNNUUUUUUUUUUUUUUUUHGGGGGGGGGGGKKKKKKWW",
		"WWWWWWWGGGGGGYYYYYVVVVVVQVVVVVNNXXXFFFFNFTTTTTTTTTTUUUUUUURRRRRRUUUUUUUUUIICCCCCCCCCCCCCAAAANNAAANNNNNNGGGGGGRUUUUUUUUUUUUUUUUUGGGGKKKKKKKGG",
		"WWNWWWWGGGGGGGYYVYVVVVVVVVVVVVVNFFFFFFSFFTTTTTTTTTTUUUUUUURRRRRRWUUUUUUUUUUUCCCCCCCCCCCCAAAAAAAAANNNNNGGGGGRRRUUUUHUUUUUUUUUUUUGGGGKKKKKKKGG",
		"WWGGGGGGGGGGGGYVVYVVVVVVVVVVVVVVFFFFFFSFFFFTTTTTTFTTUUUUUURRRRRWWUUUUUUUUAAUCCCCCCCCHCCAAAAPPPAAANNNNNVVGRRRRRUUUUHUUUUUUUUUUUUGKKKKKKKKKKKG",
		"WDDGGGGPGGGGGYYVVVVVVVVVVVVVVVVVVVFFFFFFFTTTTTTTTFFFUUUUUBRRRRRRUUUUUUUUAAAAACCCCTCCMMAAAAPPPPPAANNPPVVVVZRZZZUUUUHUUUUUUUUUUUUKKKKKKKKKKKKG",
		"DDDGDGGGGGGGGYYYVVVVVVVVVVVVVVVVVVFFFFFFFFTTTTTTTFFFFUBBBBBRRRRRUUUUUUUUUAAAAACCACCCMAAAAPPPPPPAPVVPVVVVVZZZZZUUUUHHHHHHHQUUUUUKKKKKKKKKKKKK",
		"DDDDDDDGDGWWJYJVVVVVVVVVVVVVVVVVHHHHFFFFFFTTTTTFFFFFFUUBBBRRRRRRUUJRUUCUUAAAAAAAAMPCMMAAAAPPPPPAPJVVVVVVVZZZZZZHHHHHHHHHQQUUUUUKKKKKKKKKKKKK",
		"DDDDDDDDDDJWJJJVVVVVVVVVVVVVVVVVHHHHFFFTFTTTTTFFFFFFFFBBBBBRRRRRRURRUUUAAAAAAAAMMMMCMMMMAAAPPPPPPJVVVVVVVZZZZRZZRHHHHNHHQQUUUUUZKKKKKKKKKKUK",
		"DDDDDDDDDDJJJJJJJJJVVVVVVVVVVVVVHHHHFFFFHTTTTHTHFFFFBBBBBBBBRRRRRRRRRUUUUAAAAAAMMMMMMMMMPPPPPPPPPVVVVVVVVVVRZRZZRHHNNNDDQQUUUUUKKKKKKKKKKKUU",
		"DDDDDDDDDDJJJJJJJJJVVQVVOVVVAAHVVHHHFFFFHHHTTHHHHFFRRRRRRRRBBBRRRRRRRRRUAAAANNNMMMMMMMMMYPPPPPPPPVVVVVVVVVVRRRRRRRRNNNDDDDDDDDDDKKKKKUKUUUUU",
		"DDDDDDDDDDJJJJJJJJDVVQQVVVVVVVHHHHHHHHHHHHHHHHHHHFFRRRRRRRRBBBBRRRRRRKKNNAAANNNNNMMMMMMMPPPPPPPPVVVVVRRRVVVRRRRNRRRNDDDDDDDDDDDDNFFKKKUUUUUU",
		"DDDDDDDDDDDDJJJJJJJQQQVVVVVVVVVHHHHHHHHHHHHHHHHHFFFRRRRRRRRBBBBEERRRKKKKNNNNNNNNMMMMMMMPPPPPPPPPPUUVVRRRRRRRRRRRRRRNDDDDDDDDDDDDNKKKNNUUUUUU",
		"DDDDDDDDDDDJJJJJJJQQQQQVVOVPVHHHHHHHHHHHHHHHHHHHHFFRRRRRRRRGGEEEEERNNKKKNNNNNNNNMMMMMMMPPPPPPPPPPUUUUURRRRRRRRRRRRSDDDDDDDDDDDDDNNNNNUUUUUUU",
		"DDDDDDDDDDDJJJJJJQQQQQQQOOOPPHHOHHHHHHHIHHHHHHHRRRRRRRRRRRRGGEEENNNNNNNNNNNNNNNMMMMMMMMMPPPPPPPPUUUUUUURRRRRRRRRRRSDDDDDDDDDDDDNNNNSNUUUUUUU",
		"DDDDDDDDDDJJJJJJJQQQQQQOOOOOOOOOHHHHHHHIIHHHHIFRRRRRRRRRRRRRRGEEEEENNNNNNNNNNNNMMMMMMMMPPPPPPPPPUUUUUUURRRRRRYRRRSSDDDDDDDDDDDDNNNNSISSSUUUU",
		"DDDDDDDDDDJJJJJJJJFFQQQOOJOOOOOOHHHHHHHIIHHIIIFRRRRRRRRRRRRRRGEEEEENNNNNNNNNNNMMMMMMMMMPPPPPPPPUUTTUUUURRLRPRYYYYYDDDDDNNNNNNNDNNNNSSSSSSUUU",
		"DDDDDDDDDDJJJJJJJJFFQOOBOOOOOOQQHHHHHIIIIHIIIIFRRRRRRRRRRRRRRGEKKEEENNNNNNNNNNNMMMMMMMMMMPPPPPPTTTUUUUURRYRYYYYYYWDDDDDNNNNNNNNNNNSSSSSSUUUU",
		"KKDDDDDDDDDJJJJJFJFQQOOOOOOOOOOOOHHIIIIIIIIIIIFRRRRRRRRRRRRRKKKKEEEENNNNNNNNNNNMMMMMQMMMMZPPPPPTTTUUUUUUUYYYYYYYYNNDDDNNNNNNNNNNNSSSSSSSSUUU",
		"KDDDDDDDDDDDDKFFFFFFHHHHHHHHHOOODIHHIIIIIIIIIIFRRRRRRRRRRRRRRRRRRKENNNNNNNNNNNNMMMMMQXMMMZZPZTTTTTTUUUYUUYYYYYYYYYNNNNNNNNNNNNNNSSSSSSSSSSUU",
		"KDDKDDKKKDDDKKFFFFFFHHHHHHHHHOOOIIIIIIIIIIIIIIIRRRRRRRRRRRMRRRRRRKKNNNNNNNNNNNNMMMMMQXMMMZZZZZTTTTTTUUYYYYYYYYYYYYNNNNNNNNNNNNNSSSSSSSSSSSUU",
		"KDDKKKKKKKKKKFFFFFFFHHHHHHHHHOOOZIIIIIIIIIIIIMMEERRRRRRRRRMRRRRRRKKKKNNNNNNNNNNMGQQQQQQZMZZZZZTTTTLILLLYQYYYYYYYYNNNNNNNNNNNNNNNSSSSSSSSSSUU",
		"KKKKKKKKKKCCFFFFFFFFHHHHHHHHHOOOZZIIIIIIIIIIMMMEERRRRRRRRRKKKKKKKKKKNNNNNNNNNCMMGGQQQQQZZZZZZZTTTLLLLLLYYYYYYYYYYYNNNNNNNNNNSNSSSSSSSSSSSUUU",
		"NNKKKCCKKKCCFFFFFFOOHHHHHHHHHOOOZZZIZZXIIIIMMMMMMRRRRRRRRRKJKKKKKKKKKNNNCUNNNNNGGQQQQQZZZZZZZZZTTLLLLLLJYYYYYYYYYYNNNNNNNNNSSSSSSSSSHSSSSUUU",
		"NNNKKCCCKKCFFFFFFFFFHHHHHHHHHOOOZZZZZZZCIICMMMMMMMMMMMMMJJJJJKKKKKKKKKKKCCCNNNNNQQQQQZZZZZZZZZTTTTLLLLLLLHHHYYYYYYYYYNNNNNNNNSSSSSSSSSUUUUUU",
		"NNNCCCCCKCCCFFFFFFFFHHHHHHHHHOZZZZZZZZZCCCCMMMMMMMMMMMJJJJJJJJKKKKKKKKKKKCCCCNNCCCQCZZZZZZZZZZZZTTTLLLUHHHHHYYYYYYYYYNNNNNNNPPPSSSSSSSUUUUUU",
		"NNEECCCCCCCCSFFFFFFFHHHHHHHHHOZZZZZZZWZCCCMMMMMMMMMMMJJJJJJJJJJJKKKKKKKKYCCCCCCCCCQCZZZZZZZZZZZZZTTTUUUUHHHHYYYYYYYYYNNUNNNNNGGGSGSSSSUUUUUU",
		"NNEECCCCCCCCFFFFFGFFGVVOZZZZZZZZZZZZZZCCCCCMMMMMMMMMMMJJJJJJJJJJKKKKKKKKKATTTTCCCCQCCZZZZZZZZZZZZTKKUHUUHHHHHYYYYYYYYNNDZNNGGGGGQGGGGGGUUUUU",
		"NNCCCCCCCCCPCFFFFGGFGVGZZZZZZZZZZZVZZZZZCCCMMMMMMMMMJJJJJJJJJJJJKKKKKKKKKATTTCCCCCCCCZZZZZZZZZZZTTKKUHHHHHHHHHYYYYYYYYYDZZZGGGGGGGGGGGGUUUUU",
		"NCCCCCCCCCCCCFFFFGGFGGGZZZZZZZZVVVVVZZVCCCCCMYYYYYYYJJJJJJJJJJJDKKKKKKKKKTTTTTTCTTCCCCCZZZZZZZZZZTKKKKHHHHHHHHHHHYPYYYDDZGGGGGGGGGGGGGGGUUUU",
		"NCCCCCCCCCCCGGFFGGGFGGZZZZPPZVVVVVVVVCVCCCCCCYYYYYYYGJJJJJJJJJJDKKKKKKKKKTTTTTRTTTCCCCCZCZZZZZZZZZKKKKKHHHHHHHHPPPPPYDUDDGGGGGGGGGGGGGGGUUUU",
		"NNNCCCCCCCCCGGGGGGGGGGGZZZPPPVVVVVVVVVVVCCCHCCCYYYYYJJJJJJJJJJJJKKKKKKKKGTTTTTTTTCCCCCCCCZZZZZZZKKKKKKKHHHHHHHHHPPDDDDDDTGGGGGGGGGGGGRRGUUUU",
		"NNNNCCCCCCCGGGGGGGGGGGGZZPPPPSVVVVVVVVVVHHHHCCCYYYYYJJJJJJJJJJJJJKKKDDKKGTTTTTTTTTTTTCCKKUZZZZZZKKKKKKKHHHHHLHHHPPPDDDDTTGGGGGGGGGGGGRRRUUUU",
		"NNNNNCCCGGGGGGGGGGGGGGGGGPPPPSVVVVVVVVVXHHHHCCCYYYYYADDDJJJJJJJJJJKKDDDTTTTTTTTTTTTTTTTTKKKKKKKKKKKKKKKDDELLHHHHPPPPPDTTTTGGGGGGGGGGGRRRRUUU",
		"NNNNNNCCGGGGGTTTGGGGGGGGPPPPPSVVVVVVVVVYYYYYYYYYCYEEAAADJJJJJJJZJJJKKKDTTTTTTTTTTTTTTTTKKKKKKKKKKKKKEEKDEEELLHPPPPPNPDTTTTGGTGGRRGGGRRRRUURR",
		"NNNNNNCCCTTTTTTTTTGGPPPGGPPGGGVVVVVVVVHYYYYYYYYYCCAAAAAAJJJJJJJTTTJKKKTTTTTTTTTTTTTTTTTWKKKKKKKKKKEEEEEEEECELLPPPNNNNNNTTTTTTTGRRRRRRRRRRRRR",
		"NNNNNNNNCTTTTTTTTGGPPPGGPPPGGVVVVVVVHHHYYYYYYYYYAAAAAAAQQQJJJJJTTTKKKKTTTTTTTTTTTTTTTTTTKKKKKKKKKKKEMEEEEEEEEPPPNNNNNNTTTTTTTGGRRRROORRRRRRR",
		"NNNNNNNNNTTTTTTTTPPPPPPPPPGGGGVVVHHYYYYYYYYYYYYYAAAAAAAQQQJJJRJTTTTTTTTTTTTTTTTTTTTTTTKKKKKKKKKKKKKKKQEEEEEEEEFFNHNNNNNNNTTTTTOROOOOOOORRRRR",
		"NNNNNNNNGITTTTTTPPPPPPPPPPGGGGGHHHHYYYYYYYYYYYYYAAAAAEAAQQQQQQTTTTTTTTTTTTTTTTTTTTTFTTKKKFKKFKLKKKKKKQEQQEEKKFFNNNNNNNNNNNNTTOOROOOOOGGORRRR",
		"NNNNNNNGGTTTTTIPPPPFFFPPFGGGGGGGYYYYYYYYYYHHHAAAAAAAAAAAQQQQQQQTTTTTTTTTTJJJJJJJJTTFFFFFFFFFFKKKWNNQQQQQQGKKFFFNNNNNNNNNNNNTTOOOOOOOOOGORRRR",
		"NNNNNNNGGGGGGGIIFPFFFFFFFGGGGGGGYYYYYYYYYYHHLAAAAAAAAAALQQQQQQQTTTTTTTTTTJJJJJJJJGTFFFFFFFFFFFFKNNNNQQQQQGGKKFNNNNNNNNNNONNTOOOOOOOOOOOOORRR",
		"NNNNGNGGGGGGGGIIFFFFFFFFFGGGGGGGYYYYYYYYYYHHAAAAAAALLLLLLYQQQQQTTJJJJJJJJJJJJJJJJGFFFFFFFFFFFFFFNNNNNNQGGGGGGGQGNNNNNNNNNNHHHOOOOOOOOOOOORRR",
		"NNGGGGGGGGGGGGGIIFFFFFFFFFGGGGGGYYYYYYYYYYGHANAAAAHLLLLLLYQQQQQJJJJJJJJJJJJJJJJJJFFFFFFFFFFFFFFFRNNNNQQQQQQQQQQGNNNNNNNNNHHHHOOOOOOOOOOORRII",
		"NNNGGGGGGGGGGGGGIFFFFFFFFFCGGGGGYYYYYYYYYHHHANANNAALLLLLLYYQQQQJJJJJJJJJJJJJJJJJJFFFFFFFFFFFFFFFNNNNNQQQQQQQQQQGVNNNNNNNNHHHHOOOOOOOOOIIRRII",
		"NNGGGGGGGGGGGGQQFFFFFFFFFFGGGGGPPGGHHLTTEHHNNNNNNCALLLLAAYYQAQWJJJJJJJJJJJJJJJJJJWFFFFFFFFFFFFFFFNNNNQQQQQQQQQQGGIINDNNNNNPPPPOOOOOOOOIIIIII",
		"NNGGGGGGGGGGGGQQKKFFFFFFFFFUGPPPPGGHITTTTTTNNNNNNNKLLLLLAYYYQQWJJJJJJJJJJJJJJJJJJWFFFFFFFFFFFFFFRFFNNQQQQQQQQQQGGIIINNNNNNPPPPFOOOOOOOIIIIII",
		"NNNGGGGGGGGGGQQKIKFFFFFFFFPPPPPPPPPPIJJJJJNNNNNNNWLLLLLAJJJJJJJJJJJJJJJJJJJJJJJJJWWFZFFFFFFFFFFFFFRRRQQQQQQQQQQQIIIINNNNPPPPPFFOOOOOOOIIIIII",
		"NNNGGGGGGGGGGGKKKKFFFFFFFFFPPPPPPPPPIJJJTTNNNNNNLLLLLLAAJJJJJJJJJJJJJJJJJJJJJJJJJWWPPPPFFPFFFFFFFRRRRQQQQQQQQQQQIIIINNNPPPPPPPAOOOOODIIIIIII",
		"NNGGGGGGGGGGGGKKKKKKFFFFFFFPPPPPPPPPPJJJTTTNNNNAAAAAAAAAJJJJJJJJJJJJJJJJJJJJJJJJJWWPPPPPPPFFFFRFFRRRRQQQQQQQQQQQYIYIINNNPPPPPPAOOOOODIIIIIII",
		"GGGGGGGIGXGKKGKKKKKFFFFFFFUUUUPPPPPPJJJJJJJNNNAAAAAAAAAAJJJJJJJJJJJJJJJJJJJWWWQWWWWPPPPPPKKFFNRRRRRRRQQQQQQQQQQQYYYYYYPPPPPPPPAAAAAIIIIIIIII",
		"XGGGGGGGGXXKKKKKKKKFFFFFUUUUUPPPPPPPJJJJJJJNNOAAAAAAAAAAJJJJJJJJJJJJJJJJJJJWWWQWWWPPPPPPPKKVVVRRRRRRRRMMMRYYYRYYYYYYYPPPPPPPPAAAAAAIIIIIIIII",
		"XGXXXXXXXXKKKKKKKKKBBFBBPPPPPPPPPJJJJJJJJJIOOOAAAAAAAAAAJJJJJJJJGVJJJJJJJWEEEQQWWPPPPPPPPPPVVVVVVRRRRMMMMRRYYYYYYYYYYYYPPPPPPAAAAAAIIIIIIIII",
		"XXXXXXXXXXKKKKKKKKBBBBBBBBBBBBCJJJJJJJJJJJOOOOOOOAAAAAAAJJJJJJJJGVJJEEEEEEEEEQQWWWPPPPPPFPVVVVVVVQVVRRMMRRRRYYYYYYYYYYYTPPPPAAAAAAAAAIIIIIII",
		"XXXXXXPXKKKKKKKKKKKBBBBBBBBBCBCJJJJJJJJOOOWWOOOOOAAAAAAGJJJJJJJJGJJJEEEEEEEEEEEEEEPPPPPVVVVVVVVVQQVVRRMRRRRRRRYYYYYYYYYYAAAAAAAAAAAAAIIIIIII",
		"XXSXPPPPPKKKKKKKKBBBBBBBBBBBCBCJJJJJJJJOOOOWOOOOOOOAAGAGJJJJJJJJGJJLEEEEEEEEEEEEEEPPPPPVVVVVVVVVVVVVRRRRRRRRRRYYYYYYYYWWAAAAAAAAAAAAAAIIIEIE",
		"XXSXPPPPPPKKPPPKBBBBBBBBBBCBCCCJJJJJJJOOOOOOOOOOOOLLLGGGGGGGGGGGGGJLLJFFFJQEEEEEEEPPPPPPVVVVVVVVVVVVVVRRRKRRRYYYYYYYYYWWAAAAAAAAAAAAIIIIEEEE",
		"XXSSPPPPPPPKPPPPPBBBBBBCCCCCCCCCJJJJJJJOOOOOOOOOOOILLLGWWGGGGGGGGGZMMMMMMZQEEEEEEEPPPPPTTVVVVVVVVVVWKKKKKKKKRRQQQQYYYYYWWWAAAAAAAAAAAAAAAAEE",
		"XXSMPPPPPPPPPPPPBBBBBBBCCCCCCCCCCJJJDJDDOOOOOOOOOOLLLLOLLLGGGGGGGGMMMMMCCMFEEEEEEETPPPPTXXXVVVVVVVVVKKKKKKKKRRRQQQQQYYYYWWIAAAAAAAAAAAAAAEEE",
		"XXSSSSSPPPPPPPPPPBBBCCCCCCCCCCCCCJDJDOODDOOOOOOOOLLLLLLLLLGGGGGGGGGMMTMMEEEEEEEEEETTPTTTTVVVVVVVVVVVKKKKKKKKRRQQQQQYYWYWWWIIAAAAAAAAAAAAAAAE",
		"XXSSSBSPPPPPPPPPPBBBBCCCCCCCCCCCCCDDDDDDDOOOOOOOOLLLLLLLLLQLGGGGGGGRGTMMEEEEEEEEEETTTTTTVVVVVVVVVVVVKKKKKKKKRRQQQQQQQWWWWWIIAIAAAAAAAAAAAAGO",
		"XXSSXPPPPPPPPPPPPWWWWCCNCUCCCCCCCZDDDDDDDOOOOOOOOQLLLLLLLLLLGGLGGGGGGTMMEEEEEEEEEETTTTTTVVVVVTTHVVVVKKKKKKKKKRQQQQQQWWWWWIIIIIIAAAAAAAAAOOOO",
		"XXXXXXXPPPPPPPPPPWWWWCINCCCCCCCCCDDDDDDDDOOOOOOWOORLLLLLLLLLLLLGMGMMNMMMEEEEEEEEEETTTTTTVVVTTTTTKKKKKKKKKKKKKKQQQQQQWWIIIIIIIIIAAAAAAAAAAOOO",
		"XXXXXXXPPPPPTTPPPWWWWWWNNNNBBBBBBDDDDDDDDOOOOOOWOOLKLLLLLLLLLLLQMMMMNMMMEEEEEEEEEETTTTTTTTTTTTTKKKKKKKKKKKKKKQQQQQQQWIIIIIIIIIIIIOOOAAAOOOOO",
		"JJJXJJXPPPPNTTTWWWWWWWNNNNNBBBBBBUDDDDDDDOOOWWWWWFLLLLLLLLLLLLLLLMMMMMMMEEEEEEEEEETTTTTTTTTTTTTTKKKKKKKKKKKKKQQQQQQQWWWIIIIIIIIIIIQOAAAOOOOO",
		"JJJJJJJJPPPNTTTTTWWWNNNNNNNBBBBBBDDDDDDDDOOOWWWWWLLLLLLLLLLLLMLLMMMMMMMMMEEEEEEEEETTTTTTTTTTTTTTTKKKKKKKKKKKKQQTQTQQQIIIIIIIIIIIIIIOKAOOOOOO",
		"JJJJJJJNNNNNNTTTTTWWNNNNNNBBBBBBBDDDDDDDDDOWWWWWWBBLLLLLLLLLMMLLMMMMMMMMMEEEEEEQQQTTTTTTTTTTTTTKKKKKKKKKKKKKFQQTTTKXXIIIIIIIIIIOOHHHHKOOOOOO",
		"JJJJJJJNNWNNNTTTTNNWNNNNNNBBBBBBBSVDDDDDXXOOOWWWBBBLLLLLLULLMMMMMMMMMMMMWMEEEEBBQQQQQTTKTOTTTTTTKKKKKKKKKKKKKKQQTKKXXXIIIIIIIIIHHHHHHKOOOOOO",
		"JJJJJJWWWWWNNTTTTNNWNNNNNNBBBBBBBVVVVVEDXXXXWWWWWWBSSLTTLMLMMMMMMMMMMMMMMBEEEEBBQBBQQQQQOOTTTTTTTKKKKKKKKKKKKKKQKKKKKXXIIIIIIIIHHHHHHOOOOOOO",
		"JJJJJDDWWWWNNNTTTNNNNNNNNNBBBBBBBVVVVVVDXXXXWWWWWBBOOOTTMMMMMMMMMMMMMMMMBBEEEEBBBBQQQQQQOOTTTTTTTTKKKKKKKKKKKKKKKKKKKXXXXXIIIIIHHHOOOOOOOOOO",
		"JUJJJWWWWWWNNNTTNNNNNNNNNNNBBBBBBVVVVVVDXXXXXWWWWBBBOOMMMMMMMMMMMBBBMBBMBBEEEEBBBQQQQQQQTTTTTTTTTTKKKKKKKKKKKKKKKKKKKXXXXXIIIIIHHHOOOOOOOOOO",
		"JUWWWWWWWWWWWNNNNNNNNNNNNNNBBBBBBJVVVVVDXXXXXXXXWOOOOOMMMMMMMMMMMBBBBBBBBBEEEEBBQQQQQPQPTTTTTTTTTKKKKKKKKKKKKKKKKKKKKXPPPPIIIIPHHHOOOOOOOOOO",
		"UUUWWWWWWWWWWWWWWWNNNNGGNNGBBBBBBJVVVJXXXXXXXXOOOOOOOOGGMMMMMMMBBBBBBBBBBBEEEEBMQTTPPPQPPTTTTTTTTTKVVVVVVVVVVVVVKKKKKPPPPPZZIPPHHHOOOOOOOOOO",
		"UUUWWWWWWWWWWWWWWWNNNGGGGGGGGBBBBJJJJJJXXXXXXOOOOOOOOOOGMVMMMMMBBBBBBBBBBBEEEEBBBTTTTPPPTTTTTTTTTTKVVVVVVVVVVVVVKKKKKNPPPPPPEEEHHHOOOOOOOOMO",
		"UUUWWWWWWWWWWWWWWNNNNGGGGGGGGBBBBJJJJJJJXXXXXOEOOOOOOOOOOMMMMMMMCCCCBBBBBBBBBBBAAATTTTTPTTTTTTTTTKKVVVVVVVVVVVVVKKKPCPPPPPPPPEEHHHOOOOOOOOMM",
		"UUUWWWWWWWWWWWXXNNNNGGGGGGGGGBBBBJJJJJJXXXXXXOOOOOOOOOOOMMMMMMCCCICCBBBBBBBBBBBTTTSSSSSSSSSZTTTTTUUVVVVVVVVVVVVVKPPPPPPPPPPPNNEHHHFFOFOOOMMM",
		"UUUWWWWWWWWWWWXNNNNGGGGGGGGGGJJJJJJJJJJJXXXXXXXOOOOOOOOOMFMMIIIICIIIIBBBBBBBYBLTTTSSSSSSSSSTTUTXUUUVVVVVVVVVVVVVKPPPPPPPPPPNNNNNPPFFFFFOMMMM",
		"UUUUWWWWWWWWWWXNNNNNGGGGGGGGGJJJJJJJJXXXXXXXXXZQOOOOOOVOFFFMIIIIIIIIIIBBBBBBBBTTTTSSSSSSSSSUUUTUUUUVVVVVVVVVVVVVKPPPPPPPPPPPNNNNNNFFFFFQMMMM",
		"UUUWWWWWWWWWWXXXXXGGGGGGGGGGGGGJJJJJJJJXXXXXXXZZOOOOOOOIIIMMIIIIIIIIIIBBBBBBWBTTTTSSSSSSSSSUUVVVVVVVVVVVVVVVVVVVKPPPPPPPPPPPNNNNNFFFFFQQQMMM",
		"UUUUWWWWWWWZWWXNXXXXGGGGGGGGGGJJJJJJJJXXXXXXZZZZDDDOOOOIIIIIIIIIIIIIIIBGFFBBWTTTTTSSSSSSSSSUUVVVVVVVVVVVVVVVVAAKKPPPPPPPPPPNNNNNNNNQQQQQQMMM",
		"UUWWWWWWWUUWWNNNNXXXGGGGGGGGJJJJJJJJJJJXXZZZZZZZZDDZOOHBIIIIIIIIIIIIIGGGGBBBWTTTTTSSSSSSSSSUUVVVVVVVVVVVVVVVVAAKKPPPPPPPPPPNNNNNNNNNQQQQQMQQ",
		"UUWWWUUWUUNNWNNNNXXGGGGGGGGGJJJJJJJJJJXXXXZZZZZZZZZZKKHIIIIIIIIIIIIIIGGGGGBBWTTTTTSSSSSSSSSUUVVVVVVVVVVVVVVVVAAAKKKPPPPPPPPPPPNNNNSSSQQQQQQQ",
		"UUWWUUUUUNNNNNNNRRXXGFGGGGGJJJJJJJJJJJJXXXZZZZZZZZZKKKHHIIIIIPIIIIIIWGGGGGGBBTTTTLSSSSSSSSSSUVVVVVVVVUUUUVAAAAAAAKKPPPPPPPPPPPNNNSSSSQQQQQQK",
		"UUUWUNNNNNNNNNNRRBRRGFGGGGGJFJJJJJJJJJJXXXZHHZZZKZZKKKHHIIIIPPPPIIIIIGGGGGGGGTTTLLSSSSSSSSSSAVVVVVVVVUUUUVAAAAAKKKKPPBBBBPPPPPSNSSSQQQQQQQQK",
		"UUUUUNNNNNNNNNNRRRRRFFGGGGGJFFFJJJJJJJJJXOHHZZZKKKKKHHHHHIIIPPPPIGGGGGGGGGGGGGTTTLLAAAAASSSSAAAUUUUUUUUUUUAAAAAAAKKKBBBBBBPPPSSSSSSSSSQKQQQK",
		"UUUUUUUNNNNNNNNNRRRRFFGGFFGFFFFFFJJJJJOOOOHOCZKKKKKHHHHHHIIIPPPPPGGGGGGGGGGGGGTTTTAAAAAASSSSAAAUUUUUUUUUAAAAAAAAAKKKBBBBBBBBBSBSSSSSSDDKKQQK",
		"UUUUUUUUNNNNNNNRRRRRFFGFFFFFFFFFFFJJJJOOOOHOOKKKKKKKHHHHHHHHCCPPGGGGGGGGGGGBBBBBBBAAAAAASSSSAAAUUUUUUUUAAAAAAAAAAABBBBBBBBBBBBBSBSSSSDDDKKKK",
		"UUUUUUUUUUNNNNRRRRRFFFGFFFFFFFFFFFJJJOOOOOOOOKKKKKHHHHHHHHHHCHPPPGGGGGGGGGGBBBBBBBAAAAAAAAAAAAAAUUUUJJUAAAAAAAAAAFFBBBBBBBBBBBBBBBDDDDDKKDDK",
		"UUUUUUUUUUNNNRRRRRRRRFFFFFFFFFFKJJJJJJOOOOOOOOKKZZHHHHHHHHHHHHYPZGGGGGGGGGGBBBBBBBAAAAAAAAAAAAAUUUUUUUUAAAAAAAAAAABBBBBBBBBBBBWBBBWDDDDKKDDK",
		"UUUUUUUUUUNBNRRRRRRRRRFRFFFFKKKKKKKOOOOOOOOOOKKKZZHHHHHHHHHHHHYZZYGGGYYGGYGGGGGGAAAAAAAAAAAAQQQUUUUUZAAAAAAAAAAABBBBBBBBBBBBYSWWWBWDDDDKDDKK",
		"UUUUUUUUUUNBNURRRRRRRRRRKFKKVKKKKKYYOOOOOOOOOOZZZZZZHHHHHHHHHHYYYYYYYYYYYYGGGGGGGAAAAAAAAAQQQQQQQQULZAAAAAAAAAAAABBBBBBBBBBBYSSSWWWWWDDDDDKK",
		"DDDDUUUUUUNBBBRRRRRRRRRPKKKKKKKKKKYKOOOOOOOOZZZZZZZZZHHZHHHHHHYYXXXYYYYYYYYGGGGGGAAAAAAAAQQQQQQQQQUUZAAAAAAAAAAAABBBBBBBBBBBYYSSSWWWDDDDDDPP",
		"DDDDDDDUUUBBBBRRRRRRRRKKKKKKKKKKKKKKVOOOOOOOOZZZZZZZZHZZHHHHHYGYXYYYYYYYYWWWWCJCAAAQQQAAQQQQQQQQQUUZZZZZAAAAAAAAABBBBBBBBBBYYSSSSSWZDDDPDDPP",
		"DDDDDDDDDBBBBBBRRRRRHKKKKKKKKKKKKKKKOOOOOOOOOOZZZZZZZZZZZHHQQYYYYYYYYYYYYYYWCCCCCAAQQWQQQQQQQQQQQZZZZZZZAAAAAAAAHBALLOBBRBBBSSSSZZZZDDDPPPPP",
		"DDDDDDDDDDBBBBBLLNRRNNNKKKKKKKKKKKKKOOOOOOOOOOZZZZZZZZZZZZZQQQQQQYYYYYYYYYYYCCCCCMQQQQQQQQQQQQQQQZZZZZZZZZZZAAAAAAAALOORRBRRSSSSZZZZZDDDPPPP",
		"DDDDDDDDDDDBUBBLLNRRNNNKKKKKKKKKKKKKOOOOOOOOOOOZZZZZZZZZZZQQQQQQYYYYYYYYYYYYCCCCCCQQQQQQQQQQQQQQQQQZZZZZZZZZZAAAAOOOOOORRRRRSSSZZZZZZZDPPPPP",
		"DDDDDDDDDDDFBBQLNNNNNNKKKKKKKKKKKKKFFFOOOOOOOZZZZZZZZZZZZZZQQQQYYYYYYYYYYYYYNYCCCCQJQQQQQQQQQQQQQPZZZZZZZZAZZJAOOOOOOOOZZRRRRSSZZZZZZZZZPPPP",
		"DDDDDDDDDDDDNLLLNNNNVVKKKKKKKKKKKFFFFAOOOOOOOOZZZZZZZZZZZQQQQQQYYYYYYYYYYYYYYYCCCCCJQQQQQQQQQQQQQQSZZZZEZEAOOOOOOOOOOOARRRRSSSZZZZZZZZZPPPPP",
		"DDDDDDDDDDDNNNLNNNNNNNKKKKKKKKKKFFFFFOOOOOOOOOZZZZZZZZZZZZZQQQQQYYYYYYYYYYYLYCCCCCPJQQQQQQQQQQQQQJZZEEEEEEAAOOOOOOOOOOOREEESSHHZZZZZZZPPPPPP",
		"DDDDDDDDDDDNNNNNNNNNNNNKKKKKKKKKKFFFFFFFFOOOOOZZZZZZZZZZUUZQQQQYYJYYJJLYYLLLCCCCCCPPQQQQQQQQQQQQQJJTTREEEEAAAOOOOOOOOOOOEEESSHHZZZZZZZPPPPPP",
		"DDDDDDDDDDNNNNNNNNNNNNOKKKKKKKKKFFFFFFFFDOOOOOOOHZZZZZZZUUQQQQUYYJJJJJLLLLLLLLLCPPPPPPPQQQQQQQQQQTTTTTTEEEEAAAOOOOOOOOOOOEEYSHHHZZZZZZPPPPPP",
		"DDDDDDDDDDNNNNNNNNNNNNNKWWKKKKFFFFFFFFFFFFFOOOOOZZZZZZZUUUUUUQUUQJJJJLLLLLLLLCCCCPPPPPPPPQQQQQQQUTTTTTEEEEEAAAAAAOOOOOOOOEEYSXPBZZZZPPPPPPPP",
		"DDMDDDDDDDNNNNNNNNNNNNNNWKKKKFFFFFFFFFFFFFFFOOOOZZZZZUUUUUUUUUUUQQQJJLLLLLLLLLCCCCPPPPPPPQQPQPGGGTGTTTEEEEEAAAXAAAOOOOOBOEYYPPPPPPPPPPPPPPPP",
		"DWDDDDDDDDNNNNNNNNNNNNNFUUUQQFFFFFFFFFFFFFFFOOFZZZKKKKKKKUUUUUUUQQQQQCLLLLLLCCCCCPPPPPPPPPPPMGGGGGGGTTGJJJJAAAAAAAAAAGOOOEYYYXPPPPPPPPPPPPPP",
		"WWDDDDDDDNNNNNNINNNNNNNNUULDQFFFFFFFFFFFFFFFONZZZZKKKKKKKUUUUUUUQQQCQCLCCLCCCCCCCCPPPPPPPPJPMGGGGGGGGGGGGJJJJJAAAAAAAAAZYYYYYYPPPPPPPPEPPPPP",
		"WWDDDDDDDNNNINIIINNNNNNNUULDDEFFFFFFFFFFFFFFFFOOOONNNKKKKUUUUUUUQQQCCCCCCCCCCCCCCPPPPPPPPPJPMMMGGGGGGGGGGJJJJAAAAAAAAAYZYYYYYPPPPPPPPPEEPPPP",
		"WYYDDDDDUIIIIIIIIINNNNNUUUDDDFFFDFFFFFFFFFFCFOOONNNNKKKUUUUUUUUUQQQCCCCCCCCCCCCCCCPPPPPPPPPPMMMMMMGGGGGGGJJJAAAAAAAAAAYYYYYYYYYPPPPPPEEEPPPP",
		"YYYUUDDUUIIIIIIIIINNNNUUUDDDDDDDDFFFFFFFFNNNNMMMMMMMMMKUUUUUUUUQQQQQQCCCCCCCCCCCCPPPPPPPPPPPMMMMMMMGGGGXJJJAAAAAAAAAAAYYYYYYYYYYMMPPEEEEEPPP",
		"YYUUUUUUUIIIIIIIIIIUNNUUDDDDDDDDFFFFFFFFNNNNNMMMMMMMMMKKKUUUBUQQQQQQQQCCCCCCCCCCCPPPPPPPPPPPMMMMMMMGGGNXMMJJAMAAAAAAAAAYYYYYYYYYYYPPEIEEEPPP",
		"YYYUUUUUUUIIIIIIIIIUUUUUDDDDDDDDFFFFFFFFNNNNNMMMMMMMMMMKKWKUBUUQQQQQQQQCCCCCCHHCCPPPPPPPPMMMMMMMMMMMXXXXMMMMMMAAAAAADAAYYYYYYYYYYYPYEEEEEPPP",
		"YYUUUUUUIIIIIIIGUUUUUUUUUUDDFFFFFFFFFFFNNNNNNMMMMMMMMMMKKKKXKKKKQQQQQQQCCCCCHHHCCPPPPPPPNNMMMMMMMMXXXXXXMMMMMMAAAAAAAAYYYYYYYYYYYYYYYYEEEEPP",
		"YYYYUUUIIIIIIIIIIIUUUUUUUUUUUFFFFFFFFFNNNNNNNMMMMMMMMMMKKKKKKKQQQQQQQQQCCCHHHHHHHPPNNPNNNNMMMMMMMXXXXXXXXMMMMMMMAAGDDAAYYYYYYYYYYYYYYYEEEEPP",
		"UYUYYUUIIIIIIIUUIUUUUUUUUUUUUUUUFFFFFFNNNNTTTMMMMMMMMMMKKKKKKKLQQQQQQQQCCHHHHHHHHNNNNNNNNNMMMMMMMXXXXXXXXMMMMMMMMAMDDDDDDYYYYYYYYYYYYEEEEEEE",
		"UYUUUUIIIIIIIIIUUUUUUUUUUUUUUUUUFFFFFFNTTTTTTMMMMMMMMMMKKKKKKKQQQQQGGGQQHHHHHHHHHNNNNNNNNNMMMMMMMXXXXXXXXXMMMMMMMMMDDDDDDDYYYYYYYYYYYEEEEBEA",
		"UYUUUUUIIIIIIIIUUUUUUUUUUUIUPIUUFFFFNNNTTTTTTMMMMMMMMMMKKKKKWWQQQQQQQGQQTTHHHHHHHNNNNNNNNMMMMMMMXXXXXXXXXXXMMMMMDDDDDDDDJDYYYYYYYYYYYYEEEEEA",
		"UUUUUUUIIIIIIIUUUUUUUUUUUUIIIIFFFFFFFNNTTTTTTTNNNMMMMMMKKKKKKWQQQQQQQQTTTTHHHHHHHHNNNNNNNMRRRMMMMXXXXXXXXXXMMMMMMMDDDDDDDDDDDYYYYYYYYGEEAAEA",
		"UUUUPUUIIIIIIIIIUUUUIIIUIIIIIIIFFFFFFNBBNNTTTTNNNMMMMMMKKKKWWWWQQQQQQQQTTHHHHHHHHHHNNNNNNRRRRRMMMMMXXXXXXXMMMMMMMMMDDDDDDDDCYYXYYYYNYGEGGAAA",
		"UPPUPUPIIDIIIIIIUUUUIIIIIIIITTIFNNFJJJBBBNTTTTNUUMMMMMKKKKKWWWWQQQQQQQQTTTHHHHHHHHHNNNNNNRRRRRRRSSSSSXXXXXMMMMMMMMMDDDDDDDZNNYXNYYNNNGGGGGGG",
		"PPPUPPPPPIIIIUUUUUUIIIIIIIIIITTNNNNJJAEBBNTTTTUUKKKKKKKKKKWWWWQQRQTQQQTTTHHHHHHHHHHNNNNNCRRRRRRRRLSSSXXXOXMMMMMMMMMMDDVVDDZNNNNNNYNNNGGGGGGI",
		"PPPPPPPPPPIUUUUUUUUIIIIIIIIINTNNNNREEEENNNNWNUUUUUKKKKKKKKWWWQQRRTTTQQTTTTHHHHHHAAHNNNNNRRRRRRRSSSSSSSXXOOMOOMMMMMMMDDRVVZZZZNNNNNNNRGGGGGGG",
		"PPPPPPPPPPPPUUUUUUIIIIIIIIIINTTNNNRRREEEEJNNBUUUUUKKKKKKEERRRRRRRTBTTTTTTTTHHAAHAAHNNNNDRRRRRRRSSSSSSSOOOOOOOOMMMMMMMMVVVZZZNNNNNNNNNNGGGGGG",
		"EEPPPPPPPUUUUUUUIIIIIIIIIINNNNNNNNRRREEYYEINBBBUBBKKKKKKEERRRRRRTTTTTTTTTTHHHHAAAAHNNNNDBRRRRRSSSSSSSSSSOOOOOMMMMMMMMVVVVZNNNNNNNNNNNGGGGGGG",
		"EGGGGGGPPPUUUUUUUIIIIIIIIINNNNNNNNNRRREEEEIIIBBBBBCKKEEEERRRRRRRTTTJTTTTTTHHTHAAAAANNNDDDDJRRSSSSSSSMMMMOOOOOMMMMMMMVVVVVNNNNNNNNNNNNNGGGGGG",
		"EGGGGGGGGPPUUUUUUIIIIIIIINNNNNNNNNNEEEEEEEIIBBBBBBBEEEEEEERRRRTTTTTJTTTTTTTTTHAEAANNNNDSSSSRRSSSSSSSSMGMMMGGMMMMMMMMVVVVVNNNNNNNNNNNNGGGGGGG",
		"EGGGGGGGDPPUUUUUUIIIIIIINNNNNNNNNNNNEEEEEEBBBBBBBBBEEEEEEEEERTTTTTTTTTTTTTTTTEEEEEEUUUUUSSSRSSSSSSSSSGGGGGGGMMMMMVVVVVVVVNNNNNNNNNNNNGGGGGGG",
		"EGGGGGGGGPPUUUUUUIIIIIIINNNNNNNNNNNNNEEEEGGBBBBBBBBBBEEEEEEEETTTTTTTTTTTTTTTTTEEEEEEUUUUSSSSSSSSSSSGGGGGGGGGGMMMMVVMMVVVMMNNNNNNNNNNNNNGGGGG",
		"EEGGGGGGGGPUOUUUUFFIIIINNNNNNNNNNNNNEEEEEEBBBBBBBBBBBBBBEEEEETTTTTTTTTTTTTTTTTTEEEEUUUUFFSSSSKKSSSGGGGGGGGGGMMMMMMMMMVVVMMNNNNNNNNNNNNNGGGGG",
		"GGGGGGGGGGGGOUUUFFFIIIIINNNNNNNNNNNNEEEEEBBBBBBBBBBBBBBBEEEEEEEETTTTTTTTTTTTTTTTEUUUUUUFFSSKKKKSSSSGGGGGGGGGGMMMMMMMMVVVMMMNNNNNNNNNGGGGGGGG",
		"GGGGGGGGGGOGOOUOOFIIIIFFNNNNNNNNNNNEEEEEEEEEBBBBBBBBBBBBEEEEEEEETTTTTTTTTTTTTTTTEUUUUUUFFFKKKKKKSSSSSGGGGGGGGGMMMMMMMMMMMMNNNNNNNNNNSGGGGFGG",
		"VGGGGGGGGGOOOOOOOFFFFFFFNNNNNNNNNNNNNEEEEEEEEBBBBBBBBBBBEEEEEEEEEETTTTTTTTTTTTTEEEUUUUUFXXKKKKKKKSSSSGGGNGGGJGMMMMMMMMMMMMNNNNNNNJNNSSGFFFGG"
	};

};

} //namespace day12
