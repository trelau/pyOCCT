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
#include <BRepFill_LocationLaw.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Trsf.hxx>
#include <BRepFill_SectionPlacement.hxx>

void bind_BRepFill_SectionPlacement(py::module &mod){

py::class_<BRepFill_SectionPlacement, std::unique_ptr<BRepFill_SectionPlacement, Deleter<BRepFill_SectionPlacement>>> cls_BRepFill_SectionPlacement(mod, "BRepFill_SectionPlacement", "Place a shape in a local axis coordinate");

// Constructors
cls_BRepFill_SectionPlacement.def(py::init<const opencascade::handle<BRepFill_LocationLaw> &, const TopoDS_Shape &>(), py::arg("Law"), py::arg("Section"));
cls_BRepFill_SectionPlacement.def(py::init<const opencascade::handle<BRepFill_LocationLaw> &, const TopoDS_Shape &, const Standard_Boolean>(), py::arg("Law"), py::arg("Section"), py::arg("WithContact"));
cls_BRepFill_SectionPlacement.def(py::init<const opencascade::handle<BRepFill_LocationLaw> &, const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean>(), py::arg("Law"), py::arg("Section"), py::arg("WithContact"), py::arg("WithCorrection"));
cls_BRepFill_SectionPlacement.def(py::init<const opencascade::handle<BRepFill_LocationLaw> &, const TopoDS_Shape &, const TopoDS_Shape &>(), py::arg("Law"), py::arg("Section"), py::arg("Vertex"));
cls_BRepFill_SectionPlacement.def(py::init<const opencascade::handle<BRepFill_LocationLaw> &, const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Boolean>(), py::arg("Law"), py::arg("Section"), py::arg("Vertex"), py::arg("WithContact"));
cls_BRepFill_SectionPlacement.def(py::init<const opencascade::handle<BRepFill_LocationLaw> &, const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean>(), py::arg("Law"), py::arg("Section"), py::arg("Vertex"), py::arg("WithContact"), py::arg("WithCorrection"));

// Fields

// Methods
// cls_BRepFill_SectionPlacement.def_static("operator new_", (void * (*)(size_t)) &BRepFill_SectionPlacement::operator new, "None", py::arg("theSize"));
// cls_BRepFill_SectionPlacement.def_static("operator delete_", (void (*)(void *)) &BRepFill_SectionPlacement::operator delete, "None", py::arg("theAddress"));
// cls_BRepFill_SectionPlacement.def_static("operator new[]_", (void * (*)(size_t)) &BRepFill_SectionPlacement::operator new[], "None", py::arg("theSize"));
// cls_BRepFill_SectionPlacement.def_static("operator delete[]_", (void (*)(void *)) &BRepFill_SectionPlacement::operator delete[], "None", py::arg("theAddress"));
// cls_BRepFill_SectionPlacement.def_static("operator new_", (void * (*)(size_t, void *)) &BRepFill_SectionPlacement::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepFill_SectionPlacement.def_static("operator delete_", (void (*)(void *, void *)) &BRepFill_SectionPlacement::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepFill_SectionPlacement.def("Transformation", (const gp_Trsf & (BRepFill_SectionPlacement::*)() const) &BRepFill_SectionPlacement::Transformation, "None");
cls_BRepFill_SectionPlacement.def("AbscissaOnPath", (Standard_Real (BRepFill_SectionPlacement::*)()) &BRepFill_SectionPlacement::AbscissaOnPath, "None");

// Enums

}