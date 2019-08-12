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
#include <IFSelect_SelectExplore.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Interface_Graph.hxx>
#include <Interface_EntityIterator.hxx>
#include <TCollection_AsciiString.hxx>
#include <STEPSelections_SelectGSCurves.hxx>
#include <Standard_Type.hxx>

void bind_STEPSelections_SelectGSCurves(py::module &mod){

py::class_<STEPSelections_SelectGSCurves, opencascade::handle<STEPSelections_SelectGSCurves>, IFSelect_SelectExplore> cls_STEPSelections_SelectGSCurves(mod, "STEPSelections_SelectGSCurves", "This selection returns 'curves in the geometric_set (except composite curves)'");

// Constructors
cls_STEPSelections_SelectGSCurves.def(py::init<>());

// Fields

// Methods
cls_STEPSelections_SelectGSCurves.def("Explore", (Standard_Boolean (STEPSelections_SelectGSCurves::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_Graph &, Interface_EntityIterator &) const) &STEPSelections_SelectGSCurves::Explore, "None", py::arg("level"), py::arg("ent"), py::arg("G"), py::arg("explored"));
cls_STEPSelections_SelectGSCurves.def("ExploreLabel", (TCollection_AsciiString (STEPSelections_SelectGSCurves::*)() const) &STEPSelections_SelectGSCurves::ExploreLabel, "Returns a text defining the criterium : 'Curves'");
cls_STEPSelections_SelectGSCurves.def_static("get_type_name_", (const char * (*)()) &STEPSelections_SelectGSCurves::get_type_name, "None");
cls_STEPSelections_SelectGSCurves.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &STEPSelections_SelectGSCurves::get_type_descriptor, "None");
cls_STEPSelections_SelectGSCurves.def("DynamicType", (const opencascade::handle<Standard_Type> & (STEPSelections_SelectGSCurves::*)() const) &STEPSelections_SelectGSCurves::DynamicType, "None");

// Enums

}