/*File generated by maple/log-de.mpl*/

#if defined(CRLIBM_TYPECPU_X86) || defined(CRLIBM_TYPECPU_AMD64)

  /* Coefficients are read directly from the array thanks to the following macros */ 
#define c7  c[0]
#define c6  c[1]
#define c5  c[2]
#define c4  c[3]
#define c3  c[4]
#define c2  c[5]
#define c1  c[6]
#define c14h  ch[0]
#define c13h  ch[1]
#define c12h  ch[2]
#define c11h  ch[3]
#define c10h  ch[4]
#define c9h  ch[5]
#define c8h  ch[6]
#define c7h  ch[7]
#define c6h  ch[8]
#define c5h  ch[9]
#define c4h  ch[10]
#define c3h  ch[11]
#define c2h  ch[12]
#define c1h  ch[13]
#define c7l  cl[0]
#define c6l  cl[1]
#define c5l  cl[2]
#define c4l  cl[3]
#define c3l  cl[4]
#define c2l  cl[5]
#define c1l  cl[6]
#define PREFETCH_POLY_ACCURATE 

#else /* not(defined(CRLIBM_TYPECPU_X86) || defined(CRLIBM_TYPECPU_AMD64)),
   assuming Itanium, otherwise we shouldn't be there */ 

#define PREFETCH_POLY_QUICK c7=c[0]; c6=c[1]; c5=c[2]; c4=c[3]; c3=c[4]; c2=c[5]; c1=c[6]; 
#define PREFETCH_POLY_ACCURATE c14h=ch[0]; c13h=ch[1]; c12h=ch[2]; \
        c11h=ch[3]; c10h=ch[4]; c9h=ch[5]; c8h=ch[6]; \
        c7h=ch[7]; c6h=ch[8]; c5h=ch[9]; c4h=ch[10]; \
        c3h=ch[11]; c2h=ch[12]; c1h=ch[13]; \
        c7l=cl[0]; c6l=cl[1]; c5l=cl[2]; c4l=cl[3]; c3l=cl[4]; c2l=cl[5]; c1l=cl[6]; 
#endif /* defined(CRLIBM_TYPECPU_X86) || defined(CRLIBM_TYPECPU_AMD64) */ 

#define L        7
#define MAXINDEX 53
static const long double log2h  = 6.93147180559945309428690474184975300886435434222221e-01L ;
static const long double log2l  = -1.14583527267987328109462081210062935494878745868567e-20L ;
static const long double two64 = 1.84467440737095516160000000000000000000000000000000e+19L ;
static const long double c[7] =  {
   /* c7  = */ 1.42861698277889060656803063564801448137586703523993e-01L, 
   /* c6  = */ -1.66670652659638858037057483618692543814177042804658e-01L, 
   /* c5  = */ 1.99999999940051108502877576234002532373779104091227e-01L, 
   /* c4  = */ -2.49999999963684705383605046125072846052717068232596e-01L, 
   /* c3  = */ 3.33333333333333595909029473114415509371610824018717e-01L, 
   /* c2  = */ -5.00000000000000082724625760643988314768648706376553e-01L, 
   /* c1  = */ 1.00000000000000000000000000000000000000000000000000e+00L, 
}; 
 
static const long double ch[14] =  {
   /* ch14  = */ -7.14331270132809296899379855605438649490679381415248e-02L, 
   /* ch13  = */ 7.69273287153940887750521414323312541228006011806428e-02L, 
   /* ch12  = */ -8.33333331997373241887910010061712995366178802214563e-02L, 
   /* ch11  = */ 9.09090908025638293944877509067392651331829256378114e-02L, 
   /* ch10  = */ -1.00000000000002008926336914684807055664350627921522e-01L, 
   /* ch9  = */ 1.11111111111112434574868437081596184157206153031439e-01L, 
   /* ch8  = */ -1.24999999999999999986447472843931194574906839989126e-01L, 
   /* ch7  = */ 1.42857142857142857140921067549133027796415262855589e-01L, 
   /* ch6  = */ -1.66666666666666666671184175718689601808364386670291e-01L, 
   /* ch5  = */ 2.00000000000000000002710505431213761085018632002175e-01L, 
   /* ch4  = */ -2.50000000000000000000000000000000000000000000000000e-01L, 
   /* ch3  = */ 3.33333333333333333342368351437379203616728773340583e-01L, 
   /* ch2  = */ -5.00000000000000000000000000000000000000000000000000e-01L, 
   /* ch1  = */ 1.00000000000000000000000000000000000000000000000000e+00L, 
}; 
 
static const long double cl[8] =  {
   /* cl7  = */ -6.50428946582602220613209650197130542143736318909421e-21L, 
   /* cl6  = */ 4.51744038887116027997643633388355722501892099762755e-21L, 
   /* cl5  = */ -2.71047979869680458515780941073080594825886352049465e-21L, 
   /* cl4  = */ 1.29024122830165671392403992249375050348201824530415e-31L, 
   /* cl3  = */ -9.03501810407506150530098539858790044927063511939753e-21L, 
   /* cl2  = */ -7.12424416033468026204120835128636918005390059458504e-38L, 
   /* cl1  = */ 5.42758985113557151046804223905139106366884703472162e-39L, 
}; 
 
