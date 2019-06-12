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


#include "otpch.h"

#include "game.h"
#include "position.h"
#include "dungeon.h"
#include "tile.h"

extern Game g_game;

Dungeon::Dungeon(uint16_t roomCount,
	uint8_t minRoomSize,
	uint8_t maxRoomSize,
	uint8_t pathWidth,
	DungeonType type,
	PositionEx startPos) :
	startPosition(Position(startPos.x, startPos.y, startPos.z))
{
	std::cout << "Let's make a dungeon boys! " << std::endl;
	Tile *tile;
	Item* newItem = Item::CreateItem(type.tileset.innerTile);

	tile = g_game.getMap()->getTile(startPos.x, startPos.y, startPos.z);

	if (tile == NULL) {
		tile = new StaticTile(startPos.x, startPos.y, startPos.z);
		g_game.getMap()->setTile(startPos.x, startPos.y, startPos.z, tile);
	}
	g_game.internalAddItem(tile, newItem, INDEX_WHEREEVER, FLAG_NOLIMIT);
}


