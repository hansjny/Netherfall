//////////////////////////////////////////////////////////////////////
// OpenTibia - an opensource roleplaying game
//////////////////////////////////////////////////////////////////////
// Represents an item
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

#include "magicattribute.h"
#include "configmanager.h"
#include "game.h"
#include "weapons.h"
#include <iostream>
#include <sstream>
#include <iomanip>

extern Game g_game;
extern Weapons* g_weapons;
extern ConfigManager g_config;

// bool ItemAttributes::hasAttribute(itemAttrTypes type) const
// {
// 	if(!validateIntAttrType(type))
// 		return false;

// 	Attribute* attr = getAttrConst(type);
// 	if(attr){
// 		return true;
// 	}

// 	return false;
// }

MagicAttributes::Attribute* MagicAttributes::getAttributeAtPos(int32_t pos)
{
	Attribute* curAttr = m_firstAttr;
	int32_t curPos = 0;
	while(curPos++ != pos){
		if (curAttr->next != NULL) 
			curAttr = curAttr->next;
		else 
			return NULL;
	}
	return curAttr;
}

void MagicAttributes::removeAttribute(MagicAttrTypes type)
{
	Attribute* prevAttr = NULL;
	Attribute* curAttr = m_firstAttr;
	while(curAttr != NULL){
		if(curAttr->type == type){
			if(prevAttr){
				prevAttr->next = curAttr->next;
			}
			else{
				m_firstAttr = curAttr->next;
			}

			delete curAttr;
			attribute_count--;
			return;
		}
		prevAttr = curAttr;
		curAttr = curAttr->next;
	} 
}

MagicAttributes::Attribute* MagicAttributes::getAttrByType(MagicAttrTypes type) {
	Attribute* curAttr = m_firstAttr;
	 while(curAttr != NULL){
		if(curAttr->type == type){
			return curAttr;
		}
		curAttr = curAttr->next;
	}
	return NULL;
}

void MagicAttributes::addAttr(Attribute* attr)
{
	if(m_firstAttr){
		Attribute* curAttr = m_firstAttr;
		while(curAttr->next){
			curAttr = curAttr->next;
		}
		curAttr->next = attr;
	}
	else{
		m_firstAttr = attr;
	}
	attribute_count++;
}

void MagicAttributes::deleteAttrs(Attribute* attr)
{
	if(attr){
		Attribute* next_attr = attr->next;
		attr->next = NULL;
		if(next_attr){
			deleteAttrs(next_attr);
		}
		delete attr;
	}
	attribute_count = 0;
}
