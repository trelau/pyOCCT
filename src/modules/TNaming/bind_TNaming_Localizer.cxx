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
#include <TNaming_UsedShapes.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_MapOfShape.hxx>
#include <TopoDS_Shape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <TDF_Label.hxx>
#include <TNaming_Evolution.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TNaming_ListOfNamedShape.hxx>
#include <TNaming_NamedShape.hxx>
#include <TNaming_MapOfNamedShape.hxx>
#include <TNaming_ListOfMapOfShape.hxx>
#include <TNaming_ListOfIndexedDataMapOfShapeListOfShape.hxx>
#include <TNaming_Localizer.hxx>

void bind_TNaming_Localizer(py::module &mod){

py::class_<TNaming_Localizer, std::unique_ptr<TNaming_Localizer, Deleter<TNaming_Localizer>>> cls_TNaming_Localizer(mod, "TNaming_Localizer", "None");

// Constructors
cls_TNaming_Localizer.def(py::init<>());

// Fields

// Methods
// cls_TNaming_Localizer.def_static("operator new_", (void * (*)(size_t)) &TNaming_Localizer::operator new, "None", py::arg("theSize"));
// cls_TNaming_Localizer.def_static("operator delete_", (void (*)(void *)) &TNaming_Localizer::operator delete, "None", py::arg("theAddress"));
// cls_TNaming_Localizer.def_static("operator new[]_", (void * (*)(size_t)) &TNaming_Localizer::operator new[], "None", py::arg("theSize"));
// cls_TNaming_Localizer.def_static("operator delete[]_", (void (*)(void *)) &TNaming_Localizer::operator delete[], "None", py::arg("theAddress"));
// cls_TNaming_Localizer.def_static("operator new_", (void * (*)(size_t, void *)) &TNaming_Localizer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TNaming_Localizer.def_static("operator delete_", (void (*)(void *, void *)) &TNaming_Localizer::operator delete, "None", py::arg(""), py::arg(""));
cls_TNaming_Localizer.def("Init", (void (TNaming_Localizer::*)(const opencascade::handle<TNaming_UsedShapes> &, const Standard_Integer)) &TNaming_Localizer::Init, "None", py::arg("US"), py::arg("CurTrans"));
cls_TNaming_Localizer.def("SubShapes", (const TopTools_MapOfShape & (TNaming_Localizer::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum)) &TNaming_Localizer::SubShapes, "None", py::arg("S"), py::arg("Type"));
cls_TNaming_Localizer.def("Ancestors", (const TopTools_IndexedDataMapOfShapeListOfShape & (TNaming_Localizer::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum)) &TNaming_Localizer::Ancestors, "None", py::arg("S"), py::arg("Type"));
cls_TNaming_Localizer.def("FindFeaturesInAncestors", (void (TNaming_Localizer::*)(const TopoDS_Shape &, const TopoDS_Shape &, TopTools_MapOfShape &)) &TNaming_Localizer::FindFeaturesInAncestors, "None", py::arg("S"), py::arg("In"), py::arg("AncInFeatures"));
cls_TNaming_Localizer.def("GoBack", (void (TNaming_Localizer::*)(const TopoDS_Shape &, const TDF_Label &, const TNaming_Evolution, TopTools_ListOfShape &, TNaming_ListOfNamedShape &)) &TNaming_Localizer::GoBack, "None", py::arg("S"), py::arg("Lab"), py::arg("Evol"), py::arg("OldS"), py::arg("OldLab"));
cls_TNaming_Localizer.def("Backward", (void (TNaming_Localizer::*)(const opencascade::handle<TNaming_NamedShape> &, const TopoDS_Shape &, TNaming_MapOfNamedShape &, TopTools_MapOfShape &)) &TNaming_Localizer::Backward, "None", py::arg("NS"), py::arg("S"), py::arg("Primitives"), py::arg("ValidShapes"));
cls_TNaming_Localizer.def("FindNeighbourg", (void (TNaming_Localizer::*)(const TopoDS_Shape &, const TopoDS_Shape &, TopTools_MapOfShape &)) &TNaming_Localizer::FindNeighbourg, "None", py::arg("Cont"), py::arg("S"), py::arg("Neighbourg"));
cls_TNaming_Localizer.def_static("IsNew_", (Standard_Boolean (*)(const TopoDS_Shape &, const opencascade::handle<TNaming_NamedShape> &)) &TNaming_Localizer::IsNew, "None", py::arg("S"), py::arg("NS"));
cls_TNaming_Localizer.def_static("FindGenerator_", (void (*)(const opencascade::handle<TNaming_NamedShape> &, const TopoDS_Shape &, TopTools_ListOfShape &)) &TNaming_Localizer::FindGenerator, "None", py::arg("NS"), py::arg("S"), py::arg("theListOfGenerators"));
cls_TNaming_Localizer.def_static("FindShapeContext_", (void (*)(const opencascade::handle<TNaming_NamedShape> &, const TopoDS_Shape &, TopoDS_Shape &)) &TNaming_Localizer::FindShapeContext, "Finds context of the shape <S>.", py::arg("NS"), py::arg("theS"), py::arg("theSC"));

// Enums

}