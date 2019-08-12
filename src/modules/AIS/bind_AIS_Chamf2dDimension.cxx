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
#include <TCollection_ExtendedString.hxx>
#include <gp_Pnt.hxx>
#include <DsgPrs_ArrowSide.hxx>
#include <AIS_KindOfDimension.hxx>
#include <Prs3d_Projector.hxx>
#include <Geom_Transformation.hxx>
#include <Prs3d_Presentation.hxx>
#include <AIS_Chamf2dDimension.hxx>
#include <Standard_Type.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <SelectMgr_Selection.hxx>
#include <gp_Dir.hxx>

void bind_AIS_Chamf2dDimension(py::module &mod){

py::class_<AIS_Chamf2dDimension, opencascade::handle<AIS_Chamf2dDimension>, AIS_Relation> cls_AIS_Chamf2dDimension(mod, "AIS_Chamf2dDimension", "A framework to define display of 2D chamfers. A chamfer is displayed with arrows and text. The text gives the length of the chamfer if it is a symmetrical chamfer, or the angle if it is not.");

// Constructors
cls_AIS_Chamf2dDimension.def(py::init<const TopoDS_Shape &, const opencascade::handle<Geom_Plane> &, const Standard_Real, const TCollection_ExtendedString &>(), py::arg("aFShape"), py::arg("aPlane"), py::arg("aVal"), py::arg("aText"));
cls_AIS_Chamf2dDimension.def(py::init<const TopoDS_Shape &, const opencascade::handle<Geom_Plane> &, const Standard_Real, const TCollection_ExtendedString &, const gp_Pnt &, const DsgPrs_ArrowSide>(), py::arg("aFShape"), py::arg("aPlane"), py::arg("aVal"), py::arg("aText"), py::arg("aPosition"), py::arg("aSymbolPrs"));
cls_AIS_Chamf2dDimension.def(py::init<const TopoDS_Shape &, const opencascade::handle<Geom_Plane> &, const Standard_Real, const TCollection_ExtendedString &, const gp_Pnt &, const DsgPrs_ArrowSide, const Standard_Real>(), py::arg("aFShape"), py::arg("aPlane"), py::arg("aVal"), py::arg("aText"), py::arg("aPosition"), py::arg("aSymbolPrs"), py::arg("anArrowSize"));

// Fields

// Methods
cls_AIS_Chamf2dDimension.def("KindOfDimension", (AIS_KindOfDimension (AIS_Chamf2dDimension::*)() const) &AIS_Chamf2dDimension::KindOfDimension, "Indicates that we are concerned with a 2d length.");
cls_AIS_Chamf2dDimension.def("IsMovable", (Standard_Boolean (AIS_Chamf2dDimension::*)() const) &AIS_Chamf2dDimension::IsMovable, "Returns true if the 2d chamfer dimension is movable.");
cls_AIS_Chamf2dDimension.def("Compute", (void (AIS_Chamf2dDimension::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Prs3d_Presentation> &)) &AIS_Chamf2dDimension::Compute, "computes the presentation according to a point of view given by <aProjector>. To be Used when the associated degenerated Presentations have been transformed by <aTrsf> which is not a Pure Translation. The HLR Prs can't be deducted automatically WARNING :<aTrsf> must be applied to the object to display before computation !!!", py::arg("aProjector"), py::arg("aTrsf"), py::arg("aPresentation"));
cls_AIS_Chamf2dDimension.def_static("get_type_name_", (const char * (*)()) &AIS_Chamf2dDimension::get_type_name, "None");
cls_AIS_Chamf2dDimension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_Chamf2dDimension::get_type_descriptor, "None");
cls_AIS_Chamf2dDimension.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_Chamf2dDimension::*)() const) &AIS_Chamf2dDimension::DynamicType, "None");

// Enums

}