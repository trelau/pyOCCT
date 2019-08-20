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
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_XYZ.hxx>
#include <Select3D_Pnt.hxx>

void bind_Select3D_Pnt(py::module &mod){

py::class_<Select3D_Pnt, std::unique_ptr<Select3D_Pnt>> cls_Select3D_Pnt(mod, "Select3D_Pnt", "None");

// Constructors

// Fields
cls_Select3D_Pnt.def_readwrite("x", &Select3D_Pnt::x, "None");
cls_Select3D_Pnt.def_readwrite("y", &Select3D_Pnt::y, "None");
cls_Select3D_Pnt.def_readwrite("z", &Select3D_Pnt::z, "None");

// Methods
// cls_Select3D_Pnt.def("operator=", (gp_Pnt (Select3D_Pnt::*)(const gp_Pnt &)) &Select3D_Pnt::operator=, "None", py::arg("thePnt"));

// Enums

}