
@{{BLOCK(shuttle)

@=======================================================================
@
@	shuttle, 64x64@4, 
@	+ palette 256 entries, not compressed
@	+ bitmap not compressed
@	Total size: 512 + 2048 = 2560
@
@	Time-stamp: 2025-02-13, 19:39:49
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global shuttleBitmap		@ 2048 unsigned chars
	.hidden shuttleBitmap
shuttleBitmap:
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x55000000,0x00000005,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x24500000,0x00000054,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x13450000,0x00000543,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x12345000,0x00005432,0x00000000,0x00000000,0x00000000

	.word 0x00000000,0x00000000,0x00000000,0x12234500,0x00054322,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x12223500,0x00053222,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x12222450,0x00542222,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x12222350,0x00532222,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x12122245,0x05422212,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x12322235,0x05322232,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x12222225,0x05222222,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x50000000,0x12223224,0x54223222,0x00000000,0x00000000,0x00000000

	.word 0x00000000,0x00000000,0x50000000,0x12224223,0x53224222,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x50000000,0x12225222,0x52225222,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x50000000,0x12225322,0x52235222,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x50000000,0x12225422,0x52245222,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x50000000,0x12125422,0x52245212,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x50000000,0x12325432,0x52345232,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x50000000,0x12221542,0x52451222,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x5A000000,0x12222152,0x52512222,0x0000000A,0x00000000,0x00000000

	.word 0x00000000,0x00000000,0x58A00000,0xFFF43212,0x521234FF,0x000000A8,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x586A0000,0xCCDFF432,0x5234FFDC,0x00000A68,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x5A67A000,0xCCDDEF42,0x524FEDDC,0x0000A76A,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x5877A000,0x555DEEF2,0x52FEED55,0x0000A778,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x5868A000,0x13455EF2,0x52FE5543,0x0000A868,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x5866A000,0x12234552,0x52554322,0x0000A668,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x5867A000,0x12223452,0x52543222,0x0000A768,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x5867A000,0x12222352,0x52532222,0x0000A768,0x00000000,0x00000000

	.word 0x00000000,0x00000000,0x5867A000,0x12212252,0x52522122,0x0000A768,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x5867A000,0x12232252,0x52522322,0x0000A768,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x4567A000,0x12222252,0x42522222,0x0000A765,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x1567A000,0x12222252,0x12522222,0x0000A765,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x2567A000,0x12222252,0x22522222,0x0000A765,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x2457A000,0x12355352,0x22535532,0x0000A754,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x2145A000,0x12522552,0x22552252,0x0000A541,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x22145000,0x13511552,0x22551153,0x00005412,0x00000000,0x00000000

	.word 0x00000000,0x00000000,0x22214500,0x15311353,0x23531135,0x00054122,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x22221450,0x15211254,0x24521125,0x00541222,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x22122145,0x54211245,0x25421124,0x05412212,0x00000000,0x00000000
	.word 0x00000000,0x50000000,0x22322214,0x54211245,0x25421124,0x54122232,0x00000000,0x00000000
	.word 0x00000000,0x45000000,0x22222221,0x53211235,0x25321123,0x41222222,0x00000005,0x00000000
	.word 0x00000000,0x14500000,0x22222122,0x53211235,0x25321123,0x12212222,0x00000054,0x00000000
	.word 0x00000000,0x21450000,0x22222322,0x53211235,0x25321123,0x22232222,0x00000541,0x00000000
	.word 0x00000000,0x22145000,0x22222222,0x53211235,0x25321123,0x22222222,0x00005412,0x00000000

	.word 0x00000000,0x12214500,0x21222222,0x53211235,0x25321123,0x12222221,0x00054122,0x00000000
	.word 0x00000000,0x32221450,0x23222222,0x53211235,0x25321123,0x32222223,0x00541222,0x00000000
	.word 0x00000000,0x22222150,0x22222222,0x53211235,0x25321123,0x22222222,0x00512222,0x00000000
	.word 0x00000000,0x22212250,0x22222222,0x53211235,0x25321123,0x22222222,0x00522122,0x00000000
	.word 0x00000000,0xA4232250,0xAAAAAAAA,0x54211245,0xA5421124,0xAAAAAAAA,0x00522324,0x00000000
	.word 0x00000000,0x7A222250,0x76666666,0x54311345,0x75431134,0x76666666,0x0052222A,0x00000000
	.word 0x00000000,0x6A222250,0x77777777,0xAA4AA4AA,0x7AA4AA4A,0x67777777,0x0052222A,0x00000000
	.word 0x00000000,0xAA222250,0xAAAAAAAA,0xA8A66A8A,0xAA8A66A8,0xAAAAAAAA,0x0052222A,0x00000000

	.word 0x00000000,0x00555550,0x89B00000,0xA876678A,0x8A876678,0x000000B9,0x00555550,0x00000000
	.word 0x00000000,0x00000000,0xBBB00000,0xA876678A,0xBA876678,0x000000BB,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0xAAAAAAAA,0x0AAAAAAA,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global shuttlePal		@ 512 unsigned chars
	.hidden shuttlePal
shuttlePal:
	.hword 0x0000,0x063F,0x01DD,0x0199,0x0135,0x00AF,0x318C,0x2529
	.hword 0x1CE7,0x14A5,0x1084,0x0C63,0x6A21,0x5180,0x4540,0x30E0
	.hword 0x0842,0x0842,0x0842,0x0842,0x0842,0x0842,0x0842,0x0842
	.hword 0x0C63,0x0C63,0x0C63,0x0C63,0x0C63,0x0C63,0x0C63,0x0C63
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

@}}BLOCK(shuttle)
