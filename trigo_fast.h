#include "crlibm.h"
#include "crlibm_private.h"

/*File generated by maple/coef_sine.mw*/
#define XMAX_RETURN_X_FOR_SIN 0x3E500000
#define XMAX_SIN_FAST  0x3F800000
#define XMAX_SIN_FAST2 0x3FE00000
#define XMAX_RETURN_1_FOR_COS 0x3E400000
#define XMAX_COS_FAST  0x3F800000
#define XMAX_COS_FAST2 0x3FE00000

#define RN_CST_SINFAST1 1.000086 
#define RN_CST_SINFAST2 1.007843 
#define RN_CST_SINFAST3 1.000122 
#define RN_CST_COSFAST 1.000189 

#define INV_PIO256 81.48733086305041191366848684672735336164333861911370 

#define XMAX_CODY_WAITE_2 0x40E921FB
#define XMAX_CODY_WAITE_3 0x417921FB
#define XMAX_DDRR 0x42B921FB

#define RR_CW2_CH 1.22718463026103563606739044189453125000000000000000e-02
#define RR_CW2_MCL -4.74773477070796269478059194651439932290289125393912e-13

#define RR_CW3_CH 1.22718438506126403808593750000000000000000000000000e-02
#define RR_CW3_CM 2.45247377961277379654347896575927734375000000000000e-09
#define RR_CW3_MCL 1.29015588847082744546238189049062829921108970857024e-15

#define RR_DD_MCH -1.22718463030851293593670447990007232874631881713867e-02
#define RR_DD_MCM -4.78377655916934846552251574007186173681910986202180e-19
#define RR_DD_CL -1.16983195692122643198711576336405625652558630950744e-35

#define RN_CST_SINCOS 1.020210 

#ifdef WORDS_BIGENDIAN
static db_number const s3 = {{0xBFC55555,0x55555555}} /* -1.6666666667e-01 */;
static db_number const s5 = {{0x3F811111,0x11111111}} /* +8.3333333333e-03 */;
static db_number const s7 = {{0xBF2A01A0,0x1A01A01A}} /* -1.9841269841e-04 */;

static db_number const c2 = {{0xBFE00000,0x00000000}} /* -5.0000000000e-01 */;
static db_number const c4 = {{0x3FA55555,0x55555555}} /* +4.1666666667e-02 */;
static db_number const c6 = {{0xBF56C16C,0x16C16C17}} /* -1.3888888889e-03 */;




