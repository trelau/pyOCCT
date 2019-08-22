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
#include <TopOpeBRepDS_InterferenceIterator.hxx>
#include <Standard.hxx>
#include <TopOpeBRepDS_ListOfInterference.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepDS_Interference.hxx>
#include <TopAbs_Orientation.hxx>
#include <TopAbs_State.hxx>
#include <Geom2d_Curve.hxx>
#include <TopOpeBRepDS_CurveIterator.hxx>

void bind_TopOpeBRepDS_CurveIterator(py::module &mod){

py::class_<TopOpeBRepDS_CurveIterator, TopOpeBRepDS_InterferenceIterator> cls_TopOpeBRepDS_CurveIterator(mod, "TopOpeBRepDS_CurveIterator", "None");

// Constructors
cls_TopOpeBRepDS_CurveIterator.def(py::init<const TopOpeBRepDS_ListOfInterference &>(), py::arg("L"));

// Fields

// Methods
// cls_TopOpeBRepDS_CurveIterator.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_CurveIterator::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_CurveIterator.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_CurveIterator::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_CurveIterator.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_CurveIterator::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_CurveIterator.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_CurveIterator::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_CurveIterator.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_CurveIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_CurveIterator.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_CurveIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_CurveIterator.def("MatchInterference", (Standard_Boolean (TopOpeBRepDS_CurveIterator::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const) &TopOpeBRepDS_CurveIterator::MatchInterference, "Returns True if the Interference <I> has a GeometryType() TopOpeBRepDS_CURVE returns False else.", py::arg("I"));
cls_TopOpeBRepDS_CurveIterator.def("Current", (Standard_Integer (TopOpeBRepDS_CurveIterator::*)() const) &TopOpeBRepDS_CurveIterator::Current, "Index of the curve in the data structure.");
cls_TopOpeBRepDS_CurveIterator.def("Orientation", (TopAbs_Orientation (TopOpeBRepDS_CurveIterator::*)(const TopAbs_State) const) &TopOpeBRepDS_CurveIterator::Orientation, "None", py::arg("S"));
cls_TopOpeBRepDS_CurveIterator.def("PCurve", (const opencascade::handle<Geom2d_Curve> & (TopOpeBRepDS_CurveIterator::*)() const) &TopOpeBRepDS_CurveIterator::PCurve, "None");

// Enums

}