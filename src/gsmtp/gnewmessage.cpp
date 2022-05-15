//
// Copyright (C) 2001-2022 Graeme Walker <graeme_walker@users.sourceforge.net>
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// ===
///
/// \file gnewmessage.cpp
///

#include "gdef.h"
#include "gmessagestore.h"
#include "gnewmessage.h"
#include <iostream>

void GSmtp::NewMessage::addContentLine( const std::string & line )
{
	addContent( line.data() , line.size() ) ;
	addContent( "\r\n" , 2U ) ;
}

