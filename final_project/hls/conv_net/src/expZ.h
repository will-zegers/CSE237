#include "conv_net.h"

const DTYPE expZ[SFMX_RES] = {2.0611536224385579e-09, 2.2779270412053712e-09, 2.517498719438287e-09, 2.7822663710158828e-09, 3.074879879586628e-09, 3.3982678194950955e-09, 3.755666765938329e-09, 4.1506536876982674e-09, 4.5871817466475735e-09, 5.0696198623223587e-09, 5.6027964375373472e-09, 6.192047682664127e-09, 6.8432710222181093e-09, 7.5629841182652741e-09, 8.3583901013747872e-09, 9.2374496619707912e-09, 1.0208960723597855e-08, 1.1282646495496886e-08, 1.24692527857513e-08, 1.3780655548946109e-08, 1.5229979744713063e-08, 1.6831730696738076e-08, 1.8601939266916106e-08, 2.055832229760514e-08, 2.2720459927739363e-08, 2.5109991557440709e-08, 2.7750832422408549e-08, 3.0669412945636748e-08, 3.3894943261970567e-08, 3.7459705562954053e-08, 4.1399377187853429e-08, 4.5753387694460066e-08, 5.0565313483357539e-08, 5.5883313925185258e-08, 6.1760613355806703e-08, 6.8256033763352087e-08, 7.5434583498446341e-08, 8.3368107899632158e-08, 9.2136008345666259e-08, 1.0182603693120565e-07, 1.1253517471926551e-07, 1.2437060236029426e-07, 1.3745077279214791e-07, 1.5190659675690557e-07, 1.6788275299957675e-07, 1.8553913626160969e-07, 2.0505245756120614e-07, 2.2661801277658629e-07, 2.5045163723277908e-07, 2.7679186585409992e-07, 3.0590232050184754e-07, 3.3807434839049829e-07, 3.7362993798855392e-07, 4.12924941587358e-07, 4.5635263679043422e-07, 5.0434766256792752e-07, 5.5739036926950413e-07, 6.1601162613210298e-07, 6.8079813439768993e-07, 7.5239829921648411e-07, 8.3152871910363882e-07, 9.1898135789803708e-07, 1.0156314710025805e-06, 1.1224463652344439e-06, 1.2404950799568258e-06, 1.3709590863842111e-06, 1.5151441121433917e-06, 1.6744932094344265e-06, 1.8506011975820856e-06, 2.0452306245236896e-06, 2.2603294069812791e-06, 2.4980503258668882e-06, 2.7607725720374832e-06, 3.0511255580367367e-06, 3.3720152341395377e-06, 3.7266531720790682e-06, 4.1185887075361537e-06, 4.5517444630837326e-06, 5.0304556071120023e-06, 5.5595132416507686e-06, 6.1442123533289086e-06, 6.7904048073802547e-06, 7.5045579150777382e-06, 8.2938191607583428e-06, 9.1660877362487081e-06, 1.0130093598631934e-05, 1.1195484842592312e-05, 1.237292426178976e-05, 1.3674196065682663e-05, 1.5112323819856939e-05, 1.6701700790247794e-05, 1.845823399578295e-05, 2.0399503411174602e-05, 2.2544937913215175e-05, 2.4916009731506525e-05, 2.7536449349750875e-05, 3.0432483008407789e-05, 3.363309518572363e-05, 3.7170318684131884e-05, 4.1079555225306491e-05, 4.5399929762491305e-05, 5.0174682056182506e-05, 5.5451599432185022e-05, 6.1283495053231064e-05, 6.7728736490863886e-05, 7.4851829887711765e-05, 8.2724065556644724e-05, 9.1424231478187242e-05, 0.00010103940183710885, 0.00011166580849013203, 0.00012340980408669883, 0.00013638892648203297, 0.0001507330750955006, 0.00016658581098766016, 0.00018410579366760896, 0.00020346836901067743, 0.00022486732417888533, 0.00024851682710799332, 0.0002746535699721884, 0.000303539138078918, 0.00033546262790256904, 0.00037074354045915213, 0.00040973497897985777, 0.00045282718288687621, 0.00050045143344069887, 0.00055308437014793186, 0.00061125276112968202, 0.00067553877519396614, 0.00074658580837681516, 0.00082510492326605552, 0.00091188196555468462, 0.0010077854290486985, 0.0011137751478450121, 0.0012309119026737139, 0.0013603680375481526, 0.001503439192977861, 0.0016615572731742557, 0.0018363047770292643, 0.0020294306362961326, 0.0022428677194862457, 0.0024787521766668516, 0.0027394448187689183, 0.0030275547453764255, 0.0033459654574719529, 0.0036978637164836875, 0.0040867714384649088, 0.0045165809426136053, 0.0049915939069112587, 0.005516564420761933, 0.0060967465655169268, 0.0067379469990869034, 0.0074465830709259384, 0.0082297470490218065, 0.0090952771016977949, 0.010051835744635782, 0.011108996538244754, 0.012277339903071163, 0.013568559012203959, 0.014995576820481074, 0.016572675401764991, 0.018315638888738345, 0.020241911445809019, 0.022370771856170747, 0.02472352647034512, 0.027323722447298929, 0.030197383422325582, 0.033373269960333955, 0.036883167401248758, 0.040762203978375947, 0.045049202393568626, 0.04978706836787597, 0.055023220056420602, 0.060810062625232829, 0.067205512739766285, 0.074273578214352251, 0.082084998623919214, 0.090717953289435188, 0.10025884372282895, 0.11080315836236192, 0.12245642825301306, 0.13533528323664731, 0.14956861922267353, 0.1652988882216293, 0.18268352405278215, 0.2018965179947082, 0.22313016014848849, 0.24659696394167166, 0.27253179303408503, 0.30119421191228257, 0.33287108369816898, 0.36787944117154164, 0.40656965974070947, 0.44932896411734419, 0.4965853037915457, 0.54881163609417771, 0.60653065971280151, 0.67032004603582596, 0.74081822068192527, 0.81873075307821219, 0.90483741803621542, 1.0000000000002842, 1.1051709180759632, 1.2214027581605205, 1.3498588075763924, 1.4918246976417029, 1.6487212707006085, 1.8221188003910425, 2.013752707471069, 2.2255409284931256, 2.4596031111576804, 2.7182818284598564, 3.004166023947334, 3.3201169227375478, 3.6692966676203547, 4.0551999668459082, 4.4816890703394341, 4.9530324243966355, 5.4739473917288874, 6.0496474644148206, 6.6858944422813504, 7.3890560989329606, 8.166169912570215, 9.0250134994369677, 9.9741824548178819, 11.023176380645111, 12.182493960707369, 13.463738035006015, 14.879731724877635, 16.444646771102377, 18.174145369448976, 20.085536923194233, 22.197951281448919, 24.532530197117438, 27.112638920666864, 29.964100047406976, 33.115451958703375, 36.598234443690259, 40.447304360081013, 44.701184493315942, 49.40244910554695, 54.59815003316286, 60.340287597382634, 66.686331040948076, 73.699793699621253, 81.450868664996364, 90.01713130055316, 99.484315641968593, 109.94717245216209, 121.5104175187777, 134.28977968498302, 148.41315910262932, 164.02190729996025, 181.27224187521608, 200.33680997486371, 221.406416204267, 244.69193226430906, 270.42640742625099, 298.86740096716937, 330.29955990976975, 365.03746786546316, 403.42879349288421, 445.85777008268229, 492.7490410934397, 544.57191012613259, 601.8450378723079, 665.14163304461238, 735.09518924225074, 812.40582516785139, 897.84729165075964, 992.27471560540516, 1096.6331584288794, 1211.9670744930434, 1339.4307643949355, 1480.2999275851196, 1635.9844299965634, 1808.0424144567698, 1998.1958951049016, 2208.347991888078, 2440.6019776254634, 2697.2823282695781, 2980.9579870429143, 3294.4680752851568, 3640.9503073338137, 4023.8723938239282, 4447.0667477016505, 4914.7688403011252, 5431.6595913651881, 6002.9122172634707, 6634.2440062805999, 7331.9735391590038, 8103.083927578723, 8955.292703486215, 9897.1290587480235, 10938.019208169739, 12088.380730222036, 13359.726829667474, 14764.781565583484, 16317.607198022319, 18033.744927836149, 19930.370438238759, 22026.465794816108, 24343.0094244188, 26903.186074309106, 29732.618852904216, 32859.625674457508, 36315.502674262381, 40134.837430893247, 44355.855130317221, 49020.801136403177, 54176.363796722522, 59874.141715224192, 66171.160168405855, 73130.441833447927, 80821.637540349504, 89321.723360845412, 98715.771010804689, 109097.79927655657, 120571.71498650493, 133252.35294559115, 147266.62524061941, 162754.79141907793, 179871.86225383315, 198789.15114304548, 219695.98867223857, 242801.61749843534, 268337.2865209984, 296558.56529834034, 327747.90187396412, 362217.44961141673, 400312.19133006962, 442413.392009128, 488942.41461569007, 540364.93724694685, 597195.61379309883, 660003.22476646991, 729416.36984804855, 806129.75912437518, 890911.16597958759, 984609.11122950795, 1088161.3554031642, 1202604.2841653579, 1329083.2808127375, 1468864.189654809, 1623345.9850092495, 1794074.7726070916, 1982759.2635385408, 2191287.8756078873, 2421747.6332536079, 2676445.0551904202, 2957929.2388238283, 3269017.3724737368, 3612822.9307420459, 3992786.8352129445, 4412711.8923526555, 4876800.8532747198, 5389698.4762857314, 5956538.0131876292, 6582992.5845870757, 7275331.9583932888, 8040485.2997626225, 8886110.5205124188, 9820670.9220763948, 10853519.899070002, 11994994.55120752, 13256519.140470425, 14650719.428961117, 16191549.041773709, 17894429.119563948, 19776402.658508118, 21856305.082337126, 24154952.753587998, 26695351.31075678, 29502925.916461054, 32605775.721013129, 36034955.088160791, 39824784.397597447, 44013193.534857564, 48642101.506359756, 53757835.978912532, 59411596.942574933, 65659969.137365967, 72565488.372361541, 80197267.405090645, 88631687.645242363, 97953163.605486676, 108254987.75028999, 119640264.19825613, 132222940.62279996, 146128948.6787619, 161497464.36873668, 178482300.96328619, 197253448.41584933, 217998774.6793319, 240925905.95172381, 266264304.66887411, 294267566.04167396, 325215956.12216359, 359419216.80038154, 397219665.80530846, 438995622.73575532};
