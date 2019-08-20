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
#include <TopTools_ListOfShape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopOpeBRepBuild_FuseFace.hxx>

void bind_TopOpeBRepBuild_FuseFace(py::module &mod){

py::class_<TopOpeBRepBuild_FuseFace, std::unique_ptr<TopOpeBRepBuild_FuseFace>> cls_TopOpeBRepBuild_FuseFace(mod, "TopOpeBRepBuild_FuseFace", "None");

// Constructors
cls_TopOpeBRepBuild_FuseFace.def(py::init<>());
cls_TopOpeBRepBuild_FuseFace.def(py::init<const TopTools_ListOfShape &, const TopTools_ListOfShape &, const Standard_Integer>(), py::arg("LIF"), py::arg("LRF"), py::arg("CXM"));

// Fields

// Methods
// cls_TopOpeBRepBuild_FuseFace.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_FuseFace::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_FuseFace.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_FuseFace::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_FuseFace.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_FuseFace::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_FuseFace.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_FuseFace::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_FuseFace.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_FuseFace::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_FuseFace.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_FuseFace::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_FuseFace.def("Init", (void (TopOpeBRepBuild_FuseFace::*)(const TopTools_ListOfShape &, const TopTools_ListOfShape &, const Standard_Integer)) &TopOpeBRepBuild_FuseFace::Init, "None", py::arg("LIF"), py::arg("LRF"), py::arg("CXM"));
cls_TopOpeBRepBuild_FuseFace.def("PerformFace", (void (TopOpeBRepBuild_FuseFace::*)()) &TopOpeBRepBuild_FuseFace::PerformFace, "None");
cls_TopOpeBRepBuild_FuseFace.def("PerformEdge", (void (TopOpeBRepBuild_FuseFace::*)()) &TopOpeBRepBuild_FuseFace::PerformEdge, "None");
cls_TopOpeBRepBuild_FuseFace.def("ClearEdge", (void (TopOpeBRepBuild_FuseFace::*)()) &TopOpeBRepBuild_FuseFace::ClearEdge, "None");
cls_TopOpeBRepBuild_FuseFace.def("ClearVertex", (void (TopOpeBRepBuild_FuseFace::*)()) &TopOpeBRepBuild_FuseFace::ClearVertex, "None");
cls_TopOpeBRepBuild_FuseFace.def("IsDone", (Standard_Boolean (TopOpeBRepBuild_FuseFace::*)() const) &TopOpeBRepBuild_FuseFace::IsDone, "None");
cls_TopOpeBRepBuild_FuseFace.def("IsModified", (Standard_Boolean (TopOpeBRepBuild_FuseFace::*)() const) &TopOpeBRepBuild_FuseFace::IsModified, "None");
cls_TopOpeBRepBuild_FuseFace.def("LFuseFace", (const TopTools_ListOfShape & (TopOpeBRepBuild_FuseFace::*)() const) &TopOpeBRepBuild_FuseFace::LFuseFace, "None");
cls_TopOpeBRepBuild_FuseFace.def("LInternEdge", (const TopTools_ListOfShape & (TopOpeBRepBuild_FuseFace::*)() const) &TopOpeBRepBuild_FuseFace::LInternEdge, "None");
cls_TopOpeBRepBuild_FuseFace.def("LExternEdge", (const TopTools_ListOfShape & (TopOpeBRepBuild_FuseFace::*)() const) &TopOpeBRepBuild_FuseFace::LExternEdge, "None");
cls_TopOpeBRepBuild_FuseFace.def("LModifEdge", (const TopTools_ListOfShape & (TopOpeBRepBuild_FuseFace::*)() const) &TopOpeBRepBuild_FuseFace::LModifEdge, "None");
cls_TopOpeBRepBuild_FuseFace.def("LInternVertex", (const TopTools_ListOfShape & (TopOpeBRepBuild_FuseFace::*)() const) &TopOpeBRepBuild_FuseFace::LInternVertex, "None");
cls_TopOpeBRepBuild_FuseFace.def("LExternVertex", (const TopTools_ListOfShape & (TopOpeBRepBuild_FuseFace::*)() const) &TopOpeBRepBuild_FuseFace::LExternVertex, "None");
cls_TopOpeBRepBuild_FuseFace.def("LModifVertex", (const TopTools_ListOfShape & (TopOpeBRepBuild_FuseFace::*)() const) &TopOpeBRepBuild_FuseFace::LModifVertex, "None");

// Enums

}