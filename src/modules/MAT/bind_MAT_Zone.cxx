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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <MAT_BasicElt.hxx>
#include <Standard_TypeDef.hxx>
#include <MAT_Arc.hxx>
#include <MAT_Zone.hxx>
#include <Standard_Type.hxx>
#include <MAT_Node.hxx>
#include <MAT_Side.hxx>
#include <MAT_SequenceOfArc.hxx>

void bind_MAT_Zone(py::module &mod){

py::class_<MAT_Zone, opencascade::handle<MAT_Zone>, Standard_Transient> cls_MAT_Zone(mod, "MAT_Zone", "Definition of Zone of Proximity of a BasicElt : ---------------------------------------------- A Zone of proximity is the set of the points which are more near from the BasicElt than any other.");

// Constructors
cls_MAT_Zone.def(py::init<>());
cls_MAT_Zone.def(py::init<const opencascade::handle<MAT_BasicElt> &>(), py::arg("aBasicElt"));

// Fields

// Methods
cls_MAT_Zone.def("Perform", (void (MAT_Zone::*)(const opencascade::handle<MAT_BasicElt> &)) &MAT_Zone::Perform, "Compute the frontier of the Zone of proximity.", py::arg("aBasicElt"));
cls_MAT_Zone.def("NumberOfArcs", (Standard_Integer (MAT_Zone::*)() const) &MAT_Zone::NumberOfArcs, "Return the number Of Arcs On the frontier of <me>.");
cls_MAT_Zone.def("ArcOnFrontier", (opencascade::handle<MAT_Arc> (MAT_Zone::*)(const Standard_Integer) const) &MAT_Zone::ArcOnFrontier, "Return the Arc number <Index> on the frontier. of <me>.", py::arg("Index"));
cls_MAT_Zone.def("NoEmptyZone", (Standard_Boolean (MAT_Zone::*)() const) &MAT_Zone::NoEmptyZone, "Return TRUE if <me> is not empty .");
cls_MAT_Zone.def("Limited", (Standard_Boolean (MAT_Zone::*)() const) &MAT_Zone::Limited, "Return TRUE if <me> is Limited.");
cls_MAT_Zone.def_static("get_type_name_", (const char * (*)()) &MAT_Zone::get_type_name, "None");
cls_MAT_Zone.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MAT_Zone::get_type_descriptor, "None");
cls_MAT_Zone.def("DynamicType", (const opencascade::handle<Standard_Type> & (MAT_Zone::*)() const) &MAT_Zone::DynamicType, "None");

// Enums

}