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
#include <TopoDS_Shape.hxx>
#include <Standard_Handle.hxx>
#include <BRepTools_Modification.hxx>
#include <Message_ProgressIndicator.hxx>
#include <Geom_Curve.hxx>
#include <TopLoc_Location.hxx>
#include <Geom_Surface.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <NCollection_DataMap.hxx>
#include <TopoDS_Edge.hxx>
#include <BRepTools_Modifier.hxx>
#include <TopTools_ShapeMapHasher.hxx>
#include <TopoDS_Face.hxx>
#include <TopTools_MapOfShape.hxx>

void bind_BRepTools_Modifier(py::module &mod){

py::class_<BRepTools_Modifier, std::unique_ptr<BRepTools_Modifier, Deleter<BRepTools_Modifier>>> cls_BRepTools_Modifier(mod, "BRepTools_Modifier", "Performs geometric modifications on a shape.");

// Constructors
cls_BRepTools_Modifier.def(py::init<>());
cls_BRepTools_Modifier.def(py::init<Standard_Boolean>(), py::arg("theMutableInput"));
cls_BRepTools_Modifier.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
cls_BRepTools_Modifier.def(py::init<const TopoDS_Shape &, const opencascade::handle<BRepTools_Modification> &>(), py::arg("S"), py::arg("M"));

// Fields

// Methods
// cls_BRepTools_Modifier.def_static("operator new_", (void * (*)(size_t)) &BRepTools_Modifier::operator new, "None", py::arg("theSize"));
// cls_BRepTools_Modifier.def_static("operator delete_", (void (*)(void *)) &BRepTools_Modifier::operator delete, "None", py::arg("theAddress"));
// cls_BRepTools_Modifier.def_static("operator new[]_", (void * (*)(size_t)) &BRepTools_Modifier::operator new[], "None", py::arg("theSize"));
// cls_BRepTools_Modifier.def_static("operator delete[]_", (void (*)(void *)) &BRepTools_Modifier::operator delete[], "None", py::arg("theAddress"));
// cls_BRepTools_Modifier.def_static("operator new_", (void * (*)(size_t, void *)) &BRepTools_Modifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepTools_Modifier.def_static("operator delete_", (void (*)(void *, void *)) &BRepTools_Modifier::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepTools_Modifier.def("Init", (void (BRepTools_Modifier::*)(const TopoDS_Shape &)) &BRepTools_Modifier::Init, "Initializes the modifier with the shape <S>.", py::arg("S"));
cls_BRepTools_Modifier.def("Perform", [](BRepTools_Modifier &self, const opencascade::handle<BRepTools_Modification> & a0) -> void { return self.Perform(a0); });
cls_BRepTools_Modifier.def("Perform", (void (BRepTools_Modifier::*)(const opencascade::handle<BRepTools_Modification> &, const opencascade::handle<Message_ProgressIndicator> &)) &BRepTools_Modifier::Perform, "Performs the modifications described by <M>.", py::arg("M"), py::arg("aProgress"));
cls_BRepTools_Modifier.def("IsDone", (Standard_Boolean (BRepTools_Modifier::*)() const) &BRepTools_Modifier::IsDone, "Returns Standard_True if the modification has been computed successfully.");
cls_BRepTools_Modifier.def("IsMutableInput", (Standard_Boolean (BRepTools_Modifier::*)() const) &BRepTools_Modifier::IsMutableInput, "Returns the current mutable input state");
cls_BRepTools_Modifier.def("SetMutableInput", (void (BRepTools_Modifier::*)(Standard_Boolean)) &BRepTools_Modifier::SetMutableInput, "Sets the mutable input state If true then the input (original) shape can be modified during modification process", py::arg("theMutableInput"));
cls_BRepTools_Modifier.def("ModifiedShape", (const TopoDS_Shape & (BRepTools_Modifier::*)(const TopoDS_Shape &) const) &BRepTools_Modifier::ModifiedShape, "Returns the modified shape corresponding to <S>.", py::arg("S"));

// Enums

}