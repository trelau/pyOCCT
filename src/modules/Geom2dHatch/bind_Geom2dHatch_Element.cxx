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
#include <Geom2dHatch_Element.hxx>
#include <Geom2dAdaptor_Curve.hxx>
#include <TopAbs_Orientation.hxx>

void bind_Geom2dHatch_Element(py::module &mod){

py::class_<Geom2dHatch_Element, std::unique_ptr<Geom2dHatch_Element, Deleter<Geom2dHatch_Element>>> cls_Geom2dHatch_Element(mod, "Geom2dHatch_Element", "None");

// Constructors
cls_Geom2dHatch_Element.def(py::init<>());
cls_Geom2dHatch_Element.def(py::init<const Geom2dHatch_Element &>(), py::arg("Other"));
cls_Geom2dHatch_Element.def(py::init<const Geom2dAdaptor_Curve &>(), py::arg("Curve"));
cls_Geom2dHatch_Element.def(py::init<const Geom2dAdaptor_Curve &, const TopAbs_Orientation>(), py::arg("Curve"), py::arg("Orientation"));

// Fields

// Methods
// cls_Geom2dHatch_Element.def_static("operator new_", (void * (*)(size_t)) &Geom2dHatch_Element::operator new, "None", py::arg("theSize"));
// cls_Geom2dHatch_Element.def_static("operator delete_", (void (*)(void *)) &Geom2dHatch_Element::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dHatch_Element.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dHatch_Element::operator new[], "None", py::arg("theSize"));
// cls_Geom2dHatch_Element.def_static("operator delete[]_", (void (*)(void *)) &Geom2dHatch_Element::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dHatch_Element.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dHatch_Element::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dHatch_Element.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dHatch_Element::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dHatch_Element.def("Curve", (const Geom2dAdaptor_Curve & (Geom2dHatch_Element::*)() const) &Geom2dHatch_Element::Curve, "Returns the curve associated to the element.");
cls_Geom2dHatch_Element.def("ChangeCurve", (Geom2dAdaptor_Curve & (Geom2dHatch_Element::*)()) &Geom2dHatch_Element::ChangeCurve, "Returns the curve associated to the element.");
cls_Geom2dHatch_Element.def("Orientation", (void (Geom2dHatch_Element::*)(const TopAbs_Orientation)) &Geom2dHatch_Element::Orientation, "Sets the orientation of the element.", py::arg("Orientation"));
cls_Geom2dHatch_Element.def("Orientation", (TopAbs_Orientation (Geom2dHatch_Element::*)() const) &Geom2dHatch_Element::Orientation, "Returns the orientation of the element.");

// Enums

}