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
#include <TopoDS_Wire.hxx>
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <Prs3d_Projector.hxx>
#include <Geom_Transformation.hxx>
#include <Prs3d_Presentation.hxx>
#include <AIS_FixRelation.hxx>
#include <Standard_Type.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <SelectMgr_Selection.hxx>
#include <TopoDS_Vertex.hxx>
#include <Geom_Curve.hxx>
#include <TopoDS_Edge.hxx>
#include <gp_Lin.hxx>
#include <gp_Circ.hxx>

void bind_AIS_FixRelation(py::module &mod){

py::class_<AIS_FixRelation, opencascade::handle<AIS_FixRelation>, AIS_Relation> cls_AIS_FixRelation(mod, "AIS_FixRelation", "Constructs and manages a constraint by a fixed relation between two or more interactive datums. This constraint is represented by a wire from a shape - point, vertex, or edge - in the first datum and a corresponding shape in the second. Warning: This relation is not bound with any kind of parametric constraint : it represents the 'status' of an parametric object.");

// Constructors
cls_AIS_FixRelation.def(py::init<const TopoDS_Shape &, const opencascade::handle<Geom_Plane> &, const TopoDS_Wire &>(), py::arg("aShape"), py::arg("aPlane"), py::arg("aWire"));
cls_AIS_FixRelation.def(py::init<const TopoDS_Shape &, const opencascade::handle<Geom_Plane> &, const TopoDS_Wire &, const gp_Pnt &>(), py::arg("aShape"), py::arg("aPlane"), py::arg("aWire"), py::arg("aPosition"));
cls_AIS_FixRelation.def(py::init<const TopoDS_Shape &, const opencascade::handle<Geom_Plane> &, const TopoDS_Wire &, const gp_Pnt &, const Standard_Real>(), py::arg("aShape"), py::arg("aPlane"), py::arg("aWire"), py::arg("aPosition"), py::arg("anArrowSize"));
cls_AIS_FixRelation.def(py::init<const TopoDS_Shape &, const opencascade::handle<Geom_Plane> &>(), py::arg("aShape"), py::arg("aPlane"));
cls_AIS_FixRelation.def(py::init<const TopoDS_Shape &, const opencascade::handle<Geom_Plane> &, const gp_Pnt &>(), py::arg("aShape"), py::arg("aPlane"), py::arg("aPosition"));
cls_AIS_FixRelation.def(py::init<const TopoDS_Shape &, const opencascade::handle<Geom_Plane> &, const gp_Pnt &, const Standard_Real>(), py::arg("aShape"), py::arg("aPlane"), py::arg("aPosition"), py::arg("anArrowSize"));

// Fields

// Methods
cls_AIS_FixRelation.def("Wire", (TopoDS_Wire (AIS_FixRelation::*)()) &AIS_FixRelation::Wire, "Returns the wire which connects vertices in a fixed relation.");
cls_AIS_FixRelation.def("SetWire", (void (AIS_FixRelation::*)(const TopoDS_Wire &)) &AIS_FixRelation::SetWire, "Constructs the wire aWire. This connects vertices which are in a fixed relation.", py::arg("aWire"));
cls_AIS_FixRelation.def("IsMovable", (Standard_Boolean (AIS_FixRelation::*)() const) &AIS_FixRelation::IsMovable, "Returns true if the Interactive Objects in the relation are movable.");
cls_AIS_FixRelation.def("Compute", (void (AIS_FixRelation::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Prs3d_Presentation> &)) &AIS_FixRelation::Compute, "computes the presentation according to a point of view given by <aProjector>. To be Used when the associated degenerated Presentations have been transformed by <aTrsf> which is not a Pure Translation. The HLR Prs can't be deducted automatically WARNING :<aTrsf> must be applied to the object to display before computation !!!", py::arg("aProjector"), py::arg("aTrsf"), py::arg("aPresentation"));
cls_AIS_FixRelation.def_static("get_type_name_", (const char * (*)()) &AIS_FixRelation::get_type_name, "None");
cls_AIS_FixRelation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_FixRelation::get_type_descriptor, "None");
cls_AIS_FixRelation.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_FixRelation::*)() const) &AIS_FixRelation::DynamicType, "None");

// Enums

}