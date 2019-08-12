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
#include <IGESSelect_SelectFaces.hxx>
#include <Standard_Type.hxx>

void bind_IGESSelect_SelectFaces(py::module &mod){

py::class_<IGESSelect_SelectFaces, opencascade::handle<IGESSelect_SelectFaces>, IFSelect_SelectExplore> cls_IGESSelect_SelectFaces(mod, "IGESSelect_SelectFaces", "This selection returns the faces contained in an IGES Entity or itself if it is a Face Face means : - Face (510) of a ManifoldSolidBrep - TrimmedSurface (144) - BoundedSurface (143) - Plane with a Bounding Curve (108, form not 0) - Also, any Surface which is not in a TrimmedSurface, a BoundedSurface, or a Face (FREE Surface) -> i.e. a Face for which Natural Bounds will be considered");

// Constructors
cls_IGESSelect_SelectFaces.def(py::init<>());

// Fields

// Methods
cls_IGESSelect_SelectFaces.def("Explore", (Standard_Boolean (IGESSelect_SelectFaces::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_Graph &, Interface_EntityIterator &) const) &IGESSelect_SelectFaces::Explore, "Explores an entity, to take its faces Works recursively", py::arg("level"), py::arg("ent"), py::arg("G"), py::arg("explored"));
cls_IGESSelect_SelectFaces.def("ExploreLabel", (TCollection_AsciiString (IGESSelect_SelectFaces::*)() const) &IGESSelect_SelectFaces::ExploreLabel, "Returns a text defining the criterium : 'Faces'");
cls_IGESSelect_SelectFaces.def_static("get_type_name_", (const char * (*)()) &IGESSelect_SelectFaces::get_type_name, "None");
cls_IGESSelect_SelectFaces.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_SelectFaces::get_type_descriptor, "None");
cls_IGESSelect_SelectFaces.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_SelectFaces::*)() const) &IGESSelect_SelectFaces::DynamicType, "None");

// Enums

}