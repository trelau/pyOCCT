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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <GeomFill_SectionLaw.hxx>
#include <TopoDS_Shape.hxx>
#include <GeomAbs_Shape.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Edge.hxx>
#include <BRepFill_SectionLaw.hxx>
#include <Standard_Type.hxx>
#include <GeomFill_HArray1OfSectionLaw.hxx>
#include <TopTools_DataMapOfShapeInteger.hxx>
#include <BRepTools_WireExplorer.hxx>

void bind_BRepFill_SectionLaw(py::module &mod){

py::class_<BRepFill_SectionLaw, opencascade::handle<BRepFill_SectionLaw>, Standard_Transient> cls_BRepFill_SectionLaw(mod, "BRepFill_SectionLaw", "Build Section Law, with an Vertex, or an Wire");

// Fields

// Methods
cls_BRepFill_SectionLaw.def("NbLaw", (Standard_Integer (BRepFill_SectionLaw::*)() const) &BRepFill_SectionLaw::NbLaw, "None");
cls_BRepFill_SectionLaw.def("Law", (const opencascade::handle<GeomFill_SectionLaw> & (BRepFill_SectionLaw::*)(const Standard_Integer) const) &BRepFill_SectionLaw::Law, "None", py::arg("Index"));
cls_BRepFill_SectionLaw.def("IndexOfEdge", (Standard_Integer (BRepFill_SectionLaw::*)(const TopoDS_Shape &) const) &BRepFill_SectionLaw::IndexOfEdge, "None", py::arg("anEdge"));
cls_BRepFill_SectionLaw.def("IsConstant", (Standard_Boolean (BRepFill_SectionLaw::*)() const) &BRepFill_SectionLaw::IsConstant, "None");
cls_BRepFill_SectionLaw.def("IsUClosed", (Standard_Boolean (BRepFill_SectionLaw::*)() const) &BRepFill_SectionLaw::IsUClosed, "None");
cls_BRepFill_SectionLaw.def("IsVClosed", (Standard_Boolean (BRepFill_SectionLaw::*)() const) &BRepFill_SectionLaw::IsVClosed, "None");
cls_BRepFill_SectionLaw.def("IsDone", (Standard_Boolean (BRepFill_SectionLaw::*)() const) &BRepFill_SectionLaw::IsDone, "None");
cls_BRepFill_SectionLaw.def("IsVertex", (Standard_Boolean (BRepFill_SectionLaw::*)() const) &BRepFill_SectionLaw::IsVertex, "Say if the input shape is a vertex.");
cls_BRepFill_SectionLaw.def("ConcatenedLaw", (opencascade::handle<GeomFill_SectionLaw> (BRepFill_SectionLaw::*)() const) &BRepFill_SectionLaw::ConcatenedLaw, "None");
cls_BRepFill_SectionLaw.def("Continuity", (GeomAbs_Shape (BRepFill_SectionLaw::*)(const Standard_Integer, const Standard_Real) const) &BRepFill_SectionLaw::Continuity, "None", py::arg("Index"), py::arg("TolAngular"));
cls_BRepFill_SectionLaw.def("VertexTol", (Standard_Real (BRepFill_SectionLaw::*)(const Standard_Integer, const Standard_Real) const) &BRepFill_SectionLaw::VertexTol, "None", py::arg("Index"), py::arg("Param"));
cls_BRepFill_SectionLaw.def("Vertex", (TopoDS_Vertex (BRepFill_SectionLaw::*)(const Standard_Integer, const Standard_Real) const) &BRepFill_SectionLaw::Vertex, "None", py::arg("Index"), py::arg("Param"));
cls_BRepFill_SectionLaw.def("D0", (void (BRepFill_SectionLaw::*)(const Standard_Real, TopoDS_Shape &)) &BRepFill_SectionLaw::D0, "None", py::arg("U"), py::arg("S"));
cls_BRepFill_SectionLaw.def("Init", (void (BRepFill_SectionLaw::*)(const TopoDS_Wire &)) &BRepFill_SectionLaw::Init, "None", py::arg("W"));
cls_BRepFill_SectionLaw.def("CurrentEdge", (TopoDS_Edge (BRepFill_SectionLaw::*)()) &BRepFill_SectionLaw::CurrentEdge, "None");
cls_BRepFill_SectionLaw.def_static("get_type_name_", (const char * (*)()) &BRepFill_SectionLaw::get_type_name, "None");
cls_BRepFill_SectionLaw.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepFill_SectionLaw::get_type_descriptor, "None");
cls_BRepFill_SectionLaw.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepFill_SectionLaw::*)() const) &BRepFill_SectionLaw::DynamicType, "None");

// Enums

}