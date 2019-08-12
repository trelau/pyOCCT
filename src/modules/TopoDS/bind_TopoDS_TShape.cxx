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
#include <TopAbs_ShapeEnum.hxx>
#include <Standard_Handle.hxx>
#include <TopoDS_TShape.hxx>
#include <TopoDS_Iterator.hxx>
#include <TopoDS_Builder.hxx>
#include <Standard_Type.hxx>
#include <TopoDS_ListOfShape.hxx>

void bind_TopoDS_TShape(py::module &mod){

py::class_<TopoDS_TShape, opencascade::handle<TopoDS_TShape>, Standard_Transient> cls_TopoDS_TShape(mod, "TopoDS_TShape", "A TShape is a topological structure describing a set of points in a 2D or 3D space.");

// Fields

// Methods
cls_TopoDS_TShape.def("Free", (Standard_Boolean (TopoDS_TShape::*)() const) &TopoDS_TShape::Free, "Returns the free flag.");
cls_TopoDS_TShape.def("Free", (void (TopoDS_TShape::*)(const Standard_Boolean)) &TopoDS_TShape::Free, "Sets the free flag.", py::arg("F"));
cls_TopoDS_TShape.def("Locked", (Standard_Boolean (TopoDS_TShape::*)() const) &TopoDS_TShape::Locked, "Returns the locked flag.");
cls_TopoDS_TShape.def("Locked", (void (TopoDS_TShape::*)(const Standard_Boolean)) &TopoDS_TShape::Locked, "Sets the locked flag.", py::arg("F"));
cls_TopoDS_TShape.def("Modified", (Standard_Boolean (TopoDS_TShape::*)() const) &TopoDS_TShape::Modified, "Returns the modification flag.");
cls_TopoDS_TShape.def("Modified", (void (TopoDS_TShape::*)(const Standard_Boolean)) &TopoDS_TShape::Modified, "Sets the modification flag.", py::arg("M"));
cls_TopoDS_TShape.def("Checked", (Standard_Boolean (TopoDS_TShape::*)() const) &TopoDS_TShape::Checked, "Returns the checked flag.");
cls_TopoDS_TShape.def("Checked", (void (TopoDS_TShape::*)(const Standard_Boolean)) &TopoDS_TShape::Checked, "Sets the checked flag.", py::arg("C"));
cls_TopoDS_TShape.def("Orientable", (Standard_Boolean (TopoDS_TShape::*)() const) &TopoDS_TShape::Orientable, "Returns the orientability flag.");
cls_TopoDS_TShape.def("Orientable", (void (TopoDS_TShape::*)(const Standard_Boolean)) &TopoDS_TShape::Orientable, "Sets the orientability flag.", py::arg("C"));
cls_TopoDS_TShape.def("Closed", (Standard_Boolean (TopoDS_TShape::*)() const) &TopoDS_TShape::Closed, "Returns the closedness flag.");
cls_TopoDS_TShape.def("Closed", (void (TopoDS_TShape::*)(const Standard_Boolean)) &TopoDS_TShape::Closed, "Sets the closedness flag.", py::arg("C"));
cls_TopoDS_TShape.def("Infinite", (Standard_Boolean (TopoDS_TShape::*)() const) &TopoDS_TShape::Infinite, "Returns the infinity flag.");
cls_TopoDS_TShape.def("Infinite", (void (TopoDS_TShape::*)(const Standard_Boolean)) &TopoDS_TShape::Infinite, "Sets the infinity flag.", py::arg("C"));
cls_TopoDS_TShape.def("Convex", (Standard_Boolean (TopoDS_TShape::*)() const) &TopoDS_TShape::Convex, "Returns the convexness flag.");
cls_TopoDS_TShape.def("Convex", (void (TopoDS_TShape::*)(const Standard_Boolean)) &TopoDS_TShape::Convex, "Sets the convexness flag.", py::arg("C"));
cls_TopoDS_TShape.def("ShapeType", (TopAbs_ShapeEnum (TopoDS_TShape::*)() const) &TopoDS_TShape::ShapeType, "Returns the type as a term of the ShapeEnum enum : VERTEX, EDGE, WIRE, FACE, ....");
cls_TopoDS_TShape.def("EmptyCopy", (opencascade::handle<TopoDS_TShape> (TopoDS_TShape::*)() const) &TopoDS_TShape::EmptyCopy, "Returns a copy of the TShape with no sub-shapes.");
cls_TopoDS_TShape.def_static("get_type_name_", (const char * (*)()) &TopoDS_TShape::get_type_name, "None");
cls_TopoDS_TShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopoDS_TShape::get_type_descriptor, "None");
cls_TopoDS_TShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopoDS_TShape::*)() const) &TopoDS_TShape::DynamicType, "None");

// Enums

}