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
#include <TopoDS_Vertex.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Wire.hxx>
#include <Standard_Handle.hxx>
#include <Law_Function.hxx>
#include <GeomFill_SectionLaw.hxx>
#include <GeomAbs_Shape.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Edge.hxx>
#include <BRepFill_ShapeLaw.hxx>
#include <Standard_Type.hxx>
#include <TopTools_HArray1OfShape.hxx>

void bind_BRepFill_ShapeLaw(py::module &mod){

py::class_<BRepFill_ShapeLaw, opencascade::handle<BRepFill_ShapeLaw>, BRepFill_SectionLaw> cls_BRepFill_ShapeLaw(mod, "BRepFill_ShapeLaw", "Build Section Law, with an Vertex, or an Wire");

// Constructors
cls_BRepFill_ShapeLaw.def(py::init<const TopoDS_Vertex &>(), py::arg("V"));
cls_BRepFill_ShapeLaw.def(py::init<const TopoDS_Vertex &, const Standard_Boolean>(), py::arg("V"), py::arg("Build"));
cls_BRepFill_ShapeLaw.def(py::init<const TopoDS_Wire &>(), py::arg("W"));
cls_BRepFill_ShapeLaw.def(py::init<const TopoDS_Wire &, const Standard_Boolean>(), py::arg("W"), py::arg("Build"));
cls_BRepFill_ShapeLaw.def(py::init<const TopoDS_Wire &, const opencascade::handle<Law_Function> &>(), py::arg("W"), py::arg("L"));
cls_BRepFill_ShapeLaw.def(py::init<const TopoDS_Wire &, const opencascade::handle<Law_Function> &, const Standard_Boolean>(), py::arg("W"), py::arg("L"), py::arg("Build"));

// Fields

// Methods
cls_BRepFill_ShapeLaw.def("IsVertex", (Standard_Boolean (BRepFill_ShapeLaw::*)() const) &BRepFill_ShapeLaw::IsVertex, "Say if the input shape is a vertex.");
cls_BRepFill_ShapeLaw.def("IsConstant", (Standard_Boolean (BRepFill_ShapeLaw::*)() const) &BRepFill_ShapeLaw::IsConstant, "Say if the Law is Constant.");
cls_BRepFill_ShapeLaw.def("ConcatenedLaw", (opencascade::handle<GeomFill_SectionLaw> (BRepFill_ShapeLaw::*)() const) &BRepFill_ShapeLaw::ConcatenedLaw, "Give the law build on a concaneted section");
cls_BRepFill_ShapeLaw.def("Continuity", (GeomAbs_Shape (BRepFill_ShapeLaw::*)(const Standard_Integer, const Standard_Real) const) &BRepFill_ShapeLaw::Continuity, "None", py::arg("Index"), py::arg("TolAngular"));
cls_BRepFill_ShapeLaw.def("VertexTol", (Standard_Real (BRepFill_ShapeLaw::*)(const Standard_Integer, const Standard_Real) const) &BRepFill_ShapeLaw::VertexTol, "None", py::arg("Index"), py::arg("Param"));
cls_BRepFill_ShapeLaw.def("Vertex", (TopoDS_Vertex (BRepFill_ShapeLaw::*)(const Standard_Integer, const Standard_Real) const) &BRepFill_ShapeLaw::Vertex, "None", py::arg("Index"), py::arg("Param"));
cls_BRepFill_ShapeLaw.def("D0", (void (BRepFill_ShapeLaw::*)(const Standard_Real, TopoDS_Shape &)) &BRepFill_ShapeLaw::D0, "None", py::arg("Param"), py::arg("S"));
cls_BRepFill_ShapeLaw.def("Edge", (const TopoDS_Edge & (BRepFill_ShapeLaw::*)(const Standard_Integer) const) &BRepFill_ShapeLaw::Edge, "None", py::arg("Index"));
cls_BRepFill_ShapeLaw.def_static("get_type_name_", (const char * (*)()) &BRepFill_ShapeLaw::get_type_name, "None");
cls_BRepFill_ShapeLaw.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepFill_ShapeLaw::get_type_descriptor, "None");
cls_BRepFill_ShapeLaw.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepFill_ShapeLaw::*)() const) &BRepFill_ShapeLaw::DynamicType, "None");

// Enums

}