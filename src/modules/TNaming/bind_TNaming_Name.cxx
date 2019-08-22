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
#include <TNaming_NameType.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Handle.hxx>
#include <TNaming_NamedShape.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_Label.hxx>
#include <TopAbs_Orientation.hxx>
#include <TNaming_ListOfNamedShape.hxx>
#include <TDF_LabelMap.hxx>
#include <TNaming_Name.hxx>
#include <TDF_RelocationTable.hxx>

void bind_TNaming_Name(py::module &mod){

py::class_<TNaming_Name> cls_TNaming_Name(mod, "TNaming_Name", "store the arguments of Naming.");

// Constructors
cls_TNaming_Name.def(py::init<>());

// Fields

// Methods
// cls_TNaming_Name.def_static("operator new_", (void * (*)(size_t)) &TNaming_Name::operator new, "None", py::arg("theSize"));
// cls_TNaming_Name.def_static("operator delete_", (void (*)(void *)) &TNaming_Name::operator delete, "None", py::arg("theAddress"));
// cls_TNaming_Name.def_static("operator new[]_", (void * (*)(size_t)) &TNaming_Name::operator new[], "None", py::arg("theSize"));
// cls_TNaming_Name.def_static("operator delete[]_", (void (*)(void *)) &TNaming_Name::operator delete[], "None", py::arg("theAddress"));
// cls_TNaming_Name.def_static("operator new_", (void * (*)(size_t, void *)) &TNaming_Name::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TNaming_Name.def_static("operator delete_", (void (*)(void *, void *)) &TNaming_Name::operator delete, "None", py::arg(""), py::arg(""));
cls_TNaming_Name.def("Type", (void (TNaming_Name::*)(const TNaming_NameType)) &TNaming_Name::Type, "None", py::arg("aType"));
cls_TNaming_Name.def("ShapeType", (void (TNaming_Name::*)(const TopAbs_ShapeEnum)) &TNaming_Name::ShapeType, "None", py::arg("aType"));
cls_TNaming_Name.def("Shape", (void (TNaming_Name::*)(const TopoDS_Shape &)) &TNaming_Name::Shape, "None", py::arg("theShape"));
cls_TNaming_Name.def("Append", (void (TNaming_Name::*)(const opencascade::handle<TNaming_NamedShape> &)) &TNaming_Name::Append, "None", py::arg("arg"));
cls_TNaming_Name.def("StopNamedShape", (void (TNaming_Name::*)(const opencascade::handle<TNaming_NamedShape> &)) &TNaming_Name::StopNamedShape, "None", py::arg("arg"));
cls_TNaming_Name.def("Index", (void (TNaming_Name::*)(const Standard_Integer)) &TNaming_Name::Index, "None", py::arg("I"));
cls_TNaming_Name.def("ContextLabel", (void (TNaming_Name::*)(const TDF_Label &)) &TNaming_Name::ContextLabel, "None", py::arg("theLab"));
cls_TNaming_Name.def("Orientation", (void (TNaming_Name::*)(const TopAbs_Orientation)) &TNaming_Name::Orientation, "None", py::arg("theOrientation"));
cls_TNaming_Name.def("Type", (TNaming_NameType (TNaming_Name::*)() const) &TNaming_Name::Type, "None");
cls_TNaming_Name.def("ShapeType", (TopAbs_ShapeEnum (TNaming_Name::*)() const) &TNaming_Name::ShapeType, "None");
cls_TNaming_Name.def("Shape", (TopoDS_Shape (TNaming_Name::*)() const) &TNaming_Name::Shape, "None");
cls_TNaming_Name.def("Arguments", (const TNaming_ListOfNamedShape & (TNaming_Name::*)() const) &TNaming_Name::Arguments, "None");
cls_TNaming_Name.def("StopNamedShape", (opencascade::handle<TNaming_NamedShape> (TNaming_Name::*)() const) &TNaming_Name::StopNamedShape, "None");
cls_TNaming_Name.def("Index", (Standard_Integer (TNaming_Name::*)() const) &TNaming_Name::Index, "None");
cls_TNaming_Name.def("ContextLabel", (const TDF_Label & (TNaming_Name::*)() const) &TNaming_Name::ContextLabel, "None");
cls_TNaming_Name.def("Orientation", (TopAbs_Orientation (TNaming_Name::*)() const) &TNaming_Name::Orientation, "None");
cls_TNaming_Name.def("Solve", (Standard_Boolean (TNaming_Name::*)(const TDF_Label &, const TDF_LabelMap &) const) &TNaming_Name::Solve, "None", py::arg("aLab"), py::arg("Valid"));
cls_TNaming_Name.def("Paste", (void (TNaming_Name::*)(TNaming_Name &, const opencascade::handle<TDF_RelocationTable> &) const) &TNaming_Name::Paste, "None", py::arg("into"), py::arg("RT"));

// Enums

}