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
#include <Geom_Point.hxx>
#include <Standard_TypeDef.hxx>
#include <StdPrs_ToolPoint.hxx>

void bind_StdPrs_ToolPoint(py::module &mod){

py::class_<StdPrs_ToolPoint, std::unique_ptr<StdPrs_ToolPoint, Deleter<StdPrs_ToolPoint>>> cls_StdPrs_ToolPoint(mod, "StdPrs_ToolPoint", "None");

// Constructors

// Fields

// Methods
// cls_StdPrs_ToolPoint.def_static("operator new_", (void * (*)(size_t)) &StdPrs_ToolPoint::operator new, "None", py::arg("theSize"));
// cls_StdPrs_ToolPoint.def_static("operator delete_", (void (*)(void *)) &StdPrs_ToolPoint::operator delete, "None", py::arg("theAddress"));
// cls_StdPrs_ToolPoint.def_static("operator new[]_", (void * (*)(size_t)) &StdPrs_ToolPoint::operator new[], "None", py::arg("theSize"));
// cls_StdPrs_ToolPoint.def_static("operator delete[]_", (void (*)(void *)) &StdPrs_ToolPoint::operator delete[], "None", py::arg("theAddress"));
// cls_StdPrs_ToolPoint.def_static("operator new_", (void * (*)(size_t, void *)) &StdPrs_ToolPoint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StdPrs_ToolPoint.def_static("operator delete_", (void (*)(void *, void *)) &StdPrs_ToolPoint::operator delete, "None", py::arg(""), py::arg(""));
cls_StdPrs_ToolPoint.def_static("Coord_", [](const opencascade::handle<Geom_Point> & aPoint, Standard_Real & X, Standard_Real & Y, Standard_Real & Z){ StdPrs_ToolPoint::Coord(aPoint, X, Y, Z); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(X, Y, Z); }, "None", py::arg("aPoint"), py::arg("X"), py::arg("Y"), py::arg("Z"));

// Enums

}