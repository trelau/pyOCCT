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
#include <IGESSelect_SelectPCurves.hxx>
#include <Standard_Type.hxx>

void bind_IGESSelect_SelectPCurves(py::module &mod){

py::class_<IGESSelect_SelectPCurves, opencascade::handle<IGESSelect_SelectPCurves>, IFSelect_SelectExplore> cls_IGESSelect_SelectPCurves(mod, "IGESSelect_SelectPCurves", "This Selection returns the pcurves which lie on a face In two modes : global (i.e. a CompositeCurve is not explored) or basic (all the basic curves are listed)");

// Constructors
cls_IGESSelect_SelectPCurves.def(py::init<const Standard_Boolean>(), py::arg("basic"));

// Fields

// Methods
cls_IGESSelect_SelectPCurves.def("Explore", (Standard_Boolean (IGESSelect_SelectPCurves::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_Graph &, Interface_EntityIterator &) const) &IGESSelect_SelectPCurves::Explore, "Explores an entity, to take its contained PCurves An independant curve is IGNORED : only faces are explored", py::arg("level"), py::arg("ent"), py::arg("G"), py::arg("explored"));
cls_IGESSelect_SelectPCurves.def("ExploreLabel", (TCollection_AsciiString (IGESSelect_SelectPCurves::*)() const) &IGESSelect_SelectPCurves::ExploreLabel, "Returns a text defining the criterium : 'Basic PCurves' or 'Global PCurves'");
cls_IGESSelect_SelectPCurves.def_static("get_type_name_", (const char * (*)()) &IGESSelect_SelectPCurves::get_type_name, "None");
cls_IGESSelect_SelectPCurves.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_SelectPCurves::get_type_descriptor, "None");
cls_IGESSelect_SelectPCurves.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_SelectPCurves::*)() const) &IGESSelect_SelectPCurves::DynamicType, "None");

// Enums

}