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
#include <TopoDS_Shape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopOpeBRepTool_ShapeExplorer.hxx>
#include <Standard_TypeDef.hxx>
#include <TopOpeBRepTool_BoxSort.hxx>
#include <Standard_OStream.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <TopOpeBRep_ShapeScanner.hxx>

void bind_TopOpeBRep_ShapeScanner(py::module &mod){

py::class_<TopOpeBRep_ShapeScanner, std::unique_ptr<TopOpeBRep_ShapeScanner>> cls_TopOpeBRep_ShapeScanner(mod, "TopOpeBRep_ShapeScanner", "Find, among the subshapes SS of a reference shape RS, the ones which 3D box interfers with the box of a shape S (SS and S are of the same type).");

// Constructors
cls_TopOpeBRep_ShapeScanner.def(py::init<>());

// Fields

// Methods
// cls_TopOpeBRep_ShapeScanner.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRep_ShapeScanner::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRep_ShapeScanner.def_static("operator delete_", (void (*)(void *)) &TopOpeBRep_ShapeScanner::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRep_ShapeScanner.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRep_ShapeScanner::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRep_ShapeScanner.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRep_ShapeScanner::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRep_ShapeScanner.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRep_ShapeScanner::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRep_ShapeScanner.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRep_ShapeScanner::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRep_ShapeScanner.def("Clear", (void (TopOpeBRep_ShapeScanner::*)()) &TopOpeBRep_ShapeScanner::Clear, "None");
cls_TopOpeBRep_ShapeScanner.def("AddBoxesMakeCOB", [](TopOpeBRep_ShapeScanner &self, const TopoDS_Shape & a0, const TopAbs_ShapeEnum a1) -> void { return self.AddBoxesMakeCOB(a0, a1); });
cls_TopOpeBRep_ShapeScanner.def("AddBoxesMakeCOB", (void (TopOpeBRep_ShapeScanner::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRep_ShapeScanner::AddBoxesMakeCOB, "None", py::arg("S"), py::arg("TS"), py::arg("TA"));
cls_TopOpeBRep_ShapeScanner.def("Init", (void (TopOpeBRep_ShapeScanner::*)(const TopoDS_Shape &)) &TopOpeBRep_ShapeScanner::Init, "None", py::arg("E"));
cls_TopOpeBRep_ShapeScanner.def("Init", (void (TopOpeBRep_ShapeScanner::*)(TopOpeBRepTool_ShapeExplorer &)) &TopOpeBRep_ShapeScanner::Init, "None", py::arg("X"));
cls_TopOpeBRep_ShapeScanner.def("More", (Standard_Boolean (TopOpeBRep_ShapeScanner::*)() const) &TopOpeBRep_ShapeScanner::More, "None");
cls_TopOpeBRep_ShapeScanner.def("Next", (void (TopOpeBRep_ShapeScanner::*)()) &TopOpeBRep_ShapeScanner::Next, "None");
cls_TopOpeBRep_ShapeScanner.def("Current", (const TopoDS_Shape & (TopOpeBRep_ShapeScanner::*)() const) &TopOpeBRep_ShapeScanner::Current, "None");
cls_TopOpeBRep_ShapeScanner.def("BoxSort", (const TopOpeBRepTool_BoxSort & (TopOpeBRep_ShapeScanner::*)() const) &TopOpeBRep_ShapeScanner::BoxSort, "None");
cls_TopOpeBRep_ShapeScanner.def("ChangeBoxSort", (TopOpeBRepTool_BoxSort & (TopOpeBRep_ShapeScanner::*)()) &TopOpeBRep_ShapeScanner::ChangeBoxSort, "None");
cls_TopOpeBRep_ShapeScanner.def("Index", (Standard_Integer (TopOpeBRep_ShapeScanner::*)() const) &TopOpeBRep_ShapeScanner::Index, "None");
cls_TopOpeBRep_ShapeScanner.def("DumpCurrent", (Standard_OStream & (TopOpeBRep_ShapeScanner::*)(Standard_OStream &) const) &TopOpeBRep_ShapeScanner::DumpCurrent, "None", py::arg("OS"));

// Enums

}