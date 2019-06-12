//////////////////////////////////////////////////////////////////////
// OpenTibia - an opensource roleplaying game
//////////////////////////////////////////////////////////////////////
// Item represents an existing item.
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


#ifndef __OTSERV_MAGICATTR_H__
#define __OTSERV_MAGICATTR_H__

#include "definitions.h"
#include "thing.h"
#include "items.h"
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include <iostream>
#include <list>
#include <vector>
;

#pragma pack()
enum MagicAttrTypes {
	MAGICATTR_FIREDMG = 1,
	MAGICATTR_EARTHDMG = 2,
	MAGICATTR_ENERGYDMG = 3,
};

class MagicAttributes
{
public:
	MagicAttributes()
	{
		m_firstAttr = NULL;
		attribute_count = 0;
	}
	virtual ~MagicAttributes()
	{
		if(m_firstAttr)
		{
			deleteAttrs(m_firstAttr);
		}
	}
	int getAttributeCount() {return attribute_count;}
	int32_t getTypeAtPos(int32_t i) 
	{
		Attribute* attr = getAttributeAtPos(i);
		if (attr == NULL)
			return 0;
		return (int32_t)attr->type;
	} 
	
	int32_t  getWeightAtPos(int32_t i)  
	{
		Attribute* attr = getAttributeAtPos(i);
		if (attr == NULL)
			return 0;
		return (int32_t)attr->weight;
	}
	int32_t getAttributeWeightByType(int32_t type) {
		Attribute* attr = getAttrByType((MagicAttrTypes)type);
		if (attr == NULL)
			return 0;
		else
			return attr->weight;
			
		return 0;
	}
	void createAttribute(int32_t type, int32_t weight) {
		Attribute* attr = new Attribute((MagicAttrTypes)type, weight);
		addAttr(attr);
	}
	
protected:
	class Attribute
	{
	public:
		MagicAttrTypes type;
		int32_t weight;
		Attribute* next;
		Attribute(MagicAttrTypes _type, int32_t _weight){
			type = _type;
			weight = _weight;
			next = NULL;
		}

		Attribute(const Attribute &i){
			type = i.type;
			weight = i.weight;
			next = NULL;
			if(i.next){
				next = new Attribute(*i.next);
			}
		}
	};
	
protected:
	Attribute* m_firstAttr;
	uint32_t attribute_count;
	void removeAttribute(MagicAttrTypes type);
	void addAttr(Attribute* attr);
	Attribute* getAttrByType(MagicAttrTypes type);
	void deleteAttrs(Attribute* attr);
	Attribute* getAttributeAtPos(int32_t pos);
};



#endif
