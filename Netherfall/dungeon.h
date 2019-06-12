//////////////////////////////////////////////////////////////////////
// OpenTibia - an opensource roleplaying game
//////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//////////////////////////////////////////////////////////////////////


#ifndef __OTSERV_DUNGEON_H__
#define __OTSERV_DUNGEON_H__

#include "definitions.h"
#include "tile.h"
#include "position.h"
#include "monsters.h"
#include "otsystem.h"

class Creature;
class Game;
class Spawn;

struct Wallset {
	uint32_t top;
	uint32_t left;
	uint32_t right;
	uint32_t bottom;
};

struct TileSet {
public:
	TileSet(uint32_t outerTileId, uint32_t innerTileId, Wallset walls) :
		outerTile(outerTileId)
		, innerTile(innerTileId)
		, wallset(walls) {}
	uint32_t outerTile;
	uint32_t innerTile;
	Wallset wallset;
private:
};

class DungeonType {
public:
	DungeonType(std::string name, TileSet set)
		: tileset(set)
		, typeName(name) {}
	TileSet tileset;

private:
	std::string typeName;
};

class Dungeon
{
public:
	Dungeon(uint16_t roomCount,
		uint8_t minRoomSize,
		uint8_t maxRoomSize,
		uint8_t pathWidth,
		DungeonType type,
		PositionEx startPos);

private:
	Position startPosition;
	

};

#endif
