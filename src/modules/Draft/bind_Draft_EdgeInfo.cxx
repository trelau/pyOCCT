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
#include <Standard_TypeDef.hxx>
#include <TopoDS_Face.hxx>
#include <gp_Pnt.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <Geom2d_Curve.hxx>
#include <Draft_EdgeInfo.hxx>

void bind_Draft_EdgeInfo(py::module &mod){

py::class_<Draft_EdgeInfo, std::unique_ptr<Draft_EdgeInfo, Deleter<Draft_EdgeInfo>>> cls_Draft_EdgeInfo(mod, "Draft_EdgeInfo", "None");

// Constructors
cls_Draft_EdgeInfo.def(py::init<>());
cls_Draft_EdgeInfo.def(py::init<const Standard_Boolean>(), py::arg("HasNewGeometry"));

// Fields

// Methods
// cls_Draft_EdgeInfo.def_static("operator new_", (void * (*)(size_t)) &Draft_EdgeInfo::operator new, "None", py::arg("theSize"));
// cls_Draft_EdgeInfo.def_static("operator delete_", (void (*)(void *)) &Draft_EdgeInfo::operator delete, "None", py::arg("theAddress"));
// cls_Draft_EdgeInfo.def_static("operator new[]_", (void * (*)(size_t)) &Draft_EdgeInfo::operator new[], "None", py::arg("theSize"));
// cls_Draft_EdgeInfo.def_static("operator delete[]_", (void (*)(void *)) &Draft_EdgeInfo::operator delete[], "None", py::arg("theAddress"));
// cls_Draft_EdgeInfo.def_static("operator new_", (void * (*)(size_t, void *)) &Draft_EdgeInfo::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Draft_EdgeInfo.def_static("operator delete_", (void (*)(void *, void *)) &Draft_EdgeInfo::operator delete, "None", py::arg(""), py::arg(""));
cls_Draft_EdgeInfo.def("Add", (void (Draft_EdgeInfo::*)(const TopoDS_Face &)) &Draft_EdgeInfo::Add, "None", py::arg("F"));
cls_Draft_EdgeInfo.def("RootFace", (void (Draft_EdgeInfo::*)(const TopoDS_Face &)) &Draft_EdgeInfo::RootFace, "None", py::arg("F"));
cls_Draft_EdgeInfo.def("Tangent", (void (Draft_EdgeInfo::*)(const gp_Pnt &)) &Draft_EdgeInfo::Tangent, "None", py::arg("P"));
cls_Draft_EdgeInfo.def("IsTangent", (Standard_Boolean (Draft_EdgeInfo::*)(gp_Pnt &) const) &Draft_EdgeInfo::IsTangent, "None", py::arg("P"));
cls_Draft_EdgeInfo.def("NewGeometry", (Standard_Boolean (Draft_EdgeInfo::*)() const) &Draft_EdgeInfo::NewGeometry, "None");
cls_Draft_EdgeInfo.def("SetNewGeometry", (void (Draft_EdgeInfo::*)(const Standard_Boolean)) &Draft_EdgeInfo::SetNewGeometry, "None", py::arg("NewGeom"));
cls_Draft_EdgeInfo.def("Geometry", (const opencascade::handle<Geom_Curve> & (Draft_EdgeInfo::*)() const) &Draft_EdgeInfo::Geometry, "None");
cls_Draft_EdgeInfo.def("FirstFace", (const TopoDS_Face & (Draft_EdgeInfo::*)() const) &Draft_EdgeInfo::FirstFace, "None");
cls_Draft_EdgeInfo.def("SecondFace", (const TopoDS_Face & (Draft_EdgeInfo::*)() const) &Draft_EdgeInfo::SecondFace, "None");
cls_Draft_EdgeInfo.def("FirstPC", (const opencascade::handle<Geom2d_Curve> & (Draft_EdgeInfo::*)() const) &Draft_EdgeInfo::FirstPC, "None");
cls_Draft_EdgeInfo.def("SecondPC", (const opencascade::handle<Geom2d_Curve> & (Draft_EdgeInfo::*)() const) &Draft_EdgeInfo::SecondPC, "None");
cls_Draft_EdgeInfo.def("ChangeGeometry", (opencascade::handle<Geom_Curve> & (Draft_EdgeInfo::*)()) &Draft_EdgeInfo::ChangeGeometry, "None");
cls_Draft_EdgeInfo.def("ChangeFirstPC", (opencascade::handle<Geom2d_Curve> & (Draft_EdgeInfo::*)()) &Draft_EdgeInfo::ChangeFirstPC, "None");
cls_Draft_EdgeInfo.def("ChangeSecondPC", (opencascade::handle<Geom2d_Curve> & (Draft_EdgeInfo::*)()) &Draft_EdgeInfo::ChangeSecondPC, "None");
cls_Draft_EdgeInfo.def("RootFace", (const TopoDS_Face & (Draft_EdgeInfo::*)() const) &Draft_EdgeInfo::RootFace, "None");
cls_Draft_EdgeInfo.def("Tolerance", (void (Draft_EdgeInfo::*)(const Standard_Real)) &Draft_EdgeInfo::Tolerance, "None", py::arg("tol"));
cls_Draft_EdgeInfo.def("Tolerance", (Standard_Real (Draft_EdgeInfo::*)() const) &Draft_EdgeInfo::Tolerance, "None");

// Enums

}