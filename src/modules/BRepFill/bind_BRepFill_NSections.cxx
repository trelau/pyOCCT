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
#include <BRepFill_SectionLaw.hxx>
#include <TopTools_SequenceOfShape.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomFill_SequenceOfTrsf.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <Standard_Handle.hxx>
#include <GeomFill_SectionLaw.hxx>
#include <GeomAbs_Shape.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepFill_NSections.hxx>
#include <Standard_Type.hxx>
#include <TopTools_HArray2OfShape.hxx>
#include <Geom_BSplineSurface.hxx>

void bind_BRepFill_NSections(py::module &mod){

py::class_<BRepFill_NSections, opencascade::handle<BRepFill_NSections>, BRepFill_SectionLaw> cls_BRepFill_NSections(mod, "BRepFill_NSections", "Build Section Law, with N Sections");

// Constructors
cls_BRepFill_NSections.def(py::init<const TopTools_SequenceOfShape &>(), py::arg("S"));
cls_BRepFill_NSections.def(py::init<const TopTools_SequenceOfShape &, const Standard_Boolean>(), py::arg("S"), py::arg("Build"));
cls_BRepFill_NSections.def(py::init<const TopTools_SequenceOfShape &, const GeomFill_SequenceOfTrsf &, const TColStd_SequenceOfReal &, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("Trsfs"), py::arg("P"), py::arg("VF"), py::arg("VL"));
cls_BRepFill_NSections.def(py::init<const TopTools_SequenceOfShape &, const GeomFill_SequenceOfTrsf &, const TColStd_SequenceOfReal &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("S"), py::arg("Trsfs"), py::arg("P"), py::arg("VF"), py::arg("VL"), py::arg("Build"));

// Fields

// Methods
cls_BRepFill_NSections.def("IsVertex", (Standard_Boolean (BRepFill_NSections::*)() const) &BRepFill_NSections::IsVertex, "Say if the input shape is a vertex.");
cls_BRepFill_NSections.def("IsConstant", (Standard_Boolean (BRepFill_NSections::*)() const) &BRepFill_NSections::IsConstant, "Say if the Law is Constant.");
cls_BRepFill_NSections.def("ConcatenedLaw", (opencascade::handle<GeomFill_SectionLaw> (BRepFill_NSections::*)() const) &BRepFill_NSections::ConcatenedLaw, "Give the law build on a concatened section");
cls_BRepFill_NSections.def("Continuity", (GeomAbs_Shape (BRepFill_NSections::*)(const Standard_Integer, const Standard_Real) const) &BRepFill_NSections::Continuity, "None", py::arg("Index"), py::arg("TolAngular"));
cls_BRepFill_NSections.def("VertexTol", (Standard_Real (BRepFill_NSections::*)(const Standard_Integer, const Standard_Real) const) &BRepFill_NSections::VertexTol, "None", py::arg("Index"), py::arg("Param"));
cls_BRepFill_NSections.def("Vertex", (TopoDS_Vertex (BRepFill_NSections::*)(const Standard_Integer, const Standard_Real) const) &BRepFill_NSections::Vertex, "None", py::arg("Index"), py::arg("Param"));
cls_BRepFill_NSections.def("D0", (void (BRepFill_NSections::*)(const Standard_Real, TopoDS_Shape &)) &BRepFill_NSections::D0, "None", py::arg("Param"), py::arg("S"));
cls_BRepFill_NSections.def_static("get_type_name_", (const char * (*)()) &BRepFill_NSections::get_type_name, "None");
cls_BRepFill_NSections.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepFill_NSections::get_type_descriptor, "None");
cls_BRepFill_NSections.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepFill_NSections::*)() const) &BRepFill_NSections::DynamicType, "None");

// Enums

}