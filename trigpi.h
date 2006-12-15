#include "crlibm.h"
#include "crlibm_private.h"

/*File generated by maple/trigpi.pl*/
#define ONEOVER256     3.90625000000000000000000000000000000000000000000000e-03 

#define TWOTOM124   4.70197740328915003187494614888898271127466222708835e-38 

#define TWOT0124    2.12676479325586539664609129644855132160000000000000e+37 

#define TWOTO42     4.39804651110400000000000000000000000000000000000000e+12 

#define TWOTO52     4.50359962737049600000000000000000000000000000000000e+15 

#define INV128      7.81250000000000000000000000000000000000000000000000e-03 

#define TWOTO5251        6.75539944105574400000000000000000000000000000000000e+15 

#define SMALLEST       4.94065645841246544176568792868221372365059802614325e-324

#define PIH 3.14159265358979311599796346854418516159057617187500e+00

#define PIM 1.22464679914735320717376402945839660462569212467758e-16

#define PIL -2.99476980971833966588701635421198401670550095233904e-33


typedef struct tPi_t_tag {double sh; double ch; double sm; double cm; double sl; double cl;} tPi_t;
static const tPi_t sincosTable[64] =
{
  { /* sin/cos(0*pi/128) */
    0.00000000000000000000000000000000000000000000000000e+00, /* sh */ 
    1.00000000000000000000000000000000000000000000000000e+00, /* ch */ 
    0.00000000000000000000000000000000000000000000000000e+00, /* sm */ 
    0.00000000000000000000000000000000000000000000000000e+00, /* cm */ 
    0.00000000000000000000000000000000000000000000000000e+00, /* sl */ 
    0.00000000000000000000000000000000000000000000000000e+00, /* cl */ 
  } , 
  { /* sin/cos(1*pi/128) */
    2.45412285229122881236030195850617019459605216979980e-02, /* sh */ 
    9.99698818696204249967252053465927019715309143066406e-01, /* ch */ 
    -9.18684901257787817511092729052523410277440947511204e-20, /* sm */ 
    -2.98514864037997529143865109884349378101639351597209e-17, /* cm */ 
    4.87061487044670605326897942323184237088370497395221e-36, /* sl */ 
    -1.90847873707337374441321797545527262287132421960372e-33, /* cl */ 
  } , 
  { /* sin/cos(2*pi/128) */
    4.90676743274180149345653489945107139647006988525391e-02, /* sh */ 
    9.98795456205172405006464941834565252065658569335938e-01, /* ch */ 
    -6.79610372051828011331087211108459897310458406639606e-19, /* sm */ 
    -1.22916933370754648023069228195440464413706083235769e-17, /* cm */ 
    -4.43188681247183252512131377148380367335867976105441e-35, /* sl */ 
    2.44684467864912710011822340186994056439724387642614e-34, /* cl */ 
  } , 
  { /* sin/cos(3*pi/128) */
    7.35645635996674263079597722025937400758266448974609e-02, /* sh */ 
    9.97290456678690206970827603072393685579299926757812e-01, /* ch */ 
    -2.77849415062735932702215188936675076042592110809248e-18, /* sm */ 
    9.16476953711017345735104565501545052170255011497269e-18, /* cm */ 
    -9.12403754898528209738897073370755128458265201364941e-35, /* sl */ 
    6.78241343097392959213418956364511469074601099596281e-34, /* cl */ 
  } , 
  { /* sin/cos(4*pi/128) */
    9.80171403295606036287779261328978464007377624511719e-02, /* sh */ 
    9.95184726672196928731750631413888186216354370117188e-01, /* ch */ 
    -1.63458236224425598733036227927721717477694202336940e-18, /* sm */ 
    -4.24869136783044095961919567518488446851237034975878e-17, /* cm */ 
    -1.32092388100064537760551925056417985745657226089355e-35, /* sl */ 
    1.33155107725046144631896989941148168106742079450765e-33, /* cl */ 
  } , 
  { /* sin/cos(5*pi/128) */
    1.22410675199216195663254325154412072151899337768555e-01, /* sh */ 
    9.92479534598709967063712156232213601469993591308594e-01, /* ch */ 
    2.83545014899653353390676675638351012269446701684827e-18, /* sm */ 
    3.10930550954289060565003028451274795448754407491652e-17, /* cm */ 
    1.81516557514933045310042069477077268403843802536068e-34, /* sl */ 
    -1.83795947578180190975980887553298238967275792441039e-33, /* cl */ 
  } , 
  { /* sin/cos(6*pi/128) */
    1.46730474455361747931902982600149698555469512939453e-01, /* sh */ 
    9.89176509964781014438983675063354894518852233886719e-01, /* ch */ 
    3.72694714704656774762676429108167171813186218775477e-18, /* sm */ 
    -4.09873099370471113819595571800653989851994072636781e-17, /* cm */ 
    3.73523981512508271311947760640000952122222968339672e-34, /* sl */ 
    -4.48575605520484372949276939500710783945639583248830e-34, /* cl */ 
  } , 
  { /* sin/cos(7*pi/128) */
    1.70961888760301217171644339032354764640331268310547e-01, /* sh */ 
    9.85277642388941221618381405278341844677925109863281e-01, /* ch */ 
    9.19199801817590944421343720066011137609803605455754e-18, /* sm */ 
    2.31556370279002066952419195035978530309724519300942e-17, /* cm */ 
    -6.76887439409826056872126962280395760312157075744208e-34, /* sl */ 
    -7.52759715457648329988759858960284250572199307609030e-34, /* cl */ 
  } , 
  { /* sin/cos(8*pi/128) */
    1.95090322016128275839363936938752885907888412475586e-01, /* sh */ 
    9.80785280403230430579242238309234380722045898437500e-01, /* ch */ 
    -7.99107906846173126344289703693072234842489650708062e-18, /* sm */ 
    1.85469399978250057259083323855314298012062932205111e-17, /* cm */ 
    6.18462700242207127058950316629513247512028088300259e-34, /* sl */ 
    -1.06965644455307566037437785239692763829708493768038e-33, /* cl */ 
  } , 
  { /* sin/cos(9*pi/128) */
    2.19101240156869797592875670488865580409765243530273e-01, /* sh */ 
    9.75702130038528570032951847679214552044868469238281e-01, /* ch */ 
    -3.65138122991507758201905028218239594431466287621283e-19, /* sm */ 
    -2.55725560812596856486584111140239960382614753072513e-17, /* cm */ 
    -2.33594994186064420524188910640554529764134815908088e-35, /* sl */ 
    -9.31742445089422233678739018667912651409612658394109e-34, /* cl */ 
  } , 
  { /* sin/cos(10*pi/128) */
    2.42980179903263898699705691797134932130575180053711e-01, /* sh */ 
    9.70031253194543974238683858857257291674613952636719e-01, /* ch */ 
    -8.75143152971966315657698066597556045463081095367626e-18, /* sm */ 
    1.83653003484288443908920092041031891826103053310748e-17, /* cm */ 
    -6.57232603730794308023668785032351777033485854907112e-34, /* sl */ 
    -1.43110975719449184241630500775446481526298855330310e-33, /* cl */ 
  } , 
  { /* sin/cos(11*pi/128) */
    2.66712757474898365384063936289749108254909515380859e-01, /* sh */ 
    9.63776065795439840222513794287806376814842224121094e-01, /* ch */ 
    2.09412225788266884161338599457742136857657480229159e-17, /* sm */ 
    2.64639505612200287797555650837254713865234329571181e-17, /* cm */ 
    -1.13034665247279893680679089609736970876966889026874e-33, /* sl */ 
    -2.90732345901993230283123062176090186865215463253595e-36, /* cl */ 
  } , 
  { /* sin/cos(12*pi/128) */
    2.90284677254462386564171083591645583510398864746094e-01, /* sh */ 
    9.56940335732208824381928025104571133852005004882812e-01, /* ch */ 
    -1.89279787077742514611142383006534872375212090104104e-17, /* sm */ 
    4.05538698618757005503321806309621067670667256244675e-17, /* cm */ 
    1.15229531571423146986028622140694357073680581126202e-33, /* sl */ 
    -1.71470133643021490774251081375403695480671459421111e-33, /* cl */ 
  } , 
  { /* sin/cos(13*pi/128) */
    3.13681740398891462096031546025187708437442779541016e-01, /* sh */ 
    9.49528180593036674750351266993675380945205688476562e-01, /* ch */ 
    1.45604472999689122359140657497995731581857682115574e-17, /* sm */ 
    -7.55441519280432984009053129417731398148166729726062e-18, /* cm */ 
    3.65641868980115946347742781527870762816609669157526e-34, /* sl */ 
    -5.12602450240466855759717750777748877302823219800281e-34, /* cl */ 
  } , 
  { /* sin/cos(14*pi/128) */
    3.36889853392220051109262612953898496925830841064453e-01, /* sh */ 
    9.41544065183020806308888950297841802239418029785156e-01, /* ch */ 
    -4.20009400334750923530198764394686942499166950042589e-19, /* sm */ 
    -2.78963795476983410723774639073498160082587681962273e-17, /* cm */ 
    -2.91786529699854378247553773743757458316226497390670e-36, /* sl */ 
    1.62732363567338984793340006492231780038121787494388e-33, /* cl */ 
  } , 
  { /* sin/cos(15*pi/128) */
    3.59895036534988166376791696166037581861019134521484e-01, /* sh */ 
    9.32992798834738845670244700158946216106414794921875e-01, /* ch */ 
    -1.76016871238392824991712490180716397399893409400325e-17, /* sm */ 
    4.20414155553843553793296357703776047390203635491842e-17, /* cm */ 
    1.33751254730467910174693675743357144631063005169968e-33, /* sl */ 
    9.02858964955212762289886973560835699430495731315468e-34, /* cl */ 
  } , 
  { /* sin/cos(16*pi/128) */
    3.82683432365089781779232680491986684501171112060547e-01, /* sh */ 
    9.23879532511286738483136105060111731290817260742188e-01, /* ch */ 
    -1.00507726964615876116866635215079604149716565502162e-17, /* sm */ 
    1.76450470843366770599569725809896737820548554530071e-17, /* cm */ 
    -2.06053163028066946700869844728951806226449919556645e-34, /* sl */ 
    -5.04425373215868178317262040897837818667759555267340e-34, /* cl */ 
  } , 
  { /* sin/cos(17*pi/128) */
    4.05241314004989860997341111215064302086830139160156e-01, /* sh */ 
    9.14209755703530690951197357208002358675003051757812e-01, /* ch */ 
    9.91114019428998841611582656929141002790524150916273e-18, /* sm */ 
    -3.63161825278144230137483342238202646129279797999369e-17, /* cm */ 
    -2.51690708954346477356872397338259880052208425689270e-34, /* sl */ 
    -1.94388197771225539922639474168732176327545733871664e-33, /* cl */ 
  } , 
  { /* sin/cos(18*pi/128) */
    4.27555093430282084909777040593326091766357421875000e-01, /* sh */ 
    9.03989293123443338195954765978967770934104919433594e-01, /* ch */ 
    9.41118981629547261700504547345546652274077429814600e-18, /* sm */ 
    -6.60975446874843084950410324118654757730786778092578e-18, /* cm */ 
    -1.74466824265988005677926664445477172311534261793862e-34, /* sl */ 
    1.27280130346803566179582264758403917100160817972220e-34, /* cl */ 
  } , 
  { /* sin/cos(19*pi/128) */
    4.49611329654606595163102156220702454447746276855469e-01, /* sh */ 
    8.93224301195515324458540362684288993477821350097656e-01, /* ch */ 
    4.88319242320352434992459578960859391755338197539985e-18, /* sm */ 
    -4.11612391519089126927973381825877743981647578251702e-18, /* cm */ 
    2.71510844981913810248805367518978860016097711671055e-34, /* sl */ 
    2.53802538057159989694478858192415647688294380587576e-34, /* cl */ 
  } , 
  { /* sin/cos(20*pi/128) */
    4.71396736825997642039709489836241118609905242919922e-01, /* sh */ 
    8.81921264348355049556005269550951197743415832519531e-01, /* ch */ 
    6.51667813606901296447208541365272563671678644989260e-18, /* sm */ 
    -1.98432484058905621441138331351064557464910578392153e-17, /* cm */ 
    2.94575469662359839325656601464778797771834866677748e-34, /* sl */ 
    -7.04121140076738336886106234154968299762349001311189e-34, /* cl */ 
  } , 
  { /* sin/cos(21*pi/128) */
    4.92898192229784037898809856415027752518653869628906e-01, /* sh */ 
    8.70086991108711460540803273033816367387771606445312e-01, /* ch */ 
    -1.02578316765621855379978432396560880807423053235781e-18, /* sm */ 
    -4.18885108685499682324788024356996724212552957633711e-17, /* cm */ 
    6.95208177608850685652817838158830003461259862153976e-35, /* sl */ 
    7.09001858618784147808113574428963243591875515454078e-34, /* cl */ 
  } , 
  { /* sin/cos(22*pi/128) */
    5.14102744193221772306401362584438174962997436523438e-01, /* sh */ 
    8.57728610000272118085717920621391385793685913085938e-01, /* ch */ 
    -4.57127075236156239511828925399355339402327136821488e-17, /* sm */ 
    -4.81834479363366201443381433448989495956683085629586e-17, /* cm */ 
    1.54882794422382834009847995565726593342335634635644e-33, /* sl */ 
    -1.10441305176875333754243497414965343357566732409805e-33, /* cl */ 
  } , 
  { /* sin/cos(23*pi/128) */
    5.34997619887097264346209612995153293013572692871094e-01, /* sh */ 
    8.44853565249707116890931501984596252441406250000000e-01, /* ch */ 
    -5.36831327083581339873963151168879848386957514422019e-17, /* sm */ 
    -4.36313602968796371239489349318562331730725440347672e-17, /* cm */ 
    -1.39005699188381123579693330118086965951478315829762e-33, /* sl */ 
    -2.03077268533675470129749465480265274351493013855507e-33, /* cl */ 
  } , 
  { /* sin/cos(24*pi/128) */
    5.55570233019602177648721408331766724586486816406250e-01, /* sh */ 
    8.31469612302545235671402679145103320479393005371094e-01, /* ch */ 
    4.70941094056167682138404887426404929202505139640422e-17, /* sm */ 
    1.40738569847280238930785242263532116993349751072869e-18, /* cm */ 
    -2.06405203836829206177595824610721979274646969038677e-33, /* sl */ 
    4.69513153839808352458514422733246165217408979962725e-35, /* cl */ 
  } , 
  { /* sin/cos(25*pi/128) */
    5.75808191417845338655467912758467718958854675292969e-01, /* sh */ 
    8.17584813151583711388070696557406336069107055664062e-01, /* ch */ 
    -3.79094954589427341338090415345480342563618583176174e-17, /* sm */ 
    -1.48831498124267717438654368251080189181059728497540e-17, /* cm */ 
    -2.74337380468543094919985039492410424892033458032374e-33, /* sl */ 
    -7.82732627712989170819884242480669228359664723248350e-34, /* cl */ 
  } , 
  { /* sin/cos(26*pi/128) */
    5.95699304492433356905678465409437194466590881347656e-01, /* sh */ 
    8.03207531480644942867286317778052762150764465332031e-01, /* ch */ 
    -1.34386419365794672370769766351890963879615472923649e-17, /* sm */ 
    -3.30606098048149096139985697961182567790418192774440e-17, /* cm */ 
    -6.78776879077210601615057451734157494786909383904135e-35, /* sl */ 
    -1.22427262524204334204965494469832525240861319271513e-33, /* cl */ 
  } , 
  { /* sin/cos(27*pi/128) */
    6.15231590580626819253495796147035434842109680175781e-01, /* sh */ 
    7.88346427626606227612171551299979910254478454589844e-01, /* ch */ 
    2.62314177672669502523539824382601959772978459707084e-17, /* sm */ 
    3.43969931540597076013396400088425960673639156185612e-17, /* cm */ 
    -1.40953666211067162505853387634546257268806948654638e-33, /* sl */ 
    1.77106237467371703799173999194548788681155596718637e-33, /* cl */ 
  } , 
  { /* sin/cos(28*pi/128) */
    6.34393284163645487794269683945458382368087768554688e-01, /* sh */ 
    7.73010453362736993376813643408240750432014465332031e-01, /* ch */ 
    1.04209019292800345765620100334821189439770902041504e-17, /* sm */ 
    -3.25659070336497723355416983248241127086331816976265e-17, /* cm */ 
    4.11745589292804916608872033177616781045056039843844e-34, /* sl */ 
    1.38608072515239293103931950218033658496575955944579e-33, /* cl */ 
  } , 
  { /* sin/cos(29*pi/128) */
    6.53172842953776755514638807653682306408882141113281e-01, /* sh */ 
    7.57208846506484567484562830941285938024520874023438e-01, /* ch */ 
    8.56956420600262380032120093330718187007118037955581e-18, /* sm */ 
    -1.99090987773355018590769198198766615206267472536943e-17, /* cm */ 
    -6.91653223050706326446309100906668805486226797380063e-34, /* sl */ 
    3.94092832661584820126428051219691386352890448827143e-34, /* cl */ 
  } , 
  { /* sin/cos(30*pi/128) */
    6.71558954847018441114414599724113941192626953125000e-01, /* sh */ 
    7.40951125354959105884233849792508408427238464355469e-01, /* ch */ 
    -4.04890377492966924579222325744820057841320210868276e-17, /* sm */ 
    -1.47086169522973451831939448836260932254009548735474e-17, /* cm */ 
    3.19958356253556814327429889830897695603712398130540e-34, /* sl */ 
    -4.95504338271420316912995166818275952337135785088300e-34, /* cl */ 
  } , 
  { /* sin/cos(31*pi/128) */
    6.89540544737066940506053924764273688197135925292969e-01, /* sh */ 
    7.24247082951466891742597908887546509504318237304688e-01, /* ch */ 
    -1.58893232948067898977751614830710021398692474578962e-17, /* sm */ 
    2.91984713344030043552462778935493159883806968705675e-17, /* cm */ 
    9.12423562402057118300276915582756301317547938020558e-34, /* sl */ 
    2.30273249687394643468466642789742491277527364150754e-33, /* cl */ 
  } , 
  { /* sin/cos(32*pi/128) */
    7.07106781186547572737310929369414225220680236816406e-01, /* sh */ 
    7.07106781186547572737310929369414225220680236816406e-01, /* ch */ 
    -4.83364665672645672552734986488347382506490835271488e-17, /* sm */ 
    -4.83364665672645672552734986488347382506490835271488e-17, /* cm */ 
    2.06933765434970678135950246605438944725492854770064e-33, /* sl */ 
    2.06933765434970678135950246605438944725492854770064e-33, /* cl */ 
  } , 
  { /* sin/cos(33*pi/128) */
    7.24247082951466891742597908887546509504318237304688e-01, /* sh */ 
    6.89540544737066940506053924764273688197135925292969e-01, /* ch */ 
    2.91984713344030043552462778935493159883806968705675e-17, /* sm */ 
    -1.58893232948067898977751614830710021398692474578962e-17, /* cm */ 
    2.30273249687394643468466642789742491277527364150754e-33, /* sl */ 
    9.12423562402057118300276915582756301317547938020558e-34, /* cl */ 
  } , 
  { /* sin/cos(34*pi/128) */
    7.40951125354959105884233849792508408427238464355469e-01, /* sh */ 
    6.71558954847018441114414599724113941192626953125000e-01, /* ch */ 
    -1.47086169522973451831939448836260932254009548735474e-17, /* sm */ 
    -4.04890377492966924579222325744820057841320210868276e-17, /* cm */ 
    -4.95504338271420316912995166818275952337135785088300e-34, /* sl */ 
    3.19958356253556814327429889830897695603712398130540e-34, /* cl */ 
  } , 
  { /* sin/cos(35*pi/128) */
    7.57208846506484567484562830941285938024520874023438e-01, /* sh */ 
    6.53172842953776755514638807653682306408882141113281e-01, /* ch */ 
    -1.99090987773355018590769198198766615206267472536943e-17, /* sm */ 
    8.56956420600262380032120093330718187007118037955581e-18, /* cm */ 
    3.94092832661584820126428051219691386352890448827143e-34, /* sl */ 
    -6.91653223050706326446309100906668805486226797380063e-34, /* cl */ 
  } , 
  { /* sin/cos(36*pi/128) */
    7.73010453362736993376813643408240750432014465332031e-01, /* sh */ 
    6.34393284163645487794269683945458382368087768554688e-01, /* ch */ 
    -3.25659070336497723355416983248241127086331816976265e-17, /* sm */ 
    1.04209019292800345765620100334821189439770902041504e-17, /* cm */ 
    1.38608072515239293103931950218033658496575955944579e-33, /* sl */ 
    4.11745589292804916608872033177616781045056039843844e-34, /* cl */ 
  } , 
  { /* sin/cos(37*pi/128) */
    7.88346427626606227612171551299979910254478454589844e-01, /* sh */ 
    6.15231590580626819253495796147035434842109680175781e-01, /* ch */ 
    3.43969931540597076013396400088425960673639156185612e-17, /* sm */ 
    2.62314177672669502523539824382601959772978459707084e-17, /* cm */ 
    1.77106237467371703799173999194548788681155596718637e-33, /* sl */ 
    -1.40953666211067162505853387634546257268806948654638e-33, /* cl */ 
  } , 
  { /* sin/cos(38*pi/128) */
    8.03207531480644942867286317778052762150764465332031e-01, /* sh */ 
    5.95699304492433356905678465409437194466590881347656e-01, /* ch */ 
    -3.30606098048149096139985697961182567790418192774440e-17, /* sm */ 
    -1.34386419365794672370769766351890963879615472923649e-17, /* cm */ 
    -1.22427262524204334204965494469832525240861319271513e-33, /* sl */ 
    -6.78776879077210601615057451734157494786909383904135e-35, /* cl */ 
  } , 
  { /* sin/cos(39*pi/128) */
    8.17584813151583711388070696557406336069107055664062e-01, /* sh */ 
    5.75808191417845338655467912758467718958854675292969e-01, /* ch */ 
    -1.48831498124267717438654368251080189181059728497540e-17, /* sm */ 
    -3.79094954589427341338090415345480342563618583176174e-17, /* cm */ 
    -7.82732627712989170819884242480669228359664723248350e-34, /* sl */ 
    -2.74337380468543094919985039492410424892033458032374e-33, /* cl */ 
  } , 
  { /* sin/cos(40*pi/128) */
    8.31469612302545235671402679145103320479393005371094e-01, /* sh */ 
    5.55570233019602177648721408331766724586486816406250e-01, /* ch */ 
    1.40738569847280238930785242263532116993349751072869e-18, /* sm */ 
    4.70941094056167682138404887426404929202505139640422e-17, /* cm */ 
    4.69513153839808352458514422733246165217408979962725e-35, /* sl */ 
    -2.06405203836829206177595824610721979274646969038677e-33, /* cl */ 
  } , 
  { /* sin/cos(41*pi/128) */
    8.44853565249707116890931501984596252441406250000000e-01, /* sh */ 
    5.34997619887097264346209612995153293013572692871094e-01, /* ch */ 
    -4.36313602968796371239489349318562331730725440347672e-17, /* sm */ 
    -5.36831327083581339873963151168879848386957514422019e-17, /* cm */ 
    -2.03077268533675470129749465480265274351493013855507e-33, /* sl */ 
    -1.39005699188381123579693330118086965951478315829762e-33, /* cl */ 
  } , 
  { /* sin/cos(42*pi/128) */
    8.57728610000272118085717920621391385793685913085938e-01, /* sh */ 
    5.14102744193221772306401362584438174962997436523438e-01, /* ch */ 
    -4.81834479363366201443381433448989495956683085629586e-17, /* sm */ 
    -4.57127075236156239511828925399355339402327136821488e-17, /* cm */ 
    -1.10441305176875333754243497414965343357566732409805e-33, /* sl */ 
    1.54882794422382834009847995565726593342335634635644e-33, /* cl */ 
  } , 
  { /* sin/cos(43*pi/128) */
    8.70086991108711460540803273033816367387771606445312e-01, /* sh */ 
    4.92898192229784037898809856415027752518653869628906e-01, /* ch */ 
    -4.18885108685499682324788024356996724212552957633711e-17, /* sm */ 
    -1.02578316765621855379978432396560880807423053235781e-18, /* cm */ 
    7.09001858618784147808113574428963243591875515454078e-34, /* sl */ 
    6.95208177608850685652817838158830003461259862153976e-35, /* cl */ 
  } , 
  { /* sin/cos(44*pi/128) */
    8.81921264348355049556005269550951197743415832519531e-01, /* sh */ 
    4.71396736825997642039709489836241118609905242919922e-01, /* ch */ 
    -1.98432484058905621441138331351064557464910578392153e-17, /* sm */ 
    6.51667813606901296447208541365272563671678644989260e-18, /* cm */ 
    -7.04121140076738336886106234154968299762349001311189e-34, /* sl */ 
    2.94575469662359839325656601464778797771834866677748e-34, /* cl */ 
  } , 
  { /* sin/cos(45*pi/128) */
    8.93224301195515324458540362684288993477821350097656e-01, /* sh */ 
    4.49611329654606595163102156220702454447746276855469e-01, /* ch */ 
    -4.11612391519089126927973381825877743981647578251702e-18, /* sm */ 
    4.88319242320352434992459578960859391755338197539985e-18, /* cm */ 
    2.53802538057159989694478858192415647688294380587576e-34, /* sl */ 
    2.71510844981913810248805367518978860016097711671055e-34, /* cl */ 
  } , 
  { /* sin/cos(46*pi/128) */
    9.03989293123443338195954765978967770934104919433594e-01, /* sh */ 
    4.27555093430282084909777040593326091766357421875000e-01, /* ch */ 
    -6.60975446874843084950410324118654757730786778092578e-18, /* sm */ 
    9.41118981629547261700504547345546652274077429814600e-18, /* cm */ 
    1.27280130346803566179582264758403917100160817972220e-34, /* sl */ 
    -1.74466824265988005677926664445477172311534261793862e-34, /* cl */ 
  } , 
  { /* sin/cos(47*pi/128) */
    9.14209755703530690951197357208002358675003051757812e-01, /* sh */ 
    4.05241314004989860997341111215064302086830139160156e-01, /* ch */ 
    -3.63161825278144230137483342238202646129279797999369e-17, /* sm */ 
    9.91114019428998841611582656929141002790524150916273e-18, /* cm */ 
    -1.94388197771225539922639474168732176327545733871664e-33, /* sl */ 
    -2.51690708954346477356872397338259880052208425689270e-34, /* cl */ 
  } , 
  { /* sin/cos(48*pi/128) */
    9.23879532511286738483136105060111731290817260742188e-01, /* sh */ 
    3.82683432365089781779232680491986684501171112060547e-01, /* ch */ 
    1.76450470843366770599569725809896737820548554530071e-17, /* sm */ 
    -1.00507726964615876116866635215079604149716565502162e-17, /* cm */ 
    -5.04425373215868178317262040897837818667759555267340e-34, /* sl */ 
    -2.06053163028066946700869844728951806226449919556645e-34, /* cl */ 
  } , 
  { /* sin/cos(49*pi/128) */
    9.32992798834738845670244700158946216106414794921875e-01, /* sh */ 
    3.59895036534988166376791696166037581861019134521484e-01, /* ch */ 
    4.20414155553843553793296357703776047390203635491842e-17, /* sm */ 
    -1.76016871238392824991712490180716397399893409400325e-17, /* cm */ 
    9.02858964955212762289886973560835699430495731315468e-34, /* sl */ 
    1.33751254730467910174693675743357144631063005169968e-33, /* cl */ 
  } , 
  { /* sin/cos(50*pi/128) */
    9.41544065183020806308888950297841802239418029785156e-01, /* sh */ 
    3.36889853392220051109262612953898496925830841064453e-01, /* ch */ 
    -2.78963795476983410723774639073498160082587681962273e-17, /* sm */ 
    -4.20009400334750923530198764394686942499166950042589e-19, /* cm */ 
    1.62732363567338984793340006492231780038121787494388e-33, /* sl */ 
    -2.91786529699854378247553773743757458316226497390670e-36, /* cl */ 
  } , 
  { /* sin/cos(51*pi/128) */
    9.49528180593036674750351266993675380945205688476562e-01, /* sh */ 
    3.13681740398891462096031546025187708437442779541016e-01, /* ch */ 
    -7.55441519280432984009053129417731398148166729726062e-18, /* sm */ 
    1.45604472999689122359140657497995731581857682115574e-17, /* cm */ 
    -5.12602450240466855759717750777748877302823219800281e-34, /* sl */ 
    3.65641868980115946347742781527870762816609669157526e-34, /* cl */ 
  } , 
  { /* sin/cos(52*pi/128) */
    9.56940335732208824381928025104571133852005004882812e-01, /* sh */ 
    2.90284677254462386564171083591645583510398864746094e-01, /* ch */ 
    4.05538698618757005503321806309621067670667256244675e-17, /* sm */ 
    -1.89279787077742514611142383006534872375212090104104e-17, /* cm */ 
    -1.71470133643021490774251081375403695480671459421111e-33, /* sl */ 
    1.15229531571423146986028622140694357073680581126202e-33, /* cl */ 
  } , 
  { /* sin/cos(53*pi/128) */
    9.63776065795439840222513794287806376814842224121094e-01, /* sh */ 
    2.66712757474898365384063936289749108254909515380859e-01, /* ch */ 
    2.64639505612200287797555650837254713865234329571181e-17, /* sm */ 
    2.09412225788266884161338599457742136857657480229159e-17, /* cm */ 
    -2.90732345901993230283123062176090186865215463253595e-36, /* sl */ 
    -1.13034665247279893680679089609736970876966889026874e-33, /* cl */ 
  } , 
  { /* sin/cos(54*pi/128) */
    9.70031253194543974238683858857257291674613952636719e-01, /* sh */ 
    2.42980179903263898699705691797134932130575180053711e-01, /* ch */ 
    1.83653003484288443908920092041031891826103053310748e-17, /* sm */ 
    -8.75143152971966315657698066597556045463081095367626e-18, /* cm */ 
    -1.43110975719449184241630500775446481526298855330310e-33, /* sl */ 
    -6.57232603730794308023668785032351777033485854907112e-34, /* cl */ 
  } , 
  { /* sin/cos(55*pi/128) */
    9.75702130038528570032951847679214552044868469238281e-01, /* sh */ 
    2.19101240156869797592875670488865580409765243530273e-01, /* ch */ 
    -2.55725560812596856486584111140239960382614753072513e-17, /* sm */ 
    -3.65138122991507758201905028218239594431466287621283e-19, /* cm */ 
    -9.31742445089422233678739018667912651409612658394109e-34, /* sl */ 
    -2.33594994186064420524188910640554529764134815908088e-35, /* cl */ 
  } , 
  { /* sin/cos(56*pi/128) */
    9.80785280403230430579242238309234380722045898437500e-01, /* sh */ 
    1.95090322016128275839363936938752885907888412475586e-01, /* ch */ 
    1.85469399978250057259083323855314298012062932205111e-17, /* sm */ 
    -7.99107906846173126344289703693072234842489650708062e-18, /* cm */ 
    -1.06965644455307566037437785239692763829708493768038e-33, /* sl */ 
    6.18462700242207127058950316629513247512028088300259e-34, /* cl */ 
  } , 
  { /* sin/cos(57*pi/128) */
    9.85277642388941221618381405278341844677925109863281e-01, /* sh */ 
    1.70961888760301217171644339032354764640331268310547e-01, /* ch */ 
    2.31556370279002066952419195035978530309724519300942e-17, /* sm */ 
    9.19199801817590944421343720066011137609803605455754e-18, /* cm */ 
    -7.52759715457648329988759858960284250572199307609030e-34, /* sl */ 
    -6.76887439409826056872126962280395760312157075744208e-34, /* cl */ 
  } , 
  { /* sin/cos(58*pi/128) */
    9.89176509964781014438983675063354894518852233886719e-01, /* sh */ 
    1.46730474455361747931902982600149698555469512939453e-01, /* ch */ 
    -4.09873099370471113819595571800653989851994072636781e-17, /* sm */ 
    3.72694714704656774762676429108167171813186218775477e-18, /* cm */ 
    -4.48575605520484372949276939500710783945639583248830e-34, /* sl */ 
    3.73523981512508271311947760640000952122222968339672e-34, /* cl */ 
  } , 
  { /* sin/cos(59*pi/128) */
    9.92479534598709967063712156232213601469993591308594e-01, /* sh */ 
    1.22410675199216195663254325154412072151899337768555e-01, /* ch */ 
    3.10930550954289060565003028451274795448754407491652e-17, /* sm */ 
    2.83545014899653353390676675638351012269446701684827e-18, /* cm */ 
    -1.83795947578180190975980887553298238967275792441039e-33, /* sl */ 
    1.81516557514933045310042069477077268403843802536068e-34, /* cl */ 
  } , 
  { /* sin/cos(60*pi/128) */
    9.95184726672196928731750631413888186216354370117188e-01, /* sh */ 
    9.80171403295606036287779261328978464007377624511719e-02, /* ch */ 
    -4.24869136783044095961919567518488446851237034975878e-17, /* sm */ 
    -1.63458236224425598733036227927721717477694202336940e-18, /* cm */ 
    1.33155107725046144631896989941148168106742079450765e-33, /* sl */ 
    -1.32092388100064537760551925056417985745657226089355e-35, /* cl */ 
  } , 
  { /* sin/cos(61*pi/128) */
    9.97290456678690206970827603072393685579299926757812e-01, /* sh */ 
    7.35645635996674263079597722025937400758266448974609e-02, /* ch */ 
    9.16476953711017345735104565501545052170255011497269e-18, /* sm */ 
    -2.77849415062735932702215188936675076042592110809248e-18, /* cm */ 
    6.78241343097392959213418956364511469074601099596281e-34, /* sl */ 
    -9.12403754898528209738897073370755128458265201364941e-35, /* cl */ 
  } , 
  { /* sin/cos(62*pi/128) */
    9.98795456205172405006464941834565252065658569335938e-01, /* sh */ 
    4.90676743274180149345653489945107139647006988525391e-02, /* ch */ 
    -1.22916933370754648023069228195440464413706083235769e-17, /* sm */ 
    -6.79610372051828011331087211108459897310458406639606e-19, /* cm */ 
    2.44684467864912710011822340186994056439724387642614e-34, /* sl */ 
    -4.43188681247183252512131377148380367335867976105441e-35, /* cl */ 
  } , 
  { /* sin/cos(63*pi/128) */
    9.99698818696204249967252053465927019715309143066406e-01, /* sh */ 
    2.45412285229122881236030195850617019459605216979980e-02, /* ch */ 
    -2.98514864037997529143865109884349378101639351597209e-17, /* sm */ 
    -9.18684901257787817511092729052523410277440947511204e-20, /* cm */ 
    -1.90847873707337374441321797545527262287132421960372e-33, /* sl */ 
    4.87061487044670605326897942323184237088370497395221e-36, /* cl */ 
  } , 
}; 
 