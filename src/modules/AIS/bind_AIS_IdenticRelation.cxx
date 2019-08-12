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
#include <TColStd_ListOfTransient.hxx>
#include <Standard_Transient.hxx>
#include <Prs3d_Projector.hxx>
#include <Geom_Transformation.hxx>
#include <Prs3d_Presentation.hxx>
#include <AIS_IdenticRelation.hxx>
#include <Standard_Type.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <SelectMgr_Selection.hxx>
#include <Geom_Line.hxx>
#include <gp_Pnt.hxx>
#include <Geom_Circle.hxx>
#include <Geom_Ellipse.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Vertex.hxx>
#include <gp_Dir.hxx>

void bind_AIS_IdenticRelation(py::module &mod){

py::class_<AIS_IdenticRelation, opencascade::handle<AIS_IdenticRelation>, AIS_Relation> cls_AIS_IdenticRelation(mod, "AIS_IdenticRelation", "Constructs a constraint by a relation of identity between two or more datums figuring in shape Interactive Objects.");

// Constructors
cls_AIS_IdenticRelation.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const opencascade::handle<Geom_Plane> &>(), py::arg("FirstShape"), py::arg("SecondShape"), py::arg("aPlane"));

// Fields

// Methods
cls_AIS_IdenticRelation.def("HasUsers", (Standard_Boolean (AIS_IdenticRelation::*)() const) &AIS_IdenticRelation::HasUsers, "None");
cls_AIS_IdenticRelation.def("Users", (const TColStd_ListOfTransient & (AIS_IdenticRelation::*)() const) &AIS_IdenticRelation::Users, "None");
cls_AIS_IdenticRelation.def("AddUser", (void (AIS_IdenticRelation::*)(const opencascade::handle<Standard_Transient> &)) &AIS_IdenticRelation::AddUser, "None", py::arg("theUser"));
cls_AIS_IdenticRelation.def("ClearUsers", (void (AIS_IdenticRelation::*)()) &AIS_IdenticRelation::ClearUsers, "None");
cls_AIS_IdenticRelation.def("IsMovable", (Standard_Boolean (AIS_IdenticRelation::*)() const) &AIS_IdenticRelation::IsMovable, "Returns true if the interactive object is movable.");
cls_AIS_IdenticRelation.def("Compute", (void (AIS_IdenticRelation::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Prs3d_Presentation> &)) &AIS_IdenticRelation::Compute, "computes the presentation according to a point of view given by <aProjector>. To be Used when the associated degenerated Presentations have been transformed by <aTrsf> which is not a Pure Translation. The HLR Prs can't be deducted automatically WARNING :<aTrsf> must be applied to the object to display before computation !!!", py::arg("aProjector"), py::arg("aTrsf"), py::arg("aPresentation"));
cls_AIS_IdenticRelation.def_static("get_type_name_", (const char * (*)()) &AIS_IdenticRelation::get_type_name, "None");
cls_AIS_IdenticRelation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_IdenticRelation::get_type_descriptor, "None");
cls_AIS_IdenticRelation.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_IdenticRelation::*)() const) &AIS_IdenticRelation::DynamicType, "None");

// Enums

}