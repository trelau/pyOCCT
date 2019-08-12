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
#include <TopoDS_Shape.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Plane.hxx>
#include <Standard_TypeDef.hxx>
#include <Prs3d_Projector.hxx>
#include <Geom_Transformation.hxx>
#include <Prs3d_Presentation.hxx>
#include <AIS_TangentRelation.hxx>
#include <Standard_Type.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <SelectMgr_Selection.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>

void bind_AIS_TangentRelation(py::module &mod){

py::class_<AIS_TangentRelation, opencascade::handle<AIS_TangentRelation>, AIS_Relation> cls_AIS_TangentRelation(mod, "AIS_TangentRelation", "A framework to display tangency constraints between two or more Interactive Objects of the datum type. The datums are normally faces or edges.");

// Constructors
cls_AIS_TangentRelation.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const opencascade::handle<Geom_Plane> &>(), py::arg("aFShape"), py::arg("aSShape"), py::arg("aPlane"));
cls_AIS_TangentRelation.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const opencascade::handle<Geom_Plane> &, const Standard_Integer>(), py::arg("aFShape"), py::arg("aSShape"), py::arg("aPlane"), py::arg("anExternRef"));

// Fields

// Methods
cls_AIS_TangentRelation.def("ExternRef", (Standard_Integer (AIS_TangentRelation::*)()) &AIS_TangentRelation::ExternRef, "Returns the external reference for tangency. The values are as follows: - 0 - there is no connection; - 1 - there is a connection to the first shape; - 2 - there is a connection to the second shape. This reference is defined at construction time.");
cls_AIS_TangentRelation.def("SetExternRef", (void (AIS_TangentRelation::*)(const Standard_Integer)) &AIS_TangentRelation::SetExternRef, "Sets the external reference for tangency, aRef. The values are as follows: - 0 - there is no connection; - 1 - there is a connection to the first shape; - 2 - there is a connection to the second shape. This reference is initially defined at construction time.", py::arg("aRef"));
cls_AIS_TangentRelation.def("Compute", (void (AIS_TangentRelation::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Prs3d_Presentation> &)) &AIS_TangentRelation::Compute, "computes the presentation according to a point of view given by <aProjector>. To be Used when the associated degenerated Presentations have been transformed by <aTrsf> which is not a Pure Translation. The HLR Prs can't be deducted automatically WARNING :<aTrsf> must be applied to the object to display before computation !!!", py::arg("aProjector"), py::arg("aTrsf"), py::arg("aPresentation"));
cls_AIS_TangentRelation.def_static("get_type_name_", (const char * (*)()) &AIS_TangentRelation::get_type_name, "None");
cls_AIS_TangentRelation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_TangentRelation::get_type_descriptor, "None");
cls_AIS_TangentRelation.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_TangentRelation::*)() const) &AIS_TangentRelation::DynamicType, "None");

// Enums

}