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
#include <TopOpeBRepBuild_CompositeClassifier.hxx>
#include <Standard.hxx>
#include <TopOpeBRepBuild_BlockBuilder.hxx>
#include <TopAbs_State.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <TopoDS_Shell.hxx>
#include <BRep_Builder.hxx>
#include <TopOpeBRepTool_SolidClassifier.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <TopOpeBRepBuild_ShellFaceClassifier.hxx>

void bind_TopOpeBRepBuild_ShellFaceClassifier(py::module &mod){

py::class_<TopOpeBRepBuild_ShellFaceClassifier, std::unique_ptr<TopOpeBRepBuild_ShellFaceClassifier, Deleter<TopOpeBRepBuild_ShellFaceClassifier>>, TopOpeBRepBuild_CompositeClassifier> cls_TopOpeBRepBuild_ShellFaceClassifier(mod, "TopOpeBRepBuild_ShellFaceClassifier", "Classify faces and shells. shapes are Shells, Elements are Faces.");

// Constructors
cls_TopOpeBRepBuild_ShellFaceClassifier.def(py::init<const TopOpeBRepBuild_BlockBuilder &>(), py::arg("BB"));

// Fields

// Methods
// cls_TopOpeBRepBuild_ShellFaceClassifier.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_ShellFaceClassifier::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_ShellFaceClassifier.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_ShellFaceClassifier::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_ShellFaceClassifier.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_ShellFaceClassifier::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_ShellFaceClassifier.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_ShellFaceClassifier::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_ShellFaceClassifier.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_ShellFaceClassifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_ShellFaceClassifier.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_ShellFaceClassifier::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_ShellFaceClassifier.def("Clear", (void (TopOpeBRepBuild_ShellFaceClassifier::*)()) &TopOpeBRepBuild_ShellFaceClassifier::Clear, "None");
cls_TopOpeBRepBuild_ShellFaceClassifier.def("CompareShapes", (TopAbs_State (TopOpeBRepBuild_ShellFaceClassifier::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepBuild_ShellFaceClassifier::CompareShapes, "classify shell <B1> with shell <B2>", py::arg("B1"), py::arg("B2"));
cls_TopOpeBRepBuild_ShellFaceClassifier.def("CompareElementToShape", (TopAbs_State (TopOpeBRepBuild_ShellFaceClassifier::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepBuild_ShellFaceClassifier::CompareElementToShape, "classify face <F> with shell <S>", py::arg("F"), py::arg("S"));
cls_TopOpeBRepBuild_ShellFaceClassifier.def("ResetShape", (void (TopOpeBRepBuild_ShellFaceClassifier::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_ShellFaceClassifier::ResetShape, "prepare classification involving shell <S> calls ResetElement on first face of <S>", py::arg("S"));
cls_TopOpeBRepBuild_ShellFaceClassifier.def("ResetElement", (void (TopOpeBRepBuild_ShellFaceClassifier::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_ShellFaceClassifier::ResetElement, "prepare classification involving face <F> define 3D point (later used in Compare()) on first vertex of face <F>.", py::arg("F"));
cls_TopOpeBRepBuild_ShellFaceClassifier.def("CompareElement", (Standard_Boolean (TopOpeBRepBuild_ShellFaceClassifier::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_ShellFaceClassifier::CompareElement, "Add the face <F> in the set of faces used in 3D point classification. Returns FALSE if the face <F> has been already added to the set of faces, otherwise returns TRUE.", py::arg("F"));
cls_TopOpeBRepBuild_ShellFaceClassifier.def("State", (TopAbs_State (TopOpeBRepBuild_ShellFaceClassifier::*)()) &TopOpeBRepBuild_ShellFaceClassifier::State, "Returns state of classification of 3D point, defined by ResetElement, with the current set of faces, defined by Compare.");

// Enums

}