typedef struct rri_tag {long double logirh; float r; long double logirl; } rri ;  
static const rri argredtable[129] = {
  { 
    0.00000000000000000000000000000000000000000000000000e-01L, /* logirh[0] */ 
    1.00000000000000000000000000000000000000000000000000e+00L,   /* r[0] */ 
    0.00000000000000000000000000000000000000000000000000e-01L, /* logirl[0] */ 
  } , 
  { 
    7.84317746102589287284596788335511163836599735077471e-03L, /* logirh[1] */ 
    9.92187500000000000000000000000000000000000000000000e-01L,   /* r[1] */ 
    3.38074607588470016237165513745732472460993853200422e-22L, /* logirl[1] */ 
  } , 
  { 
    1.57483569681391686082786579570225171664787922054529e-02L, /* logirh[2] */ 
    9.84375000000000000000000000000000000000000000000000e-01L,   /* r[2] */ 
    -7.29146496194247645559133241782926476205899642506092e-22L, /* logirl[2] */ 
  } , 
  { 
    2.27170262842325089513268680102564545109089522156864e-02L, /* logirh[3] */ 
    9.77539062500000000000000000000000000000000000000000e-01L,   /* r[3] */ 
    2.10583597881591980030306753885126639087470299838646e-22L, /* logirl[3] */ 
  } , 
  { 
    3.07411415542805019917064427575903451383965148124844e-02L, /* logirh[4] */ 
    9.69726562500000000000000000000000000000000000000000e-01L,   /* r[4] */ 
    7.52695325012824272079306803804945762930133964168774e-22L, /* logirl[4] */ 
  } , 
  { 
    3.78154509968176773224992313904291307835592306219041e-02L, /* logirh[5] */ 
    9.62890625000000000000000000000000000000000000000000e-01L,   /* r[5] */ 
    -2.16788501878159186776633257296336904318478361937039e-22L, /* logirl[5] */ 
  } , 
  { 
    4.59621355646357592953472545604931553953065304085612e-02L, /* logirh[6] */ 
    9.55078125000000000000000000000000000000000000000000e-01L,   /* r[6] */ 
    -4.35764480179623995168944249774175041700203429439418e-22L, /* logirl[6] */ 
  } , 
  { 
    5.31453373081281829112658150054970818132460408378392e-02L, /* logirh[7] */ 
    9.48242187500000000000000000000000000000000000000000e-01L,   /* r[7] */ 
    1.44205225309117178233184984742382173167310218612173e-21L, /* logirl[7] */ 
  } , 
  { 
    6.03805109889074798701694406916073987190429761540145e-02L, /* logirh[8] */ 
    9.41406250000000000000000000000000000000000000000000e-01L,   /* r[8] */ 
    1.27621226298941086768118279123481924424995440912208e-21L, /* logirl[8] */ 
  } , 
  { 
    6.76684141464988315320459692780996618921562912873924e-02L, /* logirh[9] */ 
    9.34570312500000000000000000000000000000000000000000e-01L,   /* r[9] */ 
    -1.85601945900591100859906157941611825774447837958521e-22L, /* logirl[9] */ 
  } , 
  { 
    7.50098210048665755422673054320092944635689491406083e-02L, /* logirh[10] */ 
    9.27734375000000000000000000000000000000000000000000e-01L,   /* r[10] */ 
    2.27568935135100192738710607079520297834759644719280e-21L, /* logirl[10] */ 
  } , 
  { 
    8.24055229659955995008915365096502370079178945161402e-02L, /* logirh[11] */ 
    9.20898437500000000000000000000000000000000000000000e-01L,   /* r[11] */ 
    -2.08652677548826307173863192982976527450361189636477e-21L, /* logirl[11] */ 
  } , 
  { 
    8.98563291218610470738304384086259091191095649264753e-02L, /* logirh[12] */ 
    9.14062500000000000000000000000000000000000000000000e-01L,   /* r[12] */ 
    2.81649638824005330910700533403251014557157154610229e-21L, /* logirl[12] */ 
  } , 
  { 
    9.62872194521514728266149175939236926069497712887824e-02L, /* logirh[13] */ 
    9.08203125000000000000000000000000000000000000000000e-01L,   /* r[13] */ 
    3.30528083859486544955729596095866578443925335442035e-21L, /* logirl[13] */ 
  } , 
  { 
    1.03842571096600936786835851777244243976383586414158e-01L, /* logirh[14] */ 
    9.01367187500000000000000000000000000000000000000000e-01L,   /* r[14] */ 
    2.54338872616873521380798016729106577000795946658943e-21L, /* logirl[14] */ 
  } , 
  { 
    1.10364333342988244918158897284188313392405689228326e-01L, /* logirh[15] */ 
    8.95507812500000000000000000000000000000000000000000e-01L,   /* r[15] */ 
    -6.14437315128255382386162762794546337880407651390618e-22L, /* logirl[15] */ 
  } , 
  { 
    1.18027206088557368998193455866818624144798377528787e-01L, /* logirh[16] */ 
    8.88671875000000000000000000000000000000000000000000e-01L,   /* r[16] */ 
    -2.70388097791548543320098495660860118836293912482208e-21L, /* logirl[16] */ 
  } , 
  { 
    1.24642445207276597340148149156702217510428454261273e-01L, /* logirh[17] */ 
    8.82812500000000000000000000000000000000000000000000e-01L,   /* r[17] */ 
    -1.65479256548791301121285753303466491277640159570672e-21L, /* logirl[17] */ 
  } , 
  { 
    1.31301737297253491506014363987553394963470054790378e-01L, /* logirh[18] */ 
    8.76953125000000000000000000000000000000000000000000e-01L,   /* r[18] */ 
    -4.44706169007428370264461881106553970898124442872790e-21L, /* logirl[18] */ 
  } , 
  { 
    1.38005673019443716708081100474903024633022141642869e-01L, /* logirh[19] */ 
    8.71093750000000000000000000000000000000000000000000e-01L,   /* r[19] */ 
    -6.32933853263050672752090547526436501335622581864643e-21L, /* logirl[19] */ 
  } , 
  { 
    1.44754854994372146671289570962759540861952700652182e-01L, /* logirh[20] */ 
    8.65234375000000000000000000000000000000000000000000e-01L,   /* r[20] */ 
    -2.20773568444613135226471926569326150288675887607608e-21L, /* logirl[20] */ 
  } , 
  { 
    1.51549898127200937837243295558398159528223914094269e-01L, /* logirh[21] */ 
    8.59375000000000000000000000000000000000000000000000e-01L,   /* r[21] */ 
    3.44652199934430957739118856235429169471459214231130e-21L, /* logirl[21] */ 
  } , 
  { 
    1.58391429943917633934029505493601419630067539401352e-01L, /* logirh[22] */ 
    8.53515625000000000000000000000000000000000000000000e-01L,   /* r[22] */ 
    5.27932393193803736951671071669282537406718712467109e-21L, /* logirl[22] */ 
  } , 
  { 
    1.65280090939102924306155009692709256796661065891385e-01L, /* logirh[23] */ 
    8.47656250000000000000000000000000000000000000000000e-01L,   /* r[23] */ 
    -2.81510601283365227976423953518023725736246907863349e-21L, /* logirl[23] */ 
  } , 
  { 
    1.72216534935759997009441409077101781122109969146550e-01L, /* logirh[24] */ 
    8.41796875000000000000000000000000000000000000000000e-01L,   /* r[24] */ 
    -2.01912227856292223514190140194940723312312693917679e-21L, /* logirl[24] */ 
  } , 
  { 
    1.78033887001673304766036221025160557474009692668915e-01L, /* logirh[25] */ 
    8.36914062500000000000000000000000000000000000000000e-01L,   /* r[25] */ 
    4.24308526385653860075391599952162594353808456148216e-21L, /* logirl[25] */ 
  } , 
  { 
    1.85059677026078958999807423657646410219967947341502e-01L, /* logirh[26] */ 
    8.31054687500000000000000000000000000000000000000000e-01L,   /* r[26] */ 
    -2.33471191752401180750814334631327570292249238444557e-21L, /* logirl[26] */ 
  } , 
  { 
    1.90952445993229815143017898126931441993292537517846e-01L, /* logirh[27] */ 
    8.26171875000000000000000000000000000000000000000000e-01L,   /* r[27] */ 
    6.30051379432552495160461774659537726971034948196913e-22L, /* logirl[27] */ 
  } , 
  { 
    1.98069913762093794816921549228894150473934132605791e-01L, /* logirh[28] */ 
    8.20312500000000000000000000000000000000000000000000e-01L,   /* r[28] */ 
    2.34598738644875224435499574368287811489905562806854e-21L, /* logirl[28] */ 
  } , 
  { 
    2.04040080748597612311876631219220712409878615289927e-01L, /* logirh[29] */ 
    8.15429687500000000000000000000000000000000000000000e-01L,   /* r[29] */ 
    -6.55266084220369778013064711105338848331692231543846e-23L, /* logirl[29] */ 
  } , 
  { 
    2.10046104808809486682598909046415514012551284395158e-01L, /* logirh[30] */ 
    8.10546875000000000000000000000000000000000000000000e-01L,   /* r[30] */ 
    -3.74137244038449388788806083485464382697060571544632e-21L, /* logirl[30] */ 
  } , 
  { 
    2.17301275689981395147928021349681415586019284091890e-01L, /* logirh[31] */ 
    8.04687500000000000000000000000000000000000000000000e-01L,   /* r[31] */ 
    4.09451380411374031422749420764587650915736730135959e-21L, /* logirl[31] */ 
  } , 
  { 
    2.23387721746383670218673127283448565094658988527954e-01L, /* logirh[32] */ 
    7.99804687500000000000000000000000000000000000000000e-01L,   /* r[32] */ 
    4.31742844476737192308069645283904795344591963380062e-21L, /* logirl[32] */ 
  } , 
  { 
    2.29511439596912796321610469862939396534784464165568e-01L, /* logirh[33] */ 
    7.94921875000000000000000000000000000000000000000000e-01L,   /* r[33] */ 
    3.43937426407325242308884173752237970071183767432875e-21L, /* logirl[33] */ 
  } , 
  { 
    2.35672888540961404738862880470229299589846050366759e-01L, /* logirh[34] */ 
    7.90039062500000000000000000000000000000000000000000e-01L,   /* r[34] */ 
    -1.79412857504879722290348395953977521127195555595173e-21L, /* logirl[34] */ 
  } , 
  { 
    2.41872536420486724268049359698462552614728338085115e-01L, /* logirh[35] */ 
    7.85156250000000000000000000000000000000000000000000e-01L,   /* r[35] */ 
    4.49037868070153677475908787622962677106946524955373e-21L, /* logirl[35] */ 
  } , 
  { 
    2.48110859833178427105411859021621978627081261947751e-01L, /* logirh[36] */ 
    7.80273437500000000000000000000000000000000000000000e-01L,   /* r[36] */ 
    -3.57593208515654235641923519987160957618932290654994e-21L, /* logirl[36] */ 
  } , 
  { 
    2.54388344352317371670256854199188012444210471585393e-01L, /* logirh[37] */ 
    7.75390625000000000000000000000000000000000000000000e-01L,   /* r[37] */ 
    1.40020874754181675296057825278585603735889206331471e-21L, /* logirl[37] */ 
  } , 
  { 
    2.59438860138385915987853380659799995555658824741840e-01L, /* logirh[38] */ 
    7.71484375000000000000000000000000000000000000000000e-01L,   /* r[38] */ 
    -6.46916224380944457548192001414018298911292216909462e-21L, /* logirl[38] */ 
  } , 
  { 
    2.65788087817044662143715211266581377458351198583841e-01L, /* logirh[39] */ 
    7.66601562500000000000000000000000000000000000000000e-01L,   /* r[39] */ 
    3.40143368552141502891849732509800494117246716875116e-21L, /* logirl[39] */ 
  } , 
  { 
    2.72177885915815673289249593258531945139111485332251e-01L, /* logirh[40] */ 
    7.61718750000000000000000000000000000000000000000000e-01L,   /* r[40] */ 
    -8.84633307151349513479527937859825353954577224837834e-22L, /* logirl[40] */ 
  } , 
  { 
    2.77319285416234343795297348500561440687306458130479e-01L, /* logirh[41] */ 
    7.57812500000000000000000000000000000000000000000000e-01L,   /* r[41] */ 
    8.60588000271282203263354404621710501397312225006788e-21L, /* logirl[41] */ 
  } , 
  { 
    2.83783432036123604418629065571089142849814379587770e-01L, /* logirh[42] */ 
    7.52929687500000000000000000000000000000000000000000e-01L,   /* r[42] */ 
    6.65259732689538164307466344899173176872160839687638e-21L, /* logirl[42] */ 
  } , 
  { 
    2.88985004232196907502858151950420051434775814414024e-01L, /* logirh[43] */ 
    7.49023437500000000000000000000000000000000000000000e-01L,   /* r[43] */ 
    -7.47526536705995483919691626521393266564129031791562e-23L, /* logirl[43] */ 
  } , 
  { 
    2.95525249912806820310438860044399689286365173757076e-01L, /* logirh[44] */ 
    7.44140625000000000000000000000000000000000000000000e-01L,   /* r[44] */ 
    1.96418844037132387179566864994176219064092063775800e-21L, /* logirl[44] */ 
  } , 
  { 
    3.00788419957081436928838027999866255868255393579602e-01L, /* logirh[45] */ 
    7.40234375000000000000000000000000000000000000000000e-01L,   /* r[45] */ 
    9.01448147009494872270782214685626529169246500631034e-21L, /* logirl[45] */ 
  } , 
  { 
    3.07406577799559516551292093211600331414956599473953e-01L, /* logirh[46] */ 
    7.35351562500000000000000000000000000000000000000000e-01L,   /* r[46] */ 
    7.19864543938640341352233477986521441579889880178279e-21L, /* logirl[46] */ 
  } , 
  { 
    3.12732822082233615765050824264470463731413474306464e-01L, /* logirh[47] */ 
    7.31445312500000000000000000000000000000000000000000e-01L,   /* r[47] */ 
    -2.48117014916151417666322195359345625530313936737052e-21L, /* logirl[47] */ 
  } , 
  { 
    3.18087587219893578585269700020887739810859784483910e-01L, /* logirh[48] */ 
    7.27539062500000000000000000000000000000000000000000e-01L,   /* r[48] */ 
    -6.13609376943018643761803888116366983614344747022738e-21L, /* logirl[48] */ 
  } , 
  { 
    3.23471180303366206721391376555096996980864787474275e-01L, /* logirh[49] */ 
    7.23632812500000000000000000000000000000000000000000e-01L,   /* r[49] */ 
    -6.83027234902916291612568719903388129847009043461519e-21L, /* logirl[49] */ 
  } , 
  { 
    3.30241686870576856292812742421638461109978379681706e-01L, /* logirh[50] */ 
    7.18750000000000000000000000000000000000000000000000e-01L,   /* r[50] */ 
    -1.34049669409517391745259355388867057086837133842982e-20L, /* logirl[50] */ 
  } , 
  { 
    3.35691291638141535192156258982087990716536296531558e-01L, /* logirh[51] */ 
    7.14843750000000000000000000000000000000000000000000e-01L,   /* r[51] */ 
    -9.33627664815897075676848962806562975738122262236195e-22L, /* logirl[51] */ 
  } , 
  { 
    3.41170757402767124748460894623214301191183039918542e-01L, /* logirh[52] */ 
    7.10937500000000000000000000000000000000000000000000e-01L,   /* r[52] */ 
    1.33237705755233408947468410861546874819170412376378e-20L, /* logirl[52] */ 
  } , 
  { 
    -3.46466767346208580905441917763276649111503502354026e-01L, /* logirh[53] */ 
    1.41406250000000000000000000000000000000000000000000e+00L,   /* r[53] */ 
    -1.30202706624963016000170912600455670740294985927040e-20L, /* logirl[53] */ 
  } , 
  { 
    -3.40926586970593210293607733252230218568001873791218e-01L, /* logirh[54] */ 
    1.40625000000000000000000000000000000000000000000000e+00L,   /* r[54] */ 
    -1.14814665281259898750718236421526040752891815931201e-20L, /* logirl[54] */ 
  } , 
  { 
    -3.35355541921137830261656978536599638118786970153451e-01L, /* logirh[55] */ 
    1.39843750000000000000000000000000000000000000000000e+00L,   /* r[55] */ 
    4.47739872243343904426499770912991919745896227107013e-21L, /* logirl[55] */ 
  } , 
  { 
    -3.30455287103297806430195551752326821315364213660359e-01L, /* logirh[56] */ 
    1.39160156250000000000000000000000000000000000000000e+00L,   /* r[56] */ 
    -3.27456892866201886570311318311258813067527495773846e-21L, /* logirl[56] */ 
  } , 
  { 
    -3.24825434091227342270433858795186665702203754335642e-01L, /* logirh[57] */ 
    1.38378906250000000000000000000000000000000000000000e+00L,   /* r[57] */ 
    1.19511796024320905916745808450236450294857297262032e-20L, /* logirl[57] */ 
  } , 
  { 
    -3.19163706299227122796481267985591045999171910807490e-01L, /* logirh[58] */ 
    1.37597656250000000000000000000000000000000000000000e+00L,   /* r[58] */ 
    6.90202297465146164725318961579993617833444966789173e-21L, /* logirl[58] */ 
  } , 
  { 
    -3.14183261995082305749471540678996461792849004268646e-01L, /* logirh[59] */ 
    1.36914062500000000000000000000000000000000000000000e+00L,   /* r[59] */ 
    4.21220977458500148787692752842598753888865534619897e-21L, /* logirl[59] */ 
  } , 
  { 
    -3.08460785721016099366091275935097826277342392131686e-01L, /* logirh[60] */ 
    1.36132812500000000000000000000000000000000000000000e+00L,   /* r[60] */ 
    4.88237814815281499208804200664728929895975484184937e-21L, /* logirl[60] */ 
  } , 
  { 
    -3.03426614715378494924018226708284373671631328761578e-01L, /* logirh[61] */ 
    1.35449218750000000000000000000000000000000000000000e+00L,   /* r[61] */ 
    -4.79684803634605371547569285269009577973457927997898e-21L, /* logirl[61] */ 
  } , 
  { 
    -2.98366972551797281470575134987299747990618925541639e-01L, /* logirh[62] */ 
    1.34765625000000000000000000000000000000000000000000e+00L,   /* r[62] */ 
    5.67470469380282997916448622011708142111988647148768e-21L, /* logirl[62] */ 
  } , 
  { 
    -2.92553002686377439973833616826404124822147423401475e-01L, /* logirh[63] */ 
    1.33984375000000000000000000000000000000000000000000e+00L,   /* r[63] */ 
    -4.36764183772251948513980052351746496236270975543032e-21L, /* logirl[63] */ 
  } , 
  { 
    -2.87437902019607012987821928473586297059227945283055e-01L, /* logirh[64] */ 
    1.33300781250000000000000000000000000000000000000000e+00L,   /* r[64] */ 
    5.29838789814029919861828480804189667231634001130568e-21L, /* logirl[64] */ 
  } , 
  { 
    -2.82296502519188342454669118919419190660846652463078e-01L, /* logirh[65] */ 
    1.32617187500000000000000000000000000000000000000000e+00L,   /* r[65] */ 
    -1.23161531041331401059141407104196718032007794736410e-20L, /* logirl[65] */ 
  } , 
  { 
    -2.77128532360745762785523768623185958404064876958728e-01L, /* logirh[66] */ 
    1.31933593750000000000000000000000000000000000000000e+00L,   /* r[66] */ 
    -2.43881362128685466800250141549314299428343038574346e-21L, /* logirl[66] */ 
  } , 
  { 
    -2.71933715483641758834396431887547862515930319204926e-01L, /* logirh[67] */ 
    1.31250000000000000000000000000000000000000000000000e+00L,   /* r[67] */ 
    2.72693735454870053343005187033588239526260949526707e-21L, /* logirl[67] */ 
  } , 
  { 
    -2.66711771502490083769927597945326169792679138481617e-01L, /* logirh[68] */ 
    1.30566406250000000000000000000000000000000000000000e+00L,   /* r[68] */ 
    -1.30538831184550256981566412802003295683583076000542e-20L, /* logirl[68] */ 
  } , 
  { 
    -2.62214012795658537999981055333087454073393018916249e-01L, /* logirh[69] */ 
    1.29980468750000000000000000000000000000000000000000e+00L,   /* r[69] */ 
    -1.35284639805347646364569630725426945939555870993862e-20L, /* logirl[69] */ 
  } , 
  { 
    -2.56940930897500425454356778875997235900285886600614e-01L, /* logirh[70] */ 
    1.29296875000000000000000000000000000000000000000000e+00L,   /* r[70] */ 
    7.59691096477297380738769966672131808838423827917718e-21L, /* logirl[70] */ 
  } , 
  { 
    -2.51639896143827947226981334161166614649118855595589e-01L, /* logirh[71] */ 
    1.28613281250000000000000000000000000000000000000000e+00L,   /* r[71] */ 
    1.08451820776528904003677301321556919497451301342926e-20L, /* logirl[71] */ 
  } , 
  { 
    -2.47073678164246748038433351690734696148865623399615e-01L, /* logirh[72] */ 
    1.28027343750000000000000000000000000000000000000000e+00L,   /* r[72] */ 
    -2.70934348074983423389837544898983311835569196319188e-22L, /* logirl[72] */ 
  } , 
  { 
    -2.41719936887145168147327835284077224287102581001818e-01L, /* logirh[73] */ 
    1.27343750000000000000000000000000000000000000000000e+00L,   /* r[73] */ 
    3.02031937056332418377432311426563822398827693734850e-21L, /* logirl[73] */ 
  } , 
  { 
    -2.37108091664582209921611002934049849955044919624925e-01L, /* logirh[74] */ 
    1.26757812500000000000000000000000000000000000000000e+00L,   /* r[74] */ 
    -1.29385562718796125049667754614832437256004301349817e-21L, /* logirl[74] */ 
  } , 
  { 
    -2.31700585247189405499685169176338206398213515058160e-01L, /* logirh[75] */ 
    1.26074218750000000000000000000000000000000000000000e+00L,   /* r[75] */ 
    6.62539371561050126516331629758628121599171156714272e-21L, /* logirl[75] */ 
  } , 
  { 
    -2.27042191729867078774313463029876913878979394212365e-01L, /* logirh[76] */ 
    1.25488281250000000000000000000000000000000000000000e+00L,   /* r[76] */ 
    -5.91897037580049650648090820667969090523023685061856e-21L, /* logirl[76] */ 
  } , 
  { 
    -2.22361995979389595864202273933774023362275329418480e-01L, /* logirh[77] */ 
    1.24902343750000000000000000000000000000000000000000e+00L,   /* r[77] */ 
    1.99231806901499648836052705402258881903978292639586e-21L, /* logirl[77] */ 
  } , 
  { 
    -2.17659792957953425506303912762007257697405293583870e-01L, /* logirh[78] */ 
    1.24316406250000000000000000000000000000000000000000e+00L,   /* r[78] */ 
    -4.74300907803349351890305548951624396775339872866125e-22L, /* logirl[78] */ 
  } , 
  { 
    -2.12145797104668402385590705860884952471678843721747e-01L, /* logirh[79] */ 
    1.23632812500000000000000000000000000000000000000000e+00L,   /* r[79] */ 
    3.47829660766824246239119087253730459399781610669550e-21L, /* logirl[79] */ 
  } , 
  { 
    -2.07395194346070587155541307955441965304999030195177e-01L, /* logirh[80] */ 
    1.23046875000000000000000000000000000000000000000000e+00L,   /* r[80] */ 
    -3.20427089356426854873522351022491299412381577686272e-21L, /* logirl[80] */ 
  } , 
  { 
    -2.02621915593412910716630305485441709834049106575549e-01L, /* logirh[81] */ 
    1.22460937500000000000000000000000000000000000000000e+00L,   /* r[81] */ 
    5.50315183352228080702347654662068966867864577851415e-21L, /* logirl[81] */ 
  } , 
  { 
    -1.97825743329919880362068387857910067850752966478467e-01L, /* logirh[82] */ 
    1.21875000000000000000000000000000000000000000000000e+00L,   /* r[82] */ 
    -5.03683339051401224496307307364812285151080899609793e-22L, /* logirl[82] */ 
  } , 
  { 
    -1.93006456893970980236542936414601001615665154531598e-01L, /* logirh[83] */ 
    1.21289062500000000000000000000000000000000000000000e+00L,   /* r[83] */ 
    -8.56513039583118089646992381309540829893520394889616e-22L, /* logirl[83] */ 
  } , 
  { 
    -1.88972566793034805259442719671536536907296977005899e-01L, /* logirh[84] */ 
    1.20800781250000000000000000000000000000000000000000e+00L,   /* r[84] */ 
    -1.46116025447516430873070498908178881036913039739167e-21L, /* logirl[84] */ 
  } , 
  { 
    -1.84110320585000416173803057529045901219433289952576e-01L, /* logirh[85] */ 
    1.20214843750000000000000000000000000000000000000000e+00L,   /* r[85] */ 
    -4.15395156136845605789354429056953059762833513205358e-21L, /* logirl[85] */ 
  } , 
  { 
    -1.79224317379374265237954554075283652991856797598302e-01L, /* logirh[86] */ 
    1.19628906250000000000000000000000000000000000000000e+00L,   /* r[86] */ 
    -1.94838468168540457849663379542888863164719363528710e-21L, /* logirl[86] */ 
  } , 
  { 
    -1.74314323881818430785127331528183702857859316281974e-01L, /* logirh[87] */ 
    1.19042968750000000000000000000000000000000000000000e+00L,   /* r[87] */ 
    6.22657527069549481059986868787317656634503241639655e-21L, /* logirl[87] */ 
  } , 
  { 
    -1.70204166019990477397598113706855826876562787219882e-01L, /* logirh[88] */ 
    1.18554687500000000000000000000000000000000000000000e+00L,   /* r[88] */ 
    2.71497198375317303100785063981453318980131866492304e-21L, /* logirl[88] */ 
  } , 
  { 
    -1.65249572895307162873914340328607153196571744047105e-01L, /* logirh[89] */ 
    1.17968750000000000000000000000000000000000000000000e+00L,   /* r[89] */ 
    -1.69710894863316053274660137780472619090744715377758e-21L, /* logirl[89] */ 
  } , 
  { 
    -1.60270309495699794511943195307601683907705591991544e-01L, /* logirh[90] */ 
    1.17382812500000000000000000000000000000000000000000e+00L,   /* r[90] */ 
    -6.04821814795533552862893869629633677033284792785115e-21L, /* logirl[90] */ 
  } , 
  { 
    -1.56101899958520053736952051814945718888338888064027e-01L, /* logirh[91] */ 
    1.16894531250000000000000000000000000000000000000000e+00L,   /* r[91] */ 
    4.40261722062672347380361273563329366574299418033041e-21L, /* logirl[91] */ 
  } , 
  { 
    -1.51916042025841975066048281095554273179004667326808e-01L, /* logirh[92] */ 
    1.16406250000000000000000000000000000000000000000000e+00L,   /* r[92] */ 
    -5.75514380133023814872665374682664797890000868696983e-21L, /* logirl[92] */ 
  } , 
  { 
    -1.46869773958217667795276076270205578566674375906587e-01L, /* logirh[93] */ 
    1.15820312500000000000000000000000000000000000000000e+00L,   /* r[93] */ 
    3.74542574364605198240110299363146340829881458953744e-21L, /* logirl[93] */ 
  } , 
  { 
    -1.42645010597909210864992976541820723923592595383525e-01L, /* logirh[94] */ 
    1.15332031250000000000000000000000000000000000000000e+00L,   /* r[94] */ 
    -1.49668764603399746810002277800399641956108986115277e-21L, /* logirl[94] */ 
  } , 
  { 
    -1.38402322859119135682777479434690803827834315598011e-01L, /* logirh[95] */ 
    1.14843750000000000000000000000000000000000000000000e+00L,   /* r[95] */ 
    -2.54839416695838356532650800861069791639429031347559e-21L, /* logirl[95] */ 
  } , 
  { 
    -1.33287222192348708683213263925804170639821677468717e-01L, /* logirh[96] */ 
    1.14257812500000000000000000000000000000000000000000e+00L,   /* r[96] */ 
    -6.43489158716437030647791169560962525141739108779861e-21L, /* logirl[96] */ 
  } , 
  { 
    -1.29004560400347845734790423743998388772524776868522e-01L, /* logirh[97] */ 
    1.13769531250000000000000000000000000000000000000000e+00L,   /* r[97] */ 
    4.12743043068895141295491814920903816740508819920186e-21L, /* logirl[97] */ 
  } , 
  { 
    -1.24703478500957235860374400920891346800090104807168e-01L, /* logirh[98] */ 
    1.13281250000000000000000000000000000000000000000000e+00L,   /* r[98] */ 
    -3.03211445997192169150157656625233654585699365130551e-21L, /* logirl[98] */ 
  } , 
  { 
    -1.20383817356440820990376872751115300275159825105220e-01L, /* logirh[99] */ 
    1.12792968750000000000000000000000000000000000000000e+00L,   /* r[99] */ 
    -6.02804224141392601725339572746961606433931174921632e-22L, /* logirl[99] */ 
  } , 
  { 
    -1.16045415757842655255155980137393711970617005135864e-01L, /* logirh[100] */ 
    1.12304687500000000000000000000000000000000000000000e+00L,   /* r[100] */ 
    1.97357499841142715648611745206675471003368015857707e-21L, /* logirl[100] */ 
  } , 
  { 
    -1.11688110388886928867871375231635155955700611229986e-01L, /* logirh[101] */ 
    1.11816406250000000000000000000000000000000000000000e+00L,   /* r[101] */ 
    -1.80234734539512005333983723608110499312624517402909e-21L, /* logirl[101] */ 
  } , 
  { 
    -1.07311735789088050666375585839862338843886391259730e-01L, /* logirh[102] */ 
    1.11328125000000000000000000000000000000000000000000e+00L,   /* r[102] */ 
    -7.99444531291997962572940662749597218537387594367069e-22L, /* logirl[102] */ 
  } , 
  { 
    -1.02916124316049955441049277432563613388083467725664e-01L, /* logirh[103] */ 
    1.10839843750000000000000000000000000000000000000000e+00L,   /* r[103] */ 
    -7.70418045355390537427085452827290090533981671198214e-22L, /* logirl[103] */ 
  } , 
  { 
    -9.85011061069331584304480803337966676735959481447935e-02L, /* logirh[104] */ 
    1.10351562500000000000000000000000000000000000000000e+00L,   /* r[104] */ 
    2.64634661517646879820354995203947987149684385342190e-21L, /* logirl[104] */ 
  } , 
  { 
    -9.40665090390674124196622452043214934747084043920040e-02L, /* logirh[105] */ 
    1.09863281250000000000000000000000000000000000000000e+00L,   /* r[105] */ 
    -7.85013737527153642092056782136336663408299656719499e-22L, /* logirl[105] */ 
  } , 
  { 
    -8.96121586896871326189772770376418264959283987991512e-02L, /* logirh[106] */ 
    1.09375000000000000000000000000000000000000000000000e+00L,   /* r[106] */ 
    -9.74192340842702289248316897714444315823596817643550e-22L, /* logirl[106] */ 
  } , 
  { 
    -8.60343373418031533820279736779479407005055691115558e-02L, /* logirh[107] */ 
    1.08984375000000000000000000000000000000000000000000e+00L,   /* r[107] */ 
    2.30146955951865559597249227413865587554269312860475e-22L, /* logirl[107] */ 
  } , 
  { 
    -8.15439840401769007739956988956020467185226152651012e-02L, /* logirh[108] */ 
    1.08496093750000000000000000000000000000000000000000e+00L,   /* r[108] */ 
    1.75068599249270760931371736454488137316032510066418e-22L, /* logirl[108] */ 
  } , 
  { 
    -7.70333764828270145253981751598537641712027834728360e-02L, /* logirh[109] */ 
    1.08007812500000000000000000000000000000000000000000e+00L,   /* r[109] */ 
    2.18898335885222504011340723675649479553611259830224e-21L, /* logirl[109] */ 
  } , 
  { 
    -7.25023311232268688402238278334355214838069514371455e-02L, /* logirh[110] */ 
    1.07519531250000000000000000000000000000000000000000e+00L,   /* r[110] */ 
    -2.13213366575366793826831658963525268068913415683098e-21L, /* logirl[110] */ 
  } , 
  { 
    -6.88626546757771517366978307472802356414831592701375e-02L, /* logirh[111] */ 
    1.07128906250000000000000000000000000000000000000000e+00L,   /* r[111] */ 
    -3.28324237603869825985548439776523090582575800369089e-22L, /* logirl[111] */ 
  } , 
  { 
    -6.42943507053972572172256989830874118752035428769886e-02L, /* logirh[112] */ 
    1.06640625000000000000000000000000000000000000000000e+00L,   /* r[112] */ 
    9.97248717475917389385548315283734311163209646118044e-22L, /* logirl[112] */ 
  } , 
  { 
    -6.06246218164348425809463336011440048878284869715571e-02L, /* logirh[113] */ 
    1.06250000000000000000000000000000000000000000000000e+00L,   /* r[113] */ 
    3.40201560723741601617729662632506532290642311489711e-22L, /* logirl[113] */ 
  } , 
  { 
    -5.60184414015375172410100661213316897146796691231430e-02L, /* logirh[114] */ 
    1.05761718750000000000000000000000000000000000000000e+00L,   /* r[114] */ 
    3.11800048645913474307950146912226463632967430723724e-23L, /* logirl[114] */ 
  } , 
  { 
    -5.23181596586815653583246027436004510491329710930586e-02L, /* logirh[115] */ 
    1.05371093750000000000000000000000000000000000000000e+00L,   /* r[115] */ 
    1.68615246867707396959723624602535685414462357313269e-21L, /* logirl[115] */ 
  } , 
  { 
    -4.76734694693569028189818886920292584363778587430716e-02L, /* logirh[116] */ 
    1.04882812500000000000000000000000000000000000000000e+00L,   /* r[116] */ 
    1.02131487169049086541356584124809714333053944625270e-21L, /* logirl[116] */ 
  } , 
  { 
    -4.39421218564987631503880941008510774281603517010808e-02L, /* logirh[117] */ 
    1.04492187500000000000000000000000000000000000000000e+00L,   /* r[117] */ 
    3.19036974975549018917247656911137538435844307015502e-22L, /* logirl[117] */ 
  } , 
  { 
    -4.01967991263367551645860776404761693925138388294727e-02L, /* logirh[118] */ 
    1.04101562500000000000000000000000000000000000000000e+00L,   /* r[118] */ 
    -5.75643838660911109663810221439950742515738641098385e-22L, /* logirl[118] */ 
  } , 
  { 
    -3.54953330145300408896490932525447092871218046639115e-02L, /* logirh[119] */ 
    1.03613281250000000000000000000000000000000000000000e+00L,   /* r[119] */ 
    9.92857944898394620246865383584341693120429858950945e-23L, /* logirl[119] */ 
  } , 
  { 
    -3.17181802707845397290716514537844972210223204456270e-02L, /* logirh[120] */ 
    1.03222656250000000000000000000000000000000000000000e+00L,   /* r[120] */ 
    -1.96176892105841918795869133037686185923113451571873e-22L, /* logirl[120] */ 
  } , 
  { 
    -2.79267065345224074627335925091742296899610664695501e-02L, /* logirh[121] */ 
    1.02832031250000000000000000000000000000000000000000e+00L,   /* r[121] */ 
    5.86417835518487049711934217680032678831410128853609e-22L, /* logirl[121] */ 
  } , 
  { 
    -2.41208027968440809158740456216718506254892417928204e-02L, /* logirh[122] */ 
    1.02441406250000000000000000000000000000000000000000e+00L,   /* r[122] */ 
    3.02985243973796148231999463903827273031077578359612e-22L, /* logirl[122] */ 
  } , 
  { 
    -1.93429628431309346365065977152442044939562038052827e-02L, /* logirh[123] */ 
    1.01953125000000000000000000000000000000000000000000e+00L,   /* r[123] */ 
    6.01063173693734308460897092397749141966269930081944e-22L, /* logirl[123] */ 
  } , 
  { 
    -1.55041865359652541508843977442755335260926585760899e-02L, /* logirh[124] */ 
    1.01562500000000000000000000000000000000000000000000e+00L,   /* r[124] */ 
    3.03517018286976482243336130818153212447067590236466e-23L, /* logirl[124] */ 
  } , 
  { 
    -1.16506172199752741354571356803548898284361712285317e-02L, /* logirh[125] */ 
    1.01171875000000000000000000000000000000000000000000e+00L,   /* r[125] */ 
    -1.34307128859459104723409399281441278120110731736138e-22L, /* logirl[125] */ 
  } , 
  { 
    -7.78214044205494894757658497566610300566480873385444e-03L, /* logirh[126] */ 
    1.00781250000000000000000000000000000000000000000000e+00L,   /* r[126] */ 
    1.13684914529339327537355164185463042556838581909991e-22L, /* logirl[126] */ 
  } , 
  { 
    -3.89864041565732301388162890642963276377486181445420e-03L, /* logirh[127] */ 
    1.00390625000000000000000000000000000000000000000000e+00L,   /* r[127] */ 
    -5.57141894132742469511718763808942289917039607877533e-23L, /* logirl[127] */ 
  } , 
  { 
    0.00000000000000000000000000000000000000000000000000e-01L, /* logirh[128] */ 
    1.00000000000000000000000000000000000000000000000000e+00L,   /* r[128] */ 
    0.00000000000000000000000000000000000000000000000000e-01L, /* logirl[128] */ 
  } }; 
 
