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
#include <TDF_Label.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TNaming_NamedShape.hxx>
#include <TNaming_NameType.hxx>
#include <TNaming_Localizer.hxx>
#include <TNaming_ListOfNamedShape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TNaming_Identifier.hxx>

void bind_TNaming_Identifier(py::module &mod){

py::class_<TNaming_Identifier, std::unique_ptr<TNaming_Identifier>> cls_TNaming_Identifier(mod, "TNaming_Identifier", "None");

// Constructors
cls_TNaming_Identifier.def(py::init<const TDF_Label &, const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Boolean>(), py::arg("Lab"), py::arg("S"), py::arg("Context"), py::arg("Geom"));
cls_TNaming_Identifier.def(py::init<const TDF_Label &, const TopoDS_Shape &, const opencascade::handle<TNaming_NamedShape> &, const Standard_Boolean>(), py::arg("Lab"), py::arg("S"), py::arg("ContextNS"), py::arg("Geom"));

// Fields

// Methods
// cls_TNaming_Identifier.def_static("operator new_", (void * (*)(size_t)) &TNaming_Identifier::operator new, "None", py::arg("theSize"));
// cls_TNaming_Identifier.def_static("operator delete_", (void (*)(void *)) &TNaming_Identifier::operator delete, "None", py::arg("theAddress"));
// cls_TNaming_Identifier.def_static("operator new[]_", (void * (*)(size_t)) &TNaming_Identifier::operator new[], "None", py::arg("theSize"));
// cls_TNaming_Identifier.def_static("operator delete[]_", (void (*)(void *)) &TNaming_Identifier::operator delete[], "None", py::arg("theAddress"));
// cls_TNaming_Identifier.def_static("operator new_", (void * (*)(size_t, void *)) &TNaming_Identifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TNaming_Identifier.def_static("operator delete_", (void (*)(void *, void *)) &TNaming_Identifier::operator delete, "None", py::arg(""), py::arg(""));
cls_TNaming_Identifier.def("IsDone", (Standard_Boolean (TNaming_Identifier::*)() const) &TNaming_Identifier::IsDone, "None");
cls_TNaming_Identifier.def("Type", (TNaming_NameType (TNaming_Identifier::*)() const) &TNaming_Identifier::Type, "None");
cls_TNaming_Identifier.def("IsFeature", (Standard_Boolean (TNaming_Identifier::*)()) &TNaming_Identifier::IsFeature, "None");
cls_TNaming_Identifier.def("Feature", (opencascade::handle<TNaming_NamedShape> (TNaming_Identifier::*)() const) &TNaming_Identifier::Feature, "None");
cls_TNaming_Identifier.def("InitArgs", (void (TNaming_Identifier::*)()) &TNaming_Identifier::InitArgs, "None");
cls_TNaming_Identifier.def("MoreArgs", (Standard_Boolean (TNaming_Identifier::*)() const) &TNaming_Identifier::MoreArgs, "None");
cls_TNaming_Identifier.def("NextArg", (void (TNaming_Identifier::*)()) &TNaming_Identifier::NextArg, "None");
cls_TNaming_Identifier.def("ArgIsFeature", (Standard_Boolean (TNaming_Identifier::*)() const) &TNaming_Identifier::ArgIsFeature, "None");
cls_TNaming_Identifier.def("FeatureArg", (opencascade::handle<TNaming_NamedShape> (TNaming_Identifier::*)()) &TNaming_Identifier::FeatureArg, "None");
cls_TNaming_Identifier.def("ShapeArg", (TopoDS_Shape (TNaming_Identifier::*)()) &TNaming_Identifier::ShapeArg, "None");
cls_TNaming_Identifier.def("ShapeContext", (TopoDS_Shape (TNaming_Identifier::*)() const) &TNaming_Identifier::ShapeContext, "None");
cls_TNaming_Identifier.def("NamedShapeOfGeneration", (opencascade::handle<TNaming_NamedShape> (TNaming_Identifier::*)() const) &TNaming_Identifier::NamedShapeOfGeneration, "None");
cls_TNaming_Identifier.def("AncestorIdentification", (void (TNaming_Identifier::*)(TNaming_Localizer &, const TopoDS_Shape &)) &TNaming_Identifier::AncestorIdentification, "None", py::arg("Localizer"), py::arg("Context"));
cls_TNaming_Identifier.def("PrimitiveIdentification", (void (TNaming_Identifier::*)(TNaming_Localizer &, const opencascade::handle<TNaming_NamedShape> &)) &TNaming_Identifier::PrimitiveIdentification, "None", py::arg("Localizer"), py::arg("NS"));
cls_TNaming_Identifier.def("GeneratedIdentification", (void (TNaming_Identifier::*)(TNaming_Localizer &, const opencascade::handle<TNaming_NamedShape> &)) &TNaming_Identifier::GeneratedIdentification, "None", py::arg("Localizer"), py::arg("NS"));
cls_TNaming_Identifier.def("Identification", (void (TNaming_Identifier::*)(TNaming_Localizer &, const opencascade::handle<TNaming_NamedShape> &)) &TNaming_Identifier::Identification, "None", py::arg("Localizer"), py::arg("NS"));

// Enums

}