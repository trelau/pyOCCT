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
#include <TopoDS_Solid.hxx>
#include <TopAbs_State.hxx>
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shell.hxx>
#include <TopOpeBRepTool_PSoClassif.hxx>
#include <TopTools_IndexedDataMapOfShapeAddress.hxx>
#include <BRep_Builder.hxx>
#include <TopOpeBRepTool_SolidClassifier.hxx>

void bind_TopOpeBRepTool_SolidClassifier(py::module &mod){

py::class_<TopOpeBRepTool_SolidClassifier> cls_TopOpeBRepTool_SolidClassifier(mod, "TopOpeBRepTool_SolidClassifier", "None");

// Constructors
cls_TopOpeBRepTool_SolidClassifier.def(py::init<>());

// Fields

// Methods
// cls_TopOpeBRepTool_SolidClassifier.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool_SolidClassifier::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool_SolidClassifier.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool_SolidClassifier::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_SolidClassifier.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool_SolidClassifier::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool_SolidClassifier.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool_SolidClassifier::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_SolidClassifier.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool_SolidClassifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool_SolidClassifier.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool_SolidClassifier::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool_SolidClassifier.def("Clear", (void (TopOpeBRepTool_SolidClassifier::*)()) &TopOpeBRepTool_SolidClassifier::Clear, "None");
cls_TopOpeBRepTool_SolidClassifier.def("LoadSolid", (void (TopOpeBRepTool_SolidClassifier::*)(const TopoDS_Solid &)) &TopOpeBRepTool_SolidClassifier::LoadSolid, "None", py::arg("S"));
cls_TopOpeBRepTool_SolidClassifier.def("Classify", (TopAbs_State (TopOpeBRepTool_SolidClassifier::*)(const TopoDS_Solid &, const gp_Pnt &, const Standard_Real)) &TopOpeBRepTool_SolidClassifier::Classify, "compute the position of point <P> regarding with the geometric domain of the solid <S>.", py::arg("S"), py::arg("P"), py::arg("Tol"));
cls_TopOpeBRepTool_SolidClassifier.def("LoadShell", (void (TopOpeBRepTool_SolidClassifier::*)(const TopoDS_Shell &)) &TopOpeBRepTool_SolidClassifier::LoadShell, "None", py::arg("S"));
cls_TopOpeBRepTool_SolidClassifier.def("Classify", (TopAbs_State (TopOpeBRepTool_SolidClassifier::*)(const TopoDS_Shell &, const gp_Pnt &, const Standard_Real)) &TopOpeBRepTool_SolidClassifier::Classify, "compute the position of point <P> regarding with the geometric domain of the shell <S>.", py::arg("S"), py::arg("P"), py::arg("Tol"));
cls_TopOpeBRepTool_SolidClassifier.def("State", (TopAbs_State (TopOpeBRepTool_SolidClassifier::*)() const) &TopOpeBRepTool_SolidClassifier::State, "None");

// Enums

}