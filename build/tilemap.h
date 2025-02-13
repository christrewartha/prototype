
//{{BLOCK(tilemap)

//======================================================================
//
//	tilemap, 256x256@8, 
//	+ palette 256 entries, not compressed
//	+ 97 tiles (t|f reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 6208 + 2048 = 8768
//
//	Time-stamp: 2025-02-13, 19:39:50
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_TILEMAP_H
#define GRIT_TILEMAP_H

#define tilemapTilesLen 6208
extern const unsigned int tilemapTiles[1552];

#define tilemapMapLen 2048
extern const unsigned short tilemapMap[1024];

#define tilemapPalLen 512
extern const unsigned short tilemapPal[256];

#endif // GRIT_TILEMAP_H

//}}BLOCK(tilemap)
