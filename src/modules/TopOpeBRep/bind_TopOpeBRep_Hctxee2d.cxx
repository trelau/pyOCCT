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
#include <Standard_Transient.hxx>
#include <TopoDS_Edge.hxx>
#include <BRepAdaptor_Surface.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <Geom2dAdaptor_Curve.hxx>
#include <IntRes2d_Domain.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRep_Hctxee2d.hxx>
#include <Standard_Type.hxx>

void bind_TopOpeBRep_Hctxee2d(py::module &mod){

py::class_<TopOpeBRep_Hctxee2d, opencascade::handle<TopOpeBRep_Hctxee2d>, Standard_Transient> cls_TopOpeBRep_Hctxee2d(mod, "TopOpeBRep_Hctxee2d", "None");

// Constructors
cls_TopOpeBRep_Hctxee2d.def(py::init<>());

// Fields

// Methods
cls_TopOpeBRep_Hctxee2d.def("SetEdges", (void (TopOpeBRep_Hctxee2d::*)(const TopoDS_Edge &, const TopoDS_Edge &, const BRepAdaptor_Surface &, const BRepAdaptor_Surface &)) &TopOpeBRep_Hctxee2d::SetEdges, "None", py::arg("E1"), py::arg("E2"), py::arg("BAS1"), py::arg("BAS2"));
cls_TopOpeBRep_Hctxee2d.def("Edge", (const TopoDS_Shape & (TopOpeBRep_Hctxee2d::*)(const Standard_Integer) const) &TopOpeBRep_Hctxee2d::Edge, "None", py::arg("I"));
cls_TopOpeBRep_Hctxee2d.def("Curve", (const Geom2dAdaptor_Curve & (TopOpeBRep_Hctxee2d::*)(const Standard_Integer) const) &TopOpeBRep_Hctxee2d::Curve, "None", py::arg("I"));
cls_TopOpeBRep_Hctxee2d.def("Domain", (const IntRes2d_Domain & (TopOpeBRep_Hctxee2d::*)(const Standard_Integer) const) &TopOpeBRep_Hctxee2d::Domain, "None", py::arg("I"));
cls_TopOpeBRep_Hctxee2d.def_static("get_type_name_", (const char * (*)()) &TopOpeBRep_Hctxee2d::get_type_name, "None");
cls_TopOpeBRep_Hctxee2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRep_Hctxee2d::get_type_descriptor, "None");
cls_TopOpeBRep_Hctxee2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRep_Hctxee2d::*)() const) &TopOpeBRep_Hctxee2d::DynamicType, "None");

// Enums

}