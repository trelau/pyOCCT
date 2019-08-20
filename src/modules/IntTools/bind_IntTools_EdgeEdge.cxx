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
#include <TopoDS_Edge.hxx>
#include <Standard_TypeDef.hxx>
#include <IntTools_Range.hxx>
#include <IntTools_SequenceOfCommonPrts.hxx>
#include <IntTools_SequenceOfRanges.hxx>
#include <Bnd_Box.hxx>
#include <BRepAdaptor_Curve.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <IntTools_EdgeEdge.hxx>

void bind_IntTools_EdgeEdge(py::module &mod){

py::class_<IntTools_EdgeEdge, std::unique_ptr<IntTools_EdgeEdge>> cls_IntTools_EdgeEdge(mod, "IntTools_EdgeEdge", "The class provides Edge/Edge intersection algorithm based on the intersection between edges bounding boxes.");

// Constructors
cls_IntTools_EdgeEdge.def(py::init<>());
cls_IntTools_EdgeEdge.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &>(), py::arg("theEdge1"), py::arg("theEdge2"));
cls_IntTools_EdgeEdge.def(py::init<const TopoDS_Edge &, const Standard_Real, const Standard_Real, const TopoDS_Edge &, const Standard_Real, const Standard_Real>(), py::arg("theEdge1"), py::arg("aT11"), py::arg("aT12"), py::arg("theEdge2"), py::arg("aT21"), py::arg("aT22"));

// Fields

// Methods
// cls_IntTools_EdgeEdge.def_static("operator new_", (void * (*)(size_t)) &IntTools_EdgeEdge::operator new, "None", py::arg("theSize"));
// cls_IntTools_EdgeEdge.def_static("operator delete_", (void (*)(void *)) &IntTools_EdgeEdge::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_EdgeEdge.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_EdgeEdge::operator new[], "None", py::arg("theSize"));
// cls_IntTools_EdgeEdge.def_static("operator delete[]_", (void (*)(void *)) &IntTools_EdgeEdge::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_EdgeEdge.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_EdgeEdge::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_EdgeEdge.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_EdgeEdge::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_EdgeEdge.def("SetEdge1", (void (IntTools_EdgeEdge::*)(const TopoDS_Edge &)) &IntTools_EdgeEdge::SetEdge1, "Sets the first edge", py::arg("theEdge"));
cls_IntTools_EdgeEdge.def("SetEdge1", (void (IntTools_EdgeEdge::*)(const TopoDS_Edge &, const Standard_Real, const Standard_Real)) &IntTools_EdgeEdge::SetEdge1, "Sets the first edge and its range", py::arg("theEdge"), py::arg("aT1"), py::arg("aT2"));
cls_IntTools_EdgeEdge.def("SetRange1", (void (IntTools_EdgeEdge::*)(const IntTools_Range &)) &IntTools_EdgeEdge::SetRange1, "Sets the range for the first edge", py::arg("theRange1"));
cls_IntTools_EdgeEdge.def("SetRange1", (void (IntTools_EdgeEdge::*)(const Standard_Real, const Standard_Real)) &IntTools_EdgeEdge::SetRange1, "Sets the range for the first edge", py::arg("aT1"), py::arg("aT2"));
cls_IntTools_EdgeEdge.def("SetEdge2", (void (IntTools_EdgeEdge::*)(const TopoDS_Edge &)) &IntTools_EdgeEdge::SetEdge2, "Sets the second edge", py::arg("theEdge"));
cls_IntTools_EdgeEdge.def("SetEdge2", (void (IntTools_EdgeEdge::*)(const TopoDS_Edge &, const Standard_Real, const Standard_Real)) &IntTools_EdgeEdge::SetEdge2, "Sets the first edge and its range", py::arg("theEdge"), py::arg("aT1"), py::arg("aT2"));
cls_IntTools_EdgeEdge.def("SetRange2", (void (IntTools_EdgeEdge::*)(const IntTools_Range &)) &IntTools_EdgeEdge::SetRange2, "Sets the range for the second edge", py::arg("theRange"));
cls_IntTools_EdgeEdge.def("SetRange2", (void (IntTools_EdgeEdge::*)(const Standard_Real, const Standard_Real)) &IntTools_EdgeEdge::SetRange2, "Sets the range for the second edge", py::arg("aT1"), py::arg("aT2"));
cls_IntTools_EdgeEdge.def("SetFuzzyValue", (void (IntTools_EdgeEdge::*)(const Standard_Real)) &IntTools_EdgeEdge::SetFuzzyValue, "Sets the Fuzzy value", py::arg("theFuzz"));
cls_IntTools_EdgeEdge.def("Perform", (void (IntTools_EdgeEdge::*)()) &IntTools_EdgeEdge::Perform, "Performs the intersection between edges");
cls_IntTools_EdgeEdge.def("IsDone", (Standard_Boolean (IntTools_EdgeEdge::*)() const) &IntTools_EdgeEdge::IsDone, "Returns TRUE if common part(s) is(are) found");
cls_IntTools_EdgeEdge.def("FuzzyValue", (Standard_Real (IntTools_EdgeEdge::*)() const) &IntTools_EdgeEdge::FuzzyValue, "Returns Fuzzy value");
cls_IntTools_EdgeEdge.def("CommonParts", (const IntTools_SequenceOfCommonPrts & (IntTools_EdgeEdge::*)() const) &IntTools_EdgeEdge::CommonParts, "Returns common parts");
cls_IntTools_EdgeEdge.def("UseQuickCoincidenceCheck", (void (IntTools_EdgeEdge::*)(const Standard_Boolean)) &IntTools_EdgeEdge::UseQuickCoincidenceCheck, "Sets the flag myQuickCoincidenceCheck", py::arg("bFlag"));
cls_IntTools_EdgeEdge.def("IsCoincidenceCheckedQuickly", (Standard_Boolean (IntTools_EdgeEdge::*)()) &IntTools_EdgeEdge::IsCoincidenceCheckedQuickly, "Returns the flag myQuickCoincidenceCheck");

// Enums

}