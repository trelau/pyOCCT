/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

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
#include <pyOCCT_Common.hxx>
#include <Graphic3d_Vec2.hxx>
#include <Graphic3d_CameraTile.hxx>
#include <Standard_TypeDef.hxx>

void bind_Graphic3d_CameraTile(py::module &mod){

py::class_<Graphic3d_CameraTile, std::unique_ptr<Graphic3d_CameraTile>> cls_Graphic3d_CameraTile(mod, "Graphic3d_CameraTile", "Class defines the area (Tile) inside a view.");

// Constructors
cls_Graphic3d_CameraTile.def(py::init<>());

// Fields
cls_Graphic3d_CameraTile.def_readwrite("TotalSize", &Graphic3d_CameraTile::TotalSize, "total size of the View area, in pixels");
cls_Graphic3d_CameraTile.def_readwrite("TileSize", &Graphic3d_CameraTile::TileSize, "size of the Tile, in pixels");
cls_Graphic3d_CameraTile.def_readwrite("Offset", &Graphic3d_CameraTile::Offset, "the lower-left corner of the Tile relative to the View area (or upper-left if IsTopDown is true), in pixels");
cls_Graphic3d_CameraTile.def_readwrite("IsTopDown", &Graphic3d_CameraTile::IsTopDown, "indicate the offset coordinate system - lower-left (default) or top-down");

// Methods
cls_Graphic3d_CameraTile.def("IsValid", (bool (Graphic3d_CameraTile::*)() const) &Graphic3d_CameraTile::IsValid, "Return true if Tile has been defined.");
cls_Graphic3d_CameraTile.def("OffsetLowerLeft", (Graphic3d_Vec2i (Graphic3d_CameraTile::*)() const) &Graphic3d_CameraTile::OffsetLowerLeft, "Return offset position from lower-left corner.");
cls_Graphic3d_CameraTile.def("Cropped", (Graphic3d_CameraTile (Graphic3d_CameraTile::*)() const) &Graphic3d_CameraTile::Cropped, "Return the copy cropped by total size");
cls_Graphic3d_CameraTile.def("__eq__", (bool (Graphic3d_CameraTile::*)(const Graphic3d_CameraTile &) const) &Graphic3d_CameraTile::operator==, py::is_operator(), "Equality check.", py::arg("theOther"));

// Enums

}