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
#include <TopOpeBRepDS_PointIterator.hxx>

void bind_TopOpeBRepDS_PointIterator(py::module &mod){

py::class_<TopOpeBRepDS_PointIterator, std::unique_ptr<TopOpeBRepDS_PointIterator, Deleter<TopOpeBRepDS_PointIterator>>, TopOpeBRepDS_InterferenceIterator> cls_TopOpeBRepDS_PointIterator(mod, "TopOpeBRepDS_PointIterator", "None");

// Constructors
cls_TopOpeBRepDS_PointIterator.def(py::init<const TopOpeBRepDS_ListOfInterference &>(), py::arg("L"));

// Fields

// Methods
// cls_TopOpeBRepDS_PointIterator.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_PointIterator::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_PointIterator.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_PointIterator::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_PointIterator.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_PointIterator::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_PointIterator.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_PointIterator::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_PointIterator.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_PointIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_PointIterator.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_PointIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_PointIterator.def("MatchInterference", (Standard_Boolean (TopOpeBRepDS_PointIterator::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const) &TopOpeBRepDS_PointIterator::MatchInterference, "Returns True if the Interference <I> has a GeometryType() TopOpeBRepDS_POINT or TopOpeBRepDS_VERTEX returns False else.", py::arg("I"));
cls_TopOpeBRepDS_PointIterator.def("Current", (Standard_Integer (TopOpeBRepDS_PointIterator::*)() const) &TopOpeBRepDS_PointIterator::Current, "Index of the point in the data structure.");
cls_TopOpeBRepDS_PointIterator.def("Orientation", (TopAbs_Orientation (TopOpeBRepDS_PointIterator::*)(const TopAbs_State) const) &TopOpeBRepDS_PointIterator::Orientation, "None", py::arg("S"));
cls_TopOpeBRepDS_PointIterator.def("Parameter", (Standard_Real (TopOpeBRepDS_PointIterator::*)() const) &TopOpeBRepDS_PointIterator::Parameter, "None");
cls_TopOpeBRepDS_PointIterator.def("IsVertex", (Standard_Boolean (TopOpeBRepDS_PointIterator::*)() const) &TopOpeBRepDS_PointIterator::IsVertex, "None");
cls_TopOpeBRepDS_PointIterator.def("IsPoint", (Standard_Boolean (TopOpeBRepDS_PointIterator::*)() const) &TopOpeBRepDS_PointIterator::IsPoint, "None");
cls_TopOpeBRepDS_PointIterator.def("DiffOriented", (Standard_Boolean (TopOpeBRepDS_PointIterator::*)() const) &TopOpeBRepDS_PointIterator::DiffOriented, "None");
cls_TopOpeBRepDS_PointIterator.def("SameOriented", (Standard_Boolean (TopOpeBRepDS_PointIterator::*)() const) &TopOpeBRepDS_PointIterator::SameOriented, "None");
cls_TopOpeBRepDS_PointIterator.def("Support", (Standard_Integer (TopOpeBRepDS_PointIterator::*)() const) &TopOpeBRepDS_PointIterator::Support, "None");

// Enums

}