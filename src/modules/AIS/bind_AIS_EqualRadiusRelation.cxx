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
#include <AIS_Relation.hxx>
#include <TopoDS_Edge.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Plane.hxx>
#include <Prs3d_Projector.hxx>
#include <Geom_Transformation.hxx>
#include <Prs3d_Presentation.hxx>
#include <AIS_EqualRadiusRelation.hxx>
#include <Standard_Type.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <Standard_TypeDef.hxx>
#include <SelectMgr_Selection.hxx>
#include <gp_Pnt.hxx>

void bind_AIS_EqualRadiusRelation(py::module &mod){

py::class_<AIS_EqualRadiusRelation, opencascade::handle<AIS_EqualRadiusRelation>, AIS_Relation> cls_AIS_EqualRadiusRelation(mod, "AIS_EqualRadiusRelation", "None");

// Constructors
cls_AIS_EqualRadiusRelation.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &, const opencascade::handle<Geom_Plane> &>(), py::arg("aFirstEdge"), py::arg("aSecondEdge"), py::arg("aPlane"));

// Fields

// Methods
cls_AIS_EqualRadiusRelation.def("Compute", (void (AIS_EqualRadiusRelation::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Prs3d_Presentation> &)) &AIS_EqualRadiusRelation::Compute, "computes the presentation according to a point of view given by <aProjector>. To be Used when the associated degenerated Presentations have been transformed by <aTrsf> which is not a Pure Translation. The HLR Prs can't be deducted automatically WARNING :<aTrsf> must be applied to the object to display before computation !!!", py::arg("aProjector"), py::arg("aTrsf"), py::arg("aPresentation"));
cls_AIS_EqualRadiusRelation.def_static("get_type_name_", (const char * (*)()) &AIS_EqualRadiusRelation::get_type_name, "None");
cls_AIS_EqualRadiusRelation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_EqualRadiusRelation::get_type_descriptor, "None");
cls_AIS_EqualRadiusRelation.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_EqualRadiusRelation::*)() const) &AIS_EqualRadiusRelation::DynamicType, "None");

// Enums

}