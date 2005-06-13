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
#define INDEXMASK 127
static const long double log2h  = 6.93147180559945309428690474184975300886435434222221e-01L ;
static const long double log2l  = -1.14583527267987328109462081210062935494878745868567e-20L ;
static const long double two64 = 1.84467440737095516160000000000000000000000000000000e+19L ;
static const long double c[7] =  {
   /* c7  = */ 1.42860987471441585385531838903183654565509641543031e-01L, 
   /* c6  = */ -1.66670030707931824157878170078461721459461841732264e-01L, 
   /* c5  = */ 1.99999999957299715572971512966837792646401794627309e-01L, 
   /* c4  = */ -2.49999999974133361728043621619033132219556136988103e-01L, 
   /* c3  = */ 3.33333333333333491175099611014687184251670259982347e-01L, 
   /* c2  = */ -5.00000000000000049710669608460378299241710919886827e-01L, 
   /* c1  = */ 1.00000000000000000000000000000000000000000000000000e+00L, 
}; 
 
static const long double ch[14] =  {
   /* ch14  = */ -7.14324161786485507414918953716931326880512642674148e-02L, 
   /* ch13  = */ 7.69266652810744782218957231456624157317492063157260e-02L, 
   /* ch12  = */ -8.33333332381758034492348456712118576206194120459259e-02L, 
   /* ch11  = */ 9.09090908332141065513009973997338164508619229309261e-02L, 
   /* ch10  = */ -1.00000000000001207646721339272755102456358144991100e-01L, 
   /* ch9  = */ 1.11111111111111906697159444623590474066077149473131e-01L, 
   /* ch8  = */ -1.24999999999999999993223736421965597287453419994563e-01L, 
   /* ch7  = */ 1.42857142857142857140921067549133027796415262855589e-01L, 
   /* ch6  = */ -1.66666666666666666671184175718689601808364386670291e-01L, 
   /* ch5  = */ 2.00000000000000000002710505431213761085018632002175e-01L, 
   /* ch4  = */ -2.50000000000000000000000000000000000000000000000000e-01L, 
   /* ch3  = */ 3.33333333333333333342368351437379203616728773340583e-01L, 
   /* ch2  = */ -5.00000000000000000000000000000000000000000000000000e-01L, 
   /* ch1  = */ 1.00000000000000000000000000000000000000000000000000e+00L, 
}; 
 
static const long double cl[8] =  {
   /* cl7  = */ -2.34607301544056142329539178188626637856988425622953e-21L, 
   /* cl6  = */ 4.51747965172264117284728817178707773935320194423540e-21L, 
   /* cl5  = */ -2.71049445588233034921278017356112411600953390125340e-21L, 
   /* cl4  = */ 4.66256664939948057471422101604617896775339795184375e-32L, 
   /* cl3  = */ -9.03501810405641912072078793108404620486918713178584e-21L, 
   /* cl2  = */ -2.17279608948233676401606923369245026501745724471211e-38L, 
   /* cl1  = */ 1.65533283613483715658161425689915551329447733519200e-39L, 
}; 
 