/*  sine and cos of kPi/256 in double-double */
static db_number const sincosTable[260] =
{
{{0x00000000,0x00000000}} /* +0.0000000000e+00 */ ,
{{0x00000000,0x00000000}} /* +0.0000000000e+00 */ ,
{{0x3FF00000,0x00000000}} /* +1.0000000000e+00 */ ,
{{0x00000000,0x00000000}} /* +0.0000000000e+00 */ ,
{{0x3F8921D1,0xFCDEC784}} /* +1.2271538286e-02 */ ,
{{0x3C29878E,0xBE836D9D}} /* +6.9197907640e-19 */ ,
{{0x3FEFFF62,0x169B92DB}} /* +9.9992470184e-01 */ ,
{{0x3C85DDA3,0xC81FBD0D}} /* +3.7931082513e-17 */ ,
{{0x3F992155,0xF7A3667E}} /* +2.4541228523e-02 */ ,
{{0xBBFB1D63,0x091A0130}} /* -9.1868490126e-20 */ ,
{{0x3FEFFD88,0x6084CD0D}} /* +9.9969881870e-01 */ ,
{{0xBC81354D,0x4556E4CB}} /* -2.9851486404e-17 */ ,
{{0x3FA2D865,0x759455CD}} /* +3.6807222941e-02 */ ,
{{0x3C2686F6,0x5BA93AC0}} /* +6.1060088804e-19 */ ,
{{0x3FEFFA72,0xEFFEF75D}} /* +9.9932238459e-01 */ ,
{{0xBC88B4CD,0xCDB25956}} /* -4.2858538441e-17 */ ,
{{0x3FA91F65,0xF10DD814}} /* +4.9067674327e-02 */ ,
{{0xBC2912BD,0x0D569A90}} /* -6.7961037205e-19 */ ,
{{0x3FEFF621,0xE3796D7E}} /* +9.9879545621e-01 */ ,
{{0xBC6C57BC,0x2E24AA15}} /* -1.2291693337e-17 */ ,
{{0x3FAF656E,0x79F820E0}} /* +6.1320736302e-02 */ ,
{{0xBC22E1EB,0xE392BFFE}} /* -5.1181134065e-19 */ ,
{{0x3FEFF095,0x658E71AD}} /* +9.9811811290e-01 */ ,
{{0x3C801A8C,0xE18A4B9E}} /* +2.7935487558e-17 */ ,
{{0x3FB2D520,0x92CE19F6}} /* +7.3564563600e-02 */ ,
{{0xBC49A088,0xA8BF6B2C}} /* -2.7784941506e-18 */ ,
{{0x3FEFE9CD,0xAD01883A}} /* +9.9729045668e-01 */ ,
{{0x3C6521EC,0xD0C67E35}} /* +9.1647695371e-18 */ ,
{{0x3FB5F6D0,0x0A9AA419}} /* +8.5797312344e-02 */ ,
{{0xBC4F4022,0xD03F6C9A}} /* -3.3881893831e-18 */ ,
{{0x3FEFE1CA,0xFCBD5B09}} /* +9.9631261218e-01 */ ,
{{0x3C6A23E3,0x202A884E}} /* +1.1336497892e-17 */ ,
{{0x3FB917A6,0xBC29B42C}} /* +9.8017140330e-02 */ ,
{{0xBC3E2718,0xD26ED688}} /* -1.6345823622e-18 */ ,
{{0x3FEFD88D,0xA3D12526}} /* +9.9518472667e-01 */ ,
{{0xBC887DF6,0x378811C7}} /* -4.2486913678e-17 */ ,
{{0x3FBC3785,0xC79EC2D5}} /* +1.1022220729e-01 */ ,
{{0xBC24F39D,0xF133FB21}} /* -5.6789503538e-19 */ ,
{{0x3FEFCE15,0xFD6DA67B}} /* +9.9390697000e-01 */ ,
{{0xBC75DD6F,0x830D4C09}} /* -1.8964849471e-17 */ ,
{{0x3FBF564E,0x56A9730E}} /* +1.2241067520e-01 */ ,
{{0x3C4A2704,0x729AE56D}} /* +2.8354501490e-18 */ ,
{{0x3FEFC264,0x70E19FD3}} /* +9.9247953460e-01 */ ,
{{0x3C81EC86,0x68ECACEE}} /* +3.1093055095e-17 */ ,
{{0x3FC139F0,0xCEDAF577}} /* +1.3458070851e-01 */ ,
{{0xBC652343,0x4D1B3CFA}} /* -9.1670359171e-18 */ ,
{{0x3FEFB579,0x7195D741}} /* +9.9090263543e-01 */ ,
{{0x3C71BFAC,0x7397CC08}} /* +1.5394565095e-17 */ ,
{{0x3FC2C810,0x6E8E613A}} /* +1.4673047446e-01 */ ,
{{0x3C513000,0xA89A11E0}} /* +3.7269471470e-18 */ ,
{{0x3FEFA755,0x7F08A517}} /* +9.8917650996e-01 */ ,
{{0xBC87A0A8,0xCA13571F}} /* -4.0987309937e-17 */ ,
{{0x3FC45576,0xB1293E5A}} /* +1.5885814333e-01 */ ,
{{0xBC5285A2,0x4119F7B1}} /* -4.0163200574e-18 */ ,
{{0x3FEF97F9,0x24C9099B}} /* +9.8730141816e-01 */ ,
{{0xBC8E2AE0,0xEEA5963B}} /* -5.2332261256e-17 */ ,
{{0x3FC5E214,0x448B3FC6}} /* +1.7096188876e-01 */ ,
{{0x3C6531FF,0x779DDAC6}} /* +9.1919980182e-18 */ ,
{{0x3FEF8764,0xFA714BA9}} /* +9.8527764239e-01 */ ,
{{0x3C7AB256,0x778FFCB6}} /* +2.3155637028e-17 */ ,
{{0x3FC76DD9,0xDE50BF31}} /* +1.8303988796e-01 */ ,
{{0x3C61D5EE,0xEC501B2F}} /* +7.7349918689e-18 */ ,
{{0x3FEF7599,0xA3A12077}} /* +9.8310548743e-01 */ ,
{{0x3C884F31,0xD743195C}} /* +4.2170007523e-17 */ ,
{{0x3FC8F8B8,0x3C69A60B}} /* +1.9509032202e-01 */ ,
{{0xBC626D19,0xB9FF8D82}} /* -7.9910790685e-18 */ ,
{{0x3FEF6297,0xCFF75CB0}} /* +9.8078528040e-01 */ ,
{{0x3C756217,0x2A361FD3}} /* +1.8546939998e-17 */ ,
{{0x3FCA82A0,0x25B00451}} /* +2.0711137619e-01 */ ,
{{0xBC687905,0xFFD084AD}} /* -1.0613362529e-17 */ ,
{{0x3FEF4E60,0x3B0B2F2D}} /* +9.7831737072e-01 */ ,
{{0xBC78EE01,0xE695AC05}} /* -2.1623082233e-17 */ ,
{{0x3FCC0B82,0x6A7E4F63}} /* +2.1910124016e-01 */ ,
{{0xBC1AF143,0x9E521935}} /* -3.6513812299e-19 */ ,
{{0x3FEF38F3,0xAC64E589}} /* +9.7570213004e-01 */ ,
{{0xBC7D7BAF,0xB51F72E6}} /* -2.5572556081e-17 */ ,
{{0x3FCD934F,0xE5454311}} /* +2.3105810828e-01 */ ,
{{0x3C675B92,0x277107AD}} /* +1.0129787150e-17 */ ,
{{0x3FEF2252,0xF7763ADA}} /* +9.7293995221e-01 */ ,
{{0xBC820CB8,0x1C8D94AB}} /* -3.1311211122e-17 */ ,
{{0x3FCF19F9,0x7B215F1B}} /* +2.4298017990e-01 */ ,
{{0xBC642DEE,0xF11DA2C4}} /* -8.7514315297e-18 */ ,
{{0x3FEF0A7E,0xFB9230D7}} /* +9.7003125319e-01 */ ,
{{0x3C752C7A,0xDC6B4989}} /* +1.8365300348e-17 */ ,
{{0x3FD04FB8,0x0E37FDAE}} /* +2.5486565960e-01 */ ,
{{0xBC0412CD,0xB72583CC}} /* -1.3602299807e-19 */ ,
{{0x3FEEF178,0xA3E473C2}} /* +9.6697647104e-01 */ ,
{{0x3C86310A,0x67FE774F}} /* +3.8496228837e-17 */ ,
{{0x3FD111D2,0x62B1F677}} /* +2.6671275747e-01 */ ,
{{0x3C7824C2,0x0AB7AA9A}} /* +2.0941222579e-17 */ ,
{{0x3FEED740,0xE7684963}} /* +9.6377606580e-01 */ ,
{{0x3C7E82C7,0x91F59CC2}} /* +2.6463950561e-17 */ ,
{{0x3FD1D344,0x3F4CDB3E}} /* +2.7851968938e-01 */ ,
{{0xBC6720D4,0x1C13519E}} /* -1.0030273720e-17 */ ,
{{0x3FEEBBD8,0xC8DF0B74}} /* +9.6043051942e-01 */ ,
{{0x3C7C6C8C,0x615E7277}} /* +2.4653904815e-17 */ ,
{{0x3FD29406,0x2ED59F06}} /* +2.9028467725e-01 */ ,
{{0xBC75D28D,0xA2C4612D}} /* -1.8927978708e-17 */ ,
{{0x3FEE9F41,0x56C62DDA}} /* +9.5694033573e-01 */ ,
{{0x3C8760B1,0xE2E3F81E}} /* +4.0553869862e-17 */ ,
{{0x3FD35410,0xC2E18152}} /* +3.0200594932e-01 */ ,
{{0xBC73CB00,0x2F96E062}} /* -1.7167666235e-17 */ ,
{{0x3FEE817B,0xAB4CD10D}} /* +9.5330604035e-01 */ ,
{{0xBC7D0AFE,0x686B5E0A}} /* -2.5190738780e-17 */ ,
{{0x3FD4135C,0x94176601}} /* +3.1368174040e-01 */ ,
{{0x3C70C97C,0x4AFA2518}} /* +1.4560447300e-17 */ ,
{{0x3FEE6288,0xEC48E112}} /* +9.4952818059e-01 */ ,
{{0xBC616B56,0xF2847754}} /* -7.5544151928e-18 */ ,
{{0x3FD4D1E2,0x4278E76A}} /* +3.2531029216e-01 */ ,
{{0x3C624172,0x18792858}} /* +7.9171249464e-18 */ ,
{{0x3FEE426A,0x4B2BC17E}} /* +9.4560732538e-01 */ ,
{{0x3C8A8738,0x89744882}} /* +4.6019102479e-17 */ ,
{{0x3FD58F9A,0x75AB1FDD}} /* +3.3688985339e-01 */ ,
{{0xBC1EFDC0,0xD58CF620}} /* -4.2000940033e-19 */ ,
{{0x3FEE2121,0x04F686E5}} /* +9.4154406518e-01 */ ,
{{0xBC8014C7,0x6C126527}} /* -2.7896379548e-17 */ ,
{{0x3FD64C7D,0xDD3F27C6}} /* +3.4841868025e-01 */ ,
{{0x3C510D2B,0x4A664121}} /* +3.6974420514e-18 */ ,
{{0x3FEDFEAE,0x622DBE2B}} /* +9.3733901191e-01 */ ,
{{0xBC8514EA,0x88425567}} /* -3.6570926284e-17 */ ,
{{0x3FD70885,0x30FA459F}} /* +3.5989503653e-01 */ ,
{{0xBC744B19,0xE0864C5D}} /* -1.7601687124e-17 */ ,
{{0x3FEDDB13,0xB6CCC23C}} /* +9.3299279883e-01 */ ,
{{0x3C883C37,0xC6107DB3}} /* +4.2041415555e-17 */ ,
{{0x3FD7C3A9,0x311DCCE7}} /* +3.7131719395e-01 */ ,
{{0x3C19A3F2,0x1EF3E8D9}} /* +3.4749239648e-19 */ ,
{{0x3FEDB652,0x6238A09B}} /* +9.2850608047e-01 */ ,
{{0xBC7ADEE7,0xEAE69460}} /* -2.3306639848e-17 */ ,
{{0x3FD87DE2,0xA6AEA963}} /* +3.8268343236e-01 */ ,
{{0xBC672CED,0xD3D5A610}} /* -1.0050772696e-17 */ ,
{{0x3FED906B,0xCF328D46}} /* +9.2387953251e-01 */ ,
{{0x3C7457E6,0x10231AC2}} /* +1.7645047084e-17 */ ,
{{0x3FD9372A,0x63BC93D7}} /* +3.9399204006e-01 */ ,
{{0x3C668431,0x9E5AD5B1}} /* +9.7649241641e-18 */ ,
{{0x3FED6961,0x73C9E68B}} /* +9.1911385169e-01 */ ,
{{0xBC7E8C61,0xC6393D55}} /* -2.6496484622e-17 */ ,
{{0x3FD9EF79,0x43A8ED8A}} /* +4.0524131400e-01 */ ,
{{0x3C66DA81,0x290BDBAB}} /* +9.9111401943e-18 */ ,
{{0x3FED4134,0xD14DC93A}} /* +9.1420975570e-01 */ ,
{{0xBC84EF52,0x95D25AF2}} /* -3.6316182528e-17 */ ,
{{0x3FDAA6C8,0x2B6D3FCA}} /* +4.1642956010e-01 */ ,
{{0xBC7D5F10,0x6EE5CCF7}} /* -2.5475580413e-17 */ ,
{{0x3FED17E7,0x743E35DC}} /* +9.0916798309e-01 */ ,
{{0xBC5101DA,0x3540130A}} /* -3.6878564091e-18 */ ,
{{0x3FDB5D10,0x09E15CC0}} /* +4.2755509343e-01 */ ,
{{0x3C65B362,0xCB974183}} /* +9.4111898163e-18 */ ,
{{0x3FECED7A,0xF43CC773}} /* +9.0398929312e-01 */ ,
{{0xBC5E7B6B,0xB5AB58AE}} /* -6.6097544687e-18 */ ,
{{0x3FDC1249,0xD8011EE7}} /* +4.3861623854e-01 */ ,
{{0xBC7813AA,0xBB515206}} /* -2.0883315831e-17 */ ,
{{0x3FECC1F0,0xF3FCFC5C}} /* +8.9867446569e-01 */ ,
{{0x3C7E5761,0x3B68F6AB}} /* +2.6316906461e-17 */ ,
{{0x3FDCC66E,0x9931C45E}} /* +4.4961132965e-01 */ ,
{{0x3C56850E,0x59C37F8F}} /* +4.8831924232e-18 */ ,
{{0x3FEC954B,0x213411F5}} /* +8.9322430120e-01 */ ,
{{0xBC52FB76,0x1E946603}} /* -4.1161239152e-18 */ ,
{{0x3FDD7977,0x5B86E389}} /* +4.6053871096e-01 */ ,
{{0x3C7550EC,0x87BC0575}} /* +1.8488777492e-17 */ ,
{{0x3FEC678B,0x3488739B}} /* +8.8763962040e-01 */ ,
{{0x3C6D86CA,0xC7C5FF5B}} /* +1.2805091919e-17 */ ,
{{0x3FDE2B5D,0x3806F63B}} /* +4.7139673683e-01 */ ,
{{0x3C5E0D89,0x1D3C6841}} /* +6.5166781361e-18 */ ,
{{0x3FEC38B2,0xF180BDB1}} /* +8.8192126435e-01 */ ,
{{0xBC76E0B1,0x757C8D07}} /* -1.9843248406e-17 */ ,
{{0x3FDEDC19,0x52EF78D6}} /* +4.8218377208e-01 */ ,
{{0xBC7DD0F7,0xC33EDEE6}} /* -2.5861500926e-17 */ ,
{{0x3FEC08C4,0x26725549}} /* +8.7607009420e-01 */ ,
{{0x3C5B157F,0xD80E2946}} /* +5.8729024235e-18 */ ,
{{0x3FDF8BA4,0xDBF89ABA}} /* +4.9289819223e-01 */ ,
{{0xBC32EC1F,0xC1B776B8}} /* -1.0257831677e-18 */ ,
{{0x3FEBD7C0,0xAC6F952A}} /* +8.7008699111e-01 */ ,
{{0xBC8825A7,0x32AC700A}} /* -4.1888510869e-17 */ ,
{{0x3FE01CFC,0x874C3EB7}} /* +5.0353838373e-01 */ ,
{{0xBC734A35,0xE7C2368C}} /* -1.6731308205e-17 */ ,
{{0x3FEBA5AA,0x673590D2}} /* +8.6397285612e-01 */ ,
{{0x3C87EA4E,0x370753B6}} /* +4.1486355957e-17 */ ,
{{0x3FE07387,0x9922FFEE}} /* +5.1410274419e-01 */ ,
{{0xBC8A5A01,0x4347406C}} /* -4.5712707524e-17 */ ,
{{0x3FEB7283,0x45196E3E}} /* +8.5772861000e-01 */ ,
{{0xBC8BC69F,0x324E6D61}} /* -4.8183447936e-17 */ ,
{{0x3FE0C970,0x4D5D898F}} /* +5.2458968268e-01 */ ,
{{0xBC88D3D7,0xDE6EE9B2}} /* -4.3068869040e-17 */ ,
{{0x3FEB3E4D,0x3EF55712}} /* +8.5135519311e-01 */ ,
{{0xBC8EB6B8,0xBF11A493}} /* -5.3279874446e-17 */ ,
{{0x3FE11EB3,0x541B4B23}} /* +5.3499761989e-01 */ ,
{{0xBC8EF23B,0x69ABE4F1}} /* -5.3683132708e-17 */ ,
{{0x3FEB090A,0x58150200}} /* +8.4485356525e-01 */ ,
{{0xBC8926DA,0x300FFCCE}} /* -4.3631360297e-17 */ ,
{{0x3FE1734D,0x63DEDB49}} /* +5.4532498842e-01 */ ,
{{0xBC87EEF2,0xCCC50575}} /* -4.1517817538e-17 */ ,
{{0x3FEAD2BC,0x9E21D511}} /* +8.3822470555e-01 */ ,
{{0xBC847FBE,0x07BEA548}} /* -3.5560085053e-17 */ ,
{{0x3FE1C73B,0x39AE68C8}} /* +5.5557023302e-01 */ ,
{{0x3C8B25DD,0x267F6600}} /* +4.7094109406e-17 */ ,
{{0x3FEA9B66,0x290EA1A3}} /* +8.3146961230e-01 */ ,
{{0x3C39F630,0xE8B6DAC8}} /* +1.4073856985e-18 */ ,
{{0x3FE21A79,0x9933EB59}} /* +5.6573181078e-01 */ ,
{{0xBC83A7B1,0x77C68FB2}} /* -3.4096079597e-17 */ ,
{{0x3FEA6309,0x1B02FAE2}} /* +8.2458930278e-01 */ ,
{{0xBC7E9111,0x52248D10}} /* -2.6512360489e-17 */ ,
{{0x3FE26D05,0x4CDD12DF}} /* +5.7580819142e-01 */ ,
{{0xBC85DA74,0x3EF3770C}} /* -3.7909495459e-17 */ ,
{{0x3FEA29A7,0xA0462782}} /* +8.1758481315e-01 */ ,
{{0xBC7128BB,0x015DF175}} /* -1.4883149812e-17 */ ,
{{0x3FE2BEDB,0x25FAF3EA}} /* +5.8579785746e-01 */ ,
{{0xBC514981,0xC796EE46}} /* -3.7485501964e-18 */ ,
{{0x3FE9EF43,0xEF29AF94}} /* +8.1045719825e-01 */ ,
{{0x3C7B1DFC,0xB60445C2}} /* +2.3520367350e-17 */ ,
{{0x3FE30FF7,0xFCE17035}} /* +5.9569930449e-01 */ ,
{{0xBC6EFCC6,0x26F74A6F}} /* -1.3438641937e-17 */ ,
{{0x3FE9B3E0,0x47F38741}} /* +8.0320753148e-01 */ ,
{{0xBC830EE2,0x86712474}} /* -3.3060609805e-17 */ ,
{{0x3FE36058,0xB10659F3}} /* +6.0551104140e-01 */ ,
{{0xBC81FCB3,0xA35857E7}} /* -3.1202672493e-17 */ ,
{{0x3FE9777E,0xF4C7D742}} /* +7.9583690461e-01 */ ,
{{0xBC815479,0xA240665E}} /* -3.0062724852e-17 */ ,
{{0x3FE3AFFA,0x292050B9}} /* +6.1523159058e-01 */ ,
{{0x3C7E3E25,0xE3954964}} /* +2.6231417767e-17 */ ,
{{0x3FE93A22,0x499263FB}} /* +7.8834642763e-01 */ ,
{{0x3C83D419,0xA920DF0B}} /* +3.4396993154e-17 */ ,
{{0x3FE3FED9,0x534556D4}} /* +6.2485948814e-01 */ ,
{{0x3C836916,0x608C5061}} /* +3.3671846037e-17 */ ,
{{0x3FE8FBCC,0xA3EF940D}} /* +7.8073722857e-01 */ ,
{{0xBC66DFA9,0x9C86F2F1}} /* -9.9198782067e-18 */ ,
{{0x3FE44CF3,0x25091DD6}} /* +6.3439328416e-01 */ ,
{{0x3C68076A,0x2CFDC6B3}} /* +1.0420901929e-17 */ ,
{{0x3FE8BC80,0x6B151741}} /* +7.7301045336e-01 */ ,
{{0xBC82C5E1,0x2ED1336D}} /* -3.2565907034e-17 */ ,
{{0x3FE49A44,0x9B9B0939}} /* +6.4383154289e-01 */ ,
{{0xBC827EE1,0x6D719B94}} /* -3.2084798795e-17 */ ,
{{0x3FE87C40,0x0FBA2EBF}} /* +7.6516726562e-01 */ ,
{{0xBC82DABC,0x0C3F64CD}} /* -3.2707225613e-17 */ ,
{{0x3FE4E6CA,0xBBE3E5E9}} /* +6.5317284295e-01 */ ,
{{0x3C63C293,0xEDCEB327}} /* +8.5695642060e-18 */ ,
{{0x3FE83B0E,0x0BFF976E}} /* +7.5720884651e-01 */ ,
{{0xBC76F420,0xF8EA3475}} /* -1.9909098777e-17 */ ,
{{0x3FE53282,0x92A35596}} /* +6.6241577759e-01 */ ,
{{0xBC7A12EB,0x89DA0257}} /* -2.2615508886e-17 */ ,
{{0x3FE7F8EC,0xE3571771}} /* +7.4913639452e-01 */ ,
{{0xBC89C8D8,0xCE93C917}} /* -4.4729078447e-17 */ ,
{{0x3FE57D69,0x348CECA0}} /* +6.7155895485e-01 */ ,
{{0xBC875720,0x992BFBB2}} /* -4.0489037749e-17 */ ,
{{0x3FE7B5DF,0x226AAFAF}} /* +7.4095112535e-01 */ ,
{{0xBC70F537,0xACDF0AD7}} /* -1.4708616952e-17 */ ,
{{0x3FE5C77B,0xBE65018C}} /* +6.8060099780e-01 */ ,
{{0x3C8069EA,0x9C0BC32A}} /* +2.8473293355e-17 */ ,
{{0x3FE771E7,0x5F037261}} /* +7.3265427167e-01 */ ,
{{0x3C75CFCE,0x8D84068F}} /* +1.8918673482e-17 */ ,
{{0x3FE610B7,0x551D2CDF}} /* +6.8954054474e-01 */ ,
{{0xBC7251B3,0x52FF2A37}} /* -1.5889323295e-17 */ ,
{{0x3FE72D08,0x37EFFF96}} /* +7.2424708295e-01 */ ,
{{0x3C80D4EF,0x0F1D915C}} /* +2.9198471334e-17 */ ,
{{0x3FE65919,0x25F0783D}} /* +6.9837624941e-01 */ ,
{{0x3C8C3D64,0xFBF5DE23}} /* +4.8988282436e-17 */ ,
{{0x3FE6E744,0x54EAA8AF}} /* +7.1573082528e-01 */ ,
{{0xBC8DBC03,0xC84E226E}} /* -5.1581018476e-17 */ ,
{{0x3FE6A09E,0x667F3BCD}} /* +7.0710678119e-01 */ ,
{{0xBC8BDD34,0x13B26456}} /* -4.8336466567e-17 */ ,
{{0x3FE6A09E,0x667F3BCD}} /* +7.0710678119e-01 */ ,
{{0xBC8BDD34,0x13B26456}} /* -4.8336466567e-17 */ ,

};

