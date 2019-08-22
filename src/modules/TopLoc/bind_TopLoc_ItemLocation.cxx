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
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <TopLoc_Datum3D.hxx>
#include <Standard_TypeDef.hxx>
#include <TopLoc_Location.hxx>
#include <TopLoc_SListOfItemLocation.hxx>
#include <gp_Trsf.hxx>
#include <TopLoc_ItemLocation.hxx>

void bind_TopLoc_ItemLocation(py::module &mod){

py::class_<TopLoc_ItemLocation> cls_TopLoc_ItemLocation(mod, "TopLoc_ItemLocation", "An ItemLocation is an elementary coordinate system in a Location.");

// Constructors
cls_TopLoc_ItemLocation.def(py::init<const opencascade::handle<TopLoc_Datum3D> &, const Standard_Integer>(), py::arg("D"), py::arg("P"));

// Fields

// Methods
// cls_TopLoc_ItemLocation.def_static("operator new_", (void * (*)(size_t)) &TopLoc_ItemLocation::operator new, "None", py::arg("theSize"));
// cls_TopLoc_ItemLocation.def_static("operator delete_", (void (*)(void *)) &TopLoc_ItemLocation::operator delete, "None", py::arg("theAddress"));
// cls_TopLoc_ItemLocation.def_static("operator new[]_", (void * (*)(size_t)) &TopLoc_ItemLocation::operator new[], "None", py::arg("theSize"));
// cls_TopLoc_ItemLocation.def_static("operator delete[]_", (void (*)(void *)) &TopLoc_ItemLocation::operator delete[], "None", py::arg("theAddress"));
// cls_TopLoc_ItemLocation.def_static("operator new_", (void * (*)(size_t, void *)) &TopLoc_ItemLocation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopLoc_ItemLocation.def_static("operator delete_", (void (*)(void *, void *)) &TopLoc_ItemLocation::operator delete, "None", py::arg(""), py::arg(""));

// Enums

}