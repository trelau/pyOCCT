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
#include <TopoDS_TFace.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <Poly_Triangulation.hxx>
#include <TopLoc_Location.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_TShape.hxx>
#include <BRep_TFace.hxx>
#include <Standard_Type.hxx>

void bind_BRep_TFace(py::module &mod){

py::class_<BRep_TFace, opencascade::handle<BRep_TFace>, TopoDS_TFace> cls_BRep_TFace(mod, "BRep_TFace", "The Tface from BRep is based on the TFace from TopoDS. The TFace contains :");

// Constructors
cls_BRep_TFace.def(py::init<>());

// Fields

// Methods
cls_BRep_TFace.def("Surface", (const opencascade::handle<Geom_Surface> & (BRep_TFace::*)() const) &BRep_TFace::Surface, "None");
cls_BRep_TFace.def("Triangulation", (const opencascade::handle<Poly_Triangulation> & (BRep_TFace::*)() const) &BRep_TFace::Triangulation, "None");
cls_BRep_TFace.def("Location", (const TopLoc_Location & (BRep_TFace::*)() const) &BRep_TFace::Location, "None");
cls_BRep_TFace.def("Tolerance", (Standard_Real (BRep_TFace::*)() const) &BRep_TFace::Tolerance, "None");
cls_BRep_TFace.def("Surface", (void (BRep_TFace::*)(const opencascade::handle<Geom_Surface> &)) &BRep_TFace::Surface, "None", py::arg("S"));
cls_BRep_TFace.def("Triangulation", (void (BRep_TFace::*)(const opencascade::handle<Poly_Triangulation> &)) &BRep_TFace::Triangulation, "None", py::arg("T"));
cls_BRep_TFace.def("Location", (void (BRep_TFace::*)(const TopLoc_Location &)) &BRep_TFace::Location, "None", py::arg("L"));
cls_BRep_TFace.def("Tolerance", (void (BRep_TFace::*)(const Standard_Real)) &BRep_TFace::Tolerance, "None", py::arg("T"));
cls_BRep_TFace.def("NaturalRestriction", (Standard_Boolean (BRep_TFace::*)() const) &BRep_TFace::NaturalRestriction, "None");
cls_BRep_TFace.def("NaturalRestriction", (void (BRep_TFace::*)(const Standard_Boolean)) &BRep_TFace::NaturalRestriction, "None", py::arg("N"));
cls_BRep_TFace.def("EmptyCopy", (opencascade::handle<TopoDS_TShape> (BRep_TFace::*)() const) &BRep_TFace::EmptyCopy, "Returns a copy of the TShape with no sub-shapes. The new Face has no triangulation.");
cls_BRep_TFace.def_static("get_type_name_", (const char * (*)()) &BRep_TFace::get_type_name, "None");
cls_BRep_TFace.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRep_TFace::get_type_descriptor, "None");
cls_BRep_TFace.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRep_TFace::*)() const) &BRep_TFace::DynamicType, "None");

// Enums

}