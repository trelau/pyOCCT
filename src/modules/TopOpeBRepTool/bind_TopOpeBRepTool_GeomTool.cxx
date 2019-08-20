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
#include <TopOpeBRepTool_OutCurveType.hxx>
#include <Standard_TypeDef.hxx>
#include <TopOpeBRepTool_GeomTool.hxx>

void bind_TopOpeBRepTool_GeomTool(py::module &mod){

py::class_<TopOpeBRepTool_GeomTool, std::unique_ptr<TopOpeBRepTool_GeomTool>> cls_TopOpeBRepTool_GeomTool(mod, "TopOpeBRepTool_GeomTool", "None");

// Constructors
cls_TopOpeBRepTool_GeomTool.def(py::init<>());
cls_TopOpeBRepTool_GeomTool.def(py::init<const TopOpeBRepTool_OutCurveType>(), py::arg("TypeC3D"));
cls_TopOpeBRepTool_GeomTool.def(py::init<const TopOpeBRepTool_OutCurveType, const Standard_Boolean>(), py::arg("TypeC3D"), py::arg("CompC3D"));
cls_TopOpeBRepTool_GeomTool.def(py::init<const TopOpeBRepTool_OutCurveType, const Standard_Boolean, const Standard_Boolean>(), py::arg("TypeC3D"), py::arg("CompC3D"), py::arg("CompPC1"));
cls_TopOpeBRepTool_GeomTool.def(py::init<const TopOpeBRepTool_OutCurveType, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("TypeC3D"), py::arg("CompC3D"), py::arg("CompPC1"), py::arg("CompPC2"));

// Fields

// Methods
// cls_TopOpeBRepTool_GeomTool.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool_GeomTool::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool_GeomTool.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool_GeomTool::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_GeomTool.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool_GeomTool::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool_GeomTool.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool_GeomTool::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_GeomTool.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool_GeomTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool_GeomTool.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool_GeomTool::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool_GeomTool.def("Define", (void (TopOpeBRepTool_GeomTool::*)(const TopOpeBRepTool_OutCurveType, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &TopOpeBRepTool_GeomTool::Define, "None", py::arg("TypeC3D"), py::arg("CompC3D"), py::arg("CompPC1"), py::arg("CompPC2"));
cls_TopOpeBRepTool_GeomTool.def("Define", (void (TopOpeBRepTool_GeomTool::*)(const TopOpeBRepTool_OutCurveType)) &TopOpeBRepTool_GeomTool::Define, "None", py::arg("TypeC3D"));
cls_TopOpeBRepTool_GeomTool.def("DefineCurves", (void (TopOpeBRepTool_GeomTool::*)(const Standard_Boolean)) &TopOpeBRepTool_GeomTool::DefineCurves, "None", py::arg("CompC3D"));
cls_TopOpeBRepTool_GeomTool.def("DefinePCurves1", (void (TopOpeBRepTool_GeomTool::*)(const Standard_Boolean)) &TopOpeBRepTool_GeomTool::DefinePCurves1, "None", py::arg("CompPC1"));
cls_TopOpeBRepTool_GeomTool.def("DefinePCurves2", (void (TopOpeBRepTool_GeomTool::*)(const Standard_Boolean)) &TopOpeBRepTool_GeomTool::DefinePCurves2, "None", py::arg("CompPC2"));
cls_TopOpeBRepTool_GeomTool.def("Define", (void (TopOpeBRepTool_GeomTool::*)(const TopOpeBRepTool_GeomTool &)) &TopOpeBRepTool_GeomTool::Define, "None", py::arg("GT"));
cls_TopOpeBRepTool_GeomTool.def("GetTolerances", [](TopOpeBRepTool_GeomTool &self, Standard_Real & tol3d, Standard_Real & tol2d){ self.GetTolerances(tol3d, tol2d); return std::tuple<Standard_Real &, Standard_Real &>(tol3d, tol2d); }, "None", py::arg("tol3d"), py::arg("tol2d"));
cls_TopOpeBRepTool_GeomTool.def("SetTolerances", (void (TopOpeBRepTool_GeomTool::*)(const Standard_Real, const Standard_Real)) &TopOpeBRepTool_GeomTool::SetTolerances, "None", py::arg("tol3d"), py::arg("tol2d"));
cls_TopOpeBRepTool_GeomTool.def("NbPntMax", (Standard_Integer (TopOpeBRepTool_GeomTool::*)() const) &TopOpeBRepTool_GeomTool::NbPntMax, "None");
cls_TopOpeBRepTool_GeomTool.def("SetNbPntMax", (void (TopOpeBRepTool_GeomTool::*)(const Standard_Integer)) &TopOpeBRepTool_GeomTool::SetNbPntMax, "None", py::arg("NbPntMax"));
cls_TopOpeBRepTool_GeomTool.def("TypeC3D", (TopOpeBRepTool_OutCurveType (TopOpeBRepTool_GeomTool::*)() const) &TopOpeBRepTool_GeomTool::TypeC3D, "None");
cls_TopOpeBRepTool_GeomTool.def("CompC3D", (Standard_Boolean (TopOpeBRepTool_GeomTool::*)() const) &TopOpeBRepTool_GeomTool::CompC3D, "None");
cls_TopOpeBRepTool_GeomTool.def("CompPC1", (Standard_Boolean (TopOpeBRepTool_GeomTool::*)() const) &TopOpeBRepTool_GeomTool::CompPC1, "None");
cls_TopOpeBRepTool_GeomTool.def("CompPC2", (Standard_Boolean (TopOpeBRepTool_GeomTool::*)() const) &TopOpeBRepTool_GeomTool::CompPC2, "None");

// Enums

}