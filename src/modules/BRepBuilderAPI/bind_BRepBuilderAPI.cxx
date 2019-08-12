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
#include <Geom_Plane.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepBuilderAPI_Command.hxx>
#include <BRepBuilderAPI_MakeShape.hxx>
#include <BRepBuilderAPI_MakeVertex.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepBuilderAPI_MakeEdge2d.hxx>
#include <BRepBuilderAPI_MakePolygon.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <BRepBuilderAPI_FindPlane.hxx>
#include <BRepBuilderAPI_Sewing.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepBuilderAPI_MakeShell.hxx>
#include <BRepBuilderAPI_MakeSolid.hxx>
#include <BRepBuilderAPI_ModifyShape.hxx>
#include <BRepBuilderAPI_Transform.hxx>
#include <BRepBuilderAPI_NurbsConvert.hxx>
#include <BRepBuilderAPI_GTransform.hxx>
#include <BRepBuilderAPI_Copy.hxx>
#include <BRepBuilderAPI_Collect.hxx>
#include <BRepBuilderAPI.hxx>

void bind_BRepBuilderAPI(py::module &mod){

py::class_<BRepBuilderAPI, std::unique_ptr<BRepBuilderAPI, Deleter<BRepBuilderAPI>>> cls_BRepBuilderAPI(mod, "BRepBuilderAPI", "The BRepBuilderAPI package provides an Application Programming Interface for the BRep topology data structure.");

// Constructors

// Fields

// Methods
// cls_BRepBuilderAPI.def_static("operator new_", (void * (*)(size_t)) &BRepBuilderAPI::operator new, "None", py::arg("theSize"));
// cls_BRepBuilderAPI.def_static("operator delete_", (void (*)(void *)) &BRepBuilderAPI::operator delete, "None", py::arg("theAddress"));
// cls_BRepBuilderAPI.def_static("operator new[]_", (void * (*)(size_t)) &BRepBuilderAPI::operator new[], "None", py::arg("theSize"));
// cls_BRepBuilderAPI.def_static("operator delete[]_", (void (*)(void *)) &BRepBuilderAPI::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBuilderAPI.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBuilderAPI::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBuilderAPI.def_static("operator delete_", (void (*)(void *, void *)) &BRepBuilderAPI::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBuilderAPI.def_static("Plane_", (void (*)(const opencascade::handle<Geom_Plane> &)) &BRepBuilderAPI::Plane, "Sets the current plane.", py::arg("P"));
cls_BRepBuilderAPI.def_static("Plane_", (const opencascade::handle<Geom_Plane> & (*)()) &BRepBuilderAPI::Plane, "Returns the current plane.");
cls_BRepBuilderAPI.def_static("Precision_", (void (*)(const Standard_Real)) &BRepBuilderAPI::Precision, "Sets the default precision. The current Precision is returned.", py::arg("P"));
cls_BRepBuilderAPI.def_static("Precision_", (Standard_Real (*)()) &BRepBuilderAPI::Precision, "Returns the default precision.");

// Enums

}