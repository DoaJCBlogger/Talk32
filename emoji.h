//107,520 bytes to store everything with 8 32-bit numbers
//33,748 bytes to use 32-bit numbers to store only the numbers that are used in each character
//25,311 bytes to use 24-bit numbers to store only the numbers that are used in each character

#define EMOJI_COUNT 3360
#define MIN_EMOJI 0x23
#define MAX_EMOJI 0x1fad6

unsigned int emoji0[] = {0x23,0x20e3};
unsigned int emoji1[] = {0x2a,0x20e3};
unsigned int emoji2[] = {0x30,0x20e3};
unsigned int emoji3[] = {0x31,0x20e3};
unsigned int emoji4[] = {0x32,0x20e3};
unsigned int emoji5[] = {0x33,0x20e3};
unsigned int emoji6[] = {0x34,0x20e3};
unsigned int emoji7[] = {0x35,0x20e3};
unsigned int emoji8[] = {0x36,0x20e3};
unsigned int emoji9[] = {0x37,0x20e3};
unsigned int emoji10[] = {0x38,0x20e3};
unsigned int emoji11[] = {0x39,0x20e3};
unsigned int emoji12[] = {0xa9};
unsigned int emoji13[] = {0xae};
unsigned int emoji14[] = {0x203c};
unsigned int emoji15[] = {0x2049};
unsigned int emoji16[] = {0x2122};
unsigned int emoji17[] = {0x2139};
unsigned int emoji18[] = {0x2194};
unsigned int emoji19[] = {0x2195};
unsigned int emoji20[] = {0x2196};
unsigned int emoji21[] = {0x2197};
unsigned int emoji22[] = {0x2198};
unsigned int emoji23[] = {0x2199};
unsigned int emoji24[] = {0x21a9};
unsigned int emoji25[] = {0x21aa};
unsigned int emoji26[] = {0x231a};
unsigned int emoji27[] = {0x231b};
unsigned int emoji28[] = {0x2328};
unsigned int emoji29[] = {0x23cf};
unsigned int emoji30[] = {0x23e9};
unsigned int emoji31[] = {0x23ea};
unsigned int emoji32[] = {0x23eb};
unsigned int emoji33[] = {0x23ec};
unsigned int emoji34[] = {0x23ed};
unsigned int emoji35[] = {0x23ee};
unsigned int emoji36[] = {0x23ef};
unsigned int emoji37[] = {0x23f0};
unsigned int emoji38[] = {0x23f1};
unsigned int emoji39[] = {0x23f2};
unsigned int emoji40[] = {0x23f3};
unsigned int emoji41[] = {0x23f8};
unsigned int emoji42[] = {0x23f9};
unsigned int emoji43[] = {0x23fa};
unsigned int emoji44[] = {0x24c2};
unsigned int emoji45[] = {0x25aa};
unsigned int emoji46[] = {0x25ab};
unsigned int emoji47[] = {0x25b6};
unsigned int emoji48[] = {0x25c0};
unsigned int emoji49[] = {0x25fb};
unsigned int emoji50[] = {0x25fc};
unsigned int emoji51[] = {0x25fd};
unsigned int emoji52[] = {0x25fe};
unsigned int emoji53[] = {0x2600};
unsigned int emoji54[] = {0x2601};
unsigned int emoji55[] = {0x2602};
unsigned int emoji56[] = {0x2603};
unsigned int emoji57[] = {0x2604};
unsigned int emoji58[] = {0x260e};
unsigned int emoji59[] = {0x2611};
unsigned int emoji60[] = {0x2614};
unsigned int emoji61[] = {0x2615};
unsigned int emoji62[] = {0x2618};
unsigned int emoji63[] = {0x261d};
unsigned int emoji64[] = {0x261d,0x1f3fb};
unsigned int emoji65[] = {0x261d,0x1f3fc};
unsigned int emoji66[] = {0x261d,0x1f3fd};
unsigned int emoji67[] = {0x261d,0x1f3fe};
unsigned int emoji68[] = {0x261d,0x1f3ff};
unsigned int emoji69[] = {0x2620};
unsigned int emoji70[] = {0x2622};
unsigned int emoji71[] = {0x2623};
unsigned int emoji72[] = {0x2626};
unsigned int emoji73[] = {0x262a};
unsigned int emoji74[] = {0x262e};
unsigned int emoji75[] = {0x262f};
unsigned int emoji76[] = {0x2638};
unsigned int emoji77[] = {0x2639};
unsigned int emoji78[] = {0x263a};
unsigned int emoji79[] = {0x2640};
unsigned int emoji80[] = {0x2642};
unsigned int emoji81[] = {0x2648};
unsigned int emoji82[] = {0x2649};
unsigned int emoji83[] = {0x264a};
unsigned int emoji84[] = {0x264b};
unsigned int emoji85[] = {0x264c};
unsigned int emoji86[] = {0x264d};
unsigned int emoji87[] = {0x264e};
unsigned int emoji88[] = {0x264f};
unsigned int emoji89[] = {0x2650};
unsigned int emoji90[] = {0x2651};
unsigned int emoji91[] = {0x2652};
unsigned int emoji92[] = {0x2653};
unsigned int emoji93[] = {0x265f};
unsigned int emoji94[] = {0x2660};
unsigned int emoji95[] = {0x2663};
unsigned int emoji96[] = {0x2665};
unsigned int emoji97[] = {0x2666};
unsigned int emoji98[] = {0x2668};
unsigned int emoji99[] = {0x267b};
unsigned int emoji100[] = {0x267e};
unsigned int emoji101[] = {0x267f};
unsigned int emoji102[] = {0x2692};
unsigned int emoji103[] = {0x2693};
unsigned int emoji104[] = {0x2694};
unsigned int emoji105[] = {0x2695};
unsigned int emoji106[] = {0x2696};
unsigned int emoji107[] = {0x2697};
unsigned int emoji108[] = {0x2699};
unsigned int emoji109[] = {0x269b};
unsigned int emoji110[] = {0x269c};
unsigned int emoji111[] = {0x26a0};
unsigned int emoji112[] = {0x26a1};
unsigned int emoji113[] = {0x26a7};
unsigned int emoji114[] = {0x26aa};
unsigned int emoji115[] = {0x26ab};
unsigned int emoji116[] = {0x26b0};
unsigned int emoji117[] = {0x26b1};
unsigned int emoji118[] = {0x26bd};
unsigned int emoji119[] = {0x26be};
unsigned int emoji120[] = {0x26c4};
unsigned int emoji121[] = {0x26c5};
unsigned int emoji122[] = {0x26c8};
unsigned int emoji123[] = {0x26ce};
unsigned int emoji124[] = {0x26cf};
unsigned int emoji125[] = {0x26d1};
unsigned int emoji126[] = {0x26d3};
unsigned int emoji127[] = {0x26d4};
unsigned int emoji128[] = {0x26e9};
unsigned int emoji129[] = {0x26ea};
unsigned int emoji130[] = {0x26f0};
unsigned int emoji131[] = {0x26f1};
unsigned int emoji132[] = {0x26f2};
unsigned int emoji133[] = {0x26f3};
unsigned int emoji134[] = {0x26f4};
unsigned int emoji135[] = {0x26f5};
unsigned int emoji136[] = {0x26f7};
unsigned int emoji137[] = {0x26f7,0x1f3fb};
unsigned int emoji138[] = {0x26f7,0x1f3fc};
unsigned int emoji139[] = {0x26f7,0x1f3fd};
unsigned int emoji140[] = {0x26f7,0x1f3fe};
unsigned int emoji141[] = {0x26f7,0x1f3ff};
unsigned int emoji142[] = {0x26f8};
unsigned int emoji143[] = {0x26f9};
unsigned int emoji144[] = {0x26f9,0x1f3fb};
unsigned int emoji145[] = {0x26f9,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji146[] = {0x26f9,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji147[] = {0x26f9,0x1f3fc};
unsigned int emoji148[] = {0x26f9,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji149[] = {0x26f9,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji150[] = {0x26f9,0x1f3fd};
unsigned int emoji151[] = {0x26f9,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji152[] = {0x26f9,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji153[] = {0x26f9,0x1f3fe};
unsigned int emoji154[] = {0x26f9,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji155[] = {0x26f9,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji156[] = {0x26f9,0x1f3ff};
unsigned int emoji157[] = {0x26f9,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji158[] = {0x26f9,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji159[] = {0x26f9,0xfe0f,0x200d,0x2640,0xfe0f};
unsigned int emoji160[] = {0x26f9,0xfe0f,0x200d,0x2642,0xfe0f};
unsigned int emoji161[] = {0x26fa};
unsigned int emoji162[] = {0x26fd};
unsigned int emoji163[] = {0x2702};
unsigned int emoji164[] = {0x2705};
unsigned int emoji165[] = {0x2708};
unsigned int emoji166[] = {0x2709};
unsigned int emoji167[] = {0x270a};
unsigned int emoji168[] = {0x270a,0x1f3fb};
unsigned int emoji169[] = {0x270a,0x1f3fc};
unsigned int emoji170[] = {0x270a,0x1f3fd};
unsigned int emoji171[] = {0x270a,0x1f3fe};
unsigned int emoji172[] = {0x270a,0x1f3ff};
unsigned int emoji173[] = {0x270b};
unsigned int emoji174[] = {0x270b,0x1f3fb};
unsigned int emoji175[] = {0x270b,0x1f3fc};
unsigned int emoji176[] = {0x270b,0x1f3fd};
unsigned int emoji177[] = {0x270b,0x1f3fe};
unsigned int emoji178[] = {0x270b,0x1f3ff};
unsigned int emoji179[] = {0x270c};
unsigned int emoji180[] = {0x270c,0x1f3fb};
unsigned int emoji181[] = {0x270c,0x1f3fc};
unsigned int emoji182[] = {0x270c,0x1f3fd};
unsigned int emoji183[] = {0x270c,0x1f3fe};
unsigned int emoji184[] = {0x270c,0x1f3ff};
unsigned int emoji185[] = {0x270d};
unsigned int emoji186[] = {0x270d,0x1f3fb};
unsigned int emoji187[] = {0x270d,0x1f3fc};
unsigned int emoji188[] = {0x270d,0x1f3fd};
unsigned int emoji189[] = {0x270d,0x1f3fe};
unsigned int emoji190[] = {0x270d,0x1f3ff};
unsigned int emoji191[] = {0x270f};
unsigned int emoji192[] = {0x2712};
unsigned int emoji193[] = {0x2714};
unsigned int emoji194[] = {0x2716};
unsigned int emoji195[] = {0x271d};
unsigned int emoji196[] = {0x2721};
unsigned int emoji197[] = {0x2728};
unsigned int emoji198[] = {0x2733};
unsigned int emoji199[] = {0x2734};
unsigned int emoji200[] = {0x2744};
unsigned int emoji201[] = {0x2747};
unsigned int emoji202[] = {0x274c};
unsigned int emoji203[] = {0x274e};
unsigned int emoji204[] = {0x2753};
unsigned int emoji205[] = {0x2754};
unsigned int emoji206[] = {0x2755};
unsigned int emoji207[] = {0x2757};
unsigned int emoji208[] = {0x2763};
unsigned int emoji209[] = {0x2764};
unsigned int emoji210[] = {0x2795};
unsigned int emoji211[] = {0x2796};
unsigned int emoji212[] = {0x2797};
unsigned int emoji213[] = {0x27a1};
unsigned int emoji214[] = {0x27b0};
unsigned int emoji215[] = {0x27bf};
unsigned int emoji216[] = {0x2934};
unsigned int emoji217[] = {0x2935};
unsigned int emoji218[] = {0x2b05};
unsigned int emoji219[] = {0x2b06};
unsigned int emoji220[] = {0x2b07};
unsigned int emoji221[] = {0x2b1b};
unsigned int emoji222[] = {0x2b1c};
unsigned int emoji223[] = {0x2b50};
unsigned int emoji224[] = {0x2b55};
unsigned int emoji225[] = {0x3030};
unsigned int emoji226[] = {0x303d};
unsigned int emoji227[] = {0x3297};
unsigned int emoji228[] = {0x3299};
unsigned int emoji229[] = {0xe50a};
unsigned int emoji230[] = {0x1f004};
unsigned int emoji231[] = {0x1f0cf};
unsigned int emoji232[] = {0x1f170};
unsigned int emoji233[] = {0x1f171};
unsigned int emoji234[] = {0x1f17e};
unsigned int emoji235[] = {0x1f17f};
unsigned int emoji236[] = {0x1f18e};
unsigned int emoji237[] = {0x1f191};
unsigned int emoji238[] = {0x1f192};
unsigned int emoji239[] = {0x1f193};
unsigned int emoji240[] = {0x1f194};
unsigned int emoji241[] = {0x1f195};
unsigned int emoji242[] = {0x1f196};
unsigned int emoji243[] = {0x1f197};
unsigned int emoji244[] = {0x1f198};
unsigned int emoji245[] = {0x1f199};
unsigned int emoji246[] = {0x1f19a};
unsigned int emoji247[] = {0x1f1e6};
unsigned int emoji248[] = {0x1f1e6,0x1f1e8};
unsigned int emoji249[] = {0x1f1e6,0x1f1e9};
unsigned int emoji250[] = {0x1f1e6,0x1f1ea};
unsigned int emoji251[] = {0x1f1e6,0x1f1eb};
unsigned int emoji252[] = {0x1f1e6,0x1f1ec};
unsigned int emoji253[] = {0x1f1e6,0x1f1ee};
unsigned int emoji254[] = {0x1f1e6,0x1f1f1};
unsigned int emoji255[] = {0x1f1e6,0x1f1f2};
unsigned int emoji256[] = {0x1f1e6,0x1f1f4};
unsigned int emoji257[] = {0x1f1e6,0x1f1f6};
unsigned int emoji258[] = {0x1f1e6,0x1f1f7};
unsigned int emoji259[] = {0x1f1e6,0x1f1f8};
unsigned int emoji260[] = {0x1f1e6,0x1f1f9};
unsigned int emoji261[] = {0x1f1e6,0x1f1fa};
unsigned int emoji262[] = {0x1f1e6,0x1f1fc};
unsigned int emoji263[] = {0x1f1e6,0x1f1fd};
unsigned int emoji264[] = {0x1f1e6,0x1f1ff};
unsigned int emoji265[] = {0x1f1e7};
unsigned int emoji266[] = {0x1f1e7,0x1f1e6};
unsigned int emoji267[] = {0x1f1e7,0x1f1e7};
unsigned int emoji268[] = {0x1f1e7,0x1f1e9};
unsigned int emoji269[] = {0x1f1e7,0x1f1ea};
unsigned int emoji270[] = {0x1f1e7,0x1f1eb};
unsigned int emoji271[] = {0x1f1e7,0x1f1ec};
unsigned int emoji272[] = {0x1f1e7,0x1f1ed};
unsigned int emoji273[] = {0x1f1e7,0x1f1ee};
unsigned int emoji274[] = {0x1f1e7,0x1f1ef};
unsigned int emoji275[] = {0x1f1e7,0x1f1f1};
unsigned int emoji276[] = {0x1f1e7,0x1f1f2};
unsigned int emoji277[] = {0x1f1e7,0x1f1f3};
unsigned int emoji278[] = {0x1f1e7,0x1f1f4};
unsigned int emoji279[] = {0x1f1e7,0x1f1f6};
unsigned int emoji280[] = {0x1f1e7,0x1f1f7};
unsigned int emoji281[] = {0x1f1e7,0x1f1f8};
unsigned int emoji282[] = {0x1f1e7,0x1f1f9};
unsigned int emoji283[] = {0x1f1e7,0x1f1fb};
unsigned int emoji284[] = {0x1f1e7,0x1f1fc};
unsigned int emoji285[] = {0x1f1e7,0x1f1fe};
unsigned int emoji286[] = {0x1f1e7,0x1f1ff};
unsigned int emoji287[] = {0x1f1e8};
unsigned int emoji288[] = {0x1f1e8,0x1f1e6};
unsigned int emoji289[] = {0x1f1e8,0x1f1e8};
unsigned int emoji290[] = {0x1f1e8,0x1f1e9};
unsigned int emoji291[] = {0x1f1e8,0x1f1eb};
unsigned int emoji292[] = {0x1f1e8,0x1f1ec};
unsigned int emoji293[] = {0x1f1e8,0x1f1ed};
unsigned int emoji294[] = {0x1f1e8,0x1f1ee};
unsigned int emoji295[] = {0x1f1e8,0x1f1f0};
unsigned int emoji296[] = {0x1f1e8,0x1f1f1};
unsigned int emoji297[] = {0x1f1e8,0x1f1f2};
unsigned int emoji298[] = {0x1f1e8,0x1f1f3};
unsigned int emoji299[] = {0x1f1e8,0x1f1f4};
unsigned int emoji300[] = {0x1f1e8,0x1f1f5};
unsigned int emoji301[] = {0x1f1e8,0x1f1f7};
unsigned int emoji302[] = {0x1f1e8,0x1f1fa};
unsigned int emoji303[] = {0x1f1e8,0x1f1fb};
unsigned int emoji304[] = {0x1f1e8,0x1f1fc};
unsigned int emoji305[] = {0x1f1e8,0x1f1fd};
unsigned int emoji306[] = {0x1f1e8,0x1f1fe};
unsigned int emoji307[] = {0x1f1e8,0x1f1ff};
unsigned int emoji308[] = {0x1f1e9};
unsigned int emoji309[] = {0x1f1e9,0x1f1ea};
unsigned int emoji310[] = {0x1f1e9,0x1f1ec};
unsigned int emoji311[] = {0x1f1e9,0x1f1ef};
unsigned int emoji312[] = {0x1f1e9,0x1f1f0};
unsigned int emoji313[] = {0x1f1e9,0x1f1f2};
unsigned int emoji314[] = {0x1f1e9,0x1f1f4};
unsigned int emoji315[] = {0x1f1e9,0x1f1ff};
unsigned int emoji316[] = {0x1f1ea};
unsigned int emoji317[] = {0x1f1ea,0x1f1e6};
unsigned int emoji318[] = {0x1f1ea,0x1f1e8};
unsigned int emoji319[] = {0x1f1ea,0x1f1ea};
unsigned int emoji320[] = {0x1f1ea,0x1f1ec};
unsigned int emoji321[] = {0x1f1ea,0x1f1ed};
unsigned int emoji322[] = {0x1f1ea,0x1f1f7};
unsigned int emoji323[] = {0x1f1ea,0x1f1f8};
unsigned int emoji324[] = {0x1f1ea,0x1f1f9};
unsigned int emoji325[] = {0x1f1ea,0x1f1fa};
unsigned int emoji326[] = {0x1f1eb};
unsigned int emoji327[] = {0x1f1eb,0x1f1ee};
unsigned int emoji328[] = {0x1f1eb,0x1f1ef};
unsigned int emoji329[] = {0x1f1eb,0x1f1f0};
unsigned int emoji330[] = {0x1f1eb,0x1f1f2};
unsigned int emoji331[] = {0x1f1eb,0x1f1f4};
unsigned int emoji332[] = {0x1f1eb,0x1f1f7};
unsigned int emoji333[] = {0x1f1ec};
unsigned int emoji334[] = {0x1f1ec,0x1f1e6};
unsigned int emoji335[] = {0x1f1ec,0x1f1e7};
unsigned int emoji336[] = {0x1f1ec,0x1f1e9};
unsigned int emoji337[] = {0x1f1ec,0x1f1ea};
unsigned int emoji338[] = {0x1f1ec,0x1f1eb};
unsigned int emoji339[] = {0x1f1ec,0x1f1ec};
unsigned int emoji340[] = {0x1f1ec,0x1f1ed};
unsigned int emoji341[] = {0x1f1ec,0x1f1ee};
unsigned int emoji342[] = {0x1f1ec,0x1f1f1};
unsigned int emoji343[] = {0x1f1ec,0x1f1f2};
unsigned int emoji344[] = {0x1f1ec,0x1f1f3};
unsigned int emoji345[] = {0x1f1ec,0x1f1f5};
unsigned int emoji346[] = {0x1f1ec,0x1f1f6};
unsigned int emoji347[] = {0x1f1ec,0x1f1f7};
unsigned int emoji348[] = {0x1f1ec,0x1f1f8};
unsigned int emoji349[] = {0x1f1ec,0x1f1f9};
unsigned int emoji350[] = {0x1f1ec,0x1f1fa};
unsigned int emoji351[] = {0x1f1ec,0x1f1fc};
unsigned int emoji352[] = {0x1f1ec,0x1f1fe};
unsigned int emoji353[] = {0x1f1ed};
unsigned int emoji354[] = {0x1f1ed,0x1f1f0};
unsigned int emoji355[] = {0x1f1ed,0x1f1f2};
unsigned int emoji356[] = {0x1f1ed,0x1f1f3};
unsigned int emoji357[] = {0x1f1ed,0x1f1f7};
unsigned int emoji358[] = {0x1f1ed,0x1f1f9};
unsigned int emoji359[] = {0x1f1ed,0x1f1fa};
unsigned int emoji360[] = {0x1f1ee};
unsigned int emoji361[] = {0x1f1ee,0x1f1e8};
unsigned int emoji362[] = {0x1f1ee,0x1f1e9};
unsigned int emoji363[] = {0x1f1ee,0x1f1ea};
unsigned int emoji364[] = {0x1f1ee,0x1f1f1};
unsigned int emoji365[] = {0x1f1ee,0x1f1f2};
unsigned int emoji366[] = {0x1f1ee,0x1f1f3};
unsigned int emoji367[] = {0x1f1ee,0x1f1f4};
unsigned int emoji368[] = {0x1f1ee,0x1f1f6};
unsigned int emoji369[] = {0x1f1ee,0x1f1f7};
unsigned int emoji370[] = {0x1f1ee,0x1f1f8};
unsigned int emoji371[] = {0x1f1ee,0x1f1f9};
unsigned int emoji372[] = {0x1f1ef};
unsigned int emoji373[] = {0x1f1ef,0x1f1ea};
unsigned int emoji374[] = {0x1f1ef,0x1f1f2};
unsigned int emoji375[] = {0x1f1ef,0x1f1f4};
unsigned int emoji376[] = {0x1f1ef,0x1f1f5};
unsigned int emoji377[] = {0x1f1f0};
unsigned int emoji378[] = {0x1f1f0,0x1f1ea};
unsigned int emoji379[] = {0x1f1f0,0x1f1ec};
unsigned int emoji380[] = {0x1f1f0,0x1f1ed};
unsigned int emoji381[] = {0x1f1f0,0x1f1ee};
unsigned int emoji382[] = {0x1f1f0,0x1f1f2};
unsigned int emoji383[] = {0x1f1f0,0x1f1f3};
unsigned int emoji384[] = {0x1f1f0,0x1f1f5};
unsigned int emoji385[] = {0x1f1f0,0x1f1f7};
unsigned int emoji386[] = {0x1f1f0,0x1f1fc};
unsigned int emoji387[] = {0x1f1f0,0x1f1fe};
unsigned int emoji388[] = {0x1f1f0,0x1f1ff};
unsigned int emoji389[] = {0x1f1f1};
unsigned int emoji390[] = {0x1f1f1,0x1f1e6};
unsigned int emoji391[] = {0x1f1f1,0x1f1e7};
unsigned int emoji392[] = {0x1f1f1,0x1f1e8};
unsigned int emoji393[] = {0x1f1f1,0x1f1ee};
unsigned int emoji394[] = {0x1f1f1,0x1f1f0};
unsigned int emoji395[] = {0x1f1f1,0x1f1f7};
unsigned int emoji396[] = {0x1f1f1,0x1f1f8};
unsigned int emoji397[] = {0x1f1f1,0x1f1f9};
unsigned int emoji398[] = {0x1f1f1,0x1f1fa};
unsigned int emoji399[] = {0x1f1f1,0x1f1fb};
unsigned int emoji400[] = {0x1f1f1,0x1f1fe};
unsigned int emoji401[] = {0x1f1f2};
unsigned int emoji402[] = {0x1f1f2,0x1f1e6};
unsigned int emoji403[] = {0x1f1f2,0x1f1e8};
unsigned int emoji404[] = {0x1f1f2,0x1f1e9};
unsigned int emoji405[] = {0x1f1f2,0x1f1ea};
unsigned int emoji406[] = {0x1f1f2,0x1f1eb};
unsigned int emoji407[] = {0x1f1f2,0x1f1ec};
unsigned int emoji408[] = {0x1f1f2,0x1f1ed};
unsigned int emoji409[] = {0x1f1f2,0x1f1f0};
unsigned int emoji410[] = {0x1f1f2,0x1f1f1};
unsigned int emoji411[] = {0x1f1f2,0x1f1f2};
unsigned int emoji412[] = {0x1f1f2,0x1f1f3};
unsigned int emoji413[] = {0x1f1f2,0x1f1f4};
unsigned int emoji414[] = {0x1f1f2,0x1f1f5};
unsigned int emoji415[] = {0x1f1f2,0x1f1f6};
unsigned int emoji416[] = {0x1f1f2,0x1f1f7};
unsigned int emoji417[] = {0x1f1f2,0x1f1f8};
unsigned int emoji418[] = {0x1f1f2,0x1f1f9};
unsigned int emoji419[] = {0x1f1f2,0x1f1fa};
unsigned int emoji420[] = {0x1f1f2,0x1f1fb};
unsigned int emoji421[] = {0x1f1f2,0x1f1fc};
unsigned int emoji422[] = {0x1f1f2,0x1f1fd};
unsigned int emoji423[] = {0x1f1f2,0x1f1fe};
unsigned int emoji424[] = {0x1f1f2,0x1f1ff};
unsigned int emoji425[] = {0x1f1f3};
unsigned int emoji426[] = {0x1f1f3,0x1f1e6};
unsigned int emoji427[] = {0x1f1f3,0x1f1e8};
unsigned int emoji428[] = {0x1f1f3,0x1f1ea};
unsigned int emoji429[] = {0x1f1f3,0x1f1eb};
unsigned int emoji430[] = {0x1f1f3,0x1f1ec};
unsigned int emoji431[] = {0x1f1f3,0x1f1ee};
unsigned int emoji432[] = {0x1f1f3,0x1f1f1};
unsigned int emoji433[] = {0x1f1f3,0x1f1f4};
unsigned int emoji434[] = {0x1f1f3,0x1f1f5};
unsigned int emoji435[] = {0x1f1f3,0x1f1f7};
unsigned int emoji436[] = {0x1f1f3,0x1f1fa};
unsigned int emoji437[] = {0x1f1f3,0x1f1ff};
unsigned int emoji438[] = {0x1f1f4};
unsigned int emoji439[] = {0x1f1f4,0x1f1f2};
unsigned int emoji440[] = {0x1f1f5};
unsigned int emoji441[] = {0x1f1f5,0x1f1e6};
unsigned int emoji442[] = {0x1f1f5,0x1f1ea};
unsigned int emoji443[] = {0x1f1f5,0x1f1eb};
unsigned int emoji444[] = {0x1f1f5,0x1f1ec};
unsigned int emoji445[] = {0x1f1f5,0x1f1ed};
unsigned int emoji446[] = {0x1f1f5,0x1f1f0};
unsigned int emoji447[] = {0x1f1f5,0x1f1f1};
unsigned int emoji448[] = {0x1f1f5,0x1f1f2};
unsigned int emoji449[] = {0x1f1f5,0x1f1f3};
unsigned int emoji450[] = {0x1f1f5,0x1f1f7};
unsigned int emoji451[] = {0x1f1f5,0x1f1f8};
unsigned int emoji452[] = {0x1f1f5,0x1f1f9};
unsigned int emoji453[] = {0x1f1f5,0x1f1fc};
unsigned int emoji454[] = {0x1f1f5,0x1f1fe};
unsigned int emoji455[] = {0x1f1f6};
unsigned int emoji456[] = {0x1f1f6,0x1f1e6};
unsigned int emoji457[] = {0x1f1f7};
unsigned int emoji458[] = {0x1f1f7,0x1f1ea};
unsigned int emoji459[] = {0x1f1f7,0x1f1f4};
unsigned int emoji460[] = {0x1f1f7,0x1f1f8};
unsigned int emoji461[] = {0x1f1f7,0x1f1fa};
unsigned int emoji462[] = {0x1f1f7,0x1f1fc};
unsigned int emoji463[] = {0x1f1f8};
unsigned int emoji464[] = {0x1f1f8,0x1f1e6};
unsigned int emoji465[] = {0x1f1f8,0x1f1e7};
unsigned int emoji466[] = {0x1f1f8,0x1f1e8};
unsigned int emoji467[] = {0x1f1f8,0x1f1e9};
unsigned int emoji468[] = {0x1f1f8,0x1f1ea};
unsigned int emoji469[] = {0x1f1f8,0x1f1ec};
unsigned int emoji470[] = {0x1f1f8,0x1f1ed};
unsigned int emoji471[] = {0x1f1f8,0x1f1ee};
unsigned int emoji472[] = {0x1f1f8,0x1f1ef};
unsigned int emoji473[] = {0x1f1f8,0x1f1f0};
unsigned int emoji474[] = {0x1f1f8,0x1f1f1};
unsigned int emoji475[] = {0x1f1f8,0x1f1f2};
unsigned int emoji476[] = {0x1f1f8,0x1f1f3};
unsigned int emoji477[] = {0x1f1f8,0x1f1f4};
unsigned int emoji478[] = {0x1f1f8,0x1f1f7};
unsigned int emoji479[] = {0x1f1f8,0x1f1f8};
unsigned int emoji480[] = {0x1f1f8,0x1f1f9};
unsigned int emoji481[] = {0x1f1f8,0x1f1fb};
unsigned int emoji482[] = {0x1f1f8,0x1f1fd};
unsigned int emoji483[] = {0x1f1f8,0x1f1fe};
unsigned int emoji484[] = {0x1f1f8,0x1f1ff};
unsigned int emoji485[] = {0x1f1f9};
unsigned int emoji486[] = {0x1f1f9,0x1f1e6};
unsigned int emoji487[] = {0x1f1f9,0x1f1e8};
unsigned int emoji488[] = {0x1f1f9,0x1f1e9};
unsigned int emoji489[] = {0x1f1f9,0x1f1eb};
unsigned int emoji490[] = {0x1f1f9,0x1f1ec};
unsigned int emoji491[] = {0x1f1f9,0x1f1ed};
unsigned int emoji492[] = {0x1f1f9,0x1f1ef};
unsigned int emoji493[] = {0x1f1f9,0x1f1f0};
unsigned int emoji494[] = {0x1f1f9,0x1f1f1};
unsigned int emoji495[] = {0x1f1f9,0x1f1f2};
unsigned int emoji496[] = {0x1f1f9,0x1f1f3};
unsigned int emoji497[] = {0x1f1f9,0x1f1f4};
unsigned int emoji498[] = {0x1f1f9,0x1f1f7};
unsigned int emoji499[] = {0x1f1f9,0x1f1f9};
unsigned int emoji500[] = {0x1f1f9,0x1f1fb};
unsigned int emoji501[] = {0x1f1f9,0x1f1fc};
unsigned int emoji502[] = {0x1f1f9,0x1f1ff};
unsigned int emoji503[] = {0x1f1fa};
unsigned int emoji504[] = {0x1f1fa,0x1f1e6};
unsigned int emoji505[] = {0x1f1fa,0x1f1ec};
unsigned int emoji506[] = {0x1f1fa,0x1f1f2};
unsigned int emoji507[] = {0x1f1fa,0x1f1f3};
unsigned int emoji508[] = {0x1f1fa,0x1f1f8};
unsigned int emoji509[] = {0x1f1fa,0x1f1fe};
unsigned int emoji510[] = {0x1f1fa,0x1f1ff};
unsigned int emoji511[] = {0x1f1fb};
unsigned int emoji512[] = {0x1f1fb,0x1f1e6};
unsigned int emoji513[] = {0x1f1fb,0x1f1e8};
unsigned int emoji514[] = {0x1f1fb,0x1f1ea};
unsigned int emoji515[] = {0x1f1fb,0x1f1ec};
unsigned int emoji516[] = {0x1f1fb,0x1f1ee};
unsigned int emoji517[] = {0x1f1fb,0x1f1f3};
unsigned int emoji518[] = {0x1f1fb,0x1f1fa};
unsigned int emoji519[] = {0x1f1fc};
unsigned int emoji520[] = {0x1f1fc,0x1f1eb};
unsigned int emoji521[] = {0x1f1fc,0x1f1f8};
unsigned int emoji522[] = {0x1f1fd};
unsigned int emoji523[] = {0x1f1fd,0x1f1f0};
unsigned int emoji524[] = {0x1f1fe};
unsigned int emoji525[] = {0x1f1fe,0x1f1ea};
unsigned int emoji526[] = {0x1f1fe,0x1f1f9};
unsigned int emoji527[] = {0x1f1ff};
unsigned int emoji528[] = {0x1f1ff,0x1f1e6};
unsigned int emoji529[] = {0x1f1ff,0x1f1f2};
unsigned int emoji530[] = {0x1f1ff,0x1f1fc};
unsigned int emoji531[] = {0x1f201};
unsigned int emoji532[] = {0x1f202};
unsigned int emoji533[] = {0x1f21a};
unsigned int emoji534[] = {0x1f22f};
unsigned int emoji535[] = {0x1f232};
unsigned int emoji536[] = {0x1f233};
unsigned int emoji537[] = {0x1f234};
unsigned int emoji538[] = {0x1f235};
unsigned int emoji539[] = {0x1f236};
unsigned int emoji540[] = {0x1f237};
unsigned int emoji541[] = {0x1f238};
unsigned int emoji542[] = {0x1f239};
unsigned int emoji543[] = {0x1f23a};
unsigned int emoji544[] = {0x1f250};
unsigned int emoji545[] = {0x1f251};
unsigned int emoji546[] = {0x1f300};
unsigned int emoji547[] = {0x1f301};
unsigned int emoji548[] = {0x1f302};
unsigned int emoji549[] = {0x1f303};
unsigned int emoji550[] = {0x1f304};
unsigned int emoji551[] = {0x1f305};
unsigned int emoji552[] = {0x1f306};
unsigned int emoji553[] = {0x1f307};
unsigned int emoji554[] = {0x1f308};
unsigned int emoji555[] = {0x1f309};
unsigned int emoji556[] = {0x1f30a};
unsigned int emoji557[] = {0x1f30b};
unsigned int emoji558[] = {0x1f30c};
unsigned int emoji559[] = {0x1f30d};
unsigned int emoji560[] = {0x1f30e};
unsigned int emoji561[] = {0x1f30f};
unsigned int emoji562[] = {0x1f310};
unsigned int emoji563[] = {0x1f311};
unsigned int emoji564[] = {0x1f312};
unsigned int emoji565[] = {0x1f313};
unsigned int emoji566[] = {0x1f314};
unsigned int emoji567[] = {0x1f315};
unsigned int emoji568[] = {0x1f316};
unsigned int emoji569[] = {0x1f317};
unsigned int emoji570[] = {0x1f318};
unsigned int emoji571[] = {0x1f319};
unsigned int emoji572[] = {0x1f31a};
unsigned int emoji573[] = {0x1f31b};
unsigned int emoji574[] = {0x1f31c};
unsigned int emoji575[] = {0x1f31d};
unsigned int emoji576[] = {0x1f31e};
unsigned int emoji577[] = {0x1f31f};
unsigned int emoji578[] = {0x1f320};
unsigned int emoji579[] = {0x1f321};
unsigned int emoji580[] = {0x1f324};
unsigned int emoji581[] = {0x1f325};
unsigned int emoji582[] = {0x1f326};
unsigned int emoji583[] = {0x1f327};
unsigned int emoji584[] = {0x1f328};
unsigned int emoji585[] = {0x1f329};
unsigned int emoji586[] = {0x1f32a};
unsigned int emoji587[] = {0x1f32b};
unsigned int emoji588[] = {0x1f32c};
unsigned int emoji589[] = {0x1f32d};
unsigned int emoji590[] = {0x1f32e};
unsigned int emoji591[] = {0x1f32f};
unsigned int emoji592[] = {0x1f330};
unsigned int emoji593[] = {0x1f331};
unsigned int emoji594[] = {0x1f332};
unsigned int emoji595[] = {0x1f333};
unsigned int emoji596[] = {0x1f334};
unsigned int emoji597[] = {0x1f335};
unsigned int emoji598[] = {0x1f336};
unsigned int emoji599[] = {0x1f337};
unsigned int emoji600[] = {0x1f338};
unsigned int emoji601[] = {0x1f339};
unsigned int emoji602[] = {0x1f33a};
unsigned int emoji603[] = {0x1f33b};
unsigned int emoji604[] = {0x1f33c};
unsigned int emoji605[] = {0x1f33d};
unsigned int emoji606[] = {0x1f33e};
unsigned int emoji607[] = {0x1f33f};
unsigned int emoji608[] = {0x1f340};
unsigned int emoji609[] = {0x1f341};
unsigned int emoji610[] = {0x1f342};
unsigned int emoji611[] = {0x1f343};
unsigned int emoji612[] = {0x1f344};
unsigned int emoji613[] = {0x1f345};
unsigned int emoji614[] = {0x1f346};
unsigned int emoji615[] = {0x1f347};
unsigned int emoji616[] = {0x1f348};
unsigned int emoji617[] = {0x1f349};
unsigned int emoji618[] = {0x1f34a};
unsigned int emoji619[] = {0x1f34b};
unsigned int emoji620[] = {0x1f34c};
unsigned int emoji621[] = {0x1f34d};
unsigned int emoji622[] = {0x1f34e};
unsigned int emoji623[] = {0x1f34f};
unsigned int emoji624[] = {0x1f350};
unsigned int emoji625[] = {0x1f351};
unsigned int emoji626[] = {0x1f352};
unsigned int emoji627[] = {0x1f353};
unsigned int emoji628[] = {0x1f354};
unsigned int emoji629[] = {0x1f355};
unsigned int emoji630[] = {0x1f356};
unsigned int emoji631[] = {0x1f357};
unsigned int emoji632[] = {0x1f358};
unsigned int emoji633[] = {0x1f359};
unsigned int emoji634[] = {0x1f35a};
unsigned int emoji635[] = {0x1f35b};
unsigned int emoji636[] = {0x1f35c};
unsigned int emoji637[] = {0x1f35d};
unsigned int emoji638[] = {0x1f35e};
unsigned int emoji639[] = {0x1f35f};
unsigned int emoji640[] = {0x1f360};
unsigned int emoji641[] = {0x1f361};
unsigned int emoji642[] = {0x1f362};
unsigned int emoji643[] = {0x1f363};
unsigned int emoji644[] = {0x1f364};
unsigned int emoji645[] = {0x1f365};
unsigned int emoji646[] = {0x1f366};
unsigned int emoji647[] = {0x1f367};
unsigned int emoji648[] = {0x1f368};
unsigned int emoji649[] = {0x1f369};
unsigned int emoji650[] = {0x1f36a};
unsigned int emoji651[] = {0x1f36b};
unsigned int emoji652[] = {0x1f36c};
unsigned int emoji653[] = {0x1f36d};
unsigned int emoji654[] = {0x1f36e};
unsigned int emoji655[] = {0x1f36f};
unsigned int emoji656[] = {0x1f370};
unsigned int emoji657[] = {0x1f371};
unsigned int emoji658[] = {0x1f372};
unsigned int emoji659[] = {0x1f373};
unsigned int emoji660[] = {0x1f374};
unsigned int emoji661[] = {0x1f375};
unsigned int emoji662[] = {0x1f376};
unsigned int emoji663[] = {0x1f377};
unsigned int emoji664[] = {0x1f378};
unsigned int emoji665[] = {0x1f379};
unsigned int emoji666[] = {0x1f37a};
unsigned int emoji667[] = {0x1f37b};
unsigned int emoji668[] = {0x1f37c};
unsigned int emoji669[] = {0x1f37d};
unsigned int emoji670[] = {0x1f37e};
unsigned int emoji671[] = {0x1f37f};
unsigned int emoji672[] = {0x1f380};
unsigned int emoji673[] = {0x1f381};
unsigned int emoji674[] = {0x1f382};
unsigned int emoji675[] = {0x1f383};
unsigned int emoji676[] = {0x1f384};
unsigned int emoji677[] = {0x1f385};
unsigned int emoji678[] = {0x1f385,0x1f3fb};
unsigned int emoji679[] = {0x1f385,0x1f3fc};
unsigned int emoji680[] = {0x1f385,0x1f3fd};
unsigned int emoji681[] = {0x1f385,0x1f3fe};
unsigned int emoji682[] = {0x1f385,0x1f3ff};
unsigned int emoji683[] = {0x1f386};
unsigned int emoji684[] = {0x1f387};
unsigned int emoji685[] = {0x1f388};
unsigned int emoji686[] = {0x1f389};
unsigned int emoji687[] = {0x1f38a};
unsigned int emoji688[] = {0x1f38b};
unsigned int emoji689[] = {0x1f38c};
unsigned int emoji690[] = {0x1f38d};
unsigned int emoji691[] = {0x1f38e};
unsigned int emoji692[] = {0x1f38f};
unsigned int emoji693[] = {0x1f390};
unsigned int emoji694[] = {0x1f391};
unsigned int emoji695[] = {0x1f392};
unsigned int emoji696[] = {0x1f393};
unsigned int emoji697[] = {0x1f396};
unsigned int emoji698[] = {0x1f397};
unsigned int emoji699[] = {0x1f399};
unsigned int emoji700[] = {0x1f39a};
unsigned int emoji701[] = {0x1f39b};
unsigned int emoji702[] = {0x1f39e};
unsigned int emoji703[] = {0x1f39f};
unsigned int emoji704[] = {0x1f3a0};
unsigned int emoji705[] = {0x1f3a1};
unsigned int emoji706[] = {0x1f3a2};
unsigned int emoji707[] = {0x1f3a3};
unsigned int emoji708[] = {0x1f3a4};
unsigned int emoji709[] = {0x1f3a5};
unsigned int emoji710[] = {0x1f3a6};
unsigned int emoji711[] = {0x1f3a7};
unsigned int emoji712[] = {0x1f3a8};
unsigned int emoji713[] = {0x1f3a9};
unsigned int emoji714[] = {0x1f3aa};
unsigned int emoji715[] = {0x1f3ab};
unsigned int emoji716[] = {0x1f3ac};
unsigned int emoji717[] = {0x1f3ad};
unsigned int emoji718[] = {0x1f3ae};
unsigned int emoji719[] = {0x1f3af};
unsigned int emoji720[] = {0x1f3b0};
unsigned int emoji721[] = {0x1f3b1};
unsigned int emoji722[] = {0x1f3b2};
unsigned int emoji723[] = {0x1f3b3};
unsigned int emoji724[] = {0x1f3b4};
unsigned int emoji725[] = {0x1f3b5};
unsigned int emoji726[] = {0x1f3b6};
unsigned int emoji727[] = {0x1f3b7};
unsigned int emoji728[] = {0x1f3b8};
unsigned int emoji729[] = {0x1f3b9};
unsigned int emoji730[] = {0x1f3ba};
unsigned int emoji731[] = {0x1f3bb};
unsigned int emoji732[] = {0x1f3bc};
unsigned int emoji733[] = {0x1f3bd};
unsigned int emoji734[] = {0x1f3be};
unsigned int emoji735[] = {0x1f3bf};
unsigned int emoji736[] = {0x1f3c0};
unsigned int emoji737[] = {0x1f3c1};
unsigned int emoji738[] = {0x1f3c2};
unsigned int emoji739[] = {0x1f3c2,0x1f3fb};
unsigned int emoji740[] = {0x1f3c2,0x1f3fc};
unsigned int emoji741[] = {0x1f3c2,0x1f3fd};
unsigned int emoji742[] = {0x1f3c2,0x1f3fe};
unsigned int emoji743[] = {0x1f3c2,0x1f3ff};
unsigned int emoji744[] = {0x1f3c3};
unsigned int emoji745[] = {0x1f3c3,0x1f3fb};
unsigned int emoji746[] = {0x1f3c3,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji747[] = {0x1f3c3,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji748[] = {0x1f3c3,0x1f3fc};
unsigned int emoji749[] = {0x1f3c3,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji750[] = {0x1f3c3,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji751[] = {0x1f3c3,0x1f3fd};
unsigned int emoji752[] = {0x1f3c3,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji753[] = {0x1f3c3,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji754[] = {0x1f3c3,0x1f3fe};
unsigned int emoji755[] = {0x1f3c3,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji756[] = {0x1f3c3,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji757[] = {0x1f3c3,0x1f3ff};
unsigned int emoji758[] = {0x1f3c3,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji759[] = {0x1f3c3,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji760[] = {0x1f3c3,0x200d,0x2640,0xfe0f};
unsigned int emoji761[] = {0x1f3c3,0x200d,0x2642,0xfe0f};
unsigned int emoji762[] = {0x1f3c4};
unsigned int emoji763[] = {0x1f3c4,0x1f3fb};
unsigned int emoji764[] = {0x1f3c4,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji765[] = {0x1f3c4,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji766[] = {0x1f3c4,0x1f3fc};
unsigned int emoji767[] = {0x1f3c4,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji768[] = {0x1f3c4,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji769[] = {0x1f3c4,0x1f3fd};
unsigned int emoji770[] = {0x1f3c4,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji771[] = {0x1f3c4,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji772[] = {0x1f3c4,0x1f3fe};
unsigned int emoji773[] = {0x1f3c4,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji774[] = {0x1f3c4,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji775[] = {0x1f3c4,0x1f3ff};
unsigned int emoji776[] = {0x1f3c4,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji777[] = {0x1f3c4,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji778[] = {0x1f3c4,0x200d,0x2640,0xfe0f};
unsigned int emoji779[] = {0x1f3c4,0x200d,0x2642,0xfe0f};
unsigned int emoji780[] = {0x1f3c5};
unsigned int emoji781[] = {0x1f3c6};
unsigned int emoji782[] = {0x1f3c7};
unsigned int emoji783[] = {0x1f3c7,0x1f3fb};
unsigned int emoji784[] = {0x1f3c7,0x1f3fc};
unsigned int emoji785[] = {0x1f3c7,0x1f3fd};
unsigned int emoji786[] = {0x1f3c7,0x1f3fe};
unsigned int emoji787[] = {0x1f3c7,0x1f3ff};
unsigned int emoji788[] = {0x1f3c8};
unsigned int emoji789[] = {0x1f3c9};
unsigned int emoji790[] = {0x1f3ca};
unsigned int emoji791[] = {0x1f3ca,0x1f3fb};
unsigned int emoji792[] = {0x1f3ca,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji793[] = {0x1f3ca,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji794[] = {0x1f3ca,0x1f3fc};
unsigned int emoji795[] = {0x1f3ca,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji796[] = {0x1f3ca,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji797[] = {0x1f3ca,0x1f3fd};
unsigned int emoji798[] = {0x1f3ca,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji799[] = {0x1f3ca,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji800[] = {0x1f3ca,0x1f3fe};
unsigned int emoji801[] = {0x1f3ca,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji802[] = {0x1f3ca,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji803[] = {0x1f3ca,0x1f3ff};
unsigned int emoji804[] = {0x1f3ca,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji805[] = {0x1f3ca,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji806[] = {0x1f3ca,0x200d,0x2640,0xfe0f};
unsigned int emoji807[] = {0x1f3ca,0x200d,0x2642,0xfe0f};
unsigned int emoji808[] = {0x1f3cb};
unsigned int emoji809[] = {0x1f3cb,0x1f3fb};
unsigned int emoji810[] = {0x1f3cb,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji811[] = {0x1f3cb,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji812[] = {0x1f3cb,0x1f3fc};
unsigned int emoji813[] = {0x1f3cb,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji814[] = {0x1f3cb,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji815[] = {0x1f3cb,0x1f3fd};
unsigned int emoji816[] = {0x1f3cb,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji817[] = {0x1f3cb,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji818[] = {0x1f3cb,0x1f3fe};
unsigned int emoji819[] = {0x1f3cb,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji820[] = {0x1f3cb,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji821[] = {0x1f3cb,0x1f3ff};
unsigned int emoji822[] = {0x1f3cb,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji823[] = {0x1f3cb,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji824[] = {0x1f3cb,0xfe0f,0x200d,0x2640,0xfe0f};
unsigned int emoji825[] = {0x1f3cb,0xfe0f,0x200d,0x2642,0xfe0f};
unsigned int emoji826[] = {0x1f3cc};
unsigned int emoji827[] = {0x1f3cc,0x1f3fb};
unsigned int emoji828[] = {0x1f3cc,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji829[] = {0x1f3cc,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji830[] = {0x1f3cc,0x1f3fc};
unsigned int emoji831[] = {0x1f3cc,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji832[] = {0x1f3cc,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji833[] = {0x1f3cc,0x1f3fd};
unsigned int emoji834[] = {0x1f3cc,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji835[] = {0x1f3cc,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji836[] = {0x1f3cc,0x1f3fe};
unsigned int emoji837[] = {0x1f3cc,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji838[] = {0x1f3cc,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji839[] = {0x1f3cc,0x1f3ff};
unsigned int emoji840[] = {0x1f3cc,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji841[] = {0x1f3cc,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji842[] = {0x1f3cc,0xfe0f,0x200d,0x2640,0xfe0f};
unsigned int emoji843[] = {0x1f3cc,0xfe0f,0x200d,0x2642,0xfe0f};
unsigned int emoji844[] = {0x1f3cd};
unsigned int emoji845[] = {0x1f3ce};
unsigned int emoji846[] = {0x1f3cf};
unsigned int emoji847[] = {0x1f3d0};
unsigned int emoji848[] = {0x1f3d1};
unsigned int emoji849[] = {0x1f3d2};
unsigned int emoji850[] = {0x1f3d3};
unsigned int emoji851[] = {0x1f3d4};
unsigned int emoji852[] = {0x1f3d5};
unsigned int emoji853[] = {0x1f3d6};
unsigned int emoji854[] = {0x1f3d7};
unsigned int emoji855[] = {0x1f3d8};
unsigned int emoji856[] = {0x1f3d9};
unsigned int emoji857[] = {0x1f3da};
unsigned int emoji858[] = {0x1f3db};
unsigned int emoji859[] = {0x1f3dc};
unsigned int emoji860[] = {0x1f3dd};
unsigned int emoji861[] = {0x1f3de};
unsigned int emoji862[] = {0x1f3df};
unsigned int emoji863[] = {0x1f3e0};
unsigned int emoji864[] = {0x1f3e1};
unsigned int emoji865[] = {0x1f3e2};
unsigned int emoji866[] = {0x1f3e3};
unsigned int emoji867[] = {0x1f3e4};
unsigned int emoji868[] = {0x1f3e5};
unsigned int emoji869[] = {0x1f3e6};
unsigned int emoji870[] = {0x1f3e7};
unsigned int emoji871[] = {0x1f3e8};
unsigned int emoji872[] = {0x1f3e9};
unsigned int emoji873[] = {0x1f3ea};
unsigned int emoji874[] = {0x1f3eb};
unsigned int emoji875[] = {0x1f3ec};
unsigned int emoji876[] = {0x1f3ed};
unsigned int emoji877[] = {0x1f3ee};
unsigned int emoji878[] = {0x1f3ef};
unsigned int emoji879[] = {0x1f3f0};
unsigned int emoji880[] = {0x1f3f3};
unsigned int emoji881[] = {0x1f3f3,0xfe0f,0x200d,0x1f308};
unsigned int emoji882[] = {0x1f3f3,0xfe0f,0x200d,0x26a7,0xfe0f};
unsigned int emoji883[] = {0x1f3f4};
unsigned int emoji884[] = {0x1f3f4,0x200d,0x2620,0xfe0f};
unsigned int emoji885[] = {0x1f3f4,0xe0067,0xe0062,0xe0065,0xe006e,0xe0067,0xe007f};
unsigned int emoji886[] = {0x1f3f4,0xe0067,0xe0062,0xe0073,0xe0063,0xe0074,0xe007f};
unsigned int emoji887[] = {0x1f3f4,0xe0067,0xe0062,0xe0077,0xe006c,0xe0073,0xe007f};
unsigned int emoji888[] = {0x1f3f5};
unsigned int emoji889[] = {0x1f3f7};
unsigned int emoji890[] = {0x1f3f8};
unsigned int emoji891[] = {0x1f3f9};
unsigned int emoji892[] = {0x1f3fa};
unsigned int emoji893[] = {0x1f3fb};
unsigned int emoji894[] = {0x1f3fc};
unsigned int emoji895[] = {0x1f3fd};
unsigned int emoji896[] = {0x1f3fe};
unsigned int emoji897[] = {0x1f3ff};
unsigned int emoji898[] = {0x1f400};
unsigned int emoji899[] = {0x1f401};
unsigned int emoji900[] = {0x1f402};
unsigned int emoji901[] = {0x1f403};
unsigned int emoji902[] = {0x1f404};
unsigned int emoji903[] = {0x1f405};
unsigned int emoji904[] = {0x1f406};
unsigned int emoji905[] = {0x1f407};
unsigned int emoji906[] = {0x1f408};
unsigned int emoji907[] = {0x1f408,0x200d,0x2b1b};
unsigned int emoji908[] = {0x1f409};
unsigned int emoji909[] = {0x1f40a};
unsigned int emoji910[] = {0x1f40b};
unsigned int emoji911[] = {0x1f40c};
unsigned int emoji912[] = {0x1f40d};
unsigned int emoji913[] = {0x1f40e};
unsigned int emoji914[] = {0x1f40f};
unsigned int emoji915[] = {0x1f410};
unsigned int emoji916[] = {0x1f411};
unsigned int emoji917[] = {0x1f412};
unsigned int emoji918[] = {0x1f413};
unsigned int emoji919[] = {0x1f414};
unsigned int emoji920[] = {0x1f415};
unsigned int emoji921[] = {0x1f415,0x200d,0x1f9ba};
unsigned int emoji922[] = {0x1f416};
unsigned int emoji923[] = {0x1f417};
unsigned int emoji924[] = {0x1f418};
unsigned int emoji925[] = {0x1f419};
unsigned int emoji926[] = {0x1f41a};
unsigned int emoji927[] = {0x1f41b};
unsigned int emoji928[] = {0x1f41c};
unsigned int emoji929[] = {0x1f41d};
unsigned int emoji930[] = {0x1f41e};
unsigned int emoji931[] = {0x1f41f};
unsigned int emoji932[] = {0x1f420};
unsigned int emoji933[] = {0x1f421};
unsigned int emoji934[] = {0x1f422};
unsigned int emoji935[] = {0x1f423};
unsigned int emoji936[] = {0x1f424};
unsigned int emoji937[] = {0x1f425};
unsigned int emoji938[] = {0x1f426};
unsigned int emoji939[] = {0x1f427};
unsigned int emoji940[] = {0x1f428};
unsigned int emoji941[] = {0x1f429};
unsigned int emoji942[] = {0x1f42a};
unsigned int emoji943[] = {0x1f42b};
unsigned int emoji944[] = {0x1f42c};
unsigned int emoji945[] = {0x1f42d};
unsigned int emoji946[] = {0x1f42e};
unsigned int emoji947[] = {0x1f42f};
unsigned int emoji948[] = {0x1f430};
unsigned int emoji949[] = {0x1f431};
unsigned int emoji950[] = {0x1f432};
unsigned int emoji951[] = {0x1f433};
unsigned int emoji952[] = {0x1f434};
unsigned int emoji953[] = {0x1f435};
unsigned int emoji954[] = {0x1f436};
unsigned int emoji955[] = {0x1f437};
unsigned int emoji956[] = {0x1f438};
unsigned int emoji957[] = {0x1f439};
unsigned int emoji958[] = {0x1f43a};
unsigned int emoji959[] = {0x1f43b};
unsigned int emoji960[] = {0x1f43b,0x200d,0x2744,0xfe0f};
unsigned int emoji961[] = {0x1f43c};
unsigned int emoji962[] = {0x1f43d};
unsigned int emoji963[] = {0x1f43e};
unsigned int emoji964[] = {0x1f43f};
unsigned int emoji965[] = {0x1f440};
unsigned int emoji966[] = {0x1f441};
unsigned int emoji967[] = {0x1f441,0x200d,0x1f5e8};
unsigned int emoji968[] = {0x1f442};
unsigned int emoji969[] = {0x1f442,0x1f3fb};
unsigned int emoji970[] = {0x1f442,0x1f3fc};
unsigned int emoji971[] = {0x1f442,0x1f3fd};
unsigned int emoji972[] = {0x1f442,0x1f3fe};
unsigned int emoji973[] = {0x1f442,0x1f3ff};
unsigned int emoji974[] = {0x1f443};
unsigned int emoji975[] = {0x1f443,0x1f3fb};
unsigned int emoji976[] = {0x1f443,0x1f3fc};
unsigned int emoji977[] = {0x1f443,0x1f3fd};
unsigned int emoji978[] = {0x1f443,0x1f3fe};
unsigned int emoji979[] = {0x1f443,0x1f3ff};
unsigned int emoji980[] = {0x1f444};
unsigned int emoji981[] = {0x1f445};
unsigned int emoji982[] = {0x1f446};
unsigned int emoji983[] = {0x1f446,0x1f3fb};
unsigned int emoji984[] = {0x1f446,0x1f3fc};
unsigned int emoji985[] = {0x1f446,0x1f3fd};
unsigned int emoji986[] = {0x1f446,0x1f3fe};
unsigned int emoji987[] = {0x1f446,0x1f3ff};
unsigned int emoji988[] = {0x1f447};
unsigned int emoji989[] = {0x1f447,0x1f3fb};
unsigned int emoji990[] = {0x1f447,0x1f3fc};
unsigned int emoji991[] = {0x1f447,0x1f3fd};
unsigned int emoji992[] = {0x1f447,0x1f3fe};
unsigned int emoji993[] = {0x1f447,0x1f3ff};
unsigned int emoji994[] = {0x1f448};
unsigned int emoji995[] = {0x1f448,0x1f3fb};
unsigned int emoji996[] = {0x1f448,0x1f3fc};
unsigned int emoji997[] = {0x1f448,0x1f3fd};
unsigned int emoji998[] = {0x1f448,0x1f3fe};
unsigned int emoji999[] = {0x1f448,0x1f3ff};
unsigned int emoji1000[] = {0x1f449};
unsigned int emoji1001[] = {0x1f449,0x1f3fb};
unsigned int emoji1002[] = {0x1f449,0x1f3fc};
unsigned int emoji1003[] = {0x1f449,0x1f3fd};
unsigned int emoji1004[] = {0x1f449,0x1f3fe};
unsigned int emoji1005[] = {0x1f449,0x1f3ff};
unsigned int emoji1006[] = {0x1f44a};
unsigned int emoji1007[] = {0x1f44a,0x1f3fb};
unsigned int emoji1008[] = {0x1f44a,0x1f3fc};
unsigned int emoji1009[] = {0x1f44a,0x1f3fd};
unsigned int emoji1010[] = {0x1f44a,0x1f3fe};
unsigned int emoji1011[] = {0x1f44a,0x1f3ff};
unsigned int emoji1012[] = {0x1f44b};
unsigned int emoji1013[] = {0x1f44b,0x1f3fb};
unsigned int emoji1014[] = {0x1f44b,0x1f3fc};
unsigned int emoji1015[] = {0x1f44b,0x1f3fd};
unsigned int emoji1016[] = {0x1f44b,0x1f3fe};
unsigned int emoji1017[] = {0x1f44b,0x1f3ff};
unsigned int emoji1018[] = {0x1f44c};
unsigned int emoji1019[] = {0x1f44c,0x1f3fb};
unsigned int emoji1020[] = {0x1f44c,0x1f3fc};
unsigned int emoji1021[] = {0x1f44c,0x1f3fd};
unsigned int emoji1022[] = {0x1f44c,0x1f3fe};
unsigned int emoji1023[] = {0x1f44c,0x1f3ff};
unsigned int emoji1024[] = {0x1f44d};
unsigned int emoji1025[] = {0x1f44d,0x1f3fb};
unsigned int emoji1026[] = {0x1f44d,0x1f3fc};
unsigned int emoji1027[] = {0x1f44d,0x1f3fd};
unsigned int emoji1028[] = {0x1f44d,0x1f3fe};
unsigned int emoji1029[] = {0x1f44d,0x1f3ff};
unsigned int emoji1030[] = {0x1f44e};
unsigned int emoji1031[] = {0x1f44e,0x1f3fb};
unsigned int emoji1032[] = {0x1f44e,0x1f3fc};
unsigned int emoji1033[] = {0x1f44e,0x1f3fd};
unsigned int emoji1034[] = {0x1f44e,0x1f3fe};
unsigned int emoji1035[] = {0x1f44e,0x1f3ff};
unsigned int emoji1036[] = {0x1f44f};
unsigned int emoji1037[] = {0x1f44f,0x1f3fb};
unsigned int emoji1038[] = {0x1f44f,0x1f3fc};
unsigned int emoji1039[] = {0x1f44f,0x1f3fd};
unsigned int emoji1040[] = {0x1f44f,0x1f3fe};
unsigned int emoji1041[] = {0x1f44f,0x1f3ff};
unsigned int emoji1042[] = {0x1f450};
unsigned int emoji1043[] = {0x1f450,0x1f3fb};
unsigned int emoji1044[] = {0x1f450,0x1f3fc};
unsigned int emoji1045[] = {0x1f450,0x1f3fd};
unsigned int emoji1046[] = {0x1f450,0x1f3fe};
unsigned int emoji1047[] = {0x1f450,0x1f3ff};
unsigned int emoji1048[] = {0x1f451};
unsigned int emoji1049[] = {0x1f452};
unsigned int emoji1050[] = {0x1f453};
unsigned int emoji1051[] = {0x1f454};
unsigned int emoji1052[] = {0x1f455};
unsigned int emoji1053[] = {0x1f456};
unsigned int emoji1054[] = {0x1f457};
unsigned int emoji1055[] = {0x1f458};
unsigned int emoji1056[] = {0x1f459};
unsigned int emoji1057[] = {0x1f45a};
unsigned int emoji1058[] = {0x1f45b};
unsigned int emoji1059[] = {0x1f45c};
unsigned int emoji1060[] = {0x1f45d};
unsigned int emoji1061[] = {0x1f45e};
unsigned int emoji1062[] = {0x1f45f};
unsigned int emoji1063[] = {0x1f460};
unsigned int emoji1064[] = {0x1f461};
unsigned int emoji1065[] = {0x1f462};
unsigned int emoji1066[] = {0x1f463};
unsigned int emoji1067[] = {0x1f464};
unsigned int emoji1068[] = {0x1f465};
unsigned int emoji1069[] = {0x1f466};
unsigned int emoji1070[] = {0x1f466,0x1f3fb};
unsigned int emoji1071[] = {0x1f466,0x1f3fc};
unsigned int emoji1072[] = {0x1f466,0x1f3fd};
unsigned int emoji1073[] = {0x1f466,0x1f3fe};
unsigned int emoji1074[] = {0x1f466,0x1f3ff};
unsigned int emoji1075[] = {0x1f467};
unsigned int emoji1076[] = {0x1f467,0x1f3fb};
unsigned int emoji1077[] = {0x1f467,0x1f3fc};
unsigned int emoji1078[] = {0x1f467,0x1f3fd};
unsigned int emoji1079[] = {0x1f467,0x1f3fe};
unsigned int emoji1080[] = {0x1f467,0x1f3ff};
unsigned int emoji1081[] = {0x1f468};
unsigned int emoji1082[] = {0x1f468,0x1f3fb};
unsigned int emoji1083[] = {0x1f468,0x1f3fb,0x200d,0x1f3a4};
unsigned int emoji1084[] = {0x1f468,0x1f3fb,0x200d,0x1f3a8};
unsigned int emoji1085[] = {0x1f468,0x1f3fb,0x200d,0x1f3eb};
unsigned int emoji1086[] = {0x1f468,0x1f3fb,0x200d,0x1f3ed};
unsigned int emoji1087[] = {0x1f468,0x1f3fb,0x200d,0x1f4bb};
unsigned int emoji1088[] = {0x1f468,0x1f3fb,0x200d,0x1f4bc};
unsigned int emoji1089[] = {0x1f468,0x1f3fb,0x200d,0x1f9af};
unsigned int emoji1090[] = {0x1f468,0x1f3fb,0x200d,0x1f9b0};
unsigned int emoji1091[] = {0x1f468,0x1f3fb,0x200d,0x1f9b1};
unsigned int emoji1092[] = {0x1f468,0x1f3fb,0x200d,0x1f9b2};
unsigned int emoji1093[] = {0x1f468,0x1f3fb,0x200d,0x1f9b3};
unsigned int emoji1094[] = {0x1f468,0x1f3fb,0x200d,0x1f9bc};
unsigned int emoji1095[] = {0x1f468,0x1f3fb,0x200d,0x1f9bd};
unsigned int emoji1096[] = {0x1f468,0x1f3fb,0x200d,0x1f33e};
unsigned int emoji1097[] = {0x1f468,0x1f3fb,0x200d,0x1f37c};
unsigned int emoji1098[] = {0x1f468,0x1f3fb,0x200d,0x1f52c};
unsigned int emoji1099[] = {0x1f468,0x1f3fb,0x200d,0x1f91d,0x200d,0x1f468,0x1f3fc};
unsigned int emoji1100[] = {0x1f468,0x1f3fb,0x200d,0x1f91d,0x200d,0x1f468,0x1f3fd};
unsigned int emoji1101[] = {0x1f468,0x1f3fb,0x200d,0x1f91d,0x200d,0x1f468,0x1f3fe};
unsigned int emoji1102[] = {0x1f468,0x1f3fb,0x200d,0x1f91d,0x200d,0x1f468,0x1f3ff};
unsigned int emoji1103[] = {0x1f468,0x1f3fb,0x200d,0x1f373};
unsigned int emoji1104[] = {0x1f468,0x1f3fb,0x200d,0x1f384};
unsigned int emoji1105[] = {0x1f468,0x1f3fb,0x200d,0x1f393};
unsigned int emoji1106[] = {0x1f468,0x1f3fb,0x200d,0x1f527};
unsigned int emoji1107[] = {0x1f468,0x1f3fb,0x200d,0x1f680};
unsigned int emoji1108[] = {0x1f468,0x1f3fb,0x200d,0x1f692};
unsigned int emoji1109[] = {0x1f468,0x1f3fb,0x200d,0x2695,0xfe0f};
unsigned int emoji1110[] = {0x1f468,0x1f3fb,0x200d,0x2696,0xfe0f};
unsigned int emoji1111[] = {0x1f468,0x1f3fb,0x200d,0x2708,0xfe0f};
unsigned int emoji1112[] = {0x1f468,0x1f3fc};
unsigned int emoji1113[] = {0x1f468,0x1f3fc,0x200d,0x1f3a4};
unsigned int emoji1114[] = {0x1f468,0x1f3fc,0x200d,0x1f3a8};
unsigned int emoji1115[] = {0x1f468,0x1f3fc,0x200d,0x1f3eb};
unsigned int emoji1116[] = {0x1f468,0x1f3fc,0x200d,0x1f3ed};
unsigned int emoji1117[] = {0x1f468,0x1f3fc,0x200d,0x1f4bb};
unsigned int emoji1118[] = {0x1f468,0x1f3fc,0x200d,0x1f4bc};
unsigned int emoji1119[] = {0x1f468,0x1f3fc,0x200d,0x1f9af};
unsigned int emoji1120[] = {0x1f468,0x1f3fc,0x200d,0x1f9b0};
unsigned int emoji1121[] = {0x1f468,0x1f3fc,0x200d,0x1f9b1};
unsigned int emoji1122[] = {0x1f468,0x1f3fc,0x200d,0x1f9b2};
unsigned int emoji1123[] = {0x1f468,0x1f3fc,0x200d,0x1f9b3};
unsigned int emoji1124[] = {0x1f468,0x1f3fc,0x200d,0x1f9bc};
unsigned int emoji1125[] = {0x1f468,0x1f3fc,0x200d,0x1f9bd};
unsigned int emoji1126[] = {0x1f468,0x1f3fc,0x200d,0x1f33e};
unsigned int emoji1127[] = {0x1f468,0x1f3fc,0x200d,0x1f37c};
unsigned int emoji1128[] = {0x1f468,0x1f3fc,0x200d,0x1f52c};
unsigned int emoji1129[] = {0x1f468,0x1f3fc,0x200d,0x1f91d,0x200d,0x1f468,0x1f3fb};
unsigned int emoji1130[] = {0x1f468,0x1f3fc,0x200d,0x1f91d,0x200d,0x1f468,0x1f3fd};
unsigned int emoji1131[] = {0x1f468,0x1f3fc,0x200d,0x1f91d,0x200d,0x1f468,0x1f3fe};
unsigned int emoji1132[] = {0x1f468,0x1f3fc,0x200d,0x1f91d,0x200d,0x1f468,0x1f3ff};
unsigned int emoji1133[] = {0x1f468,0x1f3fc,0x200d,0x1f373};
unsigned int emoji1134[] = {0x1f468,0x1f3fc,0x200d,0x1f384};
unsigned int emoji1135[] = {0x1f468,0x1f3fc,0x200d,0x1f393};
unsigned int emoji1136[] = {0x1f468,0x1f3fc,0x200d,0x1f527};
unsigned int emoji1137[] = {0x1f468,0x1f3fc,0x200d,0x1f680};
unsigned int emoji1138[] = {0x1f468,0x1f3fc,0x200d,0x1f692};
unsigned int emoji1139[] = {0x1f468,0x1f3fc,0x200d,0x2695,0xfe0f};
unsigned int emoji1140[] = {0x1f468,0x1f3fc,0x200d,0x2696,0xfe0f};
unsigned int emoji1141[] = {0x1f468,0x1f3fc,0x200d,0x2708,0xfe0f};
unsigned int emoji1142[] = {0x1f468,0x1f3fd};
unsigned int emoji1143[] = {0x1f468,0x1f3fd,0x200d,0x1f3a4};
unsigned int emoji1144[] = {0x1f468,0x1f3fd,0x200d,0x1f3a8};
unsigned int emoji1145[] = {0x1f468,0x1f3fd,0x200d,0x1f3eb};
unsigned int emoji1146[] = {0x1f468,0x1f3fd,0x200d,0x1f3ed};
unsigned int emoji1147[] = {0x1f468,0x1f3fd,0x200d,0x1f4bb};
unsigned int emoji1148[] = {0x1f468,0x1f3fd,0x200d,0x1f4bc};
unsigned int emoji1149[] = {0x1f468,0x1f3fd,0x200d,0x1f9af};
unsigned int emoji1150[] = {0x1f468,0x1f3fd,0x200d,0x1f9b0};
unsigned int emoji1151[] = {0x1f468,0x1f3fd,0x200d,0x1f9b1};
unsigned int emoji1152[] = {0x1f468,0x1f3fd,0x200d,0x1f9b2};
unsigned int emoji1153[] = {0x1f468,0x1f3fd,0x200d,0x1f9b3};
unsigned int emoji1154[] = {0x1f468,0x1f3fd,0x200d,0x1f9bc};
unsigned int emoji1155[] = {0x1f468,0x1f3fd,0x200d,0x1f9bd};
unsigned int emoji1156[] = {0x1f468,0x1f3fd,0x200d,0x1f33e};
unsigned int emoji1157[] = {0x1f468,0x1f3fd,0x200d,0x1f37c};
unsigned int emoji1158[] = {0x1f468,0x1f3fd,0x200d,0x1f52c};
unsigned int emoji1159[] = {0x1f468,0x1f3fd,0x200d,0x1f91d,0x200d,0x1f468,0x1f3fb};
unsigned int emoji1160[] = {0x1f468,0x1f3fd,0x200d,0x1f91d,0x200d,0x1f468,0x1f3fc};
unsigned int emoji1161[] = {0x1f468,0x1f3fd,0x200d,0x1f91d,0x200d,0x1f468,0x1f3fe};
unsigned int emoji1162[] = {0x1f468,0x1f3fd,0x200d,0x1f91d,0x200d,0x1f468,0x1f3ff};
unsigned int emoji1163[] = {0x1f468,0x1f3fd,0x200d,0x1f373};
unsigned int emoji1164[] = {0x1f468,0x1f3fd,0x200d,0x1f384};
unsigned int emoji1165[] = {0x1f468,0x1f3fd,0x200d,0x1f393};
unsigned int emoji1166[] = {0x1f468,0x1f3fd,0x200d,0x1f527};
unsigned int emoji1167[] = {0x1f468,0x1f3fd,0x200d,0x1f680};
unsigned int emoji1168[] = {0x1f468,0x1f3fd,0x200d,0x1f692};
unsigned int emoji1169[] = {0x1f468,0x1f3fd,0x200d,0x2695,0xfe0f};
unsigned int emoji1170[] = {0x1f468,0x1f3fd,0x200d,0x2696,0xfe0f};
unsigned int emoji1171[] = {0x1f468,0x1f3fd,0x200d,0x2708,0xfe0f};
unsigned int emoji1172[] = {0x1f468,0x1f3fe};
unsigned int emoji1173[] = {0x1f468,0x1f3fe,0x200d,0x1f3a4};
unsigned int emoji1174[] = {0x1f468,0x1f3fe,0x200d,0x1f3a8};
unsigned int emoji1175[] = {0x1f468,0x1f3fe,0x200d,0x1f3eb};
unsigned int emoji1176[] = {0x1f468,0x1f3fe,0x200d,0x1f3ed};
unsigned int emoji1177[] = {0x1f468,0x1f3fe,0x200d,0x1f4bb};
unsigned int emoji1178[] = {0x1f468,0x1f3fe,0x200d,0x1f4bc};
unsigned int emoji1179[] = {0x1f468,0x1f3fe,0x200d,0x1f9af};
unsigned int emoji1180[] = {0x1f468,0x1f3fe,0x200d,0x1f9b0};
unsigned int emoji1181[] = {0x1f468,0x1f3fe,0x200d,0x1f9b1};
unsigned int emoji1182[] = {0x1f468,0x1f3fe,0x200d,0x1f9b2};
unsigned int emoji1183[] = {0x1f468,0x1f3fe,0x200d,0x1f9b3};
unsigned int emoji1184[] = {0x1f468,0x1f3fe,0x200d,0x1f9bc};
unsigned int emoji1185[] = {0x1f468,0x1f3fe,0x200d,0x1f9bd};
unsigned int emoji1186[] = {0x1f468,0x1f3fe,0x200d,0x1f33e};
unsigned int emoji1187[] = {0x1f468,0x1f3fe,0x200d,0x1f37c};
unsigned int emoji1188[] = {0x1f468,0x1f3fe,0x200d,0x1f52c};
unsigned int emoji1189[] = {0x1f468,0x1f3fe,0x200d,0x1f91d,0x200d,0x1f468,0x1f3fb};
unsigned int emoji1190[] = {0x1f468,0x1f3fe,0x200d,0x1f91d,0x200d,0x1f468,0x1f3fc};
unsigned int emoji1191[] = {0x1f468,0x1f3fe,0x200d,0x1f91d,0x200d,0x1f468,0x1f3fd};
unsigned int emoji1192[] = {0x1f468,0x1f3fe,0x200d,0x1f91d,0x200d,0x1f468,0x1f3ff};
unsigned int emoji1193[] = {0x1f468,0x1f3fe,0x200d,0x1f373};
unsigned int emoji1194[] = {0x1f468,0x1f3fe,0x200d,0x1f384};
unsigned int emoji1195[] = {0x1f468,0x1f3fe,0x200d,0x1f393};
unsigned int emoji1196[] = {0x1f468,0x1f3fe,0x200d,0x1f527};
unsigned int emoji1197[] = {0x1f468,0x1f3fe,0x200d,0x1f680};
unsigned int emoji1198[] = {0x1f468,0x1f3fe,0x200d,0x1f692};
unsigned int emoji1199[] = {0x1f468,0x1f3fe,0x200d,0x2695,0xfe0f};
unsigned int emoji1200[] = {0x1f468,0x1f3fe,0x200d,0x2696,0xfe0f};
unsigned int emoji1201[] = {0x1f468,0x1f3fe,0x200d,0x2708,0xfe0f};
unsigned int emoji1202[] = {0x1f468,0x1f3ff};
unsigned int emoji1203[] = {0x1f468,0x1f3ff,0x200d,0x1f3a4};
unsigned int emoji1204[] = {0x1f468,0x1f3ff,0x200d,0x1f3a8};
unsigned int emoji1205[] = {0x1f468,0x1f3ff,0x200d,0x1f3eb};
unsigned int emoji1206[] = {0x1f468,0x1f3ff,0x200d,0x1f3ed};
unsigned int emoji1207[] = {0x1f468,0x1f3ff,0x200d,0x1f4bb};
unsigned int emoji1208[] = {0x1f468,0x1f3ff,0x200d,0x1f4bc};
unsigned int emoji1209[] = {0x1f468,0x1f3ff,0x200d,0x1f9af};
unsigned int emoji1210[] = {0x1f468,0x1f3ff,0x200d,0x1f9b0};
unsigned int emoji1211[] = {0x1f468,0x1f3ff,0x200d,0x1f9b1};
unsigned int emoji1212[] = {0x1f468,0x1f3ff,0x200d,0x1f9b2};
unsigned int emoji1213[] = {0x1f468,0x1f3ff,0x200d,0x1f9b3};
unsigned int emoji1214[] = {0x1f468,0x1f3ff,0x200d,0x1f9bc};
unsigned int emoji1215[] = {0x1f468,0x1f3ff,0x200d,0x1f9bd};
unsigned int emoji1216[] = {0x1f468,0x1f3ff,0x200d,0x1f33e};
unsigned int emoji1217[] = {0x1f468,0x1f3ff,0x200d,0x1f37c};
unsigned int emoji1218[] = {0x1f468,0x1f3ff,0x200d,0x1f52c};
unsigned int emoji1219[] = {0x1f468,0x1f3ff,0x200d,0x1f91d,0x200d,0x1f468,0x1f3fb};
unsigned int emoji1220[] = {0x1f468,0x1f3ff,0x200d,0x1f91d,0x200d,0x1f468,0x1f3fc};
unsigned int emoji1221[] = {0x1f468,0x1f3ff,0x200d,0x1f91d,0x200d,0x1f468,0x1f3fd};
unsigned int emoji1222[] = {0x1f468,0x1f3ff,0x200d,0x1f91d,0x200d,0x1f468,0x1f3fe};
unsigned int emoji1223[] = {0x1f468,0x1f3ff,0x200d,0x1f373};
unsigned int emoji1224[] = {0x1f468,0x1f3ff,0x200d,0x1f384};
unsigned int emoji1225[] = {0x1f468,0x1f3ff,0x200d,0x1f393};
unsigned int emoji1226[] = {0x1f468,0x1f3ff,0x200d,0x1f527};
unsigned int emoji1227[] = {0x1f468,0x1f3ff,0x200d,0x1f680};
unsigned int emoji1228[] = {0x1f468,0x1f3ff,0x200d,0x1f692};
unsigned int emoji1229[] = {0x1f468,0x1f3ff,0x200d,0x2695,0xfe0f};
unsigned int emoji1230[] = {0x1f468,0x1f3ff,0x200d,0x2696,0xfe0f};
unsigned int emoji1231[] = {0x1f468,0x1f3ff,0x200d,0x2708,0xfe0f};
unsigned int emoji1232[] = {0x1f468,0x200d,0x1f3a4};
unsigned int emoji1233[] = {0x1f468,0x200d,0x1f3a8};
unsigned int emoji1234[] = {0x1f468,0x200d,0x1f3eb};
unsigned int emoji1235[] = {0x1f468,0x200d,0x1f3ed};
unsigned int emoji1236[] = {0x1f468,0x200d,0x1f4bb};
unsigned int emoji1237[] = {0x1f468,0x200d,0x1f4bc};
unsigned int emoji1238[] = {0x1f468,0x200d,0x1f9af};
unsigned int emoji1239[] = {0x1f468,0x200d,0x1f9b0};
unsigned int emoji1240[] = {0x1f468,0x200d,0x1f9b1};
unsigned int emoji1241[] = {0x1f468,0x200d,0x1f9b2};
unsigned int emoji1242[] = {0x1f468,0x200d,0x1f9b3};
unsigned int emoji1243[] = {0x1f468,0x200d,0x1f9bc};
unsigned int emoji1244[] = {0x1f468,0x200d,0x1f9bd};
unsigned int emoji1245[] = {0x1f468,0x200d,0x1f33e};
unsigned int emoji1246[] = {0x1f468,0x200d,0x1f37c};
unsigned int emoji1247[] = {0x1f468,0x200d,0x1f52c};
unsigned int emoji1248[] = {0x1f468,0x200d,0x1f373};
unsigned int emoji1249[] = {0x1f468,0x200d,0x1f384};
unsigned int emoji1250[] = {0x1f468,0x200d,0x1f393};
unsigned int emoji1251[] = {0x1f468,0x200d,0x1f466};
unsigned int emoji1252[] = {0x1f468,0x200d,0x1f466,0x200d,0x1f466};
unsigned int emoji1253[] = {0x1f468,0x200d,0x1f467};
unsigned int emoji1254[] = {0x1f468,0x200d,0x1f467,0x200d,0x1f466};
unsigned int emoji1255[] = {0x1f468,0x200d,0x1f467,0x200d,0x1f467};
unsigned int emoji1256[] = {0x1f468,0x200d,0x1f468,0x200d,0x1f466};
unsigned int emoji1257[] = {0x1f468,0x200d,0x1f468,0x200d,0x1f466,0x200d,0x1f466};
unsigned int emoji1258[] = {0x1f468,0x200d,0x1f468,0x200d,0x1f467};
unsigned int emoji1259[] = {0x1f468,0x200d,0x1f468,0x200d,0x1f467,0x200d,0x1f466};
unsigned int emoji1260[] = {0x1f468,0x200d,0x1f468,0x200d,0x1f467,0x200d,0x1f467};
unsigned int emoji1261[] = {0x1f468,0x200d,0x1f469,0x200d,0x1f466};
unsigned int emoji1262[] = {0x1f468,0x200d,0x1f469,0x200d,0x1f466,0x200d,0x1f466};
unsigned int emoji1263[] = {0x1f468,0x200d,0x1f469,0x200d,0x1f467};
unsigned int emoji1264[] = {0x1f468,0x200d,0x1f469,0x200d,0x1f467,0x200d,0x1f466};
unsigned int emoji1265[] = {0x1f468,0x200d,0x1f469,0x200d,0x1f467,0x200d,0x1f467};
unsigned int emoji1266[] = {0x1f468,0x200d,0x1f527};
unsigned int emoji1267[] = {0x1f468,0x200d,0x1f680};
unsigned int emoji1268[] = {0x1f468,0x200d,0x1f692};
unsigned int emoji1269[] = {0x1f468,0x200d,0x2695,0xfe0f};
unsigned int emoji1270[] = {0x1f468,0x200d,0x2696,0xfe0f};
unsigned int emoji1271[] = {0x1f468,0x200d,0x2708,0xfe0f};
unsigned int emoji1272[] = {0x1f468,0x200d,0x2764,0xfe0f,0x200d,0x1f48b,0x200d,0x1f468};
unsigned int emoji1273[] = {0x1f468,0x200d,0x2764,0xfe0f,0x200d,0x1f468};
unsigned int emoji1274[] = {0x1f469};
unsigned int emoji1275[] = {0x1f469,0x1f3fb};
unsigned int emoji1276[] = {0x1f469,0x1f3fb,0x200d,0x1f3a4};
unsigned int emoji1277[] = {0x1f469,0x1f3fb,0x200d,0x1f3a8};
unsigned int emoji1278[] = {0x1f469,0x1f3fb,0x200d,0x1f3eb};
unsigned int emoji1279[] = {0x1f469,0x1f3fb,0x200d,0x1f3ed};
unsigned int emoji1280[] = {0x1f469,0x1f3fb,0x200d,0x1f4bb};
unsigned int emoji1281[] = {0x1f469,0x1f3fb,0x200d,0x1f4bc};
unsigned int emoji1282[] = {0x1f469,0x1f3fb,0x200d,0x1f9af};
unsigned int emoji1283[] = {0x1f469,0x1f3fb,0x200d,0x1f9b0};
unsigned int emoji1284[] = {0x1f469,0x1f3fb,0x200d,0x1f9b1};
unsigned int emoji1285[] = {0x1f469,0x1f3fb,0x200d,0x1f9b2};
unsigned int emoji1286[] = {0x1f469,0x1f3fb,0x200d,0x1f9b3};
unsigned int emoji1287[] = {0x1f469,0x1f3fb,0x200d,0x1f9bc};
unsigned int emoji1288[] = {0x1f469,0x1f3fb,0x200d,0x1f9bd};
unsigned int emoji1289[] = {0x1f469,0x1f3fb,0x200d,0x1f33e};
unsigned int emoji1290[] = {0x1f469,0x1f3fb,0x200d,0x1f37c};
unsigned int emoji1291[] = {0x1f469,0x1f3fb,0x200d,0x1f52c};
unsigned int emoji1292[] = {0x1f469,0x1f3fb,0x200d,0x1f91d,0x200d,0x1f468,0x1f3fc};
unsigned int emoji1293[] = {0x1f469,0x1f3fb,0x200d,0x1f91d,0x200d,0x1f468,0x1f3fd};
unsigned int emoji1294[] = {0x1f469,0x1f3fb,0x200d,0x1f91d,0x200d,0x1f468,0x1f3fe};
unsigned int emoji1295[] = {0x1f469,0x1f3fb,0x200d,0x1f91d,0x200d,0x1f468,0x1f3ff};
unsigned int emoji1296[] = {0x1f469,0x1f3fb,0x200d,0x1f91d,0x200d,0x1f469,0x1f3fc};
unsigned int emoji1297[] = {0x1f469,0x1f3fb,0x200d,0x1f91d,0x200d,0x1f469,0x1f3fd};
unsigned int emoji1298[] = {0x1f469,0x1f3fb,0x200d,0x1f91d,0x200d,0x1f469,0x1f3fe};
unsigned int emoji1299[] = {0x1f469,0x1f3fb,0x200d,0x1f91d,0x200d,0x1f469,0x1f3ff};
unsigned int emoji1300[] = {0x1f469,0x1f3fb,0x200d,0x1f373};
unsigned int emoji1301[] = {0x1f469,0x1f3fb,0x200d,0x1f384};
unsigned int emoji1302[] = {0x1f469,0x1f3fb,0x200d,0x1f393};
unsigned int emoji1303[] = {0x1f469,0x1f3fb,0x200d,0x1f527};
unsigned int emoji1304[] = {0x1f469,0x1f3fb,0x200d,0x1f680};
unsigned int emoji1305[] = {0x1f469,0x1f3fb,0x200d,0x1f692};
unsigned int emoji1306[] = {0x1f469,0x1f3fb,0x200d,0x2695,0xfe0f};
unsigned int emoji1307[] = {0x1f469,0x1f3fb,0x200d,0x2696,0xfe0f};
unsigned int emoji1308[] = {0x1f469,0x1f3fb,0x200d,0x2708,0xfe0f};
unsigned int emoji1309[] = {0x1f469,0x1f3fc};
unsigned int emoji1310[] = {0x1f469,0x1f3fc,0x200d,0x1f3a4};
unsigned int emoji1311[] = {0x1f469,0x1f3fc,0x200d,0x1f3a8};
unsigned int emoji1312[] = {0x1f469,0x1f3fc,0x200d,0x1f3eb};
unsigned int emoji1313[] = {0x1f469,0x1f3fc,0x200d,0x1f3ed};
unsigned int emoji1314[] = {0x1f469,0x1f3fc,0x200d,0x1f4bb};
unsigned int emoji1315[] = {0x1f469,0x1f3fc,0x200d,0x1f4bc};
unsigned int emoji1316[] = {0x1f469,0x1f3fc,0x200d,0x1f9af};
unsigned int emoji1317[] = {0x1f469,0x1f3fc,0x200d,0x1f9b0};
unsigned int emoji1318[] = {0x1f469,0x1f3fc,0x200d,0x1f9b1};
unsigned int emoji1319[] = {0x1f469,0x1f3fc,0x200d,0x1f9b2};
unsigned int emoji1320[] = {0x1f469,0x1f3fc,0x200d,0x1f9b3};
unsigned int emoji1321[] = {0x1f469,0x1f3fc,0x200d,0x1f9bc};
unsigned int emoji1322[] = {0x1f469,0x1f3fc,0x200d,0x1f9bd};
unsigned int emoji1323[] = {0x1f469,0x1f3fc,0x200d,0x1f33e};
unsigned int emoji1324[] = {0x1f469,0x1f3fc,0x200d,0x1f37c};
unsigned int emoji1325[] = {0x1f469,0x1f3fc,0x200d,0x1f52c};
unsigned int emoji1326[] = {0x1f469,0x1f3fc,0x200d,0x1f91d,0x200d,0x1f468,0x1f3fb};
unsigned int emoji1327[] = {0x1f469,0x1f3fc,0x200d,0x1f91d,0x200d,0x1f468,0x1f3fd};
unsigned int emoji1328[] = {0x1f469,0x1f3fc,0x200d,0x1f91d,0x200d,0x1f468,0x1f3fe};
unsigned int emoji1329[] = {0x1f469,0x1f3fc,0x200d,0x1f91d,0x200d,0x1f468,0x1f3ff};
unsigned int emoji1330[] = {0x1f469,0x1f3fc,0x200d,0x1f91d,0x200d,0x1f469,0x1f3fb};
unsigned int emoji1331[] = {0x1f469,0x1f3fc,0x200d,0x1f91d,0x200d,0x1f469,0x1f3fd};
unsigned int emoji1332[] = {0x1f469,0x1f3fc,0x200d,0x1f91d,0x200d,0x1f469,0x1f3fe};
unsigned int emoji1333[] = {0x1f469,0x1f3fc,0x200d,0x1f91d,0x200d,0x1f469,0x1f3ff};
unsigned int emoji1334[] = {0x1f469,0x1f3fc,0x200d,0x1f373};
unsigned int emoji1335[] = {0x1f469,0x1f3fc,0x200d,0x1f384};
unsigned int emoji1336[] = {0x1f469,0x1f3fc,0x200d,0x1f393};
unsigned int emoji1337[] = {0x1f469,0x1f3fc,0x200d,0x1f527};
unsigned int emoji1338[] = {0x1f469,0x1f3fc,0x200d,0x1f680};
unsigned int emoji1339[] = {0x1f469,0x1f3fc,0x200d,0x1f692};
unsigned int emoji1340[] = {0x1f469,0x1f3fc,0x200d,0x2695,0xfe0f};
unsigned int emoji1341[] = {0x1f469,0x1f3fc,0x200d,0x2696,0xfe0f};
unsigned int emoji1342[] = {0x1f469,0x1f3fc,0x200d,0x2708,0xfe0f};
unsigned int emoji1343[] = {0x1f469,0x1f3fd};
unsigned int emoji1344[] = {0x1f469,0x1f3fd,0x200d,0x1f3a4};
unsigned int emoji1345[] = {0x1f469,0x1f3fd,0x200d,0x1f3a8};
unsigned int emoji1346[] = {0x1f469,0x1f3fd,0x200d,0x1f3eb};
unsigned int emoji1347[] = {0x1f469,0x1f3fd,0x200d,0x1f3ed};
unsigned int emoji1348[] = {0x1f469,0x1f3fd,0x200d,0x1f4bb};
unsigned int emoji1349[] = {0x1f469,0x1f3fd,0x200d,0x1f4bc};
unsigned int emoji1350[] = {0x1f469,0x1f3fd,0x200d,0x1f9af};
unsigned int emoji1351[] = {0x1f469,0x1f3fd,0x200d,0x1f9b0};
unsigned int emoji1352[] = {0x1f469,0x1f3fd,0x200d,0x1f9b1};
unsigned int emoji1353[] = {0x1f469,0x1f3fd,0x200d,0x1f9b2};
unsigned int emoji1354[] = {0x1f469,0x1f3fd,0x200d,0x1f9b3};
unsigned int emoji1355[] = {0x1f469,0x1f3fd,0x200d,0x1f9bc};
unsigned int emoji1356[] = {0x1f469,0x1f3fd,0x200d,0x1f9bd};
unsigned int emoji1357[] = {0x1f469,0x1f3fd,0x200d,0x1f33e};
unsigned int emoji1358[] = {0x1f469,0x1f3fd,0x200d,0x1f37c};
unsigned int emoji1359[] = {0x1f469,0x1f3fd,0x200d,0x1f52c};
unsigned int emoji1360[] = {0x1f469,0x1f3fd,0x200d,0x1f91d,0x200d,0x1f468,0x1f3fb};
unsigned int emoji1361[] = {0x1f469,0x1f3fd,0x200d,0x1f91d,0x200d,0x1f468,0x1f3fc};
unsigned int emoji1362[] = {0x1f469,0x1f3fd,0x200d,0x1f91d,0x200d,0x1f468,0x1f3fe};
unsigned int emoji1363[] = {0x1f469,0x1f3fd,0x200d,0x1f91d,0x200d,0x1f468,0x1f3ff};
unsigned int emoji1364[] = {0x1f469,0x1f3fd,0x200d,0x1f91d,0x200d,0x1f469,0x1f3fb};
unsigned int emoji1365[] = {0x1f469,0x1f3fd,0x200d,0x1f91d,0x200d,0x1f469,0x1f3fc};
unsigned int emoji1366[] = {0x1f469,0x1f3fd,0x200d,0x1f91d,0x200d,0x1f469,0x1f3fe};
unsigned int emoji1367[] = {0x1f469,0x1f3fd,0x200d,0x1f91d,0x200d,0x1f469,0x1f3ff};
unsigned int emoji1368[] = {0x1f469,0x1f3fd,0x200d,0x1f373};
unsigned int emoji1369[] = {0x1f469,0x1f3fd,0x200d,0x1f384};
unsigned int emoji1370[] = {0x1f469,0x1f3fd,0x200d,0x1f393};
unsigned int emoji1371[] = {0x1f469,0x1f3fd,0x200d,0x1f527};
unsigned int emoji1372[] = {0x1f469,0x1f3fd,0x200d,0x1f680};
unsigned int emoji1373[] = {0x1f469,0x1f3fd,0x200d,0x1f692};
unsigned int emoji1374[] = {0x1f469,0x1f3fd,0x200d,0x2695,0xfe0f};
unsigned int emoji1375[] = {0x1f469,0x1f3fd,0x200d,0x2696,0xfe0f};
unsigned int emoji1376[] = {0x1f469,0x1f3fd,0x200d,0x2708,0xfe0f};
unsigned int emoji1377[] = {0x1f469,0x1f3fe};
unsigned int emoji1378[] = {0x1f469,0x1f3fe,0x200d,0x1f3a4};
unsigned int emoji1379[] = {0x1f469,0x1f3fe,0x200d,0x1f3a8};
unsigned int emoji1380[] = {0x1f469,0x1f3fe,0x200d,0x1f3eb};
unsigned int emoji1381[] = {0x1f469,0x1f3fe,0x200d,0x1f3ed};
unsigned int emoji1382[] = {0x1f469,0x1f3fe,0x200d,0x1f4bb};
unsigned int emoji1383[] = {0x1f469,0x1f3fe,0x200d,0x1f4bc};
unsigned int emoji1384[] = {0x1f469,0x1f3fe,0x200d,0x1f9af};
unsigned int emoji1385[] = {0x1f469,0x1f3fe,0x200d,0x1f9b0};
unsigned int emoji1386[] = {0x1f469,0x1f3fe,0x200d,0x1f9b1};
unsigned int emoji1387[] = {0x1f469,0x1f3fe,0x200d,0x1f9b2};
unsigned int emoji1388[] = {0x1f469,0x1f3fe,0x200d,0x1f9b3};
unsigned int emoji1389[] = {0x1f469,0x1f3fe,0x200d,0x1f9bc};
unsigned int emoji1390[] = {0x1f469,0x1f3fe,0x200d,0x1f9bd};
unsigned int emoji1391[] = {0x1f469,0x1f3fe,0x200d,0x1f33e};
unsigned int emoji1392[] = {0x1f469,0x1f3fe,0x200d,0x1f37c};
unsigned int emoji1393[] = {0x1f469,0x1f3fe,0x200d,0x1f52c};
unsigned int emoji1394[] = {0x1f469,0x1f3fe,0x200d,0x1f91d,0x200d,0x1f468,0x1f3fb};
unsigned int emoji1395[] = {0x1f469,0x1f3fe,0x200d,0x1f91d,0x200d,0x1f468,0x1f3fc};
unsigned int emoji1396[] = {0x1f469,0x1f3fe,0x200d,0x1f91d,0x200d,0x1f468,0x1f3fd};
unsigned int emoji1397[] = {0x1f469,0x1f3fe,0x200d,0x1f91d,0x200d,0x1f468,0x1f3ff};
unsigned int emoji1398[] = {0x1f469,0x1f3fe,0x200d,0x1f91d,0x200d,0x1f469,0x1f3fb};
unsigned int emoji1399[] = {0x1f469,0x1f3fe,0x200d,0x1f91d,0x200d,0x1f469,0x1f3fc};
unsigned int emoji1400[] = {0x1f469,0x1f3fe,0x200d,0x1f91d,0x200d,0x1f469,0x1f3fd};
unsigned int emoji1401[] = {0x1f469,0x1f3fe,0x200d,0x1f91d,0x200d,0x1f469,0x1f3ff};
unsigned int emoji1402[] = {0x1f469,0x1f3fe,0x200d,0x1f373};
unsigned int emoji1403[] = {0x1f469,0x1f3fe,0x200d,0x1f384};
unsigned int emoji1404[] = {0x1f469,0x1f3fe,0x200d,0x1f393};
unsigned int emoji1405[] = {0x1f469,0x1f3fe,0x200d,0x1f527};
unsigned int emoji1406[] = {0x1f469,0x1f3fe,0x200d,0x1f680};
unsigned int emoji1407[] = {0x1f469,0x1f3fe,0x200d,0x1f692};
unsigned int emoji1408[] = {0x1f469,0x1f3fe,0x200d,0x2695,0xfe0f};
unsigned int emoji1409[] = {0x1f469,0x1f3fe,0x200d,0x2696,0xfe0f};
unsigned int emoji1410[] = {0x1f469,0x1f3fe,0x200d,0x2708,0xfe0f};
unsigned int emoji1411[] = {0x1f469,0x1f3ff};
unsigned int emoji1412[] = {0x1f469,0x1f3ff,0x200d,0x1f3a4};
unsigned int emoji1413[] = {0x1f469,0x1f3ff,0x200d,0x1f3a8};
unsigned int emoji1414[] = {0x1f469,0x1f3ff,0x200d,0x1f3eb};
unsigned int emoji1415[] = {0x1f469,0x1f3ff,0x200d,0x1f3ed};
unsigned int emoji1416[] = {0x1f469,0x1f3ff,0x200d,0x1f4bb};
unsigned int emoji1417[] = {0x1f469,0x1f3ff,0x200d,0x1f4bc};
unsigned int emoji1418[] = {0x1f469,0x1f3ff,0x200d,0x1f9af};
unsigned int emoji1419[] = {0x1f469,0x1f3ff,0x200d,0x1f9b0};
unsigned int emoji1420[] = {0x1f469,0x1f3ff,0x200d,0x1f9b1};
unsigned int emoji1421[] = {0x1f469,0x1f3ff,0x200d,0x1f9b2};
unsigned int emoji1422[] = {0x1f469,0x1f3ff,0x200d,0x1f9b3};
unsigned int emoji1423[] = {0x1f469,0x1f3ff,0x200d,0x1f9bc};
unsigned int emoji1424[] = {0x1f469,0x1f3ff,0x200d,0x1f9bd};
unsigned int emoji1425[] = {0x1f469,0x1f3ff,0x200d,0x1f33e};
unsigned int emoji1426[] = {0x1f469,0x1f3ff,0x200d,0x1f37c};
unsigned int emoji1427[] = {0x1f469,0x1f3ff,0x200d,0x1f52c};
unsigned int emoji1428[] = {0x1f469,0x1f3ff,0x200d,0x1f91d,0x200d,0x1f468,0x1f3fb};
unsigned int emoji1429[] = {0x1f469,0x1f3ff,0x200d,0x1f91d,0x200d,0x1f468,0x1f3fc};
unsigned int emoji1430[] = {0x1f469,0x1f3ff,0x200d,0x1f91d,0x200d,0x1f468,0x1f3fd};
unsigned int emoji1431[] = {0x1f469,0x1f3ff,0x200d,0x1f91d,0x200d,0x1f468,0x1f3fe};
unsigned int emoji1432[] = {0x1f469,0x1f3ff,0x200d,0x1f91d,0x200d,0x1f469,0x1f3fb};
unsigned int emoji1433[] = {0x1f469,0x1f3ff,0x200d,0x1f91d,0x200d,0x1f469,0x1f3fc};
unsigned int emoji1434[] = {0x1f469,0x1f3ff,0x200d,0x1f91d,0x200d,0x1f469,0x1f3fd};
unsigned int emoji1435[] = {0x1f469,0x1f3ff,0x200d,0x1f91d,0x200d,0x1f469,0x1f3fe};
unsigned int emoji1436[] = {0x1f469,0x1f3ff,0x200d,0x1f373};
unsigned int emoji1437[] = {0x1f469,0x1f3ff,0x200d,0x1f384};
unsigned int emoji1438[] = {0x1f469,0x1f3ff,0x200d,0x1f393};
unsigned int emoji1439[] = {0x1f469,0x1f3ff,0x200d,0x1f527};
unsigned int emoji1440[] = {0x1f469,0x1f3ff,0x200d,0x1f680};
unsigned int emoji1441[] = {0x1f469,0x1f3ff,0x200d,0x1f692};
unsigned int emoji1442[] = {0x1f469,0x1f3ff,0x200d,0x2695,0xfe0f};
unsigned int emoji1443[] = {0x1f469,0x1f3ff,0x200d,0x2696,0xfe0f};
unsigned int emoji1444[] = {0x1f469,0x1f3ff,0x200d,0x2708,0xfe0f};
unsigned int emoji1445[] = {0x1f469,0x200d,0x1f3a4};
unsigned int emoji1446[] = {0x1f469,0x200d,0x1f3a8};
unsigned int emoji1447[] = {0x1f469,0x200d,0x1f3eb};
unsigned int emoji1448[] = {0x1f469,0x200d,0x1f3ed};
unsigned int emoji1449[] = {0x1f469,0x200d,0x1f4bb};
unsigned int emoji1450[] = {0x1f469,0x200d,0x1f4bc};
unsigned int emoji1451[] = {0x1f469,0x200d,0x1f9af};
unsigned int emoji1452[] = {0x1f469,0x200d,0x1f9b0};
unsigned int emoji1453[] = {0x1f469,0x200d,0x1f9b1};
unsigned int emoji1454[] = {0x1f469,0x200d,0x1f9b2};
unsigned int emoji1455[] = {0x1f469,0x200d,0x1f9b3};
unsigned int emoji1456[] = {0x1f469,0x200d,0x1f9bc};
unsigned int emoji1457[] = {0x1f469,0x200d,0x1f9bd};
unsigned int emoji1458[] = {0x1f469,0x200d,0x1f33e};
unsigned int emoji1459[] = {0x1f469,0x200d,0x1f37c};
unsigned int emoji1460[] = {0x1f469,0x200d,0x1f52c};
unsigned int emoji1461[] = {0x1f469,0x200d,0x1f373};
unsigned int emoji1462[] = {0x1f469,0x200d,0x1f384};
unsigned int emoji1463[] = {0x1f469,0x200d,0x1f393};
unsigned int emoji1464[] = {0x1f469,0x200d,0x1f466};
unsigned int emoji1465[] = {0x1f469,0x200d,0x1f466,0x200d,0x1f466};
unsigned int emoji1466[] = {0x1f469,0x200d,0x1f467};
unsigned int emoji1467[] = {0x1f469,0x200d,0x1f467,0x200d,0x1f466};
unsigned int emoji1468[] = {0x1f469,0x200d,0x1f467,0x200d,0x1f467};
unsigned int emoji1469[] = {0x1f469,0x200d,0x1f469,0x200d,0x1f466};
unsigned int emoji1470[] = {0x1f469,0x200d,0x1f469,0x200d,0x1f466,0x200d,0x1f466};
unsigned int emoji1471[] = {0x1f469,0x200d,0x1f469,0x200d,0x1f467};
unsigned int emoji1472[] = {0x1f469,0x200d,0x1f469,0x200d,0x1f467,0x200d,0x1f466};
unsigned int emoji1473[] = {0x1f469,0x200d,0x1f469,0x200d,0x1f467,0x200d,0x1f467};
unsigned int emoji1474[] = {0x1f469,0x200d,0x1f527};
unsigned int emoji1475[] = {0x1f469,0x200d,0x1f680};
unsigned int emoji1476[] = {0x1f469,0x200d,0x1f692};
unsigned int emoji1477[] = {0x1f469,0x200d,0x2695,0xfe0f};
unsigned int emoji1478[] = {0x1f469,0x200d,0x2696,0xfe0f};
unsigned int emoji1479[] = {0x1f469,0x200d,0x2708,0xfe0f};
unsigned int emoji1480[] = {0x1f469,0x200d,0x2764,0xfe0f,0x200d,0x1f48b,0x200d,0x1f468};
unsigned int emoji1481[] = {0x1f469,0x200d,0x2764,0xfe0f,0x200d,0x1f48b,0x200d,0x1f469};
unsigned int emoji1482[] = {0x1f469,0x200d,0x2764,0xfe0f,0x200d,0x1f468};
unsigned int emoji1483[] = {0x1f469,0x200d,0x2764,0xfe0f,0x200d,0x1f469};
unsigned int emoji1484[] = {0x1f46a};
unsigned int emoji1485[] = {0x1f46b};
unsigned int emoji1486[] = {0x1f46b,0x1f3fb};
unsigned int emoji1487[] = {0x1f46b,0x1f3fc};
unsigned int emoji1488[] = {0x1f46b,0x1f3fd};
unsigned int emoji1489[] = {0x1f46b,0x1f3fe};
unsigned int emoji1490[] = {0x1f46b,0x1f3ff};
unsigned int emoji1491[] = {0x1f46c};
unsigned int emoji1492[] = {0x1f46c,0x1f3fb};
unsigned int emoji1493[] = {0x1f46c,0x1f3fc};
unsigned int emoji1494[] = {0x1f46c,0x1f3fd};
unsigned int emoji1495[] = {0x1f46c,0x1f3fe};
unsigned int emoji1496[] = {0x1f46c,0x1f3ff};
unsigned int emoji1497[] = {0x1f46d};
unsigned int emoji1498[] = {0x1f46d,0x1f3fb};
unsigned int emoji1499[] = {0x1f46d,0x1f3fc};
unsigned int emoji1500[] = {0x1f46d,0x1f3fd};
unsigned int emoji1501[] = {0x1f46d,0x1f3fe};
unsigned int emoji1502[] = {0x1f46d,0x1f3ff};
unsigned int emoji1503[] = {0x1f46e};
unsigned int emoji1504[] = {0x1f46e,0x1f3fb};
unsigned int emoji1505[] = {0x1f46e,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji1506[] = {0x1f46e,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji1507[] = {0x1f46e,0x1f3fc};
unsigned int emoji1508[] = {0x1f46e,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji1509[] = {0x1f46e,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji1510[] = {0x1f46e,0x1f3fd};
unsigned int emoji1511[] = {0x1f46e,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji1512[] = {0x1f46e,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji1513[] = {0x1f46e,0x1f3fe};
unsigned int emoji1514[] = {0x1f46e,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji1515[] = {0x1f46e,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji1516[] = {0x1f46e,0x1f3ff};
unsigned int emoji1517[] = {0x1f46e,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji1518[] = {0x1f46e,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji1519[] = {0x1f46e,0x200d,0x2640,0xfe0f};
unsigned int emoji1520[] = {0x1f46e,0x200d,0x2642,0xfe0f};
unsigned int emoji1521[] = {0x1f46f};
unsigned int emoji1522[] = {0x1f46f,0x200d,0x2640,0xfe0f};
unsigned int emoji1523[] = {0x1f46f,0x200d,0x2642,0xfe0f};
unsigned int emoji1524[] = {0x1f470};
unsigned int emoji1525[] = {0x1f470,0x1f3fb};
unsigned int emoji1526[] = {0x1f470,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji1527[] = {0x1f470,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji1528[] = {0x1f470,0x1f3fc};
unsigned int emoji1529[] = {0x1f470,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji1530[] = {0x1f470,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji1531[] = {0x1f470,0x1f3fd};
unsigned int emoji1532[] = {0x1f470,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji1533[] = {0x1f470,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji1534[] = {0x1f470,0x1f3fe};
unsigned int emoji1535[] = {0x1f470,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji1536[] = {0x1f470,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji1537[] = {0x1f470,0x1f3ff};
unsigned int emoji1538[] = {0x1f470,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji1539[] = {0x1f470,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji1540[] = {0x1f470,0x200d,0x2640,0xfe0f};
unsigned int emoji1541[] = {0x1f470,0x200d,0x2642,0xfe0f};
unsigned int emoji1542[] = {0x1f471};
unsigned int emoji1543[] = {0x1f471,0x1f3fb};
unsigned int emoji1544[] = {0x1f471,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji1545[] = {0x1f471,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji1546[] = {0x1f471,0x1f3fc};
unsigned int emoji1547[] = {0x1f471,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji1548[] = {0x1f471,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji1549[] = {0x1f471,0x1f3fd};
unsigned int emoji1550[] = {0x1f471,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji1551[] = {0x1f471,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji1552[] = {0x1f471,0x1f3fe};
unsigned int emoji1553[] = {0x1f471,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji1554[] = {0x1f471,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji1555[] = {0x1f471,0x1f3ff};
unsigned int emoji1556[] = {0x1f471,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji1557[] = {0x1f471,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji1558[] = {0x1f471,0x200d,0x2640,0xfe0f};
unsigned int emoji1559[] = {0x1f471,0x200d,0x2642,0xfe0f};
unsigned int emoji1560[] = {0x1f472};
unsigned int emoji1561[] = {0x1f472,0x1f3fb};
unsigned int emoji1562[] = {0x1f472,0x1f3fc};
unsigned int emoji1563[] = {0x1f472,0x1f3fd};
unsigned int emoji1564[] = {0x1f472,0x1f3fe};
unsigned int emoji1565[] = {0x1f472,0x1f3ff};
unsigned int emoji1566[] = {0x1f473};
unsigned int emoji1567[] = {0x1f473,0x1f3fb};
unsigned int emoji1568[] = {0x1f473,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji1569[] = {0x1f473,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji1570[] = {0x1f473,0x1f3fc};
unsigned int emoji1571[] = {0x1f473,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji1572[] = {0x1f473,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji1573[] = {0x1f473,0x1f3fd};
unsigned int emoji1574[] = {0x1f473,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji1575[] = {0x1f473,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji1576[] = {0x1f473,0x1f3fe};
unsigned int emoji1577[] = {0x1f473,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji1578[] = {0x1f473,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji1579[] = {0x1f473,0x1f3ff};
unsigned int emoji1580[] = {0x1f473,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji1581[] = {0x1f473,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji1582[] = {0x1f473,0x200d,0x2640,0xfe0f};
unsigned int emoji1583[] = {0x1f473,0x200d,0x2642,0xfe0f};
unsigned int emoji1584[] = {0x1f474};
unsigned int emoji1585[] = {0x1f474,0x1f3fb};
unsigned int emoji1586[] = {0x1f474,0x1f3fc};
unsigned int emoji1587[] = {0x1f474,0x1f3fd};
unsigned int emoji1588[] = {0x1f474,0x1f3fe};
unsigned int emoji1589[] = {0x1f474,0x1f3ff};
unsigned int emoji1590[] = {0x1f475};
unsigned int emoji1591[] = {0x1f475,0x1f3fb};
unsigned int emoji1592[] = {0x1f475,0x1f3fc};
unsigned int emoji1593[] = {0x1f475,0x1f3fd};
unsigned int emoji1594[] = {0x1f475,0x1f3fe};
unsigned int emoji1595[] = {0x1f475,0x1f3ff};
unsigned int emoji1596[] = {0x1f476};
unsigned int emoji1597[] = {0x1f476,0x1f3fb};
unsigned int emoji1598[] = {0x1f476,0x1f3fc};
unsigned int emoji1599[] = {0x1f476,0x1f3fd};
unsigned int emoji1600[] = {0x1f476,0x1f3fe};
unsigned int emoji1601[] = {0x1f476,0x1f3ff};
unsigned int emoji1602[] = {0x1f477};
unsigned int emoji1603[] = {0x1f477,0x1f3fb};
unsigned int emoji1604[] = {0x1f477,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji1605[] = {0x1f477,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji1606[] = {0x1f477,0x1f3fc};
unsigned int emoji1607[] = {0x1f477,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji1608[] = {0x1f477,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji1609[] = {0x1f477,0x1f3fd};
unsigned int emoji1610[] = {0x1f477,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji1611[] = {0x1f477,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji1612[] = {0x1f477,0x1f3fe};
unsigned int emoji1613[] = {0x1f477,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji1614[] = {0x1f477,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji1615[] = {0x1f477,0x1f3ff};
unsigned int emoji1616[] = {0x1f477,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji1617[] = {0x1f477,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji1618[] = {0x1f477,0x200d,0x2640,0xfe0f};
unsigned int emoji1619[] = {0x1f477,0x200d,0x2642,0xfe0f};
unsigned int emoji1620[] = {0x1f478};
unsigned int emoji1621[] = {0x1f478,0x1f3fb};
unsigned int emoji1622[] = {0x1f478,0x1f3fc};
unsigned int emoji1623[] = {0x1f478,0x1f3fd};
unsigned int emoji1624[] = {0x1f478,0x1f3fe};
unsigned int emoji1625[] = {0x1f478,0x1f3ff};
unsigned int emoji1626[] = {0x1f479};
unsigned int emoji1627[] = {0x1f47a};
unsigned int emoji1628[] = {0x1f47b};
unsigned int emoji1629[] = {0x1f47c};
unsigned int emoji1630[] = {0x1f47c,0x1f3fb};
unsigned int emoji1631[] = {0x1f47c,0x1f3fc};
unsigned int emoji1632[] = {0x1f47c,0x1f3fd};
unsigned int emoji1633[] = {0x1f47c,0x1f3fe};
unsigned int emoji1634[] = {0x1f47c,0x1f3ff};
unsigned int emoji1635[] = {0x1f47d};
unsigned int emoji1636[] = {0x1f47e};
unsigned int emoji1637[] = {0x1f47f};
unsigned int emoji1638[] = {0x1f480};
unsigned int emoji1639[] = {0x1f481};
unsigned int emoji1640[] = {0x1f481,0x1f3fb};
unsigned int emoji1641[] = {0x1f481,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji1642[] = {0x1f481,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji1643[] = {0x1f481,0x1f3fc};
unsigned int emoji1644[] = {0x1f481,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji1645[] = {0x1f481,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji1646[] = {0x1f481,0x1f3fd};
unsigned int emoji1647[] = {0x1f481,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji1648[] = {0x1f481,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji1649[] = {0x1f481,0x1f3fe};
unsigned int emoji1650[] = {0x1f481,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji1651[] = {0x1f481,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji1652[] = {0x1f481,0x1f3ff};
unsigned int emoji1653[] = {0x1f481,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji1654[] = {0x1f481,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji1655[] = {0x1f481,0x200d,0x2640,0xfe0f};
unsigned int emoji1656[] = {0x1f481,0x200d,0x2642,0xfe0f};
unsigned int emoji1657[] = {0x1f482};
unsigned int emoji1658[] = {0x1f482,0x1f3fb};
unsigned int emoji1659[] = {0x1f482,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji1660[] = {0x1f482,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji1661[] = {0x1f482,0x1f3fc};
unsigned int emoji1662[] = {0x1f482,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji1663[] = {0x1f482,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji1664[] = {0x1f482,0x1f3fd};
unsigned int emoji1665[] = {0x1f482,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji1666[] = {0x1f482,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji1667[] = {0x1f482,0x1f3fe};
unsigned int emoji1668[] = {0x1f482,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji1669[] = {0x1f482,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji1670[] = {0x1f482,0x1f3ff};
unsigned int emoji1671[] = {0x1f482,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji1672[] = {0x1f482,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji1673[] = {0x1f482,0x200d,0x2640,0xfe0f};
unsigned int emoji1674[] = {0x1f482,0x200d,0x2642,0xfe0f};
unsigned int emoji1675[] = {0x1f483};
unsigned int emoji1676[] = {0x1f483,0x1f3fb};
unsigned int emoji1677[] = {0x1f483,0x1f3fc};
unsigned int emoji1678[] = {0x1f483,0x1f3fd};
unsigned int emoji1679[] = {0x1f483,0x1f3fe};
unsigned int emoji1680[] = {0x1f483,0x1f3ff};
unsigned int emoji1681[] = {0x1f484};
unsigned int emoji1682[] = {0x1f485};
unsigned int emoji1683[] = {0x1f485,0x1f3fb};
unsigned int emoji1684[] = {0x1f485,0x1f3fc};
unsigned int emoji1685[] = {0x1f485,0x1f3fd};
unsigned int emoji1686[] = {0x1f485,0x1f3fe};
unsigned int emoji1687[] = {0x1f485,0x1f3ff};
unsigned int emoji1688[] = {0x1f486};
unsigned int emoji1689[] = {0x1f486,0x1f3fb};
unsigned int emoji1690[] = {0x1f486,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji1691[] = {0x1f486,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji1692[] = {0x1f486,0x1f3fc};
unsigned int emoji1693[] = {0x1f486,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji1694[] = {0x1f486,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji1695[] = {0x1f486,0x1f3fd};
unsigned int emoji1696[] = {0x1f486,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji1697[] = {0x1f486,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji1698[] = {0x1f486,0x1f3fe};
unsigned int emoji1699[] = {0x1f486,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji1700[] = {0x1f486,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji1701[] = {0x1f486,0x1f3ff};
unsigned int emoji1702[] = {0x1f486,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji1703[] = {0x1f486,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji1704[] = {0x1f486,0x200d,0x2640,0xfe0f};
unsigned int emoji1705[] = {0x1f486,0x200d,0x2642,0xfe0f};
unsigned int emoji1706[] = {0x1f487};
unsigned int emoji1707[] = {0x1f487,0x1f3fb};
unsigned int emoji1708[] = {0x1f487,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji1709[] = {0x1f487,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji1710[] = {0x1f487,0x1f3fc};
unsigned int emoji1711[] = {0x1f487,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji1712[] = {0x1f487,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji1713[] = {0x1f487,0x1f3fd};
unsigned int emoji1714[] = {0x1f487,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji1715[] = {0x1f487,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji1716[] = {0x1f487,0x1f3fe};
unsigned int emoji1717[] = {0x1f487,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji1718[] = {0x1f487,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji1719[] = {0x1f487,0x1f3ff};
unsigned int emoji1720[] = {0x1f487,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji1721[] = {0x1f487,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji1722[] = {0x1f487,0x200d,0x2640,0xfe0f};
unsigned int emoji1723[] = {0x1f487,0x200d,0x2642,0xfe0f};
unsigned int emoji1724[] = {0x1f488};
unsigned int emoji1725[] = {0x1f489};
unsigned int emoji1726[] = {0x1f48a};
unsigned int emoji1727[] = {0x1f48b};
unsigned int emoji1728[] = {0x1f48c};
unsigned int emoji1729[] = {0x1f48d};
unsigned int emoji1730[] = {0x1f48e};
unsigned int emoji1731[] = {0x1f48f};
unsigned int emoji1732[] = {0x1f490};
unsigned int emoji1733[] = {0x1f491};
unsigned int emoji1734[] = {0x1f492};
unsigned int emoji1735[] = {0x1f493};
unsigned int emoji1736[] = {0x1f494};
unsigned int emoji1737[] = {0x1f495};
unsigned int emoji1738[] = {0x1f496};
unsigned int emoji1739[] = {0x1f497};
unsigned int emoji1740[] = {0x1f498};
unsigned int emoji1741[] = {0x1f499};
unsigned int emoji1742[] = {0x1f49a};
unsigned int emoji1743[] = {0x1f49b};
unsigned int emoji1744[] = {0x1f49c};
unsigned int emoji1745[] = {0x1f49d};
unsigned int emoji1746[] = {0x1f49e};
unsigned int emoji1747[] = {0x1f49f};
unsigned int emoji1748[] = {0x1f4a0};
unsigned int emoji1749[] = {0x1f4a1};
unsigned int emoji1750[] = {0x1f4a2};
unsigned int emoji1751[] = {0x1f4a3};
unsigned int emoji1752[] = {0x1f4a4};
unsigned int emoji1753[] = {0x1f4a5};
unsigned int emoji1754[] = {0x1f4a6};
unsigned int emoji1755[] = {0x1f4a7};
unsigned int emoji1756[] = {0x1f4a8};
unsigned int emoji1757[] = {0x1f4a9};
unsigned int emoji1758[] = {0x1f4aa};
unsigned int emoji1759[] = {0x1f4aa,0x1f3fb};
unsigned int emoji1760[] = {0x1f4aa,0x1f3fc};
unsigned int emoji1761[] = {0x1f4aa,0x1f3fd};
unsigned int emoji1762[] = {0x1f4aa,0x1f3fe};
unsigned int emoji1763[] = {0x1f4aa,0x1f3ff};
unsigned int emoji1764[] = {0x1f4ab};
unsigned int emoji1765[] = {0x1f4ac};
unsigned int emoji1766[] = {0x1f4ad};
unsigned int emoji1767[] = {0x1f4ae};
unsigned int emoji1768[] = {0x1f4af};
unsigned int emoji1769[] = {0x1f4b0};
unsigned int emoji1770[] = {0x1f4b1};
unsigned int emoji1771[] = {0x1f4b2};
unsigned int emoji1772[] = {0x1f4b3};
unsigned int emoji1773[] = {0x1f4b4};
unsigned int emoji1774[] = {0x1f4b5};
unsigned int emoji1775[] = {0x1f4b6};
unsigned int emoji1776[] = {0x1f4b7};
unsigned int emoji1777[] = {0x1f4b8};
unsigned int emoji1778[] = {0x1f4b9};
unsigned int emoji1779[] = {0x1f4ba};
unsigned int emoji1780[] = {0x1f4bb};
unsigned int emoji1781[] = {0x1f4bc};
unsigned int emoji1782[] = {0x1f4bd};
unsigned int emoji1783[] = {0x1f4be};
unsigned int emoji1784[] = {0x1f4bf};
unsigned int emoji1785[] = {0x1f4c0};
unsigned int emoji1786[] = {0x1f4c1};
unsigned int emoji1787[] = {0x1f4c2};
unsigned int emoji1788[] = {0x1f4c3};
unsigned int emoji1789[] = {0x1f4c4};
unsigned int emoji1790[] = {0x1f4c5};
unsigned int emoji1791[] = {0x1f4c6};
unsigned int emoji1792[] = {0x1f4c7};
unsigned int emoji1793[] = {0x1f4c8};
unsigned int emoji1794[] = {0x1f4c9};
unsigned int emoji1795[] = {0x1f4ca};
unsigned int emoji1796[] = {0x1f4cb};
unsigned int emoji1797[] = {0x1f4cc};
unsigned int emoji1798[] = {0x1f4cd};
unsigned int emoji1799[] = {0x1f4ce};
unsigned int emoji1800[] = {0x1f4cf};
unsigned int emoji1801[] = {0x1f4d0};
unsigned int emoji1802[] = {0x1f4d1};
unsigned int emoji1803[] = {0x1f4d2};
unsigned int emoji1804[] = {0x1f4d3};
unsigned int emoji1805[] = {0x1f4d4};
unsigned int emoji1806[] = {0x1f4d5};
unsigned int emoji1807[] = {0x1f4d6};
unsigned int emoji1808[] = {0x1f4d7};
unsigned int emoji1809[] = {0x1f4d8};
unsigned int emoji1810[] = {0x1f4d9};
unsigned int emoji1811[] = {0x1f4da};
unsigned int emoji1812[] = {0x1f4db};
unsigned int emoji1813[] = {0x1f4dc};
unsigned int emoji1814[] = {0x1f4dd};
unsigned int emoji1815[] = {0x1f4de};
unsigned int emoji1816[] = {0x1f4df};
unsigned int emoji1817[] = {0x1f4e0};
unsigned int emoji1818[] = {0x1f4e1};
unsigned int emoji1819[] = {0x1f4e2};
unsigned int emoji1820[] = {0x1f4e3};
unsigned int emoji1821[] = {0x1f4e4};
unsigned int emoji1822[] = {0x1f4e5};
unsigned int emoji1823[] = {0x1f4e6};
unsigned int emoji1824[] = {0x1f4e7};
unsigned int emoji1825[] = {0x1f4e8};
unsigned int emoji1826[] = {0x1f4e9};
unsigned int emoji1827[] = {0x1f4ea};
unsigned int emoji1828[] = {0x1f4eb};
unsigned int emoji1829[] = {0x1f4ec};
unsigned int emoji1830[] = {0x1f4ed};
unsigned int emoji1831[] = {0x1f4ee};
unsigned int emoji1832[] = {0x1f4ef};
unsigned int emoji1833[] = {0x1f4f0};
unsigned int emoji1834[] = {0x1f4f1};
unsigned int emoji1835[] = {0x1f4f2};
unsigned int emoji1836[] = {0x1f4f3};
unsigned int emoji1837[] = {0x1f4f4};
unsigned int emoji1838[] = {0x1f4f5};
unsigned int emoji1839[] = {0x1f4f6};
unsigned int emoji1840[] = {0x1f4f7};
unsigned int emoji1841[] = {0x1f4f8};
unsigned int emoji1842[] = {0x1f4f9};
unsigned int emoji1843[] = {0x1f4fa};
unsigned int emoji1844[] = {0x1f4fb};
unsigned int emoji1845[] = {0x1f4fc};
unsigned int emoji1846[] = {0x1f4fd};
unsigned int emoji1847[] = {0x1f4ff};
unsigned int emoji1848[] = {0x1f500};
unsigned int emoji1849[] = {0x1f501};
unsigned int emoji1850[] = {0x1f502};
unsigned int emoji1851[] = {0x1f503};
unsigned int emoji1852[] = {0x1f504};
unsigned int emoji1853[] = {0x1f505};
unsigned int emoji1854[] = {0x1f506};
unsigned int emoji1855[] = {0x1f507};
unsigned int emoji1856[] = {0x1f508};
unsigned int emoji1857[] = {0x1f509};
unsigned int emoji1858[] = {0x1f50a};
unsigned int emoji1859[] = {0x1f50b};
unsigned int emoji1860[] = {0x1f50c};
unsigned int emoji1861[] = {0x1f50d};
unsigned int emoji1862[] = {0x1f50e};
unsigned int emoji1863[] = {0x1f50f};
unsigned int emoji1864[] = {0x1f510};
unsigned int emoji1865[] = {0x1f511};
unsigned int emoji1866[] = {0x1f512};
unsigned int emoji1867[] = {0x1f513};
unsigned int emoji1868[] = {0x1f514};
unsigned int emoji1869[] = {0x1f515};
unsigned int emoji1870[] = {0x1f516};
unsigned int emoji1871[] = {0x1f517};
unsigned int emoji1872[] = {0x1f518};
unsigned int emoji1873[] = {0x1f519};
unsigned int emoji1874[] = {0x1f51a};
unsigned int emoji1875[] = {0x1f51b};
unsigned int emoji1876[] = {0x1f51c};
unsigned int emoji1877[] = {0x1f51d};
unsigned int emoji1878[] = {0x1f51e};
unsigned int emoji1879[] = {0x1f51f};
unsigned int emoji1880[] = {0x1f520};
unsigned int emoji1881[] = {0x1f521};
unsigned int emoji1882[] = {0x1f522};
unsigned int emoji1883[] = {0x1f523};
unsigned int emoji1884[] = {0x1f524};
unsigned int emoji1885[] = {0x1f525};
unsigned int emoji1886[] = {0x1f526};
unsigned int emoji1887[] = {0x1f527};
unsigned int emoji1888[] = {0x1f528};
unsigned int emoji1889[] = {0x1f529};
unsigned int emoji1890[] = {0x1f52a};
unsigned int emoji1891[] = {0x1f52b};
unsigned int emoji1892[] = {0x1f52c};
unsigned int emoji1893[] = {0x1f52d};
unsigned int emoji1894[] = {0x1f52e};
unsigned int emoji1895[] = {0x1f52f};
unsigned int emoji1896[] = {0x1f530};
unsigned int emoji1897[] = {0x1f531};
unsigned int emoji1898[] = {0x1f532};
unsigned int emoji1899[] = {0x1f533};
unsigned int emoji1900[] = {0x1f534};
unsigned int emoji1901[] = {0x1f535};
unsigned int emoji1902[] = {0x1f536};
unsigned int emoji1903[] = {0x1f537};
unsigned int emoji1904[] = {0x1f538};
unsigned int emoji1905[] = {0x1f539};
unsigned int emoji1906[] = {0x1f53a};
unsigned int emoji1907[] = {0x1f53b};
unsigned int emoji1908[] = {0x1f53c};
unsigned int emoji1909[] = {0x1f53d};
unsigned int emoji1910[] = {0x1f549};
unsigned int emoji1911[] = {0x1f54a};
unsigned int emoji1912[] = {0x1f54b};
unsigned int emoji1913[] = {0x1f54c};
unsigned int emoji1914[] = {0x1f54d};
unsigned int emoji1915[] = {0x1f54e};
unsigned int emoji1916[] = {0x1f550};
unsigned int emoji1917[] = {0x1f551};
unsigned int emoji1918[] = {0x1f552};
unsigned int emoji1919[] = {0x1f553};
unsigned int emoji1920[] = {0x1f554};
unsigned int emoji1921[] = {0x1f555};
unsigned int emoji1922[] = {0x1f556};
unsigned int emoji1923[] = {0x1f557};
unsigned int emoji1924[] = {0x1f558};
unsigned int emoji1925[] = {0x1f559};
unsigned int emoji1926[] = {0x1f55a};
unsigned int emoji1927[] = {0x1f55b};
unsigned int emoji1928[] = {0x1f55c};
unsigned int emoji1929[] = {0x1f55d};
unsigned int emoji1930[] = {0x1f55e};
unsigned int emoji1931[] = {0x1f55f};
unsigned int emoji1932[] = {0x1f560};
unsigned int emoji1933[] = {0x1f561};
unsigned int emoji1934[] = {0x1f562};
unsigned int emoji1935[] = {0x1f563};
unsigned int emoji1936[] = {0x1f564};
unsigned int emoji1937[] = {0x1f565};
unsigned int emoji1938[] = {0x1f566};
unsigned int emoji1939[] = {0x1f567};
unsigned int emoji1940[] = {0x1f56f};
unsigned int emoji1941[] = {0x1f570};
unsigned int emoji1942[] = {0x1f573};
unsigned int emoji1943[] = {0x1f574};
unsigned int emoji1944[] = {0x1f574,0x1f3fb};
unsigned int emoji1945[] = {0x1f574,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji1946[] = {0x1f574,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji1947[] = {0x1f574,0x1f3fc};
unsigned int emoji1948[] = {0x1f574,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji1949[] = {0x1f574,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji1950[] = {0x1f574,0x1f3fd};
unsigned int emoji1951[] = {0x1f574,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji1952[] = {0x1f574,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji1953[] = {0x1f574,0x1f3fe};
unsigned int emoji1954[] = {0x1f574,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji1955[] = {0x1f574,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji1956[] = {0x1f574,0x1f3ff};
unsigned int emoji1957[] = {0x1f574,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji1958[] = {0x1f574,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji1959[] = {0x1f574,0xfe0f,0x200d,0x2640,0xfe0f};
unsigned int emoji1960[] = {0x1f574,0xfe0f,0x200d,0x2642,0xfe0f};
unsigned int emoji1961[] = {0x1f575};
unsigned int emoji1962[] = {0x1f575,0x1f3fb};
unsigned int emoji1963[] = {0x1f575,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji1964[] = {0x1f575,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji1965[] = {0x1f575,0x1f3fc};
unsigned int emoji1966[] = {0x1f575,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji1967[] = {0x1f575,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji1968[] = {0x1f575,0x1f3fd};
unsigned int emoji1969[] = {0x1f575,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji1970[] = {0x1f575,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji1971[] = {0x1f575,0x1f3fe};
unsigned int emoji1972[] = {0x1f575,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji1973[] = {0x1f575,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji1974[] = {0x1f575,0x1f3ff};
unsigned int emoji1975[] = {0x1f575,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji1976[] = {0x1f575,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji1977[] = {0x1f575,0xfe0f,0x200d,0x2640,0xfe0f};
unsigned int emoji1978[] = {0x1f575,0xfe0f,0x200d,0x2642,0xfe0f};
unsigned int emoji1979[] = {0x1f576};
unsigned int emoji1980[] = {0x1f577};
unsigned int emoji1981[] = {0x1f578};
unsigned int emoji1982[] = {0x1f579};
unsigned int emoji1983[] = {0x1f57a};
unsigned int emoji1984[] = {0x1f57a,0x1f3fb};
unsigned int emoji1985[] = {0x1f57a,0x1f3fc};
unsigned int emoji1986[] = {0x1f57a,0x1f3fd};
unsigned int emoji1987[] = {0x1f57a,0x1f3fe};
unsigned int emoji1988[] = {0x1f57a,0x1f3ff};
unsigned int emoji1989[] = {0x1f587};
unsigned int emoji1990[] = {0x1f58a};
unsigned int emoji1991[] = {0x1f58b};
unsigned int emoji1992[] = {0x1f58c};
unsigned int emoji1993[] = {0x1f58d};
unsigned int emoji1994[] = {0x1f590};
unsigned int emoji1995[] = {0x1f590,0x1f3fb};
unsigned int emoji1996[] = {0x1f590,0x1f3fc};
unsigned int emoji1997[] = {0x1f590,0x1f3fd};
unsigned int emoji1998[] = {0x1f590,0x1f3fe};
unsigned int emoji1999[] = {0x1f590,0x1f3ff};
unsigned int emoji2000[] = {0x1f595};
unsigned int emoji2001[] = {0x1f595,0x1f3fb};
unsigned int emoji2002[] = {0x1f595,0x1f3fc};
unsigned int emoji2003[] = {0x1f595,0x1f3fd};
unsigned int emoji2004[] = {0x1f595,0x1f3fe};
unsigned int emoji2005[] = {0x1f595,0x1f3ff};
unsigned int emoji2006[] = {0x1f596};
unsigned int emoji2007[] = {0x1f596,0x1f3fb};
unsigned int emoji2008[] = {0x1f596,0x1f3fc};
unsigned int emoji2009[] = {0x1f596,0x1f3fd};
unsigned int emoji2010[] = {0x1f596,0x1f3fe};
unsigned int emoji2011[] = {0x1f596,0x1f3ff};
unsigned int emoji2012[] = {0x1f5a4};
unsigned int emoji2013[] = {0x1f5a5};
unsigned int emoji2014[] = {0x1f5a8};
unsigned int emoji2015[] = {0x1f5b1};
unsigned int emoji2016[] = {0x1f5b2};
unsigned int emoji2017[] = {0x1f5bc};
unsigned int emoji2018[] = {0x1f5c2};
unsigned int emoji2019[] = {0x1f5c3};
unsigned int emoji2020[] = {0x1f5c4};
unsigned int emoji2021[] = {0x1f5d1};
unsigned int emoji2022[] = {0x1f5d2};
unsigned int emoji2023[] = {0x1f5d3};
unsigned int emoji2024[] = {0x1f5dc};
unsigned int emoji2025[] = {0x1f5dd};
unsigned int emoji2026[] = {0x1f5de};
unsigned int emoji2027[] = {0x1f5e1};
unsigned int emoji2028[] = {0x1f5e3};
unsigned int emoji2029[] = {0x1f5e8};
unsigned int emoji2030[] = {0x1f5ef};
unsigned int emoji2031[] = {0x1f5f3};
unsigned int emoji2032[] = {0x1f5fa};
unsigned int emoji2033[] = {0x1f5fb};
unsigned int emoji2034[] = {0x1f5fc};
unsigned int emoji2035[] = {0x1f5fd};
unsigned int emoji2036[] = {0x1f5fe};
unsigned int emoji2037[] = {0x1f5ff};
unsigned int emoji2038[] = {0x1f600};
unsigned int emoji2039[] = {0x1f601};
unsigned int emoji2040[] = {0x1f602};
unsigned int emoji2041[] = {0x1f603};
unsigned int emoji2042[] = {0x1f604};
unsigned int emoji2043[] = {0x1f605};
unsigned int emoji2044[] = {0x1f606};
unsigned int emoji2045[] = {0x1f607};
unsigned int emoji2046[] = {0x1f608};
unsigned int emoji2047[] = {0x1f609};
unsigned int emoji2048[] = {0x1f60a};
unsigned int emoji2049[] = {0x1f60b};
unsigned int emoji2050[] = {0x1f60c};
unsigned int emoji2051[] = {0x1f60d};
unsigned int emoji2052[] = {0x1f60e};
unsigned int emoji2053[] = {0x1f60f};
unsigned int emoji2054[] = {0x1f610};
unsigned int emoji2055[] = {0x1f611};
unsigned int emoji2056[] = {0x1f612};
unsigned int emoji2057[] = {0x1f613};
unsigned int emoji2058[] = {0x1f614};
unsigned int emoji2059[] = {0x1f615};
unsigned int emoji2060[] = {0x1f616};
unsigned int emoji2061[] = {0x1f617};
unsigned int emoji2062[] = {0x1f618};
unsigned int emoji2063[] = {0x1f619};
unsigned int emoji2064[] = {0x1f61a};
unsigned int emoji2065[] = {0x1f61b};
unsigned int emoji2066[] = {0x1f61c};
unsigned int emoji2067[] = {0x1f61d};
unsigned int emoji2068[] = {0x1f61e};
unsigned int emoji2069[] = {0x1f61f};
unsigned int emoji2070[] = {0x1f620};
unsigned int emoji2071[] = {0x1f621};
unsigned int emoji2072[] = {0x1f622};
unsigned int emoji2073[] = {0x1f623};
unsigned int emoji2074[] = {0x1f624};
unsigned int emoji2075[] = {0x1f625};
unsigned int emoji2076[] = {0x1f626};
unsigned int emoji2077[] = {0x1f627};
unsigned int emoji2078[] = {0x1f628};
unsigned int emoji2079[] = {0x1f629};
unsigned int emoji2080[] = {0x1f62a};
unsigned int emoji2081[] = {0x1f62b};
unsigned int emoji2082[] = {0x1f62c};
unsigned int emoji2083[] = {0x1f62d};
unsigned int emoji2084[] = {0x1f62e};
unsigned int emoji2085[] = {0x1f62f};
unsigned int emoji2086[] = {0x1f630};
unsigned int emoji2087[] = {0x1f631};
unsigned int emoji2088[] = {0x1f632};
unsigned int emoji2089[] = {0x1f633};
unsigned int emoji2090[] = {0x1f634};
unsigned int emoji2091[] = {0x1f635};
unsigned int emoji2092[] = {0x1f636};
unsigned int emoji2093[] = {0x1f637};
unsigned int emoji2094[] = {0x1f638};
unsigned int emoji2095[] = {0x1f639};
unsigned int emoji2096[] = {0x1f63a};
unsigned int emoji2097[] = {0x1f63b};
unsigned int emoji2098[] = {0x1f63c};
unsigned int emoji2099[] = {0x1f63d};
unsigned int emoji2100[] = {0x1f63e};
unsigned int emoji2101[] = {0x1f63f};
unsigned int emoji2102[] = {0x1f640};
unsigned int emoji2103[] = {0x1f641};
unsigned int emoji2104[] = {0x1f642};
unsigned int emoji2105[] = {0x1f643};
unsigned int emoji2106[] = {0x1f644};
unsigned int emoji2107[] = {0x1f645};
unsigned int emoji2108[] = {0x1f645,0x1f3fb};
unsigned int emoji2109[] = {0x1f645,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji2110[] = {0x1f645,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji2111[] = {0x1f645,0x1f3fc};
unsigned int emoji2112[] = {0x1f645,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji2113[] = {0x1f645,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji2114[] = {0x1f645,0x1f3fd};
unsigned int emoji2115[] = {0x1f645,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji2116[] = {0x1f645,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji2117[] = {0x1f645,0x1f3fe};
unsigned int emoji2118[] = {0x1f645,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji2119[] = {0x1f645,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji2120[] = {0x1f645,0x1f3ff};
unsigned int emoji2121[] = {0x1f645,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji2122[] = {0x1f645,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji2123[] = {0x1f645,0x200d,0x2640,0xfe0f};
unsigned int emoji2124[] = {0x1f645,0x200d,0x2642,0xfe0f};
unsigned int emoji2125[] = {0x1f646};
unsigned int emoji2126[] = {0x1f646,0x1f3fb};
unsigned int emoji2127[] = {0x1f646,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji2128[] = {0x1f646,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji2129[] = {0x1f646,0x1f3fc};
unsigned int emoji2130[] = {0x1f646,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji2131[] = {0x1f646,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji2132[] = {0x1f646,0x1f3fd};
unsigned int emoji2133[] = {0x1f646,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji2134[] = {0x1f646,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji2135[] = {0x1f646,0x1f3fe};
unsigned int emoji2136[] = {0x1f646,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji2137[] = {0x1f646,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji2138[] = {0x1f646,0x1f3ff};
unsigned int emoji2139[] = {0x1f646,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji2140[] = {0x1f646,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji2141[] = {0x1f646,0x200d,0x2640,0xfe0f};
unsigned int emoji2142[] = {0x1f646,0x200d,0x2642,0xfe0f};
unsigned int emoji2143[] = {0x1f647};
unsigned int emoji2144[] = {0x1f647,0x1f3fb};
unsigned int emoji2145[] = {0x1f647,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji2146[] = {0x1f647,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji2147[] = {0x1f647,0x1f3fc};
unsigned int emoji2148[] = {0x1f647,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji2149[] = {0x1f647,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji2150[] = {0x1f647,0x1f3fd};
unsigned int emoji2151[] = {0x1f647,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji2152[] = {0x1f647,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji2153[] = {0x1f647,0x1f3fe};
unsigned int emoji2154[] = {0x1f647,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji2155[] = {0x1f647,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji2156[] = {0x1f647,0x1f3ff};
unsigned int emoji2157[] = {0x1f647,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji2158[] = {0x1f647,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji2159[] = {0x1f647,0x200d,0x2640,0xfe0f};
unsigned int emoji2160[] = {0x1f647,0x200d,0x2642,0xfe0f};
unsigned int emoji2161[] = {0x1f648};
unsigned int emoji2162[] = {0x1f649};
unsigned int emoji2163[] = {0x1f64a};
unsigned int emoji2164[] = {0x1f64b};
unsigned int emoji2165[] = {0x1f64b,0x1f3fb};
unsigned int emoji2166[] = {0x1f64b,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji2167[] = {0x1f64b,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji2168[] = {0x1f64b,0x1f3fc};
unsigned int emoji2169[] = {0x1f64b,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji2170[] = {0x1f64b,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji2171[] = {0x1f64b,0x1f3fd};
unsigned int emoji2172[] = {0x1f64b,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji2173[] = {0x1f64b,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji2174[] = {0x1f64b,0x1f3fe};
unsigned int emoji2175[] = {0x1f64b,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji2176[] = {0x1f64b,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji2177[] = {0x1f64b,0x1f3ff};
unsigned int emoji2178[] = {0x1f64b,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji2179[] = {0x1f64b,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji2180[] = {0x1f64b,0x200d,0x2640,0xfe0f};
unsigned int emoji2181[] = {0x1f64b,0x200d,0x2642,0xfe0f};
unsigned int emoji2182[] = {0x1f64c};
unsigned int emoji2183[] = {0x1f64c,0x1f3fb};
unsigned int emoji2184[] = {0x1f64c,0x1f3fc};
unsigned int emoji2185[] = {0x1f64c,0x1f3fd};
unsigned int emoji2186[] = {0x1f64c,0x1f3fe};
unsigned int emoji2187[] = {0x1f64c,0x1f3ff};
unsigned int emoji2188[] = {0x1f64d};
unsigned int emoji2189[] = {0x1f64d,0x1f3fb};
unsigned int emoji2190[] = {0x1f64d,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji2191[] = {0x1f64d,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji2192[] = {0x1f64d,0x1f3fc};
unsigned int emoji2193[] = {0x1f64d,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji2194[] = {0x1f64d,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji2195[] = {0x1f64d,0x1f3fd};
unsigned int emoji2196[] = {0x1f64d,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji2197[] = {0x1f64d,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji2198[] = {0x1f64d,0x1f3fe};
unsigned int emoji2199[] = {0x1f64d,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji2200[] = {0x1f64d,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji2201[] = {0x1f64d,0x1f3ff};
unsigned int emoji2202[] = {0x1f64d,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji2203[] = {0x1f64d,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji2204[] = {0x1f64d,0x200d,0x2640,0xfe0f};
unsigned int emoji2205[] = {0x1f64d,0x200d,0x2642,0xfe0f};
unsigned int emoji2206[] = {0x1f64e};
unsigned int emoji2207[] = {0x1f64e,0x1f3fb};
unsigned int emoji2208[] = {0x1f64e,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji2209[] = {0x1f64e,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji2210[] = {0x1f64e,0x1f3fc};
unsigned int emoji2211[] = {0x1f64e,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji2212[] = {0x1f64e,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji2213[] = {0x1f64e,0x1f3fd};
unsigned int emoji2214[] = {0x1f64e,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji2215[] = {0x1f64e,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji2216[] = {0x1f64e,0x1f3fe};
unsigned int emoji2217[] = {0x1f64e,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji2218[] = {0x1f64e,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji2219[] = {0x1f64e,0x1f3ff};
unsigned int emoji2220[] = {0x1f64e,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji2221[] = {0x1f64e,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji2222[] = {0x1f64e,0x200d,0x2640,0xfe0f};
unsigned int emoji2223[] = {0x1f64e,0x200d,0x2642,0xfe0f};
unsigned int emoji2224[] = {0x1f64f};
unsigned int emoji2225[] = {0x1f64f,0x1f3fb};
unsigned int emoji2226[] = {0x1f64f,0x1f3fc};
unsigned int emoji2227[] = {0x1f64f,0x1f3fd};
unsigned int emoji2228[] = {0x1f64f,0x1f3fe};
unsigned int emoji2229[] = {0x1f64f,0x1f3ff};
unsigned int emoji2230[] = {0x1f680};
unsigned int emoji2231[] = {0x1f681};
unsigned int emoji2232[] = {0x1f682};
unsigned int emoji2233[] = {0x1f683};
unsigned int emoji2234[] = {0x1f684};
unsigned int emoji2235[] = {0x1f685};
unsigned int emoji2236[] = {0x1f686};
unsigned int emoji2237[] = {0x1f687};
unsigned int emoji2238[] = {0x1f688};
unsigned int emoji2239[] = {0x1f689};
unsigned int emoji2240[] = {0x1f68a};
unsigned int emoji2241[] = {0x1f68b};
unsigned int emoji2242[] = {0x1f68c};
unsigned int emoji2243[] = {0x1f68d};
unsigned int emoji2244[] = {0x1f68e};
unsigned int emoji2245[] = {0x1f68f};
unsigned int emoji2246[] = {0x1f690};
unsigned int emoji2247[] = {0x1f691};
unsigned int emoji2248[] = {0x1f692};
unsigned int emoji2249[] = {0x1f693};
unsigned int emoji2250[] = {0x1f694};
unsigned int emoji2251[] = {0x1f695};
unsigned int emoji2252[] = {0x1f696};
unsigned int emoji2253[] = {0x1f697};
unsigned int emoji2254[] = {0x1f698};
unsigned int emoji2255[] = {0x1f699};
unsigned int emoji2256[] = {0x1f69a};
unsigned int emoji2257[] = {0x1f69b};
unsigned int emoji2258[] = {0x1f69c};
unsigned int emoji2259[] = {0x1f69d};
unsigned int emoji2260[] = {0x1f69e};
unsigned int emoji2261[] = {0x1f69f};
unsigned int emoji2262[] = {0x1f6a0};
unsigned int emoji2263[] = {0x1f6a1};
unsigned int emoji2264[] = {0x1f6a2};
unsigned int emoji2265[] = {0x1f6a3};
unsigned int emoji2266[] = {0x1f6a3,0x1f3fb};
unsigned int emoji2267[] = {0x1f6a3,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji2268[] = {0x1f6a3,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji2269[] = {0x1f6a3,0x1f3fc};
unsigned int emoji2270[] = {0x1f6a3,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji2271[] = {0x1f6a3,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji2272[] = {0x1f6a3,0x1f3fd};
unsigned int emoji2273[] = {0x1f6a3,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji2274[] = {0x1f6a3,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji2275[] = {0x1f6a3,0x1f3fe};
unsigned int emoji2276[] = {0x1f6a3,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji2277[] = {0x1f6a3,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji2278[] = {0x1f6a3,0x1f3ff};
unsigned int emoji2279[] = {0x1f6a3,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji2280[] = {0x1f6a3,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji2281[] = {0x1f6a3,0x200d,0x2640,0xfe0f};
unsigned int emoji2282[] = {0x1f6a3,0x200d,0x2642,0xfe0f};
unsigned int emoji2283[] = {0x1f6a4};
unsigned int emoji2284[] = {0x1f6a5};
unsigned int emoji2285[] = {0x1f6a6};
unsigned int emoji2286[] = {0x1f6a7};
unsigned int emoji2287[] = {0x1f6a8};
unsigned int emoji2288[] = {0x1f6a9};
unsigned int emoji2289[] = {0x1f6aa};
unsigned int emoji2290[] = {0x1f6ab};
unsigned int emoji2291[] = {0x1f6ac};
unsigned int emoji2292[] = {0x1f6ad};
unsigned int emoji2293[] = {0x1f6ae};
unsigned int emoji2294[] = {0x1f6af};
unsigned int emoji2295[] = {0x1f6b0};
unsigned int emoji2296[] = {0x1f6b1};
unsigned int emoji2297[] = {0x1f6b2};
unsigned int emoji2298[] = {0x1f6b3};
unsigned int emoji2299[] = {0x1f6b4};
unsigned int emoji2300[] = {0x1f6b4,0x1f3fb};
unsigned int emoji2301[] = {0x1f6b4,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji2302[] = {0x1f6b4,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji2303[] = {0x1f6b4,0x1f3fc};
unsigned int emoji2304[] = {0x1f6b4,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji2305[] = {0x1f6b4,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji2306[] = {0x1f6b4,0x1f3fd};
unsigned int emoji2307[] = {0x1f6b4,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji2308[] = {0x1f6b4,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji2309[] = {0x1f6b4,0x1f3fe};
unsigned int emoji2310[] = {0x1f6b4,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji2311[] = {0x1f6b4,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji2312[] = {0x1f6b4,0x1f3ff};
unsigned int emoji2313[] = {0x1f6b4,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji2314[] = {0x1f6b4,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji2315[] = {0x1f6b4,0x200d,0x2640,0xfe0f};
unsigned int emoji2316[] = {0x1f6b4,0x200d,0x2642,0xfe0f};
unsigned int emoji2317[] = {0x1f6b5};
unsigned int emoji2318[] = {0x1f6b5,0x1f3fb};
unsigned int emoji2319[] = {0x1f6b5,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji2320[] = {0x1f6b5,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji2321[] = {0x1f6b5,0x1f3fc};
unsigned int emoji2322[] = {0x1f6b5,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji2323[] = {0x1f6b5,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji2324[] = {0x1f6b5,0x1f3fd};
unsigned int emoji2325[] = {0x1f6b5,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji2326[] = {0x1f6b5,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji2327[] = {0x1f6b5,0x1f3fe};
unsigned int emoji2328[] = {0x1f6b5,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji2329[] = {0x1f6b5,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji2330[] = {0x1f6b5,0x1f3ff};
unsigned int emoji2331[] = {0x1f6b5,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji2332[] = {0x1f6b5,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji2333[] = {0x1f6b5,0x200d,0x2640,0xfe0f};
unsigned int emoji2334[] = {0x1f6b5,0x200d,0x2642,0xfe0f};
unsigned int emoji2335[] = {0x1f6b6};
unsigned int emoji2336[] = {0x1f6b6,0x1f3fb};
unsigned int emoji2337[] = {0x1f6b6,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji2338[] = {0x1f6b6,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji2339[] = {0x1f6b6,0x1f3fc};
unsigned int emoji2340[] = {0x1f6b6,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji2341[] = {0x1f6b6,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji2342[] = {0x1f6b6,0x1f3fd};
unsigned int emoji2343[] = {0x1f6b6,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji2344[] = {0x1f6b6,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji2345[] = {0x1f6b6,0x1f3fe};
unsigned int emoji2346[] = {0x1f6b6,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji2347[] = {0x1f6b6,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji2348[] = {0x1f6b6,0x1f3ff};
unsigned int emoji2349[] = {0x1f6b6,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji2350[] = {0x1f6b6,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji2351[] = {0x1f6b6,0x200d,0x2640,0xfe0f};
unsigned int emoji2352[] = {0x1f6b6,0x200d,0x2642,0xfe0f};
unsigned int emoji2353[] = {0x1f6b7};
unsigned int emoji2354[] = {0x1f6b8};
unsigned int emoji2355[] = {0x1f6b9};
unsigned int emoji2356[] = {0x1f6ba};
unsigned int emoji2357[] = {0x1f6bb};
unsigned int emoji2358[] = {0x1f6bc};
unsigned int emoji2359[] = {0x1f6bd};
unsigned int emoji2360[] = {0x1f6be};
unsigned int emoji2361[] = {0x1f6bf};
unsigned int emoji2362[] = {0x1f6c0};
unsigned int emoji2363[] = {0x1f6c0,0x1f3fb};
unsigned int emoji2364[] = {0x1f6c0,0x1f3fc};
unsigned int emoji2365[] = {0x1f6c0,0x1f3fd};
unsigned int emoji2366[] = {0x1f6c0,0x1f3fe};
unsigned int emoji2367[] = {0x1f6c0,0x1f3ff};
unsigned int emoji2368[] = {0x1f6c1};
unsigned int emoji2369[] = {0x1f6c2};
unsigned int emoji2370[] = {0x1f6c3};
unsigned int emoji2371[] = {0x1f6c4};
unsigned int emoji2372[] = {0x1f6c5};
unsigned int emoji2373[] = {0x1f6cb};
unsigned int emoji2374[] = {0x1f6cc};
unsigned int emoji2375[] = {0x1f6cc,0x1f3fb};
unsigned int emoji2376[] = {0x1f6cc,0x1f3fc};
unsigned int emoji2377[] = {0x1f6cc,0x1f3fd};
unsigned int emoji2378[] = {0x1f6cc,0x1f3fe};
unsigned int emoji2379[] = {0x1f6cc,0x1f3ff};
unsigned int emoji2380[] = {0x1f6cd};
unsigned int emoji2381[] = {0x1f6ce};
unsigned int emoji2382[] = {0x1f6cf};
unsigned int emoji2383[] = {0x1f6d0};
unsigned int emoji2384[] = {0x1f6d1};
unsigned int emoji2385[] = {0x1f6d2};
unsigned int emoji2386[] = {0x1f6d5};
unsigned int emoji2387[] = {0x1f6d6};
unsigned int emoji2388[] = {0x1f6d7};
unsigned int emoji2389[] = {0x1f6e0};
unsigned int emoji2390[] = {0x1f6e1};
unsigned int emoji2391[] = {0x1f6e2};
unsigned int emoji2392[] = {0x1f6e3};
unsigned int emoji2393[] = {0x1f6e4};
unsigned int emoji2394[] = {0x1f6e5};
unsigned int emoji2395[] = {0x1f6e9};
unsigned int emoji2396[] = {0x1f6eb};
unsigned int emoji2397[] = {0x1f6ec};
unsigned int emoji2398[] = {0x1f6f0};
unsigned int emoji2399[] = {0x1f6f3};
unsigned int emoji2400[] = {0x1f6f4};
unsigned int emoji2401[] = {0x1f6f5};
unsigned int emoji2402[] = {0x1f6f6};
unsigned int emoji2403[] = {0x1f6f7};
unsigned int emoji2404[] = {0x1f6f8};
unsigned int emoji2405[] = {0x1f6f9};
unsigned int emoji2406[] = {0x1f6fa};
unsigned int emoji2407[] = {0x1f6fb};
unsigned int emoji2408[] = {0x1f6fc};
unsigned int emoji2409[] = {0x1f7e0};
unsigned int emoji2410[] = {0x1f7e1};
unsigned int emoji2411[] = {0x1f7e2};
unsigned int emoji2412[] = {0x1f7e3};
unsigned int emoji2413[] = {0x1f7e4};
unsigned int emoji2414[] = {0x1f7e5};
unsigned int emoji2415[] = {0x1f7e6};
unsigned int emoji2416[] = {0x1f7e7};
unsigned int emoji2417[] = {0x1f7e8};
unsigned int emoji2418[] = {0x1f7e9};
unsigned int emoji2419[] = {0x1f7ea};
unsigned int emoji2420[] = {0x1f7eb};
unsigned int emoji2421[] = {0x1f90c};
unsigned int emoji2422[] = {0x1f90c,0x1f3fb};
unsigned int emoji2423[] = {0x1f90c,0x1f3fc};
unsigned int emoji2424[] = {0x1f90c,0x1f3fd};
unsigned int emoji2425[] = {0x1f90c,0x1f3fe};
unsigned int emoji2426[] = {0x1f90c,0x1f3ff};
unsigned int emoji2427[] = {0x1f90d};
unsigned int emoji2428[] = {0x1f90e};
unsigned int emoji2429[] = {0x1f90f};
unsigned int emoji2430[] = {0x1f90f,0x1f3fb};
unsigned int emoji2431[] = {0x1f90f,0x1f3fc};
unsigned int emoji2432[] = {0x1f90f,0x1f3fd};
unsigned int emoji2433[] = {0x1f90f,0x1f3fe};
unsigned int emoji2434[] = {0x1f90f,0x1f3ff};
unsigned int emoji2435[] = {0x1f910};
unsigned int emoji2436[] = {0x1f911};
unsigned int emoji2437[] = {0x1f912};
unsigned int emoji2438[] = {0x1f913};
unsigned int emoji2439[] = {0x1f914};
unsigned int emoji2440[] = {0x1f915};
unsigned int emoji2441[] = {0x1f916};
unsigned int emoji2442[] = {0x1f917};
unsigned int emoji2443[] = {0x1f918};
unsigned int emoji2444[] = {0x1f918,0x1f3fb};
unsigned int emoji2445[] = {0x1f918,0x1f3fc};
unsigned int emoji2446[] = {0x1f918,0x1f3fd};
unsigned int emoji2447[] = {0x1f918,0x1f3fe};
unsigned int emoji2448[] = {0x1f918,0x1f3ff};
unsigned int emoji2449[] = {0x1f919};
unsigned int emoji2450[] = {0x1f919,0x1f3fb};
unsigned int emoji2451[] = {0x1f919,0x1f3fc};
unsigned int emoji2452[] = {0x1f919,0x1f3fd};
unsigned int emoji2453[] = {0x1f919,0x1f3fe};
unsigned int emoji2454[] = {0x1f919,0x1f3ff};
unsigned int emoji2455[] = {0x1f91a};
unsigned int emoji2456[] = {0x1f91a,0x1f3fb};
unsigned int emoji2457[] = {0x1f91a,0x1f3fc};
unsigned int emoji2458[] = {0x1f91a,0x1f3fd};
unsigned int emoji2459[] = {0x1f91a,0x1f3fe};
unsigned int emoji2460[] = {0x1f91a,0x1f3ff};
unsigned int emoji2461[] = {0x1f91b};
unsigned int emoji2462[] = {0x1f91b,0x1f3fb};
unsigned int emoji2463[] = {0x1f91b,0x1f3fc};
unsigned int emoji2464[] = {0x1f91b,0x1f3fd};
unsigned int emoji2465[] = {0x1f91b,0x1f3fe};
unsigned int emoji2466[] = {0x1f91b,0x1f3ff};
unsigned int emoji2467[] = {0x1f91c};
unsigned int emoji2468[] = {0x1f91c,0x1f3fb};
unsigned int emoji2469[] = {0x1f91c,0x1f3fc};
unsigned int emoji2470[] = {0x1f91c,0x1f3fd};
unsigned int emoji2471[] = {0x1f91c,0x1f3fe};
unsigned int emoji2472[] = {0x1f91c,0x1f3ff};
unsigned int emoji2473[] = {0x1f91d};
unsigned int emoji2474[] = {0x1f91e};
unsigned int emoji2475[] = {0x1f91e,0x1f3fb};
unsigned int emoji2476[] = {0x1f91e,0x1f3fc};
unsigned int emoji2477[] = {0x1f91e,0x1f3fd};
unsigned int emoji2478[] = {0x1f91e,0x1f3fe};
unsigned int emoji2479[] = {0x1f91e,0x1f3ff};
unsigned int emoji2480[] = {0x1f91f};
unsigned int emoji2481[] = {0x1f91f,0x1f3fb};
unsigned int emoji2482[] = {0x1f91f,0x1f3fc};
unsigned int emoji2483[] = {0x1f91f,0x1f3fd};
unsigned int emoji2484[] = {0x1f91f,0x1f3fe};
unsigned int emoji2485[] = {0x1f91f,0x1f3ff};
unsigned int emoji2486[] = {0x1f920};
unsigned int emoji2487[] = {0x1f921};
unsigned int emoji2488[] = {0x1f922};
unsigned int emoji2489[] = {0x1f923};
unsigned int emoji2490[] = {0x1f924};
unsigned int emoji2491[] = {0x1f925};
unsigned int emoji2492[] = {0x1f926};
unsigned int emoji2493[] = {0x1f926,0x1f3fb};
unsigned int emoji2494[] = {0x1f926,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji2495[] = {0x1f926,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji2496[] = {0x1f926,0x1f3fc};
unsigned int emoji2497[] = {0x1f926,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji2498[] = {0x1f926,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji2499[] = {0x1f926,0x1f3fd};
unsigned int emoji2500[] = {0x1f926,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji2501[] = {0x1f926,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji2502[] = {0x1f926,0x1f3fe};
unsigned int emoji2503[] = {0x1f926,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji2504[] = {0x1f926,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji2505[] = {0x1f926,0x1f3ff};
unsigned int emoji2506[] = {0x1f926,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji2507[] = {0x1f926,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji2508[] = {0x1f926,0x200d,0x2640,0xfe0f};
unsigned int emoji2509[] = {0x1f926,0x200d,0x2642,0xfe0f};
unsigned int emoji2510[] = {0x1f927};
unsigned int emoji2511[] = {0x1f928};
unsigned int emoji2512[] = {0x1f929};
unsigned int emoji2513[] = {0x1f92a};
unsigned int emoji2514[] = {0x1f92b};
unsigned int emoji2515[] = {0x1f92c};
unsigned int emoji2516[] = {0x1f92d};
unsigned int emoji2517[] = {0x1f92e};
unsigned int emoji2518[] = {0x1f92f};
unsigned int emoji2519[] = {0x1f930};
unsigned int emoji2520[] = {0x1f930,0x1f3fb};
unsigned int emoji2521[] = {0x1f930,0x1f3fc};
unsigned int emoji2522[] = {0x1f930,0x1f3fd};
unsigned int emoji2523[] = {0x1f930,0x1f3fe};
unsigned int emoji2524[] = {0x1f930,0x1f3ff};
unsigned int emoji2525[] = {0x1f931};
unsigned int emoji2526[] = {0x1f931,0x1f3fb};
unsigned int emoji2527[] = {0x1f931,0x1f3fc};
unsigned int emoji2528[] = {0x1f931,0x1f3fd};
unsigned int emoji2529[] = {0x1f931,0x1f3fe};
unsigned int emoji2530[] = {0x1f931,0x1f3ff};
unsigned int emoji2531[] = {0x1f932};
unsigned int emoji2532[] = {0x1f932,0x1f3fb};
unsigned int emoji2533[] = {0x1f932,0x1f3fc};
unsigned int emoji2534[] = {0x1f932,0x1f3fd};
unsigned int emoji2535[] = {0x1f932,0x1f3fe};
unsigned int emoji2536[] = {0x1f932,0x1f3ff};
unsigned int emoji2537[] = {0x1f933};
unsigned int emoji2538[] = {0x1f933,0x1f3fb};
unsigned int emoji2539[] = {0x1f933,0x1f3fc};
unsigned int emoji2540[] = {0x1f933,0x1f3fd};
unsigned int emoji2541[] = {0x1f933,0x1f3fe};
unsigned int emoji2542[] = {0x1f933,0x1f3ff};
unsigned int emoji2543[] = {0x1f934};
unsigned int emoji2544[] = {0x1f934,0x1f3fb};
unsigned int emoji2545[] = {0x1f934,0x1f3fc};
unsigned int emoji2546[] = {0x1f934,0x1f3fd};
unsigned int emoji2547[] = {0x1f934,0x1f3fe};
unsigned int emoji2548[] = {0x1f934,0x1f3ff};
unsigned int emoji2549[] = {0x1f935};
unsigned int emoji2550[] = {0x1f935,0x1f3fb};
unsigned int emoji2551[] = {0x1f935,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji2552[] = {0x1f935,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji2553[] = {0x1f935,0x1f3fc};
unsigned int emoji2554[] = {0x1f935,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji2555[] = {0x1f935,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji2556[] = {0x1f935,0x1f3fd};
unsigned int emoji2557[] = {0x1f935,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji2558[] = {0x1f935,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji2559[] = {0x1f935,0x1f3fe};
unsigned int emoji2560[] = {0x1f935,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji2561[] = {0x1f935,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji2562[] = {0x1f935,0x1f3ff};
unsigned int emoji2563[] = {0x1f935,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji2564[] = {0x1f935,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji2565[] = {0x1f935,0x200d,0x2640,0xfe0f};
unsigned int emoji2566[] = {0x1f935,0x200d,0x2642,0xfe0f};
unsigned int emoji2567[] = {0x1f936};
unsigned int emoji2568[] = {0x1f936,0x1f3fb};
unsigned int emoji2569[] = {0x1f936,0x1f3fc};
unsigned int emoji2570[] = {0x1f936,0x1f3fd};
unsigned int emoji2571[] = {0x1f936,0x1f3fe};
unsigned int emoji2572[] = {0x1f936,0x1f3ff};
unsigned int emoji2573[] = {0x1f937};
unsigned int emoji2574[] = {0x1f937,0x1f3fb};
unsigned int emoji2575[] = {0x1f937,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji2576[] = {0x1f937,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji2577[] = {0x1f937,0x1f3fc};
unsigned int emoji2578[] = {0x1f937,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji2579[] = {0x1f937,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji2580[] = {0x1f937,0x1f3fd};
unsigned int emoji2581[] = {0x1f937,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji2582[] = {0x1f937,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji2583[] = {0x1f937,0x1f3fe};
unsigned int emoji2584[] = {0x1f937,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji2585[] = {0x1f937,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji2586[] = {0x1f937,0x1f3ff};
unsigned int emoji2587[] = {0x1f937,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji2588[] = {0x1f937,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji2589[] = {0x1f937,0x200d,0x2640,0xfe0f};
unsigned int emoji2590[] = {0x1f937,0x200d,0x2642,0xfe0f};
unsigned int emoji2591[] = {0x1f938};
unsigned int emoji2592[] = {0x1f938,0x1f3fb};
unsigned int emoji2593[] = {0x1f938,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji2594[] = {0x1f938,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji2595[] = {0x1f938,0x1f3fc};
unsigned int emoji2596[] = {0x1f938,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji2597[] = {0x1f938,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji2598[] = {0x1f938,0x1f3fd};
unsigned int emoji2599[] = {0x1f938,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji2600[] = {0x1f938,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji2601[] = {0x1f938,0x1f3fe};
unsigned int emoji2602[] = {0x1f938,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji2603[] = {0x1f938,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji2604[] = {0x1f938,0x1f3ff};
unsigned int emoji2605[] = {0x1f938,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji2606[] = {0x1f938,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji2607[] = {0x1f938,0x200d,0x2640,0xfe0f};
unsigned int emoji2608[] = {0x1f938,0x200d,0x2642,0xfe0f};
unsigned int emoji2609[] = {0x1f939};
unsigned int emoji2610[] = {0x1f939,0x1f3fb};
unsigned int emoji2611[] = {0x1f939,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji2612[] = {0x1f939,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji2613[] = {0x1f939,0x1f3fc};
unsigned int emoji2614[] = {0x1f939,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji2615[] = {0x1f939,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji2616[] = {0x1f939,0x1f3fd};
unsigned int emoji2617[] = {0x1f939,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji2618[] = {0x1f939,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji2619[] = {0x1f939,0x1f3fe};
unsigned int emoji2620[] = {0x1f939,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji2621[] = {0x1f939,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji2622[] = {0x1f939,0x1f3ff};
unsigned int emoji2623[] = {0x1f939,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji2624[] = {0x1f939,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji2625[] = {0x1f939,0x200d,0x2640,0xfe0f};
unsigned int emoji2626[] = {0x1f939,0x200d,0x2642,0xfe0f};
unsigned int emoji2627[] = {0x1f93a};
unsigned int emoji2628[] = {0x1f93c};
unsigned int emoji2629[] = {0x1f93c,0x200d,0x2640,0xfe0f};
unsigned int emoji2630[] = {0x1f93c,0x200d,0x2642,0xfe0f};
unsigned int emoji2631[] = {0x1f93d};
unsigned int emoji2632[] = {0x1f93d,0x1f3fb};
unsigned int emoji2633[] = {0x1f93d,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji2634[] = {0x1f93d,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji2635[] = {0x1f93d,0x1f3fc};
unsigned int emoji2636[] = {0x1f93d,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji2637[] = {0x1f93d,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji2638[] = {0x1f93d,0x1f3fd};
unsigned int emoji2639[] = {0x1f93d,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji2640[] = {0x1f93d,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji2641[] = {0x1f93d,0x1f3fe};
unsigned int emoji2642[] = {0x1f93d,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji2643[] = {0x1f93d,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji2644[] = {0x1f93d,0x1f3ff};
unsigned int emoji2645[] = {0x1f93d,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji2646[] = {0x1f93d,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji2647[] = {0x1f93d,0x200d,0x2640,0xfe0f};
unsigned int emoji2648[] = {0x1f93d,0x200d,0x2642,0xfe0f};
unsigned int emoji2649[] = {0x1f93e};
unsigned int emoji2650[] = {0x1f93e,0x1f3fb};
unsigned int emoji2651[] = {0x1f93e,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji2652[] = {0x1f93e,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji2653[] = {0x1f93e,0x1f3fc};
unsigned int emoji2654[] = {0x1f93e,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji2655[] = {0x1f93e,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji2656[] = {0x1f93e,0x1f3fd};
unsigned int emoji2657[] = {0x1f93e,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji2658[] = {0x1f93e,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji2659[] = {0x1f93e,0x1f3fe};
unsigned int emoji2660[] = {0x1f93e,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji2661[] = {0x1f93e,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji2662[] = {0x1f93e,0x1f3ff};
unsigned int emoji2663[] = {0x1f93e,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji2664[] = {0x1f93e,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji2665[] = {0x1f93e,0x200d,0x2640,0xfe0f};
unsigned int emoji2666[] = {0x1f93e,0x200d,0x2642,0xfe0f};
unsigned int emoji2667[] = {0x1f93f};
unsigned int emoji2668[] = {0x1f940};
unsigned int emoji2669[] = {0x1f941};
unsigned int emoji2670[] = {0x1f942};
unsigned int emoji2671[] = {0x1f943};
unsigned int emoji2672[] = {0x1f944};
unsigned int emoji2673[] = {0x1f945};
unsigned int emoji2674[] = {0x1f947};
unsigned int emoji2675[] = {0x1f948};
unsigned int emoji2676[] = {0x1f949};
unsigned int emoji2677[] = {0x1f94a};
unsigned int emoji2678[] = {0x1f94b};
unsigned int emoji2679[] = {0x1f94c};
unsigned int emoji2680[] = {0x1f94d};
unsigned int emoji2681[] = {0x1f94e};
unsigned int emoji2682[] = {0x1f94f};
unsigned int emoji2683[] = {0x1f950};
unsigned int emoji2684[] = {0x1f951};
unsigned int emoji2685[] = {0x1f952};
unsigned int emoji2686[] = {0x1f953};
unsigned int emoji2687[] = {0x1f954};
unsigned int emoji2688[] = {0x1f955};
unsigned int emoji2689[] = {0x1f956};
unsigned int emoji2690[] = {0x1f957};
unsigned int emoji2691[] = {0x1f958};
unsigned int emoji2692[] = {0x1f959};
unsigned int emoji2693[] = {0x1f95a};
unsigned int emoji2694[] = {0x1f95b};
unsigned int emoji2695[] = {0x1f95c};
unsigned int emoji2696[] = {0x1f95d};
unsigned int emoji2697[] = {0x1f95e};
unsigned int emoji2698[] = {0x1f95f};
unsigned int emoji2699[] = {0x1f960};
unsigned int emoji2700[] = {0x1f961};
unsigned int emoji2701[] = {0x1f962};
unsigned int emoji2702[] = {0x1f963};
unsigned int emoji2703[] = {0x1f964};
unsigned int emoji2704[] = {0x1f965};
unsigned int emoji2705[] = {0x1f966};
unsigned int emoji2706[] = {0x1f967};
unsigned int emoji2707[] = {0x1f968};
unsigned int emoji2708[] = {0x1f969};
unsigned int emoji2709[] = {0x1f96a};
unsigned int emoji2710[] = {0x1f96b};
unsigned int emoji2711[] = {0x1f96c};
unsigned int emoji2712[] = {0x1f96d};
unsigned int emoji2713[] = {0x1f96e};
unsigned int emoji2714[] = {0x1f96f};
unsigned int emoji2715[] = {0x1f970};
unsigned int emoji2716[] = {0x1f971};
unsigned int emoji2717[] = {0x1f972};
unsigned int emoji2718[] = {0x1f973};
unsigned int emoji2719[] = {0x1f974};
unsigned int emoji2720[] = {0x1f975};
unsigned int emoji2721[] = {0x1f976};
unsigned int emoji2722[] = {0x1f977};
unsigned int emoji2723[] = {0x1f977,0x1f3fb};
unsigned int emoji2724[] = {0x1f977,0x1f3fc};
unsigned int emoji2725[] = {0x1f977,0x1f3fd};
unsigned int emoji2726[] = {0x1f977,0x1f3fe};
unsigned int emoji2727[] = {0x1f977,0x1f3ff};
unsigned int emoji2728[] = {0x1f978};
unsigned int emoji2729[] = {0x1f97a};
unsigned int emoji2730[] = {0x1f97b};
unsigned int emoji2731[] = {0x1f97c};
unsigned int emoji2732[] = {0x1f97d};
unsigned int emoji2733[] = {0x1f97e};
unsigned int emoji2734[] = {0x1f97f};
unsigned int emoji2735[] = {0x1f980};
unsigned int emoji2736[] = {0x1f981};
unsigned int emoji2737[] = {0x1f982};
unsigned int emoji2738[] = {0x1f983};
unsigned int emoji2739[] = {0x1f984};
unsigned int emoji2740[] = {0x1f985};
unsigned int emoji2741[] = {0x1f986};
unsigned int emoji2742[] = {0x1f987};
unsigned int emoji2743[] = {0x1f988};
unsigned int emoji2744[] = {0x1f989};
unsigned int emoji2745[] = {0x1f98a};
unsigned int emoji2746[] = {0x1f98b};
unsigned int emoji2747[] = {0x1f98c};
unsigned int emoji2748[] = {0x1f98d};
unsigned int emoji2749[] = {0x1f98e};
unsigned int emoji2750[] = {0x1f98f};
unsigned int emoji2751[] = {0x1f990};
unsigned int emoji2752[] = {0x1f991};
unsigned int emoji2753[] = {0x1f992};
unsigned int emoji2754[] = {0x1f993};
unsigned int emoji2755[] = {0x1f994};
unsigned int emoji2756[] = {0x1f995};
unsigned int emoji2757[] = {0x1f996};
unsigned int emoji2758[] = {0x1f997};
unsigned int emoji2759[] = {0x1f998};
unsigned int emoji2760[] = {0x1f999};
unsigned int emoji2761[] = {0x1f99a};
unsigned int emoji2762[] = {0x1f99b};
unsigned int emoji2763[] = {0x1f99c};
unsigned int emoji2764[] = {0x1f99d};
unsigned int emoji2765[] = {0x1f99e};
unsigned int emoji2766[] = {0x1f99f};
unsigned int emoji2767[] = {0x1f9a0};
unsigned int emoji2768[] = {0x1f9a1};
unsigned int emoji2769[] = {0x1f9a2};
unsigned int emoji2770[] = {0x1f9a3};
unsigned int emoji2771[] = {0x1f9a4};
unsigned int emoji2772[] = {0x1f9a5};
unsigned int emoji2773[] = {0x1f9a6};
unsigned int emoji2774[] = {0x1f9a7};
unsigned int emoji2775[] = {0x1f9a8};
unsigned int emoji2776[] = {0x1f9a9};
unsigned int emoji2777[] = {0x1f9aa};
unsigned int emoji2778[] = {0x1f9ab};
unsigned int emoji2779[] = {0x1f9ac};
unsigned int emoji2780[] = {0x1f9ad};
unsigned int emoji2781[] = {0x1f9ae};
unsigned int emoji2782[] = {0x1f9af};
unsigned int emoji2783[] = {0x1f9b0};
unsigned int emoji2784[] = {0x1f9b1};
unsigned int emoji2785[] = {0x1f9b2};
unsigned int emoji2786[] = {0x1f9b3};
unsigned int emoji2787[] = {0x1f9b4};
unsigned int emoji2788[] = {0x1f9b5};
unsigned int emoji2789[] = {0x1f9b5,0x1f3fb};
unsigned int emoji2790[] = {0x1f9b5,0x1f3fc};
unsigned int emoji2791[] = {0x1f9b5,0x1f3fd};
unsigned int emoji2792[] = {0x1f9b5,0x1f3fe};
unsigned int emoji2793[] = {0x1f9b5,0x1f3ff};
unsigned int emoji2794[] = {0x1f9b6};
unsigned int emoji2795[] = {0x1f9b6,0x1f3fb};
unsigned int emoji2796[] = {0x1f9b6,0x1f3fc};
unsigned int emoji2797[] = {0x1f9b6,0x1f3fd};
unsigned int emoji2798[] = {0x1f9b6,0x1f3fe};
unsigned int emoji2799[] = {0x1f9b6,0x1f3ff};
unsigned int emoji2800[] = {0x1f9b7};
unsigned int emoji2801[] = {0x1f9b8};
unsigned int emoji2802[] = {0x1f9b8,0x1f3fb};
unsigned int emoji2803[] = {0x1f9b8,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji2804[] = {0x1f9b8,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji2805[] = {0x1f9b8,0x1f3fc};
unsigned int emoji2806[] = {0x1f9b8,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji2807[] = {0x1f9b8,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji2808[] = {0x1f9b8,0x1f3fd};
unsigned int emoji2809[] = {0x1f9b8,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji2810[] = {0x1f9b8,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji2811[] = {0x1f9b8,0x1f3fe};
unsigned int emoji2812[] = {0x1f9b8,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji2813[] = {0x1f9b8,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji2814[] = {0x1f9b8,0x1f3ff};
unsigned int emoji2815[] = {0x1f9b8,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji2816[] = {0x1f9b8,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji2817[] = {0x1f9b8,0x200d,0x2640,0xfe0f};
unsigned int emoji2818[] = {0x1f9b8,0x200d,0x2642,0xfe0f};
unsigned int emoji2819[] = {0x1f9b9};
unsigned int emoji2820[] = {0x1f9b9,0x1f3fb};
unsigned int emoji2821[] = {0x1f9b9,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji2822[] = {0x1f9b9,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji2823[] = {0x1f9b9,0x1f3fc};
unsigned int emoji2824[] = {0x1f9b9,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji2825[] = {0x1f9b9,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji2826[] = {0x1f9b9,0x1f3fd};
unsigned int emoji2827[] = {0x1f9b9,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji2828[] = {0x1f9b9,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji2829[] = {0x1f9b9,0x1f3fe};
unsigned int emoji2830[] = {0x1f9b9,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji2831[] = {0x1f9b9,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji2832[] = {0x1f9b9,0x1f3ff};
unsigned int emoji2833[] = {0x1f9b9,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji2834[] = {0x1f9b9,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji2835[] = {0x1f9b9,0x200d,0x2640,0xfe0f};
unsigned int emoji2836[] = {0x1f9b9,0x200d,0x2642,0xfe0f};
unsigned int emoji2837[] = {0x1f9ba};
unsigned int emoji2838[] = {0x1f9bb};
unsigned int emoji2839[] = {0x1f9bb,0x1f3fb};
unsigned int emoji2840[] = {0x1f9bb,0x1f3fc};
unsigned int emoji2841[] = {0x1f9bb,0x1f3fd};
unsigned int emoji2842[] = {0x1f9bb,0x1f3fe};
unsigned int emoji2843[] = {0x1f9bb,0x1f3ff};
unsigned int emoji2844[] = {0x1f9bc};
unsigned int emoji2845[] = {0x1f9bd};
unsigned int emoji2846[] = {0x1f9be};
unsigned int emoji2847[] = {0x1f9bf};
unsigned int emoji2848[] = {0x1f9c0};
unsigned int emoji2849[] = {0x1f9c1};
unsigned int emoji2850[] = {0x1f9c2};
unsigned int emoji2851[] = {0x1f9c3};
unsigned int emoji2852[] = {0x1f9c4};
unsigned int emoji2853[] = {0x1f9c5};
unsigned int emoji2854[] = {0x1f9c6};
unsigned int emoji2855[] = {0x1f9c7};
unsigned int emoji2856[] = {0x1f9c8};
unsigned int emoji2857[] = {0x1f9c9};
unsigned int emoji2858[] = {0x1f9ca};
unsigned int emoji2859[] = {0x1f9cb};
unsigned int emoji2860[] = {0x1f9cd};
unsigned int emoji2861[] = {0x1f9cd,0x1f3fb};
unsigned int emoji2862[] = {0x1f9cd,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji2863[] = {0x1f9cd,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji2864[] = {0x1f9cd,0x1f3fc};
unsigned int emoji2865[] = {0x1f9cd,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji2866[] = {0x1f9cd,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji2867[] = {0x1f9cd,0x1f3fd};
unsigned int emoji2868[] = {0x1f9cd,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji2869[] = {0x1f9cd,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji2870[] = {0x1f9cd,0x1f3fe};
unsigned int emoji2871[] = {0x1f9cd,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji2872[] = {0x1f9cd,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji2873[] = {0x1f9cd,0x1f3ff};
unsigned int emoji2874[] = {0x1f9cd,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji2875[] = {0x1f9cd,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji2876[] = {0x1f9cd,0x200d,0x2640,0xfe0f};
unsigned int emoji2877[] = {0x1f9cd,0x200d,0x2642,0xfe0f};
unsigned int emoji2878[] = {0x1f9ce};
unsigned int emoji2879[] = {0x1f9ce,0x1f3fb};
unsigned int emoji2880[] = {0x1f9ce,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji2881[] = {0x1f9ce,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji2882[] = {0x1f9ce,0x1f3fc};
unsigned int emoji2883[] = {0x1f9ce,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji2884[] = {0x1f9ce,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji2885[] = {0x1f9ce,0x1f3fd};
unsigned int emoji2886[] = {0x1f9ce,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji2887[] = {0x1f9ce,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji2888[] = {0x1f9ce,0x1f3fe};
unsigned int emoji2889[] = {0x1f9ce,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji2890[] = {0x1f9ce,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji2891[] = {0x1f9ce,0x1f3ff};
unsigned int emoji2892[] = {0x1f9ce,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji2893[] = {0x1f9ce,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji2894[] = {0x1f9ce,0x200d,0x2640,0xfe0f};
unsigned int emoji2895[] = {0x1f9ce,0x200d,0x2642,0xfe0f};
unsigned int emoji2896[] = {0x1f9cf};
unsigned int emoji2897[] = {0x1f9cf,0x1f3fb};
unsigned int emoji2898[] = {0x1f9cf,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji2899[] = {0x1f9cf,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji2900[] = {0x1f9cf,0x1f3fc};
unsigned int emoji2901[] = {0x1f9cf,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji2902[] = {0x1f9cf,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji2903[] = {0x1f9cf,0x1f3fd};
unsigned int emoji2904[] = {0x1f9cf,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji2905[] = {0x1f9cf,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji2906[] = {0x1f9cf,0x1f3fe};
unsigned int emoji2907[] = {0x1f9cf,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji2908[] = {0x1f9cf,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji2909[] = {0x1f9cf,0x1f3ff};
unsigned int emoji2910[] = {0x1f9cf,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji2911[] = {0x1f9cf,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji2912[] = {0x1f9cf,0x200d,0x2640,0xfe0f};
unsigned int emoji2913[] = {0x1f9cf,0x200d,0x2642,0xfe0f};
unsigned int emoji2914[] = {0x1f9d0};
unsigned int emoji2915[] = {0x1f9d1};
unsigned int emoji2916[] = {0x1f9d1,0x1f3fb};
unsigned int emoji2917[] = {0x1f9d1,0x1f3fb,0x200d,0x1f3a4};
unsigned int emoji2918[] = {0x1f9d1,0x1f3fb,0x200d,0x1f3a8};
unsigned int emoji2919[] = {0x1f9d1,0x1f3fb,0x200d,0x1f3eb};
unsigned int emoji2920[] = {0x1f9d1,0x1f3fb,0x200d,0x1f3ed};
unsigned int emoji2921[] = {0x1f9d1,0x1f3fb,0x200d,0x1f4bb};
unsigned int emoji2922[] = {0x1f9d1,0x1f3fb,0x200d,0x1f4bc};
unsigned int emoji2923[] = {0x1f9d1,0x1f3fb,0x200d,0x1f9af};
unsigned int emoji2924[] = {0x1f9d1,0x1f3fb,0x200d,0x1f9b0};
unsigned int emoji2925[] = {0x1f9d1,0x1f3fb,0x200d,0x1f9b1};
unsigned int emoji2926[] = {0x1f9d1,0x1f3fb,0x200d,0x1f9b2};
unsigned int emoji2927[] = {0x1f9d1,0x1f3fb,0x200d,0x1f9b3};
unsigned int emoji2928[] = {0x1f9d1,0x1f3fb,0x200d,0x1f9bc};
unsigned int emoji2929[] = {0x1f9d1,0x1f3fb,0x200d,0x1f9bd};
unsigned int emoji2930[] = {0x1f9d1,0x1f3fb,0x200d,0x1f33e};
unsigned int emoji2931[] = {0x1f9d1,0x1f3fb,0x200d,0x1f37c};
unsigned int emoji2932[] = {0x1f9d1,0x1f3fb,0x200d,0x1f52c};
unsigned int emoji2933[] = {0x1f9d1,0x1f3fb,0x200d,0x1f91d,0x200d,0x1f9d1,0x1f3fb};
unsigned int emoji2934[] = {0x1f9d1,0x1f3fb,0x200d,0x1f91d,0x200d,0x1f9d1,0x1f3fc};
unsigned int emoji2935[] = {0x1f9d1,0x1f3fb,0x200d,0x1f91d,0x200d,0x1f9d1,0x1f3fd};
unsigned int emoji2936[] = {0x1f9d1,0x1f3fb,0x200d,0x1f91d,0x200d,0x1f9d1,0x1f3fe};
unsigned int emoji2937[] = {0x1f9d1,0x1f3fb,0x200d,0x1f91d,0x200d,0x1f9d1,0x1f3ff};
unsigned int emoji2938[] = {0x1f9d1,0x1f3fb,0x200d,0x1f373};
unsigned int emoji2939[] = {0x1f9d1,0x1f3fb,0x200d,0x1f384};
unsigned int emoji2940[] = {0x1f9d1,0x1f3fb,0x200d,0x1f393};
unsigned int emoji2941[] = {0x1f9d1,0x1f3fb,0x200d,0x1f527};
unsigned int emoji2942[] = {0x1f9d1,0x1f3fb,0x200d,0x1f680};
unsigned int emoji2943[] = {0x1f9d1,0x1f3fb,0x200d,0x1f692};
unsigned int emoji2944[] = {0x1f9d1,0x1f3fb,0x200d,0x2695,0xfe0f};
unsigned int emoji2945[] = {0x1f9d1,0x1f3fb,0x200d,0x2696,0xfe0f};
unsigned int emoji2946[] = {0x1f9d1,0x1f3fb,0x200d,0x2708,0xfe0f};
unsigned int emoji2947[] = {0x1f9d1,0x1f3fc};
unsigned int emoji2948[] = {0x1f9d1,0x1f3fc,0x200d,0x1f3a4};
unsigned int emoji2949[] = {0x1f9d1,0x1f3fc,0x200d,0x1f3a8};
unsigned int emoji2950[] = {0x1f9d1,0x1f3fc,0x200d,0x1f3eb};
unsigned int emoji2951[] = {0x1f9d1,0x1f3fc,0x200d,0x1f3ed};
unsigned int emoji2952[] = {0x1f9d1,0x1f3fc,0x200d,0x1f4bb};
unsigned int emoji2953[] = {0x1f9d1,0x1f3fc,0x200d,0x1f4bc};
unsigned int emoji2954[] = {0x1f9d1,0x1f3fc,0x200d,0x1f9af};
unsigned int emoji2955[] = {0x1f9d1,0x1f3fc,0x200d,0x1f9b0};
unsigned int emoji2956[] = {0x1f9d1,0x1f3fc,0x200d,0x1f9b1};
unsigned int emoji2957[] = {0x1f9d1,0x1f3fc,0x200d,0x1f9b2};
unsigned int emoji2958[] = {0x1f9d1,0x1f3fc,0x200d,0x1f9b3};
unsigned int emoji2959[] = {0x1f9d1,0x1f3fc,0x200d,0x1f9bc};
unsigned int emoji2960[] = {0x1f9d1,0x1f3fc,0x200d,0x1f9bd};
unsigned int emoji2961[] = {0x1f9d1,0x1f3fc,0x200d,0x1f33e};
unsigned int emoji2962[] = {0x1f9d1,0x1f3fc,0x200d,0x1f37c};
unsigned int emoji2963[] = {0x1f9d1,0x1f3fc,0x200d,0x1f52c};
unsigned int emoji2964[] = {0x1f9d1,0x1f3fc,0x200d,0x1f91d,0x200d,0x1f9d1,0x1f3fb};
unsigned int emoji2965[] = {0x1f9d1,0x1f3fc,0x200d,0x1f91d,0x200d,0x1f9d1,0x1f3fc};
unsigned int emoji2966[] = {0x1f9d1,0x1f3fc,0x200d,0x1f91d,0x200d,0x1f9d1,0x1f3fd};
unsigned int emoji2967[] = {0x1f9d1,0x1f3fc,0x200d,0x1f91d,0x200d,0x1f9d1,0x1f3fe};
unsigned int emoji2968[] = {0x1f9d1,0x1f3fc,0x200d,0x1f91d,0x200d,0x1f9d1,0x1f3ff};
unsigned int emoji2969[] = {0x1f9d1,0x1f3fc,0x200d,0x1f373};
unsigned int emoji2970[] = {0x1f9d1,0x1f3fc,0x200d,0x1f384};
unsigned int emoji2971[] = {0x1f9d1,0x1f3fc,0x200d,0x1f393};
unsigned int emoji2972[] = {0x1f9d1,0x1f3fc,0x200d,0x1f527};
unsigned int emoji2973[] = {0x1f9d1,0x1f3fc,0x200d,0x1f680};
unsigned int emoji2974[] = {0x1f9d1,0x1f3fc,0x200d,0x1f692};
unsigned int emoji2975[] = {0x1f9d1,0x1f3fc,0x200d,0x2695,0xfe0f};
unsigned int emoji2976[] = {0x1f9d1,0x1f3fc,0x200d,0x2696,0xfe0f};
unsigned int emoji2977[] = {0x1f9d1,0x1f3fc,0x200d,0x2708,0xfe0f};
unsigned int emoji2978[] = {0x1f9d1,0x1f3fd};
unsigned int emoji2979[] = {0x1f9d1,0x1f3fd,0x200d,0x1f3a4};
unsigned int emoji2980[] = {0x1f9d1,0x1f3fd,0x200d,0x1f3a8};
unsigned int emoji2981[] = {0x1f9d1,0x1f3fd,0x200d,0x1f3eb};
unsigned int emoji2982[] = {0x1f9d1,0x1f3fd,0x200d,0x1f3ed};
unsigned int emoji2983[] = {0x1f9d1,0x1f3fd,0x200d,0x1f4bb};
unsigned int emoji2984[] = {0x1f9d1,0x1f3fd,0x200d,0x1f4bc};
unsigned int emoji2985[] = {0x1f9d1,0x1f3fd,0x200d,0x1f9af};
unsigned int emoji2986[] = {0x1f9d1,0x1f3fd,0x200d,0x1f9b0};
unsigned int emoji2987[] = {0x1f9d1,0x1f3fd,0x200d,0x1f9b1};
unsigned int emoji2988[] = {0x1f9d1,0x1f3fd,0x200d,0x1f9b2};
unsigned int emoji2989[] = {0x1f9d1,0x1f3fd,0x200d,0x1f9b3};
unsigned int emoji2990[] = {0x1f9d1,0x1f3fd,0x200d,0x1f9bc};
unsigned int emoji2991[] = {0x1f9d1,0x1f3fd,0x200d,0x1f9bd};
unsigned int emoji2992[] = {0x1f9d1,0x1f3fd,0x200d,0x1f33e};
unsigned int emoji2993[] = {0x1f9d1,0x1f3fd,0x200d,0x1f37c};
unsigned int emoji2994[] = {0x1f9d1,0x1f3fd,0x200d,0x1f52c};
unsigned int emoji2995[] = {0x1f9d1,0x1f3fd,0x200d,0x1f91d,0x200d,0x1f9d1,0x1f3fb};
unsigned int emoji2996[] = {0x1f9d1,0x1f3fd,0x200d,0x1f91d,0x200d,0x1f9d1,0x1f3fc};
unsigned int emoji2997[] = {0x1f9d1,0x1f3fd,0x200d,0x1f91d,0x200d,0x1f9d1,0x1f3fd};
unsigned int emoji2998[] = {0x1f9d1,0x1f3fd,0x200d,0x1f91d,0x200d,0x1f9d1,0x1f3fe};
unsigned int emoji2999[] = {0x1f9d1,0x1f3fd,0x200d,0x1f91d,0x200d,0x1f9d1,0x1f3ff};
unsigned int emoji3000[] = {0x1f9d1,0x1f3fd,0x200d,0x1f373};
unsigned int emoji3001[] = {0x1f9d1,0x1f3fd,0x200d,0x1f384};
unsigned int emoji3002[] = {0x1f9d1,0x1f3fd,0x200d,0x1f393};
unsigned int emoji3003[] = {0x1f9d1,0x1f3fd,0x200d,0x1f527};
unsigned int emoji3004[] = {0x1f9d1,0x1f3fd,0x200d,0x1f680};
unsigned int emoji3005[] = {0x1f9d1,0x1f3fd,0x200d,0x1f692};
unsigned int emoji3006[] = {0x1f9d1,0x1f3fd,0x200d,0x2695,0xfe0f};
unsigned int emoji3007[] = {0x1f9d1,0x1f3fd,0x200d,0x2696,0xfe0f};
unsigned int emoji3008[] = {0x1f9d1,0x1f3fd,0x200d,0x2708,0xfe0f};
unsigned int emoji3009[] = {0x1f9d1,0x1f3fe};
unsigned int emoji3010[] = {0x1f9d1,0x1f3fe,0x200d,0x1f3a4};
unsigned int emoji3011[] = {0x1f9d1,0x1f3fe,0x200d,0x1f3a8};
unsigned int emoji3012[] = {0x1f9d1,0x1f3fe,0x200d,0x1f3eb};
unsigned int emoji3013[] = {0x1f9d1,0x1f3fe,0x200d,0x1f3ed};
unsigned int emoji3014[] = {0x1f9d1,0x1f3fe,0x200d,0x1f4bb};
unsigned int emoji3015[] = {0x1f9d1,0x1f3fe,0x200d,0x1f4bc};
unsigned int emoji3016[] = {0x1f9d1,0x1f3fe,0x200d,0x1f9af};
unsigned int emoji3017[] = {0x1f9d1,0x1f3fe,0x200d,0x1f9b0};
unsigned int emoji3018[] = {0x1f9d1,0x1f3fe,0x200d,0x1f9b1};
unsigned int emoji3019[] = {0x1f9d1,0x1f3fe,0x200d,0x1f9b2};
unsigned int emoji3020[] = {0x1f9d1,0x1f3fe,0x200d,0x1f9b3};
unsigned int emoji3021[] = {0x1f9d1,0x1f3fe,0x200d,0x1f9bc};
unsigned int emoji3022[] = {0x1f9d1,0x1f3fe,0x200d,0x1f9bd};
unsigned int emoji3023[] = {0x1f9d1,0x1f3fe,0x200d,0x1f33e};
unsigned int emoji3024[] = {0x1f9d1,0x1f3fe,0x200d,0x1f37c};
unsigned int emoji3025[] = {0x1f9d1,0x1f3fe,0x200d,0x1f52c};
unsigned int emoji3026[] = {0x1f9d1,0x1f3fe,0x200d,0x1f91d,0x200d,0x1f9d1,0x1f3fb};
unsigned int emoji3027[] = {0x1f9d1,0x1f3fe,0x200d,0x1f91d,0x200d,0x1f9d1,0x1f3fc};
unsigned int emoji3028[] = {0x1f9d1,0x1f3fe,0x200d,0x1f91d,0x200d,0x1f9d1,0x1f3fd};
unsigned int emoji3029[] = {0x1f9d1,0x1f3fe,0x200d,0x1f91d,0x200d,0x1f9d1,0x1f3fe};
unsigned int emoji3030[] = {0x1f9d1,0x1f3fe,0x200d,0x1f91d,0x200d,0x1f9d1,0x1f3ff};
unsigned int emoji3031[] = {0x1f9d1,0x1f3fe,0x200d,0x1f373};
unsigned int emoji3032[] = {0x1f9d1,0x1f3fe,0x200d,0x1f384};
unsigned int emoji3033[] = {0x1f9d1,0x1f3fe,0x200d,0x1f393};
unsigned int emoji3034[] = {0x1f9d1,0x1f3fe,0x200d,0x1f527};
unsigned int emoji3035[] = {0x1f9d1,0x1f3fe,0x200d,0x1f680};
unsigned int emoji3036[] = {0x1f9d1,0x1f3fe,0x200d,0x1f692};
unsigned int emoji3037[] = {0x1f9d1,0x1f3fe,0x200d,0x2695,0xfe0f};
unsigned int emoji3038[] = {0x1f9d1,0x1f3fe,0x200d,0x2696,0xfe0f};
unsigned int emoji3039[] = {0x1f9d1,0x1f3fe,0x200d,0x2708,0xfe0f};
unsigned int emoji3040[] = {0x1f9d1,0x1f3ff};
unsigned int emoji3041[] = {0x1f9d1,0x1f3ff,0x200d,0x1f3a4};
unsigned int emoji3042[] = {0x1f9d1,0x1f3ff,0x200d,0x1f3a8};
unsigned int emoji3043[] = {0x1f9d1,0x1f3ff,0x200d,0x1f3eb};
unsigned int emoji3044[] = {0x1f9d1,0x1f3ff,0x200d,0x1f3ed};
unsigned int emoji3045[] = {0x1f9d1,0x1f3ff,0x200d,0x1f4bb};
unsigned int emoji3046[] = {0x1f9d1,0x1f3ff,0x200d,0x1f4bc};
unsigned int emoji3047[] = {0x1f9d1,0x1f3ff,0x200d,0x1f9af};
unsigned int emoji3048[] = {0x1f9d1,0x1f3ff,0x200d,0x1f9b0};
unsigned int emoji3049[] = {0x1f9d1,0x1f3ff,0x200d,0x1f9b1};
unsigned int emoji3050[] = {0x1f9d1,0x1f3ff,0x200d,0x1f9b2};
unsigned int emoji3051[] = {0x1f9d1,0x1f3ff,0x200d,0x1f9b3};
unsigned int emoji3052[] = {0x1f9d1,0x1f3ff,0x200d,0x1f9bc};
unsigned int emoji3053[] = {0x1f9d1,0x1f3ff,0x200d,0x1f9bd};
unsigned int emoji3054[] = {0x1f9d1,0x1f3ff,0x200d,0x1f33e};
unsigned int emoji3055[] = {0x1f9d1,0x1f3ff,0x200d,0x1f37c};
unsigned int emoji3056[] = {0x1f9d1,0x1f3ff,0x200d,0x1f52c};
unsigned int emoji3057[] = {0x1f9d1,0x1f3ff,0x200d,0x1f91d,0x200d,0x1f9d1,0x1f3fb};
unsigned int emoji3058[] = {0x1f9d1,0x1f3ff,0x200d,0x1f91d,0x200d,0x1f9d1,0x1f3fc};
unsigned int emoji3059[] = {0x1f9d1,0x1f3ff,0x200d,0x1f91d,0x200d,0x1f9d1,0x1f3fd};
unsigned int emoji3060[] = {0x1f9d1,0x1f3ff,0x200d,0x1f91d,0x200d,0x1f9d1,0x1f3fe};
unsigned int emoji3061[] = {0x1f9d1,0x1f3ff,0x200d,0x1f91d,0x200d,0x1f9d1,0x1f3ff};
unsigned int emoji3062[] = {0x1f9d1,0x1f3ff,0x200d,0x1f373};
unsigned int emoji3063[] = {0x1f9d1,0x1f3ff,0x200d,0x1f384};
unsigned int emoji3064[] = {0x1f9d1,0x1f3ff,0x200d,0x1f393};
unsigned int emoji3065[] = {0x1f9d1,0x1f3ff,0x200d,0x1f527};
unsigned int emoji3066[] = {0x1f9d1,0x1f3ff,0x200d,0x1f680};
unsigned int emoji3067[] = {0x1f9d1,0x1f3ff,0x200d,0x1f692};
unsigned int emoji3068[] = {0x1f9d1,0x1f3ff,0x200d,0x2695,0xfe0f};
unsigned int emoji3069[] = {0x1f9d1,0x1f3ff,0x200d,0x2696,0xfe0f};
unsigned int emoji3070[] = {0x1f9d1,0x1f3ff,0x200d,0x2708,0xfe0f};
unsigned int emoji3071[] = {0x1f9d1,0x200d,0x1f3a4};
unsigned int emoji3072[] = {0x1f9d1,0x200d,0x1f3a8};
unsigned int emoji3073[] = {0x1f9d1,0x200d,0x1f3eb};
unsigned int emoji3074[] = {0x1f9d1,0x200d,0x1f3ed};
unsigned int emoji3075[] = {0x1f9d1,0x200d,0x1f4bb};
unsigned int emoji3076[] = {0x1f9d1,0x200d,0x1f4bc};
unsigned int emoji3077[] = {0x1f9d1,0x200d,0x1f9af};
unsigned int emoji3078[] = {0x1f9d1,0x200d,0x1f9b0};
unsigned int emoji3079[] = {0x1f9d1,0x200d,0x1f9b1};
unsigned int emoji3080[] = {0x1f9d1,0x200d,0x1f9b2};
unsigned int emoji3081[] = {0x1f9d1,0x200d,0x1f9b3};
unsigned int emoji3082[] = {0x1f9d1,0x200d,0x1f9bc};
unsigned int emoji3083[] = {0x1f9d1,0x200d,0x1f9bd};
unsigned int emoji3084[] = {0x1f9d1,0x200d,0x1f33e};
unsigned int emoji3085[] = {0x1f9d1,0x200d,0x1f37c};
unsigned int emoji3086[] = {0x1f9d1,0x200d,0x1f52c};
unsigned int emoji3087[] = {0x1f9d1,0x200d,0x1f91d,0x200d,0x1f9d1};
unsigned int emoji3088[] = {0x1f9d1,0x200d,0x1f373};
unsigned int emoji3089[] = {0x1f9d1,0x200d,0x1f384};
unsigned int emoji3090[] = {0x1f9d1,0x200d,0x1f393};
unsigned int emoji3091[] = {0x1f9d1,0x200d,0x1f527};
unsigned int emoji3092[] = {0x1f9d1,0x200d,0x1f680};
unsigned int emoji3093[] = {0x1f9d1,0x200d,0x1f692};
unsigned int emoji3094[] = {0x1f9d1,0x200d,0x2695,0xfe0f};
unsigned int emoji3095[] = {0x1f9d1,0x200d,0x2696,0xfe0f};
unsigned int emoji3096[] = {0x1f9d1,0x200d,0x2708,0xfe0f};
unsigned int emoji3097[] = {0x1f9d2};
unsigned int emoji3098[] = {0x1f9d2,0x1f3fb};
unsigned int emoji3099[] = {0x1f9d2,0x1f3fc};
unsigned int emoji3100[] = {0x1f9d2,0x1f3fd};
unsigned int emoji3101[] = {0x1f9d2,0x1f3fe};
unsigned int emoji3102[] = {0x1f9d2,0x1f3ff};
unsigned int emoji3103[] = {0x1f9d3};
unsigned int emoji3104[] = {0x1f9d3,0x1f3fb};
unsigned int emoji3105[] = {0x1f9d3,0x1f3fc};
unsigned int emoji3106[] = {0x1f9d3,0x1f3fd};
unsigned int emoji3107[] = {0x1f9d3,0x1f3fe};
unsigned int emoji3108[] = {0x1f9d3,0x1f3ff};
unsigned int emoji3109[] = {0x1f9d4};
unsigned int emoji3110[] = {0x1f9d4,0x1f3fb};
unsigned int emoji3111[] = {0x1f9d4,0x1f3fc};
unsigned int emoji3112[] = {0x1f9d4,0x1f3fd};
unsigned int emoji3113[] = {0x1f9d4,0x1f3fe};
unsigned int emoji3114[] = {0x1f9d4,0x1f3ff};
unsigned int emoji3115[] = {0x1f9d5};
unsigned int emoji3116[] = {0x1f9d5,0x1f3fb};
unsigned int emoji3117[] = {0x1f9d5,0x1f3fc};
unsigned int emoji3118[] = {0x1f9d5,0x1f3fd};
unsigned int emoji3119[] = {0x1f9d5,0x1f3fe};
unsigned int emoji3120[] = {0x1f9d5,0x1f3ff};
unsigned int emoji3121[] = {0x1f9d6};
unsigned int emoji3122[] = {0x1f9d6,0x1f3fb};
unsigned int emoji3123[] = {0x1f9d6,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji3124[] = {0x1f9d6,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji3125[] = {0x1f9d6,0x1f3fc};
unsigned int emoji3126[] = {0x1f9d6,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji3127[] = {0x1f9d6,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji3128[] = {0x1f9d6,0x1f3fd};
unsigned int emoji3129[] = {0x1f9d6,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji3130[] = {0x1f9d6,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji3131[] = {0x1f9d6,0x1f3fe};
unsigned int emoji3132[] = {0x1f9d6,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji3133[] = {0x1f9d6,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji3134[] = {0x1f9d6,0x1f3ff};
unsigned int emoji3135[] = {0x1f9d6,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji3136[] = {0x1f9d6,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji3137[] = {0x1f9d6,0x200d,0x2640,0xfe0f};
unsigned int emoji3138[] = {0x1f9d6,0x200d,0x2642,0xfe0f};
unsigned int emoji3139[] = {0x1f9d7};
unsigned int emoji3140[] = {0x1f9d7,0x1f3fb};
unsigned int emoji3141[] = {0x1f9d7,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji3142[] = {0x1f9d7,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji3143[] = {0x1f9d7,0x1f3fc};
unsigned int emoji3144[] = {0x1f9d7,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji3145[] = {0x1f9d7,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji3146[] = {0x1f9d7,0x1f3fd};
unsigned int emoji3147[] = {0x1f9d7,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji3148[] = {0x1f9d7,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji3149[] = {0x1f9d7,0x1f3fe};
unsigned int emoji3150[] = {0x1f9d7,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji3151[] = {0x1f9d7,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji3152[] = {0x1f9d7,0x1f3ff};
unsigned int emoji3153[] = {0x1f9d7,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji3154[] = {0x1f9d7,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji3155[] = {0x1f9d7,0x200d,0x2640,0xfe0f};
unsigned int emoji3156[] = {0x1f9d7,0x200d,0x2642,0xfe0f};
unsigned int emoji3157[] = {0x1f9d8};
unsigned int emoji3158[] = {0x1f9d8,0x1f3fb};
unsigned int emoji3159[] = {0x1f9d8,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji3160[] = {0x1f9d8,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji3161[] = {0x1f9d8,0x1f3fc};
unsigned int emoji3162[] = {0x1f9d8,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji3163[] = {0x1f9d8,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji3164[] = {0x1f9d8,0x1f3fd};
unsigned int emoji3165[] = {0x1f9d8,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji3166[] = {0x1f9d8,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji3167[] = {0x1f9d8,0x1f3fe};
unsigned int emoji3168[] = {0x1f9d8,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji3169[] = {0x1f9d8,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji3170[] = {0x1f9d8,0x1f3ff};
unsigned int emoji3171[] = {0x1f9d8,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji3172[] = {0x1f9d8,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji3173[] = {0x1f9d8,0x200d,0x2640,0xfe0f};
unsigned int emoji3174[] = {0x1f9d8,0x200d,0x2642,0xfe0f};
unsigned int emoji3175[] = {0x1f9d9};
unsigned int emoji3176[] = {0x1f9d9,0x1f3fb};
unsigned int emoji3177[] = {0x1f9d9,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji3178[] = {0x1f9d9,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji3179[] = {0x1f9d9,0x1f3fc};
unsigned int emoji3180[] = {0x1f9d9,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji3181[] = {0x1f9d9,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji3182[] = {0x1f9d9,0x1f3fd};
unsigned int emoji3183[] = {0x1f9d9,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji3184[] = {0x1f9d9,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji3185[] = {0x1f9d9,0x1f3fe};
unsigned int emoji3186[] = {0x1f9d9,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji3187[] = {0x1f9d9,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji3188[] = {0x1f9d9,0x1f3ff};
unsigned int emoji3189[] = {0x1f9d9,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji3190[] = {0x1f9d9,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji3191[] = {0x1f9d9,0x200d,0x2640,0xfe0f};
unsigned int emoji3192[] = {0x1f9d9,0x200d,0x2642,0xfe0f};
unsigned int emoji3193[] = {0x1f9da};
unsigned int emoji3194[] = {0x1f9da,0x1f3fb};
unsigned int emoji3195[] = {0x1f9da,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji3196[] = {0x1f9da,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji3197[] = {0x1f9da,0x1f3fc};
unsigned int emoji3198[] = {0x1f9da,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji3199[] = {0x1f9da,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji3200[] = {0x1f9da,0x1f3fd};
unsigned int emoji3201[] = {0x1f9da,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji3202[] = {0x1f9da,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji3203[] = {0x1f9da,0x1f3fe};
unsigned int emoji3204[] = {0x1f9da,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji3205[] = {0x1f9da,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji3206[] = {0x1f9da,0x1f3ff};
unsigned int emoji3207[] = {0x1f9da,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji3208[] = {0x1f9da,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji3209[] = {0x1f9da,0x200d,0x2640,0xfe0f};
unsigned int emoji3210[] = {0x1f9da,0x200d,0x2642,0xfe0f};
unsigned int emoji3211[] = {0x1f9db};
unsigned int emoji3212[] = {0x1f9db,0x1f3fb};
unsigned int emoji3213[] = {0x1f9db,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji3214[] = {0x1f9db,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji3215[] = {0x1f9db,0x1f3fc};
unsigned int emoji3216[] = {0x1f9db,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji3217[] = {0x1f9db,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji3218[] = {0x1f9db,0x1f3fd};
unsigned int emoji3219[] = {0x1f9db,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji3220[] = {0x1f9db,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji3221[] = {0x1f9db,0x1f3fe};
unsigned int emoji3222[] = {0x1f9db,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji3223[] = {0x1f9db,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji3224[] = {0x1f9db,0x1f3ff};
unsigned int emoji3225[] = {0x1f9db,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji3226[] = {0x1f9db,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji3227[] = {0x1f9db,0x200d,0x2640,0xfe0f};
unsigned int emoji3228[] = {0x1f9db,0x200d,0x2642,0xfe0f};
unsigned int emoji3229[] = {0x1f9dc};
unsigned int emoji3230[] = {0x1f9dc,0x1f3fb};
unsigned int emoji3231[] = {0x1f9dc,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji3232[] = {0x1f9dc,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji3233[] = {0x1f9dc,0x1f3fc};
unsigned int emoji3234[] = {0x1f9dc,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji3235[] = {0x1f9dc,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji3236[] = {0x1f9dc,0x1f3fd};
unsigned int emoji3237[] = {0x1f9dc,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji3238[] = {0x1f9dc,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji3239[] = {0x1f9dc,0x1f3fe};
unsigned int emoji3240[] = {0x1f9dc,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji3241[] = {0x1f9dc,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji3242[] = {0x1f9dc,0x1f3ff};
unsigned int emoji3243[] = {0x1f9dc,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji3244[] = {0x1f9dc,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji3245[] = {0x1f9dc,0x200d,0x2640,0xfe0f};
unsigned int emoji3246[] = {0x1f9dc,0x200d,0x2642,0xfe0f};
unsigned int emoji3247[] = {0x1f9dd};
unsigned int emoji3248[] = {0x1f9dd,0x1f3fb};
unsigned int emoji3249[] = {0x1f9dd,0x1f3fb,0x200d,0x2640,0xfe0f};
unsigned int emoji3250[] = {0x1f9dd,0x1f3fb,0x200d,0x2642,0xfe0f};
unsigned int emoji3251[] = {0x1f9dd,0x1f3fc};
unsigned int emoji3252[] = {0x1f9dd,0x1f3fc,0x200d,0x2640,0xfe0f};
unsigned int emoji3253[] = {0x1f9dd,0x1f3fc,0x200d,0x2642,0xfe0f};
unsigned int emoji3254[] = {0x1f9dd,0x1f3fd};
unsigned int emoji3255[] = {0x1f9dd,0x1f3fd,0x200d,0x2640,0xfe0f};
unsigned int emoji3256[] = {0x1f9dd,0x1f3fd,0x200d,0x2642,0xfe0f};
unsigned int emoji3257[] = {0x1f9dd,0x1f3fe};
unsigned int emoji3258[] = {0x1f9dd,0x1f3fe,0x200d,0x2640,0xfe0f};
unsigned int emoji3259[] = {0x1f9dd,0x1f3fe,0x200d,0x2642,0xfe0f};
unsigned int emoji3260[] = {0x1f9dd,0x1f3ff};
unsigned int emoji3261[] = {0x1f9dd,0x1f3ff,0x200d,0x2640,0xfe0f};
unsigned int emoji3262[] = {0x1f9dd,0x1f3ff,0x200d,0x2642,0xfe0f};
unsigned int emoji3263[] = {0x1f9dd,0x200d,0x2640,0xfe0f};
unsigned int emoji3264[] = {0x1f9dd,0x200d,0x2642,0xfe0f};
unsigned int emoji3265[] = {0x1f9de};
unsigned int emoji3266[] = {0x1f9de,0x200d,0x2640,0xfe0f};
unsigned int emoji3267[] = {0x1f9de,0x200d,0x2642,0xfe0f};
unsigned int emoji3268[] = {0x1f9df};
unsigned int emoji3269[] = {0x1f9df,0x200d,0x2640,0xfe0f};
unsigned int emoji3270[] = {0x1f9df,0x200d,0x2642,0xfe0f};
unsigned int emoji3271[] = {0x1f9e0};
unsigned int emoji3272[] = {0x1f9e1};
unsigned int emoji3273[] = {0x1f9e2};
unsigned int emoji3274[] = {0x1f9e3};
unsigned int emoji3275[] = {0x1f9e4};
unsigned int emoji3276[] = {0x1f9e5};
unsigned int emoji3277[] = {0x1f9e6};
unsigned int emoji3278[] = {0x1f9e7};
unsigned int emoji3279[] = {0x1f9e8};
unsigned int emoji3280[] = {0x1f9e9};
unsigned int emoji3281[] = {0x1f9ea};
unsigned int emoji3282[] = {0x1f9eb};
unsigned int emoji3283[] = {0x1f9ec};
unsigned int emoji3284[] = {0x1f9ed};
unsigned int emoji3285[] = {0x1f9ee};
unsigned int emoji3286[] = {0x1f9ef};
unsigned int emoji3287[] = {0x1f9f0};
unsigned int emoji3288[] = {0x1f9f1};
unsigned int emoji3289[] = {0x1f9f2};
unsigned int emoji3290[] = {0x1f9f3};
unsigned int emoji3291[] = {0x1f9f4};
unsigned int emoji3292[] = {0x1f9f5};
unsigned int emoji3293[] = {0x1f9f6};
unsigned int emoji3294[] = {0x1f9f7};
unsigned int emoji3295[] = {0x1f9f8};
unsigned int emoji3296[] = {0x1f9f9};
unsigned int emoji3297[] = {0x1f9fa};
unsigned int emoji3298[] = {0x1f9fb};
unsigned int emoji3299[] = {0x1f9fc};
unsigned int emoji3300[] = {0x1f9fd};
unsigned int emoji3301[] = {0x1f9fe};
unsigned int emoji3302[] = {0x1f9ff};
unsigned int emoji3303[] = {0x1fa70};
unsigned int emoji3304[] = {0x1fa71};
unsigned int emoji3305[] = {0x1fa72};
unsigned int emoji3306[] = {0x1fa73};
unsigned int emoji3307[] = {0x1fa74};
unsigned int emoji3308[] = {0x1fa78};
unsigned int emoji3309[] = {0x1fa79};
unsigned int emoji3310[] = {0x1fa7a};
unsigned int emoji3311[] = {0x1fa80};
unsigned int emoji3312[] = {0x1fa81};
unsigned int emoji3313[] = {0x1fa82};
unsigned int emoji3314[] = {0x1fa83};
unsigned int emoji3315[] = {0x1fa84};
unsigned int emoji3316[] = {0x1fa85};
unsigned int emoji3317[] = {0x1fa86};
unsigned int emoji3318[] = {0x1fa90};
unsigned int emoji3319[] = {0x1fa91};
unsigned int emoji3320[] = {0x1fa92};
unsigned int emoji3321[] = {0x1fa93};
unsigned int emoji3322[] = {0x1fa94};
unsigned int emoji3323[] = {0x1fa95};
unsigned int emoji3324[] = {0x1fa96};
unsigned int emoji3325[] = {0x1fa97};
unsigned int emoji3326[] = {0x1fa98};
unsigned int emoji3327[] = {0x1fa99};
unsigned int emoji3328[] = {0x1fa9a};
unsigned int emoji3329[] = {0x1fa9b};
unsigned int emoji3330[] = {0x1fa9c};
unsigned int emoji3331[] = {0x1fa9d};
unsigned int emoji3332[] = {0x1fa9e};
unsigned int emoji3333[] = {0x1fa9f};
unsigned int emoji3334[] = {0x1faa0};
unsigned int emoji3335[] = {0x1faa1};
unsigned int emoji3336[] = {0x1faa2};
unsigned int emoji3337[] = {0x1faa3};
unsigned int emoji3338[] = {0x1faa4};
unsigned int emoji3339[] = {0x1faa5};
unsigned int emoji3340[] = {0x1faa6};
unsigned int emoji3341[] = {0x1faa7};
unsigned int emoji3342[] = {0x1faa8};
unsigned int emoji3343[] = {0x1fab0};
unsigned int emoji3344[] = {0x1fab1};
unsigned int emoji3345[] = {0x1fab2};
unsigned int emoji3346[] = {0x1fab3};
unsigned int emoji3347[] = {0x1fab4};
unsigned int emoji3348[] = {0x1fab5};
unsigned int emoji3349[] = {0x1fab6};
unsigned int emoji3350[] = {0x1fac0};
unsigned int emoji3351[] = {0x1fac1};
unsigned int emoji3352[] = {0x1fac2};
unsigned int emoji3353[] = {0x1fad0};
unsigned int emoji3354[] = {0x1fad1};
unsigned int emoji3355[] = {0x1fad2};
unsigned int emoji3356[] = {0x1fad3};
unsigned int emoji3357[] = {0x1fad4};
unsigned int emoji3358[] = {0x1fad5};
unsigned int emoji3359[] = {0x1fad6};

const unsigned int *emojiCodepoints[] = {emoji0,emoji1,emoji2,emoji3,emoji4,emoji5,emoji6,emoji7,emoji8,emoji9,emoji10,emoji11,emoji12,emoji13,emoji14,emoji15,emoji16,emoji17,emoji18,emoji19,emoji20,emoji21,emoji22,emoji23,emoji24,emoji25,emoji26,emoji27,emoji28,emoji29,emoji30,emoji31,emoji32,emoji33,emoji34,emoji35,emoji36,emoji37,emoji38,emoji39,emoji40,emoji41,emoji42,emoji43,emoji44,emoji45,emoji46,emoji47,emoji48,emoji49,emoji50,emoji51,emoji52,emoji53,emoji54,emoji55,emoji56,emoji57,emoji58,emoji59,emoji60,emoji61,emoji62,emoji63,emoji64,emoji65,emoji66,emoji67,emoji68,emoji69,emoji70,emoji71,emoji72,emoji73,emoji74,emoji75,emoji76,emoji77,emoji78,emoji79,emoji80,emoji81,emoji82,emoji83,emoji84,emoji85,emoji86,emoji87,emoji88,emoji89,emoji90,emoji91,emoji92,emoji93,emoji94,emoji95,emoji96,emoji97,emoji98,emoji99,emoji100,emoji101,emoji102,emoji103,emoji104,emoji105,emoji106,emoji107,emoji108,emoji109,emoji110,emoji111,emoji112,emoji113,emoji114,emoji115,emoji116,emoji117,emoji118,emoji119,emoji120,emoji121,emoji122,emoji123,emoji124,emoji125,emoji126,emoji127,emoji128,emoji129,emoji130,emoji131,emoji132,emoji133,emoji134,emoji135,emoji136,emoji137,emoji138,emoji139,emoji140,emoji141,emoji142,emoji143,emoji144,emoji145,emoji146,emoji147,emoji148,emoji149,emoji150,emoji151,emoji152,emoji153,emoji154,emoji155,emoji156,emoji157,emoji158,emoji159,emoji160,emoji161,emoji162,emoji163,emoji164,emoji165,emoji166,emoji167,emoji168,emoji169,emoji170,emoji171,emoji172,emoji173,emoji174,emoji175,emoji176,emoji177,emoji178,emoji179,emoji180,emoji181,emoji182,emoji183,emoji184,emoji185,emoji186,emoji187,emoji188,emoji189,emoji190,emoji191,emoji192,emoji193,emoji194,emoji195,emoji196,emoji197,emoji198,emoji199,emoji200,emoji201,emoji202,emoji203,emoji204,emoji205,emoji206,emoji207,emoji208,emoji209,emoji210,emoji211,emoji212,emoji213,emoji214,emoji215,emoji216,emoji217,emoji218,emoji219,emoji220,emoji221,emoji222,emoji223,emoji224,emoji225,emoji226,emoji227,emoji228,emoji229,emoji230,emoji231,emoji232,emoji233,emoji234,emoji235,emoji236,emoji237,emoji238,emoji239,emoji240,emoji241,emoji242,emoji243,emoji244,emoji245,emoji246,emoji247,emoji248,emoji249,emoji250,emoji251,emoji252,emoji253,emoji254,emoji255,emoji256,emoji257,emoji258,emoji259,emoji260,emoji261,emoji262,emoji263,emoji264,emoji265,emoji266,emoji267,emoji268,emoji269,emoji270,emoji271,emoji272,emoji273,emoji274,emoji275,emoji276,emoji277,emoji278,emoji279,emoji280,emoji281,emoji282,emoji283,emoji284,emoji285,emoji286,emoji287,emoji288,emoji289,emoji290,emoji291,emoji292,emoji293,emoji294,emoji295,emoji296,emoji297,emoji298,emoji299,emoji300,emoji301,emoji302,emoji303,emoji304,emoji305,emoji306,emoji307,emoji308,emoji309,emoji310,emoji311,emoji312,emoji313,emoji314,emoji315,emoji316,emoji317,emoji318,emoji319,emoji320,emoji321,emoji322,emoji323,emoji324,emoji325,emoji326,emoji327,emoji328,emoji329,emoji330,emoji331,emoji332,emoji333,emoji334,emoji335,emoji336,emoji337,emoji338,emoji339,emoji340,emoji341,emoji342,emoji343,emoji344,emoji345,emoji346,emoji347,emoji348,emoji349,emoji350,emoji351,emoji352,emoji353,emoji354,emoji355,emoji356,emoji357,emoji358,emoji359,emoji360,emoji361,emoji362,emoji363,emoji364,emoji365,emoji366,emoji367,emoji368,emoji369,emoji370,emoji371,emoji372,emoji373,emoji374,emoji375,emoji376,emoji377,emoji378,emoji379,emoji380,emoji381,emoji382,emoji383,emoji384,emoji385,emoji386,emoji387,emoji388,emoji389,emoji390,emoji391,emoji392,emoji393,emoji394,emoji395,emoji396,emoji397,emoji398,emoji399,emoji400,emoji401,emoji402,emoji403,emoji404,emoji405,emoji406,emoji407,emoji408,emoji409,emoji410,emoji411,emoji412,emoji413,emoji414,emoji415,emoji416,emoji417,emoji418,emoji419,emoji420,emoji421,emoji422,emoji423,emoji424,emoji425,emoji426,emoji427,emoji428,emoji429,emoji430,emoji431,emoji432,emoji433,emoji434,emoji435,emoji436,emoji437,emoji438,emoji439,emoji440,emoji441,emoji442,emoji443,emoji444,emoji445,emoji446,emoji447,emoji448,emoji449,emoji450,emoji451,emoji452,emoji453,emoji454,emoji455,emoji456,emoji457,emoji458,emoji459,emoji460,emoji461,emoji462,emoji463,emoji464,emoji465,emoji466,emoji467,emoji468,emoji469,emoji470,emoji471,emoji472,emoji473,emoji474,emoji475,emoji476,emoji477,emoji478,emoji479,emoji480,emoji481,emoji482,emoji483,emoji484,emoji485,emoji486,emoji487,emoji488,emoji489,emoji490,emoji491,emoji492,emoji493,emoji494,emoji495,emoji496,emoji497,emoji498,emoji499,emoji500,emoji501,emoji502,emoji503,emoji504,emoji505,emoji506,emoji507,emoji508,emoji509,emoji510,emoji511,emoji512,emoji513,emoji514,emoji515,emoji516,emoji517,emoji518,emoji519,emoji520,emoji521,emoji522,emoji523,emoji524,emoji525,emoji526,emoji527,emoji528,emoji529,emoji530,emoji531,emoji532,emoji533,emoji534,emoji535,emoji536,emoji537,emoji538,emoji539,emoji540,emoji541,emoji542,emoji543,emoji544,emoji545,emoji546,emoji547,emoji548,emoji549,emoji550,emoji551,emoji552,emoji553,emoji554,emoji555,emoji556,emoji557,emoji558,emoji559,emoji560,emoji561,emoji562,emoji563,emoji564,emoji565,emoji566,emoji567,emoji568,emoji569,emoji570,emoji571,emoji572,emoji573,emoji574,emoji575,emoji576,emoji577,emoji578,emoji579,emoji580,emoji581,emoji582,emoji583,emoji584,emoji585,emoji586,emoji587,emoji588,emoji589,emoji590,emoji591,emoji592,emoji593,emoji594,emoji595,emoji596,emoji597,emoji598,emoji599,emoji600,emoji601,emoji602,emoji603,emoji604,emoji605,emoji606,emoji607,emoji608,emoji609,emoji610,emoji611,emoji612,emoji613,emoji614,emoji615,emoji616,emoji617,emoji618,emoji619,emoji620,emoji621,emoji622,emoji623,emoji624,emoji625,emoji626,emoji627,emoji628,emoji629,emoji630,emoji631,emoji632,emoji633,emoji634,emoji635,emoji636,emoji637,emoji638,emoji639,emoji640,emoji641,emoji642,emoji643,emoji644,emoji645,emoji646,emoji647,emoji648,emoji649,emoji650,emoji651,emoji652,emoji653,emoji654,emoji655,emoji656,emoji657,emoji658,emoji659,emoji660,emoji661,emoji662,emoji663,emoji664,emoji665,emoji666,emoji667,emoji668,emoji669,emoji670,emoji671,emoji672,emoji673,emoji674,emoji675,emoji676,emoji677,emoji678,emoji679,emoji680,emoji681,emoji682,emoji683,emoji684,emoji685,emoji686,emoji687,emoji688,emoji689,emoji690,emoji691,emoji692,emoji693,emoji694,emoji695,emoji696,emoji697,emoji698,emoji699,emoji700,emoji701,emoji702,emoji703,emoji704,emoji705,emoji706,emoji707,emoji708,emoji709,emoji710,emoji711,emoji712,emoji713,emoji714,emoji715,emoji716,emoji717,emoji718,emoji719,emoji720,emoji721,emoji722,emoji723,emoji724,emoji725,emoji726,emoji727,emoji728,emoji729,emoji730,emoji731,emoji732,emoji733,emoji734,emoji735,emoji736,emoji737,emoji738,emoji739,emoji740,emoji741,emoji742,emoji743,emoji744,emoji745,emoji746,emoji747,emoji748,emoji749,emoji750,emoji751,emoji752,emoji753,emoji754,emoji755,emoji756,emoji757,emoji758,emoji759,emoji760,emoji761,emoji762,emoji763,emoji764,emoji765,emoji766,emoji767,emoji768,emoji769,emoji770,emoji771,emoji772,emoji773,emoji774,emoji775,emoji776,emoji777,emoji778,emoji779,emoji780,emoji781,emoji782,emoji783,emoji784,emoji785,emoji786,emoji787,emoji788,emoji789,emoji790,emoji791,emoji792,emoji793,emoji794,emoji795,emoji796,emoji797,emoji798,emoji799,emoji800,emoji801,emoji802,emoji803,emoji804,emoji805,emoji806,emoji807,emoji808,emoji809,emoji810,emoji811,emoji812,emoji813,emoji814,emoji815,emoji816,emoji817,emoji818,emoji819,emoji820,emoji821,emoji822,emoji823,emoji824,emoji825,emoji826,emoji827,emoji828,emoji829,emoji830,emoji831,emoji832,emoji833,emoji834,emoji835,emoji836,emoji837,emoji838,emoji839,emoji840,emoji841,emoji842,emoji843,emoji844,emoji845,emoji846,emoji847,emoji848,emoji849,emoji850,emoji851,emoji852,emoji853,emoji854,emoji855,emoji856,emoji857,emoji858,emoji859,emoji860,emoji861,emoji862,emoji863,emoji864,emoji865,emoji866,emoji867,emoji868,emoji869,emoji870,emoji871,emoji872,emoji873,emoji874,emoji875,emoji876,emoji877,emoji878,emoji879,emoji880,emoji881,emoji882,emoji883,emoji884,emoji885,emoji886,emoji887,emoji888,emoji889,emoji890,emoji891,emoji892,emoji893,emoji894,emoji895,emoji896,emoji897,emoji898,emoji899,emoji900,emoji901,emoji902,emoji903,emoji904,emoji905,emoji906,emoji907,emoji908,emoji909,emoji910,emoji911,emoji912,emoji913,emoji914,emoji915,emoji916,emoji917,emoji918,emoji919,emoji920,emoji921,emoji922,emoji923,emoji924,emoji925,emoji926,emoji927,emoji928,emoji929,emoji930,emoji931,emoji932,emoji933,emoji934,emoji935,emoji936,emoji937,emoji938,emoji939,emoji940,emoji941,emoji942,emoji943,emoji944,emoji945,emoji946,emoji947,emoji948,emoji949,emoji950,emoji951,emoji952,emoji953,emoji954,emoji955,emoji956,emoji957,emoji958,emoji959,emoji960,emoji961,emoji962,emoji963,emoji964,emoji965,emoji966,emoji967,emoji968,emoji969,emoji970,emoji971,emoji972,emoji973,emoji974,emoji975,emoji976,emoji977,emoji978,emoji979,emoji980,emoji981,emoji982,emoji983,emoji984,emoji985,emoji986,emoji987,emoji988,emoji989,emoji990,emoji991,emoji992,emoji993,emoji994,emoji995,emoji996,emoji997,emoji998,emoji999,emoji1000,emoji1001,emoji1002,emoji1003,emoji1004,emoji1005,emoji1006,emoji1007,emoji1008,emoji1009,emoji1010,emoji1011,emoji1012,emoji1013,emoji1014,emoji1015,emoji1016,emoji1017,emoji1018,emoji1019,emoji1020,emoji1021,emoji1022,emoji1023,emoji1024,emoji1025,emoji1026,emoji1027,emoji1028,emoji1029,emoji1030,emoji1031,emoji1032,emoji1033,emoji1034,emoji1035,emoji1036,emoji1037,emoji1038,emoji1039,emoji1040,emoji1041,emoji1042,emoji1043,emoji1044,emoji1045,emoji1046,emoji1047,emoji1048,emoji1049,emoji1050,emoji1051,emoji1052,emoji1053,emoji1054,emoji1055,emoji1056,emoji1057,emoji1058,emoji1059,emoji1060,emoji1061,emoji1062,emoji1063,emoji1064,emoji1065,emoji1066,emoji1067,emoji1068,emoji1069,emoji1070,emoji1071,emoji1072,emoji1073,emoji1074,emoji1075,emoji1076,emoji1077,emoji1078,emoji1079,emoji1080,emoji1081,emoji1082,emoji1083,emoji1084,emoji1085,emoji1086,emoji1087,emoji1088,emoji1089,emoji1090,emoji1091,emoji1092,emoji1093,emoji1094,emoji1095,emoji1096,emoji1097,emoji1098,emoji1099,emoji1100,emoji1101,emoji1102,emoji1103,emoji1104,emoji1105,emoji1106,emoji1107,emoji1108,emoji1109,emoji1110,emoji1111,emoji1112,emoji1113,emoji1114,emoji1115,emoji1116,emoji1117,emoji1118,emoji1119,emoji1120,emoji1121,emoji1122,emoji1123,emoji1124,emoji1125,emoji1126,emoji1127,emoji1128,emoji1129,emoji1130,emoji1131,emoji1132,emoji1133,emoji1134,emoji1135,emoji1136,emoji1137,emoji1138,emoji1139,emoji1140,emoji1141,emoji1142,emoji1143,emoji1144,emoji1145,emoji1146,emoji1147,emoji1148,emoji1149,emoji1150,emoji1151,emoji1152,emoji1153,emoji1154,emoji1155,emoji1156,emoji1157,emoji1158,emoji1159,emoji1160,emoji1161,emoji1162,emoji1163,emoji1164,emoji1165,emoji1166,emoji1167,emoji1168,emoji1169,emoji1170,emoji1171,emoji1172,emoji1173,emoji1174,emoji1175,emoji1176,emoji1177,emoji1178,emoji1179,emoji1180,emoji1181,emoji1182,emoji1183,emoji1184,emoji1185,emoji1186,emoji1187,emoji1188,emoji1189,emoji1190,emoji1191,emoji1192,emoji1193,emoji1194,emoji1195,emoji1196,emoji1197,emoji1198,emoji1199,emoji1200,emoji1201,emoji1202,emoji1203,emoji1204,emoji1205,emoji1206,emoji1207,emoji1208,emoji1209,emoji1210,emoji1211,emoji1212,emoji1213,emoji1214,emoji1215,emoji1216,emoji1217,emoji1218,emoji1219,emoji1220,emoji1221,emoji1222,emoji1223,emoji1224,emoji1225,emoji1226,emoji1227,emoji1228,emoji1229,emoji1230,emoji1231,emoji1232,emoji1233,emoji1234,emoji1235,emoji1236,emoji1237,emoji1238,emoji1239,emoji1240,emoji1241,emoji1242,emoji1243,emoji1244,emoji1245,emoji1246,emoji1247,emoji1248,emoji1249,emoji1250,emoji1251,emoji1252,emoji1253,emoji1254,emoji1255,emoji1256,emoji1257,emoji1258,emoji1259,emoji1260,emoji1261,emoji1262,emoji1263,emoji1264,emoji1265,emoji1266,emoji1267,emoji1268,emoji1269,emoji1270,emoji1271,emoji1272,emoji1273,emoji1274,emoji1275,emoji1276,emoji1277,emoji1278,emoji1279,emoji1280,emoji1281,emoji1282,emoji1283,emoji1284,emoji1285,emoji1286,emoji1287,emoji1288,emoji1289,emoji1290,emoji1291,emoji1292,emoji1293,emoji1294,emoji1295,emoji1296,emoji1297,emoji1298,emoji1299,emoji1300,emoji1301,emoji1302,emoji1303,emoji1304,emoji1305,emoji1306,emoji1307,emoji1308,emoji1309,emoji1310,emoji1311,emoji1312,emoji1313,emoji1314,emoji1315,emoji1316,emoji1317,emoji1318,emoji1319,emoji1320,emoji1321,emoji1322,emoji1323,emoji1324,emoji1325,emoji1326,emoji1327,emoji1328,emoji1329,emoji1330,emoji1331,emoji1332,emoji1333,emoji1334,emoji1335,emoji1336,emoji1337,emoji1338,emoji1339,emoji1340,emoji1341,emoji1342,emoji1343,emoji1344,emoji1345,emoji1346,emoji1347,emoji1348,emoji1349,emoji1350,emoji1351,emoji1352,emoji1353,emoji1354,emoji1355,emoji1356,emoji1357,emoji1358,emoji1359,emoji1360,emoji1361,emoji1362,emoji1363,emoji1364,emoji1365,emoji1366,emoji1367,emoji1368,emoji1369,emoji1370,emoji1371,emoji1372,emoji1373,emoji1374,emoji1375,emoji1376,emoji1377,emoji1378,emoji1379,emoji1380,emoji1381,emoji1382,emoji1383,emoji1384,emoji1385,emoji1386,emoji1387,emoji1388,emoji1389,emoji1390,emoji1391,emoji1392,emoji1393,emoji1394,emoji1395,emoji1396,emoji1397,emoji1398,emoji1399,emoji1400,emoji1401,emoji1402,emoji1403,emoji1404,emoji1405,emoji1406,emoji1407,emoji1408,emoji1409,emoji1410,emoji1411,emoji1412,emoji1413,emoji1414,emoji1415,emoji1416,emoji1417,emoji1418,emoji1419,emoji1420,emoji1421,emoji1422,emoji1423,emoji1424,emoji1425,emoji1426,emoji1427,emoji1428,emoji1429,emoji1430,emoji1431,emoji1432,emoji1433,emoji1434,emoji1435,emoji1436,emoji1437,emoji1438,emoji1439,emoji1440,emoji1441,emoji1442,emoji1443,emoji1444,emoji1445,emoji1446,emoji1447,emoji1448,emoji1449,emoji1450,emoji1451,emoji1452,emoji1453,emoji1454,emoji1455,emoji1456,emoji1457,emoji1458,emoji1459,emoji1460,emoji1461,emoji1462,emoji1463,emoji1464,emoji1465,emoji1466,emoji1467,emoji1468,emoji1469,emoji1470,emoji1471,emoji1472,emoji1473,emoji1474,emoji1475,emoji1476,emoji1477,emoji1478,emoji1479,emoji1480,emoji1481,emoji1482,emoji1483,emoji1484,emoji1485,emoji1486,emoji1487,emoji1488,emoji1489,emoji1490,emoji1491,emoji1492,emoji1493,emoji1494,emoji1495,emoji1496,emoji1497,emoji1498,emoji1499,emoji1500,emoji1501,emoji1502,emoji1503,emoji1504,emoji1505,emoji1506,emoji1507,emoji1508,emoji1509,emoji1510,emoji1511,emoji1512,emoji1513,emoji1514,emoji1515,emoji1516,emoji1517,emoji1518,emoji1519,emoji1520,emoji1521,emoji1522,emoji1523,emoji1524,emoji1525,emoji1526,emoji1527,emoji1528,emoji1529,emoji1530,emoji1531,emoji1532,emoji1533,emoji1534,emoji1535,emoji1536,emoji1537,emoji1538,emoji1539,emoji1540,emoji1541,emoji1542,emoji1543,emoji1544,emoji1545,emoji1546,emoji1547,emoji1548,emoji1549,emoji1550,emoji1551,emoji1552,emoji1553,emoji1554,emoji1555,emoji1556,emoji1557,emoji1558,emoji1559,emoji1560,emoji1561,emoji1562,emoji1563,emoji1564,emoji1565,emoji1566,emoji1567,emoji1568,emoji1569,emoji1570,emoji1571,emoji1572,emoji1573,emoji1574,emoji1575,emoji1576,emoji1577,emoji1578,emoji1579,emoji1580,emoji1581,emoji1582,emoji1583,emoji1584,emoji1585,emoji1586,emoji1587,emoji1588,emoji1589,emoji1590,emoji1591,emoji1592,emoji1593,emoji1594,emoji1595,emoji1596,emoji1597,emoji1598,emoji1599,emoji1600,emoji1601,emoji1602,emoji1603,emoji1604,emoji1605,emoji1606,emoji1607,emoji1608,emoji1609,emoji1610,emoji1611,emoji1612,emoji1613,emoji1614,emoji1615,emoji1616,emoji1617,emoji1618,emoji1619,emoji1620,emoji1621,emoji1622,emoji1623,emoji1624,emoji1625,emoji1626,emoji1627,emoji1628,emoji1629,emoji1630,emoji1631,emoji1632,emoji1633,emoji1634,emoji1635,emoji1636,emoji1637,emoji1638,emoji1639,emoji1640,emoji1641,emoji1642,emoji1643,emoji1644,emoji1645,emoji1646,emoji1647,emoji1648,emoji1649,emoji1650,emoji1651,emoji1652,emoji1653,emoji1654,emoji1655,emoji1656,emoji1657,emoji1658,emoji1659,emoji1660,emoji1661,emoji1662,emoji1663,emoji1664,emoji1665,emoji1666,emoji1667,emoji1668,emoji1669,emoji1670,emoji1671,emoji1672,emoji1673,emoji1674,emoji1675,emoji1676,emoji1677,emoji1678,emoji1679,emoji1680,emoji1681,emoji1682,emoji1683,emoji1684,emoji1685,emoji1686,emoji1687,emoji1688,emoji1689,emoji1690,emoji1691,emoji1692,emoji1693,emoji1694,emoji1695,emoji1696,emoji1697,emoji1698,emoji1699,emoji1700,emoji1701,emoji1702,emoji1703,emoji1704,emoji1705,emoji1706,emoji1707,emoji1708,emoji1709,emoji1710,emoji1711,emoji1712,emoji1713,emoji1714,emoji1715,emoji1716,emoji1717,emoji1718,emoji1719,emoji1720,emoji1721,emoji1722,emoji1723,emoji1724,emoji1725,emoji1726,emoji1727,emoji1728,emoji1729,emoji1730,emoji1731,emoji1732,emoji1733,emoji1734,emoji1735,emoji1736,emoji1737,emoji1738,emoji1739,emoji1740,emoji1741,emoji1742,emoji1743,emoji1744,emoji1745,emoji1746,emoji1747,emoji1748,emoji1749,emoji1750,emoji1751,emoji1752,emoji1753,emoji1754,emoji1755,emoji1756,emoji1757,emoji1758,emoji1759,emoji1760,emoji1761,emoji1762,emoji1763,emoji1764,emoji1765,emoji1766,emoji1767,emoji1768,emoji1769,emoji1770,emoji1771,emoji1772,emoji1773,emoji1774,emoji1775,emoji1776,emoji1777,emoji1778,emoji1779,emoji1780,emoji1781,emoji1782,emoji1783,emoji1784,emoji1785,emoji1786,emoji1787,emoji1788,emoji1789,emoji1790,emoji1791,emoji1792,emoji1793,emoji1794,emoji1795,emoji1796,emoji1797,emoji1798,emoji1799,emoji1800,emoji1801,emoji1802,emoji1803,emoji1804,emoji1805,emoji1806,emoji1807,emoji1808,emoji1809,emoji1810,emoji1811,emoji1812,emoji1813,emoji1814,emoji1815,emoji1816,emoji1817,emoji1818,emoji1819,emoji1820,emoji1821,emoji1822,emoji1823,emoji1824,emoji1825,emoji1826,emoji1827,emoji1828,emoji1829,emoji1830,emoji1831,emoji1832,emoji1833,emoji1834,emoji1835,emoji1836,emoji1837,emoji1838,emoji1839,emoji1840,emoji1841,emoji1842,emoji1843,emoji1844,emoji1845,emoji1846,emoji1847,emoji1848,emoji1849,emoji1850,emoji1851,emoji1852,emoji1853,emoji1854,emoji1855,emoji1856,emoji1857,emoji1858,emoji1859,emoji1860,emoji1861,emoji1862,emoji1863,emoji1864,emoji1865,emoji1866,emoji1867,emoji1868,emoji1869,emoji1870,emoji1871,emoji1872,emoji1873,emoji1874,emoji1875,emoji1876,emoji1877,emoji1878,emoji1879,emoji1880,emoji1881,emoji1882,emoji1883,emoji1884,emoji1885,emoji1886,emoji1887,emoji1888,emoji1889,emoji1890,emoji1891,emoji1892,emoji1893,emoji1894,emoji1895,emoji1896,emoji1897,emoji1898,emoji1899,emoji1900,emoji1901,emoji1902,emoji1903,emoji1904,emoji1905,emoji1906,emoji1907,emoji1908,emoji1909,emoji1910,emoji1911,emoji1912,emoji1913,emoji1914,emoji1915,emoji1916,emoji1917,emoji1918,emoji1919,emoji1920,emoji1921,emoji1922,emoji1923,emoji1924,emoji1925,emoji1926,emoji1927,emoji1928,emoji1929,emoji1930,emoji1931,emoji1932,emoji1933,emoji1934,emoji1935,emoji1936,emoji1937,emoji1938,emoji1939,emoji1940,emoji1941,emoji1942,emoji1943,emoji1944,emoji1945,emoji1946,emoji1947,emoji1948,emoji1949,emoji1950,emoji1951,emoji1952,emoji1953,emoji1954,emoji1955,emoji1956,emoji1957,emoji1958,emoji1959,emoji1960,emoji1961,emoji1962,emoji1963,emoji1964,emoji1965,emoji1966,emoji1967,emoji1968,emoji1969,emoji1970,emoji1971,emoji1972,emoji1973,emoji1974,emoji1975,emoji1976,emoji1977,emoji1978,emoji1979,emoji1980,emoji1981,emoji1982,emoji1983,emoji1984,emoji1985,emoji1986,emoji1987,emoji1988,emoji1989,emoji1990,emoji1991,emoji1992,emoji1993,emoji1994,emoji1995,emoji1996,emoji1997,emoji1998,emoji1999,emoji2000,emoji2001,emoji2002,emoji2003,emoji2004,emoji2005,emoji2006,emoji2007,emoji2008,emoji2009,emoji2010,emoji2011,emoji2012,emoji2013,emoji2014,emoji2015,emoji2016,emoji2017,emoji2018,emoji2019,emoji2020,emoji2021,emoji2022,emoji2023,emoji2024,emoji2025,emoji2026,emoji2027,emoji2028,emoji2029,emoji2030,emoji2031,emoji2032,emoji2033,emoji2034,emoji2035,emoji2036,emoji2037,emoji2038,emoji2039,emoji2040,emoji2041,emoji2042,emoji2043,emoji2044,emoji2045,emoji2046,emoji2047,emoji2048,emoji2049,emoji2050,emoji2051,emoji2052,emoji2053,emoji2054,emoji2055,emoji2056,emoji2057,emoji2058,emoji2059,emoji2060,emoji2061,emoji2062,emoji2063,emoji2064,emoji2065,emoji2066,emoji2067,emoji2068,emoji2069,emoji2070,emoji2071,emoji2072,emoji2073,emoji2074,emoji2075,emoji2076,emoji2077,emoji2078,emoji2079,emoji2080,emoji2081,emoji2082,emoji2083,emoji2084,emoji2085,emoji2086,emoji2087,emoji2088,emoji2089,emoji2090,emoji2091,emoji2092,emoji2093,emoji2094,emoji2095,emoji2096,emoji2097,emoji2098,emoji2099,emoji2100,emoji2101,emoji2102,emoji2103,emoji2104,emoji2105,emoji2106,emoji2107,emoji2108,emoji2109,emoji2110,emoji2111,emoji2112,emoji2113,emoji2114,emoji2115,emoji2116,emoji2117,emoji2118,emoji2119,emoji2120,emoji2121,emoji2122,emoji2123,emoji2124,emoji2125,emoji2126,emoji2127,emoji2128,emoji2129,emoji2130,emoji2131,emoji2132,emoji2133,emoji2134,emoji2135,emoji2136,emoji2137,emoji2138,emoji2139,emoji2140,emoji2141,emoji2142,emoji2143,emoji2144,emoji2145,emoji2146,emoji2147,emoji2148,emoji2149,emoji2150,emoji2151,emoji2152,emoji2153,emoji2154,emoji2155,emoji2156,emoji2157,emoji2158,emoji2159,emoji2160,emoji2161,emoji2162,emoji2163,emoji2164,emoji2165,emoji2166,emoji2167,emoji2168,emoji2169,emoji2170,emoji2171,emoji2172,emoji2173,emoji2174,emoji2175,emoji2176,emoji2177,emoji2178,emoji2179,emoji2180,emoji2181,emoji2182,emoji2183,emoji2184,emoji2185,emoji2186,emoji2187,emoji2188,emoji2189,emoji2190,emoji2191,emoji2192,emoji2193,emoji2194,emoji2195,emoji2196,emoji2197,emoji2198,emoji2199,emoji2200,emoji2201,emoji2202,emoji2203,emoji2204,emoji2205,emoji2206,emoji2207,emoji2208,emoji2209,emoji2210,emoji2211,emoji2212,emoji2213,emoji2214,emoji2215,emoji2216,emoji2217,emoji2218,emoji2219,emoji2220,emoji2221,emoji2222,emoji2223,emoji2224,emoji2225,emoji2226,emoji2227,emoji2228,emoji2229,emoji2230,emoji2231,emoji2232,emoji2233,emoji2234,emoji2235,emoji2236,emoji2237,emoji2238,emoji2239,emoji2240,emoji2241,emoji2242,emoji2243,emoji2244,emoji2245,emoji2246,emoji2247,emoji2248,emoji2249,emoji2250,emoji2251,emoji2252,emoji2253,emoji2254,emoji2255,emoji2256,emoji2257,emoji2258,emoji2259,emoji2260,emoji2261,emoji2262,emoji2263,emoji2264,emoji2265,emoji2266,emoji2267,emoji2268,emoji2269,emoji2270,emoji2271,emoji2272,emoji2273,emoji2274,emoji2275,emoji2276,emoji2277,emoji2278,emoji2279,emoji2280,emoji2281,emoji2282,emoji2283,emoji2284,emoji2285,emoji2286,emoji2287,emoji2288,emoji2289,emoji2290,emoji2291,emoji2292,emoji2293,emoji2294,emoji2295,emoji2296,emoji2297,emoji2298,emoji2299,emoji2300,emoji2301,emoji2302,emoji2303,emoji2304,emoji2305,emoji2306,emoji2307,emoji2308,emoji2309,emoji2310,emoji2311,emoji2312,emoji2313,emoji2314,emoji2315,emoji2316,emoji2317,emoji2318,emoji2319,emoji2320,emoji2321,emoji2322,emoji2323,emoji2324,emoji2325,emoji2326,emoji2327,emoji2328,emoji2329,emoji2330,emoji2331,emoji2332,emoji2333,emoji2334,emoji2335,emoji2336,emoji2337,emoji2338,emoji2339,emoji2340,emoji2341,emoji2342,emoji2343,emoji2344,emoji2345,emoji2346,emoji2347,emoji2348,emoji2349,emoji2350,emoji2351,emoji2352,emoji2353,emoji2354,emoji2355,emoji2356,emoji2357,emoji2358,emoji2359,emoji2360,emoji2361,emoji2362,emoji2363,emoji2364,emoji2365,emoji2366,emoji2367,emoji2368,emoji2369,emoji2370,emoji2371,emoji2372,emoji2373,emoji2374,emoji2375,emoji2376,emoji2377,emoji2378,emoji2379,emoji2380,emoji2381,emoji2382,emoji2383,emoji2384,emoji2385,emoji2386,emoji2387,emoji2388,emoji2389,emoji2390,emoji2391,emoji2392,emoji2393,emoji2394,emoji2395,emoji2396,emoji2397,emoji2398,emoji2399,emoji2400,emoji2401,emoji2402,emoji2403,emoji2404,emoji2405,emoji2406,emoji2407,emoji2408,emoji2409,emoji2410,emoji2411,emoji2412,emoji2413,emoji2414,emoji2415,emoji2416,emoji2417,emoji2418,emoji2419,emoji2420,emoji2421,emoji2422,emoji2423,emoji2424,emoji2425,emoji2426,emoji2427,emoji2428,emoji2429,emoji2430,emoji2431,emoji2432,emoji2433,emoji2434,emoji2435,emoji2436,emoji2437,emoji2438,emoji2439,emoji2440,emoji2441,emoji2442,emoji2443,emoji2444,emoji2445,emoji2446,emoji2447,emoji2448,emoji2449,emoji2450,emoji2451,emoji2452,emoji2453,emoji2454,emoji2455,emoji2456,emoji2457,emoji2458,emoji2459,emoji2460,emoji2461,emoji2462,emoji2463,emoji2464,emoji2465,emoji2466,emoji2467,emoji2468,emoji2469,emoji2470,emoji2471,emoji2472,emoji2473,emoji2474,emoji2475,emoji2476,emoji2477,emoji2478,emoji2479,emoji2480,emoji2481,emoji2482,emoji2483,emoji2484,emoji2485,emoji2486,emoji2487,emoji2488,emoji2489,emoji2490,emoji2491,emoji2492,emoji2493,emoji2494,emoji2495,emoji2496,emoji2497,emoji2498,emoji2499,emoji2500,emoji2501,emoji2502,emoji2503,emoji2504,emoji2505,emoji2506,emoji2507,emoji2508,emoji2509,emoji2510,emoji2511,emoji2512,emoji2513,emoji2514,emoji2515,emoji2516,emoji2517,emoji2518,emoji2519,emoji2520,emoji2521,emoji2522,emoji2523,emoji2524,emoji2525,emoji2526,emoji2527,emoji2528,emoji2529,emoji2530,emoji2531,emoji2532,emoji2533,emoji2534,emoji2535,emoji2536,emoji2537,emoji2538,emoji2539,emoji2540,emoji2541,emoji2542,emoji2543,emoji2544,emoji2545,emoji2546,emoji2547,emoji2548,emoji2549,emoji2550,emoji2551,emoji2552,emoji2553,emoji2554,emoji2555,emoji2556,emoji2557,emoji2558,emoji2559,emoji2560,emoji2561,emoji2562,emoji2563,emoji2564,emoji2565,emoji2566,emoji2567,emoji2568,emoji2569,emoji2570,emoji2571,emoji2572,emoji2573,emoji2574,emoji2575,emoji2576,emoji2577,emoji2578,emoji2579,emoji2580,emoji2581,emoji2582,emoji2583,emoji2584,emoji2585,emoji2586,emoji2587,emoji2588,emoji2589,emoji2590,emoji2591,emoji2592,emoji2593,emoji2594,emoji2595,emoji2596,emoji2597,emoji2598,emoji2599,emoji2600,emoji2601,emoji2602,emoji2603,emoji2604,emoji2605,emoji2606,emoji2607,emoji2608,emoji2609,emoji2610,emoji2611,emoji2612,emoji2613,emoji2614,emoji2615,emoji2616,emoji2617,emoji2618,emoji2619,emoji2620,emoji2621,emoji2622,emoji2623,emoji2624,emoji2625,emoji2626,emoji2627,emoji2628,emoji2629,emoji2630,emoji2631,emoji2632,emoji2633,emoji2634,emoji2635,emoji2636,emoji2637,emoji2638,emoji2639,emoji2640,emoji2641,emoji2642,emoji2643,emoji2644,emoji2645,emoji2646,emoji2647,emoji2648,emoji2649,emoji2650,emoji2651,emoji2652,emoji2653,emoji2654,emoji2655,emoji2656,emoji2657,emoji2658,emoji2659,emoji2660,emoji2661,emoji2662,emoji2663,emoji2664,emoji2665,emoji2666,emoji2667,emoji2668,emoji2669,emoji2670,emoji2671,emoji2672,emoji2673,emoji2674,emoji2675,emoji2676,emoji2677,emoji2678,emoji2679,emoji2680,emoji2681,emoji2682,emoji2683,emoji2684,emoji2685,emoji2686,emoji2687,emoji2688,emoji2689,emoji2690,emoji2691,emoji2692,emoji2693,emoji2694,emoji2695,emoji2696,emoji2697,emoji2698,emoji2699,emoji2700,emoji2701,emoji2702,emoji2703,emoji2704,emoji2705,emoji2706,emoji2707,emoji2708,emoji2709,emoji2710,emoji2711,emoji2712,emoji2713,emoji2714,emoji2715,emoji2716,emoji2717,emoji2718,emoji2719,emoji2720,emoji2721,emoji2722,emoji2723,emoji2724,emoji2725,emoji2726,emoji2727,emoji2728,emoji2729,emoji2730,emoji2731,emoji2732,emoji2733,emoji2734,emoji2735,emoji2736,emoji2737,emoji2738,emoji2739,emoji2740,emoji2741,emoji2742,emoji2743,emoji2744,emoji2745,emoji2746,emoji2747,emoji2748,emoji2749,emoji2750,emoji2751,emoji2752,emoji2753,emoji2754,emoji2755,emoji2756,emoji2757,emoji2758,emoji2759,emoji2760,emoji2761,emoji2762,emoji2763,emoji2764,emoji2765,emoji2766,emoji2767,emoji2768,emoji2769,emoji2770,emoji2771,emoji2772,emoji2773,emoji2774,emoji2775,emoji2776,emoji2777,emoji2778,emoji2779,emoji2780,emoji2781,emoji2782,emoji2783,emoji2784,emoji2785,emoji2786,emoji2787,emoji2788,emoji2789,emoji2790,emoji2791,emoji2792,emoji2793,emoji2794,emoji2795,emoji2796,emoji2797,emoji2798,emoji2799,emoji2800,emoji2801,emoji2802,emoji2803,emoji2804,emoji2805,emoji2806,emoji2807,emoji2808,emoji2809,emoji2810,emoji2811,emoji2812,emoji2813,emoji2814,emoji2815,emoji2816,emoji2817,emoji2818,emoji2819,emoji2820,emoji2821,emoji2822,emoji2823,emoji2824,emoji2825,emoji2826,emoji2827,emoji2828,emoji2829,emoji2830,emoji2831,emoji2832,emoji2833,emoji2834,emoji2835,emoji2836,emoji2837,emoji2838,emoji2839,emoji2840,emoji2841,emoji2842,emoji2843,emoji2844,emoji2845,emoji2846,emoji2847,emoji2848,emoji2849,emoji2850,emoji2851,emoji2852,emoji2853,emoji2854,emoji2855,emoji2856,emoji2857,emoji2858,emoji2859,emoji2860,emoji2861,emoji2862,emoji2863,emoji2864,emoji2865,emoji2866,emoji2867,emoji2868,emoji2869,emoji2870,emoji2871,emoji2872,emoji2873,emoji2874,emoji2875,emoji2876,emoji2877,emoji2878,emoji2879,emoji2880,emoji2881,emoji2882,emoji2883,emoji2884,emoji2885,emoji2886,emoji2887,emoji2888,emoji2889,emoji2890,emoji2891,emoji2892,emoji2893,emoji2894,emoji2895,emoji2896,emoji2897,emoji2898,emoji2899,emoji2900,emoji2901,emoji2902,emoji2903,emoji2904,emoji2905,emoji2906,emoji2907,emoji2908,emoji2909,emoji2910,emoji2911,emoji2912,emoji2913,emoji2914,emoji2915,emoji2916,emoji2917,emoji2918,emoji2919,emoji2920,emoji2921,emoji2922,emoji2923,emoji2924,emoji2925,emoji2926,emoji2927,emoji2928,emoji2929,emoji2930,emoji2931,emoji2932,emoji2933,emoji2934,emoji2935,emoji2936,emoji2937,emoji2938,emoji2939,emoji2940,emoji2941,emoji2942,emoji2943,emoji2944,emoji2945,emoji2946,emoji2947,emoji2948,emoji2949,emoji2950,emoji2951,emoji2952,emoji2953,emoji2954,emoji2955,emoji2956,emoji2957,emoji2958,emoji2959,emoji2960,emoji2961,emoji2962,emoji2963,emoji2964,emoji2965,emoji2966,emoji2967,emoji2968,emoji2969,emoji2970,emoji2971,emoji2972,emoji2973,emoji2974,emoji2975,emoji2976,emoji2977,emoji2978,emoji2979,emoji2980,emoji2981,emoji2982,emoji2983,emoji2984,emoji2985,emoji2986,emoji2987,emoji2988,emoji2989,emoji2990,emoji2991,emoji2992,emoji2993,emoji2994,emoji2995,emoji2996,emoji2997,emoji2998,emoji2999,emoji3000,emoji3001,emoji3002,emoji3003,emoji3004,emoji3005,emoji3006,emoji3007,emoji3008,emoji3009,emoji3010,emoji3011,emoji3012,emoji3013,emoji3014,emoji3015,emoji3016,emoji3017,emoji3018,emoji3019,emoji3020,emoji3021,emoji3022,emoji3023,emoji3024,emoji3025,emoji3026,emoji3027,emoji3028,emoji3029,emoji3030,emoji3031,emoji3032,emoji3033,emoji3034,emoji3035,emoji3036,emoji3037,emoji3038,emoji3039,emoji3040,emoji3041,emoji3042,emoji3043,emoji3044,emoji3045,emoji3046,emoji3047,emoji3048,emoji3049,emoji3050,emoji3051,emoji3052,emoji3053,emoji3054,emoji3055,emoji3056,emoji3057,emoji3058,emoji3059,emoji3060,emoji3061,emoji3062,emoji3063,emoji3064,emoji3065,emoji3066,emoji3067,emoji3068,emoji3069,emoji3070,emoji3071,emoji3072,emoji3073,emoji3074,emoji3075,emoji3076,emoji3077,emoji3078,emoji3079,emoji3080,emoji3081,emoji3082,emoji3083,emoji3084,emoji3085,emoji3086,emoji3087,emoji3088,emoji3089,emoji3090,emoji3091,emoji3092,emoji3093,emoji3094,emoji3095,emoji3096,emoji3097,emoji3098,emoji3099,emoji3100,emoji3101,emoji3102,emoji3103,emoji3104,emoji3105,emoji3106,emoji3107,emoji3108,emoji3109,emoji3110,emoji3111,emoji3112,emoji3113,emoji3114,emoji3115,emoji3116,emoji3117,emoji3118,emoji3119,emoji3120,emoji3121,emoji3122,emoji3123,emoji3124,emoji3125,emoji3126,emoji3127,emoji3128,emoji3129,emoji3130,emoji3131,emoji3132,emoji3133,emoji3134,emoji3135,emoji3136,emoji3137,emoji3138,emoji3139,emoji3140,emoji3141,emoji3142,emoji3143,emoji3144,emoji3145,emoji3146,emoji3147,emoji3148,emoji3149,emoji3150,emoji3151,emoji3152,emoji3153,emoji3154,emoji3155,emoji3156,emoji3157,emoji3158,emoji3159,emoji3160,emoji3161,emoji3162,emoji3163,emoji3164,emoji3165,emoji3166,emoji3167,emoji3168,emoji3169,emoji3170,emoji3171,emoji3172,emoji3173,emoji3174,emoji3175,emoji3176,emoji3177,emoji3178,emoji3179,emoji3180,emoji3181,emoji3182,emoji3183,emoji3184,emoji3185,emoji3186,emoji3187,emoji3188,emoji3189,emoji3190,emoji3191,emoji3192,emoji3193,emoji3194,emoji3195,emoji3196,emoji3197,emoji3198,emoji3199,emoji3200,emoji3201,emoji3202,emoji3203,emoji3204,emoji3205,emoji3206,emoji3207,emoji3208,emoji3209,emoji3210,emoji3211,emoji3212,emoji3213,emoji3214,emoji3215,emoji3216,emoji3217,emoji3218,emoji3219,emoji3220,emoji3221,emoji3222,emoji3223,emoji3224,emoji3225,emoji3226,emoji3227,emoji3228,emoji3229,emoji3230,emoji3231,emoji3232,emoji3233,emoji3234,emoji3235,emoji3236,emoji3237,emoji3238,emoji3239,emoji3240,emoji3241,emoji3242,emoji3243,emoji3244,emoji3245,emoji3246,emoji3247,emoji3248,emoji3249,emoji3250,emoji3251,emoji3252,emoji3253,emoji3254,emoji3255,emoji3256,emoji3257,emoji3258,emoji3259,emoji3260,emoji3261,emoji3262,emoji3263,emoji3264,emoji3265,emoji3266,emoji3267,emoji3268,emoji3269,emoji3270,emoji3271,emoji3272,emoji3273,emoji3274,emoji3275,emoji3276,emoji3277,emoji3278,emoji3279,emoji3280,emoji3281,emoji3282,emoji3283,emoji3284,emoji3285,emoji3286,emoji3287,emoji3288,emoji3289,emoji3290,emoji3291,emoji3292,emoji3293,emoji3294,emoji3295,emoji3296,emoji3297,emoji3298,emoji3299,emoji3300,emoji3301,emoji3302,emoji3303,emoji3304,emoji3305,emoji3306,emoji3307,emoji3308,emoji3309,emoji3310,emoji3311,emoji3312,emoji3313,emoji3314,emoji3315,emoji3316,emoji3317,emoji3318,emoji3319,emoji3320,emoji3321,emoji3322,emoji3323,emoji3324,emoji3325,emoji3326,emoji3327,emoji3328,emoji3329,emoji3330,emoji3331,emoji3332,emoji3333,emoji3334,emoji3335,emoji3336,emoji3337,emoji3338,emoji3339,emoji3340,emoji3341,emoji3342,emoji3343,emoji3344,emoji3345,emoji3346,emoji3347,emoji3348,emoji3349,emoji3350,emoji3351,emoji3352,emoji3353,emoji3354,emoji3355,emoji3356,emoji3357,emoji3358,emoji3359};

const char *emojiFilenames[] = {
	"23-20e3",
	"2a-20e3",
	"30-20e3",
	"31-20e3",
	"32-20e3",
	"33-20e3",
	"34-20e3",
	"35-20e3",
	"36-20e3",
	"37-20e3",
	"38-20e3",
	"39-20e3",
	"a9",
	"ae",
	"203c",
	"2049",
	"2122",
	"2139",
	"2194",
	"2195",
	"2196",
	"2197",
	"2198",
	"2199",
	"21a9",
	"21aa",
	"231a",
	"231b",
	"2328",
	"23cf",
	"23e9",
	"23ea",
	"23eb",
	"23ec",
	"23ed",
	"23ee",
	"23ef",
	"23f0",
	"23f1",
	"23f2",
	"23f3",
	"23f8",
	"23f9",
	"23fa",
	"24c2",
	"25aa",
	"25ab",
	"25b6",
	"25c0",
	"25fb",
	"25fc",
	"25fd",
	"25fe",
	"2600",
	"2601",
	"2602",
	"2603",
	"2604",
	"260e",
	"2611",
	"2614",
	"2615",
	"2618",
	"261d",
	"261d-1f3fb",
	"261d-1f3fc",
	"261d-1f3fd",
	"261d-1f3fe",
	"261d-1f3ff",
	"2620",
	"2622",
	"2623",
	"2626",
	"262a",
	"262e",
	"262f",
	"2638",
	"2639",
	"263a",
	"2640",
	"2642",
	"2648",
	"2649",
	"264a",
	"264b",
	"264c",
	"264d",
	"264e",
	"264f",
	"2650",
	"2651",
	"2652",
	"2653",
	"265f",
	"2660",
	"2663",
	"2665",
	"2666",
	"2668",
	"267b",
	"267e",
	"267f",
	"2692",
	"2693",
	"2694",
	"2695",
	"2696",
	"2697",
	"2699",
	"269b",
	"269c",
	"26a0",
	"26a1",
	"26a7",
	"26aa",
	"26ab",
	"26b0",
	"26b1",
	"26bd",
	"26be",
	"26c4",
	"26c5",
	"26c8",
	"26ce",
	"26cf",
	"26d1",
	"26d3",
	"26d4",
	"26e9",
	"26ea",
	"26f0",
	"26f1",
	"26f2",
	"26f3",
	"26f4",
	"26f5",
	"26f7",
	"26f7-1f3fb",
	"26f7-1f3fc",
	"26f7-1f3fd",
	"26f7-1f3fe",
	"26f7-1f3ff",
	"26f8",
	"26f9",
	"26f9-1f3fb",
	"26f9-1f3fb-200d-2640-fe0f",
	"26f9-1f3fb-200d-2642-fe0f",
	"26f9-1f3fc",
	"26f9-1f3fc-200d-2640-fe0f",
	"26f9-1f3fc-200d-2642-fe0f",
	"26f9-1f3fd",
	"26f9-1f3fd-200d-2640-fe0f",
	"26f9-1f3fd-200d-2642-fe0f",
	"26f9-1f3fe",
	"26f9-1f3fe-200d-2640-fe0f",
	"26f9-1f3fe-200d-2642-fe0f",
	"26f9-1f3ff",
	"26f9-1f3ff-200d-2640-fe0f",
	"26f9-1f3ff-200d-2642-fe0f",
	"26f9-fe0f-200d-2640-fe0f",
	"26f9-fe0f-200d-2642-fe0f",
	"26fa",
	"26fd",
	"2702",
	"2705",
	"2708",
	"2709",
	"270a",
	"270a-1f3fb",
	"270a-1f3fc",
	"270a-1f3fd",
	"270a-1f3fe",
	"270a-1f3ff",
	"270b",
	"270b-1f3fb",
	"270b-1f3fc",
	"270b-1f3fd",
	"270b-1f3fe",
	"270b-1f3ff",
	"270c",
	"270c-1f3fb",
	"270c-1f3fc",
	"270c-1f3fd",
	"270c-1f3fe",
	"270c-1f3ff",
	"270d",
	"270d-1f3fb",
	"270d-1f3fc",
	"270d-1f3fd",
	"270d-1f3fe",
	"270d-1f3ff",
	"270f",
	"2712",
	"2714",
	"2716",
	"271d",
	"2721",
	"2728",
	"2733",
	"2734",
	"2744",
	"2747",
	"274c",
	"274e",
	"2753",
	"2754",
	"2755",
	"2757",
	"2763",
	"2764",
	"2795",
	"2796",
	"2797",
	"27a1",
	"27b0",
	"27bf",
	"2934",
	"2935",
	"2b05",
	"2b06",
	"2b07",
	"2b1b",
	"2b1c",
	"2b50",
	"2b55",
	"3030",
	"303d",
	"3297",
	"3299",
	"e50a",
	"1f004",
	"1f0cf",
	"1f170",
	"1f171",
	"1f17e",
	"1f17f",
	"1f18e",
	"1f191",
	"1f192",
	"1f193",
	"1f194",
	"1f195",
	"1f196",
	"1f197",
	"1f198",
	"1f199",
	"1f19a",
	"1f1e6",
	"1f1e6-1f1e8",
	"1f1e6-1f1e9",
	"1f1e6-1f1ea",
	"1f1e6-1f1eb",
	"1f1e6-1f1ec",
	"1f1e6-1f1ee",
	"1f1e6-1f1f1",
	"1f1e6-1f1f2",
	"1f1e6-1f1f4",
	"1f1e6-1f1f6",
	"1f1e6-1f1f7",
	"1f1e6-1f1f8",
	"1f1e6-1f1f9",
	"1f1e6-1f1fa",
	"1f1e6-1f1fc",
	"1f1e6-1f1fd",
	"1f1e6-1f1ff",
	"1f1e7",
	"1f1e7-1f1e6",
	"1f1e7-1f1e7",
	"1f1e7-1f1e9",
	"1f1e7-1f1ea",
	"1f1e7-1f1eb",
	"1f1e7-1f1ec",
	"1f1e7-1f1ed",
	"1f1e7-1f1ee",
	"1f1e7-1f1ef",
	"1f1e7-1f1f1",
	"1f1e7-1f1f2",
	"1f1e7-1f1f3",
	"1f1e7-1f1f4",
	"1f1e7-1f1f6",
	"1f1e7-1f1f7",
	"1f1e7-1f1f8",
	"1f1e7-1f1f9",
	"1f1e7-1f1fb",
	"1f1e7-1f1fc",
	"1f1e7-1f1fe",
	"1f1e7-1f1ff",
	"1f1e8",
	"1f1e8-1f1e6",
	"1f1e8-1f1e8",
	"1f1e8-1f1e9",
	"1f1e8-1f1eb",
	"1f1e8-1f1ec",
	"1f1e8-1f1ed",
	"1f1e8-1f1ee",
	"1f1e8-1f1f0",
	"1f1e8-1f1f1",
	"1f1e8-1f1f2",
	"1f1e8-1f1f3",
	"1f1e8-1f1f4",
	"1f1e8-1f1f5",
	"1f1e8-1f1f7",
	"1f1e8-1f1fa",
	"1f1e8-1f1fb",
	"1f1e8-1f1fc",
	"1f1e8-1f1fd",
	"1f1e8-1f1fe",
	"1f1e8-1f1ff",
	"1f1e9",
	"1f1e9-1f1ea",
	"1f1e9-1f1ec",
	"1f1e9-1f1ef",
	"1f1e9-1f1f0",
	"1f1e9-1f1f2",
	"1f1e9-1f1f4",
	"1f1e9-1f1ff",
	"1f1ea",
	"1f1ea-1f1e6",
	"1f1ea-1f1e8",
	"1f1ea-1f1ea",
	"1f1ea-1f1ec",
	"1f1ea-1f1ed",
	"1f1ea-1f1f7",
	"1f1ea-1f1f8",
	"1f1ea-1f1f9",
	"1f1ea-1f1fa",
	"1f1eb",
	"1f1eb-1f1ee",
	"1f1eb-1f1ef",
	"1f1eb-1f1f0",
	"1f1eb-1f1f2",
	"1f1eb-1f1f4",
	"1f1eb-1f1f7",
	"1f1ec",
	"1f1ec-1f1e6",
	"1f1ec-1f1e7",
	"1f1ec-1f1e9",
	"1f1ec-1f1ea",
	"1f1ec-1f1eb",
	"1f1ec-1f1ec",
	"1f1ec-1f1ed",
	"1f1ec-1f1ee",
	"1f1ec-1f1f1",
	"1f1ec-1f1f2",
	"1f1ec-1f1f3",
	"1f1ec-1f1f5",
	"1f1ec-1f1f6",
	"1f1ec-1f1f7",
	"1f1ec-1f1f8",
	"1f1ec-1f1f9",
	"1f1ec-1f1fa",
	"1f1ec-1f1fc",
	"1f1ec-1f1fe",
	"1f1ed",
	"1f1ed-1f1f0",
	"1f1ed-1f1f2",
	"1f1ed-1f1f3",
	"1f1ed-1f1f7",
	"1f1ed-1f1f9",
	"1f1ed-1f1fa",
	"1f1ee",
	"1f1ee-1f1e8",
	"1f1ee-1f1e9",
	"1f1ee-1f1ea",
	"1f1ee-1f1f1",
	"1f1ee-1f1f2",
	"1f1ee-1f1f3",
	"1f1ee-1f1f4",
	"1f1ee-1f1f6",
	"1f1ee-1f1f7",
	"1f1ee-1f1f8",
	"1f1ee-1f1f9",
	"1f1ef",
	"1f1ef-1f1ea",
	"1f1ef-1f1f2",
	"1f1ef-1f1f4",
	"1f1ef-1f1f5",
	"1f1f0",
	"1f1f0-1f1ea",
	"1f1f0-1f1ec",
	"1f1f0-1f1ed",
	"1f1f0-1f1ee",
	"1f1f0-1f1f2",
	"1f1f0-1f1f3",
	"1f1f0-1f1f5",
	"1f1f0-1f1f7",
	"1f1f0-1f1fc",
	"1f1f0-1f1fe",
	"1f1f0-1f1ff",
	"1f1f1",
	"1f1f1-1f1e6",
	"1f1f1-1f1e7",
	"1f1f1-1f1e8",
	"1f1f1-1f1ee",
	"1f1f1-1f1f0",
	"1f1f1-1f1f7",
	"1f1f1-1f1f8",
	"1f1f1-1f1f9",
	"1f1f1-1f1fa",
	"1f1f1-1f1fb",
	"1f1f1-1f1fe",
	"1f1f2",
	"1f1f2-1f1e6",
	"1f1f2-1f1e8",
	"1f1f2-1f1e9",
	"1f1f2-1f1ea",
	"1f1f2-1f1eb",
	"1f1f2-1f1ec",
	"1f1f2-1f1ed",
	"1f1f2-1f1f0",
	"1f1f2-1f1f1",
	"1f1f2-1f1f2",
	"1f1f2-1f1f3",
	"1f1f2-1f1f4",
	"1f1f2-1f1f5",
	"1f1f2-1f1f6",
	"1f1f2-1f1f7",
	"1f1f2-1f1f8",
	"1f1f2-1f1f9",
	"1f1f2-1f1fa",
	"1f1f2-1f1fb",
	"1f1f2-1f1fc",
	"1f1f2-1f1fd",
	"1f1f2-1f1fe",
	"1f1f2-1f1ff",
	"1f1f3",
	"1f1f3-1f1e6",
	"1f1f3-1f1e8",
	"1f1f3-1f1ea",
	"1f1f3-1f1eb",
	"1f1f3-1f1ec",
	"1f1f3-1f1ee",
	"1f1f3-1f1f1",
	"1f1f3-1f1f4",
	"1f1f3-1f1f5",
	"1f1f3-1f1f7",
	"1f1f3-1f1fa",
	"1f1f3-1f1ff",
	"1f1f4",
	"1f1f4-1f1f2",
	"1f1f5",
	"1f1f5-1f1e6",
	"1f1f5-1f1ea",
	"1f1f5-1f1eb",
	"1f1f5-1f1ec",
	"1f1f5-1f1ed",
	"1f1f5-1f1f0",
	"1f1f5-1f1f1",
	"1f1f5-1f1f2",
	"1f1f5-1f1f3",
	"1f1f5-1f1f7",
	"1f1f5-1f1f8",
	"1f1f5-1f1f9",
	"1f1f5-1f1fc",
	"1f1f5-1f1fe",
	"1f1f6",
	"1f1f6-1f1e6",
	"1f1f7",
	"1f1f7-1f1ea",
	"1f1f7-1f1f4",
	"1f1f7-1f1f8",
	"1f1f7-1f1fa",
	"1f1f7-1f1fc",
	"1f1f8",
	"1f1f8-1f1e6",
	"1f1f8-1f1e7",
	"1f1f8-1f1e8",
	"1f1f8-1f1e9",
	"1f1f8-1f1ea",
	"1f1f8-1f1ec",
	"1f1f8-1f1ed",
	"1f1f8-1f1ee",
	"1f1f8-1f1ef",
	"1f1f8-1f1f0",
	"1f1f8-1f1f1",
	"1f1f8-1f1f2",
	"1f1f8-1f1f3",
	"1f1f8-1f1f4",
	"1f1f8-1f1f7",
	"1f1f8-1f1f8",
	"1f1f8-1f1f9",
	"1f1f8-1f1fb",
	"1f1f8-1f1fd",
	"1f1f8-1f1fe",
	"1f1f8-1f1ff",
	"1f1f9",
	"1f1f9-1f1e6",
	"1f1f9-1f1e8",
	"1f1f9-1f1e9",
	"1f1f9-1f1eb",
	"1f1f9-1f1ec",
	"1f1f9-1f1ed",
	"1f1f9-1f1ef",
	"1f1f9-1f1f0",
	"1f1f9-1f1f1",
	"1f1f9-1f1f2",
	"1f1f9-1f1f3",
	"1f1f9-1f1f4",
	"1f1f9-1f1f7",
	"1f1f9-1f1f9",
	"1f1f9-1f1fb",
	"1f1f9-1f1fc",
	"1f1f9-1f1ff",
	"1f1fa",
	"1f1fa-1f1e6",
	"1f1fa-1f1ec",
	"1f1fa-1f1f2",
	"1f1fa-1f1f3",
	"1f1fa-1f1f8",
	"1f1fa-1f1fe",
	"1f1fa-1f1ff",
	"1f1fb",
	"1f1fb-1f1e6",
	"1f1fb-1f1e8",
	"1f1fb-1f1ea",
	"1f1fb-1f1ec",
	"1f1fb-1f1ee",
	"1f1fb-1f1f3",
	"1f1fb-1f1fa",
	"1f1fc",
	"1f1fc-1f1eb",
	"1f1fc-1f1f8",
	"1f1fd",
	"1f1fd-1f1f0",
	"1f1fe",
	"1f1fe-1f1ea",
	"1f1fe-1f1f9",
	"1f1ff",
	"1f1ff-1f1e6",
	"1f1ff-1f1f2",
	"1f1ff-1f1fc",
	"1f201",
	"1f202",
	"1f21a",
	"1f22f",
	"1f232",
	"1f233",
	"1f234",
	"1f235",
	"1f236",
	"1f237",
	"1f238",
	"1f239",
	"1f23a",
	"1f250",
	"1f251",
	"1f300",
	"1f301",
	"1f302",
	"1f303",
	"1f304",
	"1f305",
	"1f306",
	"1f307",
	"1f308",
	"1f309",
	"1f30a",
	"1f30b",
	"1f30c",
	"1f30d",
	"1f30e",
	"1f30f",
	"1f310",
	"1f311",
	"1f312",
	"1f313",
	"1f314",
	"1f315",
	"1f316",
	"1f317",
	"1f318",
	"1f319",
	"1f31a",
	"1f31b",
	"1f31c",
	"1f31d",
	"1f31e",
	"1f31f",
	"1f320",
	"1f321",
	"1f324",
	"1f325",
	"1f326",
	"1f327",
	"1f328",
	"1f329",
	"1f32a",
	"1f32b",
	"1f32c",
	"1f32d",
	"1f32e",
	"1f32f",
	"1f330",
	"1f331",
	"1f332",
	"1f333",
	"1f334",
	"1f335",
	"1f336",
	"1f337",
	"1f338",
	"1f339",
	"1f33a",
	"1f33b",
	"1f33c",
	"1f33d",
	"1f33e",
	"1f33f",
	"1f340",
	"1f341",
	"1f342",
	"1f343",
	"1f344",
	"1f345",
	"1f346",
	"1f347",
	"1f348",
	"1f349",
	"1f34a",
	"1f34b",
	"1f34c",
	"1f34d",
	"1f34e",
	"1f34f",
	"1f350",
	"1f351",
	"1f352",
	"1f353",
	"1f354",
	"1f355",
	"1f356",
	"1f357",
	"1f358",
	"1f359",
	"1f35a",
	"1f35b",
	"1f35c",
	"1f35d",
	"1f35e",
	"1f35f",
	"1f360",
	"1f361",
	"1f362",
	"1f363",
	"1f364",
	"1f365",
	"1f366",
	"1f367",
	"1f368",
	"1f369",
	"1f36a",
	"1f36b",
	"1f36c",
	"1f36d",
	"1f36e",
	"1f36f",
	"1f370",
	"1f371",
	"1f372",
	"1f373",
	"1f374",
	"1f375",
	"1f376",
	"1f377",
	"1f378",
	"1f379",
	"1f37a",
	"1f37b",
	"1f37c",
	"1f37d",
	"1f37e",
	"1f37f",
	"1f380",
	"1f381",
	"1f382",
	"1f383",
	"1f384",
	"1f385",
	"1f385-1f3fb",
	"1f385-1f3fc",
	"1f385-1f3fd",
	"1f385-1f3fe",
	"1f385-1f3ff",
	"1f386",
	"1f387",
	"1f388",
	"1f389",
	"1f38a",
	"1f38b",
	"1f38c",
	"1f38d",
	"1f38e",
	"1f38f",
	"1f390",
	"1f391",
	"1f392",
	"1f393",
	"1f396",
	"1f397",
	"1f399",
	"1f39a",
	"1f39b",
	"1f39e",
	"1f39f",
	"1f3a0",
	"1f3a1",
	"1f3a2",
	"1f3a3",
	"1f3a4",
	"1f3a5",
	"1f3a6",
	"1f3a7",
	"1f3a8",
	"1f3a9",
	"1f3aa",
	"1f3ab",
	"1f3ac",
	"1f3ad",
	"1f3ae",
	"1f3af",
	"1f3b0",
	"1f3b1",
	"1f3b2",
	"1f3b3",
	"1f3b4",
	"1f3b5",
	"1f3b6",
	"1f3b7",
	"1f3b8",
	"1f3b9",
	"1f3ba",
	"1f3bb",
	"1f3bc",
	"1f3bd",
	"1f3be",
	"1f3bf",
	"1f3c0",
	"1f3c1",
	"1f3c2",
	"1f3c2-1f3fb",
	"1f3c2-1f3fc",
	"1f3c2-1f3fd",
	"1f3c2-1f3fe",
	"1f3c2-1f3ff",
	"1f3c3",
	"1f3c3-1f3fb",
	"1f3c3-1f3fb-200d-2640-fe0f",
	"1f3c3-1f3fb-200d-2642-fe0f",
	"1f3c3-1f3fc",
	"1f3c3-1f3fc-200d-2640-fe0f",
	"1f3c3-1f3fc-200d-2642-fe0f",
	"1f3c3-1f3fd",
	"1f3c3-1f3fd-200d-2640-fe0f",
	"1f3c3-1f3fd-200d-2642-fe0f",
	"1f3c3-1f3fe",
	"1f3c3-1f3fe-200d-2640-fe0f",
	"1f3c3-1f3fe-200d-2642-fe0f",
	"1f3c3-1f3ff",
	"1f3c3-1f3ff-200d-2640-fe0f",
	"1f3c3-1f3ff-200d-2642-fe0f",
	"1f3c3-200d-2640-fe0f",
	"1f3c3-200d-2642-fe0f",
	"1f3c4",
	"1f3c4-1f3fb",
	"1f3c4-1f3fb-200d-2640-fe0f",
	"1f3c4-1f3fb-200d-2642-fe0f",
	"1f3c4-1f3fc",
	"1f3c4-1f3fc-200d-2640-fe0f",
	"1f3c4-1f3fc-200d-2642-fe0f",
	"1f3c4-1f3fd",
	"1f3c4-1f3fd-200d-2640-fe0f",
	"1f3c4-1f3fd-200d-2642-fe0f",
	"1f3c4-1f3fe",
	"1f3c4-1f3fe-200d-2640-fe0f",
	"1f3c4-1f3fe-200d-2642-fe0f",
	"1f3c4-1f3ff",
	"1f3c4-1f3ff-200d-2640-fe0f",
	"1f3c4-1f3ff-200d-2642-fe0f",
	"1f3c4-200d-2640-fe0f",
	"1f3c4-200d-2642-fe0f",
	"1f3c5",
	"1f3c6",
	"1f3c7",
	"1f3c7-1f3fb",
	"1f3c7-1f3fc",
	"1f3c7-1f3fd",
	"1f3c7-1f3fe",
	"1f3c7-1f3ff",
	"1f3c8",
	"1f3c9",
	"1f3ca",
	"1f3ca-1f3fb",
	"1f3ca-1f3fb-200d-2640-fe0f",
	"1f3ca-1f3fb-200d-2642-fe0f",
	"1f3ca-1f3fc",
	"1f3ca-1f3fc-200d-2640-fe0f",
	"1f3ca-1f3fc-200d-2642-fe0f",
	"1f3ca-1f3fd",
	"1f3ca-1f3fd-200d-2640-fe0f",
	"1f3ca-1f3fd-200d-2642-fe0f",
	"1f3ca-1f3fe",
	"1f3ca-1f3fe-200d-2640-fe0f",
	"1f3ca-1f3fe-200d-2642-fe0f",
	"1f3ca-1f3ff",
	"1f3ca-1f3ff-200d-2640-fe0f",
	"1f3ca-1f3ff-200d-2642-fe0f",
	"1f3ca-200d-2640-fe0f",
	"1f3ca-200d-2642-fe0f",
	"1f3cb",
	"1f3cb-1f3fb",
	"1f3cb-1f3fb-200d-2640-fe0f",
	"1f3cb-1f3fb-200d-2642-fe0f",
	"1f3cb-1f3fc",
	"1f3cb-1f3fc-200d-2640-fe0f",
	"1f3cb-1f3fc-200d-2642-fe0f",
	"1f3cb-1f3fd",
	"1f3cb-1f3fd-200d-2640-fe0f",
	"1f3cb-1f3fd-200d-2642-fe0f",
	"1f3cb-1f3fe",
	"1f3cb-1f3fe-200d-2640-fe0f",
	"1f3cb-1f3fe-200d-2642-fe0f",
	"1f3cb-1f3ff",
	"1f3cb-1f3ff-200d-2640-fe0f",
	"1f3cb-1f3ff-200d-2642-fe0f",
	"1f3cb-fe0f-200d-2640-fe0f",
	"1f3cb-fe0f-200d-2642-fe0f",
	"1f3cc",
	"1f3cc-1f3fb",
	"1f3cc-1f3fb-200d-2640-fe0f",
	"1f3cc-1f3fb-200d-2642-fe0f",
	"1f3cc-1f3fc",
	"1f3cc-1f3fc-200d-2640-fe0f",
	"1f3cc-1f3fc-200d-2642-fe0f",
	"1f3cc-1f3fd",
	"1f3cc-1f3fd-200d-2640-fe0f",
	"1f3cc-1f3fd-200d-2642-fe0f",
	"1f3cc-1f3fe",
	"1f3cc-1f3fe-200d-2640-fe0f",
	"1f3cc-1f3fe-200d-2642-fe0f",
	"1f3cc-1f3ff",
	"1f3cc-1f3ff-200d-2640-fe0f",
	"1f3cc-1f3ff-200d-2642-fe0f",
	"1f3cc-fe0f-200d-2640-fe0f",
	"1f3cc-fe0f-200d-2642-fe0f",
	"1f3cd",
	"1f3ce",
	"1f3cf",
	"1f3d0",
	"1f3d1",
	"1f3d2",
	"1f3d3",
	"1f3d4",
	"1f3d5",
	"1f3d6",
	"1f3d7",
	"1f3d8",
	"1f3d9",
	"1f3da",
	"1f3db",
	"1f3dc",
	"1f3dd",
	"1f3de",
	"1f3df",
	"1f3e0",
	"1f3e1",
	"1f3e2",
	"1f3e3",
	"1f3e4",
	"1f3e5",
	"1f3e6",
	"1f3e7",
	"1f3e8",
	"1f3e9",
	"1f3ea",
	"1f3eb",
	"1f3ec",
	"1f3ed",
	"1f3ee",
	"1f3ef",
	"1f3f0",
	"1f3f3",
	"1f3f3-fe0f-200d-1f308",
	"1f3f3-fe0f-200d-26a7-fe0f",
	"1f3f4",
	"1f3f4-200d-2620-fe0f",
	"1f3f4-e0067-e0062-e0065-e006e-e0067-e007f",
	"1f3f4-e0067-e0062-e0073-e0063-e0074-e007f",
	"1f3f4-e0067-e0062-e0077-e006c-e0073-e007f",
	"1f3f5",
	"1f3f7",
	"1f3f8",
	"1f3f9",
	"1f3fa",
	"1f3fb",
	"1f3fc",
	"1f3fd",
	"1f3fe",
	"1f3ff",
	"1f400",
	"1f401",
	"1f402",
	"1f403",
	"1f404",
	"1f405",
	"1f406",
	"1f407",
	"1f408",
	"1f408-200d-2b1b",
	"1f409",
	"1f40a",
	"1f40b",
	"1f40c",
	"1f40d",
	"1f40e",
	"1f40f",
	"1f410",
	"1f411",
	"1f412",
	"1f413",
	"1f414",
	"1f415",
	"1f415-200d-1f9ba",
	"1f416",
	"1f417",
	"1f418",
	"1f419",
	"1f41a",
	"1f41b",
	"1f41c",
	"1f41d",
	"1f41e",
	"1f41f",
	"1f420",
	"1f421",
	"1f422",
	"1f423",
	"1f424",
	"1f425",
	"1f426",
	"1f427",
	"1f428",
	"1f429",
	"1f42a",
	"1f42b",
	"1f42c",
	"1f42d",
	"1f42e",
	"1f42f",
	"1f430",
	"1f431",
	"1f432",
	"1f433",
	"1f434",
	"1f435",
	"1f436",
	"1f437",
	"1f438",
	"1f439",
	"1f43a",
	"1f43b",
	"1f43b-200d-2744-fe0f",
	"1f43c",
	"1f43d",
	"1f43e",
	"1f43f",
	"1f440",
	"1f441",
	"1f441-200d-1f5e8",
	"1f442",
	"1f442-1f3fb",
	"1f442-1f3fc",
	"1f442-1f3fd",
	"1f442-1f3fe",
	"1f442-1f3ff",
	"1f443",
	"1f443-1f3fb",
	"1f443-1f3fc",
	"1f443-1f3fd",
	"1f443-1f3fe",
	"1f443-1f3ff",
	"1f444",
	"1f445",
	"1f446",
	"1f446-1f3fb",
	"1f446-1f3fc",
	"1f446-1f3fd",
	"1f446-1f3fe",
	"1f446-1f3ff",
	"1f447",
	"1f447-1f3fb",
	"1f447-1f3fc",
	"1f447-1f3fd",
	"1f447-1f3fe",
	"1f447-1f3ff",
	"1f448",
	"1f448-1f3fb",
	"1f448-1f3fc",
	"1f448-1f3fd",
	"1f448-1f3fe",
	"1f448-1f3ff",
	"1f449",
	"1f449-1f3fb",
	"1f449-1f3fc",
	"1f449-1f3fd",
	"1f449-1f3fe",
	"1f449-1f3ff",
	"1f44a",
	"1f44a-1f3fb",
	"1f44a-1f3fc",
	"1f44a-1f3fd",
	"1f44a-1f3fe",
	"1f44a-1f3ff",
	"1f44b",
	"1f44b-1f3fb",
	"1f44b-1f3fc",
	"1f44b-1f3fd",
	"1f44b-1f3fe",
	"1f44b-1f3ff",
	"1f44c",
	"1f44c-1f3fb",
	"1f44c-1f3fc",
	"1f44c-1f3fd",
	"1f44c-1f3fe",
	"1f44c-1f3ff",
	"1f44d",
	"1f44d-1f3fb",
	"1f44d-1f3fc",
	"1f44d-1f3fd",
	"1f44d-1f3fe",
	"1f44d-1f3ff",
	"1f44e",
	"1f44e-1f3fb",
	"1f44e-1f3fc",
	"1f44e-1f3fd",
	"1f44e-1f3fe",
	"1f44e-1f3ff",
	"1f44f",
	"1f44f-1f3fb",
	"1f44f-1f3fc",
	"1f44f-1f3fd",
	"1f44f-1f3fe",
	"1f44f-1f3ff",
	"1f450",
	"1f450-1f3fb",
	"1f450-1f3fc",
	"1f450-1f3fd",
	"1f450-1f3fe",
	"1f450-1f3ff",
	"1f451",
	"1f452",
	"1f453",
	"1f454",
	"1f455",
	"1f456",
	"1f457",
	"1f458",
	"1f459",
	"1f45a",
	"1f45b",
	"1f45c",
	"1f45d",
	"1f45e",
	"1f45f",
	"1f460",
	"1f461",
	"1f462",
	"1f463",
	"1f464",
	"1f465",
	"1f466",
	"1f466-1f3fb",
	"1f466-1f3fc",
	"1f466-1f3fd",
	"1f466-1f3fe",
	"1f466-1f3ff",
	"1f467",
	"1f467-1f3fb",
	"1f467-1f3fc",
	"1f467-1f3fd",
	"1f467-1f3fe",
	"1f467-1f3ff",
	"1f468",
	"1f468-1f3fb",
	"1f468-1f3fb-200d-1f3a4",
	"1f468-1f3fb-200d-1f3a8",
	"1f468-1f3fb-200d-1f3eb",
	"1f468-1f3fb-200d-1f3ed",
	"1f468-1f3fb-200d-1f4bb",
	"1f468-1f3fb-200d-1f4bc",
	"1f468-1f3fb-200d-1f9af",
	"1f468-1f3fb-200d-1f9b0",
	"1f468-1f3fb-200d-1f9b1",
	"1f468-1f3fb-200d-1f9b2",
	"1f468-1f3fb-200d-1f9b3",
	"1f468-1f3fb-200d-1f9bc",
	"1f468-1f3fb-200d-1f9bd",
	"1f468-1f3fb-200d-1f33e",
	"1f468-1f3fb-200d-1f37c",
	"1f468-1f3fb-200d-1f52c",
	"1f468-1f3fb-200d-1f91d-200d-1f468-1f3fc",
	"1f468-1f3fb-200d-1f91d-200d-1f468-1f3fd",
	"1f468-1f3fb-200d-1f91d-200d-1f468-1f3fe",
	"1f468-1f3fb-200d-1f91d-200d-1f468-1f3ff",
	"1f468-1f3fb-200d-1f373",
	"1f468-1f3fb-200d-1f384",
	"1f468-1f3fb-200d-1f393",
	"1f468-1f3fb-200d-1f527",
	"1f468-1f3fb-200d-1f680",
	"1f468-1f3fb-200d-1f692",
	"1f468-1f3fb-200d-2695-fe0f",
	"1f468-1f3fb-200d-2696-fe0f",
	"1f468-1f3fb-200d-2708-fe0f",
	"1f468-1f3fc",
	"1f468-1f3fc-200d-1f3a4",
	"1f468-1f3fc-200d-1f3a8",
	"1f468-1f3fc-200d-1f3eb",
	"1f468-1f3fc-200d-1f3ed",
	"1f468-1f3fc-200d-1f4bb",
	"1f468-1f3fc-200d-1f4bc",
	"1f468-1f3fc-200d-1f9af",
	"1f468-1f3fc-200d-1f9b0",
	"1f468-1f3fc-200d-1f9b1",
	"1f468-1f3fc-200d-1f9b2",
	"1f468-1f3fc-200d-1f9b3",
	"1f468-1f3fc-200d-1f9bc",
	"1f468-1f3fc-200d-1f9bd",
	"1f468-1f3fc-200d-1f33e",
	"1f468-1f3fc-200d-1f37c",
	"1f468-1f3fc-200d-1f52c",
	"1f468-1f3fc-200d-1f91d-200d-1f468-1f3fb",
	"1f468-1f3fc-200d-1f91d-200d-1f468-1f3fd",
	"1f468-1f3fc-200d-1f91d-200d-1f468-1f3fe",
	"1f468-1f3fc-200d-1f91d-200d-1f468-1f3ff",
	"1f468-1f3fc-200d-1f373",
	"1f468-1f3fc-200d-1f384",
	"1f468-1f3fc-200d-1f393",
	"1f468-1f3fc-200d-1f527",
	"1f468-1f3fc-200d-1f680",
	"1f468-1f3fc-200d-1f692",
	"1f468-1f3fc-200d-2695-fe0f",
	"1f468-1f3fc-200d-2696-fe0f",
	"1f468-1f3fc-200d-2708-fe0f",
	"1f468-1f3fd",
	"1f468-1f3fd-200d-1f3a4",
	"1f468-1f3fd-200d-1f3a8",
	"1f468-1f3fd-200d-1f3eb",
	"1f468-1f3fd-200d-1f3ed",
	"1f468-1f3fd-200d-1f4bb",
	"1f468-1f3fd-200d-1f4bc",
	"1f468-1f3fd-200d-1f9af",
	"1f468-1f3fd-200d-1f9b0",
	"1f468-1f3fd-200d-1f9b1",
	"1f468-1f3fd-200d-1f9b2",
	"1f468-1f3fd-200d-1f9b3",
	"1f468-1f3fd-200d-1f9bc",
	"1f468-1f3fd-200d-1f9bd",
	"1f468-1f3fd-200d-1f33e",
	"1f468-1f3fd-200d-1f37c",
	"1f468-1f3fd-200d-1f52c",
	"1f468-1f3fd-200d-1f91d-200d-1f468-1f3fb",
	"1f468-1f3fd-200d-1f91d-200d-1f468-1f3fc",
	"1f468-1f3fd-200d-1f91d-200d-1f468-1f3fe",
	"1f468-1f3fd-200d-1f91d-200d-1f468-1f3ff",
	"1f468-1f3fd-200d-1f373",
	"1f468-1f3fd-200d-1f384",
	"1f468-1f3fd-200d-1f393",
	"1f468-1f3fd-200d-1f527",
	"1f468-1f3fd-200d-1f680",
	"1f468-1f3fd-200d-1f692",
	"1f468-1f3fd-200d-2695-fe0f",
	"1f468-1f3fd-200d-2696-fe0f",
	"1f468-1f3fd-200d-2708-fe0f",
	"1f468-1f3fe",
	"1f468-1f3fe-200d-1f3a4",
	"1f468-1f3fe-200d-1f3a8",
	"1f468-1f3fe-200d-1f3eb",
	"1f468-1f3fe-200d-1f3ed",
	"1f468-1f3fe-200d-1f4bb",
	"1f468-1f3fe-200d-1f4bc",
	"1f468-1f3fe-200d-1f9af",
	"1f468-1f3fe-200d-1f9b0",
	"1f468-1f3fe-200d-1f9b1",
	"1f468-1f3fe-200d-1f9b2",
	"1f468-1f3fe-200d-1f9b3",
	"1f468-1f3fe-200d-1f9bc",
	"1f468-1f3fe-200d-1f9bd",
	"1f468-1f3fe-200d-1f33e",
	"1f468-1f3fe-200d-1f37c",
	"1f468-1f3fe-200d-1f52c",
	"1f468-1f3fe-200d-1f91d-200d-1f468-1f3fb",
	"1f468-1f3fe-200d-1f91d-200d-1f468-1f3fc",
	"1f468-1f3fe-200d-1f91d-200d-1f468-1f3fd",
	"1f468-1f3fe-200d-1f91d-200d-1f468-1f3ff",
	"1f468-1f3fe-200d-1f373",
	"1f468-1f3fe-200d-1f384",
	"1f468-1f3fe-200d-1f393",
	"1f468-1f3fe-200d-1f527",
	"1f468-1f3fe-200d-1f680",
	"1f468-1f3fe-200d-1f692",
	"1f468-1f3fe-200d-2695-fe0f",
	"1f468-1f3fe-200d-2696-fe0f",
	"1f468-1f3fe-200d-2708-fe0f",
	"1f468-1f3ff",
	"1f468-1f3ff-200d-1f3a4",
	"1f468-1f3ff-200d-1f3a8",
	"1f468-1f3ff-200d-1f3eb",
	"1f468-1f3ff-200d-1f3ed",
	"1f468-1f3ff-200d-1f4bb",
	"1f468-1f3ff-200d-1f4bc",
	"1f468-1f3ff-200d-1f9af",
	"1f468-1f3ff-200d-1f9b0",
	"1f468-1f3ff-200d-1f9b1",
	"1f468-1f3ff-200d-1f9b2",
	"1f468-1f3ff-200d-1f9b3",
	"1f468-1f3ff-200d-1f9bc",
	"1f468-1f3ff-200d-1f9bd",
	"1f468-1f3ff-200d-1f33e",
	"1f468-1f3ff-200d-1f37c",
	"1f468-1f3ff-200d-1f52c",
	"1f468-1f3ff-200d-1f91d-200d-1f468-1f3fb",
	"1f468-1f3ff-200d-1f91d-200d-1f468-1f3fc",
	"1f468-1f3ff-200d-1f91d-200d-1f468-1f3fd",
	"1f468-1f3ff-200d-1f91d-200d-1f468-1f3fe",
	"1f468-1f3ff-200d-1f373",
	"1f468-1f3ff-200d-1f384",
	"1f468-1f3ff-200d-1f393",
	"1f468-1f3ff-200d-1f527",
	"1f468-1f3ff-200d-1f680",
	"1f468-1f3ff-200d-1f692",
	"1f468-1f3ff-200d-2695-fe0f",
	"1f468-1f3ff-200d-2696-fe0f",
	"1f468-1f3ff-200d-2708-fe0f",
	"1f468-200d-1f3a4",
	"1f468-200d-1f3a8",
	"1f468-200d-1f3eb",
	"1f468-200d-1f3ed",
	"1f468-200d-1f4bb",
	"1f468-200d-1f4bc",
	"1f468-200d-1f9af",
	"1f468-200d-1f9b0",
	"1f468-200d-1f9b1",
	"1f468-200d-1f9b2",
	"1f468-200d-1f9b3",
	"1f468-200d-1f9bc",
	"1f468-200d-1f9bd",
	"1f468-200d-1f33e",
	"1f468-200d-1f37c",
	"1f468-200d-1f52c",
	"1f468-200d-1f373",
	"1f468-200d-1f384",
	"1f468-200d-1f393",
	"1f468-200d-1f466",
	"1f468-200d-1f466-200d-1f466",
	"1f468-200d-1f467",
	"1f468-200d-1f467-200d-1f466",
	"1f468-200d-1f467-200d-1f467",
	"1f468-200d-1f468-200d-1f466",
	"1f468-200d-1f468-200d-1f466-200d-1f466",
	"1f468-200d-1f468-200d-1f467",
	"1f468-200d-1f468-200d-1f467-200d-1f466",
	"1f468-200d-1f468-200d-1f467-200d-1f467",
	"1f468-200d-1f469-200d-1f466",
	"1f468-200d-1f469-200d-1f466-200d-1f466",
	"1f468-200d-1f469-200d-1f467",
	"1f468-200d-1f469-200d-1f467-200d-1f466",
	"1f468-200d-1f469-200d-1f467-200d-1f467",
	"1f468-200d-1f527",
	"1f468-200d-1f680",
	"1f468-200d-1f692",
	"1f468-200d-2695-fe0f",
	"1f468-200d-2696-fe0f",
	"1f468-200d-2708-fe0f",
	"1f468-200d-2764-fe0f-200d-1f48b-200d-1f468",
	"1f468-200d-2764-fe0f-200d-1f468",
	"1f469",
	"1f469-1f3fb",
	"1f469-1f3fb-200d-1f3a4",
	"1f469-1f3fb-200d-1f3a8",
	"1f469-1f3fb-200d-1f3eb",
	"1f469-1f3fb-200d-1f3ed",
	"1f469-1f3fb-200d-1f4bb",
	"1f469-1f3fb-200d-1f4bc",
	"1f469-1f3fb-200d-1f9af",
	"1f469-1f3fb-200d-1f9b0",
	"1f469-1f3fb-200d-1f9b1",
	"1f469-1f3fb-200d-1f9b2",
	"1f469-1f3fb-200d-1f9b3",
	"1f469-1f3fb-200d-1f9bc",
	"1f469-1f3fb-200d-1f9bd",
	"1f469-1f3fb-200d-1f33e",
	"1f469-1f3fb-200d-1f37c",
	"1f469-1f3fb-200d-1f52c",
	"1f469-1f3fb-200d-1f91d-200d-1f468-1f3fc",
	"1f469-1f3fb-200d-1f91d-200d-1f468-1f3fd",
	"1f469-1f3fb-200d-1f91d-200d-1f468-1f3fe",
	"1f469-1f3fb-200d-1f91d-200d-1f468-1f3ff",
	"1f469-1f3fb-200d-1f91d-200d-1f469-1f3fc",
	"1f469-1f3fb-200d-1f91d-200d-1f469-1f3fd",
	"1f469-1f3fb-200d-1f91d-200d-1f469-1f3fe",
	"1f469-1f3fb-200d-1f91d-200d-1f469-1f3ff",
	"1f469-1f3fb-200d-1f373",
	"1f469-1f3fb-200d-1f384",
	"1f469-1f3fb-200d-1f393",
	"1f469-1f3fb-200d-1f527",
	"1f469-1f3fb-200d-1f680",
	"1f469-1f3fb-200d-1f692",
	"1f469-1f3fb-200d-2695-fe0f",
	"1f469-1f3fb-200d-2696-fe0f",
	"1f469-1f3fb-200d-2708-fe0f",
	"1f469-1f3fc",
	"1f469-1f3fc-200d-1f3a4",
	"1f469-1f3fc-200d-1f3a8",
	"1f469-1f3fc-200d-1f3eb",
	"1f469-1f3fc-200d-1f3ed",
	"1f469-1f3fc-200d-1f4bb",
	"1f469-1f3fc-200d-1f4bc",
	"1f469-1f3fc-200d-1f9af",
	"1f469-1f3fc-200d-1f9b0",
	"1f469-1f3fc-200d-1f9b1",
	"1f469-1f3fc-200d-1f9b2",
	"1f469-1f3fc-200d-1f9b3",
	"1f469-1f3fc-200d-1f9bc",
	"1f469-1f3fc-200d-1f9bd",
	"1f469-1f3fc-200d-1f33e",
	"1f469-1f3fc-200d-1f37c",
	"1f469-1f3fc-200d-1f52c",
	"1f469-1f3fc-200d-1f91d-200d-1f468-1f3fb",
	"1f469-1f3fc-200d-1f91d-200d-1f468-1f3fd",
	"1f469-1f3fc-200d-1f91d-200d-1f468-1f3fe",
	"1f469-1f3fc-200d-1f91d-200d-1f468-1f3ff",
	"1f469-1f3fc-200d-1f91d-200d-1f469-1f3fb",
	"1f469-1f3fc-200d-1f91d-200d-1f469-1f3fd",
	"1f469-1f3fc-200d-1f91d-200d-1f469-1f3fe",
	"1f469-1f3fc-200d-1f91d-200d-1f469-1f3ff",
	"1f469-1f3fc-200d-1f373",
	"1f469-1f3fc-200d-1f384",
	"1f469-1f3fc-200d-1f393",
	"1f469-1f3fc-200d-1f527",
	"1f469-1f3fc-200d-1f680",
	"1f469-1f3fc-200d-1f692",
	"1f469-1f3fc-200d-2695-fe0f",
	"1f469-1f3fc-200d-2696-fe0f",
	"1f469-1f3fc-200d-2708-fe0f",
	"1f469-1f3fd",
	"1f469-1f3fd-200d-1f3a4",
	"1f469-1f3fd-200d-1f3a8",
	"1f469-1f3fd-200d-1f3eb",
	"1f469-1f3fd-200d-1f3ed",
	"1f469-1f3fd-200d-1f4bb",
	"1f469-1f3fd-200d-1f4bc",
	"1f469-1f3fd-200d-1f9af",
	"1f469-1f3fd-200d-1f9b0",
	"1f469-1f3fd-200d-1f9b1",
	"1f469-1f3fd-200d-1f9b2",
	"1f469-1f3fd-200d-1f9b3",
	"1f469-1f3fd-200d-1f9bc",
	"1f469-1f3fd-200d-1f9bd",
	"1f469-1f3fd-200d-1f33e",
	"1f469-1f3fd-200d-1f37c",
	"1f469-1f3fd-200d-1f52c",
	"1f469-1f3fd-200d-1f91d-200d-1f468-1f3fb",
	"1f469-1f3fd-200d-1f91d-200d-1f468-1f3fc",
	"1f469-1f3fd-200d-1f91d-200d-1f468-1f3fe",
	"1f469-1f3fd-200d-1f91d-200d-1f468-1f3ff",
	"1f469-1f3fd-200d-1f91d-200d-1f469-1f3fb",
	"1f469-1f3fd-200d-1f91d-200d-1f469-1f3fc",
	"1f469-1f3fd-200d-1f91d-200d-1f469-1f3fe",
	"1f469-1f3fd-200d-1f91d-200d-1f469-1f3ff",
	"1f469-1f3fd-200d-1f373",
	"1f469-1f3fd-200d-1f384",
	"1f469-1f3fd-200d-1f393",
	"1f469-1f3fd-200d-1f527",
	"1f469-1f3fd-200d-1f680",
	"1f469-1f3fd-200d-1f692",
	"1f469-1f3fd-200d-2695-fe0f",
	"1f469-1f3fd-200d-2696-fe0f",
	"1f469-1f3fd-200d-2708-fe0f",
	"1f469-1f3fe",
	"1f469-1f3fe-200d-1f3a4",
	"1f469-1f3fe-200d-1f3a8",
	"1f469-1f3fe-200d-1f3eb",
	"1f469-1f3fe-200d-1f3ed",
	"1f469-1f3fe-200d-1f4bb",
	"1f469-1f3fe-200d-1f4bc",
	"1f469-1f3fe-200d-1f9af",
	"1f469-1f3fe-200d-1f9b0",
	"1f469-1f3fe-200d-1f9b1",
	"1f469-1f3fe-200d-1f9b2",
	"1f469-1f3fe-200d-1f9b3",
	"1f469-1f3fe-200d-1f9bc",
	"1f469-1f3fe-200d-1f9bd",
	"1f469-1f3fe-200d-1f33e",
	"1f469-1f3fe-200d-1f37c",
	"1f469-1f3fe-200d-1f52c",
	"1f469-1f3fe-200d-1f91d-200d-1f468-1f3fb",
	"1f469-1f3fe-200d-1f91d-200d-1f468-1f3fc",
	"1f469-1f3fe-200d-1f91d-200d-1f468-1f3fd",
	"1f469-1f3fe-200d-1f91d-200d-1f468-1f3ff",
	"1f469-1f3fe-200d-1f91d-200d-1f469-1f3fb",
	"1f469-1f3fe-200d-1f91d-200d-1f469-1f3fc",
	"1f469-1f3fe-200d-1f91d-200d-1f469-1f3fd",
	"1f469-1f3fe-200d-1f91d-200d-1f469-1f3ff",
	"1f469-1f3fe-200d-1f373",
	"1f469-1f3fe-200d-1f384",
	"1f469-1f3fe-200d-1f393",
	"1f469-1f3fe-200d-1f527",
	"1f469-1f3fe-200d-1f680",
	"1f469-1f3fe-200d-1f692",
	"1f469-1f3fe-200d-2695-fe0f",
	"1f469-1f3fe-200d-2696-fe0f",
	"1f469-1f3fe-200d-2708-fe0f",
	"1f469-1f3ff",
	"1f469-1f3ff-200d-1f3a4",
	"1f469-1f3ff-200d-1f3a8",
	"1f469-1f3ff-200d-1f3eb",
	"1f469-1f3ff-200d-1f3ed",
	"1f469-1f3ff-200d-1f4bb",
	"1f469-1f3ff-200d-1f4bc",
	"1f469-1f3ff-200d-1f9af",
	"1f469-1f3ff-200d-1f9b0",
	"1f469-1f3ff-200d-1f9b1",
	"1f469-1f3ff-200d-1f9b2",
	"1f469-1f3ff-200d-1f9b3",
	"1f469-1f3ff-200d-1f9bc",
	"1f469-1f3ff-200d-1f9bd",
	"1f469-1f3ff-200d-1f33e",
	"1f469-1f3ff-200d-1f37c",
	"1f469-1f3ff-200d-1f52c",
	"1f469-1f3ff-200d-1f91d-200d-1f468-1f3fb",
	"1f469-1f3ff-200d-1f91d-200d-1f468-1f3fc",
	"1f469-1f3ff-200d-1f91d-200d-1f468-1f3fd",
	"1f469-1f3ff-200d-1f91d-200d-1f468-1f3fe",
	"1f469-1f3ff-200d-1f91d-200d-1f469-1f3fb",
	"1f469-1f3ff-200d-1f91d-200d-1f469-1f3fc",
	"1f469-1f3ff-200d-1f91d-200d-1f469-1f3fd",
	"1f469-1f3ff-200d-1f91d-200d-1f469-1f3fe",
	"1f469-1f3ff-200d-1f373",
	"1f469-1f3ff-200d-1f384",
	"1f469-1f3ff-200d-1f393",
	"1f469-1f3ff-200d-1f527",
	"1f469-1f3ff-200d-1f680",
	"1f469-1f3ff-200d-1f692",
	"1f469-1f3ff-200d-2695-fe0f",
	"1f469-1f3ff-200d-2696-fe0f",
	"1f469-1f3ff-200d-2708-fe0f",
	"1f469-200d-1f3a4",
	"1f469-200d-1f3a8",
	"1f469-200d-1f3eb",
	"1f469-200d-1f3ed",
	"1f469-200d-1f4bb",
	"1f469-200d-1f4bc",
	"1f469-200d-1f9af",
	"1f469-200d-1f9b0",
	"1f469-200d-1f9b1",
	"1f469-200d-1f9b2",
	"1f469-200d-1f9b3",
	"1f469-200d-1f9bc",
	"1f469-200d-1f9bd",
	"1f469-200d-1f33e",
	"1f469-200d-1f37c",
	"1f469-200d-1f52c",
	"1f469-200d-1f373",
	"1f469-200d-1f384",
	"1f469-200d-1f393",
	"1f469-200d-1f466",
	"1f469-200d-1f466-200d-1f466",
	"1f469-200d-1f467",
	"1f469-200d-1f467-200d-1f466",
	"1f469-200d-1f467-200d-1f467",
	"1f469-200d-1f469-200d-1f466",
	"1f469-200d-1f469-200d-1f466-200d-1f466",
	"1f469-200d-1f469-200d-1f467",
	"1f469-200d-1f469-200d-1f467-200d-1f466",
	"1f469-200d-1f469-200d-1f467-200d-1f467",
	"1f469-200d-1f527",
	"1f469-200d-1f680",
	"1f469-200d-1f692",
	"1f469-200d-2695-fe0f",
	"1f469-200d-2696-fe0f",
	"1f469-200d-2708-fe0f",
	"1f469-200d-2764-fe0f-200d-1f48b-200d-1f468",
	"1f469-200d-2764-fe0f-200d-1f48b-200d-1f469",
	"1f469-200d-2764-fe0f-200d-1f468",
	"1f469-200d-2764-fe0f-200d-1f469",
	"1f46a",
	"1f46b",
	"1f46b-1f3fb",
	"1f46b-1f3fc",
	"1f46b-1f3fd",
	"1f46b-1f3fe",
	"1f46b-1f3ff",
	"1f46c",
	"1f46c-1f3fb",
	"1f46c-1f3fc",
	"1f46c-1f3fd",
	"1f46c-1f3fe",
	"1f46c-1f3ff",
	"1f46d",
	"1f46d-1f3fb",
	"1f46d-1f3fc",
	"1f46d-1f3fd",
	"1f46d-1f3fe",
	"1f46d-1f3ff",
	"1f46e",
	"1f46e-1f3fb",
	"1f46e-1f3fb-200d-2640-fe0f",
	"1f46e-1f3fb-200d-2642-fe0f",
	"1f46e-1f3fc",
	"1f46e-1f3fc-200d-2640-fe0f",
	"1f46e-1f3fc-200d-2642-fe0f",
	"1f46e-1f3fd",
	"1f46e-1f3fd-200d-2640-fe0f",
	"1f46e-1f3fd-200d-2642-fe0f",
	"1f46e-1f3fe",
	"1f46e-1f3fe-200d-2640-fe0f",
	"1f46e-1f3fe-200d-2642-fe0f",
	"1f46e-1f3ff",
	"1f46e-1f3ff-200d-2640-fe0f",
	"1f46e-1f3ff-200d-2642-fe0f",
	"1f46e-200d-2640-fe0f",
	"1f46e-200d-2642-fe0f",
	"1f46f",
	"1f46f-200d-2640-fe0f",
	"1f46f-200d-2642-fe0f",
	"1f470",
	"1f470-1f3fb",
	"1f470-1f3fb-200d-2640-fe0f",
	"1f470-1f3fb-200d-2642-fe0f",
	"1f470-1f3fc",
	"1f470-1f3fc-200d-2640-fe0f",
	"1f470-1f3fc-200d-2642-fe0f",
	"1f470-1f3fd",
	"1f470-1f3fd-200d-2640-fe0f",
	"1f470-1f3fd-200d-2642-fe0f",
	"1f470-1f3fe",
	"1f470-1f3fe-200d-2640-fe0f",
	"1f470-1f3fe-200d-2642-fe0f",
	"1f470-1f3ff",
	"1f470-1f3ff-200d-2640-fe0f",
	"1f470-1f3ff-200d-2642-fe0f",
	"1f470-200d-2640-fe0f",
	"1f470-200d-2642-fe0f",
	"1f471",
	"1f471-1f3fb",
	"1f471-1f3fb-200d-2640-fe0f",
	"1f471-1f3fb-200d-2642-fe0f",
	"1f471-1f3fc",
	"1f471-1f3fc-200d-2640-fe0f",
	"1f471-1f3fc-200d-2642-fe0f",
	"1f471-1f3fd",
	"1f471-1f3fd-200d-2640-fe0f",
	"1f471-1f3fd-200d-2642-fe0f",
	"1f471-1f3fe",
	"1f471-1f3fe-200d-2640-fe0f",
	"1f471-1f3fe-200d-2642-fe0f",
	"1f471-1f3ff",
	"1f471-1f3ff-200d-2640-fe0f",
	"1f471-1f3ff-200d-2642-fe0f",
	"1f471-200d-2640-fe0f",
	"1f471-200d-2642-fe0f",
	"1f472",
	"1f472-1f3fb",
	"1f472-1f3fc",
	"1f472-1f3fd",
	"1f472-1f3fe",
	"1f472-1f3ff",
	"1f473",
	"1f473-1f3fb",
	"1f473-1f3fb-200d-2640-fe0f",
	"1f473-1f3fb-200d-2642-fe0f",
	"1f473-1f3fc",
	"1f473-1f3fc-200d-2640-fe0f",
	"1f473-1f3fc-200d-2642-fe0f",
	"1f473-1f3fd",
	"1f473-1f3fd-200d-2640-fe0f",
	"1f473-1f3fd-200d-2642-fe0f",
	"1f473-1f3fe",
	"1f473-1f3fe-200d-2640-fe0f",
	"1f473-1f3fe-200d-2642-fe0f",
	"1f473-1f3ff",
	"1f473-1f3ff-200d-2640-fe0f",
	"1f473-1f3ff-200d-2642-fe0f",
	"1f473-200d-2640-fe0f",
	"1f473-200d-2642-fe0f",
	"1f474",
	"1f474-1f3fb",
	"1f474-1f3fc",
	"1f474-1f3fd",
	"1f474-1f3fe",
	"1f474-1f3ff",
	"1f475",
	"1f475-1f3fb",
	"1f475-1f3fc",
	"1f475-1f3fd",
	"1f475-1f3fe",
	"1f475-1f3ff",
	"1f476",
	"1f476-1f3fb",
	"1f476-1f3fc",
	"1f476-1f3fd",
	"1f476-1f3fe",
	"1f476-1f3ff",
	"1f477",
	"1f477-1f3fb",
	"1f477-1f3fb-200d-2640-fe0f",
	"1f477-1f3fb-200d-2642-fe0f",
	"1f477-1f3fc",
	"1f477-1f3fc-200d-2640-fe0f",
	"1f477-1f3fc-200d-2642-fe0f",
	"1f477-1f3fd",
	"1f477-1f3fd-200d-2640-fe0f",
	"1f477-1f3fd-200d-2642-fe0f",
	"1f477-1f3fe",
	"1f477-1f3fe-200d-2640-fe0f",
	"1f477-1f3fe-200d-2642-fe0f",
	"1f477-1f3ff",
	"1f477-1f3ff-200d-2640-fe0f",
	"1f477-1f3ff-200d-2642-fe0f",
	"1f477-200d-2640-fe0f",
	"1f477-200d-2642-fe0f",
	"1f478",
	"1f478-1f3fb",
	"1f478-1f3fc",
	"1f478-1f3fd",
	"1f478-1f3fe",
	"1f478-1f3ff",
	"1f479",
	"1f47a",
	"1f47b",
	"1f47c",
	"1f47c-1f3fb",
	"1f47c-1f3fc",
	"1f47c-1f3fd",
	"1f47c-1f3fe",
	"1f47c-1f3ff",
	"1f47d",
	"1f47e",
	"1f47f",
	"1f480",
	"1f481",
	"1f481-1f3fb",
	"1f481-1f3fb-200d-2640-fe0f",
	"1f481-1f3fb-200d-2642-fe0f",
	"1f481-1f3fc",
	"1f481-1f3fc-200d-2640-fe0f",
	"1f481-1f3fc-200d-2642-fe0f",
	"1f481-1f3fd",
	"1f481-1f3fd-200d-2640-fe0f",
	"1f481-1f3fd-200d-2642-fe0f",
	"1f481-1f3fe",
	"1f481-1f3fe-200d-2640-fe0f",
	"1f481-1f3fe-200d-2642-fe0f",
	"1f481-1f3ff",
	"1f481-1f3ff-200d-2640-fe0f",
	"1f481-1f3ff-200d-2642-fe0f",
	"1f481-200d-2640-fe0f",
	"1f481-200d-2642-fe0f",
	"1f482",
	"1f482-1f3fb",
	"1f482-1f3fb-200d-2640-fe0f",
	"1f482-1f3fb-200d-2642-fe0f",
	"1f482-1f3fc",
	"1f482-1f3fc-200d-2640-fe0f",
	"1f482-1f3fc-200d-2642-fe0f",
	"1f482-1f3fd",
	"1f482-1f3fd-200d-2640-fe0f",
	"1f482-1f3fd-200d-2642-fe0f",
	"1f482-1f3fe",
	"1f482-1f3fe-200d-2640-fe0f",
	"1f482-1f3fe-200d-2642-fe0f",
	"1f482-1f3ff",
	"1f482-1f3ff-200d-2640-fe0f",
	"1f482-1f3ff-200d-2642-fe0f",
	"1f482-200d-2640-fe0f",
	"1f482-200d-2642-fe0f",
	"1f483",
	"1f483-1f3fb",
	"1f483-1f3fc",
	"1f483-1f3fd",
	"1f483-1f3fe",
	"1f483-1f3ff",
	"1f484",
	"1f485",
	"1f485-1f3fb",
	"1f485-1f3fc",
	"1f485-1f3fd",
	"1f485-1f3fe",
	"1f485-1f3ff",
	"1f486",
	"1f486-1f3fb",
	"1f486-1f3fb-200d-2640-fe0f",
	"1f486-1f3fb-200d-2642-fe0f",
	"1f486-1f3fc",
	"1f486-1f3fc-200d-2640-fe0f",
	"1f486-1f3fc-200d-2642-fe0f",
	"1f486-1f3fd",
	"1f486-1f3fd-200d-2640-fe0f",
	"1f486-1f3fd-200d-2642-fe0f",
	"1f486-1f3fe",
	"1f486-1f3fe-200d-2640-fe0f",
	"1f486-1f3fe-200d-2642-fe0f",
	"1f486-1f3ff",
	"1f486-1f3ff-200d-2640-fe0f",
	"1f486-1f3ff-200d-2642-fe0f",
	"1f486-200d-2640-fe0f",
	"1f486-200d-2642-fe0f",
	"1f487",
	"1f487-1f3fb",
	"1f487-1f3fb-200d-2640-fe0f",
	"1f487-1f3fb-200d-2642-fe0f",
	"1f487-1f3fc",
	"1f487-1f3fc-200d-2640-fe0f",
	"1f487-1f3fc-200d-2642-fe0f",
	"1f487-1f3fd",
	"1f487-1f3fd-200d-2640-fe0f",
	"1f487-1f3fd-200d-2642-fe0f",
	"1f487-1f3fe",
	"1f487-1f3fe-200d-2640-fe0f",
	"1f487-1f3fe-200d-2642-fe0f",
	"1f487-1f3ff",
	"1f487-1f3ff-200d-2640-fe0f",
	"1f487-1f3ff-200d-2642-fe0f",
	"1f487-200d-2640-fe0f",
	"1f487-200d-2642-fe0f",
	"1f488",
	"1f489",
	"1f48a",
	"1f48b",
	"1f48c",
	"1f48d",
	"1f48e",
	"1f48f",
	"1f490",
	"1f491",
	"1f492",
	"1f493",
	"1f494",
	"1f495",
	"1f496",
	"1f497",
	"1f498",
	"1f499",
	"1f49a",
	"1f49b",
	"1f49c",
	"1f49d",
	"1f49e",
	"1f49f",
	"1f4a0",
	"1f4a1",
	"1f4a2",
	"1f4a3",
	"1f4a4",
	"1f4a5",
	"1f4a6",
	"1f4a7",
	"1f4a8",
	"1f4a9",
	"1f4aa",
	"1f4aa-1f3fb",
	"1f4aa-1f3fc",
	"1f4aa-1f3fd",
	"1f4aa-1f3fe",
	"1f4aa-1f3ff",
	"1f4ab",
	"1f4ac",
	"1f4ad",
	"1f4ae",
	"1f4af",
	"1f4b0",
	"1f4b1",
	"1f4b2",
	"1f4b3",
	"1f4b4",
	"1f4b5",
	"1f4b6",
	"1f4b7",
	"1f4b8",
	"1f4b9",
	"1f4ba",
	"1f4bb",
	"1f4bc",
	"1f4bd",
	"1f4be",
	"1f4bf",
	"1f4c0",
	"1f4c1",
	"1f4c2",
	"1f4c3",
	"1f4c4",
	"1f4c5",
	"1f4c6",
	"1f4c7",
	"1f4c8",
	"1f4c9",
	"1f4ca",
	"1f4cb",
	"1f4cc",
	"1f4cd",
	"1f4ce",
	"1f4cf",
	"1f4d0",
	"1f4d1",
	"1f4d2",
	"1f4d3",
	"1f4d4",
	"1f4d5",
	"1f4d6",
	"1f4d7",
	"1f4d8",
	"1f4d9",
	"1f4da",
	"1f4db",
	"1f4dc",
	"1f4dd",
	"1f4de",
	"1f4df",
	"1f4e0",
	"1f4e1",
	"1f4e2",
	"1f4e3",
	"1f4e4",
	"1f4e5",
	"1f4e6",
	"1f4e7",
	"1f4e8",
	"1f4e9",
	"1f4ea",
	"1f4eb",
	"1f4ec",
	"1f4ed",
	"1f4ee",
	"1f4ef",
	"1f4f0",
	"1f4f1",
	"1f4f2",
	"1f4f3",
	"1f4f4",
	"1f4f5",
	"1f4f6",
	"1f4f7",
	"1f4f8",
	"1f4f9",
	"1f4fa",
	"1f4fb",
	"1f4fc",
	"1f4fd",
	"1f4ff",
	"1f500",
	"1f501",
	"1f502",
	"1f503",
	"1f504",
	"1f505",
	"1f506",
	"1f507",
	"1f508",
	"1f509",
	"1f50a",
	"1f50b",
	"1f50c",
	"1f50d",
	"1f50e",
	"1f50f",
	"1f510",
	"1f511",
	"1f512",
	"1f513",
	"1f514",
	"1f515",
	"1f516",
	"1f517",
	"1f518",
	"1f519",
	"1f51a",
	"1f51b",
	"1f51c",
	"1f51d",
	"1f51e",
	"1f51f",
	"1f520",
	"1f521",
	"1f522",
	"1f523",
	"1f524",
	"1f525",
	"1f526",
	"1f527",
	"1f528",
	"1f529",
	"1f52a",
	"1f52b",
	"1f52c",
	"1f52d",
	"1f52e",
	"1f52f",
	"1f530",
	"1f531",
	"1f532",
	"1f533",
	"1f534",
	"1f535",
	"1f536",
	"1f537",
	"1f538",
	"1f539",
	"1f53a",
	"1f53b",
	"1f53c",
	"1f53d",
	"1f549",
	"1f54a",
	"1f54b",
	"1f54c",
	"1f54d",
	"1f54e",
	"1f550",
	"1f551",
	"1f552",
	"1f553",
	"1f554",
	"1f555",
	"1f556",
	"1f557",
	"1f558",
	"1f559",
	"1f55a",
	"1f55b",
	"1f55c",
	"1f55d",
	"1f55e",
	"1f55f",
	"1f560",
	"1f561",
	"1f562",
	"1f563",
	"1f564",
	"1f565",
	"1f566",
	"1f567",
	"1f56f",
	"1f570",
	"1f573",
	"1f574",
	"1f574-1f3fb",
	"1f574-1f3fb-200d-2640-fe0f",
	"1f574-1f3fb-200d-2642-fe0f",
	"1f574-1f3fc",
	"1f574-1f3fc-200d-2640-fe0f",
	"1f574-1f3fc-200d-2642-fe0f",
	"1f574-1f3fd",
	"1f574-1f3fd-200d-2640-fe0f",
	"1f574-1f3fd-200d-2642-fe0f",
	"1f574-1f3fe",
	"1f574-1f3fe-200d-2640-fe0f",
	"1f574-1f3fe-200d-2642-fe0f",
	"1f574-1f3ff",
	"1f574-1f3ff-200d-2640-fe0f",
	"1f574-1f3ff-200d-2642-fe0f",
	"1f574-fe0f-200d-2640-fe0f",
	"1f574-fe0f-200d-2642-fe0f",
	"1f575",
	"1f575-1f3fb",
	"1f575-1f3fb-200d-2640-fe0f",
	"1f575-1f3fb-200d-2642-fe0f",
	"1f575-1f3fc",
	"1f575-1f3fc-200d-2640-fe0f",
	"1f575-1f3fc-200d-2642-fe0f",
	"1f575-1f3fd",
	"1f575-1f3fd-200d-2640-fe0f",
	"1f575-1f3fd-200d-2642-fe0f",
	"1f575-1f3fe",
	"1f575-1f3fe-200d-2640-fe0f",
	"1f575-1f3fe-200d-2642-fe0f",
	"1f575-1f3ff",
	"1f575-1f3ff-200d-2640-fe0f",
	"1f575-1f3ff-200d-2642-fe0f",
	"1f575-fe0f-200d-2640-fe0f",
	"1f575-fe0f-200d-2642-fe0f",
	"1f576",
	"1f577",
	"1f578",
	"1f579",
	"1f57a",
	"1f57a-1f3fb",
	"1f57a-1f3fc",
	"1f57a-1f3fd",
	"1f57a-1f3fe",
	"1f57a-1f3ff",
	"1f587",
	"1f58a",
	"1f58b",
	"1f58c",
	"1f58d",
	"1f590",
	"1f590-1f3fb",
	"1f590-1f3fc",
	"1f590-1f3fd",
	"1f590-1f3fe",
	"1f590-1f3ff",
	"1f595",
	"1f595-1f3fb",
	"1f595-1f3fc",
	"1f595-1f3fd",
	"1f595-1f3fe",
	"1f595-1f3ff",
	"1f596",
	"1f596-1f3fb",
	"1f596-1f3fc",
	"1f596-1f3fd",
	"1f596-1f3fe",
	"1f596-1f3ff",
	"1f5a4",
	"1f5a5",
	"1f5a8",
	"1f5b1",
	"1f5b2",
	"1f5bc",
	"1f5c2",
	"1f5c3",
	"1f5c4",
	"1f5d1",
	"1f5d2",
	"1f5d3",
	"1f5dc",
	"1f5dd",
	"1f5de",
	"1f5e1",
	"1f5e3",
	"1f5e8",
	"1f5ef",
	"1f5f3",
	"1f5fa",
	"1f5fb",
	"1f5fc",
	"1f5fd",
	"1f5fe",
	"1f5ff",
	"1f600",
	"1f601",
	"1f602",
	"1f603",
	"1f604",
	"1f605",
	"1f606",
	"1f607",
	"1f608",
	"1f609",
	"1f60a",
	"1f60b",
	"1f60c",
	"1f60d",
	"1f60e",
	"1f60f",
	"1f610",
	"1f611",
	"1f612",
	"1f613",
	"1f614",
	"1f615",
	"1f616",
	"1f617",
	"1f618",
	"1f619",
	"1f61a",
	"1f61b",
	"1f61c",
	"1f61d",
	"1f61e",
	"1f61f",
	"1f620",
	"1f621",
	"1f622",
	"1f623",
	"1f624",
	"1f625",
	"1f626",
	"1f627",
	"1f628",
	"1f629",
	"1f62a",
	"1f62b",
	"1f62c",
	"1f62d",
	"1f62e",
	"1f62f",
	"1f630",
	"1f631",
	"1f632",
	"1f633",
	"1f634",
	"1f635",
	"1f636",
	"1f637",
	"1f638",
	"1f639",
	"1f63a",
	"1f63b",
	"1f63c",
	"1f63d",
	"1f63e",
	"1f63f",
	"1f640",
	"1f641",
	"1f642",
	"1f643",
	"1f644",
	"1f645",
	"1f645-1f3fb",
	"1f645-1f3fb-200d-2640-fe0f",
	"1f645-1f3fb-200d-2642-fe0f",
	"1f645-1f3fc",
	"1f645-1f3fc-200d-2640-fe0f",
	"1f645-1f3fc-200d-2642-fe0f",
	"1f645-1f3fd",
	"1f645-1f3fd-200d-2640-fe0f",
	"1f645-1f3fd-200d-2642-fe0f",
	"1f645-1f3fe",
	"1f645-1f3fe-200d-2640-fe0f",
	"1f645-1f3fe-200d-2642-fe0f",
	"1f645-1f3ff",
	"1f645-1f3ff-200d-2640-fe0f",
	"1f645-1f3ff-200d-2642-fe0f",
	"1f645-200d-2640-fe0f",
	"1f645-200d-2642-fe0f",
	"1f646",
	"1f646-1f3fb",
	"1f646-1f3fb-200d-2640-fe0f",
	"1f646-1f3fb-200d-2642-fe0f",
	"1f646-1f3fc",
	"1f646-1f3fc-200d-2640-fe0f",
	"1f646-1f3fc-200d-2642-fe0f",
	"1f646-1f3fd",
	"1f646-1f3fd-200d-2640-fe0f",
	"1f646-1f3fd-200d-2642-fe0f",
	"1f646-1f3fe",
	"1f646-1f3fe-200d-2640-fe0f",
	"1f646-1f3fe-200d-2642-fe0f",
	"1f646-1f3ff",
	"1f646-1f3ff-200d-2640-fe0f",
	"1f646-1f3ff-200d-2642-fe0f",
	"1f646-200d-2640-fe0f",
	"1f646-200d-2642-fe0f",
	"1f647",
	"1f647-1f3fb",
	"1f647-1f3fb-200d-2640-fe0f",
	"1f647-1f3fb-200d-2642-fe0f",
	"1f647-1f3fc",
	"1f647-1f3fc-200d-2640-fe0f",
	"1f647-1f3fc-200d-2642-fe0f",
	"1f647-1f3fd",
	"1f647-1f3fd-200d-2640-fe0f",
	"1f647-1f3fd-200d-2642-fe0f",
	"1f647-1f3fe",
	"1f647-1f3fe-200d-2640-fe0f",
	"1f647-1f3fe-200d-2642-fe0f",
	"1f647-1f3ff",
	"1f647-1f3ff-200d-2640-fe0f",
	"1f647-1f3ff-200d-2642-fe0f",
	"1f647-200d-2640-fe0f",
	"1f647-200d-2642-fe0f",
	"1f648",
	"1f649",
	"1f64a",
	"1f64b",
	"1f64b-1f3fb",
	"1f64b-1f3fb-200d-2640-fe0f",
	"1f64b-1f3fb-200d-2642-fe0f",
	"1f64b-1f3fc",
	"1f64b-1f3fc-200d-2640-fe0f",
	"1f64b-1f3fc-200d-2642-fe0f",
	"1f64b-1f3fd",
	"1f64b-1f3fd-200d-2640-fe0f",
	"1f64b-1f3fd-200d-2642-fe0f",
	"1f64b-1f3fe",
	"1f64b-1f3fe-200d-2640-fe0f",
	"1f64b-1f3fe-200d-2642-fe0f",
	"1f64b-1f3ff",
	"1f64b-1f3ff-200d-2640-fe0f",
	"1f64b-1f3ff-200d-2642-fe0f",
	"1f64b-200d-2640-fe0f",
	"1f64b-200d-2642-fe0f",
	"1f64c",
	"1f64c-1f3fb",
	"1f64c-1f3fc",
	"1f64c-1f3fd",
	"1f64c-1f3fe",
	"1f64c-1f3ff",
	"1f64d",
	"1f64d-1f3fb",
	"1f64d-1f3fb-200d-2640-fe0f",
	"1f64d-1f3fb-200d-2642-fe0f",
	"1f64d-1f3fc",
	"1f64d-1f3fc-200d-2640-fe0f",
	"1f64d-1f3fc-200d-2642-fe0f",
	"1f64d-1f3fd",
	"1f64d-1f3fd-200d-2640-fe0f",
	"1f64d-1f3fd-200d-2642-fe0f",
	"1f64d-1f3fe",
	"1f64d-1f3fe-200d-2640-fe0f",
	"1f64d-1f3fe-200d-2642-fe0f",
	"1f64d-1f3ff",
	"1f64d-1f3ff-200d-2640-fe0f",
	"1f64d-1f3ff-200d-2642-fe0f",
	"1f64d-200d-2640-fe0f",
	"1f64d-200d-2642-fe0f",
	"1f64e",
	"1f64e-1f3fb",
	"1f64e-1f3fb-200d-2640-fe0f",
	"1f64e-1f3fb-200d-2642-fe0f",
	"1f64e-1f3fc",
	"1f64e-1f3fc-200d-2640-fe0f",
	"1f64e-1f3fc-200d-2642-fe0f",
	"1f64e-1f3fd",
	"1f64e-1f3fd-200d-2640-fe0f",
	"1f64e-1f3fd-200d-2642-fe0f",
	"1f64e-1f3fe",
	"1f64e-1f3fe-200d-2640-fe0f",
	"1f64e-1f3fe-200d-2642-fe0f",
	"1f64e-1f3ff",
	"1f64e-1f3ff-200d-2640-fe0f",
	"1f64e-1f3ff-200d-2642-fe0f",
	"1f64e-200d-2640-fe0f",
	"1f64e-200d-2642-fe0f",
	"1f64f",
	"1f64f-1f3fb",
	"1f64f-1f3fc",
	"1f64f-1f3fd",
	"1f64f-1f3fe",
	"1f64f-1f3ff",
	"1f680",
	"1f681",
	"1f682",
	"1f683",
	"1f684",
	"1f685",
	"1f686",
	"1f687",
	"1f688",
	"1f689",
	"1f68a",
	"1f68b",
	"1f68c",
	"1f68d",
	"1f68e",
	"1f68f",
	"1f690",
	"1f691",
	"1f692",
	"1f693",
	"1f694",
	"1f695",
	"1f696",
	"1f697",
	"1f698",
	"1f699",
	"1f69a",
	"1f69b",
	"1f69c",
	"1f69d",
	"1f69e",
	"1f69f",
	"1f6a0",
	"1f6a1",
	"1f6a2",
	"1f6a3",
	"1f6a3-1f3fb",
	"1f6a3-1f3fb-200d-2640-fe0f",
	"1f6a3-1f3fb-200d-2642-fe0f",
	"1f6a3-1f3fc",
	"1f6a3-1f3fc-200d-2640-fe0f",
	"1f6a3-1f3fc-200d-2642-fe0f",
	"1f6a3-1f3fd",
	"1f6a3-1f3fd-200d-2640-fe0f",
	"1f6a3-1f3fd-200d-2642-fe0f",
	"1f6a3-1f3fe",
	"1f6a3-1f3fe-200d-2640-fe0f",
	"1f6a3-1f3fe-200d-2642-fe0f",
	"1f6a3-1f3ff",
	"1f6a3-1f3ff-200d-2640-fe0f",
	"1f6a3-1f3ff-200d-2642-fe0f",
	"1f6a3-200d-2640-fe0f",
	"1f6a3-200d-2642-fe0f",
	"1f6a4",
	"1f6a5",
	"1f6a6",
	"1f6a7",
	"1f6a8",
	"1f6a9",
	"1f6aa",
	"1f6ab",
	"1f6ac",
	"1f6ad",
	"1f6ae",
	"1f6af",
	"1f6b0",
	"1f6b1",
	"1f6b2",
	"1f6b3",
	"1f6b4",
	"1f6b4-1f3fb",
	"1f6b4-1f3fb-200d-2640-fe0f",
	"1f6b4-1f3fb-200d-2642-fe0f",
	"1f6b4-1f3fc",
	"1f6b4-1f3fc-200d-2640-fe0f",
	"1f6b4-1f3fc-200d-2642-fe0f",
	"1f6b4-1f3fd",
	"1f6b4-1f3fd-200d-2640-fe0f",
	"1f6b4-1f3fd-200d-2642-fe0f",
	"1f6b4-1f3fe",
	"1f6b4-1f3fe-200d-2640-fe0f",
	"1f6b4-1f3fe-200d-2642-fe0f",
	"1f6b4-1f3ff",
	"1f6b4-1f3ff-200d-2640-fe0f",
	"1f6b4-1f3ff-200d-2642-fe0f",
	"1f6b4-200d-2640-fe0f",
	"1f6b4-200d-2642-fe0f",
	"1f6b5",
	"1f6b5-1f3fb",
	"1f6b5-1f3fb-200d-2640-fe0f",
	"1f6b5-1f3fb-200d-2642-fe0f",
	"1f6b5-1f3fc",
	"1f6b5-1f3fc-200d-2640-fe0f",
	"1f6b5-1f3fc-200d-2642-fe0f",
	"1f6b5-1f3fd",
	"1f6b5-1f3fd-200d-2640-fe0f",
	"1f6b5-1f3fd-200d-2642-fe0f",
	"1f6b5-1f3fe",
	"1f6b5-1f3fe-200d-2640-fe0f",
	"1f6b5-1f3fe-200d-2642-fe0f",
	"1f6b5-1f3ff",
	"1f6b5-1f3ff-200d-2640-fe0f",
	"1f6b5-1f3ff-200d-2642-fe0f",
	"1f6b5-200d-2640-fe0f",
	"1f6b5-200d-2642-fe0f",
	"1f6b6",
	"1f6b6-1f3fb",
	"1f6b6-1f3fb-200d-2640-fe0f",
	"1f6b6-1f3fb-200d-2642-fe0f",
	"1f6b6-1f3fc",
	"1f6b6-1f3fc-200d-2640-fe0f",
	"1f6b6-1f3fc-200d-2642-fe0f",
	"1f6b6-1f3fd",
	"1f6b6-1f3fd-200d-2640-fe0f",
	"1f6b6-1f3fd-200d-2642-fe0f",
	"1f6b6-1f3fe",
	"1f6b6-1f3fe-200d-2640-fe0f",
	"1f6b6-1f3fe-200d-2642-fe0f",
	"1f6b6-1f3ff",
	"1f6b6-1f3ff-200d-2640-fe0f",
	"1f6b6-1f3ff-200d-2642-fe0f",
	"1f6b6-200d-2640-fe0f",
	"1f6b6-200d-2642-fe0f",
	"1f6b7",
	"1f6b8",
	"1f6b9",
	"1f6ba",
	"1f6bb",
	"1f6bc",
	"1f6bd",
	"1f6be",
	"1f6bf",
	"1f6c0",
	"1f6c0-1f3fb",
	"1f6c0-1f3fc",
	"1f6c0-1f3fd",
	"1f6c0-1f3fe",
	"1f6c0-1f3ff",
	"1f6c1",
	"1f6c2",
	"1f6c3",
	"1f6c4",
	"1f6c5",
	"1f6cb",
	"1f6cc",
	"1f6cc-1f3fb",
	"1f6cc-1f3fc",
	"1f6cc-1f3fd",
	"1f6cc-1f3fe",
	"1f6cc-1f3ff",
	"1f6cd",
	"1f6ce",
	"1f6cf",
	"1f6d0",
	"1f6d1",
	"1f6d2",
	"1f6d5",
	"1f6d6",
	"1f6d7",
	"1f6e0",
	"1f6e1",
	"1f6e2",
	"1f6e3",
	"1f6e4",
	"1f6e5",
	"1f6e9",
	"1f6eb",
	"1f6ec",
	"1f6f0",
	"1f6f3",
	"1f6f4",
	"1f6f5",
	"1f6f6",
	"1f6f7",
	"1f6f8",
	"1f6f9",
	"1f6fa",
	"1f6fb",
	"1f6fc",
	"1f7e0",
	"1f7e1",
	"1f7e2",
	"1f7e3",
	"1f7e4",
	"1f7e5",
	"1f7e6",
	"1f7e7",
	"1f7e8",
	"1f7e9",
	"1f7ea",
	"1f7eb",
	"1f90c",
	"1f90c-1f3fb",
	"1f90c-1f3fc",
	"1f90c-1f3fd",
	"1f90c-1f3fe",
	"1f90c-1f3ff",
	"1f90d",
	"1f90e",
	"1f90f",
	"1f90f-1f3fb",
	"1f90f-1f3fc",
	"1f90f-1f3fd",
	"1f90f-1f3fe",
	"1f90f-1f3ff",
	"1f910",
	"1f911",
	"1f912",
	"1f913",
	"1f914",
	"1f915",
	"1f916",
	"1f917",
	"1f918",
	"1f918-1f3fb",
	"1f918-1f3fc",
	"1f918-1f3fd",
	"1f918-1f3fe",
	"1f918-1f3ff",
	"1f919",
	"1f919-1f3fb",
	"1f919-1f3fc",
	"1f919-1f3fd",
	"1f919-1f3fe",
	"1f919-1f3ff",
	"1f91a",
	"1f91a-1f3fb",
	"1f91a-1f3fc",
	"1f91a-1f3fd",
	"1f91a-1f3fe",
	"1f91a-1f3ff",
	"1f91b",
	"1f91b-1f3fb",
	"1f91b-1f3fc",
	"1f91b-1f3fd",
	"1f91b-1f3fe",
	"1f91b-1f3ff",
	"1f91c",
	"1f91c-1f3fb",
	"1f91c-1f3fc",
	"1f91c-1f3fd",
	"1f91c-1f3fe",
	"1f91c-1f3ff",
	"1f91d",
	"1f91e",
	"1f91e-1f3fb",
	"1f91e-1f3fc",
	"1f91e-1f3fd",
	"1f91e-1f3fe",
	"1f91e-1f3ff",
	"1f91f",
	"1f91f-1f3fb",
	"1f91f-1f3fc",
	"1f91f-1f3fd",
	"1f91f-1f3fe",
	"1f91f-1f3ff",
	"1f920",
	"1f921",
	"1f922",
	"1f923",
	"1f924",
	"1f925",
	"1f926",
	"1f926-1f3fb",
	"1f926-1f3fb-200d-2640-fe0f",
	"1f926-1f3fb-200d-2642-fe0f",
	"1f926-1f3fc",
	"1f926-1f3fc-200d-2640-fe0f",
	"1f926-1f3fc-200d-2642-fe0f",
	"1f926-1f3fd",
	"1f926-1f3fd-200d-2640-fe0f",
	"1f926-1f3fd-200d-2642-fe0f",
	"1f926-1f3fe",
	"1f926-1f3fe-200d-2640-fe0f",
	"1f926-1f3fe-200d-2642-fe0f",
	"1f926-1f3ff",
	"1f926-1f3ff-200d-2640-fe0f",
	"1f926-1f3ff-200d-2642-fe0f",
	"1f926-200d-2640-fe0f",
	"1f926-200d-2642-fe0f",
	"1f927",
	"1f928",
	"1f929",
	"1f92a",
	"1f92b",
	"1f92c",
	"1f92d",
	"1f92e",
	"1f92f",
	"1f930",
	"1f930-1f3fb",
	"1f930-1f3fc",
	"1f930-1f3fd",
	"1f930-1f3fe",
	"1f930-1f3ff",
	"1f931",
	"1f931-1f3fb",
	"1f931-1f3fc",
	"1f931-1f3fd",
	"1f931-1f3fe",
	"1f931-1f3ff",
	"1f932",
	"1f932-1f3fb",
	"1f932-1f3fc",
	"1f932-1f3fd",
	"1f932-1f3fe",
	"1f932-1f3ff",
	"1f933",
	"1f933-1f3fb",
	"1f933-1f3fc",
	"1f933-1f3fd",
	"1f933-1f3fe",
	"1f933-1f3ff",
	"1f934",
	"1f934-1f3fb",
	"1f934-1f3fc",
	"1f934-1f3fd",
	"1f934-1f3fe",
	"1f934-1f3ff",
	"1f935",
	"1f935-1f3fb",
	"1f935-1f3fb-200d-2640-fe0f",
	"1f935-1f3fb-200d-2642-fe0f",
	"1f935-1f3fc",
	"1f935-1f3fc-200d-2640-fe0f",
	"1f935-1f3fc-200d-2642-fe0f",
	"1f935-1f3fd",
	"1f935-1f3fd-200d-2640-fe0f",
	"1f935-1f3fd-200d-2642-fe0f",
	"1f935-1f3fe",
	"1f935-1f3fe-200d-2640-fe0f",
	"1f935-1f3fe-200d-2642-fe0f",
	"1f935-1f3ff",
	"1f935-1f3ff-200d-2640-fe0f",
	"1f935-1f3ff-200d-2642-fe0f",
	"1f935-200d-2640-fe0f",
	"1f935-200d-2642-fe0f",
	"1f936",
	"1f936-1f3fb",
	"1f936-1f3fc",
	"1f936-1f3fd",
	"1f936-1f3fe",
	"1f936-1f3ff",
	"1f937",
	"1f937-1f3fb",
	"1f937-1f3fb-200d-2640-fe0f",
	"1f937-1f3fb-200d-2642-fe0f",
	"1f937-1f3fc",
	"1f937-1f3fc-200d-2640-fe0f",
	"1f937-1f3fc-200d-2642-fe0f",
	"1f937-1f3fd",
	"1f937-1f3fd-200d-2640-fe0f",
	"1f937-1f3fd-200d-2642-fe0f",
	"1f937-1f3fe",
	"1f937-1f3fe-200d-2640-fe0f",
	"1f937-1f3fe-200d-2642-fe0f",
	"1f937-1f3ff",
	"1f937-1f3ff-200d-2640-fe0f",
	"1f937-1f3ff-200d-2642-fe0f",
	"1f937-200d-2640-fe0f",
	"1f937-200d-2642-fe0f",
	"1f938",
	"1f938-1f3fb",
	"1f938-1f3fb-200d-2640-fe0f",
	"1f938-1f3fb-200d-2642-fe0f",
	"1f938-1f3fc",
	"1f938-1f3fc-200d-2640-fe0f",
	"1f938-1f3fc-200d-2642-fe0f",
	"1f938-1f3fd",
	"1f938-1f3fd-200d-2640-fe0f",
	"1f938-1f3fd-200d-2642-fe0f",
	"1f938-1f3fe",
	"1f938-1f3fe-200d-2640-fe0f",
	"1f938-1f3fe-200d-2642-fe0f",
	"1f938-1f3ff",
	"1f938-1f3ff-200d-2640-fe0f",
	"1f938-1f3ff-200d-2642-fe0f",
	"1f938-200d-2640-fe0f",
	"1f938-200d-2642-fe0f",
	"1f939",
	"1f939-1f3fb",
	"1f939-1f3fb-200d-2640-fe0f",
	"1f939-1f3fb-200d-2642-fe0f",
	"1f939-1f3fc",
	"1f939-1f3fc-200d-2640-fe0f",
	"1f939-1f3fc-200d-2642-fe0f",
	"1f939-1f3fd",
	"1f939-1f3fd-200d-2640-fe0f",
	"1f939-1f3fd-200d-2642-fe0f",
	"1f939-1f3fe",
	"1f939-1f3fe-200d-2640-fe0f",
	"1f939-1f3fe-200d-2642-fe0f",
	"1f939-1f3ff",
	"1f939-1f3ff-200d-2640-fe0f",
	"1f939-1f3ff-200d-2642-fe0f",
	"1f939-200d-2640-fe0f",
	"1f939-200d-2642-fe0f",
	"1f93a",
	"1f93c",
	"1f93c-200d-2640-fe0f",
	"1f93c-200d-2642-fe0f",
	"1f93d",
	"1f93d-1f3fb",
	"1f93d-1f3fb-200d-2640-fe0f",
	"1f93d-1f3fb-200d-2642-fe0f",
	"1f93d-1f3fc",
	"1f93d-1f3fc-200d-2640-fe0f",
	"1f93d-1f3fc-200d-2642-fe0f",
	"1f93d-1f3fd",
	"1f93d-1f3fd-200d-2640-fe0f",
	"1f93d-1f3fd-200d-2642-fe0f",
	"1f93d-1f3fe",
	"1f93d-1f3fe-200d-2640-fe0f",
	"1f93d-1f3fe-200d-2642-fe0f",
	"1f93d-1f3ff",
	"1f93d-1f3ff-200d-2640-fe0f",
	"1f93d-1f3ff-200d-2642-fe0f",
	"1f93d-200d-2640-fe0f",
	"1f93d-200d-2642-fe0f",
	"1f93e",
	"1f93e-1f3fb",
	"1f93e-1f3fb-200d-2640-fe0f",
	"1f93e-1f3fb-200d-2642-fe0f",
	"1f93e-1f3fc",
	"1f93e-1f3fc-200d-2640-fe0f",
	"1f93e-1f3fc-200d-2642-fe0f",
	"1f93e-1f3fd",
	"1f93e-1f3fd-200d-2640-fe0f",
	"1f93e-1f3fd-200d-2642-fe0f",
	"1f93e-1f3fe",
	"1f93e-1f3fe-200d-2640-fe0f",
	"1f93e-1f3fe-200d-2642-fe0f",
	"1f93e-1f3ff",
	"1f93e-1f3ff-200d-2640-fe0f",
	"1f93e-1f3ff-200d-2642-fe0f",
	"1f93e-200d-2640-fe0f",
	"1f93e-200d-2642-fe0f",
	"1f93f",
	"1f940",
	"1f941",
	"1f942",
	"1f943",
	"1f944",
	"1f945",
	"1f947",
	"1f948",
	"1f949",
	"1f94a",
	"1f94b",
	"1f94c",
	"1f94d",
	"1f94e",
	"1f94f",
	"1f950",
	"1f951",
	"1f952",
	"1f953",
	"1f954",
	"1f955",
	"1f956",
	"1f957",
	"1f958",
	"1f959",
	"1f95a",
	"1f95b",
	"1f95c",
	"1f95d",
	"1f95e",
	"1f95f",
	"1f960",
	"1f961",
	"1f962",
	"1f963",
	"1f964",
	"1f965",
	"1f966",
	"1f967",
	"1f968",
	"1f969",
	"1f96a",
	"1f96b",
	"1f96c",
	"1f96d",
	"1f96e",
	"1f96f",
	"1f970",
	"1f971",
	"1f972",
	"1f973",
	"1f974",
	"1f975",
	"1f976",
	"1f977",
	"1f977-1f3fb",
	"1f977-1f3fc",
	"1f977-1f3fd",
	"1f977-1f3fe",
	"1f977-1f3ff",
	"1f978",
	"1f97a",
	"1f97b",
	"1f97c",
	"1f97d",
	"1f97e",
	"1f97f",
	"1f980",
	"1f981",
	"1f982",
	"1f983",
	"1f984",
	"1f985",
	"1f986",
	"1f987",
	"1f988",
	"1f989",
	"1f98a",
	"1f98b",
	"1f98c",
	"1f98d",
	"1f98e",
	"1f98f",
	"1f990",
	"1f991",
	"1f992",
	"1f993",
	"1f994",
	"1f995",
	"1f996",
	"1f997",
	"1f998",
	"1f999",
	"1f99a",
	"1f99b",
	"1f99c",
	"1f99d",
	"1f99e",
	"1f99f",
	"1f9a0",
	"1f9a1",
	"1f9a2",
	"1f9a3",
	"1f9a4",
	"1f9a5",
	"1f9a6",
	"1f9a7",
	"1f9a8",
	"1f9a9",
	"1f9aa",
	"1f9ab",
	"1f9ac",
	"1f9ad",
	"1f9ae",
	"1f9af",
	"1f9b0",
	"1f9b1",
	"1f9b2",
	"1f9b3",
	"1f9b4",
	"1f9b5",
	"1f9b5-1f3fb",
	"1f9b5-1f3fc",
	"1f9b5-1f3fd",
	"1f9b5-1f3fe",
	"1f9b5-1f3ff",
	"1f9b6",
	"1f9b6-1f3fb",
	"1f9b6-1f3fc",
	"1f9b6-1f3fd",
	"1f9b6-1f3fe",
	"1f9b6-1f3ff",
	"1f9b7",
	"1f9b8",
	"1f9b8-1f3fb",
	"1f9b8-1f3fb-200d-2640-fe0f",
	"1f9b8-1f3fb-200d-2642-fe0f",
	"1f9b8-1f3fc",
	"1f9b8-1f3fc-200d-2640-fe0f",
	"1f9b8-1f3fc-200d-2642-fe0f",
	"1f9b8-1f3fd",
	"1f9b8-1f3fd-200d-2640-fe0f",
	"1f9b8-1f3fd-200d-2642-fe0f",
	"1f9b8-1f3fe",
	"1f9b8-1f3fe-200d-2640-fe0f",
	"1f9b8-1f3fe-200d-2642-fe0f",
	"1f9b8-1f3ff",
	"1f9b8-1f3ff-200d-2640-fe0f",
	"1f9b8-1f3ff-200d-2642-fe0f",
	"1f9b8-200d-2640-fe0f",
	"1f9b8-200d-2642-fe0f",
	"1f9b9",
	"1f9b9-1f3fb",
	"1f9b9-1f3fb-200d-2640-fe0f",
	"1f9b9-1f3fb-200d-2642-fe0f",
	"1f9b9-1f3fc",
	"1f9b9-1f3fc-200d-2640-fe0f",
	"1f9b9-1f3fc-200d-2642-fe0f",
	"1f9b9-1f3fd",
	"1f9b9-1f3fd-200d-2640-fe0f",
	"1f9b9-1f3fd-200d-2642-fe0f",
	"1f9b9-1f3fe",
	"1f9b9-1f3fe-200d-2640-fe0f",
	"1f9b9-1f3fe-200d-2642-fe0f",
	"1f9b9-1f3ff",
	"1f9b9-1f3ff-200d-2640-fe0f",
	"1f9b9-1f3ff-200d-2642-fe0f",
	"1f9b9-200d-2640-fe0f",
	"1f9b9-200d-2642-fe0f",
	"1f9ba",
	"1f9bb",
	"1f9bb-1f3fb",
	"1f9bb-1f3fc",
	"1f9bb-1f3fd",
	"1f9bb-1f3fe",
	"1f9bb-1f3ff",
	"1f9bc",
	"1f9bd",
	"1f9be",
	"1f9bf",
	"1f9c0",
	"1f9c1",
	"1f9c2",
	"1f9c3",
	"1f9c4",
	"1f9c5",
	"1f9c6",
	"1f9c7",
	"1f9c8",
	"1f9c9",
	"1f9ca",
	"1f9cb",
	"1f9cd",
	"1f9cd-1f3fb",
	"1f9cd-1f3fb-200d-2640-fe0f",
	"1f9cd-1f3fb-200d-2642-fe0f",
	"1f9cd-1f3fc",
	"1f9cd-1f3fc-200d-2640-fe0f",
	"1f9cd-1f3fc-200d-2642-fe0f",
	"1f9cd-1f3fd",
	"1f9cd-1f3fd-200d-2640-fe0f",
	"1f9cd-1f3fd-200d-2642-fe0f",
	"1f9cd-1f3fe",
	"1f9cd-1f3fe-200d-2640-fe0f",
	"1f9cd-1f3fe-200d-2642-fe0f",
	"1f9cd-1f3ff",
	"1f9cd-1f3ff-200d-2640-fe0f",
	"1f9cd-1f3ff-200d-2642-fe0f",
	"1f9cd-200d-2640-fe0f",
	"1f9cd-200d-2642-fe0f",
	"1f9ce",
	"1f9ce-1f3fb",
	"1f9ce-1f3fb-200d-2640-fe0f",
	"1f9ce-1f3fb-200d-2642-fe0f",
	"1f9ce-1f3fc",
	"1f9ce-1f3fc-200d-2640-fe0f",
	"1f9ce-1f3fc-200d-2642-fe0f",
	"1f9ce-1f3fd",
	"1f9ce-1f3fd-200d-2640-fe0f",
	"1f9ce-1f3fd-200d-2642-fe0f",
	"1f9ce-1f3fe",
	"1f9ce-1f3fe-200d-2640-fe0f",
	"1f9ce-1f3fe-200d-2642-fe0f",
	"1f9ce-1f3ff",
	"1f9ce-1f3ff-200d-2640-fe0f",
	"1f9ce-1f3ff-200d-2642-fe0f",
	"1f9ce-200d-2640-fe0f",
	"1f9ce-200d-2642-fe0f",
	"1f9cf",
	"1f9cf-1f3fb",
	"1f9cf-1f3fb-200d-2640-fe0f",
	"1f9cf-1f3fb-200d-2642-fe0f",
	"1f9cf-1f3fc",
	"1f9cf-1f3fc-200d-2640-fe0f",
	"1f9cf-1f3fc-200d-2642-fe0f",
	"1f9cf-1f3fd",
	"1f9cf-1f3fd-200d-2640-fe0f",
	"1f9cf-1f3fd-200d-2642-fe0f",
	"1f9cf-1f3fe",
	"1f9cf-1f3fe-200d-2640-fe0f",
	"1f9cf-1f3fe-200d-2642-fe0f",
	"1f9cf-1f3ff",
	"1f9cf-1f3ff-200d-2640-fe0f",
	"1f9cf-1f3ff-200d-2642-fe0f",
	"1f9cf-200d-2640-fe0f",
	"1f9cf-200d-2642-fe0f",
	"1f9d0",
	"1f9d1",
	"1f9d1-1f3fb",
	"1f9d1-1f3fb-200d-1f3a4",
	"1f9d1-1f3fb-200d-1f3a8",
	"1f9d1-1f3fb-200d-1f3eb",
	"1f9d1-1f3fb-200d-1f3ed",
	"1f9d1-1f3fb-200d-1f4bb",
	"1f9d1-1f3fb-200d-1f4bc",
	"1f9d1-1f3fb-200d-1f9af",
	"1f9d1-1f3fb-200d-1f9b0",
	"1f9d1-1f3fb-200d-1f9b1",
	"1f9d1-1f3fb-200d-1f9b2",
	"1f9d1-1f3fb-200d-1f9b3",
	"1f9d1-1f3fb-200d-1f9bc",
	"1f9d1-1f3fb-200d-1f9bd",
	"1f9d1-1f3fb-200d-1f33e",
	"1f9d1-1f3fb-200d-1f37c",
	"1f9d1-1f3fb-200d-1f52c",
	"1f9d1-1f3fb-200d-1f91d-200d-1f9d1-1f3fb",
	"1f9d1-1f3fb-200d-1f91d-200d-1f9d1-1f3fc",
	"1f9d1-1f3fb-200d-1f91d-200d-1f9d1-1f3fd",
	"1f9d1-1f3fb-200d-1f91d-200d-1f9d1-1f3fe",
	"1f9d1-1f3fb-200d-1f91d-200d-1f9d1-1f3ff",
	"1f9d1-1f3fb-200d-1f373",
	"1f9d1-1f3fb-200d-1f384",
	"1f9d1-1f3fb-200d-1f393",
	"1f9d1-1f3fb-200d-1f527",
	"1f9d1-1f3fb-200d-1f680",
	"1f9d1-1f3fb-200d-1f692",
	"1f9d1-1f3fb-200d-2695-fe0f",
	"1f9d1-1f3fb-200d-2696-fe0f",
	"1f9d1-1f3fb-200d-2708-fe0f",
	"1f9d1-1f3fc",
	"1f9d1-1f3fc-200d-1f3a4",
	"1f9d1-1f3fc-200d-1f3a8",
	"1f9d1-1f3fc-200d-1f3eb",
	"1f9d1-1f3fc-200d-1f3ed",
	"1f9d1-1f3fc-200d-1f4bb",
	"1f9d1-1f3fc-200d-1f4bc",
	"1f9d1-1f3fc-200d-1f9af",
	"1f9d1-1f3fc-200d-1f9b0",
	"1f9d1-1f3fc-200d-1f9b1",
	"1f9d1-1f3fc-200d-1f9b2",
	"1f9d1-1f3fc-200d-1f9b3",
	"1f9d1-1f3fc-200d-1f9bc",
	"1f9d1-1f3fc-200d-1f9bd",
	"1f9d1-1f3fc-200d-1f33e",
	"1f9d1-1f3fc-200d-1f37c",
	"1f9d1-1f3fc-200d-1f52c",
	"1f9d1-1f3fc-200d-1f91d-200d-1f9d1-1f3fb",
	"1f9d1-1f3fc-200d-1f91d-200d-1f9d1-1f3fc",
	"1f9d1-1f3fc-200d-1f91d-200d-1f9d1-1f3fd",
	"1f9d1-1f3fc-200d-1f91d-200d-1f9d1-1f3fe",
	"1f9d1-1f3fc-200d-1f91d-200d-1f9d1-1f3ff",
	"1f9d1-1f3fc-200d-1f373",
	"1f9d1-1f3fc-200d-1f384",
	"1f9d1-1f3fc-200d-1f393",
	"1f9d1-1f3fc-200d-1f527",
	"1f9d1-1f3fc-200d-1f680",
	"1f9d1-1f3fc-200d-1f692",
	"1f9d1-1f3fc-200d-2695-fe0f",
	"1f9d1-1f3fc-200d-2696-fe0f",
	"1f9d1-1f3fc-200d-2708-fe0f",
	"1f9d1-1f3fd",
	"1f9d1-1f3fd-200d-1f3a4",
	"1f9d1-1f3fd-200d-1f3a8",
	"1f9d1-1f3fd-200d-1f3eb",
	"1f9d1-1f3fd-200d-1f3ed",
	"1f9d1-1f3fd-200d-1f4bb",
	"1f9d1-1f3fd-200d-1f4bc",
	"1f9d1-1f3fd-200d-1f9af",
	"1f9d1-1f3fd-200d-1f9b0",
	"1f9d1-1f3fd-200d-1f9b1",
	"1f9d1-1f3fd-200d-1f9b2",
	"1f9d1-1f3fd-200d-1f9b3",
	"1f9d1-1f3fd-200d-1f9bc",
	"1f9d1-1f3fd-200d-1f9bd",
	"1f9d1-1f3fd-200d-1f33e",
	"1f9d1-1f3fd-200d-1f37c",
	"1f9d1-1f3fd-200d-1f52c",
	"1f9d1-1f3fd-200d-1f91d-200d-1f9d1-1f3fb",
	"1f9d1-1f3fd-200d-1f91d-200d-1f9d1-1f3fc",
	"1f9d1-1f3fd-200d-1f91d-200d-1f9d1-1f3fd",
	"1f9d1-1f3fd-200d-1f91d-200d-1f9d1-1f3fe",
	"1f9d1-1f3fd-200d-1f91d-200d-1f9d1-1f3ff",
	"1f9d1-1f3fd-200d-1f373",
	"1f9d1-1f3fd-200d-1f384",
	"1f9d1-1f3fd-200d-1f393",
	"1f9d1-1f3fd-200d-1f527",
	"1f9d1-1f3fd-200d-1f680",
	"1f9d1-1f3fd-200d-1f692",
	"1f9d1-1f3fd-200d-2695-fe0f",
	"1f9d1-1f3fd-200d-2696-fe0f",
	"1f9d1-1f3fd-200d-2708-fe0f",
	"1f9d1-1f3fe",
	"1f9d1-1f3fe-200d-1f3a4",
	"1f9d1-1f3fe-200d-1f3a8",
	"1f9d1-1f3fe-200d-1f3eb",
	"1f9d1-1f3fe-200d-1f3ed",
	"1f9d1-1f3fe-200d-1f4bb",
	"1f9d1-1f3fe-200d-1f4bc",
	"1f9d1-1f3fe-200d-1f9af",
	"1f9d1-1f3fe-200d-1f9b0",
	"1f9d1-1f3fe-200d-1f9b1",
	"1f9d1-1f3fe-200d-1f9b2",
	"1f9d1-1f3fe-200d-1f9b3",
	"1f9d1-1f3fe-200d-1f9bc",
	"1f9d1-1f3fe-200d-1f9bd",
	"1f9d1-1f3fe-200d-1f33e",
	"1f9d1-1f3fe-200d-1f37c",
	"1f9d1-1f3fe-200d-1f52c",
	"1f9d1-1f3fe-200d-1f91d-200d-1f9d1-1f3fb",
	"1f9d1-1f3fe-200d-1f91d-200d-1f9d1-1f3fc",
	"1f9d1-1f3fe-200d-1f91d-200d-1f9d1-1f3fd",
	"1f9d1-1f3fe-200d-1f91d-200d-1f9d1-1f3fe",
	"1f9d1-1f3fe-200d-1f91d-200d-1f9d1-1f3ff",
	"1f9d1-1f3fe-200d-1f373",
	"1f9d1-1f3fe-200d-1f384",
	"1f9d1-1f3fe-200d-1f393",
	"1f9d1-1f3fe-200d-1f527",
	"1f9d1-1f3fe-200d-1f680",
	"1f9d1-1f3fe-200d-1f692",
	"1f9d1-1f3fe-200d-2695-fe0f",
	"1f9d1-1f3fe-200d-2696-fe0f",
	"1f9d1-1f3fe-200d-2708-fe0f",
	"1f9d1-1f3ff",
	"1f9d1-1f3ff-200d-1f3a4",
	"1f9d1-1f3ff-200d-1f3a8",
	"1f9d1-1f3ff-200d-1f3eb",
	"1f9d1-1f3ff-200d-1f3ed",
	"1f9d1-1f3ff-200d-1f4bb",
	"1f9d1-1f3ff-200d-1f4bc",
	"1f9d1-1f3ff-200d-1f9af",
	"1f9d1-1f3ff-200d-1f9b0",
	"1f9d1-1f3ff-200d-1f9b1",
	"1f9d1-1f3ff-200d-1f9b2",
	"1f9d1-1f3ff-200d-1f9b3",
	"1f9d1-1f3ff-200d-1f9bc",
	"1f9d1-1f3ff-200d-1f9bd",
	"1f9d1-1f3ff-200d-1f33e",
	"1f9d1-1f3ff-200d-1f37c",
	"1f9d1-1f3ff-200d-1f52c",
	"1f9d1-1f3ff-200d-1f91d-200d-1f9d1-1f3fb",
	"1f9d1-1f3ff-200d-1f91d-200d-1f9d1-1f3fc",
	"1f9d1-1f3ff-200d-1f91d-200d-1f9d1-1f3fd",
	"1f9d1-1f3ff-200d-1f91d-200d-1f9d1-1f3fe",
	"1f9d1-1f3ff-200d-1f91d-200d-1f9d1-1f3ff",
	"1f9d1-1f3ff-200d-1f373",
	"1f9d1-1f3ff-200d-1f384",
	"1f9d1-1f3ff-200d-1f393",
	"1f9d1-1f3ff-200d-1f527",
	"1f9d1-1f3ff-200d-1f680",
	"1f9d1-1f3ff-200d-1f692",
	"1f9d1-1f3ff-200d-2695-fe0f",
	"1f9d1-1f3ff-200d-2696-fe0f",
	"1f9d1-1f3ff-200d-2708-fe0f",
	"1f9d1-200d-1f3a4",
	"1f9d1-200d-1f3a8",
	"1f9d1-200d-1f3eb",
	"1f9d1-200d-1f3ed",
	"1f9d1-200d-1f4bb",
	"1f9d1-200d-1f4bc",
	"1f9d1-200d-1f9af",
	"1f9d1-200d-1f9b0",
	"1f9d1-200d-1f9b1",
	"1f9d1-200d-1f9b2",
	"1f9d1-200d-1f9b3",
	"1f9d1-200d-1f9bc",
	"1f9d1-200d-1f9bd",
	"1f9d1-200d-1f33e",
	"1f9d1-200d-1f37c",
	"1f9d1-200d-1f52c",
	"1f9d1-200d-1f91d-200d-1f9d1",
	"1f9d1-200d-1f373",
	"1f9d1-200d-1f384",
	"1f9d1-200d-1f393",
	"1f9d1-200d-1f527",
	"1f9d1-200d-1f680",
	"1f9d1-200d-1f692",
	"1f9d1-200d-2695-fe0f",
	"1f9d1-200d-2696-fe0f",
	"1f9d1-200d-2708-fe0f",
	"1f9d2",
	"1f9d2-1f3fb",
	"1f9d2-1f3fc",
	"1f9d2-1f3fd",
	"1f9d2-1f3fe",
	"1f9d2-1f3ff",
	"1f9d3",
	"1f9d3-1f3fb",
	"1f9d3-1f3fc",
	"1f9d3-1f3fd",
	"1f9d3-1f3fe",
	"1f9d3-1f3ff",
	"1f9d4",
	"1f9d4-1f3fb",
	"1f9d4-1f3fc",
	"1f9d4-1f3fd",
	"1f9d4-1f3fe",
	"1f9d4-1f3ff",
	"1f9d5",
	"1f9d5-1f3fb",
	"1f9d5-1f3fc",
	"1f9d5-1f3fd",
	"1f9d5-1f3fe",
	"1f9d5-1f3ff",
	"1f9d6",
	"1f9d6-1f3fb",
	"1f9d6-1f3fb-200d-2640-fe0f",
	"1f9d6-1f3fb-200d-2642-fe0f",
	"1f9d6-1f3fc",
	"1f9d6-1f3fc-200d-2640-fe0f",
	"1f9d6-1f3fc-200d-2642-fe0f",
	"1f9d6-1f3fd",
	"1f9d6-1f3fd-200d-2640-fe0f",
	"1f9d6-1f3fd-200d-2642-fe0f",
	"1f9d6-1f3fe",
	"1f9d6-1f3fe-200d-2640-fe0f",
	"1f9d6-1f3fe-200d-2642-fe0f",
	"1f9d6-1f3ff",
	"1f9d6-1f3ff-200d-2640-fe0f",
	"1f9d6-1f3ff-200d-2642-fe0f",
	"1f9d6-200d-2640-fe0f",
	"1f9d6-200d-2642-fe0f",
	"1f9d7",
	"1f9d7-1f3fb",
	"1f9d7-1f3fb-200d-2640-fe0f",
	"1f9d7-1f3fb-200d-2642-fe0f",
	"1f9d7-1f3fc",
	"1f9d7-1f3fc-200d-2640-fe0f",
	"1f9d7-1f3fc-200d-2642-fe0f",
	"1f9d7-1f3fd",
	"1f9d7-1f3fd-200d-2640-fe0f",
	"1f9d7-1f3fd-200d-2642-fe0f",
	"1f9d7-1f3fe",
	"1f9d7-1f3fe-200d-2640-fe0f",
	"1f9d7-1f3fe-200d-2642-fe0f",
	"1f9d7-1f3ff",
	"1f9d7-1f3ff-200d-2640-fe0f",
	"1f9d7-1f3ff-200d-2642-fe0f",
	"1f9d7-200d-2640-fe0f",
	"1f9d7-200d-2642-fe0f",
	"1f9d8",
	"1f9d8-1f3fb",
	"1f9d8-1f3fb-200d-2640-fe0f",
	"1f9d8-1f3fb-200d-2642-fe0f",
	"1f9d8-1f3fc",
	"1f9d8-1f3fc-200d-2640-fe0f",
	"1f9d8-1f3fc-200d-2642-fe0f",
	"1f9d8-1f3fd",
	"1f9d8-1f3fd-200d-2640-fe0f",
	"1f9d8-1f3fd-200d-2642-fe0f",
	"1f9d8-1f3fe",
	"1f9d8-1f3fe-200d-2640-fe0f",
	"1f9d8-1f3fe-200d-2642-fe0f",
	"1f9d8-1f3ff",
	"1f9d8-1f3ff-200d-2640-fe0f",
	"1f9d8-1f3ff-200d-2642-fe0f",
	"1f9d8-200d-2640-fe0f",
	"1f9d8-200d-2642-fe0f",
	"1f9d9",
	"1f9d9-1f3fb",
	"1f9d9-1f3fb-200d-2640-fe0f",
	"1f9d9-1f3fb-200d-2642-fe0f",
	"1f9d9-1f3fc",
	"1f9d9-1f3fc-200d-2640-fe0f",
	"1f9d9-1f3fc-200d-2642-fe0f",
	"1f9d9-1f3fd",
	"1f9d9-1f3fd-200d-2640-fe0f",
	"1f9d9-1f3fd-200d-2642-fe0f",
	"1f9d9-1f3fe",
	"1f9d9-1f3fe-200d-2640-fe0f",
	"1f9d9-1f3fe-200d-2642-fe0f",
	"1f9d9-1f3ff",
	"1f9d9-1f3ff-200d-2640-fe0f",
	"1f9d9-1f3ff-200d-2642-fe0f",
	"1f9d9-200d-2640-fe0f",
	"1f9d9-200d-2642-fe0f",
	"1f9da",
	"1f9da-1f3fb",
	"1f9da-1f3fb-200d-2640-fe0f",
	"1f9da-1f3fb-200d-2642-fe0f",
	"1f9da-1f3fc",
	"1f9da-1f3fc-200d-2640-fe0f",
	"1f9da-1f3fc-200d-2642-fe0f",
	"1f9da-1f3fd",
	"1f9da-1f3fd-200d-2640-fe0f",
	"1f9da-1f3fd-200d-2642-fe0f",
	"1f9da-1f3fe",
	"1f9da-1f3fe-200d-2640-fe0f",
	"1f9da-1f3fe-200d-2642-fe0f",
	"1f9da-1f3ff",
	"1f9da-1f3ff-200d-2640-fe0f",
	"1f9da-1f3ff-200d-2642-fe0f",
	"1f9da-200d-2640-fe0f",
	"1f9da-200d-2642-fe0f",
	"1f9db",
	"1f9db-1f3fb",
	"1f9db-1f3fb-200d-2640-fe0f",
	"1f9db-1f3fb-200d-2642-fe0f",
	"1f9db-1f3fc",
	"1f9db-1f3fc-200d-2640-fe0f",
	"1f9db-1f3fc-200d-2642-fe0f",
	"1f9db-1f3fd",
	"1f9db-1f3fd-200d-2640-fe0f",
	"1f9db-1f3fd-200d-2642-fe0f",
	"1f9db-1f3fe",
	"1f9db-1f3fe-200d-2640-fe0f",
	"1f9db-1f3fe-200d-2642-fe0f",
	"1f9db-1f3ff",
	"1f9db-1f3ff-200d-2640-fe0f",
	"1f9db-1f3ff-200d-2642-fe0f",
	"1f9db-200d-2640-fe0f",
	"1f9db-200d-2642-fe0f",
	"1f9dc",
	"1f9dc-1f3fb",
	"1f9dc-1f3fb-200d-2640-fe0f",
	"1f9dc-1f3fb-200d-2642-fe0f",
	"1f9dc-1f3fc",
	"1f9dc-1f3fc-200d-2640-fe0f",
	"1f9dc-1f3fc-200d-2642-fe0f",
	"1f9dc-1f3fd",
	"1f9dc-1f3fd-200d-2640-fe0f",
	"1f9dc-1f3fd-200d-2642-fe0f",
	"1f9dc-1f3fe",
	"1f9dc-1f3fe-200d-2640-fe0f",
	"1f9dc-1f3fe-200d-2642-fe0f",
	"1f9dc-1f3ff",
	"1f9dc-1f3ff-200d-2640-fe0f",
	"1f9dc-1f3ff-200d-2642-fe0f",
	"1f9dc-200d-2640-fe0f",
	"1f9dc-200d-2642-fe0f",
	"1f9dd",
	"1f9dd-1f3fb",
	"1f9dd-1f3fb-200d-2640-fe0f",
	"1f9dd-1f3fb-200d-2642-fe0f",
	"1f9dd-1f3fc",
	"1f9dd-1f3fc-200d-2640-fe0f",
	"1f9dd-1f3fc-200d-2642-fe0f",
	"1f9dd-1f3fd",
	"1f9dd-1f3fd-200d-2640-fe0f",
	"1f9dd-1f3fd-200d-2642-fe0f",
	"1f9dd-1f3fe",
	"1f9dd-1f3fe-200d-2640-fe0f",
	"1f9dd-1f3fe-200d-2642-fe0f",
	"1f9dd-1f3ff",
	"1f9dd-1f3ff-200d-2640-fe0f",
	"1f9dd-1f3ff-200d-2642-fe0f",
	"1f9dd-200d-2640-fe0f",
	"1f9dd-200d-2642-fe0f",
	"1f9de",
	"1f9de-200d-2640-fe0f",
	"1f9de-200d-2642-fe0f",
	"1f9df",
	"1f9df-200d-2640-fe0f",
	"1f9df-200d-2642-fe0f",
	"1f9e0",
	"1f9e1",
	"1f9e2",
	"1f9e3",
	"1f9e4",
	"1f9e5",
	"1f9e6",
	"1f9e7",
	"1f9e8",
	"1f9e9",
	"1f9ea",
	"1f9eb",
	"1f9ec",
	"1f9ed",
	"1f9ee",
	"1f9ef",
	"1f9f0",
	"1f9f1",
	"1f9f2",
	"1f9f3",
	"1f9f4",
	"1f9f5",
	"1f9f6",
	"1f9f7",
	"1f9f8",
	"1f9f9",
	"1f9fa",
	"1f9fb",
	"1f9fc",
	"1f9fd",
	"1f9fe",
	"1f9ff",
	"1fa70",
	"1fa71",
	"1fa72",
	"1fa73",
	"1fa74",
	"1fa78",
	"1fa79",
	"1fa7a",
	"1fa80",
	"1fa81",
	"1fa82",
	"1fa83",
	"1fa84",
	"1fa85",
	"1fa86",
	"1fa90",
	"1fa91",
	"1fa92",
	"1fa93",
	"1fa94",
	"1fa95",
	"1fa96",
	"1fa97",
	"1fa98",
	"1fa99",
	"1fa9a",
	"1fa9b",
	"1fa9c",
	"1fa9d",
	"1fa9e",
	"1fa9f",
	"1faa0",
	"1faa1",
	"1faa2",
	"1faa3",
	"1faa4",
	"1faa5",
	"1faa6",
	"1faa7",
	"1faa8",
	"1fab0",
	"1fab1",
	"1fab2",
	"1fab3",
	"1fab4",
	"1fab5",
	"1fab6",
	"1fac0",
	"1fac1",
	"1fac2",
	"1fad0",
	"1fad1",
	"1fad2",
	"1fad3",
	"1fad4",
	"1fad5",
	"1fad6"
};

unsigned char emojiCodepointCount[] = {2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,5,5,1,1,1,1,1,1,1,2,2,2,2,2,1,2,2,2,2,2,1,2,2,2,2,2,1,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,1,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,1,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,1,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,1,2,2,1,2,1,2,2,1,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,1,1,2,2,2,2,2,1,1,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,5,5,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,5,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,5,1,4,7,7,7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,1,1,1,1,1,1,3,1,2,2,2,2,2,1,2,2,2,2,2,1,1,1,2,2,2,2,2,1,2,2,2,2,2,1,2,2,2,2,2,1,2,2,2,2,2,1,2,2,2,2,2,1,2,2,2,2,2,1,2,2,2,2,2,1,2,2,2,2,2,1,2,2,2,2,2,1,2,2,2,2,2,1,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,2,2,2,2,2,1,2,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,4,4,4,4,4,4,5,5,5,2,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,4,4,4,4,4,4,5,5,5,2,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,4,4,4,4,4,4,5,5,5,2,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,4,4,4,4,4,4,5,5,5,2,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,4,4,4,4,4,4,5,5,5,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,5,3,5,5,5,7,5,7,7,5,7,5,7,7,3,3,3,4,4,4,8,6,1,2,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7,4,4,4,4,4,4,5,5,5,2,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7,4,4,4,4,4,4,5,5,5,2,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7,4,4,4,4,4,4,5,5,5,2,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7,4,4,4,4,4,4,5,5,5,2,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7,4,4,4,4,4,4,5,5,5,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,5,3,5,5,5,7,5,7,7,3,3,3,4,4,4,8,8,6,6,1,1,2,2,2,2,2,1,2,2,2,2,2,1,2,2,2,2,2,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,4,4,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,2,2,2,2,2,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,2,2,2,2,2,1,2,2,2,2,2,1,2,2,2,2,2,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,2,2,2,2,2,1,1,1,1,2,2,2,2,2,1,1,1,1,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,2,2,2,2,2,1,1,2,2,2,2,2,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,5,5,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,5,5,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,1,2,2,2,2,2,1,2,2,2,2,2,1,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,1,1,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,2,2,2,2,2,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,2,2,2,2,2,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,2,2,2,2,2,1,2,2,2,2,2,1,2,2,2,2,2,1,2,2,2,2,2,1,1,2,2,2,2,2,1,2,2,2,2,2,1,1,1,1,1,1,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,2,2,2,2,2,1,2,2,2,2,2,1,2,2,2,2,2,1,2,2,2,2,2,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,2,2,2,2,2,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,1,4,4,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,2,2,2,2,2,1,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,1,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,1,2,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,4,4,4,4,4,4,5,5,5,2,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,4,4,4,4,4,4,5,5,5,2,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,4,4,4,4,4,4,5,5,5,2,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,4,4,4,4,4,4,5,5,5,2,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,4,4,4,4,4,4,5,5,5,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,5,3,3,3,3,3,3,4,4,4,1,2,2,2,2,2,1,2,2,2,2,2,1,2,2,2,2,2,1,2,2,2,2,2,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,2,5,5,2,5,5,2,5,5,2,5,5,2,5,5,4,4,1,4,4,1,4,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

HBITMAP emojiBitmaps[EMOJI_COUNT];

unsigned char emojiIsLoaded[(EMOJI_COUNT / 8) + ((EMOJI_COUNT % 8) != 0 ? 1 : 0)];