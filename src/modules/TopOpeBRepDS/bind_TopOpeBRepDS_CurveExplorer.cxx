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
#include <TopOpeBRepDS_DataStructure.hxx>
#include <Standard_TypeDef.hxx>
#include <TopOpeBRepDS_Curve.hxx>
#include <TopOpeBRepDS_CurveExplorer.hxx>

void bind_TopOpeBRepDS_CurveExplorer(py::module &mod){

py::class_<TopOpeBRepDS_CurveExplorer, std::unique_ptr<TopOpeBRepDS_CurveExplorer, Deleter<TopOpeBRepDS_CurveExplorer>>> cls_TopOpeBRepDS_CurveExplorer(mod, "TopOpeBRepDS_CurveExplorer", "None");

// Constructors
cls_TopOpeBRepDS_CurveExplorer.def(py::init<>());
cls_TopOpeBRepDS_CurveExplorer.def(py::init<const TopOpeBRepDS_DataStructure &>(), py::arg("DS"));
cls_TopOpeBRepDS_CurveExplorer.def(py::init<const TopOpeBRepDS_DataStructure &, const Standard_Boolean>(), py::arg("DS"), py::arg("FindOnlyKeep"));

// Fields

// Methods
// cls_TopOpeBRepDS_CurveExplorer.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_CurveExplorer::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_CurveExplorer.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_CurveExplorer::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_CurveExplorer.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_CurveExplorer::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_CurveExplorer.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_CurveExplorer::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_CurveExplorer.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_CurveExplorer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_CurveExplorer.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_CurveExplorer::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_CurveExplorer.def("Init", [](TopOpeBRepDS_CurveExplorer &self, const TopOpeBRepDS_DataStructure & a0) -> void { return self.Init(a0); });
cls_TopOpeBRepDS_CurveExplorer.def("Init", (void (TopOpeBRepDS_CurveExplorer::*)(const TopOpeBRepDS_DataStructure &, const Standard_Boolean)) &TopOpeBRepDS_CurveExplorer::Init, "None", py::arg("DS"), py::arg("FindOnlyKeep"));
cls_TopOpeBRepDS_CurveExplorer.def("More", (Standard_Boolean (TopOpeBRepDS_CurveExplorer::*)() const) &TopOpeBRepDS_CurveExplorer::More, "None");
cls_TopOpeBRepDS_CurveExplorer.def("Next", (void (TopOpeBRepDS_CurveExplorer::*)()) &TopOpeBRepDS_CurveExplorer::Next, "None");
cls_TopOpeBRepDS_CurveExplorer.def("Curve", (const TopOpeBRepDS_Curve & (TopOpeBRepDS_CurveExplorer::*)() const) &TopOpeBRepDS_CurveExplorer::Curve, "None");
cls_TopOpeBRepDS_CurveExplorer.def("IsCurve", (Standard_Boolean (TopOpeBRepDS_CurveExplorer::*)(const Standard_Integer) const) &TopOpeBRepDS_CurveExplorer::IsCurve, "None", py::arg("I"));
cls_TopOpeBRepDS_CurveExplorer.def("IsCurveKeep", (Standard_Boolean (TopOpeBRepDS_CurveExplorer::*)(const Standard_Integer) const) &TopOpeBRepDS_CurveExplorer::IsCurveKeep, "None", py::arg("I"));
cls_TopOpeBRepDS_CurveExplorer.def("Curve", (const TopOpeBRepDS_Curve & (TopOpeBRepDS_CurveExplorer::*)(const Standard_Integer) const) &TopOpeBRepDS_CurveExplorer::Curve, "None", py::arg("I"));
cls_TopOpeBRepDS_CurveExplorer.def("NbCurve", (Standard_Integer (TopOpeBRepDS_CurveExplorer::*)()) &TopOpeBRepDS_CurveExplorer::NbCurve, "None");
cls_TopOpeBRepDS_CurveExplorer.def("Index", (Standard_Integer (TopOpeBRepDS_CurveExplorer::*)() const) &TopOpeBRepDS_CurveExplorer::Index, "None");

// Enums

}