#else
static db_number const s3 = {{0x55555555,0xBFC55555}} /* -1.6666666667e-01 */;
static db_number const s5 = {{0x11111111,0x3F811111}} /* +8.3333333333e-03 */;
static db_number const s7 = {{0x1A01A01A,0xBF2A01A0}} /* -1.9841269841e-04 */;

static db_number const c2 = {{0x00000000,0xBFE00000}} /* -5.0000000000e-01 */;
static db_number const c4 = {{0x55555555,0x3FA55555}} /* +4.1666666667e-02 */;
static db_number const c6 = {{0x16C16C17,0xBF56C16C}} /* -1.3888888889e-03 */;




/*  sine and cos of kPi/256 in double-double */
static db_number const sincosTable[260] =
{
{{0x00000000,0x00000000}} /* +0.0000000000e+00 */ ,
{{0x00000000,0x00000000}} /* +0.0000000000e+00 */ ,
{{0x00000000,0x3FF00000}} /* +1.0000000000e+00 */ ,
{{0x00000000,0x00000000}} /* +0.0000000000e+00 */ ,
{{0xFCDEC784,0x3F8921D1}} /* +1.2271538286e-02 */ ,
{{0xBE836D9D,0x3C29878E}} /* +6.9197907640e-19 */ ,
{{0x169B92DB,0x3FEFFF62}} /* +9.9992470184e-01 */ ,
{{0xC81FBD0D,0x3C85DDA3}} /* +3.7931082513e-17 */ ,
{{0xF7A3667E,0x3F992155}} /* +2.4541228523e-02 */ ,
{{0x091A0130,0xBBFB1D63}} /* -9.1868490126e-20 */ ,
{{0x6084CD0D,0x3FEFFD88}} /* +9.9969881870e-01 */ ,
{{0x4556E4CB,0xBC81354D}} /* -2.9851486404e-17 */ ,
{{0x759455CD,0x3FA2D865}} /* +3.6807222941e-02 */ ,
{{0x5BA93AC0,0x3C2686F6}} /* +6.1060088804e-19 */ ,
{{0xEFFEF75D,0x3FEFFA72}} /* +9.9932238459e-01 */ ,
{{0xCDB25956,0xBC88B4CD}} /* -4.2858538441e-17 */ ,
{{0xF10DD814,0x3FA91F65}} /* +4.9067674327e-02 */ ,
{{0x0D569A90,0xBC2912BD}} /* -6.7961037205e-19 */ ,
{{0xE3796D7E,0x3FEFF621}} /* +9.9879545621e-01 */ ,
{{0x2E24AA15,0xBC6C57BC}} /* -1.2291693337e-17 */ ,
{{0x79F820E0,0x3FAF656E}} /* +6.1320736302e-02 */ ,
{{0xE392BFFE,0xBC22E1EB}} /* -5.1181134065e-19 */ ,
{{0x658E71AD,0x3FEFF095}} /* +9.9811811290e-01 */ ,
{{0xE18A4B9E,0x3C801A8C}} /* +2.7935487558e-17 */ ,
{{0x92CE19F6,0x3FB2D520}} /* +7.3564563600e-02 */ ,
{{0xA8BF6B2C,0xBC49A088}} /* -2.7784941506e-18 */ ,
{{0xAD01883A,0x3FEFE9CD}} /* +9.9729045668e-01 */ ,
{{0xD0C67E35,0x3C6521EC}} /* +9.1647695371e-18 */ ,
{{0x0A9AA419,0x3FB5F6D0}} /* +8.5797312344e-02 */ ,
{{0xD03F6C9A,0xBC4F4022}} /* -3.3881893831e-18 */ ,
{{0xFCBD5B09,0x3FEFE1CA}} /* +9.9631261218e-01 */ ,
{{0x202A884E,0x3C6A23E3}} /* +1.1336497892e-17 */ ,
{{0xBC29B42C,0x3FB917A6}} /* +9.8017140330e-02 */ ,
{{0xD26ED688,0xBC3E2718}} /* -1.6345823622e-18 */ ,
{{0xA3D12526,0x3FEFD88D}} /* +9.9518472667e-01 */ ,
{{0x378811C7,0xBC887DF6}} /* -4.2486913678e-17 */ ,
{{0xC79EC2D5,0x3FBC3785}} /* +1.1022220729e-01 */ ,
{{0xF133FB21,0xBC24F39D}} /* -5.6789503538e-19 */ ,
{{0xFD6DA67B,0x3FEFCE15}} /* +9.9390697000e-01 */ ,
{{0x830D4C09,0xBC75DD6F}} /* -1.8964849471e-17 */ ,
{{0x56A9730E,0x3FBF564E}} /* +1.2241067520e-01 */ ,
{{0x729AE56D,0x3C4A2704}} /* +2.8354501490e-18 */ ,
{{0x70E19FD3,0x3FEFC264}} /* +9.9247953460e-01 */ ,
{{0x68ECACEE,0x3C81EC86}} /* +3.1093055095e-17 */ ,
{{0xCEDAF577,0x3FC139F0}} /* +1.3458070851e-01 */ ,
{{0x4D1B3CFA,0xBC652343}} /* -9.1670359171e-18 */ ,
{{0x7195D741,0x3FEFB579}} /* +9.9090263543e-01 */ ,
{{0x7397CC08,0x3C71BFAC}} /* +1.5394565095e-17 */ ,
{{0x6E8E613A,0x3FC2C810}} /* +1.4673047446e-01 */ ,
{{0xA89A11E0,0x3C513000}} /* +3.7269471470e-18 */ ,
{{0x7F08A517,0x3FEFA755}} /* +9.8917650996e-01 */ ,
{{0xCA13571F,0xBC87A0A8}} /* -4.0987309937e-17 */ ,
{{0xB1293E5A,0x3FC45576}} /* +1.5885814333e-01 */ ,
{{0x4119F7B1,0xBC5285A2}} /* -4.0163200574e-18 */ ,
{{0x24C9099B,0x3FEF97F9}} /* +9.8730141816e-01 */ ,
{{0xEEA5963B,0xBC8E2AE0}} /* -5.2332261256e-17 */ ,
{{0x448B3FC6,0x3FC5E214}} /* +1.7096188876e-01 */ ,
{{0x779DDAC6,0x3C6531FF}} /* +9.1919980182e-18 */ ,
{{0xFA714BA9,0x3FEF8764}} /* +9.8527764239e-01 */ ,
{{0x778FFCB6,0x3C7AB256}} /* +2.3155637028e-17 */ ,
{{0xDE50BF31,0x3FC76DD9}} /* +1.8303988796e-01 */ ,
{{0xEC501B2F,0x3C61D5EE}} /* +7.7349918689e-18 */ ,
{{0xA3A12077,0x3FEF7599}} /* +9.8310548743e-01 */ ,
{{0xD743195C,0x3C884F31}} /* +4.2170007523e-17 */ ,
{{0x3C69A60B,0x3FC8F8B8}} /* +1.9509032202e-01 */ ,
{{0xB9FF8D82,0xBC626D19}} /* -7.9910790685e-18 */ ,
{{0xCFF75CB0,0x3FEF6297}} /* +9.8078528040e-01 */ ,
{{0x2A361FD3,0x3C756217}} /* +1.8546939998e-17 */ ,
{{0x25B00451,0x3FCA82A0}} /* +2.0711137619e-01 */ ,
{{0xFFD084AD,0xBC687905}} /* -1.0613362529e-17 */ ,
{{0x3B0B2F2D,0x3FEF4E60}} /* +9.7831737072e-01 */ ,
{{0xE695AC05,0xBC78EE01}} /* -2.1623082233e-17 */ ,
{{0x6A7E4F63,0x3FCC0B82}} /* +2.1910124016e-01 */ ,
{{0x9E521935,0xBC1AF143}} /* -3.6513812299e-19 */ ,
{{0xAC64E589,0x3FEF38F3}} /* +9.7570213004e-01 */ ,
{{0xB51F72E6,0xBC7D7BAF}} /* -2.5572556081e-17 */ ,
{{0xE5454311,0x3FCD934F}} /* +2.3105810828e-01 */ ,
{{0x277107AD,0x3C675B92}} /* +1.0129787150e-17 */ ,
{{0xF7763ADA,0x3FEF2252}} /* +9.7293995221e-01 */ ,
{{0x1C8D94AB,0xBC820CB8}} /* -3.1311211122e-17 */ ,
{{0x7B215F1B,0x3FCF19F9}} /* +2.4298017990e-01 */ ,
{{0xF11DA2C4,0xBC642DEE}} /* -8.7514315297e-18 */ ,
{{0xFB9230D7,0x3FEF0A7E}} /* +9.7003125319e-01 */ ,
{{0xDC6B4989,0x3C752C7A}} /* +1.8365300348e-17 */ ,
{{0x0E37FDAE,0x3FD04FB8}} /* +2.5486565960e-01 */ ,
{{0xB72583CC,0xBC0412CD}} /* -1.3602299807e-19 */ ,
{{0xA3E473C2,0x3FEEF178}} /* +9.6697647104e-01 */ ,
{{0x67FE774F,0x3C86310A}} /* +3.8496228837e-17 */ ,
{{0x62B1F677,0x3FD111D2}} /* +2.6671275747e-01 */ ,
{{0x0AB7AA9A,0x3C7824C2}} /* +2.0941222579e-17 */ ,
{{0xE7684963,0x3FEED740}} /* +9.6377606580e-01 */ ,
{{0x91F59CC2,0x3C7E82C7}} /* +2.6463950561e-17 */ ,
{{0x3F4CDB3E,0x3FD1D344}} /* +2.7851968938e-01 */ ,
{{0x1C13519E,0xBC6720D4}} /* -1.0030273720e-17 */ ,
{{0xC8DF0B74,0x3FEEBBD8}} /* +9.6043051942e-01 */ ,
{{0x615E7277,0x3C7C6C8C}} /* +2.4653904815e-17 */ ,
{{0x2ED59F06,0x3FD29406}} /* +2.9028467725e-01 */ ,
{{0xA2C4612D,0xBC75D28D}} /* -1.8927978708e-17 */ ,
{{0x56C62DDA,0x3FEE9F41}} /* +9.5694033573e-01 */ ,
{{0xE2E3F81E,0x3C8760B1}} /* +4.0553869862e-17 */ ,
{{0xC2E18152,0x3FD35410}} /* +3.0200594932e-01 */ ,
{{0x2F96E062,0xBC73CB00}} /* -1.7167666235e-17 */ ,
{{0xAB4CD10D,0x3FEE817B}} /* +9.5330604035e-01 */ ,
{{0x686B5E0A,0xBC7D0AFE}} /* -2.5190738780e-17 */ ,
{{0x94176601,0x3FD4135C}} /* +3.1368174040e-01 */ ,
{{0x4AFA2518,0x3C70C97C}} /* +1.4560447300e-17 */ ,
{{0xEC48E112,0x3FEE6288}} /* +9.4952818059e-01 */ ,
{{0xF2847754,0xBC616B56}} /* -7.5544151928e-18 */ ,
{{0x4278E76A,0x3FD4D1E2}} /* +3.2531029216e-01 */ ,
{{0x18792858,0x3C624172}} /* +7.9171249464e-18 */ ,
{{0x4B2BC17E,0x3FEE426A}} /* +9.4560732538e-01 */ ,
{{0x89744882,0x3C8A8738}} /* +4.6019102479e-17 */ ,
{{0x75AB1FDD,0x3FD58F9A}} /* +3.3688985339e-01 */ ,
{{0xD58CF620,0xBC1EFDC0}} /* -4.2000940033e-19 */ ,
{{0x04F686E5,0x3FEE2121}} /* +9.4154406518e-01 */ ,
{{0x6C126527,0xBC8014C7}} /* -2.7896379548e-17 */ ,
{{0xDD3F27C6,0x3FD64C7D}} /* +3.4841868025e-01 */ ,
{{0x4A664121,0x3C510D2B}} /* +3.6974420514e-18 */ ,
{{0x622DBE2B,0x3FEDFEAE}} /* +9.3733901191e-01 */ ,
{{0x88425567,0xBC8514EA}} /* -3.6570926284e-17 */ ,
{{0x30FA459F,0x3FD70885}} /* +3.5989503653e-01 */ ,
{{0xE0864C5D,0xBC744B19}} /* -1.7601687124e-17 */ ,
{{0xB6CCC23C,0x3FEDDB13}} /* +9.3299279883e-01 */ ,
{{0xC6107DB3,0x3C883C37}} /* +4.2041415555e-17 */ ,
{{0x311DCCE7,0x3FD7C3A9}} /* +3.7131719395e-01 */ ,
{{0x1EF3E8D9,0x3C19A3F2}} /* +3.4749239648e-19 */ ,
{{0x6238A09B,0x3FEDB652}} /* +9.2850608047e-01 */ ,
{{0xEAE69460,0xBC7ADEE7}} /* -2.3306639848e-17 */ ,
{{0xA6AEA963,0x3FD87DE2}} /* +3.8268343236e-01 */ ,
{{0xD3D5A610,0xBC672CED}} /* -1.0050772696e-17 */ ,
{{0xCF328D46,0x3FED906B}} /* +9.2387953251e-01 */ ,
{{0x10231AC2,0x3C7457E6}} /* +1.7645047084e-17 */ ,
{{0x63BC93D7,0x3FD9372A}} /* +3.9399204006e-01 */ ,
{{0x9E5AD5B1,0x3C668431}} /* +9.7649241641e-18 */ ,
{{0x73C9E68B,0x3FED6961}} /* +9.1911385169e-01 */ ,
{{0xC6393D55,0xBC7E8C61}} /* -2.6496484622e-17 */ ,
{{0x43A8ED8A,0x3FD9EF79}} /* +4.0524131400e-01 */ ,
{{0x290BDBAB,0x3C66DA81}} /* +9.9111401943e-18 */ ,
{{0xD14DC93A,0x3FED4134}} /* +9.1420975570e-01 */ ,
{{0x95D25AF2,0xBC84EF52}} /* -3.6316182528e-17 */ ,
{{0x2B6D3FCA,0x3FDAA6C8}} /* +4.1642956010e-01 */ ,
{{0x6EE5CCF7,0xBC7D5F10}} /* -2.5475580413e-17 */ ,
{{0x743E35DC,0x3FED17E7}} /* +9.0916798309e-01 */ ,
{{0x3540130A,0xBC5101DA}} /* -3.6878564091e-18 */ ,
{{0x09E15CC0,0x3FDB5D10}} /* +4.2755509343e-01 */ ,
{{0xCB974183,0x3C65B362}} /* +9.4111898163e-18 */ ,
{{0xF43CC773,0x3FECED7A}} /* +9.0398929312e-01 */ ,
{{0xB5AB58AE,0xBC5E7B6B}} /* -6.6097544687e-18 */ ,
{{0xD8011EE7,0x3FDC1249}} /* +4.3861623854e-01 */ ,
{{0xBB515206,0xBC7813AA}} /* -2.0883315831e-17 */ ,
{{0xF3FCFC5C,0x3FECC1F0}} /* +8.9867446569e-01 */ ,
{{0x3B68F6AB,0x3C7E5761}} /* +2.6316906461e-17 */ ,
{{0x9931C45E,0x3FDCC66E}} /* +4.4961132965e-01 */ ,
{{0x59C37F8F,0x3C56850E}} /* +4.8831924232e-18 */ ,
{{0x213411F5,0x3FEC954B}} /* +8.9322430120e-01 */ ,
{{0x1E946603,0xBC52FB76}} /* -4.1161239152e-18 */ ,
{{0x5B86E389,0x3FDD7977}} /* +4.6053871096e-01 */ ,
{{0x87BC0575,0x3C7550EC}} /* +1.8488777492e-17 */ ,
{{0x3488739B,0x3FEC678B}} /* +8.8763962040e-01 */ ,
{{0xC7C5FF5B,0x3C6D86CA}} /* +1.2805091919e-17 */ ,
{{0x3806F63B,0x3FDE2B5D}} /* +4.7139673683e-01 */ ,
{{0x1D3C6841,0x3C5E0D89}} /* +6.5166781361e-18 */ ,
{{0xF180BDB1,0x3FEC38B2}} /* +8.8192126435e-01 */ ,
{{0x757C8D07,0xBC76E0B1}} /* -1.9843248406e-17 */ ,
{{0x52EF78D6,0x3FDEDC19}} /* +4.8218377208e-01 */ ,
{{0xC33EDEE6,0xBC7DD0F7}} /* -2.5861500926e-17 */ ,
{{0x26725549,0x3FEC08C4}} /* +8.7607009420e-01 */ ,
{{0xD80E2946,0x3C5B157F}} /* +5.8729024235e-18 */ ,
{{0xDBF89ABA,0x3FDF8BA4}} /* +4.9289819223e-01 */ ,
{{0xC1B776B8,0xBC32EC1F}} /* -1.0257831677e-18 */ ,
{{0xAC6F952A,0x3FEBD7C0}} /* +8.7008699111e-01 */ ,
{{0x32AC700A,0xBC8825A7}} /* -4.1888510869e-17 */ ,
{{0x874C3EB7,0x3FE01CFC}} /* +5.0353838373e-01 */ ,
{{0xE7C2368C,0xBC734A35}} /* -1.6731308205e-17 */ ,
{{0x673590D2,0x3FEBA5AA}} /* +8.6397285612e-01 */ ,
{{0x370753B6,0x3C87EA4E}} /* +4.1486355957e-17 */ ,
{{0x9922FFEE,0x3FE07387}} /* +5.1410274419e-01 */ ,
{{0x4347406C,0xBC8A5A01}} /* -4.5712707524e-17 */ ,
{{0x45196E3E,0x3FEB7283}} /* +8.5772861000e-01 */ ,
{{0x324E6D61,0xBC8BC69F}} /* -4.8183447936e-17 */ ,
{{0x4D5D898F,0x3FE0C970}} /* +5.2458968268e-01 */ ,
{{0xDE6EE9B2,0xBC88D3D7}} /* -4.3068869040e-17 */ ,
{{0x3EF55712,0x3FEB3E4D}} /* +8.5135519311e-01 */ ,
{{0xBF11A493,0xBC8EB6B8}} /* -5.3279874446e-17 */ ,
{{0x541B4B23,0x3FE11EB3}} /* +5.3499761989e-01 */ ,
{{0x69ABE4F1,0xBC8EF23B}} /* -5.3683132708e-17 */ ,
{{0x58150200,0x3FEB090A}} /* +8.4485356525e-01 */ ,
{{0x300FFCCE,0xBC8926DA}} /* -4.3631360297e-17 */ ,
{{0x63DEDB49,0x3FE1734D}} /* +5.4532498842e-01 */ ,
{{0xCCC50575,0xBC87EEF2}} /* -4.1517817538e-17 */ ,
{{0x9E21D511,0x3FEAD2BC}} /* +8.3822470555e-01 */ ,
{{0x07BEA548,0xBC847FBE}} /* -3.5560085053e-17 */ ,
{{0x39AE68C8,0x3FE1C73B}} /* +5.5557023302e-01 */ ,
{{0x267F6600,0x3C8B25DD}} /* +4.7094109406e-17 */ ,
{{0x290EA1A3,0x3FEA9B66}} /* +8.3146961230e-01 */ ,
{{0xE8B6DAC8,0x3C39F630}} /* +1.4073856985e-18 */ ,
{{0x9933EB59,0x3FE21A79}} /* +5.6573181078e-01 */ ,
{{0x77C68FB2,0xBC83A7B1}} /* -3.4096079597e-17 */ ,
{{0x1B02FAE2,0x3FEA6309}} /* +8.2458930278e-01 */ ,
{{0x52248D10,0xBC7E9111}} /* -2.6512360489e-17 */ ,
{{0x4CDD12DF,0x3FE26D05}} /* +5.7580819142e-01 */ ,
{{0x3EF3770C,0xBC85DA74}} /* -3.7909495459e-17 */ ,
{{0xA0462782,0x3FEA29A7}} /* +8.1758481315e-01 */ ,
{{0x015DF175,0xBC7128BB}} /* -1.4883149812e-17 */ ,
{{0x25FAF3EA,0x3FE2BEDB}} /* +5.8579785746e-01 */ ,
{{0xC796EE46,0xBC514981}} /* -3.7485501964e-18 */ ,
{{0xEF29AF94,0x3FE9EF43}} /* +8.1045719825e-01 */ ,
{{0xB60445C2,0x3C7B1DFC}} /* +2.3520367350e-17 */ ,
{{0xFCE17035,0x3FE30FF7}} /* +5.9569930449e-01 */ ,
{{0x26F74A6F,0xBC6EFCC6}} /* -1.3438641937e-17 */ ,
{{0x47F38741,0x3FE9B3E0}} /* +8.0320753148e-01 */ ,
{{0x86712474,0xBC830EE2}} /* -3.3060609805e-17 */ ,
{{0xB10659F3,0x3FE36058}} /* +6.0551104140e-01 */ ,
{{0xA35857E7,0xBC81FCB3}} /* -3.1202672493e-17 */ ,
{{0xF4C7D742,0x3FE9777E}} /* +7.9583690461e-01 */ ,
{{0xA240665E,0xBC815479}} /* -3.0062724852e-17 */ ,
{{0x292050B9,0x3FE3AFFA}} /* +6.1523159058e-01 */ ,
{{0xE3954964,0x3C7E3E25}} /* +2.6231417767e-17 */ ,
{{0x499263FB,0x3FE93A22}} /* +7.8834642763e-01 */ ,
{{0xA920DF0B,0x3C83D419}} /* +3.4396993154e-17 */ ,
{{0x534556D4,0x3FE3FED9}} /* +6.2485948814e-01 */ ,
{{0x608C5061,0x3C836916}} /* +3.3671846037e-17 */ ,
{{0xA3EF940D,0x3FE8FBCC}} /* +7.8073722857e-01 */ ,
{{0x9C86F2F1,0xBC66DFA9}} /* -9.9198782067e-18 */ ,
{{0x25091DD6,0x3FE44CF3}} /* +6.3439328416e-01 */ ,
{{0x2CFDC6B3,0x3C68076A}} /* +1.0420901929e-17 */ ,
{{0x6B151741,0x3FE8BC80}} /* +7.7301045336e-01 */ ,
{{0x2ED1336D,0xBC82C5E1}} /* -3.2565907034e-17 */ ,
{{0x9B9B0939,0x3FE49A44}} /* +6.4383154289e-01 */ ,
{{0x6D719B94,0xBC827EE1}} /* -3.2084798795e-17 */ ,
{{0x0FBA2EBF,0x3FE87C40}} /* +7.6516726562e-01 */ ,
{{0x0C3F64CD,0xBC82DABC}} /* -3.2707225613e-17 */ ,
{{0xBBE3E5E9,0x3FE4E6CA}} /* +6.5317284295e-01 */ ,
{{0xEDCEB327,0x3C63C293}} /* +8.5695642060e-18 */ ,
{{0x0BFF976E,0x3FE83B0E}} /* +7.5720884651e-01 */ ,
{{0xF8EA3475,0xBC76F420}} /* -1.9909098777e-17 */ ,
{{0x92A35596,0x3FE53282}} /* +6.6241577759e-01 */ ,
{{0x89DA0257,0xBC7A12EB}} /* -2.2615508886e-17 */ ,
{{0xE3571771,0x3FE7F8EC}} /* +7.4913639452e-01 */ ,
{{0xCE93C917,0xBC89C8D8}} /* -4.4729078447e-17 */ ,
{{0x348CECA0,0x3FE57D69}} /* +6.7155895485e-01 */ ,
{{0x992BFBB2,0xBC875720}} /* -4.0489037749e-17 */ ,
{{0x226AAFAF,0x3FE7B5DF}} /* +7.4095112535e-01 */ ,
{{0xACDF0AD7,0xBC70F537}} /* -1.4708616952e-17 */ ,
{{0xBE65018C,0x3FE5C77B}} /* +6.8060099780e-01 */ ,
{{0x9C0BC32A,0x3C8069EA}} /* +2.8473293355e-17 */ ,
{{0x5F037261,0x3FE771E7}} /* +7.3265427167e-01 */ ,
{{0x8D84068F,0x3C75CFCE}} /* +1.8918673482e-17 */ ,
{{0x551D2CDF,0x3FE610B7}} /* +6.8954054474e-01 */ ,
{{0x52FF2A37,0xBC7251B3}} /* -1.5889323295e-17 */ ,
{{0x37EFFF96,0x3FE72D08}} /* +7.2424708295e-01 */ ,
{{0x0F1D915C,0x3C80D4EF}} /* +2.9198471334e-17 */ ,
{{0x25F0783D,0x3FE65919}} /* +6.9837624941e-01 */ ,
{{0xFBF5DE23,0x3C8C3D64}} /* +4.8988282436e-17 */ ,
{{0x54EAA8AF,0x3FE6E744}} /* +7.1573082528e-01 */ ,
{{0xC84E226E,0xBC8DBC03}} /* -5.1581018476e-17 */ ,
{{0x667F3BCD,0x3FE6A09E}} /* +7.0710678119e-01 */ ,
{{0x13B26456,0xBC8BDD34}} /* -4.8336466567e-17 */ ,
{{0x667F3BCD,0x3FE6A09E}} /* +7.0710678119e-01 */ ,
{{0x13B26456,0xBC8BDD34}} /* -4.8336466567e-17 */ ,

};

#endif /* WORDS_BIGENDIAN */


