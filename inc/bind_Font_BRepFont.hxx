/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019-2020  Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#pragma once

#include <pyOCCT_Common.hxx>
#include <Font_BRepFont.hxx>

class Font_BRepFont_: public Font_BRepFont {
public:
    //! Empty constructor
    Standard_EXPORT Font_BRepFont_(): Font_BRepFont() {};

    //! Constructor with initialization.
    //! @param theFontPath FULL path to the font
    //! @param theSize     the face size in model units
    Standard_EXPORT Font_BRepFont_(
        const NCollection_String& theFontPath,
        const Standard_Real       theSize)
        : Font_BRepFont(theFontPath, theSize) {};

    //! Constructor with initialization.
    //! @param theFontName    the font name
    //! @param theFontAspect  the font style
    //! @param theSize        the face size in model units
    //! @param theStrictLevel search strict level for using aliases and fallback
    Standard_EXPORT Font_BRepFont_(
        const NCollection_String& theFontName,
        const Font_FontAspect     theFontAspect,
        const Standard_Real       theSize,
        const Font_StrictLevel    theStrictLevel = Font_StrictLevel_Any)
        : Font_BRepFont(theFontName, theFontAspect, theSize, theStrictLevel) {}

    // Redefine the new & del as public
    DEFINE_STANDARD_ALLOC
};
