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
#include <IGESData_IGESEntity.hxx>
#include <IGESSelect_SelectBasicGeom.hxx>
#include <Standard_Type.hxx>

void bind_IGESSelect_SelectBasicGeom(py::module &mod){

py::class_<IGESSelect_SelectBasicGeom, opencascade::handle<IGESSelect_SelectBasicGeom>, IFSelect_SelectExplore> cls_IGESSelect_SelectBasicGeom(mod, "IGESSelect_SelectBasicGeom", "This selection returns the basic geometric elements contained in an IGES Entity Intended to run a 'quick' transfer. I.E. : - for a Group, considers its Elements - for a Trimmed or Bounded Surface or a Face (BREP), considers the 3D curves of each of its loops - for a Plane (108), considers its Bounding Curve - for a Curve itself, takes it");

// Constructors
cls_IGESSelect_SelectBasicGeom.def(py::init<const Standard_Integer>(), py::arg("mode"));

// Fields

// Methods
// cls_IGESSelect_SelectBasicGeom.def("CurvesOnly", (Standard_Boolean (IGESSelect_SelectBasicGeom::*)() const) &IGESSelect_SelectBasicGeom::CurvesOnly, "None");
cls_IGESSelect_SelectBasicGeom.def("Explore", (Standard_Boolean (IGESSelect_SelectBasicGeom::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_Graph &, Interface_EntityIterator &) const) &IGESSelect_SelectBasicGeom::Explore, "Explores an entity, to take its contained Curves 3d Works recursively", py::arg("level"), py::arg("ent"), py::arg("G"), py::arg("explored"));
cls_IGESSelect_SelectBasicGeom.def("ExploreLabel", (TCollection_AsciiString (IGESSelect_SelectBasicGeom::*)() const) &IGESSelect_SelectBasicGeom::ExploreLabel, "Returns a text defining the criterium : 'Curves 3d' or 'Basic Geometry'");
cls_IGESSelect_SelectBasicGeom.def_static("SubCurves_", (Standard_Boolean (*)(const opencascade::handle<IGESData_IGESEntity> &, Interface_EntityIterator &)) &IGESSelect_SelectBasicGeom::SubCurves, "This method can be called from everywhere to get the curves as sub-elements of a given curve : CompositeCurve : explored lists its subs + returns True Any Curve : explored is not filled but returned is True Other : returned is False", py::arg("ent"), py::arg("explored"));
cls_IGESSelect_SelectBasicGeom.def_static("get_type_name_", (const char * (*)()) &IGESSelect_SelectBasicGeom::get_type_name, "None");
cls_IGESSelect_SelectBasicGeom.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_SelectBasicGeom::get_type_descriptor, "None");
cls_IGESSelect_SelectBasicGeom.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_SelectBasicGeom::*)() const) &IGESSelect_SelectBasicGeom::DynamicType, "None");

// Enums

}