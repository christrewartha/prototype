
@{{BLOCK(door_closed)

@=======================================================================
@
@	door_closed, 64x128@4, 
@	+ palette 256 entries, not compressed
@	+ bitmap not compressed
@	Total size: 512 + 4096 = 4608
@
@	Time-stamp: 2025-02-17, 20:07:12
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global door_closedBitmap		@ 4096 unsigned chars
	.hidden door_closedBitmap
door_closedBitmap:
	.word 0x42424242,0x42424242,0x42424242,0x42424242,0x42424242,0x42424242,0x42424242,0x42424242
	.word 0x24242424,0x24242424,0x24242424,0x24242424,0x24242424,0x24242424,0x24242424,0x24242424
	.word 0x24245242,0xC4C4C4C4,0xC4C4C4C4,0xC4C4C4C4,0xC4C4C4C4,0xC4C4C4C4,0xC4C4C4C4,0x24C4C4C4
	.word 0x5259244C,0x52525252,0x52525252,0x45252452,0x4C429292,0x25252525,0x4C929245,0x42452525
	.word 0x2925C424,0x59259259,0x92592592,0x52292525,0x22525252,0x25404045,0x52525252,0x24522592
	.word 0xC5024242,0x9C522452,0x25252520,0x25152540,0x29009025,0x95205252,0x40409C90,0x42409520
	.word 0x90455242,0x25292522,0xC9092045,0x65209205,0x05C90C90,0x5209C900,0x25252502,0x22425224
	.word 0x42204442,0x29252540,0x20020520,0x42492520,0x92424242,0x20500002,0x029C9C29,0x42452455

	.word 0x24504242,0x00509020,0x42450005,0x252C2424,0x42452545,0x000C4242,0x25520050,0x24525252
	.word 0x90024254,0x00002525,0x25424250,0x00054245,0x45C00200,0x04424245,0x95297500,0x42429C42
	.word 0x25425424,0x29000529,0x0200C444,0x0000C420,0x42000500,0x42525052,0x00000242,0x24250050
	.word 0x02004222,0x42425000,0x50000002,0x00009250,0x47000000,0x25000002,0x9C092425,0x42520202
	.word 0x2590C424,0x52524005,0x00000505,0x33305240,0x40033001,0x00000075,0x752422C9,0x42409050
	.word 0x00002424,0x104247A0,0x31313000,0x11110403,0x47311331,0x00031010,0xA0425050,0x24C00000
	.word 0x30204542,0x00052361,0x613131A0,0x31330426,0x23613011,0x03111130,0xA7420000,0x42450031
	.word 0x13002422,0x33042513,0xD11316D1,0x7117025A,0x46D11731,0x11313380,0x60250331,0x24520013

	.word 0x31005224,0x3105238B,0x831B36A1,0x13B30426,0x23813071,0x36113BE0,0xA0401311,0x42400137
	.word 0x13104442,0xB73246E3,0xD1131663,0xB631025A,0x46E310A1,0x7A3B36E0,0x8023F131,0x24250317
	.word 0xB1325224,0x13052661,0x81B36333,0x3D13040A,0x26AB70B1,0x361131D0,0x65418117,0x24207111
	.word 0x33102424,0x31329AD1,0xF131311B,0x16110403,0x43E36373,0x36311680,0xA023F371,0x42523317
	.word 0x16005242,0x11052681,0x81363713,0x16330406,0x26836183,0x3613B385,0xD0418111,0x42403110
	.word 0x13302442,0xB33296D3,0x83171711,0x6D110403,0x46836183,0x163136E0,0x8023F173,0x24C50637
	.word 0xB1709242,0x31052681,0x83631373,0x1613022D,0x2383B1F3,0x361B3180,0xA0418131,0x42423613
	.word 0x11302245,0x63704633,0x81713100,0x1331045A,0x46F13131,0x763136F0,0x6023F163,0x24250A63

	.word 0x11325422,0x13052A86,0xF3136607,0x31675226,0x2381361B,0x163111E0,0xE0418113,0x242173AB
	.word 0x31102422,0x31129BD1,0xE71B3306,0x3B31040A,0x46E3B331,0x0113B3F0,0xA023F317,0x42505163
	.word 0x31300424,0x13752681,0x8313100D,0x10310456,0x21F113B1,0x13B311E0,0x674181B3,0x42407161
	.word 0x17102424,0x11324AD3,0x83B137A6,0x37130401,0x43831131,0x361136F0,0xA04BF131,0x245231DA
	.word 0x61752542,0x33052681,0xF31317AB,0x13130226,0x4683B3B1,0x3633B380,0x65218171,0x42400113
	.word 0x37302422,0x117296D1,0xE111B363,0x1711045A,0x46F13133,0x633631F0,0xD023E301,0x24C07317
	.word 0x31052424,0x13352A81,0x61B313A6,0x13630406,0x2183111B,0x311311E0,0x60418171,0x42403313
	.word 0x10104424,0x31729BD3,0xA3317163,0x37D1029D,0x46D11B33,0xB3B11BE0,0xD021F103,0x24C0011B

	.word 0x103C9C42,0xB1052681,0x613B3133,0x16110406,0x2381B33B,0x131131D0,0xA041FA76,0x42400131
	.word 0x17002424,0x133293E3,0xF0311631,0x1E730403,0x46E33113,0x1113B6E0,0xD021863D,0x24C5031B
	.word 0x10152542,0x3B05268B,0xE01B313B,0x68010406,0x21F1B363,0x13B311D0,0xA041E318,0x24210713
	.word 0x37302422,0x131296D1,0x87313171,0x36330251,0x46313131,0x113136E0,0x8023F16D,0x42550336
	.word 0x30000424,0x31052681,0xE0363713,0x1F130426,0x2381B136,0x13B3B1D0,0xD0418136,0x22420311
	.word 0x70304242,0x1B3243E3,0x83711311,0x3631025A,0x46D71316,0x113136E0,0x804BF317,0x42400131
	.word 0x1000C424,0x31352863,0x83131737,0x61170406,0x23803136,0x3B3B11D0,0xD0218161,0x24200331
	.word 0x63109224,0x117296D1,0xD1711101,0x33330251,0x41A01716,0x13131380,0xA043F313,0x4250511B

	.word 0x63325242,0xB3052683,0x11363733,0x61B10401,0x2187B313,0xB3631B85,0xA02B81B3,0x42420713
	.word 0xA1302424,0x311293E1,0x3B313101,0x13330403,0x438D011B,0x1313B3E0,0x6043E131,0x24C50137
	.word 0x37709242,0xB3052687,0x16311731,0x36110206,0x26A67131,0x3B1111F0,0x852B8366,0x42400111
	.word 0x10302424,0x31024383,0x36363731,0x63310451,0x418103B3,0x3133BAF0,0x3043EB31,0x24C00317
	.word 0x30152542,0x10052661,0x7D613131,0x11175206,0x21837113,0x13B113E0,0x65218311,0x42400313
	.word 0x73004422,0x300923E1,0x0813B317,0xB313040A,0x43E13631,0x3B311B80,0xD043F13B,0x24500037
	.word 0x3030C424,0x000241EB,0x36131100,0x1317020D,0x21871A31,0x110113A5,0xA02381B3,0x24220331
	.word 0x10109224,0x00092D83,0x11317303,0x3B130401,0x9BE3663B,0x137636D2,0x60438331,0x42450313

	.word 0x13052242,0x10052187,0x31730000,0x31370406,0x23871D11,0xB130D185,0x652BEB13,0x24200313
	.word 0x70702445,0x100923E3,0x33710000,0x1B130256,0x46E71A11,0x3161D180,0x60418311,0x425001B0
	.word 0x00300422,0x11052A80,0x11000100,0x13300406,0x26836373,0xB1D36165,0x3021F3B3,0x42423331
	.word 0x00004242,0x000923A0,0x31001000,0x770004CA,0x41E71101,0x116111D0,0x60418131,0x24C50101
	.word 0x00005242,0x00052380,0x10100000,0x01000406,0x218B3303,0xB33636A0,0x1021F311,0x42921173
	.word 0x00304424,0x000923E0,0x00300100,0x000004CA,0x41E31100,0x311311D0,0x604383B3,0x24C03130
	.word 0x03005242,0x00052A80,0x30100000,0x10005206,0x23870000,0x163B1BA0,0x65218313,0x42407110
	.word 0x11304242,0x000246D0,0x33000300,0x00000403,0x43870300,0x313133D0,0x6041F1B1,0x24C03633

	.word 0x31000242,0x000046A0,0x11100000,0x0000040A,0x2BE00113,0x71B11165,0x10268313,0x42400130
	.word 0x11004242,0x00092360,0xD0000000,0x00000406,0x93600A10,0x313313D2,0x6043E716,0x24505101
	.word 0x00005242,0x00024163,0xA0000031,0x00000406,0x21A30310,0x71311765,0x1521811D,0x42400100
	.word 0x00004242,0x00029680,0xD0001160,0x01002403,0x43601103,0x7117B310,0x6041F3BA,0x24250003
	.word 0x13025224,0x100546D0,0xA0001311,0x00000401,0x2BA00000,0x13131379,0xA021F113,0x42400003
	.word 0x30009244,0x00092680,0xD0103117,0x010004C3,0x50A71300,0x711B3012,0x60438310,0x24507101
	.word 0x0000C422,0x000523E0,0x80000000,0x0000042A,0x43A01001,0x6631303C,0x65218363,0x42200303
	.word 0x00009424,0x100923A7,0xD0001000,0x00300403,0x4B600000,0x63300000,0xA043F131,0x24200111

	.word 0x0000C242,0x000523E0,0xA1000000,0x00300426,0x21A30100,0x33710079,0x60218366,0x42403A31
	.word 0x00304424,0x00092380,0xD0000000,0x00100403,0x23300000,0x70000030,0x6043D163,0x245C0371
	.word 0x00002C42,0x00052AD0,0x80000000,0x00000403,0x43A10010,0x01010032,0x65238030,0x24210310
	.word 0x03009242,0x000923A0,0xA0010101,0x0013924B,0x23600000,0x00000039,0xA0400700,0x42525000
	.word 0x00025242,0x00252680,0x00090009,0x05002450,0x20500090,0x00000925,0x60452009,0x22400030
	.word 0x01009224,0x424243D0,0x24242442,0x24424424,0x44244429,0x24444254,0xE0424424,0x42400010
	.word 0x00025242,0x37333680,0x33333173,0x3B137333,0x1B31B3B3,0x337B1371,0x67731733,0x24200000
	.word 0x30002424,0x8E888100,0x88F88F89,0x8E8F8888,0xF8F8FE8F,0x88FE8E8E,0x31E8F88F,0x42505001

	.word 0x00015242,0x363B3300,0xB313B317,0x1B111363,0x31317171,0x61631B3B,0x1031136A,0x24410003
	.word 0x00052442,0x17117000,0x31317137,0x88373B31,0x1111A8EF,0x8D317313,0x1016BA6D,0x42250000
	.word 0x000024C4,0xF8000203,0x6616D888,0x36617136,0x1738D671,0x13111311,0x50B13631,0x424000A8
	.word 0x00004424,0x31333000,0x33363136,0x13630000,0x00A61311,0x37773660,0xB1037301,0x242000A1
	.word 0x00002542,0x3B111100,0x71313113,0xB3132011,0x3073361D,0x8888A637,0x03003888,0x24290AC0
	.word 0x00054422,0x1333B300,0xA6666663,0x00000336,0x13700030,0x36333611,0x00000336,0x4250C300
	.word 0x00002224,0x1D611000,0xD6DAADA6,0x00000316,0x13100000,0x333B1636,0x32000071,0x24290013
	.word 0x00004442,0x17113300,0x11117113,0x05033113,0x31713000,0x11B33131,0x25051113,0x42520029

	.word 0x03095224,0x00000000,0x00000000,0x00000000,0x00000015,0x00000000,0x01000000,0x22400052
	.word 0x00002444,0x24242500,0x44244244,0x06009242,0x40002500,0x24442442,0x54244244,0x42470002
	.word 0x00025422,0x25254210,0x00005C50,0x00000245,0x40050000,0x520C5002,0x02420520,0x22900000
	.word 0x01004224,0x7A324730,0x73D1A1A1,0x00000497,0x25001000,0xA1AA6309,0x014511AD,0x424C0000
	.word 0x00025242,0x3A052030,0x6A6A6D66,0x003004C3,0x40100300,0xA6D6A632,0x05271D66,0x22900000
	.word 0x00004424,0x0B324730,0xF3131113,0x03019223,0x9BD01000,0x31113632,0x3241E113,0x42420000
	.word 0x0052C242,0x010521A5,0x81B1B313,0x0113C40A,0x26E01000,0x1B113635,0x0521F731,0x25400300
	.word 0x00092424,0x71304360,0xD13331B1,0x00310403,0x43803001,0x13317A12,0x3041E11B,0x24200000

	.word 0x00052542,0x33052BA0,0x813B1137,0x00A00426,0x26E00000,0x31B17805,0x0021F113,0x42450000
	.word 0x00092422,0x013241A0,0xE71313B3,0x003104C3,0x43803000,0x36333A32,0x3043831B,0x24C00000
	.word 0x0000C424,0x11302363,0xD131B111,0x0010042A,0x26800000,0x31310615,0x004683B3,0x24290000
	.word 0x31092424,0x37024380,0x87013331,0x310304C3,0x4AD00001,0x01110832,0x3041F111,0x425C5000
	.word 0x10052542,0x303526A0,0x800B3B17,0x1130042A,0x21800000,0x73170635,0x09238313,0x24410000
	.word 0x31022422,0x017143D0,0xD00A1311,0x1A7104C3,0x93800000,0x71000302,0x0041F111,0x42250000
	.word 0x10059242,0x03052BA0,0xA6036111,0x0710042A,0x26830000,0x01003105,0x05218173,0x24420000
	.word 0x11029224,0x711243A0,0x6D013737,0x003004C3,0x23371001,0x01000009,0x09438300,0x42505000

	.word 0x70525242,0x01052160,0x68131001,0x0030042A,0x23633000,0x01010005,0x00238003,0x22420000
	.word 0x30004442,0x003243A0,0xED760000,0x001104C3,0x41A00000,0x01003001,0x09238000,0x42450030
	.word 0x00152242,0x00052660,0x61030000,0x00000403,0x21A00100,0x00300004,0x0521D010,0x42400030
	.word 0x00092424,0x000943A0,0xA7100010,0x100004C1,0x53637000,0x10000002,0x092387AB,0x24250037
	.word 0x00002542,0x00052BA0,0xD0001000,0x00000421,0x41A01000,0x30000052,0x0521D01A,0x24240130
	.word 0x00092422,0x00024360,0xA0000000,0x30009253,0x23600000,0x71001004,0x0143A003,0x42450010
	.word 0x09052424,0x700921A0,0x61010013,0x00005291,0x23A00700,0x00000009,0x50416011,0x22520310
	.word 0x50024242,0x100048A0,0x80000000,0x000004C3,0xC3D00000,0x00001004,0x024BA700,0x42400010

	.word 0x0215C424,0x13052130,0x63300010,0x00000423,0x93800000,0x10100052,0x0523A000,0x224203A0
	.word 0x00504424,0x310423A0,0xA0001000,0x10000403,0x23600000,0x00000009,0x09236030,0x42450310
	.word 0x30092242,0x11792330,0xA1000000,0x00000421,0x41A00000,0x0100009C,0x0C43A000,0x25400313
	.word 0x00004422,0x310257A0,0xD0001001,0x03310423,0x23800003,0x10000109,0x09236030,0x24200030
	.word 0x05254224,0x115241A0,0xA0100000,0x00000421,0x21A00000,0x00000025,0x0523A010,0x42290000
	.word 0x01092244,0x31029B30,0x60000000,0x00000403,0x23A00000,0x00001054,0x09236000,0x24250000
	.word 0x52525452,0x100523A0,0x30100100,0x00105223,0x23630130,0x00000009,0x0221A001,0x45420113
	.word 0x01092442,0x30092330,0xD0000000,0x00000423,0x23A01130,0x00003009,0x09503030,0x24205631

	.word 0x25254242,0x01522110,0x00000000,0x00505290,0x23E00110,0x00003004,0x02400000,0x42420101
	.word 0x009024C4,0x9C924330,0x40929242,0x00000425,0x23A00000,0x4C492925,0x09254292,0x24C50301
	.word 0x90C45242,0x25250110,0x202525C5,0x00051520,0x01300000,0x52C025C4,0x05202520,0x24290100
	.word 0x20092442,0x86888600,0xEDAE68A8,0xE8A8888A,0xF68DD8A8,0xA8EA388A,0x01A3DA63,0x42520020
	.word 0x4525C424,0x31313325,0x11113131,0x11313133,0x31311133,0x61311131,0x00710131,0x24292515
	.word 0x15292424,0x01710025,0x00070000,0x00000000,0x6A636367,0x30000006,0x01000000,0x42525020
	.word 0x02045242,0x00300090,0xA6100010,0x6A6D8D6D,0x3333B310,0x00000303,0x50003000,0x24240051
	.word 0x09529242,0x00000020,0x10003000,0x30030010,0x011B1110,0x00000000,0x02000000,0x42450040

	.word 0x00252424,0x16AA0525,0x00300001,0x00000000,0x10000030,0x00003113,0x15000001,0x22452000
	.word 0x62592424,0x00301015,0x10000000,0x00010100,0xD1A11301,0x000011D6,0x20001313,0x42421515
	.word 0x02924542,0x30000292,0x00000000,0x01000000,0x00173111,0x00010000,0x90000000,0x45429020
	.word 0x25924242,0x00100005,0x0311A100,0x00000100,0x01000010,0x00300000,0x02501924,0x24225000
	.word 0x09254242,0x30000524,0x13130130,0x10000000,0x00000000,0x3A63ADA3,0x90000737,0x4242902C
	.word 0x52524242,0x11000190,0x3B100011,0x09303101,0x00000000,0x00300000,0x02510000,0x24542009
	.word 0x9C925424,0x0500052C,0x00000000,0x00000000,0x00000009,0x00000000,0x25200515,0x24225925
	.word 0x4C242424,0x92924245,0x45454092,0x29292925,0x29292240,0x24292929,0x29294224,0x42454254

	.section .rodata
	.align	2
	.global door_closedPal		@ 512 unsigned chars
	.hidden door_closedPal
door_closedPal:
	.hword 0x1489,0x190E,0x0403,0x1CCE,0x2020,0x1C2C,0x1110,0x0C8B
	.hword 0x1D73,0x2C85,0x2572,0x08CD,0x0026,0x18F4,0x2DB8,0x1535
	.hword 0x354F,0x1CC5,0x0007,0x20F4,0x1462,0x250A,0x28A3,0x190B
	.hword 0x042E,0x21D9,0x31F5,0x4214,0x258F,0x0C63,0x0C63,0x0C63
	.hword 0x1084,0x1084,0x1084,0x1084,0x1084,0x1084,0x1084,0x1084
	.hword 0x14A5,0x14A5,0x14A5,0x14A5,0x14A5,0x14A5,0x14A5,0x14A5
	.hword 0x18C6,0x18C6,0x18C6,0x18C6,0x18C6,0x18C6,0x18C6,0x18C6
	.hword 0x1CE7,0x1CE7,0x1CE7,0x1CE7,0x1CE7,0x1CE7,0x1CE7,0x1CE7

	.hword 0x2108,0x2108,0x2108,0x2108,0x2108,0x2108,0x2108,0x2108
	.hword 0x2529,0x2529,0x2529,0x2529,0x2529,0x2529,0x2529,0x2529
	.hword 0x294A,0x294A,0x294A,0x294A,0x294A,0x294A,0x294A,0x294A
	.hword 0x2D6B,0x2D6B,0x2D6B,0x2D6B,0x2D6B,0x2D6B,0x2D6B,0x2D6B
	.hword 0x318C,0x318C,0x318C,0x318C,0x318C,0x318C,0x318C,0x318C
	.hword 0x35AD,0x35AD,0x35AD,0x35AD,0x35AD,0x35AD,0x35AD,0x35AD
	.hword 0x39CE,0x39CE,0x39CE,0x39CE,0x39CE,0x39CE,0x39CE,0x39CE
	.hword 0x3DEF,0x3DEF,0x3DEF,0x3DEF,0x3DEF,0x3DEF,0x3DEF,0x3DEF

	.hword 0x4210,0x4210,0x4210,0x4210,0x4210,0x4210,0x4210,0x4210
	.hword 0x4631,0x4631,0x4631,0x4631,0x4631,0x4631,0x4631,0x4631
	.hword 0x4A52,0x4A52,0x4A52,0x4A52,0x4A52,0x4A52,0x4A52,0x4A52
	.hword 0x4E73,0x4E73,0x4E73,0x4E73,0x4E73,0x4E73,0x4E73,0x4E73
	.hword 0x5294,0x5294,0x5294,0x5294,0x5294,0x5294,0x5294,0x5294
	.hword 0x56B5,0x56B5,0x56B5,0x56B5,0x56B5,0x56B5,0x56B5,0x56B5
	.hword 0x5AD6,0x5AD6,0x5AD6,0x5AD6,0x5AD6,0x5AD6,0x5AD6,0x5AD6
	.hword 0x5EF7,0x5EF7,0x5EF7,0x5EF7,0x5EF7,0x5EF7,0x5EF7,0x5EF7

	.hword 0x6318,0x6318,0x6318,0x6318,0x6318,0x6318,0x6318,0x6318
	.hword 0x6739,0x6739,0x6739,0x6739,0x6739,0x6739,0x6739,0x6739
	.hword 0x6B5A,0x6B5A,0x6B5A,0x6B5A,0x6B5A,0x6B5A,0x6B5A,0x6B5A
	.hword 0x6F7B,0x6F7B,0x6F7B,0x6F7B,0x6F7B,0x6F7B,0x6F7B,0x6F7B
	.hword 0x739C,0x739C,0x739C,0x739C,0x739C,0x739C,0x739C,0x739C
	.hword 0x77BD,0x77BD,0x77BD,0x77BD,0x77BD,0x77BD,0x77BD,0x77BD
	.hword 0x7BDE,0x7BDE,0x7BDE,0x7BDE,0x7BDE,0x7BDE,0x7BDE,0x7BDE
	.hword 0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF

@}}BLOCK(door_closed)
