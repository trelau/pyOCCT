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
#include <TopOpeBRepBuild_ShellFaceSet.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <TopOpeBRepBuild_ShapeSet.hxx>
#include <TopOpeBRepBuild_LoopSet.hxx>
#include <TopOpeBRepBuild_BlockIterator.hxx>
#include <TopOpeBRepBuild_BlockBuilder.hxx>
#include <TopOpeBRepBuild_SolidAreaBuilder.hxx>
#include <TopOpeBRepBuild_SolidBuilder.hxx>

void bind_TopOpeBRepBuild_SolidBuilder(py::module &mod){

py::class_<TopOpeBRepBuild_SolidBuilder, std::unique_ptr<TopOpeBRepBuild_SolidBuilder>> cls_TopOpeBRepBuild_SolidBuilder(mod, "TopOpeBRepBuild_SolidBuilder", "None");

// Constructors
cls_TopOpeBRepBuild_SolidBuilder.def(py::init<>());
cls_TopOpeBRepBuild_SolidBuilder.def(py::init<TopOpeBRepBuild_ShellFaceSet &>(), py::arg("FS"));
cls_TopOpeBRepBuild_SolidBuilder.def(py::init<TopOpeBRepBuild_ShellFaceSet &, const Standard_Boolean>(), py::arg("FS"), py::arg("ForceClass"));

// Fields

// Methods
// cls_TopOpeBRepBuild_SolidBuilder.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_SolidBuilder::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_SolidBuilder.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_SolidBuilder::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_SolidBuilder.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_SolidBuilder::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_SolidBuilder.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_SolidBuilder::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_SolidBuilder.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_SolidBuilder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_SolidBuilder.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_SolidBuilder::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_SolidBuilder.def("InitSolidBuilder", (void (TopOpeBRepBuild_SolidBuilder::*)(TopOpeBRepBuild_ShellFaceSet &, const Standard_Boolean)) &TopOpeBRepBuild_SolidBuilder::InitSolidBuilder, "None", py::arg("FS"), py::arg("ForceClass"));
cls_TopOpeBRepBuild_SolidBuilder.def("InitSolid", (Standard_Integer (TopOpeBRepBuild_SolidBuilder::*)()) &TopOpeBRepBuild_SolidBuilder::InitSolid, "None");
cls_TopOpeBRepBuild_SolidBuilder.def("MoreSolid", (Standard_Boolean (TopOpeBRepBuild_SolidBuilder::*)() const) &TopOpeBRepBuild_SolidBuilder::MoreSolid, "None");
cls_TopOpeBRepBuild_SolidBuilder.def("NextSolid", (void (TopOpeBRepBuild_SolidBuilder::*)()) &TopOpeBRepBuild_SolidBuilder::NextSolid, "None");
cls_TopOpeBRepBuild_SolidBuilder.def("InitShell", (Standard_Integer (TopOpeBRepBuild_SolidBuilder::*)()) &TopOpeBRepBuild_SolidBuilder::InitShell, "None");
cls_TopOpeBRepBuild_SolidBuilder.def("MoreShell", (Standard_Boolean (TopOpeBRepBuild_SolidBuilder::*)() const) &TopOpeBRepBuild_SolidBuilder::MoreShell, "None");
cls_TopOpeBRepBuild_SolidBuilder.def("NextShell", (void (TopOpeBRepBuild_SolidBuilder::*)()) &TopOpeBRepBuild_SolidBuilder::NextShell, "None");
cls_TopOpeBRepBuild_SolidBuilder.def("IsOldShell", (Standard_Boolean (TopOpeBRepBuild_SolidBuilder::*)() const) &TopOpeBRepBuild_SolidBuilder::IsOldShell, "None");
cls_TopOpeBRepBuild_SolidBuilder.def("OldShell", (const TopoDS_Shape & (TopOpeBRepBuild_SolidBuilder::*)() const) &TopOpeBRepBuild_SolidBuilder::OldShell, "Returns current shell This shell may be : * an old shell OldShell(), which has not been reconstructed; * a new shell made of faces described by ...NewFace() methods.");
cls_TopOpeBRepBuild_SolidBuilder.def("InitFace", (Standard_Integer (TopOpeBRepBuild_SolidBuilder::*)()) &TopOpeBRepBuild_SolidBuilder::InitFace, "None");
cls_TopOpeBRepBuild_SolidBuilder.def("MoreFace", (Standard_Boolean (TopOpeBRepBuild_SolidBuilder::*)() const) &TopOpeBRepBuild_SolidBuilder::MoreFace, "None");
cls_TopOpeBRepBuild_SolidBuilder.def("NextFace", (void (TopOpeBRepBuild_SolidBuilder::*)()) &TopOpeBRepBuild_SolidBuilder::NextFace, "None");
cls_TopOpeBRepBuild_SolidBuilder.def("Face", (const TopoDS_Shape & (TopOpeBRepBuild_SolidBuilder::*)() const) &TopOpeBRepBuild_SolidBuilder::Face, "Returns current new face of current new shell.");

// Enums

}