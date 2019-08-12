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
#include <TransferBRep_BinderOfShape.hxx>
#include <TopoDS_Shape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Shell.hxx>
#include <TopoDS_Solid.hxx>
#include <TopoDS_CompSolid.hxx>
#include <TopoDS_Compound.hxx>
#include <Standard_Handle.hxx>
#include <TransferBRep_ShapeBinder.hxx>
#include <Standard_Type.hxx>

void bind_TransferBRep_ShapeBinder(py::module &mod){

py::class_<TransferBRep_ShapeBinder, opencascade::handle<TransferBRep_ShapeBinder>, TransferBRep_BinderOfShape> cls_TransferBRep_ShapeBinder(mod, "TransferBRep_ShapeBinder", "A ShapeBinder is a BinderOfShape with some additional services to cast the Result under various kinds of Shapes");

// Constructors
cls_TransferBRep_ShapeBinder.def(py::init<>());
cls_TransferBRep_ShapeBinder.def(py::init<const TopoDS_Shape &>(), py::arg("res"));

// Fields

// Methods
cls_TransferBRep_ShapeBinder.def("ShapeType", (TopAbs_ShapeEnum (TransferBRep_ShapeBinder::*)() const) &TransferBRep_ShapeBinder::ShapeType, "Returns the Type of the Shape Result (under TopAbs form)");
cls_TransferBRep_ShapeBinder.def("Vertex", (TopoDS_Vertex (TransferBRep_ShapeBinder::*)() const) &TransferBRep_ShapeBinder::Vertex, "None");
cls_TransferBRep_ShapeBinder.def("Edge", (TopoDS_Edge (TransferBRep_ShapeBinder::*)() const) &TransferBRep_ShapeBinder::Edge, "None");
cls_TransferBRep_ShapeBinder.def("Wire", (TopoDS_Wire (TransferBRep_ShapeBinder::*)() const) &TransferBRep_ShapeBinder::Wire, "None");
cls_TransferBRep_ShapeBinder.def("Face", (TopoDS_Face (TransferBRep_ShapeBinder::*)() const) &TransferBRep_ShapeBinder::Face, "None");
cls_TransferBRep_ShapeBinder.def("Shell", (TopoDS_Shell (TransferBRep_ShapeBinder::*)() const) &TransferBRep_ShapeBinder::Shell, "None");
cls_TransferBRep_ShapeBinder.def("Solid", (TopoDS_Solid (TransferBRep_ShapeBinder::*)() const) &TransferBRep_ShapeBinder::Solid, "None");
cls_TransferBRep_ShapeBinder.def("CompSolid", (TopoDS_CompSolid (TransferBRep_ShapeBinder::*)() const) &TransferBRep_ShapeBinder::CompSolid, "None");
cls_TransferBRep_ShapeBinder.def("Compound", (TopoDS_Compound (TransferBRep_ShapeBinder::*)() const) &TransferBRep_ShapeBinder::Compound, "None");
cls_TransferBRep_ShapeBinder.def_static("get_type_name_", (const char * (*)()) &TransferBRep_ShapeBinder::get_type_name, "None");
cls_TransferBRep_ShapeBinder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TransferBRep_ShapeBinder::get_type_descriptor, "None");
cls_TransferBRep_ShapeBinder.def("DynamicType", (const opencascade::handle<Standard_Type> & (TransferBRep_ShapeBinder::*)() const) &TransferBRep_ShapeBinder::DynamicType, "None");

// Enums

}