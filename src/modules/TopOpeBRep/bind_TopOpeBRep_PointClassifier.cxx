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
#include <TopoDS_Face.hxx>
#include <TopAbs_State.hxx>
#include <gp_Pnt2d.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <BRepTopAdaptor_TopolTool.hxx>
#include <BRepAdaptor_HSurface.hxx>
#include <TopOpeBRep_DataMapOfTopolTool.hxx>
#include <TopOpeBRep_PointClassifier.hxx>

void bind_TopOpeBRep_PointClassifier(py::module &mod){

py::class_<TopOpeBRep_PointClassifier, std::unique_ptr<TopOpeBRep_PointClassifier>> cls_TopOpeBRep_PointClassifier(mod, "TopOpeBRep_PointClassifier", "None");

// Constructors
cls_TopOpeBRep_PointClassifier.def(py::init<>());

// Fields

// Methods
// cls_TopOpeBRep_PointClassifier.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRep_PointClassifier::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRep_PointClassifier.def_static("operator delete_", (void (*)(void *)) &TopOpeBRep_PointClassifier::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRep_PointClassifier.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRep_PointClassifier::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRep_PointClassifier.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRep_PointClassifier::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRep_PointClassifier.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRep_PointClassifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRep_PointClassifier.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRep_PointClassifier::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRep_PointClassifier.def("Init", (void (TopOpeBRep_PointClassifier::*)()) &TopOpeBRep_PointClassifier::Init, "None");
cls_TopOpeBRep_PointClassifier.def("Load", (void (TopOpeBRep_PointClassifier::*)(const TopoDS_Face &)) &TopOpeBRep_PointClassifier::Load, "None", py::arg("F"));
cls_TopOpeBRep_PointClassifier.def("Classify", (TopAbs_State (TopOpeBRep_PointClassifier::*)(const TopoDS_Face &, const gp_Pnt2d &, const Standard_Real)) &TopOpeBRep_PointClassifier::Classify, "compute position of point <P> regarding with the face <F>.", py::arg("F"), py::arg("P"), py::arg("Tol"));
cls_TopOpeBRep_PointClassifier.def("State", (TopAbs_State (TopOpeBRep_PointClassifier::*)() const) &TopOpeBRep_PointClassifier::State, "None");

// Enums

}