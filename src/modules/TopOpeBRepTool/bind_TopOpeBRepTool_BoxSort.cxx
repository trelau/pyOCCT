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
#include <TopOpeBRepTool_HBoxTool.hxx>
#include <TopoDS_Shape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <Bnd_HArray1OfBox.hxx>
#include <Bnd_Box.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <Bnd_BoundSortBox.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <TopOpeBRepTool_BoxSort.hxx>

void bind_TopOpeBRepTool_BoxSort(py::module &mod){

py::class_<TopOpeBRepTool_BoxSort, std::unique_ptr<TopOpeBRepTool_BoxSort>> cls_TopOpeBRepTool_BoxSort(mod, "TopOpeBRepTool_BoxSort", "None");

// Constructors
cls_TopOpeBRepTool_BoxSort.def(py::init<>());
cls_TopOpeBRepTool_BoxSort.def(py::init<const opencascade::handle<TopOpeBRepTool_HBoxTool> &>(), py::arg("T"));

// Fields

// Methods
// cls_TopOpeBRepTool_BoxSort.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool_BoxSort::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool_BoxSort.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool_BoxSort::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_BoxSort.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool_BoxSort::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool_BoxSort.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool_BoxSort::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_BoxSort.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool_BoxSort::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool_BoxSort.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool_BoxSort::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool_BoxSort.def("SetHBoxTool", (void (TopOpeBRepTool_BoxSort::*)(const opencascade::handle<TopOpeBRepTool_HBoxTool> &)) &TopOpeBRepTool_BoxSort::SetHBoxTool, "None", py::arg("T"));
cls_TopOpeBRepTool_BoxSort.def("HBoxTool", (const opencascade::handle<TopOpeBRepTool_HBoxTool> & (TopOpeBRepTool_BoxSort::*)() const) &TopOpeBRepTool_BoxSort::HBoxTool, "None");
cls_TopOpeBRepTool_BoxSort.def("Clear", (void (TopOpeBRepTool_BoxSort::*)()) &TopOpeBRepTool_BoxSort::Clear, "None");
cls_TopOpeBRepTool_BoxSort.def("AddBoxes", [](TopOpeBRepTool_BoxSort &self, const TopoDS_Shape & a0, const TopAbs_ShapeEnum a1) -> void { return self.AddBoxes(a0, a1); });
cls_TopOpeBRepTool_BoxSort.def("AddBoxes", (void (TopOpeBRepTool_BoxSort::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepTool_BoxSort::AddBoxes, "None", py::arg("S"), py::arg("TS"), py::arg("TA"));
cls_TopOpeBRepTool_BoxSort.def("MakeHAB", [](TopOpeBRepTool_BoxSort &self, const TopoDS_Shape & a0, const TopAbs_ShapeEnum a1) -> void { return self.MakeHAB(a0, a1); });
cls_TopOpeBRepTool_BoxSort.def("MakeHAB", (void (TopOpeBRepTool_BoxSort::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepTool_BoxSort::MakeHAB, "None", py::arg("S"), py::arg("TS"), py::arg("TA"));
cls_TopOpeBRepTool_BoxSort.def("HAB", (const opencascade::handle<Bnd_HArray1OfBox> & (TopOpeBRepTool_BoxSort::*)() const) &TopOpeBRepTool_BoxSort::HAB, "None");
cls_TopOpeBRepTool_BoxSort.def_static("MakeHABCOB_", (void (*)(const opencascade::handle<Bnd_HArray1OfBox> &, Bnd_Box &)) &TopOpeBRepTool_BoxSort::MakeHABCOB, "None", py::arg("HAB"), py::arg("COB"));
cls_TopOpeBRepTool_BoxSort.def("HABShape", (const TopoDS_Shape & (TopOpeBRepTool_BoxSort::*)(const Standard_Integer) const) &TopOpeBRepTool_BoxSort::HABShape, "None", py::arg("I"));
cls_TopOpeBRepTool_BoxSort.def("MakeCOB", [](TopOpeBRepTool_BoxSort &self, const TopoDS_Shape & a0, const TopAbs_ShapeEnum a1) -> void { return self.MakeCOB(a0, a1); });
cls_TopOpeBRepTool_BoxSort.def("MakeCOB", (void (TopOpeBRepTool_BoxSort::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepTool_BoxSort::MakeCOB, "None", py::arg("S"), py::arg("TS"), py::arg("TA"));
cls_TopOpeBRepTool_BoxSort.def("AddBoxesMakeCOB", [](TopOpeBRepTool_BoxSort &self, const TopoDS_Shape & a0, const TopAbs_ShapeEnum a1) -> void { return self.AddBoxesMakeCOB(a0, a1); });
cls_TopOpeBRepTool_BoxSort.def("AddBoxesMakeCOB", (void (TopOpeBRepTool_BoxSort::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepTool_BoxSort::AddBoxesMakeCOB, "None", py::arg("S"), py::arg("TS"), py::arg("TA"));
cls_TopOpeBRepTool_BoxSort.def("Compare", (const TColStd_ListIteratorOfListOfInteger & (TopOpeBRepTool_BoxSort::*)(const TopoDS_Shape &)) &TopOpeBRepTool_BoxSort::Compare, "None", py::arg("S"));
cls_TopOpeBRepTool_BoxSort.def("TouchedShape", (const TopoDS_Shape & (TopOpeBRepTool_BoxSort::*)(const TColStd_ListIteratorOfListOfInteger &) const) &TopOpeBRepTool_BoxSort::TouchedShape, "None", py::arg("I"));
cls_TopOpeBRepTool_BoxSort.def("Box", (const Bnd_Box & (TopOpeBRepTool_BoxSort::*)(const TopoDS_Shape &) const) &TopOpeBRepTool_BoxSort::Box, "None", py::arg("S"));

// Enums

}