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
#include <NCollection_BaseAllocator.hxx>
#include <TopoDS_Shape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <Bnd_Box.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <Standard_TypeDef.hxx>
#include <BOPDS_ShapeInfo.hxx>

void bind_BOPDS_ShapeInfo(py::module &mod){

py::class_<BOPDS_ShapeInfo> cls_BOPDS_ShapeInfo(mod, "BOPDS_ShapeInfo", "The class BOPDS_ShapeInfo is to store handy information about shape");

// Constructors
cls_BOPDS_ShapeInfo.def(py::init<>());
cls_BOPDS_ShapeInfo.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Fields

// Methods
// cls_BOPDS_ShapeInfo.def_static("operator new_", (void * (*)(size_t)) &BOPDS_ShapeInfo::operator new, "None", py::arg("theSize"));
// cls_BOPDS_ShapeInfo.def_static("operator delete_", (void (*)(void *)) &BOPDS_ShapeInfo::operator delete, "None", py::arg("theAddress"));
// cls_BOPDS_ShapeInfo.def_static("operator new[]_", (void * (*)(size_t)) &BOPDS_ShapeInfo::operator new[], "None", py::arg("theSize"));
// cls_BOPDS_ShapeInfo.def_static("operator delete[]_", (void (*)(void *)) &BOPDS_ShapeInfo::operator delete[], "None", py::arg("theAddress"));
// cls_BOPDS_ShapeInfo.def_static("operator new_", (void * (*)(size_t, void *)) &BOPDS_ShapeInfo::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPDS_ShapeInfo.def_static("operator delete_", (void (*)(void *, void *)) &BOPDS_ShapeInfo::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPDS_ShapeInfo.def("SetShape", (void (BOPDS_ShapeInfo::*)(const TopoDS_Shape &)) &BOPDS_ShapeInfo::SetShape, "Modifier Sets the shape <theS>", py::arg("theS"));
cls_BOPDS_ShapeInfo.def("Shape", (const TopoDS_Shape & (BOPDS_ShapeInfo::*)() const) &BOPDS_ShapeInfo::Shape, "Selector Returns the shape");
cls_BOPDS_ShapeInfo.def("SetShapeType", (void (BOPDS_ShapeInfo::*)(const TopAbs_ShapeEnum)) &BOPDS_ShapeInfo::SetShapeType, "Modifier Sets the type of shape theType", py::arg("theType"));
cls_BOPDS_ShapeInfo.def("ShapeType", (TopAbs_ShapeEnum (BOPDS_ShapeInfo::*)() const) &BOPDS_ShapeInfo::ShapeType, "Selector Returns the type of shape");
cls_BOPDS_ShapeInfo.def("SetBox", (void (BOPDS_ShapeInfo::*)(const Bnd_Box &)) &BOPDS_ShapeInfo::SetBox, "Modifier Sets the boundung box of the shape theBox", py::arg("theBox"));
cls_BOPDS_ShapeInfo.def("Box", (const Bnd_Box & (BOPDS_ShapeInfo::*)() const) &BOPDS_ShapeInfo::Box, "Selector Returns the boundung box of the shape");
cls_BOPDS_ShapeInfo.def("ChangeBox", (Bnd_Box & (BOPDS_ShapeInfo::*)()) &BOPDS_ShapeInfo::ChangeBox, "Selector/Modifier Returns the boundung box of the shape");
cls_BOPDS_ShapeInfo.def("SubShapes", (const TColStd_ListOfInteger & (BOPDS_ShapeInfo::*)() const) &BOPDS_ShapeInfo::SubShapes, "Selector Returns the list of indices of sub-shapes");
cls_BOPDS_ShapeInfo.def("ChangeSubShapes", (TColStd_ListOfInteger & (BOPDS_ShapeInfo::*)()) &BOPDS_ShapeInfo::ChangeSubShapes, "Selector/ Modifier Returns the list of indices of sub-shapes");
cls_BOPDS_ShapeInfo.def("HasSubShape", (Standard_Boolean (BOPDS_ShapeInfo::*)(const Standard_Integer) const) &BOPDS_ShapeInfo::HasSubShape, "Query Returns true if the shape has sub-shape with index theI", py::arg("theI"));
cls_BOPDS_ShapeInfo.def("HasReference", (Standard_Boolean (BOPDS_ShapeInfo::*)() const) &BOPDS_ShapeInfo::HasReference, "None");
cls_BOPDS_ShapeInfo.def("SetReference", (void (BOPDS_ShapeInfo::*)(const Standard_Integer)) &BOPDS_ShapeInfo::SetReference, "Modifier Sets the index of a reference information", py::arg("theI"));
cls_BOPDS_ShapeInfo.def("Reference", (Standard_Integer (BOPDS_ShapeInfo::*)() const) &BOPDS_ShapeInfo::Reference, "Selector Returns the index of a reference information");
cls_BOPDS_ShapeInfo.def("HasBRep", (Standard_Boolean (BOPDS_ShapeInfo::*)() const) &BOPDS_ShapeInfo::HasBRep, "Query Returns true if the shape has boundary representation");
cls_BOPDS_ShapeInfo.def("IsInterfering", (Standard_Boolean (BOPDS_ShapeInfo::*)() const) &BOPDS_ShapeInfo::IsInterfering, "Returns true if the shape can be participant of an interference");
cls_BOPDS_ShapeInfo.def("HasFlag", (Standard_Boolean (BOPDS_ShapeInfo::*)() const) &BOPDS_ShapeInfo::HasFlag, "Query Returns true if there is flag.");
cls_BOPDS_ShapeInfo.def("HasFlag", [](BOPDS_ShapeInfo &self, Standard_Integer & theFlag){ Standard_Boolean rv = self.HasFlag(theFlag); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, theFlag); }, "Query Returns true if there is flag. Returns the the flag theFlag", py::arg("theFlag"));
cls_BOPDS_ShapeInfo.def("SetFlag", (void (BOPDS_ShapeInfo::*)(const Standard_Integer)) &BOPDS_ShapeInfo::SetFlag, "Modifier Sets the flag", py::arg("theI"));
cls_BOPDS_ShapeInfo.def("Flag", (Standard_Integer (BOPDS_ShapeInfo::*)() const) &BOPDS_ShapeInfo::Flag, "Returns the flag");
cls_BOPDS_ShapeInfo.def("Dump", (void (BOPDS_ShapeInfo::*)() const) &BOPDS_ShapeInfo::Dump, "None");

// Enums

}