typedef struct rri_tag {float r; long double logirh;  long double logirl; } rri ;  
static const rri argredtable[128] = {
  { 
    1.00000000000000000000000000000000000000000000000000e+00L,   /* r[0] */ 
    0.00000000000000000000000000000000000000000000000000e+00L, /* logirh[0] */ 
    0.00000000000000000000000000000000000000000000000000e+00L, /* logirl[0] */ 
  } , 
  { 
    9.92187500000000000000000000000000000000000000000000e-01L,   /* r[1] */ 
    7.84317746102589287284596788335511163836599735077471e-03L, /* logirh[1] */ 
    3.38074607588470016237165513745732472460993853200422e-22L, /* logirl[1] */ 
  } , 
  { 
    9.84375000000000000000000000000000000000000000000000e-01L,   /* r[2] */ 
    1.57483569681391686082786579570225171664787922054529e-02L, /* logirh[2] */ 
    -7.29146496194247645559133241782926476205899642506092e-22L, /* logirl[2] */ 
  } , 
  { 
    9.77050781250000000000000000000000000000000000000000e-01L,   /* r[3] */ 
    2.32166515756649942034666594947722728647931944578886e-02L, /* logirh[3] */ 
    8.16575450536547381330756941074595397347505963439697e-22L, /* logirl[3] */ 
  } , 
  { 
    9.69726562500000000000000000000000000000000000000000e-01L,   /* r[4] */ 
    3.07411415542805019917064427575903451383965148124844e-02L, /* logirh[4] */ 
    7.52695325012824272079306803804945762930133964168774e-22L, /* logirl[4] */ 
  } , 
  { 
    9.62402343750000000000000000000000000000000000000000e-01L,   /* r[5] */ 
    3.83226790066782003103828830453680964751583815086633e-02L, /* logirh[5] */ 
    1.32588478845446750814375495501523698113568837341268e-21L, /* logirl[5] */ 
  } , 
  { 
    9.55078125000000000000000000000000000000000000000000e-01L,   /* r[6] */ 
    4.59621355646357592953472545604931553953065304085612e-02L, /* logirh[6] */ 
    -4.35764480179623995168944249774175041700203429439418e-22L, /* logirl[6] */ 
  } , 
  { 
    9.48242187500000000000000000000000000000000000000000e-01L,   /* r[7] */ 
    5.31453373081281829112658150054970818132460408378392e-02L, /* logirh[7] */ 
    1.44205225309117178233184984742382173167310218612172e-21L, /* logirl[7] */ 
  } , 
  { 
    9.41406250000000000000000000000000000000000000000000e-01L,   /* r[8] */ 
    6.03805109889074798701694406916073987190429761540145e-02L, /* logirh[8] */ 
    1.27621226298941086768118279123481924424995440912208e-21L, /* logirl[8] */ 
  } , 
  { 
    9.34082031250000000000000000000000000000000000000000e-01L,   /* r[9] */ 
    6.81910167191455281494459790547768562873898190446198e-02L, /* logirh[9] */ 
    -1.70880559998991196112313542261373401163426418187142e-21L, /* logirl[9] */ 
  } , 
  { 
    9.27734375000000000000000000000000000000000000000000e-01L,   /* r[10] */ 
    7.50098210048665755422673054320092944635689491406083e-02L, /* logirh[10] */ 
    2.27568935135100192738710607079520297834759644719280e-21L, /* logirl[10] */ 
  } , 
  { 
    9.20898437500000000000000000000000000000000000000000e-01L,   /* r[11] */ 
    8.24055229659955995008915365096502370079178945161402e-02L, /* logirh[11] */ 
    -2.08652677548826307173863192982976527450361189636477e-21L, /* logirl[11] */ 
  } , 
  { 
    9.14062500000000000000000000000000000000000000000000e-01L,   /* r[12] */ 
    8.98563291218610470738304384086259091191095649264753e-02L, /* logirh[12] */ 
    2.81649638824005330910700533403251014557157154610229e-21L, /* logirl[12] */ 
  } , 
  { 
    9.07714843750000000000000000000000000000000000000000e-01L,   /* r[13] */ 
    9.68249984379543874202667802508770478198130149394274e-02L, /* logirh[13] */ 
    3.68094693298691578446114201021493215549389467689654e-22L, /* logirl[13] */ 
  } , 
  { 
    9.01367187500000000000000000000000000000000000000000e-01L,   /* r[14] */ 
    1.03842571096600936786835851777244243976383586414158e-01L, /* logirh[14] */ 
    2.54338872616873521380798016729106577000795946658943e-21L, /* logirl[14] */ 
  } , 
  { 
    8.95019531250000000000000000000000000000000000000000e-01L,   /* r[15] */ 
    1.10909738319693389317513541186821512951610202435404e-01L, /* logirh[15] */ 
    2.35644659310271753015106107980519412012017300780629e-21L, /* logirl[15] */ 
  } , 
  { 
    8.88671875000000000000000000000000000000000000000000e-01L,   /* r[16] */ 
    1.18027206088557368998193455866818624144798377528787e-01L, /* logirh[16] */ 
    -2.70388097791548543320098495660860118836293912482208e-21L, /* logirl[16] */ 
  } , 
  { 
    8.82812500000000000000000000000000000000000000000000e-01L,   /* r[17] */ 
    1.24642445207276597340148149156702217510428454261273e-01L, /* logirh[17] */ 
    -1.65479256548791301121285753303466491277640159570672e-21L, /* logirl[17] */ 
  } , 
  { 
    8.76953125000000000000000000000000000000000000000000e-01L,   /* r[18] */ 
    1.31301737297253491506014363987553394963470054790378e-01L, /* logirh[18] */ 
    -4.44706169007428370264461881106553970898124442872790e-21L, /* logirl[18] */ 
  } , 
  { 
    8.70605468750000000000000000000000000000000000000000e-01L,   /* r[19] */ 
    1.38566368296257995358167561250617438872723141685128e-01L, /* logirh[19] */ 
    -4.67634371291677236899800289793824808374204801868093e-22L, /* logirl[19] */ 
  } , 
  { 
    8.64746093750000000000000000000000000000000000000000e-01L,   /* r[20] */ 
    1.45319348376564863616804482160382860911340685561299e-01L, /* logirh[20] */ 
    -1.30029933894575998199859720642569228712037418444249e-21L, /* logirl[20] */ 
  } , 
  { 
    8.58886718750000000000000000000000000000000000000000e-01L,   /* r[21] */ 
    1.52118241421840233982849116545210677031718660145998e-01L, /* logirh[21] */ 
    3.64354833902581289681945250205165982842948711023632e-21L, /* logirl[21] */ 
  } , 
  { 
    8.53515625000000000000000000000000000000000000000000e-01L,   /* r[22] */ 
    1.58391429943917633934029505493601419630067539401352e-01L, /* logirh[22] */ 
    5.27932393193803736951671071669282537406718712467109e-21L, /* logirl[22] */ 
  } , 
  { 
    8.47656250000000000000000000000000000000000000000000e-01L,   /* r[23] */ 
    1.65280090939102924306155009692709256796661065891385e-01L, /* logirh[23] */ 
    -2.81510601283365227976423953518023725736246907863349e-21L, /* logirl[23] */ 
  } , 
  { 
    8.42285156250000000000000000000000000000000000000000e-01L,   /* r[24] */ 
    1.71636656693938272180742846129142264999245526269078e-01L, /* logirh[24] */ 
    5.29375472570288169027310108578005956387644768823013e-21L, /* logirl[24] */ 
  } , 
  { 
    8.36425781250000000000000000000000000000000000000000e-01L,   /* r[25] */ 
    1.78617487835278495469731006861646704919621697627008e-01L, /* logirh[25] */ 
    -5.38910368385932491449404580991668679267931166391590e-21L, /* logirl[25] */ 
  } , 
  { 
    8.31054687500000000000000000000000000000000000000000e-01L,   /* r[26] */ 
    1.85059677026078958999807423657646410219967947341502e-01L, /* logirh[26] */ 
    -2.33471191752401180750814334631327570292249238444557e-21L, /* logirl[26] */ 
  } , 
  { 
    8.25683593750000000000000000000000000000000000000000e-01L,   /* r[27] */ 
    1.91543637260818105263310805186360852303550927899778e-01L, /* logirh[27] */ 
    -6.00441704121360115108475562878860059804996577890616e-22L, /* logirl[27] */ 
  } , 
  { 
    8.20312500000000000000000000000000000000000000000000e-01L,   /* r[28] */ 
    1.98069913762093794816921549228894150473934132605791e-01L, /* logirh[28] */ 
    2.34598738644875224435499574368287811489905562806854e-21L, /* logirl[28] */ 
  } , 
  { 
    8.15429687500000000000000000000000000000000000000000e-01L,   /* r[29] */ 
    2.04040080748597612311876631219220712409878615289927e-01L, /* logirh[29] */ 
    -6.55266084220369778013064711105338848331692231543846e-23L, /* logirl[29] */ 
  } , 
  { 
    8.10058593750000000000000000000000000000000000000000e-01L,   /* r[30] */ 
    2.10648695968953912917276914684716615511206327937543e-01L, /* logirh[30] */ 
    -1.26710049189072313882986012728331847015236776848568e-21L, /* logirl[30] */ 
  } , 
  { 
    8.05175781250000000000000000000000000000000000000000e-01L,   /* r[31] */ 
    2.16694663599799501227903542055486241224571131169796e-01L, /* logirh[31] */ 
    -4.60644559263224179134698153089361151013881754428009e-21L, /* logirl[31] */ 
  } , 
  { 
    7.99804687500000000000000000000000000000000000000000e-01L,   /* r[32] */ 
    2.23387721746383670218673127283448565094658988527954e-01L, /* logirh[32] */ 
    4.31742844476737192308069645283904795344591963380062e-21L, /* logirl[32] */ 
  } , 
  { 
    7.94921875000000000000000000000000000000000000000000e-01L,   /* r[33] */ 
    2.29511439596912796321610469862939396534784464165568e-01L, /* logirh[33] */ 
    3.43937426407325242308884173752237970071183767432875e-21L, /* logirl[33] */ 
  } , 
  { 
    7.90039062500000000000000000000000000000000000000000e-01L,   /* r[34] */ 
    2.35672888540961404738862880470229299589846050366759e-01L, /* logirh[34] */ 
    -1.79412857504879722290348395953977521127195555595173e-21L, /* logirl[34] */ 
  } , 
  { 
    7.85156250000000000000000000000000000000000000000000e-01L,   /* r[35] */ 
    2.41872536420486724268049359698462552614728338085115e-01L, /* logirh[35] */ 
    4.49037868070153677475908787622962677106946524955373e-21L, /* logirl[35] */ 
  } , 
  { 
    7.80273437500000000000000000000000000000000000000000e-01L,   /* r[36] */ 
    2.48110859833178427105411859021621978627081261947751e-01L, /* logirh[36] */ 
    -3.57593208515654235641923519987160957618932290654994e-21L, /* logirl[36] */ 
  } , 
  { 
    7.75878906250000000000000000000000000000000000000000e-01L,   /* r[37] */ 
    2.53758819622682423467613377354723525058943778276443e-01L, /* logirh[37] */ 
    3.20563840854194897949310719402625620635813869593052e-21L, /* logirl[37] */ 
  } , 
  { 
    7.70996093750000000000000000000000000000000000000000e-01L,   /* r[38] */ 
    2.60071971903756312988632154459267553647805470973253e-01L, /* logirh[38] */ 
    -5.41882056366019440034410441132485333532494541348922e-21L, /* logirl[38] */ 
  } , 
  { 
    7.66601562500000000000000000000000000000000000000000e-01L,   /* r[39] */ 
    2.65788087817044662143715211266581377458351198583841e-01L, /* logirh[39] */ 
    3.40143368552141502891849732509800494117246716875116e-21L, /* logirl[39] */ 
  } , 
  { 
    7.61718750000000000000000000000000000000000000000000e-01L,   /* r[40] */ 
    2.72177885915815673289249593258531945139111485332251e-01L, /* logirh[40] */ 
    -8.84633307151349513479527937859825353954577224837834e-22L, /* logirl[40] */ 
  } , 
  { 
    7.57324218750000000000000000000000000000000000000000e-01L,   /* r[41] */ 
    2.77963822982859581314958596909292509735678322613239e-01L, /* logirh[41] */ 
    -3.54474552917897427055990528561562900487032834630297e-21L, /* logirl[41] */ 
  } , 
  { 
    7.52929687500000000000000000000000000000000000000000e-01L,   /* r[42] */ 
    2.83783432036123604418629065571089142849814379587770e-01L, /* logirh[42] */ 
    6.65259732689538164307466344899173176872160839687638e-21L, /* logirl[42] */ 
  } , 
  { 
    7.48535156250000000000000000000000000000000000000000e-01L,   /* r[43] */ 
    2.89637107287584277988401471048973689903505146503448e-01L, /* logirh[43] */ 
    8.44502718672055373787764268905081131551582182658017e-21L, /* logirl[43] */ 
  } , 
  { 
    7.44140625000000000000000000000000000000000000000000e-01L,   /* r[44] */ 
    2.95525249912806820310438860044399689286365173757076e-01L, /* logirh[44] */ 
    1.96418844037132387179566864994176219064092063775800e-21L, /* logirl[44] */ 
  } , 
  { 
    7.39746093750000000000000000000000000000000000000000e-01L,   /* r[45] */ 
    3.01448268215928886712157847016513301241502631455660e-01L, /* logirh[45] */ 
    -2.80734803827355347488954127622224279750224052590805e-21L, /* logirl[45] */ 
  } , 
  { 
    7.35839843750000000000000000000000000000000000000000e-01L,   /* r[46] */ 
    3.06742787532902944200221412307527657503669615834951e-01L, /* logirh[46] */ 
    1.21982177874199009422425119496965659738938728771737e-20L, /* logirl[46] */ 
  } , 
  { 
    7.31445312500000000000000000000000000000000000000000e-01L,   /* r[47] */ 
    3.12732822082233615765050824264470463731413474306464e-01L, /* logirh[47] */ 
    -2.48117014916151417666322195359345625530313936737052e-21L, /* logirl[47] */ 
  } , 
  { 
    7.27050781250000000000000000000000000000000000000000e-01L,   /* r[48] */ 
    3.18758953475389418655326981277831066563521744683385e-01L, /* logirh[48] */ 
    6.18924657142483596407123884547314261312268979674812e-21L, /* logirl[48] */ 
  } , 
  { 
    7.23144531250000000000000000000000000000000000000000e-01L,   /* r[49] */ 
    3.24146171891599621094504773965994104401033837348223e-01L, /* logirh[49] */ 
    -6.77810676502059511550248363328884520138042030679722e-21L, /* logirl[49] */ 
  } , 
  { 
    7.19238281250000000000000000000000000000000000000000e-01L,   /* r[50] */ 
    3.29562569696768133456748345322395721268549095839262e-01L, /* logirh[50] */ 
    3.36942877993616991096538545261104308752103794630367e-21L, /* logirl[50] */ 
  } , 
  { 
    7.14843750000000000000000000000000000000000000000000e-01L,   /* r[51] */ 
    3.35691291638141535192156258982087990716536296531558e-01L, /* logirh[51] */ 
    -9.33627664815897075676848962806562975738122262236195e-22L, /* logirl[51] */ 
  } , 
  { 
    7.10937500000000000000000000000000000000000000000000e-01L,   /* r[52] */ 
    3.41170757402767124748460894623214301191183039918542e-01L, /* logirh[52] */ 
    1.33237705755233408947468410861546874819170412376378e-20L, /* logirl[52] */ 
  } , 
  { 
    1.41406250000000000000000000000000000000000000000000e+00L,   /* r[53] */ 
    -3.46466767346208580905441917763276649111503502354026e-01L, /* logirh[53] */ 
    -1.30202706624963016000170912600455670740294985927040e-20L, /* logirl[53] */ 
  } , 
  { 
    1.40625000000000000000000000000000000000000000000000e+00L,   /* r[54] */ 
    -3.40926586970593210293607733252230218568001873791218e-01L, /* logirh[54] */ 
    -1.14814665281259898750718236421526040752891815931201e-20L, /* logirl[54] */ 
  } , 
  { 
    1.39843750000000000000000000000000000000000000000000e+00L,   /* r[55] */ 
    -3.35355541921137830261656978536599638118786970153451e-01L, /* logirh[55] */ 
    4.47739872243343904426499770912991919745896227107013e-21L, /* logirl[55] */ 
  } , 
  { 
    1.39160156250000000000000000000000000000000000000000e+00L,   /* r[56] */ 
    -3.30455287103297806430195551752326821315364213660359e-01L, /* logirh[56] */ 
    -3.27456892866201886570311318311258813067527495773846e-21L, /* logirl[56] */ 
  } , 
  { 
    1.38378906250000000000000000000000000000000000000000e+00L,   /* r[57] */ 
    -3.24825434091227342270433858795186665702203754335642e-01L, /* logirh[57] */ 
    1.19511796024320905916745808450236450294857297262032e-20L, /* logirl[57] */ 
  } , 
  { 
    1.37597656250000000000000000000000000000000000000000e+00L,   /* r[58] */ 
    -3.19163706299227122796481267985591045999171910807490e-01L, /* logirh[58] */ 
    6.90202297465146164725318961579993617833444966789173e-21L, /* logirl[58] */ 
  } , 
  { 
    1.36914062500000000000000000000000000000000000000000e+00L,   /* r[59] */ 
    -3.14183261995082305749471540678996461792849004268646e-01L, /* logirh[59] */ 
    4.21220977458500148787692752842598753888865534619897e-21L, /* logirl[59] */ 
  } , 
  { 
    1.36132812500000000000000000000000000000000000000000e+00L,   /* r[60] */ 
    -3.08460785721016099366091275935097826277342392131686e-01L, /* logirh[60] */ 
    4.88237814815281499208804200664728929895975484184937e-21L, /* logirl[60] */ 
  } , 
  { 
    1.35449218750000000000000000000000000000000000000000e+00L,   /* r[61] */ 
    -3.03426614715378494924018226708284373671631328761578e-01L, /* logirh[61] */ 
    -4.79684803634605371547569285269009577973457927997898e-21L, /* logirl[61] */ 
  } , 
  { 
    1.34765625000000000000000000000000000000000000000000e+00L,   /* r[62] */ 
    -2.98366972551797281470575134987299747990618925541639e-01L, /* logirh[62] */ 
    5.67470469380282997916448622011708142111988647148768e-21L, /* logirl[62] */ 
  } , 
  { 
    1.33984375000000000000000000000000000000000000000000e+00L,   /* r[63] */ 
    -2.92553002686377439973833616826404124822147423401475e-01L, /* logirh[63] */ 
    -4.36764183772251948513980052351746496236270975543032e-21L, /* logirl[63] */ 
  } , 
  { 
    1.33300781250000000000000000000000000000000000000000e+00L,   /* r[64] */ 
    -2.87437902019607012987821928473586297059227945283055e-01L, /* logirh[64] */ 
    5.29838789814029919861828480804189667231634001130568e-21L, /* logirl[64] */ 
  } , 
  { 
    1.32617187500000000000000000000000000000000000000000e+00L,   /* r[65] */ 
    -2.82296502519188342454669118919419190660846652463078e-01L, /* logirh[65] */ 
    -1.23161531041331401059141407104196718032007794736410e-20L, /* logirl[65] */ 
  } , 
  { 
    1.31933593750000000000000000000000000000000000000000e+00L,   /* r[66] */ 
    -2.77128532360745762785523768623185958404064876958728e-01L, /* logirh[66] */ 
    -2.43881362128685466800250141549314299428343038574346e-21L, /* logirl[66] */ 
  } , 
  { 
    1.31250000000000000000000000000000000000000000000000e+00L,   /* r[67] */ 
    -2.71933715483641758834396431887547862515930319204926e-01L, /* logirh[67] */ 
    2.72693735454870053343005187033588239526260949526707e-21L, /* logirl[67] */ 
  } , 
  { 
    1.30566406250000000000000000000000000000000000000000e+00L,   /* r[68] */ 
    -2.66711771502490083769927597945326169792679138481617e-01L, /* logirh[68] */ 
    -1.30538831184550256981566412802003295683583076000542e-20L, /* logirl[68] */ 
  } , 
  { 
    1.29980468750000000000000000000000000000000000000000e+00L,   /* r[69] */ 
    -2.62214012795658537999981055333087454073393018916249e-01L, /* logirh[69] */ 
    -1.35284639805347646364569630725426945939555870993862e-20L, /* logirl[69] */ 
  } , 
  { 
    1.29296875000000000000000000000000000000000000000000e+00L,   /* r[70] */ 
    -2.56940930897500425454356778875997235900285886600614e-01L, /* logirh[70] */ 
    7.59691096477297380738769966672131808838423827917718e-21L, /* logirl[70] */ 
  } , 
  { 
    1.28613281250000000000000000000000000000000000000000e+00L,   /* r[71] */ 
    -2.51639896143827947226981334161166614649118855595589e-01L, /* logirh[71] */ 
    1.08451820776528904003677301321556919497451301342926e-20L, /* logirl[71] */ 
  } , 
  { 
    1.28027343750000000000000000000000000000000000000000e+00L,   /* r[72] */ 
    -2.47073678164246748038433351690734696148865623399615e-01L, /* logirh[72] */ 
    -2.70934348074983423389837544898983311835569196319188e-22L, /* logirl[72] */ 
  } , 
  { 
    1.27343750000000000000000000000000000000000000000000e+00L,   /* r[73] */ 
    -2.41719936887145168147327835284077224287102581001818e-01L, /* logirh[73] */ 
    3.02031937056332418377432311426563822398827693734850e-21L, /* logirl[73] */ 
  } , 
  { 
    1.26757812500000000000000000000000000000000000000000e+00L,   /* r[74] */ 
    -2.37108091664582209921611002934049849955044919624925e-01L, /* logirh[74] */ 
    -1.29385562718796125049667754614832437256004301349817e-21L, /* logirl[74] */ 
  } , 
  { 
    1.26074218750000000000000000000000000000000000000000e+00L,   /* r[75] */ 
    -2.31700585247189405499685169176338206398213515058160e-01L, /* logirh[75] */ 
    6.62539371561050126516331629758628121599171156714272e-21L, /* logirl[75] */ 
  } , 
  { 
    1.25488281250000000000000000000000000000000000000000e+00L,   /* r[76] */ 
    -2.27042191729867078774313463029876913878979394212365e-01L, /* logirh[76] */ 
    -5.91897037580049650648090820667969090523023685061856e-21L, /* logirl[76] */ 
  } , 
  { 
    1.24902343750000000000000000000000000000000000000000e+00L,   /* r[77] */ 
    -2.22361995979389595864202273933774023362275329418480e-01L, /* logirh[77] */ 
    1.99231806901499648836052705402258881903978292639586e-21L, /* logirl[77] */ 
  } , 
  { 
    1.24316406250000000000000000000000000000000000000000e+00L,   /* r[78] */ 
    -2.17659792957953425506303912762007257697405293583870e-01L, /* logirh[78] */ 
    -4.74300907803349351890305548951624396775339872866125e-22L, /* logirl[78] */ 
  } , 
  { 
    1.23632812500000000000000000000000000000000000000000e+00L,   /* r[79] */ 
    -2.12145797104668402385590705860884952471678843721747e-01L, /* logirh[79] */ 
    3.47829660766824246239119087253730459399781610669550e-21L, /* logirl[79] */ 
  } , 
  { 
    1.23046875000000000000000000000000000000000000000000e+00L,   /* r[80] */ 
    -2.07395194346070587155541307955441965304999030195177e-01L, /* logirh[80] */ 
    -3.20427089356426854873522351022491299412381577686272e-21L, /* logirl[80] */ 
  } , 
  { 
    1.22460937500000000000000000000000000000000000000000e+00L,   /* r[81] */ 
    -2.02621915593412910716630305485441709834049106575549e-01L, /* logirh[81] */ 
    5.50315183352228080702347654662068966867864577851415e-21L, /* logirl[81] */ 
  } , 
  { 
    1.21875000000000000000000000000000000000000000000000e+00L,   /* r[82] */ 
    -1.97825743329919880362068387857910067850752966478467e-01L, /* logirh[82] */ 
    -5.03683339051401224496307307364812285151080899609793e-22L, /* logirl[82] */ 
  } , 
  { 
    1.21289062500000000000000000000000000000000000000000e+00L,   /* r[83] */ 
    -1.93006456893970980236542936414601001615665154531598e-01L, /* logirh[83] */ 
    -8.56513039583118089646992381309540829893520394889616e-22L, /* logirl[83] */ 
  } , 
  { 
    1.20800781250000000000000000000000000000000000000000e+00L,   /* r[84] */ 
    -1.88972566793034805259442719671536536907296977005899e-01L, /* logirh[84] */ 
    -1.46116025447516430873070498908178881036913039739167e-21L, /* logirl[84] */ 
  } , 
  { 
    1.20214843750000000000000000000000000000000000000000e+00L,   /* r[85] */ 
    -1.84110320585000416173803057529045901219433289952576e-01L, /* logirh[85] */ 
    -4.15395156136845605789354429056953059762833513205358e-21L, /* logirl[85] */ 
  } , 
  { 
    1.19628906250000000000000000000000000000000000000000e+00L,   /* r[86] */ 
    -1.79224317379374265237954554075283652991856797598302e-01L, /* logirh[86] */ 
    -1.94838468168540457849663379542888863164719363528710e-21L, /* logirl[86] */ 
  } , 
  { 
    1.19042968750000000000000000000000000000000000000000e+00L,   /* r[87] */ 
    -1.74314323881818430785127331528183702857859316281974e-01L, /* logirh[87] */ 
    6.22657527069549481059986868787317656634503241639655e-21L, /* logirl[87] */ 
  } , 
  { 
    1.18554687500000000000000000000000000000000000000000e+00L,   /* r[88] */ 
    -1.70204166019990477397598113706855826876562787219882e-01L, /* logirh[88] */ 
    2.71497198375317303100785063981453318980131866492304e-21L, /* logirl[88] */ 
  } , 
  { 
    1.17968750000000000000000000000000000000000000000000e+00L,   /* r[89] */ 
    -1.65249572895307162873914340328607153196571744047105e-01L, /* logirh[89] */ 
    -1.69710894863316053274660137780472619090744715377758e-21L, /* logirl[89] */ 
  } , 
  { 
    1.17382812500000000000000000000000000000000000000000e+00L,   /* r[90] */ 
    -1.60270309495699794511943195307601683907705591991544e-01L, /* logirh[90] */ 
    -6.04821814795533552862893869629633677033284792785115e-21L, /* logirl[90] */ 
  } , 
  { 
    1.16894531250000000000000000000000000000000000000000e+00L,   /* r[91] */ 
    -1.56101899958520053736952051814945718888338888064027e-01L, /* logirh[91] */ 
    4.40261722062672347380361273563329366574299418033041e-21L, /* logirl[91] */ 
  } , 
  { 
    1.16406250000000000000000000000000000000000000000000e+00L,   /* r[92] */ 
    -1.51916042025841975066048281095554273179004667326808e-01L, /* logirh[92] */ 
    -5.75514380133023814872665374682664797890000868696983e-21L, /* logirl[92] */ 
  } , 
  { 
    1.15820312500000000000000000000000000000000000000000e+00L,   /* r[93] */ 
    -1.46869773958217667795276076270205578566674375906587e-01L, /* logirh[93] */ 
    3.74542574364605198240110299363146340829881458953744e-21L, /* logirl[93] */ 
  } , 
  { 
    1.15332031250000000000000000000000000000000000000000e+00L,   /* r[94] */ 
    -1.42645010597909210864992976541820723923592595383525e-01L, /* logirh[94] */ 
    -1.49668764603399746810002277800399641956108986115277e-21L, /* logirl[94] */ 
  } , 
  { 
    1.14843750000000000000000000000000000000000000000000e+00L,   /* r[95] */ 
    -1.38402322859119135682777479434690803827834315598011e-01L, /* logirh[95] */ 
    -2.54839416695838356532650800861069791639429031347559e-21L, /* logirl[95] */ 
  } , 
  { 
    1.14257812500000000000000000000000000000000000000000e+00L,   /* r[96] */ 
    -1.33287222192348708683213263925804170639821677468717e-01L, /* logirh[96] */ 
    -6.43489158716437030647791169560962525141739108779860e-21L, /* logirl[96] */ 
  } , 
  { 
    1.13769531250000000000000000000000000000000000000000e+00L,   /* r[97] */ 
    -1.29004560400347845734790423743998388772524776868522e-01L, /* logirh[97] */ 
    4.12743043068895141295491814920903816740508819920186e-21L, /* logirl[97] */ 
  } , 
  { 
    1.13281250000000000000000000000000000000000000000000e+00L,   /* r[98] */ 
    -1.24703478500957235860374400920891346800090104807168e-01L, /* logirh[98] */ 
    -3.03211445997192169150157656625233654585699365130551e-21L, /* logirl[98] */ 
  } , 
  { 
    1.12792968750000000000000000000000000000000000000000e+00L,   /* r[99] */ 
    -1.20383817356440820990376872751115300275159825105220e-01L, /* logirh[99] */ 
    -6.02804224141392601725339572746961606433931174921632e-22L, /* logirl[99] */ 
  } , 
  { 
    1.12304687500000000000000000000000000000000000000000e+00L,   /* r[100] */ 
    -1.16045415757842655255155980137393711970617005135864e-01L, /* logirh[100] */ 
    1.97357499841142715648611745206675471003368015857707e-21L, /* logirl[100] */ 
  } , 
  { 
    1.11816406250000000000000000000000000000000000000000e+00L,   /* r[101] */ 
    -1.11688110388886928867871375231635155955700611229986e-01L, /* logirh[101] */ 
    -1.80234734539512005333983723608110499312624517402909e-21L, /* logirl[101] */ 
  } , 
  { 
    1.11328125000000000000000000000000000000000000000000e+00L,   /* r[102] */ 
    -1.07311735789088050666375585839862338843886391259730e-01L, /* logirh[102] */ 
    -7.99444531291997962572940662749597218537387594367069e-22L, /* logirl[102] */ 
  } , 
  { 
    1.10839843750000000000000000000000000000000000000000e+00L,   /* r[103] */ 
    -1.02916124316049955441049277432563613388083467725664e-01L, /* logirh[103] */ 
    -7.70418045355390537427085452827290090533981671198214e-22L, /* logirl[103] */ 
  } , 
  { 
    1.10351562500000000000000000000000000000000000000000e+00L,   /* r[104] */ 
    -9.85011061069331584304480803337966676735959481447935e-02L, /* logirh[104] */ 
    2.64634661517646879820354995203947987149684385342190e-21L, /* logirl[104] */ 
  } , 
  { 
    1.09863281250000000000000000000000000000000000000000e+00L,   /* r[105] */ 
    -9.40665090390674124196622452043214934747084043920040e-02L, /* logirh[105] */ 
    -7.85013737527153642092056782136336663408299656719499e-22L, /* logirl[105] */ 
  } , 
  { 
    1.09375000000000000000000000000000000000000000000000e+00L,   /* r[106] */ 
    -8.96121586896871326189772770376418264959283987991512e-02L, /* logirh[106] */ 
    -9.74192340842702289248316897714444315823596817643550e-22L, /* logirl[106] */ 
  } , 
  { 
    1.08984375000000000000000000000000000000000000000000e+00L,   /* r[107] */ 
    -8.60343373418031533820279736779479407005055691115558e-02L, /* logirh[107] */ 
    2.30146955951865559597249227413865587554269312860475e-22L, /* logirl[107] */ 
  } , 
  { 
    1.08496093750000000000000000000000000000000000000000e+00L,   /* r[108] */ 
    -8.15439840401769007739956988956020467185226152651012e-02L, /* logirh[108] */ 
    1.75068599249270760931371736454488137316032510066418e-22L, /* logirl[108] */ 
  } , 
  { 
    1.08007812500000000000000000000000000000000000000000e+00L,   /* r[109] */ 
    -7.70333764828270145253981751598537641712027834728360e-02L, /* logirh[109] */ 
    2.18898335885222504011340723675649479553611259830224e-21L, /* logirl[109] */ 
  } , 
  { 
    1.07519531250000000000000000000000000000000000000000e+00L,   /* r[110] */ 
    -7.25023311232268688402238278334355214838069514371455e-02L, /* logirh[110] */ 
    -2.13213366575366793826831658963525268068913415683098e-21L, /* logirl[110] */ 
  } , 
  { 
    1.07128906250000000000000000000000000000000000000000e+00L,   /* r[111] */ 
    -6.88626546757771517366978307472802356414831592701375e-02L, /* logirh[111] */ 
    -3.28324237603869825985548439776523090582575800369088e-22L, /* logirl[111] */ 
  } , 
  { 
    1.06640625000000000000000000000000000000000000000000e+00L,   /* r[112] */ 
    -6.42943507053972572172256989830874118752035428769886e-02L, /* logirh[112] */ 
    9.97248717475917389385548315283734311163209646118044e-22L, /* logirl[112] */ 
  } , 
  { 
    1.06250000000000000000000000000000000000000000000000e+00L,   /* r[113] */ 
    -6.06246218164348425809463336011440048878284869715571e-02L, /* logirh[113] */ 
    3.40201560723741601617729662632506532290642311489711e-22L, /* logirl[113] */ 
  } , 
  { 
    1.05761718750000000000000000000000000000000000000000e+00L,   /* r[114] */ 
    -5.60184414015375172410100661213316897146796691231430e-02L, /* logirh[114] */ 
    3.11800048645913474307950146912226463632967430723724e-23L, /* logirl[114] */ 
  } , 
  { 
    1.05371093750000000000000000000000000000000000000000e+00L,   /* r[115] */ 
    -5.23181596586815653583246027436004510491329710930586e-02L, /* logirh[115] */ 
    1.68615246867707396959723624602535685414462357313269e-21L, /* logirl[115] */ 
  } , 
  { 
    1.04882812500000000000000000000000000000000000000000e+00L,   /* r[116] */ 
    -4.76734694693569028189818886920292584363778587430716e-02L, /* logirh[116] */ 
    1.02131487169049086541356584124809714333053944625270e-21L, /* logirl[116] */ 
  } , 
  { 
    1.04492187500000000000000000000000000000000000000000e+00L,   /* r[117] */ 
    -4.39421218564987631503880941008510774281603517010808e-02L, /* logirh[117] */ 
    3.19036974975549018917247656911137538435844307015502e-22L, /* logirl[117] */ 
  } , 
  { 
    1.04101562500000000000000000000000000000000000000000e+00L,   /* r[118] */ 
    -4.01967991263367551645860776404761693925138388294727e-02L, /* logirh[118] */ 
    -5.75643838660911109663810221439950742515738641098385e-22L, /* logirl[118] */ 
  } , 
  { 
    1.03613281250000000000000000000000000000000000000000e+00L,   /* r[119] */ 
    -3.54953330145300408896490932525447092871218046639115e-02L, /* logirh[119] */ 
    9.92857944898394620246865383584341693120429858950945e-23L, /* logirl[119] */ 
  } , 
  { 
    1.03222656250000000000000000000000000000000000000000e+00L,   /* r[120] */ 
    -3.17181802707845397290716514537844972210223204456270e-02L, /* logirh[120] */ 
    -1.96176892105841918795869133037686185923113451571873e-22L, /* logirl[120] */ 
  } , 
  { 
    1.02832031250000000000000000000000000000000000000000e+00L,   /* r[121] */ 
    -2.79267065345224074627335925091742296899610664695501e-02L, /* logirh[121] */ 
    5.86417835518487049711934217680032678831410128853609e-22L, /* logirl[121] */ 
  } , 
  { 
    1.02441406250000000000000000000000000000000000000000e+00L,   /* r[122] */ 
    -2.41208027968440809158740456216718506254892417928204e-02L, /* logirh[122] */ 
    3.02985243973796148231999463903827273031077578359612e-22L, /* logirl[122] */ 
  } , 
  { 
    1.01953125000000000000000000000000000000000000000000e+00L,   /* r[123] */ 
    -1.93429628431309346365065977152442044939562038052827e-02L, /* logirh[123] */ 
    6.01063173693734308460897092397749141966269930081944e-22L, /* logirl[123] */ 
  } , 
  { 
    1.01562500000000000000000000000000000000000000000000e+00L,   /* r[124] */ 
    -1.55041865359652541508843977442755335260926585760899e-02L, /* logirh[124] */ 
    3.03517018286976482243336130818153212447067590236466e-23L, /* logirl[124] */ 
  } , 
  { 
    1.01171875000000000000000000000000000000000000000000e+00L,   /* r[125] */ 
    -1.16506172199752741354571356803548898284361712285317e-02L, /* logirh[125] */ 
    -1.34307128859459104723409399281441278120110731736138e-22L, /* logirl[125] */ 
  } , 
  { 
    1.00781250000000000000000000000000000000000000000000e+00L,   /* r[126] */ 
    -7.78214044205494894757658497566610300566480873385444e-03L, /* logirh[126] */ 
    1.13684914529339327537355164185463042556838581909991e-22L, /* logirl[126] */ 
  } , 
  { 
    1.00390625000000000000000000000000000000000000000000e+00L,   /* r[127] */ 
    -3.89864041565732301388162890642963276377486181445420e-03L, /* logirh[127] */ 
    -5.57141894132742469511718763808942289917039607877533e-23L, /* logirl[127] */ 
  } }; 
 
